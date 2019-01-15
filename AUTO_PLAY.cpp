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
	
	//U�� �ƴٸ� ���� TrashCards�� 2�� �̻��̸� �ȵȴ�.
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

	//�ߺ��Ǵ� ī��� �ִ밡 �����̴�.
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
		�ΰ��� �ĺ��ڳ��� ī�尡 2�� �̻� �ߺ��Ǵ� ���� ���� ������ 2�� �̻� �ߺ��� �������� �ʴ´�.
		ī�� ������ ������ �ĺ��ڿ� ���ÿ� ���Եɼ� ����.
	*/

	//�ߺ��� ī����� ��Ŀ�� ��ü ���ش�.

	//��Ŀ�� ���ڸ��� ������ ī��� Attach�� ����Ʈ�� �־��ش�.
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

	//��Ŀ�� �ְ� ���� ī�尡 2�� �̻��̸� ���� ī���� ��Ʈ����Ʈ�� ������ �Ǵ��� Ȯ���Ѵ�.
	if (jokerCards.size() > 0 && remainCards.size() > 1)
	{
		std::vector<CCARD*> bundleCards;
		std::vector<CCARD*> straightCards;

		//��Ŀ�� ����Ͽ� ��Ʈ����Ʈ�� ��� �����Ѵ�.
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

		//��Ŀ�� ����Ͽ� ������ ��� �����Ѵ�.
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
			//���ؼ� ���� ī��� ���̱� �Ҽ� ����.
			if (remainCards[i]->m_emCardPos == _DROP)
				remainCardsFinally.push_back(remainCards[i]);
			else
				handCards.push_back(remainCards[i]);
		}

		//����� ���� ���ϸ� ���̱⸦ �Ҽ� ����.
		if (regedStrCards.size() + regedBunCards.size() > 0)
		{
			std::vector<CCARD*> attCards;
			int attCardCnt = 0;
			regStraight->IsAttach(regedStrCards, handCards, attCards);
			regAttCnt += attCards.size();

			//���̱���ī��� �����ϰ� ���� ���̱⸦ ���� �����Ѵ�.
			for (int i = 0; i < (int)attCards.size(); i++)
			{
				cardsForStrAttach.push_back(attCards[i]);
			}

			attCards.clear();

			regBundle->IsAttach(regedBunCards, handCards, attCards);
			regAttCnt += attCards.size();

			//���̱���ī��� �����ϰ� ����ī�� ������ ���� �����Ѵ�.
			for (int i = 0; i < (int)attCards.size(); i++)
			{
				cardsForBunAttach.push_back(attCards[i]);
			}
		}

		//���� ī��� ���� �����Ѵ�.
		for (int i = 0; i < (int)handCards.size(); i++)
			remainCardsFinally.push_back(handCards[i]);

		//���� ī�忡 ���ؼ� ���� ī�尡 ������ ����
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
	//��Ŀ�� ����� Ȯ�� ������
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

	//����°�� ��Ŀ ī����
	emptyCandidate->ThirdCard = regCards[2];

	emptyJokerInfo->Position = JCP_THIRDCARD;
	emptyJokerInfo->JokerType = emptyCandidate->ThirdCard->m_nJokerType;
	emptyJokerInfo->JokerNo = emptyCandidate->ThirdCard->m_nJokerNo;
	emptyJokerInfo->JokerCard = emptyCandidate->ThirdCard;

	//ī�忡 �ִ� Joker������ ������� ����
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
	//��⿭�� �ִ� ī��� �ƴ� ī�带 �и��Ѵ�.
	std::vector<CCARD*> stanbyCards;
	std::vector<_emREG_TYPE> stanbyCardsRegTypes;

	while (myHandCards.size() >= stanbyCardCnt)
	{
		CCARD * firstCard = myHandCards[0];
		CCARD * secondCard = myHandCards[1];
		CCARD * thirdCard = myHandCards[2];

		//��⿭ ī�尡 ���� ����ִٰ� ������ (�׷��� �ڵ��Ǿ� ����)

		//ī�� �����߿� �����̶� ����ī�尡 �ִٸ� �װ� ��⿭ ī���̴�.
		if (firstCard->m_emCardPos != _DROP && secondCard->m_emCardPos != _DROP && thirdCard->m_emCardPos != _DROP)
			break;

		_emREG_TYPE regType = CardUtil::CheckStraightOrBundle(firstCard, secondCard, thirdCard);
		
		//�Ʒ� ó�� �ɼ� ������ ����ڵ带 �ִ´�.
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
	
	//��Ŀ�� ���� ����Ʈ�� ��´�.
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
	
	//�ִ� ī����� ���ī�带 �����Ͽ� 10�� �ּ� ī����� ���ī�带 ���� 9��
	if (totalCardCnt > MaxTotalCardCnt && totalCardCnt < MaxHandCardCnt)
		return false;

	//��ġ�� �ʰ� �븻�ϰ� U�� �Ǵ��� Ȯ���Ѵ�. CASE 1
	std::vector<CCARD*> tempCards = myHandCards;
	if (checkNotDuplicateCardsU(stanbyCards, stanbyCardsRegTypes, tempCards, autoResult) == true)
		return true;
	else
		autoResult.Clear();

	//�Ʒ����ʹ� ī�尡 ��ġ�� ��츦 �ݿ��� Uã�� CASE 2

	//�������� �̷��� ��Ʈ����Ʈ, ���� �ĺ���(Candidate) ����Ʈ�� �����.

	//����!!!!!!!!!!! �Ʒ� ��ƾ�� �ݵ�� ������� ȣ��Ǿ� ��
	std::vector<Candidate> candidateList;
	makeCandidateList(noJokerCards, candidateList, pDrop, stanbyCards, stanbyCardsRegTypes);

	std::vector<CandidateSet> candidateSetList;
	makeCandidateSetList(candidateSetList, candidateList, noJokerCards);
	
	// ��ȿ�� ��� �ĺ��� 3�� ã��
	if (searchUWithoutJoker(candidateSetList, autoResult) == true)
		return true;
	
	//��ȿ�� ��� �ĺ��� 3�� ã�� (��Ŀ)
	if (searchUWithJoker(candidateSetList, jokerCards, autoResult) == true)
		return true;

	//���̱� �ؼ� U�� �Ǵ��� ã��
	if (searchUWithAttach(candidateSetList, autoResult) == true)
		return true;
	
	return false;
}

