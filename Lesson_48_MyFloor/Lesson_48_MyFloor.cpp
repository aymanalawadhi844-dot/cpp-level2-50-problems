
#include <iostream>
#include <string>
using namespace std;

int MyFloor(float Number)//Number=10.7
{
	if (Number > 0)
		return int(Number);//10
	else
		return int(Number) - 1;
}

float ReadNumber()
{
	float Number = 0;
	cout << "Please Enter a float Number?\n";
	cin >> Number;

	return Number;
}

int main()
{
	float Number = ReadNumber();

	cout << "My Floor Result: " << MyFloor(Number) << endl;
	cout << "C++ Floor Result: " << floor(Number) << endl;

	return 0;
}
