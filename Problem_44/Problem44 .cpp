#include <iostream>
using namespace std;

short ReadDay()
{
	short Day;
	cout << "Please Enter a Day? \n";
	cin >> Day;
	return Day;
}

short ReadMonth()
{
	short Month;
	cout << "Please Enter a Month? \n";
	cin >> Month;
	return Month;
}

short ReadYear()
{
	short Year;
	cout << "Please Enter a Year? \n";
	cin >> Year;
	return Year;
}

struct stDate
{
	short Year;
	short Month;
	short Day;
};

bool isLeapYear(short Year)
{
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInAMonth(short Month, short Year)
{
	if (Month < 1 || Month>12)
		return 0;
	int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) :
		days[Month - 1];
}

bool IsLastDayInYear(stDate Date)
{
	return (Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year));
}

bool IsLastMonthInYear(short Month)
{
	return(Month == 12);
}

stDate ReadFullDate()
{
	stDate Date;

	Date.Year = ReadYear();
	Date.Month = ReadMonth();
	Date.Day = ReadDay();

	return Date;
}

int main()
{
	stDate Date = ReadFullDate();


	if (IsLastDayInYear(Date))

		cout << "\nYes, This Day is Last Day in Year\n";
    else
		cout << "\n No, This Day is Not Last Day in Year\n";


	   if (IsLastMonthInYear(Date.Month))
		
			cout << "\nYes, This Month is Last Month in Year\n";
	   else
			cout << "\nNo, This Month is Not Last Month in Year\n";
	
	system("pause>=0");
	return 0;
}
