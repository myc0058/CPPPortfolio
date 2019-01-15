#include "stdafx.h"

#include "AUTO_PLAY.h"
#include "CardUtil.h"

bool AutoResult::ToUPacket(Phom_SessionRoomR_Card_U & packet)
{
	bool result = false;
	CardUtil::Copy(PhomCards, packet.vtPHOM);
	CardUtil::Copy(RegStCards, packet.vtREG_STR);
	CardUtil::Copy(RegBnCards, packet.vtREG_BUN);
	CardUtil::Copy(AttStCards, packet.vtATT_STR);
	CardUtil::Copy(AttBnCards, packet.vtATT_BUN);
	
	//U가 됐다면 절대 TrashCards가 2장 이상이면 안된다.
	VERIFY(TrashCards.size() < 2);
	
	if (TrashCards.size() > 0)
	{
		CardUtil::Copy(TrashCards[0], packet.stDODROP);
		result = true;
	}

	return result;
}

bool AutoResult::ChangeCardToJoker(CCARD * src, CCARD * joker)
{
	for (int i = 0; i < (int)PhomCards.size(); i++)
	{
		if (PhomCards[i] == src)
		{
			PhomCards[i] = joker;
			return true;
		}
	}

	for (int i = 0; i < (int)RegStCards.size(); i++)
	{
		if (RegStCards[i] == src)
		{
			RegStCards[i] = joker;
			return true;
		}
	}

	for (int i = 0; i < (int)RegBnCards.size(); i++)
	{
		if (RegBnCards[i] == src)
		{
			RegBnCards[i] = joker;
			return true;
		}
	}

	return false;
}

void AutoResult::Clear()
{
	phomCardsRegType = _REG_NONE;
	PhomCards.clear();
	RegStCards.clear();
	RegBnCards.clear();
	AttStCards.clear();
	AttBnCards.clear();
	TrashCards.clear();
}

bool Candidate::CheckAllowDuplicate(Candidate & target)
{
	static int allowDuplicateCnt = 1;
	int duplicateCnt = 0;

	if (FirstCard == target.FirstCard || FirstCard == target.SecondCard || FirstCard == target.ThirdCard)
		duplicateCnt++;

	if (SecondCard == target.FirstCard || SecondCard == target.SecondCard || SecondCard == target.ThirdCard)
		duplicateCnt++;

	if (ThirdCard == target.FirstCard || ThirdCard == target.SecondCard || ThirdCard == target.ThirdCard)
		duplicateCnt++;

	return duplicateCnt <= allowDuplicateCnt;
}

int Candidate::GetDuplicateCnt(Candidate & target)
{
	int duplicateCnt = 0;

	if (FirstCard == target.FirstCard || FirstCard == target.SecondCard || FirstCard == target.ThirdCard)
		duplicateCnt++;

	if (SecondCard == target.FirstCard || SecondCard == target.SecondCard || SecondCard == target.ThirdCard)
		duplicateCnt++;

	if (ThirdCard == target.FirstCard || ThirdCard == target.SecondCard || ThirdCard == target.ThirdCard)
		duplicateCnt++;

	return duplicateCnt;
}

DUPLI_CARD_SEQ Candidate::GetDuplicateCardSeqAndSaveJokerInfo(Candidate & target,
	std::vector<CCARD*> & jokerCards, JokerInfo * usedJokerInfo)
{

	//중복되는 카드는 최대가 한장이다.
	if (FirstCard == target.FirstCard || SecondCard == target.FirstCard || ThirdCard == target.FirstCard)
	{
		if (jokerCards.size() > 0)
		{
			usedJokerInfo->Position = JCP_FIRSTCARD;
			usedJokerInfo->JokerType = target.FirstCard->m_nType;
			usedJokerInfo->JokerNo = target.FirstCard->m_nNo;
			usedJokerInfo->JokerCard = jokerCards[0];
			
			target.FirstCard = jokerCards[0];

			jokerCards.erase(jokerCards.begin());
			return DCS_NOPROBLEM;
		}
		else
			return DCS_FIRST;
	}
	
	if (FirstCard == target.SecondCard || SecondCard == target.SecondCard || ThirdCard == target.SecondCard)
	{
		if (jokerCards.size() > 0)
		{
			usedJokerInfo->Position = JCP_SECONDCARD;
			usedJokerInfo->JokerType = target.SecondCard->m_nType;
			usedJokerInfo->JokerNo = target.SecondCard->m_nNo;
			usedJokerInfo->JokerCard = jokerCards[0];
			
			target.SecondCard = jokerCards[0];

			jokerCards.erase(jokerCards.begin());
			return DCS_NOPROBLEM;
		}
		else
			return DCS_SECOND;
	}

	if (FirstCard == target.ThirdCard || SecondCard == target.ThirdCard || ThirdCard == target.ThirdCard)
	{
		if (jokerCards.size() > 0)
		{
			usedJokerInfo->Position = JCP_THIRDCARD;
			usedJokerInfo->JokerType = target.ThirdCard->m_nType;
			usedJokerInfo->JokerNo = target.ThirdCard->m_nNo;
			usedJokerInfo->JokerCard = jokerCards[0];
			target.ThirdCard = jokerCards[0];

			jokerCards.erase(jokerCards.begin());
			return DCS_NOPROBLEM;
		}
		else
			return DCS_THIRD;
	}

	this->MakeCardInfo();

	return DCS_NOPROBLEM;
}

void Candidate::ToAutoResult(AutoResult & autoResult, _emREG_TYPE regType)
{
	if ((DropCard != NULL) && (FirstCard == DropCard || SecondCard == DropCard || ThirdCard == DropCard))
	{
		autoResult.phomCardsRegType = regType;
		autoResult.PhomCards.push_back(FirstCard);
		autoResult.PhomCards.push_back(SecondCard);
		autoResult.PhomCards.push_back(ThirdCard);
	}
	else
	{
		if (RegType == _STRAIGHT)
		{
			autoResult.RegStCards.push_back(FirstCard);
			autoResult.RegStCards.push_back(SecondCard);
			autoResult.RegStCards.push_back(ThirdCard);
		}
		else
		{
			autoResult.RegBnCards.push_back(FirstCard);
			autoResult.RegBnCards.push_back(SecondCard);
			autoResult.RegBnCards.push_back(ThirdCard);
		}
	}
}

