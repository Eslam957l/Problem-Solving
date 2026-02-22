#include <iostream>
#include <string>
using namespace std;

string RemovePunctuation(string S1)
{
	string S2 = "";

	for (short i = 0; S1.length() > i; i++)
	{
		if (!ispunct(S1[i]))
		{
			S2 += S1[i];
		}
	}
	return S2;
}

int main()
{

	string S1 = "Hi, My Name is Islam Hassan..+-&% Thanks?\n";

	cout << "Original String: " << S1 << endl;
	cout << "\nPauncuations Removed:  " << RemovePunctuation(S1);


	system("pause>0");
}