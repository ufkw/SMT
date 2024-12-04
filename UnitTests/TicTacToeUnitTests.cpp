#include "pch.h"

#include "CppUnitTest.h"
#include "../TicTacToe/TicTacToe.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(UnitTests)
	{
	public:

		/// <summary>
		/// Test case
		/// </summary>
		TEST_METHOD(TestCaseConstructor1)
		{
			TicTacToe tic_tac_toe_game = TicTacToe();
			Assert::AreEqual(3, (int)tic_tac_toe_game.GetBoard().size());
		}


		/// <summary>
		/// Test case
		/// </summary>
		TEST_METHOD(TestCaseConstructor2)
		{
			TicTacToe tic_tac_toe_game = TicTacToe();
			Assert::AreEqual(3, (int)tic_tac_toe_game.GetBoard()[0].size());
		}

		/// <summary>
		/// Test case
		/// </summary>
		TEST_METHOD(TestCaseMakeMove)
		{
			TicTacToe tic_tac_toe_game = TicTacToe();
			tic_tac_toe_game.MakeMove(0, 1, 'X');
			Assert::AreEqual('X', tic_tac_toe_game.GetBoard()[0][1]);
		}

		/// <summary>
		/// Test case
		/// </summary>
		TEST_METHOD(TestCaseIsMoveValidFalse1)
		{
			TicTacToe tic_tac_toe_game = TicTacToe();
			tic_tac_toe_game.MakeMove(0, 1, 'X');
			tic_tac_toe_game.IsMoveValid(0, 1);
			Assert::IsFalse(tic_tac_toe_game.IsMoveValid(0, 1));
		}

		/// <summary>
		/// Test case
		/// </summary>
		TEST_METHOD(TestCaseIsMoveValidFalse2)
		{
			TicTacToe tic_tac_toe_game = TicTacToe();
			Assert::IsFalse(tic_tac_toe_game.IsMoveValid(0, 3));
		}

		/// <summary>
		/// Test case
		/// </summary>
		TEST_METHOD(TestCaseIsMoveValidTrue)
		{
			TicTacToe tic_tac_toe_game = TicTacToe();
			Assert::IsTrue(tic_tac_toe_game.IsMoveValid(0, 2));
		}

		/// <summary>
		/// Test case
		/// </summary>
		TEST_METHOD(TestCaseCheckWinFalse)
		{
			TicTacToe tic_tac_toe_game = TicTacToe();
			tic_tac_toe_game.MakeMove(0, 1, 'X');
			tic_tac_toe_game.MakeMove(1, 1, 'X');
			tic_tac_toe_game.MakeMove(2, 1, 'X');
			Assert::IsFalse(tic_tac_toe_game.CheckWin('O'));
		}

		/// <summary>
		/// Test case
		/// </summary>
		TEST_METHOD(TestCaseCheckWinTrue1)
		{
			TicTacToe tic_tac_toe_game = TicTacToe();
			tic_tac_toe_game.MakeMove(0, 0, 'X');
			tic_tac_toe_game.MakeMove(1, 1, 'X');
			tic_tac_toe_game.MakeMove(2, 2, 'X');
			Assert::IsTrue(tic_tac_toe_game.CheckWin('X'));
		}

		/// <summary>
		/// Test case
		/// </summary>
		TEST_METHOD(TestCaseCheckWinTrue2)
		{
			TicTacToe tic_tac_toe_game = TicTacToe();
			tic_tac_toe_game.MakeMove(2, 0, 'O');
			tic_tac_toe_game.MakeMove(2, 1, 'O');
			tic_tac_toe_game.MakeMove(2, 2, 'O');
			Assert::IsTrue(tic_tac_toe_game.CheckWin('O'));
		}


		/// <summary>
		/// Test case
		/// </summary>
		TEST_METHOD(TestCaseCheckWinTrue3)
		{
			TicTacToe tic_tac_toe_game = TicTacToe();
			tic_tac_toe_game.MakeMove(1, 0, 'O');
			tic_tac_toe_game.MakeMove(1, 1, 'O');
			tic_tac_toe_game.MakeMove(1, 2, 'O');
			Assert::IsTrue(tic_tac_toe_game.CheckWin('O'));
		}

		/// <summary>
		/// Test case
		/// </summary>
		TEST_METHOD(TestCaseCheckWinTrue4)
		{
			TicTacToe tic_tac_toe_game = TicTacToe();
			tic_tac_toe_game.MakeMove(-1, 0, 'O');
			tic_tac_toe_game.MakeMove(-1, 1, 'O');
			tic_tac_toe_game.MakeMove(-1, 2, 'O');
			Assert::IsFalse(tic_tac_toe_game.CheckWin('O'));
		}

		/// <summary>
		/// Test case
		/// </summary>
		TEST_METHOD(TestCaseIsBoardFullFalse)
		{
			TicTacToe tic_tac_toe_game = TicTacToe();
			Assert::IsFalse(tic_tac_toe_game.IsBoardFull());
		}

		/// <summary>
		/// Test case
		/// </summary>
		TEST_METHOD(TestCaseIsBoardFullTrue)
		{
			TicTacToe tic_tac_toe_game = TicTacToe();
			tic_tac_toe_game.MakeMove(0, 0, 'O');
			tic_tac_toe_game.MakeMove(0, 1, 'O');
			tic_tac_toe_game.MakeMove(0, 2, 'O');
			tic_tac_toe_game.MakeMove(1, 0, 'O');
			tic_tac_toe_game.MakeMove(1, 1, 'O');
			tic_tac_toe_game.MakeMove(1, 2, 'O');
			tic_tac_toe_game.MakeMove(2, 0, 'O');
			tic_tac_toe_game.MakeMove(2, 1, 'O');
			tic_tac_toe_game.MakeMove(2, 2, 'O');
			Assert::IsTrue(tic_tac_toe_game.IsBoardFull());
		}


		/// <summary>
		/// Test case
		/// </summary>
		TEST_METHOD(TestCaseSetPlayers1)
		{
			TicTacToe tic_tac_toe_game = TicTacToe();
			int testCount = 100;
			int player1X = 0;
			int player1O = 0;

			for (int i = 0; i < testCount; i++)
			{
				char player1, player2;
				tic_tac_toe_game.SetPlayers(&player1, &player2);

				if (player1 == 'X')
				{
					player1X++;
				}
				else
				{
					player1O++;
				}
			}

			Assert::AreEqual(static_cast<double>(player1X) / testCount, static_cast<double>(player1O) / testCount, 0.06);
		}

		/// <summary>
		/// Test case
		/// </summary>
		TEST_METHOD(TestCaseSetPlayers2)
		{
			TicTacToe tic_tac_toe_game = TicTacToe();

			char player1, player2;
			tic_tac_toe_game.SetPlayers(&player1, &player2);

			Assert::IsTrue((player1 == 'X' || player1 == 'O') && (player2 == 'X' || player2 == 'O') && player1 != player2);
		}
		
	};
};