bool CandidateSet::AdjustValidation()
{
	if (FirstRegCandidate.RegType != _REG_NONE && SecondRegCandidate.RegType != _REG_NONE)
		if (FirstRegCandidate.CheckAllowDuplicate(SecondRegCandidate) == false)
		{
			SecondRegCandidate.RegType = _REG_NONE;
			SecondRegCandidate.FirstCard = NULL;
			SecondRegCandidate.SecondCard = NULL;
			SecondRegCandidate.ThirdCard = NULL;
		}

	if (FirstRegCandidate.RegType != _REG_NONE && ThirdRegCandidate.RegType != _REG_NONE)
		if (FirstRegCandidate.CheckAllowDuplicate(ThirdRegCandidate) == false)
		{
			ThirdRegCandidate.RegType = _REG_NONE;
			ThirdRegCandidate.FirstCard = NULL;
			ThirdRegCandidate.SecondCard = NULL;
			ThirdRegCandidate.ThirdCard = NULL;
		}

	if (SecondRegCandidate.RegType != _REG_NONE && ThirdRegCandidate.RegType != _REG_NONE)
		if (SecondRegCandidate.CheckAllowDuplicate(ThirdRegCandidate) == false)
		{
			ThirdRegCandidate.RegType = _REG_NONE;
			ThirdRegCandidate.FirstCard = NULL;
			ThirdRegCandidate.SecondCard = NULL;
			ThirdRegCandidate.ThirdCard = NULL;
		}
	if (SecondRegCandidate.RegType == _REG_NONE)
		std::swap(SecondRegCandidate, ThirdRegCandidate);

	FirstRegCandidate.MakeCardInfo();
	SecondRegCandidate.MakeCardInfo();
	ThirdRegCandidate.MakeCardInfo();

	return true;
}

bool CandidateSet::CanRegisterAll()
{
	if (FirstRegCandidate.RegType == _REG_NONE || SecondRegCandidate.RegType == _REG_NONE || ThirdRegCandidate.RegType == _REG_NONE)
		return false;

	if (FirstRegCandidate.GetDuplicateCnt(SecondRegCandidate) != 0)
		return false;

	if (FirstRegCandidate.GetDuplicateCnt(ThirdRegCandidate) != 0)
		return false;

	if (SecondRegCandidate.GetDuplicateCnt(ThirdRegCandidate) != 0)
		return false;

	for (int i = 0; i < (int)remainCards.size(); i++)
		remainCardsFinally.push_back(remainCards[i]);

	return true;
}

bool CandidateSet::CanRegisterAllWithJoker(std::vector<CCARD*> jokerCards)
{
	if (FirstRegCandidate.RegType == _REG_NONE && SecondRegCandidate.RegType == _REG_NONE && ThirdRegCandidate.RegType == _REG_NONE)
		return false;

	/*
		두개의 후보자끼리 카드가 2장 이상 중복되는 경우는 없기 때문에 2장 이상 중복은 가정하지 않는다.
		카드 한장이 세개의 후보자에 동시에 포함될수 없다.
	*/

	//중복된 카드들은 조커로 대체 해준다.

	//조커가 모자르면 나머지 카드는 Attach용 리스트로 넣어준다.
	if (FirstRegCandidate.RegType != _REG_NONE && SecondRegCandidate.RegType != _REG_NONE)
	{
		AdjustJokerTwoCandidates(jokerCards, &FirstRegCandidate, &FirstJokerInfo, &SecondRegCandidate, &SecondJokerInfo);
	}
		
	if (FirstRegCandidate.RegType != _REG_NONE && ThirdRegCandidate.RegType != _REG_NONE)
	{
		AdjustJokerTwoCandidates(jokerCards, &FirstRegCandidate, &FirstJokerInfo, &ThirdRegCandidate, &ThirdJokerInfo);
	}

	if (SecondRegCandidate.RegType != _REG_NONE && ThirdRegCandidate.RegType != _REG_NONE)
	{
		AdjustJokerTwoCandidates(jokerCards, &SecondRegCandidate, &SecondJokerInfo, &ThirdRegCandidate, &ThirdJokerInfo);
	}

	//조커가 있고 남은 카드가 2장 이상이면 남은 카드들로 스트레이트나 번들이 되는지 확인한다.
	if (jokerCards.size() > 0 && remainCards.size() > 1)
	{
		std::vector<CCARD*> bundleCards;
		std::vector<CCARD*> straightCards;

		//조커를 사용하여 스트레이트를 모두 추출한다.
		CardUtil::SortType(remainCards);
		for (int i = 0; i < (int)jokerCards.size();)
		{
			int backupJokerType = jokerCards[0]->m_nJokerType;
			int backupJokerNo = jokerCards[0]->m_nJokerNo;

			if (CardUtil::ExtractStraightWithJoker(remainCards, jokerCards[0], true, &straightCards) == true)
			{
				straightCards.push_back(jokerCards[0]);
				jokerCards.erase(jokerCards.begin() + i);

				if (AddUsedJokerCandidate(straightCards, _STRAIGHT, backupJokerType, backupJokerNo) == true)
					straightCards.clear();
				else
					break;
			}
			else
				i++;
		}

		//조커를 사용하여 번들을 모두 추출한다.
		CardUtil::SortNo(remainCards);
		for (int i = 0; i < (int)jokerCards.size();)
		{
			int backupJokerType = jokerCards[0]->m_nJokerType;
			int backupJokerNo = jokerCards[0]->m_nJokerNo;

			if (CardUtil::ExtractBundleWithJoker(remainCards, jokerCards[0], true, &bundleCards) == true)
			{
				bundleCards.push_back(jokerCards[0]);
				jokerCards.erase(jokerCards.begin() + i);

				if (AddUsedJokerCandidate(bundleCards, _BUNDLE, backupJokerType, backupJokerNo) == true)
					bundleCards.clear();
				else
					break;
			}
			else
				i++;
		}
	}
	

	bool result = FirstRegCandidate.RegType != _REG_NONE && SecondRegCandidate.RegType != _REG_NONE && ThirdRegCandidate.RegType != _REG_NONE;

	if (result == true)
		for (int i = 0; i < (int) remainCards.size(); i++)
			remainCardsFinally.push_back(remainCards[i]);

	return result;
}

