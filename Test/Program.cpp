#include <iostream>
#include <string>
#include "Console.h"
#include "Strings.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::to_string;
using utility::Console;
using utility::Strings;

// DECLARE vs DEFINE
bool isEven(int number);


int main()
{
	double x = 123.456;
	double y = x;
	double* ptr = &x;
	double** p = &ptr;

	
	cout << &*&ptr << endl << endl;

	cout << x << endl << y << endl;
	
	*ptr = 3.14159;
	cout << endl << x << endl << y << endl;

	ptr = &y;
	*ptr = 100 * x;

	cout << endl << x << endl << y << endl;





	/*Console::writeLine("Hello");
	Console::writeLine("Goodbye");
	Console::writeLine("Enter a number");

	int number = Console::readInteger();

	if (isEven(number))
	{
		string message = Strings::integerToString(number) + " is even";
		Console::writeLine(message);
	}
	else
	{
		string message = Strings::integerToString(number) + " is odd";
	    Console::writeLine(message);
	}*/

	return 0;
}

bool isEven(int number)
{
	return number % 2 == 0;
}