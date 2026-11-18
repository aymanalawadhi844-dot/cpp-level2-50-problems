
#include <iostream>
#include <cstdlib>
#include <time.h>//time()

using namespace std;

//enum GameChoice 
enum enGameChoice { Stone = 1, Paper = 2, Scissors = 3 };// ÕÃ—  Ê—ﬁ…   „ﬁ’ 

//enum Winner
enum enWinner { Player1 = 1, Computer = 2, Draw = 3 };//  «··«⁄» «·«Ê·   «·ﬂ„»ÌÊ —   «· ⁄«œ· 

//struct Round Info
struct stRoundInfo
{
	short RoundNumber = 0;

	enGameChoice Player1Choice;
	enGameChoice ComputerChoice;
	enWinner Winner;
	string WinnerName;
};

//struct GameResults
struct stGameResults
{
	short GameRounds = 0;
	short Player1WinTimes = 0;
	short Computer2WinTimes = 0;
	short DrawTimes;
	enWinner GameWinner;
	string WinnerName = "";
};

//Random Number
int RandomNumber(int From, int To)
{
	int randNum = rand() % (To - From + 1) + From;

	return randNum; 
}

//WinnerName
string WinnerName(enWinner Winner)
{
	string arrWinnerName[3] = { "Player1","Computer","No Winner" };
	return arrWinnerName[Winner - 1];
}

//enWho Won The Round
enWinner WhoWonTheRound(stRoundInfo RoundInfo)
{
	if (RoundInfo.Player1Choice == RoundInfo.ComputerChoice)
	{
		return enWinner::Draw;
	}

	//switch
	switch (RoundInfo.Player1Choice)
	{
	case enGameChoice::Stone:
		if (RoundInfo.ComputerChoice == enGameChoice::Paper)
		{
			return enWinner::Computer;
		}
		break;

	case enGameChoice::Paper:
		if (RoundInfo.ComputerChoice == enGameChoice::Scissors)
		{
			return enWinner::Computer;
		}
		break;

	case enGameChoice::Scissors:
		if (RoundInfo.ComputerChoice == enGameChoice::Stone)
		{
			return enWinner::Computer;
		}
		break;

	}
	//if you reach here then player1 is the winner.
	return enWinner::Player1;
}

//Choice Name
string ChoiceName(enGameChoice Choice)
{
	string arrGameChoices[3] = { "Stone","Paper","Scissors" };
	return arrGameChoices[Choice - 1];
}

//Set Winner Screen Color
void SetWinnerScreenColor(enWinner Winner)
{
	//switch
	switch (Winner)
	{
	case enWinner::Player1:
		system("color 2F");//turn screen to Green
		break;

	case enWinner::Computer:
		system("color 4F");//turn screen to Red
		cout << "\a";
		break;

	default:
		system("color 6F");//turn screen to Yellow
		break;
	}
}

//Print Round Results
void PrintRoundResults(stRoundInfo RoundInfo)
{
	cout << "\n-------------------Round [" << RoundInfo.RoundNumber << "]------------------\n\n";// 1  // 2 //3
	cout << "Player1 Choice : " << ChoiceName(RoundInfo.Player1Choice) << endl;//stone  Paper // Scissors
	cout << "Computer Choice : " << ChoiceName(RoundInfo.ComputerChoice) << endl;//paper Scissors // Paper
	cout << "Round Winner : [" << RoundInfo.WinnerName << "]\n";//Computer  Computer  Player1

	SetWinnerScreenColor(RoundInfo.Winner);
}

//enWinner Who Won The Game
enWinner WhoWonTheGame(short Player1WinTimes, short ComputerWinTimes)
{
	if (Player1WinTimes > ComputerWinTimes)
		return enWinner::Player1;
	else if (ComputerWinTimes > Player1WinTimes)
		return enWinner::Computer;
	else
		return enWinner::Draw;
}

//stGameResults Fill Game Results
stGameResults FillGameResults(int GameReounds, short Player1WinTimes, short ComputerWinTimes, short DrawTimes)
{
	stGameResults GameResults;

	GameResults.GameRounds = GameReounds;
	GameResults.Player1WinTimes = Player1WinTimes;
	GameResults.Computer2WinTimes = ComputerWinTimes;
	GameResults.DrawTimes = DrawTimes;
	GameResults.GameWinner = WhoWonTheGame(Player1WinTimes, ComputerWinTimes);
	GameResults.WinnerName = WinnerName(GameResults.GameWinner); 

	return GameResults;
}

