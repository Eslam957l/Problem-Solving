#include <iostream>
#include <string>
using namespace std;

class clsCalculator
{
private:
	float _Result = 0;
	float _PreviousResult = 0;
	string _LastOperation = " Clear ";
	float _LastNumber = 0;

	bool _IsZero(float Number)
	{
		return Number == 0;
	}


public:

	void Add(float Number)
	{
		_LastNumber = Number;
		_LastOperation = "Adding";
		_PreviousResult = _Result;
		_Result += Number;
	}

	void substracting(float Number)
	{
		_LastNumber = Number;
		_LastOperation = "Substract";
		_PreviousResult = _Result;
		_Result -= Number;
	}

	void Divide(float Number)
	{
		if (_IsZero(Number))
		{
			Number = 1;
		}

		_LastNumber = Number;
		_PreviousResult = _Result;
		_LastOperation = "Dividing";
		_Result /= Number;
	}

	void Multiplicatoin(float Number)
	{
		_LastNumber = Number;
		_LastOperation = "Multiply";
		_PreviousResult = _Result;
		_Result *= Number;

	}

	void Clear()
	{
	    _Result = 0;
		_PreviousResult = 0;
	    _LastOperation = " Clear ";
	    _LastNumber = 0;
	}

	void CancelOperation()
	{
		_LastNumber = 0;
		_LastOperation = "Cancel Operation ";
		_Result = _PreviousResult;
	}

	float GetFinalResult()
	{
		return _Result;
	}

	void PrintResult()
	{
		cout << "Result After " << _LastOperation << " " << _LastNumber << " is :" << _Result << endl;

	}

};

int main()
{
	clsCalculator Calculator1;

	Calculator1.Clear();
	Calculator1.Add(10);
	Calculator1.PrintResult();

	Calculator1.substracting(5);
	Calculator1.PrintResult();

	Calculator1.Add(55);
	Calculator1.PrintResult();

	Calculator1.Add(40);
	Calculator1.PrintResult();

	Calculator1.Divide(0);
	Calculator1.PrintResult();

	Calculator1.Divide(20);
	Calculator1.PrintResult();

	return 0;
}