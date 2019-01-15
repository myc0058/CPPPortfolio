#pragma once

enum class StepStatus
{
	NONE = 0,
	STARTED,
	FINISHED,
};

enum class SendStepFlag
{
	NONE = 0,
	ONLY_START,
	ONLY_FINISH,
	BOTH,
};

class TimingOperation
{
public:
	TimingOperation(std::function<void()> & Operation)
	{
		Executed = false;
		this->Operation = Operation;
	}

	bool Executed;
	std::function<void()> Operation;
};

//주의!!!! StepBase는 StepManager를 통해서만 객체를 만들어야 합니다.
class StepBase
{
public:
	StepBase(ISendableToSessionUsers * sender, int ownerSerial, std::string & ownerID,
		DWORD stepTime, GAME_STEP step)
	{
		this->sender = sender;
		this->stepOwner.bySERIAL = ownerSerial;
		this->stepOwner.szID = ownerID;

		this->myStep = step;
		this->ref1 = 0;
		this->stepTime = stepTime;
		this->isCurrentStep = false;

		this->SetSendStepFlag(SendStepFlag::BOTH);
		this->nextSameStep = NULL;

		this->startOperations.clear();
		this->timeoutOperations.clear();
		this->finishOperations.clear();

		this->clientTime = DWORD_MAX;

	}

	StepBase(ISendableToSessionUsers * sender, int ownerSerial, std::string & ownerID, 
		DWORD stepTime, GAME_STEP step, std::function <GAME_STEP()> & calcNextStepOperation) : 
		StepBase(sender, ownerSerial, ownerID, stepTime, step)
	{
		this->SetCalcNextStepOperation(calcNextStepOperation);
	}

	StepBase(ISendableToSessionUsers * sender, int ownerSerial, std::string & ownerID,
		DWORD stepTime, GAME_STEP step, DWORD clientTime) :
		StepBase(sender, ownerSerial, ownerID, stepTime, step)
	{
		this->clientTime = clientTime;
	}

	virtual ~StepBase()
	{
		if (nextSameStep != NULL)
		{
			delete nextSameStep;
		}
	}

	void Init()
	{
		SetStatus(StepStatus::NONE);
		
		for (int i = 0; i < (int)startOperations.size(); i++)
		{
			auto & item = startOperations[i];
			item.Executed = false;
		}

		for (int i = 0; i < (int)timeoutOperations.size(); i++)
		{
			auto & item = timeoutOperations[i];
			item.Executed = false;
		}

		for (int i = 0; i < (int)finishOperations.size(); i++)
		{
			auto & item = finishOperations[i];
			item.Executed = false;
		}
	}

	void SetStepTime(DWORD stepTime)
	{
		this->stepTime = stepTime;
	}

	DWORD GetStepTime()
	{
		return stepTime;
	}

	DWORD GetRemainTime()
	{
		int restTime = startTime + stepTime - stSERVER_INFO.now;
		if (restTime < 0)
			return 0;
		else
			return restTime;
	}

	void Start()
	{
		Init();
		startTime = stSERVER_INFO.now;
		SetStatus(StepStatus::STARTED);
		internalStart();
	}

	GAME_STEP Update(StepBase ** returnNextSameStep)
	{
		DWORD now = stSERVER_INFO.now;

		//스텝이 완료되기 전에 실행되야 하는 함수들이 있다면 실행해준다.
		for (int i = 0; i < (int)startOperations.size(); i++)
		{
			auto & item = startOperations[i];
			if (item.Executed == false)
			{
				item.Executed = true;
				item.Operation();
			}
		}

		//operation에서 스텝을 꾸면 안됨. 아래 루틴은 실행하지 않는다.
		if (isCurrentStep == false)
		{
			//ASSERT(!"OPERATION IN StepBase CANNOT CHANGE STEP!!");
			return IS_NONE;
		}

		if (stepTime != INFINITE_DWORD && now >= startTime + stepTime)
		{
			//타임아웃 함수들이 있다면 실행해준다.
			for (int i = 0; i < (int)timeoutOperations.size(); i++)
			{
				auto & item = timeoutOperations[i];
				if (item.Executed == false)
				{
					item.Executed = true;
					item.Operation();
				}
			}

			//operation에서 스텝을 꾸면 안됨. 아래 루틴은 실행하지 않는다.
			if (isCurrentStep == false)
			{
				//ASSERT(!"OPERATION IN StepBase CANNOT CHANGE STEP!!");
				return IS_NONE;
			}

			if (this->nextSameStep != NULL)
				*returnNextSameStep = this->nextSameStep;

			return Finish();
		}
		else
			return IS_NONE;
	}

	GAME_STEP Finish()
	{
		SetStatus(StepStatus::FINISHED);
		return internalFinish();
	}

	GAME_STEP Finish(GAME_STEP nextStep)
	{
		SetStatus(StepStatus::FINISHED);
		return internalFinish(nextStep);
	}

	GAME_STEP GetMyStep() { return myStep; }
	
	StepStatus GetStatus() const { return status; }
	void SetStatus(StepStatus val) { status = val; }
	