bool CandidateSet::CanRegisterAndAttachNineCards(CSTRAIGHT * regStraight, CBUNDLE * regBundle)
{
	int regAttCnt = 0;

	std::vector<CCARD*> cardListForAttach;
	if (remainCards.size() > 0)
	{
		std::vector<CCARD*> handCards;
		std::vector<CCARD*> regedStrCards;
		std::vector<CCARD*> regedBunCards;

		if (FirstRegCandidate.RegType != _REG_NONE)
		{
			if (FirstRegCandidate.RegType == _STRAIGHT)
			{
				regedStrCards.push_back(FirstRegCandidate.FirstCard);
				regedStrCards.push_back(FirstRegCandidate.SecondCard);
				regedStrCards.push_back(FirstRegCandidate.ThirdCard);
			}
			else
			{
				regedBunCards.push_back(FirstRegCandidate.FirstCard);
				regedBunCards.push_back(FirstRegCandidate.SecondCard);
				regedBunCards.push_back(FirstRegCandidate.ThirdCard);
			}

			regAttCnt += 3;
		}

		if (SecondRegCandidate.RegType != _REG_NONE)
		{
			if (SecondRegCandidate.RegType == _STRAIGHT)
			{
				regedStrCards.push_back(SecondRegCandidate.FirstCard);
				regedStrCards.push_back(SecondRegCandidate.SecondCard);
				regedStrCards.push_back(SecondRegCandidate.ThirdCard);
			}
			else
			{
				regedBunCards.push_back(SecondRegCandidate.FirstCard);
				regedBunCards.push_back(SecondRegCandidate.SecondCard);
				regedBunCards.push_back(SecondRegCandidate.ThirdCard);
			}
			

			regAttCnt += 3;
		}

		if (ThirdRegCandidate.RegType != _REG_NONE)
		{
			if (ThirdRegCandidate.RegType == _STRAIGHT)
			{
				regedStrCards.push_back(ThirdRegCandidate.FirstCard);
				regedStrCards.push_back(ThirdRegCandidate.SecondCard);
				regedStrCards.push_back(ThirdRegCandidate.ThirdCard);
			}
			else
			{
				regedBunCards.push_back(ThirdRegCandidate.FirstCard);
				regedBunCards.push_back(ThirdRegCandidate.SecondCard);
				regedBunCards.push_back(ThirdRegCandidate.ThirdCard);
			}

			regAttCnt += 3;
		}

		for (int i = 0; i < (int)remainCards.size(); i++)
		{
			//폼해서 받은 카드는 붙이기 할수 없다.
			if (remainCards[i]->m_emCardPos == _DROP)
				remainCardsFinally.push_back(remainCards[i]);
			else
				handCards.push_back(remainCards[i]);
		}

		//등록을 하지 못하면 붙이기를 할수 없다.
		if (regedStrCards.size() + regedBunCards.size() > 0)
		{
			std::vector<CCARD*> attCards;
			int attCardCnt = 0;
			regStraight->IsAttach(regedStrCards, handCards, attCards);
			regAttCnt += attCards.size();

			//붙이기한카드는 저장하고 번들 붙이기를 위해 삭제한다.
			for (int i = 0; i < (int)attCards.size(); i++)
			{
				cardsForStrAttach.push_back(attCards[i]);
			}

			attCards.clear();

			regBundle->IsAttach(regedBunCards, handCards, attCards);
			regAttCnt += attCards.size();

			//붙이기한카드는 저장하고 남은카드 저장을 위해 삭제한다.
			for (int i = 0; i < (int)attCards.size(); i++)
			{
				cardsForBunAttach.push_back(attCards[i]);
			}
		}

		//남은 카드는 따로 저장한다.
		for (int i = 0; i < (int)handCards.size(); i++)
			remainCardsFinally.push_back(handCards[i]);

		//남은 카드에 폼해서 받은 카드가 있으면 실패
		for (int i = 0; i < (int)remainCardsFinally.size(); i++)
			if (remainCardsFinally[i]->m_emCardPos == _DROP)
				return false;
	}
	
	return regAttCnt >= AUTO_PLAY::MinUCardCnt;
}

int CandidateSet::AddRemainCards(std::vector<CCARD*> & regCards)
{
	for (int i = 0; i < (int)regCards.size(); i++)
	{
		AddRemainCard(regCards[i]);
	}

	return (int) remainCards.size();
}

bool CandidateSet::AddRemainCard(CCARD * card)
{
	if (ExistInCandidate(card) == true)
		return false;

	remainCards.push_back(card);
	
	return true;;
}

bool CandidateSet::ExistInCandidate(CCARD * card)
{
	if (FirstRegCandidate.RegType != _REG_NONE)
	{
		if (card == FirstRegCandidate.FirstCard || card == FirstRegCandidate.SecondCard || card == FirstRegCandidate.ThirdCard)
			return true;
	}
		
	if (SecondRegCandidate.RegType != _REG_NONE)
	{
		if (card == SecondRegCandidate.FirstCard || card == SecondRegCandidate.SecondCard || card == SecondRegCandidate.ThirdCard)
			return true;
	}

	if (ThirdRegCandidate.RegType != _REG_NONE)
	{
		if (card == ThirdRegCandidate.FirstCard || card == ThirdRegCandidate.SecondCard || card == ThirdRegCandidate.ThirdCard)
			return true;
	}

	return false;
}

void CandidateSet::ToAutoResult(AutoResult & autoResult)
{
	//조커의 사용을 확정 지어줌
	if (FirstJokerInfo.Position != JCP_NONE)
	{
		FirstJokerInfo.JokerCard->m_nJokerType = FirstJokerInfo.JokerType;
		FirstJokerInfo.JokerCard->m_nJokerNo = FirstJokerInfo.JokerNo;
	}

	if (SecondJokerInfo.Position != JCP_NONE)
	{
		SecondJokerInfo.JokerCard->m_nJokerType = SecondJokerInfo.JokerType;
		SecondJokerInfo.JokerCard->m_nJokerNo = SecondJokerInfo.JokerNo;
	}

	if (ThirdJokerInfo.Position != JCP_NONE)
	{
		ThirdJokerInfo.JokerCard->m_nJokerType = ThirdJokerInfo.JokerType;
		ThirdJokerInfo.JokerCard->m_nJokerNo = ThirdJokerInfo.JokerNo;
	}

	if (FirstRegCandidate.RegType != _REG_NONE)
		FirstRegCandidate.ToAutoResult(autoResult, FirstRegCandidate.RegType);

	if (SecondRegCandidate.RegType != _REG_NONE)
		SecondRegCandidate.ToAutoResult(autoResult, SecondRegCandidate.RegType);

	if (ThirdRegCandidate.RegType != _REG_NONE)
		ThirdRegCandidate.ToAutoResult(autoResult, ThirdRegCandidate.RegType);

	for (int i = 0; i < (int)cardsForStrAttach.size(); i++)
		autoResult.AttStCards.push_back(cardsForStrAttach[i]);
	
	for (int i = 0; i < (int)cardsForBunAttach.size(); i++)
		autoResult.AttBnCards.push_back(cardsForBunAttach[i]);

	for (int i = 0; i < (int)remainCardsFinally.size(); i++)
		autoResult.TrashCards.push_back(remainCardsFinally[i]);
}

int CandidateSet::GetSumRemainCardsNumber()
{
	int result = 0;
	for (int i = 0; i < (int)remainCardsFinally.size(); i++)
		result += remainCardsFinally[i]->m_nNo;
	return result;
}

