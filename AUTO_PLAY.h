#pragma once

#include "card.h"
#include "game_def.h"
#include "CSTRAIGHT.h"
#include "CBUNDLE.h"
#include "..\PROCESSOR\PhomSessionRoom.H"

enum DUPLI_CARD_SEQ{
	DCS_NOPROBLEM = 0,
	DCS_FIRST,
	DCS_SECOND,
	DCS_THIRD
};

enum JOKER_CARD_POSITION {
	JCP_NONE = -1,
	JCP_FIRSTCARD,
	JCP_SECONDCARD,
	JCP_THIRDCARD
};

class AutoResult
{
public:
	_emREG_TYPE phomCardsRegType;
	std::vector<CCARD*> PhomCards;
	std::vector<CCARD*> RegStCards;
	std::vector<CCARD*> RegBnCards;
	std::vector<CCARD*> AttStCards;
	std::vector<CCARD*> AttBnCards;
	std::vector<CCARD*> TrashCards;
	bool ChangeCardToJoker(CCARD * src, CCARD * joker);
	bool ToUPacket(Phom_SessionRoomR_Card_U & packet);
	void Clear();
	AutoResult() { phomCardsRegType = _REG_NONE; }
};

class JokerInfo
{
public:
	JokerInfo()
	{
		Position = JCP_NONE;
		JokerType = -1;
		JokerNo = -1;
		JokerCard = NULL;
	}

	JOKER_CARD_POSITION Position;
	int JokerType;
	int JokerNo;
	CCARD * JokerCard;
};

class Candidate
{
public:
	Candidate()
	{
		RegType = _REG_NONE;
		CardInfo.clear();
		FirstCard = NULL;
		SecondCard = NULL;
		ThirdCard = NULL;
		DropCard = NULL;
	}

	_emREG_TYPE RegType;
	std::string CardInfo;
	CCARD * FirstCard;
	CCARD * SecondCard;
	CCARD * ThirdCard;
	CCARD * DropCard;

	bool CheckAllowDuplicate(Candidate & target);
	int GetDuplicateCnt(Candidate & target);
	DUPLI_CARD_SEQ GetDuplicateCardSeqAndSaveJokerInfo(Candidate & target,
		std::vector<CCARD*> & jokerCards, JokerInfo * usedJokerInfo);
	void ToAutoResult(AutoResult & result, _emREG_TYPE regType);
	void MakeCardInfo()
	{
		CardInfo.clear();
		if (RegType != _REG_NONE)
		{
			CardInfo += FirstCard->get_text();
			CardInfo += SecondCard->get_text();
			CardInfo += ThirdCard->get_text();
		}
	}

	bool Compare(Candidate & target)
	{
		if (RegType == _REG_NONE && target.RegType == _REG_NONE)
			return true;

		if (RegType != target.RegType && (RegType == _REG_NONE || target.RegType == _REG_NONE))
			return false;
		
		bool result = true;

		result &= FirstCard == target.FirstCard;

		result &= SecondCard == target.SecondCard;

		result &= ThirdCard == target.ThirdCard;

		return result;
	}
};

class CandidateSet
{
public:
	CandidateSet()
	{
		FirstRegCandidate.RegType = _REG_NONE;
		SecondRegCandidate.RegType = _REG_NONE;
		ThirdRegCandidate.RegType = _REG_NONE;
	}

	JokerInfo FirstJokerInfo;
	Candidate FirstRegCandidate;
	JokerInfo SecondJokerInfo;
	Candidate SecondRegCandidate;
	JokerInfo ThirdJokerInfo;
	Candidate ThirdRegCandidate;

	std::vector<CCARD*> remainCards;

	std::vector<CCARD*> cardsForBunAttach;
	std::vector<CCARD*> cardsForStrAttach;
	std::vector<CCARD*> remainCardsFinally;

	bool AdjustValidation();
	bool CanRegisterAll();
	bool CanRegisterAllWithJoker(std::vector<CCARD*> jokerCards);

