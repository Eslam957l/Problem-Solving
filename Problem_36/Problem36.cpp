#include <iostream>
#include <fstream>
#include <vector>
#include <string>
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
	bool MarkforDelete = false;
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

string ConvertToLine(strInfo Client, string Seperator = "#//#")
{
	string stClientRecord = "";
	stClientRecord += Client.Name + Seperator;
	stClientRecord += Client.AcountNumber + Seperator;
	stClientRecord += Client.PinCode + Seperator;
	stClientRecord += Client.Phone + Seperator;
	stClientRecord += to_string(Client.Salary);

	return stClientRecord;
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

bool DeleteClientByAcountNumber(string AcountNumber, vector <strInfo> vClients)
{
	for (strInfo& E : vClients)
	{
		if (E.AcountNumber == AcountNumber)
		{
			E.MarkforDelete = true;
			return true;
		}
	}
	return false;

}

vector <strInfo> SaveData(string FileName, vector <strInfo> vClients)
{
	fstream MyFile;
	MyFile.open(FileName, ios::out);//overwrite
	string DataLine;
	if (MyFile.is_open())
	{
		for (strInfo C : vClients)
		{
			if (C.MarkforDelete == false)
			{
	
					DataLine = ConvertToLine(C);
				MyFile << DataLine << endl;
			}
		}
		MyFile.close();
	}
	return vClients;
}

bool DeleteClient(string AcountNumber, vector <strInfo>& vClients)
{
	strInfo Client;
	char Answer = 'n';
	 
	if (FindAcountNumber(AcountNumber, Client))
	{
		PrintClientCard(Client);

		cout << "\n\n Are You Sure Want Delete This Client? (Y/N)? ";
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			DeleteClientByAcountNumber(AcountNumber, vClients);
			SaveData(ClientsFile, vClients);

			vClients = LoadClientData(ClientsFile);

			cout << "\n\n Client Deleted Successfully.";
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

	vector <strInfo> vClinets = LoadClientData(ClientsFile);

	string AcountNumber = ReadAcountNumber();

	DeleteClient(AcountNumber, vClinets);

	system("pause>0");
	return 0;
}