bool AUTO_PLAY::AutoRegist(std::vector<CCARD*> & myHandCards, AutoResult & autoResult)
{
	//ī����� 3���� �ȵǸ� ����Ұ� ������ false ����
	if (myHandCards.size() < 3)
		return false;

	//��Ŀ�� ���� ����Ʈ�� ��´�.
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

	//�ڵ� ����� ���� ��Ŀ�� ����Ͽ� ������ ����ϰ� �� ���� ��Ʈ����Ʈ�� ����Ѵ�
	//�׷��Ƿ� �ּ��� ����� ���� ������ �ִ�.

	//��Ŀ�� ����Ͽ� ������ ��� �����Ѵ�.
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

	//��Ŀ�� ����Ͽ� ��Ʈ����Ʈ�� ��� �����Ѵ�.
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

	//���� ī��� ����� ��Ʈ����Ʈ ��������
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
	//��⿭�� �ִ� ī����� �ĺ��ڷ� �����.
	//��⿭�� �ִ� ī�带 ����� ī��� �־��ش�.
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

	//��Ʈ����Ʈ �ĺ��� �����
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

	//���� �ĺ��� �����
	CardUtil::SortNo(noJokerCards);

	//����!! i�� for�� �ȿ��� �ڵ����� ���� ���� �ʴ´�.
	for (int i = 0; i < (int)noJokerCards.size() - 2;)
	{
		//���� ���ڰ� 4���� �����϶�
		if (i < (int) noJokerCards.size() - 3 &&
			CardUtil::MakeBundle(noJokerCards[i], noJokerCards[i + 1], noJokerCards[i + 2], noJokerCards[i + 3]) == true)
		{
			//�������ڰ� 4���� ������ �� ������ �װ����� ���´�. �װ��� ������ �������� ���� ����ťó�� �Ʒ��� ���� �������.

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
			
			//4���� ī��� �̹� �� ����Ͽ��⿡ i�� �� ���� �ε����� ���� ��Ų��.
			i = i + MaxBundleCardCnt;
			continue;
		}
		else if (CardUtil::MakeBundle(noJokerCards[i], noJokerCards[i + 1], noJokerCards[i + 2]) == true) //���� ���ڰ� 3���� �����϶�
		{
			Candidate candidate;
			candidate.RegType = _BUNDLE;
			candidate.FirstCard = noJokerCards[i];
			candidate.SecondCard = noJokerCards[i + 1];
			candidate.ThirdCard = noJokerCards[i + 2];
			candidate.DropCard = dropCard;
			candidate.MakeCardInfo();
			candidateList.push_back(candidate);

			//3���� ī��� �̹� �� ����Ͽ��⿡ i�� �� ���� �ε����� ���� ��Ų��.
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
	//U�� �Ǳ� ���ؼ� ��������� �ϴ� ��� ��Ʈ ��
	static int uRegCnt = 3;

	CandidateSet candidateSet;
	
	if (candidateList.size() >= 3)
	{
		//n!/r!(n - r)! **** 5!/3!2! ****  5���� 3���� ������ ������� ������ ����Ǽ�
		//�ĺ��� ����Ʈ���� ��ϰ����� �ĺ��� ��Ʈ�� �����.
		int candidateSetListSize = factorial(candidateList.size()) / (factorial(uRegCnt) * factorial(candidateList.size() - uRegCnt));
		if (candidateSetListSize < 1) candidateSetListSize = 1;

		//3���� �̾Ƽ� 6������ ������ �ٲ㼭 candidateSet�� ������ �ϱ� ������ 6�� �����ش�.
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

	//�ߺ� candidateset ����
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
	//��ġ�� �ʴ� ��� �ĺ��� ������ �־�� �Ѵ�.
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
	//��Ŀ���ڸ� �����Ͽ� ��� �ĺ��� ������ �Ǵ��� Ȯ��
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
	//��ϰ� ���̱Ⱑ ��� ���ļ� 9���̸� U
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
	//��� CadidateSet�� ��Ŀ�� �����Ѵ�.
	for (int i = 0; i < (int)candidateSetList.size(); i++)
		candidateSetList[i].CanRegisterAllWithJoker(jokerCards);

	//��ϰ� ���̱Ⱑ ��� ���ļ� 9���̸� U
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

		//��⿭ ī�尡 ���� ����ִٰ� ������ (�׷��� �ڵ��Ǿ� ����)

		//ī�� �����߿� �����̶� ����ī�尡 �ִٸ� �װ� ��⿭ ī���̴�.
		if (firstCard->m_emCardPos != _DROP && secondCard->m_emCardPos != _DROP && thirdCard->m_emCardPos != _DROP)
			break;

		_emREG_TYPE regType = CardUtil::CheckStraightOrBundle(firstCard, secondCard, thirdCard);

		//�Ʒ� ó�� �ɼ� ������ ����ڵ带 �ִ´�.
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

	//��Ŀ�� ���� ����Ʈ�� ��´�.
	std::vector<CCARD*> noJokerCards;
	std::vector<CCARD*> jokerCards;
	for (int i = 0; i < (int)myHandCards.size(); i++)
	{
		if (myHandCards[i]->is_joker() == false)
			noJokerCards.push_back(myHandCards[i]);
		else
			jokerCards.push_back(myHandCards[i]);
	}

	//����!!!!!!!!!!! �Ʒ� ��ƾ�� �ݵ�� ������� ȣ��Ǿ� ��
	//�������� �̷��� ��Ʈ����Ʈ, ���� �ĺ���(Candidate) ����Ʈ�� �����.
	std::vector<Candidate> candidateList;
	makeCandidateList(noJokerCards, candidateList, NULL, stanbyCards, stanbyCardsRegTypes);

	std::vector<CandidateSet> candidateSetList;
	makeCandidateSetList(candidateSetList, candidateList, noJokerCards);

	//��Ϲ� ���̱��  CandidateSet�� ã�´�.
	searchBestCandidateSet(candidateSetList, jokerCards, autoResult);

	return true;
}

bool AUTO_PLAY::checkRegistStraight(std::vector<CCARD*> & pvtTemp)
{
	if (pvtTemp.empty())
		return true;

	static int jokboCardCount = 3;

	int jokboCount = (int)pvtTemp.size() / jokboCardCount;

	//���ī���� ����� 3�� ������� �Ѵ�.
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

	//���ī���� ����� 3�� ������� �Ѵ�.
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

	//��Ŀ�� ���� ����Ʈ�� ��´�.
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

	//��⿭�� �ִ� ī�带 ����� ī��� �־��ش�.
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

	//��Ŀ ���� ����� ��Ʈ����Ʈ ��������
	CardUtil::SortType(noJokerCards);
	while (CardUtil::ExtractStraight(noJokerCards, &straightCards) == true) {}

	CardUtil::SortNo(noJokerCards);
	while (CardUtil::ExtractBundle(noJokerCards, &bundleCards) == true) {}

	std::vector<int> backupJokerTypes;
	std::vector<int> backupJokerNos;

	//��Ŀ�� ����Ͽ� ��Ʈ����Ʈ�� ��� �����Ѵ�.
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
	
	//��Ŀ�� ����Ͽ� ������ ��� �����Ѵ�.
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

	//���� ī��� �ٿ� �ش�.
	AutoAttach(noJokerCards, autoResult, bundleCards, straightCards);

	//���� ī�带 ����� �־��ش�.
	for (int i = 0; i < (int)noJokerCards.size(); i++)
		autoResult.TrashCards.push_back(noJokerCards[i]);

	if (autoResult.RegStCards.size() + autoResult.RegBnCards.size() + autoResult.AttStCards.size() + autoResult.AttBnCards.size() >= AUTO_PLAY::MinUCardCnt)
	{
		return true;
	}
	else
	{
		//U�� ���� �ʴ´ٸ� ��Ŀ���� ���¸� ������� �������´�.
		//JokerType�� no�� ������� �����ش�.
		for (int i = 0; i < (int)backupJokerTypes.size(); i++)
		{
			backupJokerCards[i]->m_nJokerType = backupJokerTypes[i];
			backupJokerCards[i]->m_nJokerNo = backupJokerNos[i];
		}
		return false;
	}
		
}