bool CandidateSet::Compare(CandidateSet & target)
{
	bool result = true;
	
	result &= FirstRegCandidate.Compare(target.FirstRegCandidate);
	
	result &= SecondRegCandidate.Compare(target.SecondRegCandidate);
	
	result &= ThirdRegCandidate.Compare(target.ThirdRegCandidate);
	

	return result;
}

bool CandidateSet::AdjustJokerTwoCandidates(std::vector<CCARD*> & jokerCards, Candidate * candidate, JokerInfo * jokerInfo, Candidate * candidate2, JokerInfo * jokerInfo2)
{
	if (jokerInfo->Position != JCP_NONE && jokerInfo2->Position != JCP_NONE)
		return false;

	Candidate * targetCandidate = NULL;
	JokerInfo * targetJokerInfo = NULL;

	Candidate * notUsedJokerCandiate = NULL;
	JokerInfo * notUsedJokerJokerInfo = NULL;

	if (jokerInfo2->Position == JCP_NONE)
	{
		targetCandidate = candidate2;
		targetJokerInfo = jokerInfo2;

		notUsedJokerCandiate = candidate;
		notUsedJokerJokerInfo = jokerInfo;
	}
	else
	{
		targetCandidate = candidate;
		targetJokerInfo = jokerInfo;

		notUsedJokerCandiate = candidate2;
		notUsedJokerJokerInfo = jokerInfo2;
	}
	

	DUPLI_CARD_SEQ problemSeq = notUsedJokerCandiate->GetDuplicateCardSeqAndSaveJokerInfo(*targetCandidate, jokerCards, targetJokerInfo);

	if (problemSeq != DCS_NOPROBLEM)
	{
		if (problemSeq == DCS_FIRST)
		{
			AddRemainCard(targetCandidate->SecondCard);
			AddRemainCard(targetCandidate->ThirdCard);
		}
		else if (problemSeq == DCS_SECOND)
		{
			AddRemainCard(targetCandidate->FirstCard);
			AddRemainCard(targetCandidate->ThirdCard);
		}
		else if (problemSeq == DCS_THIRD)
		{
			AddRemainCard(targetCandidate->FirstCard);
			AddRemainCard(targetCandidate->SecondCard);
		}

		targetCandidate->RegType = _REG_NONE;
	}

	return true;
}

bool CandidateSet::AddUsedJokerCandidate(std::vector<CCARD*> & regCards, _emREG_TYPE regType, int backupJokerType, int backupJokerNo)
{
	Candidate * emptyCandidate = NULL;
	JokerInfo * emptyJokerInfo = NULL;

	if (FirstRegCandidate.RegType == _REG_NONE)
	{
		emptyCandidate = &FirstRegCandidate;
		emptyJokerInfo = &FirstJokerInfo;
	}
	else if (SecondRegCandidate.RegType == _REG_NONE)
	{
		emptyCandidate = &SecondRegCandidate;
		emptyJokerInfo = &SecondJokerInfo;
	}
	else if (ThirdRegCandidate.RegType == _REG_NONE)
	{
		emptyCandidate = &ThirdRegCandidate;
		emptyJokerInfo = &ThirdJokerInfo;
	}
	else
		return false;

	emptyCandidate->RegType = regType;
	emptyCandidate->FirstCard = regCards[0];
	emptyCandidate->SecondCard = regCards[1];

	//세번째가 조커 카드임
	emptyCandidate->ThirdCard = regCards[2];

	emptyJokerInfo->Position = JCP_THIRDCARD;
	emptyJokerInfo->JokerType = emptyCandidate->ThirdCard->m_nJokerType;
	emptyJokerInfo->JokerNo = emptyCandidate->ThirdCard->m_nJokerNo;
	emptyJokerInfo->JokerCard = emptyCandidate->ThirdCard;

	//카드에 있던 Joker정보는 원래대로 돌림
	emptyCandidate->ThirdCard->m_nJokerType = backupJokerType;
	emptyCandidate->ThirdCard->m_nJokerNo = backupJokerNo;

	emptyCandidate->MakeCardInfo();
	return true;
}

AUTO_PLAY::AUTO_PLAY(void)
{
}

AUTO_PLAY::~AUTO_PLAY(void)
{
}

void AUTO_PLAY::Clear()
{

}

bool AUTO_PLAY::Is_U(std::vector<CCARD*> & myHandCards, CCARD *pDrop, AutoResult & autoResult)
{
	//대기열에 있는 카드와 아닌 카드를 분리한다.
	std::vector<CCARD*> stanbyCards;
	std::vector<_emREG_TYPE> stanbyCardsRegTypes;

	while (myHandCards.size() >= stanbyCardCnt)
	{
		CCARD * firstCard = myHandCards[0];
		CCARD * secondCard = myHandCards[1];
		CCARD * thirdCard = myHandCards[2];

		//대기열 카드가 먼저 들어있다고 가정함 (그렇게 코딩되어 있음)

		//카드 세장중에 한장이라도 버린카드가 있다면 그건 대기열 카드이다.
		if (firstCard->m_emCardPos != _DROP && secondCard->m_emCardPos != _DROP && thirdCard->m_emCardPos != _DROP)
			break;

		_emREG_TYPE regType = CardUtil::CheckStraightOrBundle(firstCard, secondCard, thirdCard);
		
		//아래 처럼 될순 없지만 방어코드를 넣는다.
		if (regType == _REG_NONE)
			break;

		stanbyCardsRegTypes.push_back(regType);
		stanbyCards.push_back(firstCard);
		stanbyCards.push_back(secondCard);
		stanbyCards.push_back(thirdCard);

		myHandCards.erase(myHandCards.begin());
		myHandCards.erase(myHandCards.begin());
		myHandCards.erase(myHandCards.begin());
	}
	
	//조커를 빼고 리스트에 담는다.
	std::vector<CCARD*> noJokerCards;
	std::vector<CCARD*> jokerCards;
	for (int i = 0; i < (int)myHandCards.size(); i++)
	{
		if (myHandCards[i]->is_joker() == false)
			noJokerCards.push_back(myHandCards[i]);
		else
			jokerCards.push_back(myHandCards[i]);
	}
	
	int totalCardCnt = myHandCards.size();
	int dropCardCnt = 0;
	if (pDrop != NULL)
	{
		noJokerCards.push_back(pDrop);
		totalCardCnt++;
		dropCardCnt++;
	}
	
	//최대 카드수는 드롭카드를 포함하여 10장 최소 카드수는 드롭카드를 빼고 9장
	if (totalCardCnt > MaxTotalCardCnt && totalCardCnt < MaxHandCardCnt)
		return false;

	//겹치지 않고 노말하게 U가 되는지 확인한다. CASE 1
	std::vector<CCARD*> tempCards = myHandCards;
	if (checkNotDuplicateCardsU(stanbyCards, stanbyCardsRegTypes, tempCards, autoResult) == true)
		return true;
	else
		autoResult.Clear();

	//아래부터는 카드가 겹치는 경우를 반영한 U찾기 CASE 2

	//세장으로 이뤄진 스트레이트, 번들 후보자(Candidate) 리스트를 만든다.

	//주의!!!!!!!!!!! 아래 루틴은 반드시 순서대로 호출되야 함
	std::vector<Candidate> candidateList;
	makeCandidateList(noJokerCards, candidateList, pDrop, stanbyCards, stanbyCardsRegTypes);

	std::vector<CandidateSet> candidateSetList;
	makeCandidateSetList(candidateSetList, candidateList, noJokerCards);
	
	// 유효한 등록 후보자 3개 찾기
	if (searchUWithoutJoker(candidateSetList, autoResult) == true)
		return true;
	
	//유효한 등록 후보자 3개 찾기 (조커)
	if (searchUWithJoker(candidateSetList, jokerCards, autoResult) == true)
		return true;

	//붙이기 해서 U가 되는지 찾기
	if (searchUWithAttach(candidateSetList, autoResult) == true)
		return true;
	
	return false;
}

