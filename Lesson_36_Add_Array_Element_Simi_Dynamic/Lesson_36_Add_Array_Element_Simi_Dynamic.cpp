
#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
using namespace std;

int ReadNumber()
{
	int Number;
	cout << "\nPlease Enter a Number?\n";
	cin >> Number;

	return Number;
}

void AddArrayElement(int Number, int arr[100], int& arrLength)
{
	//its a new element so we need to add the length by 1
	arrLength++;
	arr[arrLength - 1] = Number;
}

void InputUserNumbersInArray(int arr[100], int& arrLength)
{
	bool AddMore = true;

	do
	{
		AddArrayElement(ReadNumber(), arr, arrLength);
		 
		cout << "\nDo you want to add more numbers?[0]:No,[1]:Yes?";
		cin >> AddMore;
	} while (AddMore);
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
	int arr[100], arrLength = 0;
	InputUserNumbersInArray(arr, arrLength);

	cout << "\nArray Length: " << arrLength << endl;
	cout << "Array Elements: ";
	PrintArray(arr, arrLength);


	return 0;
}
