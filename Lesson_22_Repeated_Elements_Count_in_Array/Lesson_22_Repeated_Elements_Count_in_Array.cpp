
#include <iostream>
#include <string>
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

void ReadArray(int arr[100], int &arrLength)
{
	cout << "Enter Number Of Elements: \n";
	cin >> arrLength;

	cout << "\nEnter Array Elements:\n";
	for (int i = 0; i < arrLength; i++)
	{
		cout << "Element [" << i + 1 << "] : ";
		cin >> arr[i];
	}
	cout << endl;
}

void PrintArray(int arr[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";
}

int TimesRepeated(int Number, int arr[100], int arrLength)
{
	int Count = 0;

	for (int i = 0; i < arrLength - 1; i++)
	{
		if (Number == arr[i])
		{
			Count++;
		}
	}

	return Count;
}

int main()
{
	int arr[100], arrLength, NumberToCheck;

	ReadArray(arr, arrLength);

	NumberToCheck = ReadPositiveNumber("Enter The Number You Want To Check:");

	cout << "\nOriginal Array: ";
	PrintArray(arr, arrLength);

	cout << "\nNumber " << NumberToCheck;
	cout << "is Repeated ";
	cout << TimesRepeated(NumberToCheck, arr, arrLength) << " Time(s)\n";


	return 0;
}