bool AUTO_PLAY::AutoRegist(std::vector<CCARD*> & myHandCards, AutoResult & autoResult)
{
	//카드수가 3장이 안되면 등록할게 없으니 false 리턴
	if (myHandCards.size() < 3)
		return false;

	//조커를 빼고 리스트에 담는다.
	std::vector<CCARD*> noJokerCards;
	std::vector<CCARD*> jokerCards;
	for (int i = 0; i < (int)myHandCards.size(); i++)
	{
		if (myHandCards[i]->is_joker() == false)
			noJokerCards.push_back(myHandCards[i]);
		else
			jokerCards.push_back(myHandCards[i]);
	}

	std::vector<CCARD*> bundleCards;
	std::vector<CCARD*> straightCards;

	//자동 등록은 먼저 조커를 사용하여 번들을 등록하고 그 다음 스트레이트를 등록한다
	//그러므로 최선의 등록이 되지 않을수 있다.

	//조커를 사용하여 번들을 모두 추출한다.
	CardUtil::SortNo(noJokerCards);
	for (int i = 0; i < (int)jokerCards.size();)
	{
		if (CardUtil::ExtractBundleWithJoker(noJokerCards, jokerCards[0], true, &bundleCards) == true)
		{
			bundleCards.push_back(jokerCards[0]);

			jokerCards.erase(jokerCards.begin() + i);
		}
		else
			i++;

	}

	//조커를 사용하여 스트레이트를 모두 추출한다.
	CardUtil::SortType(noJokerCards);
	for (int i = 0; i < (int)jokerCards.size();)
	{
		if (CardUtil::ExtractStraightWithJoker(noJokerCards, jokerCards[0], true, &straightCards) == true)
		{
			straightCards.push_back(jokerCards[0]);

			jokerCards.erase(jokerCards.begin() + i);
		}
		else
			i++;
	}

	//남은 카드로 번들과 스트레이트 가져오기
	CardUtil::SortNo(noJokerCards);
	while (CardUtil::ExtractBundle(noJokerCards, &bundleCards) == true) {}

	CardUtil::SortType(noJokerCards);
	while (CardUtil::ExtractStraight(noJokerCards, &straightCards) == true) {}
	
	bool result = false;
	for (int i = 0; i < (int)bundleCards.size(); i++)
	{
		autoResult.RegBnCards.push_back(bundleCards[i]);
		result = true;
	}

	for (int i = 0; i < (int)straightCards.size(); i++)
	{
		autoResult.RegStCards.push_back(straightCards[i]);
		result = true;
	}

	return result;
}

bool AUTO_PLAY::AutoAttach(std::vector<CCARD*> & myHandCards, AutoResult & autoResult, std::vector<CCARD*> & regedBundleCards, std::vector<CCARD*> & regedStraightCards)
{
	std::vector<CCARD*> regedCards = regedBundleCards;
	std::vector<CCARD*> attCards;

	_regBundle->IsAttach(regedCards, myHandCards, attCards);

	bool result = false;
	for (int i = 0; i < (int)attCards.size(); i++)
	{
		autoResult.AttBnCards.push_back(attCards[i]);
		result = true;
	}

	attCards.clear();

	regedCards.clear();
	regedCards = regedStraightCards;
	_regStraight->IsAttach(regedCards, myHandCards, attCards);

	for (int i = 0; i < (int)attCards.size(); i++)
	{
		autoResult.AttStCards.push_back(attCards[i]);
		result = true;
	}

	attCards.clear();

	return result;
}

void AUTO_PLAY::makeCandidateList(std::vector<CCARD*> & noJokerCards, std::vector<Candidate> & candidateList, CCARD * dropCard,
	std::vector<CCARD*> & myStanbyCards, std::vector<_emREG_TYPE> & myStanbyCardsRegTypes)
{
	//대기열에 있는 카드들을 후보자로 만든다.
	//대기열에 있는 카드를 등록한 카드로 넣어준다.
	for (int i = 0; i < (int)myStanbyCardsRegTypes.size(); i++)
	{
		Candidate candidate;
		candidate.RegType = myStanbyCardsRegTypes[i];
		candidate.FirstCard = myStanbyCards[stanbyCardCnt*i];
		candidate.SecondCard = myStanbyCards[stanbyCardCnt*i + 1];
		candidate.ThirdCard = myStanbyCards[stanbyCardCnt*i + 2];
		candidate.DropCard = dropCard;
		candidate.MakeCardInfo();
		candidateList.push_back(candidate);
	}

	//스트레이트 후보자 만들기
	CardUtil::SortType(noJokerCards);

	for (int i = 0; i < (int)noJokerCards.size() - 2; i++)
	{
		if (CardUtil::MakeStraight(noJokerCards[i], noJokerCards[i + 1], noJokerCards[i + 2]) == true)
		{
			Candidate candidate;
			candidate.RegType = _STRAIGHT;
			candidate.FirstCard = noJokerCards[i];
			candidate.SecondCard = noJokerCards[i + 1];
			candidate.ThirdCard = noJokerCards[i + 2];
			candidate.DropCard = dropCard;
			candidate.MakeCardInfo();
			candidateList.push_back(candidate);
		}
	}

	//번들 후보자 만들기
	CardUtil::SortNo(noJokerCards);

	//주의!! i가 for문 안에서 자동으로 증가 하지 않는다.
	for (int i = 0; i < (int)noJokerCards.size() - 2;)
	{
		//같은 숫자가 4개인 번들일때
		if (i < (int) noJokerCards.size() - 3 &&
			CardUtil::MakeBundle(noJokerCards[i], noJokerCards[i + 1], noJokerCards[i + 2], noJokerCards[i + 3]) == true)
		{
			//같은숫자가 4개인 번들은 총 조합이 네가지가 나온다. 네가지 조합을 가져오기 위해 원형큐처럼 아래와 같이 만들었다.

			int cicularIndex = 0;
			for (int j = 0; j < MaxBundleCardCnt; j++)
			{
				Candidate candidate;
				candidate.RegType = _BUNDLE;
				cicularIndex = (j % MaxBundleCardCnt) + i;
				candidate.FirstCard = noJokerCards[cicularIndex];
				cicularIndex = ((j + 1) % MaxBundleCardCnt) + i;
				candidate.SecondCard = noJokerCards[cicularIndex];
				cicularIndex = ((j + 2) % MaxBundleCardCnt) + i;
				candidate.ThirdCard = noJokerCards[cicularIndex];
				candidate.DropCard = dropCard;
				candidate.MakeCardInfo();
				candidateList.push_back(candidate);
			}
			
			//4개의 카드는 이미 다 사용하였기에 i를 그 다음 인덱스로 점프 시킨다.
			i = i + MaxBundleCardCnt;
			continue;
		}
		else if (CardUtil::MakeBundle(noJokerCards[i], noJokerCards[i + 1], noJokerCards[i + 2]) == true) //같은 숫자가 3개인 번들일때
		{
			Candidate candidate;
			candidate.RegType = _BUNDLE;
			candidate.FirstCard = noJokerCards[i];
			candidate.SecondCard = noJokerCards[i + 1];
			candidate.ThirdCard = noJokerCards[i + 2];
			candidate.DropCard = dropCard;
			candidate.MakeCardInfo();
			candidateList.push_back(candidate);

			//3개의 카드는 이미 다 사용하였기에 i를 그 다음 인덱스로 점프 시킨다.
			i = i + MinBundleCardCnt;
			continue;
		}

		i++;
	}
}

