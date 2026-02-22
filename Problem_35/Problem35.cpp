#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <iomanip>
using namespace std;

const string ClientsFile = "Clients.txt";

struct strInfo
{
	string Name;
	string AcountNumber;
	string PinCode;
	string Phone;
	double Salary;
};

vector<string> SplitString(string S1, string Delim)
{
	vector<string> vString;
	short pos = 0;

	string sWord;
	while ((pos = S1.find(Delim)) != std::string::npos)
	{
		sWord = S1.substr(0, pos);
		if (sWord != "")
		{
			vString.push_back(sWord);
		}
		S1.erase(0, pos + Delim.length());

	}
	if (S1 != "")
	{
		vString.push_back(S1);
	}
	return vString;
}

strInfo ConvertLinetoRecord(string Line, string Seperator = "#//#")
{
	strInfo Client;
	vector<string> vClientData;
	vClientData = SplitString(Line, Seperator);

	Client.Name = vClientData[0];
	Client.AcountNumber = vClientData[1];
	Client.PinCode = vClientData[2];
	Client.Phone = vClientData[3];
	Client.Salary = stod(vClientData[4]);

		return Client;
}

vector <strInfo> LoadClientData(string FileName)
{
	vector <strInfo> vClient;
	fstream MyFile;
	MyFile.open(FileName, ios::in);

	if (MyFile.is_open())
	{
		string Line;
		strInfo Client;


		while (getline(MyFile, Line))
		{

			Client = ConvertLinetoRecord(Line);
			vClient.push_back(Client);

		}
	}
	return vClient;
}

void PrintClientCard(strInfo Client)
{
	cout << "\nThe following are the client details:\n";
	cout << "\nName: " << Client.Name;
	cout << "\nAcount Number : " << Client.AcountNumber;
	cout << "\nPin Code : " << Client.PinCode;
	cout << "\nPhone : " << Client.Phone;
	cout << "\nSalary: " << Client.Salary;
}

bool FindAcountNumber(string AcountNumber, strInfo& Client)
{
	vector <strInfo> vClient = LoadClientData(ClientsFile);

	for (strInfo E : vClient)
	{
		if (E.AcountNumber == AcountNumber)
		{
		    Client = E;
			return true;
		}
	}
	return false;
}

string ReadAcountNumber()
{
	string AcountNumber = "";

	cout << "Please Enter an AcoutNumber?\n ";
	cin >> AcountNumber;
	return AcountNumber;
}

int main()
{

	strInfo Client;
	string AcountNumber = ReadAcountNumber();

	if (FindAcountNumber(AcountNumber, Client))
	{
		cout << "\nYes The Acount is Exist.\n\n ";
		PrintClientCard(Client);
	}
	else
	{
		cout << "\nClient with Account Number (" << AcountNumber << ") is Not Found!";
	}


	system("pause>0");
	return 0;
}