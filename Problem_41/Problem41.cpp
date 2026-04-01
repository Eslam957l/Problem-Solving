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

short ReadDays()
{
	int Days;
	cout << "Please Enter a Day ?\n";
	cin >> Days;
	return Days;
}

void Date(short Days)
{

	if (Days < 0 || Days > 6)
	{
		cout << "Invaild Day\n";
		return;
	}
	string ArrOfDays[7] = { "Sat", "Sun", "Mon", "Tue", "Wed" ,"Thu" , "Fri" };
	cout << "Day Order: " << Days << endl;
	cout << "Day Name: " << ArrOfDays[Days] << endl;

}


int main()
{
	short Year = ReadYear();
	short Month = ReadMonth();
	short Days = ReadDays();

	cout << "Date: " << Days << "/" << Month << "/" << Year << endl;
	
	Date(Days);

	system("pause>0");
	return 0;
}