int factorial(int n)
{
	return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}

void AUTO_PLAY::makeCandidateSetList(std::vector<CandidateSet> & candidateSetList, 
	std::vector<Candidate> & candidateList, std::vector<CCARD*> & noJokerCards)
{
	//U가 되기 위해서 만들어져야 하는 등록 세트 수
	static int uRegCnt = 3;

	CandidateSet candidateSet;
	
	if (candidateList.size() >= 3)
	{
		//n!/r!(n - r)! **** 5!/3!2! ****  5개중 3개씩 순서와 상관없는 조합의 경우의수
		//후보자 리스트에서 등록가능한 후보자 세트를 만든다.
		int candidateSetListSize = factorial(candidateList.size()) / (factorial(uRegCnt) * factorial(candidateList.size() - uRegCnt));
		if (candidateSetListSize < 1) candidateSetListSize = 1;

		//3개씩 뽑아서 6가지의 순서를 바꿔서 candidateSet을 만들어야 하기 때문에 6을 곱해준다.
		candidateSetListSize = candidateSetListSize * 6;
		candidateSetList.reserve(candidateSetListSize);

		for (int i = 0; i < (int)candidateList.size() - 2; i++)
		{
			for (int j = i + 1; j < (int)candidateList.size() - 1; j++)
			{
				for (int k = j + 1; k < (int)candidateList.size(); k++)
				{
					candidateSet.FirstRegCandidate = candidateList[i];
					candidateSet.SecondRegCandidate = candidateList[j];
					candidateSet.ThirdRegCandidate = candidateList[k];
					candidateSet.AdjustValidation();
					candidateSetList.push_back(candidateSet);

					candidateSet.FirstRegCandidate = candidateList[i];
					candidateSet.SecondRegCandidate = candidateList[k];
					candidateSet.ThirdRegCandidate = candidateList[j];
					candidateSet.AdjustValidation();
					candidateSetList.push_back(candidateSet);

					candidateSet.FirstRegCandidate = candidateList[j];
					candidateSet.SecondRegCandidate = candidateList[i];
					candidateSet.ThirdRegCandidate = candidateList[k];
					candidateSet.AdjustValidation();
					candidateSetList.push_back(candidateSet);

					candidateSet.FirstRegCandidate = candidateList[j];
					candidateSet.SecondRegCandidate = candidateList[k];
					candidateSet.ThirdRegCandidate = candidateList[i];
					candidateSet.AdjustValidation();
					candidateSetList.push_back(candidateSet);

					candidateSet.FirstRegCandidate = candidateList[k];
					candidateSet.SecondRegCandidate = candidateList[i];
					candidateSet.ThirdRegCandidate = candidateList[j];
					candidateSet.AdjustValidation();
					candidateSetList.push_back(candidateSet);

					candidateSet.FirstRegCandidate = candidateList[k];
					candidateSet.SecondRegCandidate = candidateList[j];
					candidateSet.ThirdRegCandidate = candidateList[i];
					candidateSet.AdjustValidation();
					candidateSetList.push_back(candidateSet);
				}
			}
		}
	}
	else
	{
		if (candidateList.size() == 1)
		{
			candidateSet.FirstRegCandidate = candidateList[0];
			candidateSet.SecondRegCandidate.RegType = _REG_NONE;
			candidateSet.ThirdRegCandidate.RegType = _REG_NONE;

			candidateSet.AdjustValidation();
			candidateSetList.push_back(candidateSet);
		}

		if (candidateList.size() == 2)
		{
			candidateSet.FirstRegCandidate = candidateList[0];
			candidateSet.SecondRegCandidate = candidateList[1];
			candidateSet.ThirdRegCandidate.RegType = _REG_NONE;

			candidateSet.AdjustValidation();
			candidateSetList.push_back(candidateSet);

			candidateSet.FirstRegCandidate = candidateList[1];
			candidateSet.SecondRegCandidate = candidateList[0];
			candidateSet.ThirdRegCandidate.RegType = _REG_NONE;

			candidateSet.AdjustValidation();
			candidateSetList.push_back(candidateSet);
		}
	}

	//중복 candidateset 제거
	for (int i = 0; i < (int)candidateSetList.size(); i++)
	{
		for (int j = i + 1; j < (int)candidateSetList.size();)
		{
			if (candidateSetList[i].Compare(candidateSetList[j]) == true)
				candidateSetList.erase(candidateSetList.begin() + j);
			else
				j++;
		}
	}

	for (int i = 0; i < (int)candidateSetList.size(); i++)
	{
		candidateSetList[i].AddRemainCards(noJokerCards);
	}
}

bool AUTO_PLAY::searchUWithoutJoker(std::vector<CandidateSet> & candidateSetList, AutoResult & autoResult)
{
	//겹치지 않는 등록 후보자 세개가 있어야 한다.
	for (int i = 0; i < (int)candidateSetList.size(); i++)
	{
		if (candidateSetList[i].CanRegisterAll() == true)
		{
			candidateSetList[i].ToAutoResult(autoResult);
			return true;
		}
	}

	return false;
	
}

