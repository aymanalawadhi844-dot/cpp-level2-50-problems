
#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
using namespace std;

float MyABS(float Number)
{
	if (Number > 0)
		return Number;
	else
		return Number * -1;
}

float ReadNumber()
{
	float Number = 0;
	cout << "Please Enter a Number?\n";
	cin >> Number;

	return Number;
}

int main()
{
	float Number = ReadNumber();

	cout << "My abs Result: " << MyABS(Number) << endl;
	cout << "C++ abs Result: " << abs(Number) << endl;

	return 0;
}Ğ
