
#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
using namespace std;

int RandomNumber(int From, int To)
{
	//Function to Generate a Random Number
	int RandNum = rand() % (To - From + 1) + From;

	return RandNum;
}

void FillArrayWithRandomNumbers(int arr[100], int& arrLength)
{
	cout << "\nEnter Number Of Elements:\n";
	cin >> arrLength;

	for (int i = 0; i < arrLength; i++)
	{
		arr[i] = RandomNumber(1, 100);
	}
}

void PrintArray(int arr[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";
}

short FindNumberPositionInArray(int Number, int arr[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		if (arr[i] == Number)
			return i;
	}

	return -1;
}

bool IsNumberInArray(int Number, int arr[100], int arrLength)
{
	return FindNumberPositionInArray(Number, arr, arrLength) != -1;
}


int ReadNumber()
{
	int Number;
	cout << "\nPlease Enter a Number to Search For\n";
	cin >> Number;

	return Number;
}

int main() 
{
	//Seeds the random Number generator in C++, called only one
	srand((unsigned)time(NULL));

	int arr[100], arrLength;
	FillArrayWithRandomNumbers(arr, arrLength);

	cout << "\nArray Elements: ";
	PrintArray(arr, arrLength);

	int Number = ReadNumber();
	cout << "\nNumber You Are Looking For is:" << Number << endl;


	if (!IsNumberInArray(Number,arr,arrLength))
	{
		cout << "No, The Number is Not Found :-(\n";
	}
	else
	{
		cout << "Yes, The Number Found :-)\n";
	}

	return 0;
}