bool AUTO_PLAY::searchUWithJoker(std::vector<CandidateSet> & candidateSetList, std::vector<CCARD*> & jokerCards,
	AutoResult & autoResult)
{
	//조커숫자를 적용하여 등록 후보자 세개가 되는지 확인
	for (int i = 0; i < (int)candidateSetList.size(); i++)
	{
		if (candidateSetList[i].CanRegisterAllWithJoker(jokerCards) == true)
		{
			candidateSetList[i].ToAutoResult(autoResult);
			return true;
		}
	}

	return false;
}

bool AUTO_PLAY::searchUWithAttach(std::vector<CandidateSet> & candidateSetList, AutoResult & autoResult)
{
	//등록과 붙이기가 모두 합쳐서 9장이면 U
	for (int i = 0; i < (int)candidateSetList.size(); i++)
	{
		if (candidateSetList[i].CanRegisterAndAttachNineCards(_regStraight, _regBundle) == true)
		{
			candidateSetList[i].ToAutoResult(autoResult);
			return true;
		}
	}

	return false;

}

int AUTO_PLAY::getStraightCount(std::vector<CCARD*> & regCards, AutoResult & autoResult)
{
	int result = 0;

	CardUtil::SortType(regCards);

	std::vector<CCARD*> extractCards;
	while (CardUtil::ExtractStraight(regCards, &extractCards) == true)
	{
		for (int i = 0; i < (int)extractCards.size(); i++)
			autoResult.RegStCards.push_back(extractCards[i]);

		result++;
	}
	
	return result;
}

int AUTO_PLAY::getBundleCount(std::vector<CCARD*> & regCards, AutoResult & autoResult)
{
	int result = 0;

	CardUtil::SortNo(regCards);

	std::vector<CCARD*> extractCards;
	while (CardUtil::ExtractBundle(regCards, &extractCards) == true)
	{
		for (int i = 0; i < (int)extractCards.size(); i++)
			autoResult.RegBnCards.push_back(extractCards[i]);

		result++;
	}

	return result;
}

void AUTO_PLAY::searchBestCandidateSet(std::vector<CandidateSet> & candidateSetList, 
	std::vector<CCARD*> & jokerCards, AutoResult & autoResult)
{
	//모든 CadidateSet에 조커를 적용한다.
	for (int i = 0; i < (int)candidateSetList.size(); i++)
		candidateSetList[i].CanRegisterAllWithJoker(jokerCards);

	//등록과 붙이기가 모두 합쳐서 9장이면 U
	for (int i = 0; i < (int)candidateSetList.size(); i++)
		candidateSetList[i].CanRegisterAndAttachNineCards(_regStraight, _regBundle);

	int smallestCardsSumNo = MAXINT;
	int bestCandidateSetIndex = -1;

	for (int i = 0; i < (int)candidateSetList.size(); i++)
	{
		int currentSumNo = candidateSetList[i].GetSumRemainCardsNumber();
		if (currentSumNo < smallestCardsSumNo)
		{
			smallestCardsSumNo = currentSumNo;
			bestCandidateSetIndex = i;
		}
	}

	VERIFY(bestCandidateSetIndex == -1);

	if (bestCandidateSetIndex != -1)
	{
		candidateSetList[bestCandidateSetIndex].ToAutoResult(autoResult);
	}
}

bool AUTO_PLAY::CheckRegistAttach(std::vector<CCARD*> & regStrCards, std::vector<CCARD*> & regBunCards,
	std::vector<CCARD*> & attStrCards, std::vector<CCARD*> & attBunCards)
{
	if (regStrCards.empty() && regBunCards.empty() && attBunCards.empty() && attStrCards.empty())
		return false;

	std::vector<CCARD*> handCards;
	std::vector<CCARD*> regedCards;

	handCards.clear();
	handCards = regStrCards;
	if (checkRegistStraight(handCards) == false)
		return false;

	handCards.clear();
	handCards = regBunCards;
	if (checkRegistBundle(handCards) == false)
		return false;


	handCards.clear();
	regedCards.clear();
	handCards = attStrCards;
	regedCards = regStrCards;

	int attCardCnt = 0;
	std::vector<CCARD*> attCards;
	_regStraight->IsAttach(regedCards, handCards, attCards);

	if (handCards.size() > 0)
		return false;

	attCards.clear();

	handCards.clear();
	regedCards.clear();
	handCards = attBunCards;
	regedCards = regBunCards;
	_regBundle->IsAttach(regedCards, handCards, attCards);

	if (handCards.size() > 0)
		return false;

	attCards.clear();

	return true;
}

bool AUTO_PLAY::BestRegist(std::vector<CCARD*> & myHandCards, AutoResult & autoResult)
{
	std::vector<CCARD*> stanbyCards;
	std::vector<_emREG_TYPE> stanbyCardsRegTypes;

	while (myHandCards.size() >= stanbyCardCnt)
	{
		CCARD * firstCard = myHandCards[0];
		CCARD * secondCard = myHandCards[1];
		CCARD * thirdCard = myHandCards[2];

		//대기열 카드가 먼저 들어있다고 가정함 (그렇게 코딩되어 있음)

		//카드 세장중에 한장이라도 버린카드가 있다면 그건 대기열 카드이다.
		if (firstCard->m_emCardPos != _DROP && secondCard->m_emCardPos != _DROP && thirdCard->m_emCardPos != _DROP)
			break;

		_emREG_TYPE regType = CardUtil::CheckStraightOrBundle(firstCard, secondCard, thirdCard);

		//아래 처럼 될순 없지만 방어코드를 넣는다.
		if (regType == _REG_NONE)
			break;

		stanbyCardsRegTypes.push_back(regType);
		stanbyCards.push_back(firstCard);
		stanbyCards.push_back(secondCard);
		stanbyCards.push_back(thirdCard);

		myHandCards.erase(myHandCards.begin());
		myHandCards.erase(myHandCards.begin());
		myHandCards.erase(myHandCards.begin());
	}

	//조커를 빼고 리스트에 담는다.
	std::vector<CCARD*> noJokerCards;
	std::vector<CCARD*> jokerCards;
	for (int i = 0; i < (int)myHandCards.size(); i++)
	{
		if (myHandCards[i]->is_joker() == false)
			noJokerCards.push_back(myHandCards[i]);
		else
			jokerCards.push_back(myHandCards[i]);
	}

	//주의!!!!!!!!!!! 아래 루틴은 반드시 순서대로 호출되야 함
	//세장으로 이뤄진 스트레이트, 번들 후보자(Candidate) 리스트를 만든다.
	std::vector<Candidate> candidateList;
	makeCandidateList(noJokerCards, candidateList, NULL, stanbyCards, stanbyCardsRegTypes);

	std::vector<CandidateSet> candidateSetList;
	makeCandidateSetList(candidateSetList, candidateList, noJokerCards);

	//등록및 붙이기로  CandidateSet을 찾는다.
	searchBestCandidateSet(candidateSetList, jokerCards, autoResult);

	return true;
}

