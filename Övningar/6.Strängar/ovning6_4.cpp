#include <iostream>
using namespace std;

int main()
{
	string text;
	int bokstav, siffror, övrigt = 0;

	cout << "Skriv en textrad. ";
	getline(cin, text);

	// kan istället använda isalpha() och isdigit()
	for (int i = 0; i < text.length(); i++)
	{
		if ((65 <= text.at(i) && text.at(i) <= 90) || (97 <= text.at(i) && text.at(i) <= 122))
		{
			bokstav++;
		}
		else if (48 <= text.at(i) && text.at(i) <= 57)
		{
			siffror++;
		}
		else
		{
			övrigt++;
		}
	}
	cout << "Bokstäver: " << bokstav << endl;
	cout << "Siffror: " << siffror << endl;
	cout << "Övriga Tecken: " << övrigt << endl;
	return 0;
}

/**
 * Skriv ett program som läser in en textrad (sträng), beräknar och skriver ut hur många bokstäver, siffror och övriga tecken som förekommer i textraden.
 Om du vill så kan du lösa den här uppgiften med hjälp av en funktion som har 4 parametrar, en sträng och tre räknare.
 *
 */