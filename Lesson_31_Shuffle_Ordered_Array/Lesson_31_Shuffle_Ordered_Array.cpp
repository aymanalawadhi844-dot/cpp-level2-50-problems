
#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
using namespace std;

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

void FillArrayWith1toN(int arr[100], int& arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		arr[i] = i + 1;
	}
}

//Swap
void Swap(int& A, int& B)
{
	int Temp = A;
	A = B;
	B = Temp;
}

//Random
int RandomNumber(int From, int To)
{
	//Function to Generate a Random Number
	int RandNum = rand() % (To - From + 1) + From;

	return RandNum;
}

void ShuffleArray(int arr[100],int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
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


int main()
{
	//Seeds the random Number generator in C++, called only one
	srand((unsigned)time(NULL));

	int arr[100];
	int arrLength = ReadPositiveNumber("Enter Number Of Elements:");

	FillArrayWith1toN(arr, arrLength);

	cout << "\nArray Elements Before Shuffle:\n";
	PrintArray(arr, arrLength);

	ShuffleArray(arr, arrLength);

	cout << "\nArray Elements After Shuffle:\n";
	PrintArray(arr, arrLength);


	return 0;
}
