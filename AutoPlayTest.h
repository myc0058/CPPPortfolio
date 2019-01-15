class AutoPlayTest
{
public:
	void TestALL()
	{
		CONSOLE_DEBUG_C("************** AUTO_PLAY TEST START **************", BLUE);

		if (ThreeStraightU() == true)
		{
			CONSOLE_DEBUG_C("ThreeStraightU() Test SUCCESS", GREEN);
		}
		else
		{
			CONSOLE_DEBUG_C("ThreeStraightU() Test Fail", RED);
		}

		if (ThreeBundleU() == true)
		{
			CONSOLE_DEBUG_C("ThreeBundleU() Test SUCCESS", GREEN);
		}
		else
		{
			CONSOLE_DEBUG_C("ThreeBundleU() Test Fail", RED);
		}

		if (TwoStraightOneBundleU() == true)
		{
			CONSOLE_DEBUG_C("TwoStraightOneBundleU() Test SUCCESS", GREEN);
		}
		else
		{
			CONSOLE_DEBUG_C("TwoStraightOneBundleU() Test Fail", RED);
		}

		if (DuplicateCardsU() == true)
		{
			CONSOLE_DEBUG_C("DuplicateCardsU() Test SUCCESS", GREEN);
		}
		else
		{
			CONSOLE_DEBUG_C("DuplicateCardsU() Test Fail", RED);
		}

		if (DuplicateCardsU2() == true)
		{
			CONSOLE_DEBUG_C("DuplicateCardsU2() Test SUCCESS", GREEN);
		}
		else
		{
			CONSOLE_DEBUG_C("DuplicateCardsU2() Test Fail", RED);
		}
		
		if (DuplicateCardsUWithJoker() == true)
		{
			CONSOLE_DEBUG_C("DuplicateCardsUWithJoker() Test SUCCESS", GREEN);
		}
		else
		{
			CONSOLE_DEBUG_C("DuplicateCardsUWithJoker() Test Fail", RED);
		}

		if (DuplicateCardsUWithJoker2() == true)
		{
			CONSOLE_DEBUG_C("DuplicateCardsUWithJoker2() Test SUCCESS", GREEN);
		}
		else
		{
			CONSOLE_DEBUG_C("DuplicateCardsUWithJoker2() Test Fail", RED);
		}

		if (PhomU() == true)
		{
			CONSOLE_DEBUG_C("PhomU() Test SUCCESS", GREEN);
		}
		else
		{
			CONSOLE_DEBUG_C("PhomU() Test Fail", RED);
		}

		if (RegistAttachU() == true)
		{
			CONSOLE_DEBUG_C("RegistAttachU() Test SUCCESS", GREEN);
		}
		else
		{
			CONSOLE_DEBUG_C("RegistAttachU() Test Fail", RED);
		}

		if (RegistAttachU2() == true)
		{
			CONSOLE_DEBUG_C("RegistAttachU2() Test SUCCESS", GREEN);
		}
		else
		{
			CONSOLE_DEBUG_C("RegistAttachU2() Test Fail", RED);
		}

		if (SparselyCardsUWithJoker2() == true)
		{
			CONSOLE_DEBUG_C("SparselyCardsUWithJoker2() Test SUCCESS", GREEN);
		}
		else
		{
			CONSOLE_DEBUG_C("SparselyCardsUWithJoker2() Test Fail", RED);
		}

		if (SparselyCardsUWithJoker1() == true)
		{
			CONSOLE_DEBUG_C("SparselyCardsUWithJoker1() Test SUCCESS", GREEN);
		}
		else
		{
			CONSOLE_DEBUG_C("SparselyCardsUWithJoker1() Test Fail", RED);
		}

		if (ProblemCardsUWithJoker1() == false)
		{
			CONSOLE_DEBUG_C("ProblemCardsUWithJoker1() Test SUCCESS", GREEN);
		}
		else
		{
			CONSOLE_DEBUG_C("ProblemCardsUWithJoker1() Test Fail", RED);
		}
		
		if (ProblemCardsUWithJoker2() == true)
		{
			CONSOLE_DEBUG_C("ProblemCardsUWithJoker2() Test SUCCESS", GREEN);
		}
		else
		{
			CONSOLE_DEBUG_C("ProblemCardsUWithJoker2() Test Fail", RED);
		}

		if (ProblemCardsUWithAndReadyJoker2() == true)
		{
			CONSOLE_DEBUG_C("ProblemCardsUWithAndReadyJoker2() Test SUCCESS", GREEN);
		}
		else
		{
			CONSOLE_DEBUG_C("ProblemCardsUWithAndReadyJoker2() Test Fail", RED);
		}

		if (SparselyCardsUWithJoker3() == true)
		{
			CONSOLE_DEBUG_C("SparselyCardsUWithJoker3() Test SUCCESS", GREEN);
		}
		else
		{
			CONSOLE_DEBUG_C("SparselyCardsUWithJoker3() Test Fail", RED);
		}

		if (SameNo2Bundle2JokerTest() == true)
		{
			CONSOLE_DEBUG_C("SameNo2Bundle2JokerTest() Test SUCCESS", GREEN);
		}
		else
		{
			CONSOLE_DEBUG_C("SameNo2Bundle2JokerTest() Test Fail", RED);
		}

		if (CheckUAttachProblem() == false)
		{
			CONSOLE_DEBUG_C("CheckUAttachProblem() Test SUCCESS", GREEN);
		}
		else
		{
			CONSOLE_DEBUG_C("CheckUAttachProblem() Test Fail", RED);
		}

		if (ProblemCheckUTest() == true)
		{
			CONSOLE_DEBUG_C("ProblemCheckUTest() Test SUCCESS", GREEN);
		}
		else
		{
			CONSOLE_DEBUG_C("ProblemCheckUTest() Test Fail", RED);
		}

		if (ProblemCheckUTest2() == true)
		{
			CONSOLE_DEBUG_C("ProblemCheckUTest2() Test SUCCESS", GREEN);
		}
		else
		{
			CONSOLE_DEBUG_C("ProblemCheckUTest2() Test Fail", RED);
		}
		
		if (ProblemCheckUTest3() == false)
		{
			CONSOLE_DEBUG_C("ProblemCheckUTest3() Test SUCCESS", GREEN);
		}
		else
		{
			CONSOLE_DEBUG_C("ProblemCheckUTest3() Test Fail", RED);
		}

		if (Regist2BundleWIthJokerTest() == true)
		{
			CONSOLE_DEBUG_C("Regist2BundleWIthJokerTest() Test SUCCESS", GREEN);
		}
		else
		{
			CONSOLE_DEBUG_C("Regist2BundleWIthJokerTest() Test Fail", RED);
		}

		if (Regist2BundleWIthJoker2Test() == true)
		{
			CONSOLE_DEBUG_C("Regist2BundleWIthJoker2Test() Test SUCCESS", GREEN);
		}
		else
		{
			CONSOLE_DEBUG_C("Regist2BundleWIthJoker2Test() Test Fail", RED);
		}

		if (ProblemCheckUTest4() == true)
		{
			CONSOLE_DEBUG_C("ProblemCheckUTest4() Test SUCCESS", GREEN);
		}
		else
		{
			CONSOLE_DEBUG_C("ProblemCheckUTest4() Test Fail", RED);
		}

		if (ProblemCheckUTest5() == false)
		{
			CONSOLE_DEBUG_C("ProblemCheckUTest5() Test SUCCESS", GREEN);
		}
		else
		{
			CONSOLE_DEBUG_C("ProblemCheckUTest5() Test Fail", RED);
		}

		CONSOLE_DEBUG_C("************** AUTO_PLAY TEST FINISH **************", BLUE);
	}

private:
	bool ThreeStraightU()
	{
		CSTRAIGHT _regStraight;
		CBUNDLE _regBundle;
		AUTO_PLAY autoPlay;
		autoPlay.setReg(&_regStraight, &_regBundle);
		AutoResult autoResult;
		std::vector<CCARD*> vtHandCards;
		/*
		int nNumber[playerCnt][ndivide_card] = {
		{ 0, 1, 2, 3, 4, 5, 6, 7, 8 },
		{ 13, 14, 16, 17, 19, 20, 22, 23, 25 }
		};
		*/
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(0);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(1);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(2);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(3);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(4);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(5);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(6);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(7);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(8);

		bool result = autoPlay.Is_U(vtHandCards, NULL, autoResult);

		result &= autoResult.RegStCards.size() == 9;
		result &= autoResult.RegBnCards.size() == 0;
		result &= autoResult.AttStCards.size() == 0;
		result &= autoResult.AttBnCards.size() == 0;
		result &= autoResult.TrashCards.size() == 0;

		for (int i = 0; i < (int)vtHandCards.size(); i++)
		{
			delete vtHandCards[i];
		}

		vtHandCards.clear();

		return result;
	}

	bool ThreeBundleU()
	{
		CSTRAIGHT _regStraight;
		CBUNDLE _regBundle;
		AUTO_PLAY autoPlay;
		autoPlay.setReg(&_regStraight, &_regBundle);
		AutoResult autoResult;
		std::vector<CCARD*> vtHandCards;
		
		/* 선이 받자마자 U일때 ( 3 번들)
		int nNumber[playerCnt][ndivide_card] = {
		{ 0, 13, 26, 2, 15, 28, 3, 16, 29 },
		{ 18, 19, 21, 22, 31, 32, 45, 46, 49 }
		};
		*/
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(0);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(13);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(26);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(2);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(15);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(28);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(3);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(16);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(29);

		bool result = autoPlay.Is_U(vtHandCards, NULL, autoResult);

		result &= autoResult.RegStCards.size() == 0;
		result &= autoResult.RegBnCards.size() == 9;
		result &= autoResult.AttStCards.size() == 0;
		result &= autoResult.AttBnCards.size() == 0;
		result &= autoResult.TrashCards.size() == 0;

		for (int i = 0; i < (int)vtHandCards.size(); i++)
		{
			delete vtHandCards[i];
		}

		vtHandCards.clear();

		return result;
	}

	bool TwoStraightOneBundleU()
	{
		CSTRAIGHT _regStraight;
		CBUNDLE _regBundle;
		AUTO_PLAY autoPlay;
		autoPlay.setReg(&_regStraight, &_regBundle);
		AutoResult autoResult;
		std::vector<CCARD*> vtHandCards;

		/* 선이 받자마자 U일때 ( 2 스트레이트, 1 번들 123 456 111)
		int nNumber[playerCnt][ndivide_card] = {
		{ 0, 1, 2, 3, 4, 5, 13, 26, 39 },
		{ 40, 41, 16, 17, 19, 20, 22, 23, 25 }
		};
		*/
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(0);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(1);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(2);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(3);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(4);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(5);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(13);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(26);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(39);

		bool result = autoPlay.Is_U(vtHandCards, NULL, autoResult);

		result &= autoResult.RegStCards.size() == 6;
		result &= autoResult.RegBnCards.size() == 3;
		result &= autoResult.AttStCards.size() == 0;
		result &= autoResult.AttBnCards.size() == 0;
		result &= autoResult.TrashCards.size() == 0;

		for (int i = 0; i < (int)vtHandCards.size(); i++)
		{
			delete vtHandCards[i];
		}

		vtHandCards.clear();

		return result;
	}

	bool DuplicateCardsU()
	{
		CSTRAIGHT _regStraight;
		CBUNDLE _regBundle;
		AUTO_PLAY autoPlay;
		autoPlay.setReg(&_regStraight, &_regBundle);
		AutoResult autoResult;
		std::vector<CCARD*> vtHandCards;

		/* 선이 받자마자 U일때 ( 카드가 겹치는 경우 - 2 스트레이트, 1 번들, 222 345 345)
		int nNumber[playerCnt][ndivide_card] = {
		{ 1, 14, 27, 2, 3, 4, 28, 29, 30 },
		{ 40, 41, 16, 17, 19, 20, 22, 23, 25 }
		};
		*/
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(1);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(14);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(27);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(2);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(3);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(4);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(28);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(29);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(30);

		bool result = autoPlay.Is_U(vtHandCards, NULL, autoResult);

		result &= autoResult.RegStCards.size() == 6;
		result &= autoResult.RegBnCards.size() == 3;
		result &= autoResult.AttStCards.size() == 0;
		result &= autoResult.AttBnCards.size() == 0;
		result &= autoResult.TrashCards.size() == 0;

		for (int i = 0; i < (int)vtHandCards.size(); i++)
		{
			delete vtHandCards[i];
		}

		vtHandCards.clear();

		return result;
	}

	bool DuplicateCardsU2()
	{
		CSTRAIGHT _regStraight;
		CBUNDLE _regBundle;
		AUTO_PLAY autoPlay;
		autoPlay.setReg(&_regStraight, &_regBundle);
		AutoResult autoResult;
		std::vector<CCARD*> vtHandCards;

		/* 선이 받자마자 U일때 ( 카드가 겹치는 경우 - 1 스트레이트, 2 번들, 345 444 666)
		int nNumber[playerCnt][ndivide_card] = {
		{ 2, 3, 4, 16, 29, 42, 5, 18, 31 },
		{ 40, 41, 43, 17, 19, 20, 22, 23, 25 }
		};
		*/
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(2);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(3);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(4);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(16);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(29);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(42);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(5);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(18);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(31);

		bool result = autoPlay.Is_U(vtHandCards, NULL, autoResult);

		result &= autoResult.RegStCards.size() == 3;
		result &= autoResult.RegBnCards.size() == 6;
		result &= autoResult.AttStCards.size() == 0;
		result &= autoResult.AttBnCards.size() == 0;
		result &= autoResult.TrashCards.size() == 0;

		for (int i = 0; i < (int)vtHandCards.size(); i++)
		{
			delete vtHandCards[i];
		}

		vtHandCards.clear();

		return result;
	}

	bool DuplicateCardsUWithJoker()
	{
		CSTRAIGHT _regStraight;
		CBUNDLE _regBundle;
		AUTO_PLAY autoPlay;
		autoPlay.setReg(&_regStraight, &_regBundle);
		AutoResult autoResult;
		std::vector<CCARD*> vtHandCards;

		/* 선이 받자마자 U일때 ( 카드가 겹치고 조커로 해결 34567 44 66 J)
		int nNumber[playerCnt][ndivide_card] = {
		{ 2, 3, 4, 5, 6, 16, 29, 18, 31 },
		{ 40, 41, 16, 17, 19, 20, 22, 23, 25 }
		};
		*/
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(2);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(3);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(4);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(5);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(6);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(16);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(29);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(18);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(31);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(52);

		bool result = autoPlay.Is_U(vtHandCards, NULL, autoResult);

		result &= autoResult.RegStCards.size() == 3;
		result &= autoResult.RegBnCards.size() == 6;
		result &= autoResult.AttStCards.size() == 0;
		result &= autoResult.AttBnCards.size() == 0;
		result &= autoResult.TrashCards.size() == 1;

		for (int i = 0; i < (int)vtHandCards.size(); i++)
		{
			delete vtHandCards[i];
		}

		vtHandCards.clear();

		return result;
	}

	bool DuplicateCardsUWithJoker2()
	{
		CSTRAIGHT _regStraight;
		CBUNDLE _regBundle;
		AUTO_PLAY autoPlay;
		autoPlay.setReg(&_regStraight, &_regBundle);
		AutoResult autoResult;
		std::vector<CCARD*> vtHandCards;

		/* 선이 받자마자 U일때 ( 카드가 겹치고 조커로 해결 1234 2 234 JJ)
		int nNumber[playerCnt][ndivide_card] = {
		{ 0, 1, 2, 3, 14, 27, 28, 29, 52 },
		{ 40, 41, 16, 17, 19, 20, 22, 23, 25 }
		};
		giveSunlastCardJoker = true;
		*/
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(0);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(1);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(2);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(3);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(14);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(27);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(28);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(29);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(52);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(53);

		bool result = autoPlay.Is_U(vtHandCards, NULL, autoResult);

		result &= autoResult.RegStCards.size() == 6;
		result &= autoResult.RegBnCards.size() == 3;
		result &= autoResult.AttStCards.size() == 0;
		result &= autoResult.AttBnCards.size() == 0;
		result &= autoResult.TrashCards.size() == 1;

		for (int i = 0; i < (int)vtHandCards.size(); i++)
		{
			delete vtHandCards[i];
		}

		vtHandCards.clear();

		return result;
	}

	bool PhomU()
	{
		CSTRAIGHT _regStraight;
		CBUNDLE _regBundle;
		AUTO_PLAY autoPlay;
		autoPlay.setReg(&_regStraight, &_regBundle);
		AutoResult autoResult;
		std::vector<CCARD*> vtHandCards;

		/* 선이 아닌 사람이 폼해서 U일때
		int nNumber[playerCnt][ndivide_card] = {
		{ 8,										14, 16, 17, 19, 20, 22, 23, 25 },
		{ 0, 1, 2, 3, 4, 5, 6, 7,					10 }
		};
		*/
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(0);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(1);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(2);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(3);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(4);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(5);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(6);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(7);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(10);

		CCARD * pDropCard = new CCARD();
		pDropCard->clear();
		pDropCard->m_emCardPos = _DROP;
		pDropCard->set(8);

		bool result = autoPlay.Is_U(vtHandCards, pDropCard, autoResult);

		result &= autoResult.PhomCards.size() == 3;
		result &= autoResult.RegStCards.size() == 6;
		result &= autoResult.RegBnCards.size() == 0;
		result &= autoResult.AttStCards.size() == 0;
		result &= autoResult.AttBnCards.size() == 0;
		result &= autoResult.TrashCards.size() == 1;

		for (int i = 0; i < (int)vtHandCards.size(); i++)
		{
			delete vtHandCards[i];
		}

		vtHandCards.clear();
		
		delete pDropCard;

		return result;
	}

	bool RegistAttachU()
	{
		CSTRAIGHT _regStraight;

		CCARD * reg1 = new CCARD();
		reg1->m_emCardPos = _REG_TABLE;
		reg1->set(1);
		_regStraight.addReg(reg1);
		CCARD * reg2 = new CCARD();
		reg2->m_emCardPos = _REG_TABLE;
		reg2->set(2);
		_regStraight.addReg(reg2);
		CCARD * reg3 = new CCARD();
		reg3->m_emCardPos = _REG_TABLE;
		reg3->set(3);
		_regStraight.addReg(reg3);

		CCARD * reg4 = new CCARD();
		reg4->m_emCardPos = _REG_TABLE;
		reg4->set(4);
		_regStraight.addReg(reg4);
		CCARD * reg5 = new CCARD();
		reg5->m_emCardPos = _REG_TABLE;
		reg5->set(5);
		_regStraight.addReg(reg5);
		CCARD * reg6 = new CCARD();
		reg6->m_emCardPos = _REG_TABLE;
		reg6->set(6);
		_regStraight.addReg(reg6);
		
		
		CBUNDLE _regBundle;
		AUTO_PLAY autoPlay;
		autoPlay.setReg(&_regStraight, &_regBundle);
		AutoResult autoResult;
		std::vector<CCARD*> vtHandCards;

		/* 선이 아닌 사람이 붙이기를 등록턴에서 모든 카드를 한 경우 U
		int nNumber[playerCnt][ndivide_card] = {
		{ 1, 2, 3, 4, 5, 6,							13, 14, 16},
		{ 26, 27, 28, 29, 30, 31, 0, 7, 8 }
		};
		*/
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(26);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(27);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(28);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(29);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(30);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(31);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(0);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(7);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(8);

		bool result = autoPlay.Is_U(vtHandCards, NULL, autoResult);
		
		result &= autoResult.RegStCards.size() == 6;
		result &= autoResult.RegBnCards.size() == 0;
		result &= autoResult.AttStCards.size() == 3;
		result &= autoResult.AttBnCards.size() == 0;
		result &= autoResult.TrashCards.size() == 0;

		for (int i = 0; i < (int)vtHandCards.size(); i++)
		{
			delete vtHandCards[i];
		}

		vtHandCards.clear();

		delete reg1;
		delete reg2;
		delete reg3;
		delete reg4;
		delete reg5;
		delete reg6;

		return result;
	}

	bool RegistAttachU2()
	{
		CSTRAIGHT _regStraight;

		CCARD * reg1 = new CCARD();
		reg1->m_emCardPos = _REG_TABLE;
		reg1->set(1);
		_regStraight.addReg(reg1);
		CCARD * reg2 = new CCARD();
		reg2->m_emCardPos = _REG_TABLE;
		reg2->set(2);
		_regStraight.addReg(reg2);
		CCARD * reg3 = new CCARD();
		reg3->m_emCardPos = _REG_TABLE;
		reg3->set(3);
		_regStraight.addReg(reg3);

		CBUNDLE _regBundle;

		CCARD * reg4 = new CCARD();
		reg4->m_emCardPos = _REG_TABLE;
		reg4->set(4);
		_regBundle.addReg(reg4);
		CCARD * reg5 = new CCARD();
		reg5->m_emCardPos = _REG_TABLE;
		reg5->set(17);
		_regBundle.addReg(reg5);
		CCARD * reg6 = new CCARD();
		reg6->m_emCardPos = _REG_TABLE;
		reg6->set(30);
		_regBundle.addReg(reg6);

		AUTO_PLAY autoPlay;
		autoPlay.setReg(&_regStraight, &_regBundle);
		AutoResult autoResult;
		std::vector<CCARD*> vtHandCards;

		/* 선이 아닌 사람이 붙이기를 등록턴에서 모든 카드를 한 경우 U
		int nNumber[playerCnt][ndivide_card] = {
		{ 1, 2, 3, 4, 17, 30,							13, 14, 16},
		{ 26, 27, 28, 29, 30, 31, 32, 0, 43 }
		};
		*/
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(26);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(27);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(28);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(29);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(30);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(31);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(32);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(0);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(43);

		bool result = autoPlay.Is_U(vtHandCards, NULL, autoResult);

		result &= autoResult.RegStCards.size() == 6;
		result &= autoResult.RegBnCards.size() == 0;
		result &= autoResult.AttStCards.size() == 2;
		result &= autoResult.AttBnCards.size() == 1;
		result &= autoResult.TrashCards.size() == 0;

		for (int i = 0; i < (int)vtHandCards.size(); i++)
		{
			delete vtHandCards[i];
		}

		vtHandCards.clear();

		delete reg1;
		delete reg2;
		delete reg3;
		delete reg4;
		delete reg5;
		delete reg6;

		return result;
	}

	bool SparselyCardsUWithJoker2()
	{
		CSTRAIGHT _regStraight;
		CBUNDLE _regBundle;
		AUTO_PLAY autoPlay;
		autoPlay.setReg(&_regStraight, &_regBundle);
		AutoResult autoResult;
		std::vector<CCARD*> vtHandCards;

		/* 조커 두장으로 띄엄띄엄있는 숫자 U만들기 2 4 666 2 4 JJ
		int nNumber[playerCnt][ndivide_card] = {
		{ 1, 3, 5, 18, 27, 29, 31, 52, 53 },
		{ 26, 40, 28, 42, 30, 43, 0, 7,	40 }
		};
		*/
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(1);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(3);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(5);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(18);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(27);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(29);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(31);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(52);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(53);

		bool result = autoPlay.Is_U(vtHandCards, NULL, autoResult);

		result &= autoResult.RegStCards.size() == 6;
		result &= autoResult.RegBnCards.size() == 3;
		result &= autoResult.AttStCards.size() == 0;
		result &= autoResult.AttBnCards.size() == 0;
		result &= autoResult.TrashCards.size() == 0;

		for (int i = 0; i < (int)vtHandCards.size(); i++)
		{
			delete vtHandCards[i];
		}

		vtHandCards.clear();

		return result;
	}

	bool SparselyCardsUWithJoker1()
	{
		CSTRAIGHT _regStraight;
		CBUNDLE _regBundle;
		AUTO_PLAY autoPlay;
		autoPlay.setReg(&_regStraight, &_regBundle);
		AutoResult autoResult;
		std::vector<CCARD*> vtHandCards;

		/* 조커 두장으로 띄엄띄엄있는 숫자 U만들기 2 4 666 678 J
		int nNumber[playerCnt][ndivide_card] = {
		{ 1, 3, 5, 18, 31, 44, 6, 7, 52 },
		{ 26, 40, 28, 42, 30, 43, 0, 7,	40 }
		};
		*/
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(1);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(3);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(5);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(18);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(31);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(44);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(6);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(7);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(52);

		bool result = autoPlay.Is_U(vtHandCards, NULL, autoResult);

		result &= autoResult.RegStCards.size() == 6;
		result &= autoResult.RegBnCards.size() == 3;
		result &= autoResult.AttStCards.size() == 0;
		result &= autoResult.AttBnCards.size() == 0;
		result &= autoResult.TrashCards.size() == 0;

		for (int i = 0; i < (int)vtHandCards.size(); i++)
		{
			delete vtHandCards[i];
		}

		vtHandCards.clear();

		return result;
	}

	bool ProblemCardsUWithJoker1()
	{
		CSTRAIGHT _regStraight;
		CBUNDLE _regBundle;
		AUTO_PLAY autoPlay;
		autoPlay.setReg(&_regStraight, &_regBundle);
		AutoResult autoResult;
		std::vector<CCARD*> vtHandCards;

		/* 조커 한장이 껴있는 문제를 일으키는 케이스
		C3, C4, C5
		J(1,4), C5, C6,
		H3, S4, D6,
		D9, H10 (버리기)
		*/
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(15);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _DROP;
		vtHandCards[vtHandCards.size() - 1]->set(16);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(17);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(52);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(18);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(41);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(3);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(31);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(34);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(48);

		bool result = autoPlay.Is_U(vtHandCards, NULL, autoResult);

		result &= autoResult.RegStCards.size() == 0;
		result &= autoResult.RegBnCards.size() == 0;
		result &= autoResult.AttStCards.size() == 0;
		result &= autoResult.AttBnCards.size() == 0;
		result &= autoResult.TrashCards.size() == 0;

		for (int i = 0; i < (int)vtHandCards.size(); i++)
		{
			delete vtHandCards[i];
		}

		vtHandCards.clear();

		return result;
	}

	bool ProblemCardsUWithJoker2()
	{
		CSTRAIGHT _regStraight;
		CBUNDLE _regBundle;
		AUTO_PLAY autoPlay;
		autoPlay.setReg(&_regStraight, &_regBundle);
		AutoResult autoResult;
		std::vector<CCARD*> vtHandCards;

		/* 폼한카드가 있고 조커 2장일때 문제
		D9(drop), S9, J
		S1, H1, J,
		C2, C3, C4,C5
		*/

		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _DROP;
		vtHandCards[vtHandCards.size() - 1]->set(34);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(8);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(52);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(0);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(39);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(14);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(15);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(16);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(17);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(53);

		bool result = autoPlay.Is_U(vtHandCards, NULL, autoResult);

		result &= autoResult.RegStCards.size() == 3;
		result &= autoResult.RegBnCards.size() == 6;
		result &= autoResult.AttStCards.size() == 1;
		result &= autoResult.AttBnCards.size() == 0;
		result &= autoResult.TrashCards.size() == 0;

		for (int i = 0; i < (int)vtHandCards.size(); i++)
		{
			delete vtHandCards[i];
		}

		vtHandCards.clear();

		return result;
	}

	bool ProblemCardsUWithAndReadyJoker2()
	{
		CSTRAIGHT _regStraight;
		CBUNDLE _regBundle;
		AUTO_PLAY autoPlay;
		autoPlay.setReg(&_regStraight, &_regBundle);
		AutoResult autoResult;
		std::vector<CCARD*> vtHandCards;

		/* U체크 하면서 결과에 같은 스트레이트카드가 6장 들어있었던 버그
		S8, S9, Joker4(Drop)
		S6, H6, C6(Drop),
		D11, D12, Joker1(Drop),
		*/

		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _STANDBY1;
		vtHandCards[vtHandCards.size() - 1]->set(7);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _STANDBY1;
		vtHandCards[vtHandCards.size() - 1]->set(8);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _DROP;
		vtHandCards[vtHandCards.size() - 1]->set(55);

		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _STANDBY2;
		vtHandCards[vtHandCards.size() - 1]->set(5);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _STANDBY2;
		vtHandCards[vtHandCards.size() - 1]->set(44);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _DROP;
		vtHandCards[vtHandCards.size() - 1]->set(18);

		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(36);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(37);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(52);
		

		bool result = autoPlay.Is_U(vtHandCards, NULL, autoResult);

		result &= autoResult.RegStCards.size() == 6;
		result &= autoResult.RegBnCards.size() == 3;
		result &= autoResult.AttStCards.size() == 0;
		result &= autoResult.AttBnCards.size() == 0;
		result &= autoResult.TrashCards.size() == 0;

		for (int i = 0; i < (int)vtHandCards.size(); i++)
		{
			delete vtHandCards[i];
		}

		vtHandCards.clear();

		return result;
	}

	bool SparselyCardsUWithJoker3()
	{
		CSTRAIGHT _regStraight;
		CBUNDLE _regBundle;
		AUTO_PLAY autoPlay;
		autoPlay.setReg(&_regStraight, &_regBundle);
		AutoResult autoResult;
		std::vector<CCARD*> vtHandCards;

		/* 조커 세장으로 띄엄띄엄있는 숫자 U만들기 2 4 6 6 3 5 JJJ
		int nNumber[playerCnt][ndivide_card] = {
		{ 1, 3, 5, 31, 28, 30, 52, 53, 54 },
		{ 26, 40, 28, 42, 30, 43, 0, 7,	40 }
		};
		*/
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(1);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(3);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(5);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(31);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(28);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(30);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(52);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(53);
		vtHandCards.push_back(new CCARD());
		vtHandCards[vtHandCards.size() - 1]->clear();
		vtHandCards[vtHandCards.size() - 1]->m_emCardPos = _HAND;
		vtHandCards[vtHandCards.size() - 1]->set(54);

		bool result = autoPlay.Is_U(vtHandCards, NULL, autoResult);

		result &= autoResult.RegStCards.size() == 6;
		result &= autoResult.RegBnCards.size() == 3;
		result &= autoResult.AttStCards.size() == 0;
		result &= autoResult.AttBnCards.size() == 0;
		result &= autoResult.TrashCards.size() == 0;

		for (int i = 0; i < (int)vtHandCards.size(); i++)
		{
			delete vtHandCards[i];
		}

		vtHandCards.clear();

		return result;
	}

	bool SameNo2Bundle2JokerTest()
	{
		CSTRAIGHT _regStraight;
		CBUNDLE _regBundle;
		AUTO_PLAY autoPlay;
		autoPlay.setReg(&_regStraight, &_regBundle);
		
		std::vector<CCARD*> vtRegStrCards;
		std::vector<CCARD*> vtRegBunCards;
		std::vector<CCARD*> vtAttStrCards;
		std::vector<CCARD*> vtAttBunCards;

		AddCard(vtRegBunCards, 0, _HAND);
		AddCard(vtRegBunCards, 13, _HAND);
		AddCard(vtRegBunCards, 54, _HAND);
		AddCard(vtRegBunCards, 26, _HAND);
		AddCard(vtRegBunCards, 39, _HAND);
		AddCard(vtRegBunCards, 55, _HAND);

		bool result = autoPlay.CheckRegistAttach(vtRegStrCards, vtRegBunCards, vtAttStrCards, vtAttBunCards);

		for (int i = 0; i < (int)vtRegBunCards.size(); i++)
		{
			delete vtRegBunCards[i];
		}

		vtRegBunCards.clear();

		return result;
	}

	void AddCard(std::vector<CCARD *> &vtCards, int cardIdx, _emCARD_POS cardPos)
	{
		vtCards.push_back(new CCARD());
		vtCards[vtCards.size() - 1]->clear();
		vtCards[vtCards.size() - 1]->m_emCardPos = cardPos;
		vtCards[vtCards.size() - 1]->set(cardIdx);
	}
	
	bool CheckUAttachProblem()
	{
		CSTRAIGHT _regStraight;
		CBUNDLE _regBundle;
		AUTO_PLAY autoPlay;
		autoPlay.setReg(&_regStraight, &_regBundle);
		AutoResult autoResult;
		std::vector<CCARD*> vtHandCards;

		AddCard(vtHandCards, 2, _HAND);
		AddCard(vtHandCards, 6, _HAND);
		AddCard(vtHandCards, 17, _HAND);

		AddCard(vtHandCards, 28, _HAND);
		AddCard(vtHandCards, 29, _HAND);
		AddCard(vtHandCards, 30, _HAND);

		AddCard(vtHandCards, 32, _HAND);
		AddCard(vtHandCards, 33, _HAND);
		AddCard(vtHandCards, 45, _HAND);

		//U가 아닌데 U라고 나오는 문제를 수정하기 위한 테스트
		bool result = autoPlay.Is_U(vtHandCards, NULL, autoResult);

		for (int i = 0; i < (int)vtHandCards.size(); i++)
		{
			delete vtHandCards[i];
		}

		vtHandCards.clear();

		return result;
	}

	bool ProblemCheckUTest()
	{
		CSTRAIGHT _regStraight;
		CBUNDLE _regBundle;
		AUTO_PLAY autoPlay;
		autoPlay.setReg(&_regStraight, &_regBundle);
		AutoResult autoResult;
		std::vector<CCARD*> vtHandCards;

		AddCard(vtHandCards, 23, _HAND);
		AddCard(vtHandCards, 24, _HAND);
		AddCard(vtHandCards, 52, _HAND);

		AddCard(vtHandCards, 1, _HAND);
		AddCard(vtHandCards, 14, _HAND);
		AddCard(vtHandCards, 27, _HAND);

		AddCard(vtHandCards, 35, _HAND);
		AddCard(vtHandCards, 36, _HAND);
		AddCard(vtHandCards, 53, _HAND);

		//조커 2장을 써서 U인데 U가 아니라고 나오는 버그 수정
		bool result = autoPlay.Is_U(vtHandCards, NULL, autoResult);

		result &= autoResult.RegStCards.size() == 6;
		result &= autoResult.RegBnCards.size() == 3;
		result &= autoResult.AttStCards.size() == 0;
		result &= autoResult.AttBnCards.size() == 0;
		result &= autoResult.TrashCards.size() == 0;

		for (int i = 0; i < (int)vtHandCards.size(); i++)
		{
			delete vtHandCards[i];
		}

		vtHandCards.clear();

		return result;
	}

	bool ProblemCheckUTest2()
	{
		CSTRAIGHT _regStraight;
		CBUNDLE _regBundle;
		AUTO_PLAY autoPlay;
		autoPlay.setReg(&_regStraight, &_regBundle);
		AutoResult autoResult;
		std::vector<CCARD*> vtHandCards;

		//(C11, 12, 13)(C10, D10, H10)(S11, S12, Joker)

		AddCard(vtHandCards, 23, _HAND);
		AddCard(vtHandCards, 24, _HAND);
		AddCard(vtHandCards, 25, _HAND);

		AddCard(vtHandCards, 22, _HAND);
		AddCard(vtHandCards, 35, _HAND);
		AddCard(vtHandCards, 48, _HAND);

		AddCard(vtHandCards, 10, _HAND);
		AddCard(vtHandCards, 11, _HAND);
		AddCard(vtHandCards, 52, _HAND);

		//조커 2장을 써서 U인데 U가 아니라고 나오는 버그 수정
		bool result = autoPlay.Is_U(vtHandCards, NULL, autoResult);

		result &= autoResult.RegStCards.size() == 6;
		result &= autoResult.RegBnCards.size() == 3;
		result &= autoResult.AttStCards.size() == 0;
		result &= autoResult.AttBnCards.size() == 0;
		result &= autoResult.TrashCards.size() == 0;

		for (int i = 0; i < (int)vtHandCards.size(); i++)
		{
			delete vtHandCards[i];
		}

		vtHandCards.clear();

		return result;
	}

	bool ProblemCheckUTest3()
	{
		CSTRAIGHT _regStraight;
		CBUNDLE _regBundle;
		AUTO_PLAY autoPlay;
		autoPlay.setReg(&_regStraight, &_regBundle);
		AutoResult autoResult;
		std::vector<CCARD*> vtHandCards;

		AddCard(vtHandCards, 44, _DROP);
		AddCard(vtHandCards, 52, _STANDBY1);
		AddCard(vtHandCards, 46, _STANDBY1);

		AddCard(vtHandCards, 40, _HAND);
		AddCard(vtHandCards, 32, _HAND);
		AddCard(vtHandCards, 21, _HAND);

		AddCard(vtHandCards, 38, _HAND);
		AddCard(vtHandCards, 45, _HAND);
		AddCard(vtHandCards, 48, _HAND);

		AddCard(vtHandCards, 43, _HAND);

		//조커 2장을 써서 U인데 U가 아니라고 나오는 버그 수정
		bool result = autoPlay.Is_U(vtHandCards, NULL, autoResult);

		for (int i = 0; i < (int)vtHandCards.size(); i++)
		{
			delete vtHandCards[i];
		}

		vtHandCards.clear();

		return result;
	}

	bool ProblemCheckUTest4()
	{
		CSTRAIGHT _regStraight;
		CBUNDLE _regBundle;
		AUTO_PLAY autoPlay;
		autoPlay.setReg(&_regStraight, &_regBundle);
		AutoResult autoResult;
		std::vector<CCARD*> vtHandCards;

		//6, 19, 32, 34, 33, 35, 16, 17, 38, 52
		AddCard(vtHandCards, 6, _DROP);
		AddCard(vtHandCards, 19, _STANDBY1);
		AddCard(vtHandCards, 32, _STANDBY1);

		AddCard(vtHandCards, 34, _DROP);
		AddCard(vtHandCards, 33, _STANDBY2);
		AddCard(vtHandCards, 35, _STANDBY2);

		AddCard(vtHandCards, 16, _HAND);
		AddCard(vtHandCards, 17, _HAND);
		AddCard(vtHandCards, 38, _HAND);

		AddCard(vtHandCards, 52, _HAND);

		//U가 되야 함
		bool result = autoPlay.Is_U(vtHandCards, NULL, autoResult);

		result &= autoResult.RegStCards.size() == 6;
		result &= autoResult.RegBnCards.size() == 3;
		result &= autoResult.AttStCards.size() == 0;
		result &= autoResult.AttBnCards.size() == 0;
		result &= autoResult.TrashCards.size() == 1;

		for (int i = 0; i < (int)vtHandCards.size(); i++)
		{
			delete vtHandCards[i];
		}

		vtHandCards.clear();

		return result;
	}

	bool ProblemCheckUTest5()
	{
		CSTRAIGHT _regStraight;
		CBUNDLE _regBundle;
		AUTO_PLAY autoPlay;
		autoPlay.setReg(&_regStraight, &_regBundle);
		AutoResult autoResult;
		std::vector<CCARD*> vtHandCards;

		//36, 35, 52, 32, 33, 34, 14, 16, 17, 19
		AddCard(vtHandCards, 36, _DROP);
		AddCard(vtHandCards, 35, _STANDBY1);
		AddCard(vtHandCards, 52, _STANDBY1);

		AddCard(vtHandCards, 32, _DROP);
		AddCard(vtHandCards, 33, _STANDBY2);
		AddCard(vtHandCards, 34, _STANDBY2);

		AddCard(vtHandCards, 14, _HAND);
		AddCard(vtHandCards, 16, _HAND);
		AddCard(vtHandCards, 17, _HAND);

		AddCard(vtHandCards, 19, _HAND);

		//U가 되면 안됨
		bool result = autoPlay.Is_U(vtHandCards, NULL, autoResult);

		for (int i = 0; i < (int)vtHandCards.size(); i++)
		{
			delete vtHandCards[i];
		}

		vtHandCards.clear();

		return result;
	}

	bool Regist2BundleWIthJokerTest()
	{
		CSTRAIGHT _regStraight;
		CBUNDLE _regBundle;
		AUTO_PLAY autoPlay;
		autoPlay.setReg(&_regStraight, &_regBundle);

		std::vector<CCARD*> vtRegStrCards;
		std::vector<CCARD*> vtRegBunCards;
		std::vector<CCARD*> vtAttStrCards;
		std::vector<CCARD*> vtAttBunCards;

		AddCard(vtRegBunCards, 17, _HAND);
		AddCard(vtRegBunCards, 30, _HAND);
		AddCard(vtRegBunCards, 43, _HAND);
		AddCard(vtRegBunCards, 7, _HAND);
		AddCard(vtRegBunCards, 20, _HAND);
		AddCard(vtRegBunCards, 52, _HAND);

		bool result = autoPlay.CheckRegistAttach(vtRegStrCards, vtRegBunCards, vtAttStrCards, vtAttBunCards);

		for (int i = 0; i < (int)vtRegBunCards.size(); i++)
		{
			delete vtRegBunCards[i];
		}

		vtRegBunCards.clear();

		return result;
	}

	bool Regist2BundleWIthJoker2Test()
	{
		CSTRAIGHT _regStraight;
		CBUNDLE _regBundle;
		AUTO_PLAY autoPlay;
		autoPlay.setReg(&_regStraight, &_regBundle);

		std::vector<CCARD*> vtRegStrCards;
		std::vector<CCARD*> vtRegBunCards;
		std::vector<CCARD*> vtAttStrCards;
		std::vector<CCARD*> vtAttBunCards;

		AddCard(vtRegBunCards, 9, _HAND);
		AddCard(vtRegBunCards, 22, _HAND);
		AddCard(vtRegBunCards, 52, _HAND);
		AddCard(vtRegBunCards, 7, _HAND);
		AddCard(vtRegBunCards, 20, _HAND);
		AddCard(vtRegBunCards, 53, _HAND);

		bool result = autoPlay.CheckRegistAttach(vtRegStrCards, vtRegBunCards, vtAttStrCards, vtAttBunCards);

		for (int i = 0; i < (int)vtRegBunCards.size(); i++)
		{
			delete vtRegBunCards[i];
		}

		vtRegBunCards.clear();

		return result;
	}
};