	SendStepFlag GetSendStepFlag() const { return sendStepFlag; }
	void SetSendStepFlag(SendStepFlag val) { sendStepFlag = val; }
	
	void AddStartOperation(std::function<void()> & startFunction)
	{
		TimingOperation oper(startFunction);
		startOperations.push_back(oper);
	}
	void AddTimeOutOperation(std::function<void()> & timeoutFunction)
	{
		TimingOperation oper(timeoutFunction);
		timeoutOperations.push_back(oper);
	}
	void AddFinishOperation(std::function<void()> & finishFunction)
	{
		TimingOperation oper(finishFunction);
		finishOperations.push_back(oper);
	}

	std::function<GAME_STEP()> GetCalcNextStepOperation() const { return calcNextStepOperation; }
	void SetCalcNextStepOperation(std::function<GAME_STEP()> & val) { calcNextStepOperation = val; }
	
	stUSER_BASE & GetStepOwner() { return stepOwner; }
	void SetStepOwner(int serial, std::string & id)
	{
		this->stepOwner.bySERIAL = serial;
		this->stepOwner.szID = id;
	}
	StepBase * GetLastNextSameStep()
	{
		StepBase * nextStep = nextSameStep;
		StepBase * lastSameStep = this;

		while (nextStep != NULL)
		{
			lastSameStep = nextStep;
			nextStep = lastSameStep->GetNextSameStep();
		}
		return lastSameStep;
	}

	StepBase * GetNextSameStep()
	{
		return this->nextSameStep;
	}

	void SetNextSameStep(StepBase * nextStep)
	{
		this->nextSameStep = nextStep;
	}
	DWORD GetRef1() const { return ref1; }
	void SetRef1(DWORD val) { ref1 = val; }

	bool CheckOverStepTimeWithRef1(DWORD now)
	{
#ifdef _QUICKTEST_INTERVAL
		return now >= startTime + _QUICKTEST_INTERVAL;
#else
		return now >= startTime + ref1;
#endif
	}
	bool GetIsCurrentStep() const { return isCurrentStep; }
	void SetIsCurrentStep(bool val) { isCurrentStep = val; }

	void SetStartTime(DWORD time)
	{
		//CONSOLE_MDEBUG_C("CALL SET START TIME : " << GetStringGAME_STEP(this->GetMyStep()) << " " << time, YELLOW);
		this->startTime = time;
	}
protected:
	virtual void internalStart()
	{
		if (GetSendStepFlag() == SendStepFlag::BOTH || GetSendStepFlag() == SendStepFlag::ONLY_START)
		{
			Common_SessionRoomR_GameStep gameStep;
			gameStep.bySTEP = myStep;
			if (clientTime == DWORD_MAX)
				gameStep.nSTEPTIME = stepTime;
			else
				gameStep.nSTEPTIME = clientTime;
			gameStep.bySTART_END = (byte)StartEndFlag::START;
			gameStep.stUSER = stepOwner;
			//CONSOLE_MDEBUG_C("SEND START GAME STEP : " << stepOwner.szID, YELLOW);
			sender->SendToSessionPlayer(gameStep);
		}
	}

	virtual GAME_STEP internalFinish() 
	{
		finishProcess();

		return calcNextStepOperation();
	}

	virtual GAME_STEP internalFinish(GAME_STEP nextStep)
	{
		finishProcess();

		return nextStep;
	}

	void finishProcess()
	{
		for (int i = 0; i < (int)finishOperations.size(); i++)
		{
			auto & item = finishOperations[i];
			if (item.Executed == false)
			{
				item.Executed = true;
				item.Operation();
			}
		}

		//operation에서 스텝을 꾸면 안됨. 아래 루틴은 실행하지 않는다.
		if (isCurrentStep == false)
		{
			//ASSERT(!"OPERATION IN StepBase CANNOT CHANGE STEP!!");
			return;
		}

		if (GetSendStepFlag() == SendStepFlag::BOTH || GetSendStepFlag() == SendStepFlag::ONLY_FINISH)
		{
			Common_SessionRoomR_GameStep gameStep;
			gameStep.bySTEP = myStep;
			if (clientTime == DWORD_MAX)
				gameStep.nSTEPTIME = stepTime;
			else
				gameStep.nSTEPTIME = clientTime;
			gameStep.bySTART_END = (byte)StartEndFlag::END;
			gameStep.stUSER = stepOwner;
			//CONSOLE_MDEBUG_C("SEND FINISH GAME STEP : " << stepOwner.szID, YELLOW);
			sender->SendToSessionPlayer(gameStep);
		}
	}


	ISendableToSessionUsers * sender;
	stUSER_BASE stepOwner;

	DWORD startTime;
	DWORD stepTime;

	GAME_STEP myStep;
	
	StepStatus status;
	
	std::vector<TimingOperation> startOperations;
	std::vector<TimingOperation> timeoutOperations;
	std::vector<TimingOperation> finishOperations;

	std::function <GAME_STEP()> calcNextStepOperation;
	SendStepFlag sendStepFlag;
	StepBase * nextSameStep;

	DWORD ref1;
	bool isCurrentStep;

	DWORD clientTime;
};