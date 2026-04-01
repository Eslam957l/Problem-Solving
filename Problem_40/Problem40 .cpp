#include <iostream>
#include <string>
using namespace std;

short ReadMonth()
{
	int Month;
	cout << "Please Enter a Month ? \n";
	cin >> Month;

	return Month;
}

short ReadYear()
{
	int Year;
	cout << "Please Enter a Year ?\n";
	cin >> Year;

	return Year;
}

bool IsLeapYear(int Year)
{
	return (Year % 4 == 0 && Year % 100 != 0) || Year % 400 == 0;
}

short NumberOfDays(int Year, int Month)
{
	if (Month < 1 || Month > 12)
	{
		return 0;
   }
	int Arr[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : Arr[Month - 1];
}

int main()
{
	short Month = ReadMonth();
	short Year = ReadYear();

	cout << "Number of Days in Month [" << Month << "] is " << NumberOfDays(Year, Month);


	system("pause>0");
	return 0;
}
