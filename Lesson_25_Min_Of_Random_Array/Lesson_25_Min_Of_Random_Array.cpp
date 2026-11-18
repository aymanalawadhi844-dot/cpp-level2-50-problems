
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

int MinNumberInArray(int arr[100], int arrLength)
{
	int Min = 0;
	Min = arr[0];

	for (int i = 0; i < arrLength; i++)
	{
		if (arr[i] < Min)
		{ 
			Min = arr[i];
		}
	}

	return Min;
}

int main()
{
	//Seeds the random Number generator in C++, called only one
	srand((unsigned)time(NULL));

	int arr[100], arrLength;

	FillArrayWithRandomNumbers(arr, arrLength);

	cout << "\nArray Elements: ";
	PrintArray(arr, arrLength);

	cout << "\nMin Number is: ";
	cout << MinNumberInArray(arr, arrLength) << endl;

	return 0;
}
