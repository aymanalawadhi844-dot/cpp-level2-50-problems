
#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
using namespace std;

//enum
enum enCharType { SmallLetter = 1, CapitalLetter = 2, SpecialCharacter = 3, Digit = 4 };

int RandomNumber(int From, int To)
{
	//Function to Generate a Random Number
	int RandNum = rand() % (To - From + 1) + From;

	return RandNum;
}

char GetRandomCharacter(enCharType CharType)
{
	switch (CharType)
	{
	case enCharType::SmallLetter:
	{
		return char(RandomNumber(97, 122));
		break;
	}
	case enCharType::CapitalLetter:
	{
		return char(RandomNumber(65, 90));
		break;
	}
	case enCharType::SpecialCharacter:
	{
		return char(RandomNumber(33, 47));
		break;
	}
	case enCharType::Digit:
	{
		return char(RandomNumber(48, 57));
		break;
	}

	}
}

string GenerateWord(enCharType CharType, short Length)
{
	string Word;
	for (int i = 1; i <= Length; i++)
	{
		Word = Word + GetRandomCharacter(CharType);
	}

	return Word;
}

string GenerateKey()
{
	string Key = "";
	Key = GenerateWord(enCharType::CapitalLetter, 4) + "-";
	Key = Key + GenerateWord(enCharType::CapitalLetter, 4) + "-";
	Key = Key + GenerateWord(enCharType::CapitalLetter, 4) + "-";
	Key = Key + GenerateWord(enCharType::CapitalLetter, 4);

	return Key;
}

void FillArrayWithKeys(string arr[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		arr[i] = GenerateKey();
   }
}

int ReadPositiveNumber(string Message)
{
	int Number = 0;
	do
	{
		cout << Message << endl;
		cin >> Number;
	} while (Number <= 0);

	return Number;
}

void PrintStringArray(string arr[100],int arrLength)
{
	cout << "\nArray Elements:\n\n";
	for (int i = 0; i < arrLength; i++)
	{
		cout <<"Array ["<<i+1<<"]: "<< arr[i] << endl;
	}
	cout << "\n";
}

int main()
{
	//Seeds the random Number generator in C++, called only one
	srand((unsigned)time(NULL));

	string arr[100];
	int arrLength = 0;

	arrLength = ReadPositiveNumber("How Many Keys Do You Want to Gernerate?\n");

	FillArrayWithKeys(arr, arrLength);

	PrintStringArray(arr, arrLength);

	return 0;
}
