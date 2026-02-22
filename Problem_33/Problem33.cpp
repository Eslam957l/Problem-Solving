#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>
using namespace std;

const string ClientsFile = "Clients.txt";

struct strInfo
{
	string AcountNumber;
	string Name;
	string Phone;
	string PinCode;
	double Salary;
};

strInfo ReadInfo()
{
	strInfo Client;

	cout << "Please Enter Client Data\n\n";

	cout << "Please Enter a Name: ";
	cin >> Client.Name;

	cout << "Please Enter a AcountNumber: ";
    cin >> Client.AcountNumber;

	cout << "Please Enter a PinCode: ";
	cin >> Client.PinCode;

	cout << "Please Enter a Phone: ";
	cin >> Client.Phone;

	cout << "Please Enter a Salary: ";
	cin>> Client.Salary;

	return Client;
}

string SaveRecordtoLine(strInfo Client, string Seperator = "#//#")
{
	string AddInfoClient = "";

	AddInfoClient += Client.Name + Seperator;
	AddInfoClient += Client.AcountNumber + Seperator;
	AddInfoClient += Client.PinCode + Seperator;
	AddInfoClient += Client.Phone + Seperator;
	AddInfoClient += to_string(Client.Salary);

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
	string FileName;
	strInfo Client;
	Client = ReadInfo();

	AddInfoClienttoFile(ClientsFile, SaveRecordtoLine(Client));

}

void AddClients()
{
	char AddMore = 'Y';

	do
	{
		system("cls");
		cout << "Add New Client\n";
		AddNewClient();

		cout << "\nClient Added Successfully, Do You Want Add More Client? Please Enter (Y/N): \n\n";
		cin >> AddMore;

	} while (toupper(AddMore) == 'Y');

}

int main()
{

	AddClients();

	system("pause>0");
	return 0;
}
