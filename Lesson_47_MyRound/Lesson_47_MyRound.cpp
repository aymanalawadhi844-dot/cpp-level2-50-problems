
#include <iostream>
#include <string>
using namespace std;

float GetFractionPart(float Number)
{
	return Number - int(Number);//10.7 - 10 = 0.7
}

int MyRound(float Number)
{
	int IntPart;
	IntPart = int(Number);//IntPart=10

	float FractionsPart = GetFractionPart(Number);//FractionsPart=0.7

	if (abs(FractionsPart) >= .5)
	{
		if (Number > 0)
			return ++IntPart;
		else
			return --IntPart;
	}
	else
	{
		return IntPart;
	}
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

	cout << "My Round Result: " << MyRound(Number) << endl;
	cout << "C++ Round Result: " << round(Number) << endl;

	return 0;
}
