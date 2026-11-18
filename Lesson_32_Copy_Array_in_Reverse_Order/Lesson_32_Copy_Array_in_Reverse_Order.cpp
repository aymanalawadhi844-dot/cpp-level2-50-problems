
#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
using namespace std;

//Random
int RandomNumber(int From, int To)
{
	//Function to Generate a Random Number
	int RandNum = rand() % (To - From + 1) + From;

	return RandNum;
}

void FillArrayWithRandomNumbers(int arr[100], int& arrLength)
{
	cout << "Enter Number Of Elements:\n";
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

void CopyArrayInReverseOrder(int arrSource[100], int arrDestination[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		arrDestination[i] = arrSource[arrLength - 1 - i];
	}
}

int main()
{
	//Seeds the random Number generator in C++, called only on e
	srand((unsigned)time(NULL));

	int arr[100], arr2[100], arrLength;

	FillArrayWithRandomNumbers(arr, arrLength);

	cout << "\nArray 1 Element:\n";
	PrintArray(arr, arrLength);

	CopyArrayInReverseOrder(arr,arr2,arrLength);

	cout << "\nArray Elements After Shuffle:\n";
	PrintArray(arr2, arrLength);


	return 0;
}
