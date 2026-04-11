#include <iostream>
#include <string>
using namespace std;

class clsPerson
{
private:

	int _ID;
	string _FirstName;
	string _LastName;
	string _Email;
	string _Phone;
	string _Body;
	string _Subject;
	string _SMS;


public:

	int GetID()
	{
		return _ID;
	}

	void SetFirstName(string FirstName)
	{
	    _FirstName = FirstName;
	}

	string GetFirstName()
	{
		return _FirstName;
	}

	void SetLastName(string LastName)
	{
		_LastName = LastName;
	}
	
	string GetLastName()
	{
		return _LastName;
	}

	void SetEmail(string Email)
	{
		_Email = Email;
	}

	string GetEmail()
	{
		return _Email;
	}

	void SetPhone(string Phone)
	{
		_Phone = Phone;
	}

	string GetPhone()
	{
		return _Phone;
	}

	string FullName()
	{
		return _FirstName + "" + _LastName;
	}

	clsPerson(int ID, string FirstName, string LastName, string Email, string Phone)
	{
		_ID = ID;
		_FirstName = FirstName;
		_LastName = LastName;
		_Email = Email;
		_Phone = Phone;
	}

	void Print()
	{
		cout << "INFO: \n";
		cout << "\n ------------------------------ \n";
		cout << "ID       :       " << GetID() << endl;
		cout << "FirstName:       " << GetFirstName() << endl;
		cout << "LastName :       " << GetLastName() << endl;
		cout << "FullName :       " << FullName() << endl;
		cout << "Email    :       " << GetEmail() << endl;
		cout << "Phone    :       " << GetPhone() << endl;
		cout << "\n ------------------------------ \n";
	
	}

	void SendEmail(string Subject, string Body)
	{
		cout << "\nThe Following Message Sent Successfully to Email: " << GetEmail() << endl;
		cout << "Subject:  " << Subject << "\n";
		cout << "Body   :   " << Body << "\n\n";
	}

	void SendSMS(string SMS)
	{
		cout << "\n\nThe Following SMS Sent Successfully to Phone " << GetPhone() << endl;
		cout << SMS << "\n\n";
	}


};

int main()
{
	clsPerson Person1(123, "Name1 ", "Name2 ", "Email@gmail.com ", "00000000000");
	Person1.Print();

	Person1.SendEmail("Hi", "How Are You , Great Work And Great Project");
	Person1.SendSMS("The Phone Numebr is unique And True");

}