
#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
using namespace std;

//enum
enum enPrimeNotPrime { Prime = 1, NotPrime = 2 };

enPrimeNotPrime CheckPrime(int Number)
{


	int M = round(Number / 2);

	for (int i = 2; i <= M; i++)
	{
		if (Number % i == 0)
		{
			return enPrimeNotPrime::NotPrime;
		}
	}

	return enPrimeNotPrime::Prime;
}

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

void CopyOnlyPrimeNumbers(int arrSource[100], int arrDestination[100], int arrLength,int &arr2Length)
{
	int Counter = 0;

	for (int i = 0; i < arrLength; i++)
	{
		if (CheckPrime(arrSource[i]) == enPrimeNotPrime::Prime)
		{
			arrDestination[Counter] = arrSource[i];
			Counter++;
		}
	}
	arr2Length = --Counter;
}

void PrintArray(int arr[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";
}


int main()
{
	//Seeds the random Number generator in C++, called only one
	srand((unsigned)time(NULL));

	int arr[100], arrLength;

	FillArrayWithRandomNumbers(arr, arrLength);

	int arr2[100], arr2Length = 0;
	CopyOnlyPrimeNumbers(arr, arr2, arrLength,arr2Length);

	cout << "\nArray 1 Elements:\n";
	PrintArray(arr, arrLength);

	cout << "\nPrime Numbers in Array2:\n";
	PrintArray(arr2, arr2Length);


	return 0;
}