	bool AddUsedJokerCandidate(std::vector<CCARD*> & regCards, _emREG_TYPE regType, int backupJokerType, int backupJokerNo);

	bool AdjustJokerTwoCandidates(std::vector<CCARD*> & jokerCards, Candidate * candidate, JokerInfo * jokerInfo, Candidate * candidate2, JokerInfo * jokerInfo2);
	bool CanRegisterAndAttachNineCards(CSTRAIGHT * regStraight, CBUNDLE * regBundle);
	int AddRemainCards(std::vector<CCARD*> & regCards);
	bool AddRemainCard(CCARD * card);
	void ToAutoResult(AutoResult & autoResult);
	int GetSumRemainCardsNumber();
	bool Compare(CandidateSet & target);
private:
	bool ExistInCandidate(CCARD * card);
};

class AUTO_PLAY
{
public:
	AUTO_PLAY(void);
	~AUTO_PLAY(void);

	inline void setReg(CSTRAIGHT * regStraight, CBUNDLE * regBundle) 
	{ 
		_regStraight = regStraight;	
		_regBundle = regBundle; 
	}

	void Clear();
	
	bool Is_U(std::vector<CCARD*> & myHandCards, CCARD *pDrop, AutoResult & autoResult);
	bool AutoRegist(std::vector<CCARD*> & myHandCards, AutoResult & autoResult);
	bool AutoAttach(std::vector<CCARD*> & myHandCards, AutoResult & autoResult, std::vector<CCARD*> & regedBundleCards, std::vector<CCARD*> & regedStraightCards);
	bool CheckRegistAttach(std::vector<CCARD*> & regStrCards, std::vector<CCARD*> & regBunCards,
		std::vector<CCARD*> & attStrCards, std::vector<CCARD*> & attBunCards);
	bool BestRegist(std::vector<CCARD*> & myHandCards, AutoResult & autoResult);

	static const int MinUCardCnt = 9;
private:
	CSTRAIGHT * _regStraight;
	CBUNDLE	* _regBundle;

	void makeCandidateList(std::vector<CCARD*> & regCards, std::vector<Candidate> & candidateList, CCARD * dropCard, 
		std::vector<CCARD*> & myStanbyCards, std::vector<_emREG_TYPE> & myStanbyCardsRegTypes);
	void makeCandidateSetList(std::vector<CandidateSet> & candidateSetList,
		std::vector<Candidate> & candidateList, std::vector<CCARD*> & regCards);
	bool searchUWithoutJoker(std::vector<CandidateSet> & candidateSetList, AutoResult & autoResult);
	bool searchUWithJoker(std::vector<CandidateSet> & candidateSetList, std::vector<CCARD*> & jokerCards,
		AutoResult & autoResult);
	bool searchUWithAttach(std::vector<CandidateSet> & candidateSetList, AutoResult & autoResult);

	int getStraightCount(std::vector<CCARD*> & regCards, AutoResult & autoResult);
	int getBundleCount(std::vector<CCARD*> & regCards, AutoResult & autoResult);

	void searchBestCandidateSet(std::vector<CandidateSet> & candidateSetList, 
		std::vector<CCARD*> & jokerCards, AutoResult & autoResult);

	bool checkRegistStraight(std::vector<CCARD*> &vtCards);
	bool checkRegistBundle(std::vector<CCARD*> &vtCards);

	bool checkNotDuplicateCardsU(std::vector<CCARD*> & myStanbyCards, std::vector<_emREG_TYPE> & myStanbyCardsRegTypes, 
		std::vector<CCARD*> & myHandCards, AutoResult & autoResult);

	static const int MaxTotalCardCnt = 10;
	static const int MaxHandCardCnt = 9;

	static const int MaxBundleCardCnt = 4;
	static const int MinBundleCardCnt = 3;

	static const int stanbyCardCnt = 3;
};
