
#include <iostream>
#include <string>
using namespace std;

int MySqrt(float Number)
{
	return pow(Number, 0.5);
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

	cout << "My Sqrt Result: " << MySqrt(Number) << endl;
	cout << "C++ Sqrt Result: " << sqrt(Number) << endl;

	return 0;
}
