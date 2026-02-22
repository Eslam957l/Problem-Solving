#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct strInfo
{
	string AcountNumber;
	string Name;
	string Phone;
	string PinCode;
	int Salary;
};

strInfo ReadInfo()
{
	strInfo Client;

	cout << "Please Enter Client Date: \n\n\n";

	cout << "Please Enter a Name: ";
	getline(cin, Client.Name);

	cout << "Please Enter a AcountNumber: ";
	cin >> Client.AcountNumber;

	cout << "Please Enter a PinCode: ";
	cin >> Client.PinCode;

	cout << "Please Enter a Phone: ";
	cin >> Client.Phone;

	cout << "Please Enter a Salary: ";
	cin >> Client.Salary;

	return Client;
}

string SaveRecordtoLine(strInfo Client, string Seperator = "#//#")
{
	string AddInfoClient = "";

	AddInfoClient += Client.Name + Seperator;
	AddInfoClient += Client.AcountNumber + Seperator;
	AddInfoClient += Client.PinCode + Seperator;
	AddInfoClient += Client.Phone + Seperator;
	AddInfoClient += Client.Salary + Seperator;

	return AddInfoClient;

}

void AddInfoClienttoFile(string FileName, string stDataLine)
{
	fstream MyFile;

	MyFile.open(FileName, ios::out | ios::app);
	if (MyFile.is_open())
	{
		MyFile << stDataLine << endl;

		MyFile.close();
	}
	
}

void AddNewClient()
{
	strInfo Client;
	Client = ReadInfo();

	AddInfoClienttoFile(ClientFileName, SaveRecordtoLine(Client));

}

void AddClients()
{
	char AddMore = 'Y';
	system("cls");

	do
	{
		cout << "Add New Client:\n\n";
		AddNewClient();

		cout << "\n Client Added Successfully, Do You Want Add More Client?\n Please Enter (Y/N)";
		cin >> AddMore;

	}while (toupper(AddMore) == 'Y')

}

int main()
{

	AddClients();

	system("pause>0");
	return 0;
}

