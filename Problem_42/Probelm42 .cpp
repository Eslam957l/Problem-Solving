#include <iostream>
using namespace std;

bool isLeapYear(short Year)
{
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);

}

short NumberOfDaysinMonth(short Year, short Month)
{
	if (Month < 1 || Month > 12)
	{
		return 0;
	}
	int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : days[Month - 1];
}

short NumberOfDaysFromBeginigOfTheyear(short Days, short Month, short Year)
{
	int TotalDays = 0;
	for (int i = 1; Month - 1 >= i; i++)
	{
		TotalDays += NumberOfDaysinMonth(Year, i);
	}
	TotalDays += Days;

	return TotalDays;

}

short ReadDays()
{
	short Days;
	cout << "\nPlease Enter A Days? \n";
	cin >> Days;
	return Days;
}

short ReadMonth()
{
	short Month;
	cout << "\nPlease Enter A Month? \n";
	cin >> Month;
	return Month;
}

short ReadYear()
{
	short Year;
	cout << "\n Please Enter A Year? \n";
	cin >> Year;
	return Year;
}

int main()
{
	short Days = ReadDays();
	short Month = ReadMonth();
	short Year = ReadYear();

	cout << "The Number Of Days from Begining of the Year is : " <<
		NumberOfDaysFromBeginigOfTheyear(Days, Month, Year);

	system("pause>=0");
	return 0;
}