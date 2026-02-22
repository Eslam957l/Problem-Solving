#include <iostream>
#include <string>
#include <vector>
using namespace std;

string Readstring()
{
	string S1;
	cout << "Please enter a String?\n";
	getline(cin, S1);
	return S1;

}

vector <string> SplitString(string S1, string Delim)
{

	vector <string> vstring;
	short pos = 0;
	string sword;

	while ((pos = S1.find(Delim)) != std::string::npos)
	{
		sword = S1.substr(0, pos);
		if (sword != "")
		{
			vstring.push_back(sword);
		}

		S1.erase(0, pos + Delim.length());
	}
	if (S1 != "")
	{
		vstring.push_back(S1);
	}
	return vstring;
}

string ReverseWord(string S1)
{
	string S2 = "";
	vector <string> vstring;

	vstring = SplitString(S1, " ");

	vector <string>::iterator iter = vstring.end();

	while (iter != vstring.begin())
	{
		--iter;
		S2 += *iter + " ";
	}

	S2 = S2.substr(0, S2.length() - 1);
	return S2;

}

int main()
{

	string S1 = Readstring();
	cout << "\n\nString after reversing words:";
	cout << "\n" << ReverseWord(S1);
	
	system("pause>0");
}
