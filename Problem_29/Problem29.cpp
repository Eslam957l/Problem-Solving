#include <iostream>
#include <string>
#include <vector>
using namespace std;

string ReplaceString(string S1, string StrToReplace, string StrReplaceTo)
{
	short pos = S1.find(StrToReplace);

	while (pos != std::string::npos)
	{
		S1 = S1.replace(pos, StrToReplace.length(), StrReplaceTo);

		pos = S1.find(StrToReplace);
	}
	return S1;
}

int main()
{

	string S1 = "Welcome to Egypt , Egypt is a nice country";
	string StrToReplace = "Egypt";
	string StrReplaceTo = "Saudi Arabia";


	cout << "\nOrigial String\n" << S1;
	cout << "\n\nString After Replace:";
	cout << "\n" << ReplaceString(S1, StrToReplace, StrReplaceTo);


	system("pause>0");
}