//enGameChoice Read Player1 Choice
enGameChoice ReadPlayer1Choice()
{
	short Choice = 1;

	do
	{
		cout << "\nYour Choice: [1]:Stone, [2]:Paper, [3]:Scissors ?";
		cin >> Choice;

	} while (Choice < 1 || Choice>3);

	return (enGameChoice)Choice;// 1 stone
}

//enGameChoice GetComputerChoice
enGameChoice GetComputerChoice()
{
	return (enGameChoice)RandomNumber(1, 3);//2 paper
}

//stGameResults Play Game
stGameResults PlayGame(short HowManyRounds)
{
	stRoundInfo RoundInfo;

	short Player1WinTimes = 0, ComputerWinTimes = 0, DrawTimes = 0;

	for (short GameRound = 1; GameRound <= HowManyRounds; GameRound++)
	{
		cout << "\nRound [" << GameRound << "] begins:\n";
		RoundInfo.RoundNumber = GameRound;// 1  //2  //3 
		RoundInfo.Player1Choice = ReadPlayer1Choice();//1 stone // 2 paper // 3 Scissors
		RoundInfo.ComputerChoice = GetComputerChoice();//2 paper 3 //scissors // 2 Paper
		RoundInfo.Winner = WhoWonTheRound(RoundInfo);// 2  // 2  // 1
		RoundInfo.WinnerName = WinnerName(RoundInfo.Winner);// Computer Computer  Player1

		//Increase Win/Draw Counters
		if (RoundInfo.Winner == enWinner::Player1)
			Player1WinTimes++; // 1
		else if (RoundInfo.Winner == enWinner::Computer)
			ComputerWinTimes++;// 1 + 1 = 2
		else
			DrawTimes++;

		PrintRoundResults(RoundInfo);
	}

	return FillGameResults(HowManyRounds, Player1WinTimes, ComputerWinTimes, DrawTimes);
}

//string Tabs
string Tabs(short NumberOfTabs)
{
	string t = "";
	for (int i = 1; i <= NumberOfTabs; i++)
	{
		t = t + "\t";
		cout << t;
	}

	return t;
}

//show Game Over Screen
void ShowGameOverScreen()
{
	cout << Tabs(2) << "____________________________________________________________\n\n";
	cout << Tabs(2) << "                   +++ G a m e  O v e r +++\n";
	cout << Tabs(2) << "_____________________________________________________________\n\n";
}

//Show Final Game Results
void ShowFinalGameResults(stGameResults GameResults)
{
	cout << Tabs(2) << "-----------------[ Game Results ]----------------\n\n";
	cout << Tabs(2) << "Game Rounds           : " << GameResults.GameRounds << endl;// 3
	cout << Tabs(2) << "Player1 Win Times     : " << GameResults.Player1WinTimes << endl;// 1
	cout << Tabs(2) << "Computer Win Times    : " << GameResults.Computer2WinTimes << endl;// 2
	cout << Tabs(2) << "Draw Times            : " << GameResults.DrawTimes << endl;// 0
	cout << Tabs(2) << "Final Winner          : " << GameResults.WinnerName << endl;// Computer
	cout << Tabs(2) << "__________________________________________________________________\n";

	SetWinnerScreenColor(GameResults.GameWinner);
}

//Read How Many Rounds
short ReadHowManyRounds()
{
	short GameRounds = 1;

	do
	{
		cout << "How Many Rounds 1 to 10 ?\n";
		cin >> GameRounds;

	} while (GameRounds < 1 || GameRounds > 10);

	return GameRounds;
}

// Rese Screen
void ReseScreen()
{
	system("cls");
	system("color 0F");
}

//Start Game
void StartGame()
{
	char PlayAgain = 'Y';

	do
	{
		ReseScreen();
		stGameResults GameResults = PlayGame(ReadHowManyRounds());
		ShowGameOverScreen();
		ShowFinalGameResults(GameResults);

		cout << endl << Tabs(3) << "Do you want to play again? Y/N ? ";
		cin >> PlayAgain;

	} while (PlayAgain == 'Y' || PlayAgain == 'y');
}

int main()
{
	//seeds the random number generator in c++, called only once
	srand((unsigned)time(NULL));

	StartGame();

	return 0;
}