bool AUTO_PLAY::checkRegistStraight(std::vector<CCARD*> & pvtTemp)
{
	if (pvtTemp.empty())
		return true;

	static int jokboCardCount = 3;

	int jokboCount = (int)pvtTemp.size() / jokboCardCount;

	//등록카드의 장수는 3의 배수여야 한다.
	if (pvtTemp.size() % jokboCardCount != 0)
		return false;

	for (int i = 0; i < (int)jokboCount; i++)
	{
		if (CardUtil::IsStraight(pvtTemp[i * 3 + 0], pvtTemp[i * 3 + 1], pvtTemp[i * 3 + 2], true) == false)
			return false;
	}

	return true;
}

bool AUTO_PLAY::checkRegistBundle(std::vector<CCARD*> & pvtTemp)
{
	if (pvtTemp.empty())
		return true;

	static int jokboCardCount = 3;

	int jokboCount = (int)pvtTemp.size() / jokboCardCount;

	//등록카드의 장수는 3의 배수여야 한다.
	if (pvtTemp.size() % jokboCardCount != 0)
		return false;

	for (int i = 0; i < (int)jokboCount; i++)
	{
		if (CardUtil::IsBundle(pvtTemp[i * 3 + 0], pvtTemp[i * 3 + 1], pvtTemp[i * 3 + 2], true) == false)
			return false;
	}

	return true;
}

bool AUTO_PLAY::checkNotDuplicateCardsU(std::vector<CCARD*> & myStanbyCards, std::vector<_emREG_TYPE> & myStanbyCardsRegTypes, std::vector<CCARD*> & myHandCards, AutoResult & autoResult)
{
	if (myStanbyCards.size() + myHandCards.size() < AUTO_PLAY::MinUCardCnt)
		return false;

	//조커를 빼고 리스트에 담는다.
	std::vector<CCARD*> noJokerCards;
	std::vector<CCARD*> jokerCards;
	for (int i = 0; i < (int)myHandCards.size(); i++)
	{
		if (myHandCards[i]->is_joker() == false)
			noJokerCards.push_back(myHandCards[i]);
		else
			jokerCards.push_back(myHandCards[i]);
	}

	std::vector<CCARD*> backupJokerCards = jokerCards;

	std::vector<CCARD*> bundleCards;
	std::vector<CCARD*> straightCards;

	//대기열에 있는 카드를 등록한 카드로 넣어준다.
	for (int i = 0; i < (int)myStanbyCardsRegTypes.size(); i++)
	{
		if (myStanbyCardsRegTypes[i] == _STRAIGHT)
		{
			straightCards.push_back(myStanbyCards[stanbyCardCnt*i]);
			straightCards.push_back(myStanbyCards[stanbyCardCnt*i+1]);
			straightCards.push_back(myStanbyCards[stanbyCardCnt*i+2]);
		}
		else if (myStanbyCardsRegTypes[i] == _BUNDLE)
		{
			bundleCards.push_back(myStanbyCards[stanbyCardCnt*i]);
			bundleCards.push_back(myStanbyCards[stanbyCardCnt*i + 1]);
			bundleCards.push_back(myStanbyCards[stanbyCardCnt*i + 2]);
		}
	}

	//조커 없이 번들과 스트레이트 가져오기
	CardUtil::SortType(noJokerCards);
	while (CardUtil::ExtractStraight(noJokerCards, &straightCards) == true) {}

	CardUtil::SortNo(noJokerCards);
	while (CardUtil::ExtractBundle(noJokerCards, &bundleCards) == true) {}

	std::vector<int> backupJokerTypes;
	std::vector<int> backupJokerNos;

	//조커를 사용하여 스트레이트를 모두 추출한다.
	CardUtil::SortType(noJokerCards);
	for (int i = 0; i < (int)jokerCards.size();)
	{
		int backupJokerType = jokerCards[0]->m_nJokerType;
		int backupJokerNo = jokerCards[0]->m_nJokerNo;

		if (CardUtil::ExtractStraightWithJoker(noJokerCards, jokerCards[0], true, &straightCards) == true)
		{
			straightCards.push_back(jokerCards[0]);
			backupJokerTypes.push_back(backupJokerType);
			backupJokerNos.push_back(backupJokerNo);
			jokerCards.erase(jokerCards.begin() + i);
		}
		else
			i++;
	}
	
	//조커를 사용하여 번들을 모두 추출한다.
	CardUtil::SortNo(noJokerCards);
	for (int i = 0; i < (int)jokerCards.size();)
	{
		int backupJokerType = jokerCards[0]->m_nJokerType;
		int backupJokerNo = jokerCards[0]->m_nJokerNo;

		if (CardUtil::ExtractBundleWithJoker(noJokerCards, jokerCards[0], true, &bundleCards) == true)
		{
			bundleCards.push_back(jokerCards[0]);
			backupJokerTypes.push_back(backupJokerType);
			backupJokerNos.push_back(backupJokerNo);
			jokerCards.erase(jokerCards.begin() + i);
		}
		else
			i++;

	}

	bool result = false;
	for (int i = 0; i < (int)bundleCards.size(); i++)
	{
		autoResult.RegBnCards.push_back(bundleCards[i]);
		result = true;
	}

	for (int i = 0; i < (int)straightCards.size(); i++)
	{
		autoResult.RegStCards.push_back(straightCards[i]);
		result = true;
	}

	//남은 카드는 붙여 준다.
	AutoAttach(noJokerCards, autoResult, bundleCards, straightCards);

	//남은 카드를 결과에 넣어준다.
	for (int i = 0; i < (int)noJokerCards.size(); i++)
		autoResult.TrashCards.push_back(noJokerCards[i]);

	if (autoResult.RegStCards.size() + autoResult.RegBnCards.size() + autoResult.AttStCards.size() + autoResult.AttBnCards.size() >= AUTO_PLAY::MinUCardCnt)
	{
		return true;
	}
	else
	{
		//U가 되지 않는다면 조커들의 상태를 원래대로 돌려놓는다.
		//JokerType과 no를 원래대로 돌려준다.
		for (int i = 0; i < (int)backupJokerTypes.size(); i++)
		{
			backupJokerCards[i]->m_nJokerType = backupJokerTypes[i];
			backupJokerCards[i]->m_nJokerNo = backupJokerNos[i];
		}
		return false;
	}
		
}