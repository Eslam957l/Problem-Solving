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
	string AcountNumber;
	string Name;
	string Phone;
	string PinCode;
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

void PrintClientRecord(strInfo Client)
{
	cout << "| " << setw(15) << left << Client.AcountNumber;
	cout << "| " << setw(10) << left << Client.PinCode;
	cout << "| " << setw(40) << left << Client.Name;
	cout << "| " << setw(12) << left << Client.Phone;
	cout << "| " << setw(12) << left << Client.Salary;
}

void PrintAllClientData(vector <strInfo> vClient)
{

	cout << "\n\t\t\t\t\tClient List (" << vClient.size() << ") Client(s).";

	
	cout <<	"\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;
	cout << "| " << left << setw(15) << "Acout Number";
	cout << "| " << left << setw(10) << "Pin Code";
	cout << "| " << left << setw(40) << "Client Name";
	cout << "| " << left << setw(12) << "Phone";
	cout << "| " << left << setw(12) << "Salary";
	cout <<
		"\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;

	for (strInfo Client : vClient)
	{
		PrintClientRecord(Client);
		cout << endl;

	}

	cout <<
		"\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;

}

int main()
{
	vector <strInfo> vClient = LoadClientData(ClientsFile);

	PrintAllClientData(vClient);

	system("pause>0");
	return 0;
}
