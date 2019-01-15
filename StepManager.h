#pragma once

#include "stdafx.h"
#include "StepBase.h"
#include <INTERFACES/ISendableToSessionUsers.h>
#include <INTERFACES/ICommonSessionProcessor.h>

class StepManager
{
public:
	StepManager() : currentStep(NULL), previousStep(NULL)
	{
		SetIsReady(false);
	}

	void Init(ISendableToSessionUsers * sender)
	{
		this->sender = sender;
		addNoneStep();
		SetIsReady(true);
	}

	void Update()
	{
		StepBase * nextSameStep = NULL;
		
#ifdef _QUICKTEST_INTERVAL
		if (currentStep->GetStepTime() != INFINITE_DWORD && currentStep->GetStepTime() != 0)
			currentStep->SetStepTime(_QUICKTEST_INTERVAL);
#endif

		GAME_STEP nextStep = currentStep->Update(&nextSameStep);

		if (nextStep != IS_NONE)
		{
			if (nextSameStep != NULL)
			{
				SetCurrentStepObj(nextSameStep);
				currentStep->Start();
			}
			else
			{
				SetCurrentStepObj(stepList[nextStep]);
				currentStep->Start();
			}
		}
	}

	void ForceChangeStep(GAME_STEP nextStep)
	{
		currentStep->Finish(nextStep);
		SetCurrentStepObj(stepList[nextStep]);
		currentStep->Start();
	}

	void RestartCurrentStep()
	{
		currentStep->SetStartTime(stSERVER_INFO.now);
	}

	void AddStep(StepBase * step)
	{
		auto foundStep = stepList.find(step->GetMyStep());

		if (foundStep == stepList.end()) 
		{
			stepList[step->GetMyStep()] = step;
		}
		else 
		{
			StepBase * lastStep = foundStep->second->GetLastNextSameStep();
			lastStep->SetNextSameStep(step);
		}
	}
	
	void RemoveAllStep()
	{
		for (auto & kv : stepList)
		{
			delete kv.second;
		}

		stepList.clear();
		currentStep = NULL;
		previousStep = NULL;
		addNoneStep();
	}

	GAME_STEP GetCurrentStep()
	{
		if (currentStep == NULL)
			return IS_NONE;
		
		return currentStep->GetMyStep();
	}
	
	StepBase * GetCurrentStepObj()
	{
		return currentStep;
	}

	void SetCurrentStepObj(StepBase * step)
	{
		ASSERT(step->GetMyStep() != IS_GAMELOOP || currentStep->GetMyStep() != IS_GAMELOOP);

		if (currentStep == NULL)
		{
			CONSOLE_MDEBUG_C("SetCurrentStepObj " << "NOTHING" << " =====> " << GetStringGAME_STEP(step->GetMyStep()), YELLOW);
		}
		else
		{
			currentStep->SetIsCurrentStep(false);
			CONSOLE_MDEBUG_C("SetCurrentStepObj " << GetStringGAME_STEP(currentStep->GetMyStep()) << " =====> " << GetStringGAME_STEP(step->GetMyStep()) << " owner id : " << step->GetStepOwner().szID, YELLOW);
		}
		
		previousStep = currentStep;
		step->Init();
		currentStep = step;
		currentStep->SetIsCurrentStep(true);
	}

	StepBase * GetStepObj(GAME_STEP step)
	{
		return stepList[step];
	}

	bool GetIsReady() { return isReady; }
	void SetIsReady(bool val) { isReady = val; }
	
	StepBase * CreateStep(GAME_STEP gameStep, DWORD stepTime, bool sendToClient)
	{
		StepBase * step = new StepBase(sender, -1, std::string(""), stepTime, gameStep);
		step->SetCalcNextStepOperation(std::function<GAME_STEP()>([step]()
		{
			//호출되서는 안됨
			std::string gameStepName = "Not Regitster NextStepOperation StepName : ";
			gameStepName += GetStringGAME_STEP(step->GetMyStep());
			ASSERT(gameStepName.c_str() == 0);
			return IS_NONE;
		}));

		return step;
	}

	StepBase * CreateTurnStep(GAME_STEP gameStep, DWORD stepTime, bool sendToClient, DWORD clientTime)
	{
		StepBase * step = new StepBase(sender, -1, std::string(""), stepTime, gameStep, clientTime);
		step->SetCalcNextStepOperation(std::function<GAME_STEP()>([step]()
		{
			//호출되서는 안됨
			std::string gameStepName = "Not Regitster NextStepOperation StepName : ";
			gameStepName += GetStringGAME_STEP(step->GetMyStep());
			ASSERT(gameStepName.c_str() == 0);
			return IS_NONE;
		}));

		return step;
	}

	StepBase * CreateStep(GAME_STEP gameStep, DWORD stepTime, bool sendToClient, std::function<GAME_STEP()> & nextOperation)
	{
		StepBase * step = new StepBase(sender, -1, std::string(""), stepTime, gameStep, nextOperation);

		if (sendToClient == true)
			step->SetSendStepFlag(SendStepFlag::BOTH);
		else
			step->SetSendStepFlag(SendStepFlag::NONE);

		return step;
	}
	
	StepBase * CreateStep(GAME_STEP gameStep, DWORD stepTime, bool sendToClient, GAME_STEP nextStep)
	{
		StepBase * step = new StepBase(sender, -1, std::string(""), stepTime, gameStep);
		step->SetCalcNextStepOperation(std::function<GAME_STEP()>(
			[nextStep]() { return nextStep; }
		));
		return step;
	}

	StepBase * GetPreviousStepObj() const { return previousStep; }
private:
	void addNoneStep()
	{
		StepBase * step = CreateStep(IS_NONE, DWORD_MAX, false);
		AddStep(step);
		SetCurrentStepObj(stepList[IS_NONE]);

		//CONSOLE_MDEBUG_C("Add NONE STEP", YELLOW);
	}

	bool isReady;
	
	StepBase * previousStep;
	StepBase * currentStep;
	std::map<GAME_STEP, StepBase*> stepList;
	ISendableToSessionUsers * sender;
};