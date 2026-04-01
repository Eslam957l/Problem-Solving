#include <iostream>
#include <string>
using namespace std;

int ReadYear()
{
    int Year;
    cout << "Please Enter a Year ? \n";
    cin >> Year;

    return Year;
}

bool LeapYear(int Year)
{
    return(Year % 4 == 0 && Year % 100 != 0) || Year % 400 == 0;
}

short yearforDays(int Year)
{
    return LeapYear(Year) ? 366 : 365;
}

int DaysforHours(int Year)
{
  return  yearforDays(Year) * 24;
}

int HoursforMinutes(int Year)
{
    return DaysforHours(Year) * 60;
}

int MinutesforSecond(int Year)
{
   return HoursforMinutes(Year) * 60;
}

int main()
{
    int Year = ReadYear();

    cout << "Number of Days in Year [" << Year << "] is " << yearforDays(Year) << endl;
    cout << "Number of Hours in Year [" << Year << "] is " << DaysforHours(Year) << endl;
    cout << "Number of Minutes in Year [" << Year << "] is " << HoursforMinutes(Year) << endl;
    cout << "Number of Second in Year [" << Year << "] is " << MinutesforSecond(Year) << endl;

    system("pause>=0");
    return 0;
}
