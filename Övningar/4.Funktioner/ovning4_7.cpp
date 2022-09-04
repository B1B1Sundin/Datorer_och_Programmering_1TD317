#include <iostream>
using namespace std;
char LasTecken();
char LasTeckenAlt(char a, char b, char c);
/**
 *  Antag att huvudprogrammet kunde styra funktionen genom att skicka med parametrar som angav vilka tre tecken som är godkända att läsas in.
 * Hur skulle denna alternativa funktion se ut ? Tips : Anropet i main kan se ut så här :
 * char ch1 = 'D',
		 ch2 = 'E', ch3 = 'F';
svar = LasTeckenAlt(ch1, ch2, ch3);
Eller så här :

		svar = LasTeckenAlt('K', 'L', 'M');
 *
 */

int main()
{
	char svar1, svar2;
	svar1 = LasTecken();
	cout << "(LasTecken) Svaret = " << svar1 << endl;

	svar2 = LasTeckenAlt('K', 'L', 'M');
	cout << "(LasTeckenAlt) Svaret = " << svar2 << endl;
	return 0;
}

char LasTeckenAlt(char a, char b, char c)
{
	char ch;
	cout << "Skriv in ett tecken. ";
	cin >> ch;

	while (!(ch == a || ch == b || ch == c))
	{
		cout << "Inkorrekt input." << endl;
		cin >> ch;
	}

	return ch;
}

char LasTecken()
{
	char ch;
	cout << "Skriv in ett tecken. ";
	cin >> ch;

	while (!(ch == 'A' || ch == 'B' || ch == 'C'))
	{
		cout << "Inkorrekt input." << endl;
		cin >> ch;
	}

	return ch;
}
