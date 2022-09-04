#include <iostream>
using namespace std;
void skriv(string namn, string op);

int main()
{
	string namn, operand;
	cout << "Skriv in ett namn. ";
	getline(cin, namn);
	cout << "lodrätt eller baklänges? ";
	cin >> operand;
	skriv(namn, operand);

	return 0;
}

void skriv(string namn, string op)
{
	if (op == "lodrätt")
	{
		for (int i = 0; i < namn.length(); i++)
		{
			cout << namn.at(i) << endl;
		}
	}
	else
	{
		for (int i = namn.length() - 1; i >= 0; i--)
		{
			cout << namn.at(i);
		}
		cout << endl;
	}
}
/**
 * Skriv en funktion skriv som givet två parametrar löser uppgiften ovan.
Exempel:
Funktionsanrop: skriv(namn,"baklänges");
ska resultera i att funktionen skriver ut namnet namn baklänges, och med parametern "lodrätt" ska utskriften ske vertikalt.
Skriv även main som anropar din funktion för att testa att den fungerar på rätt sätt.
OBS! Om det blir problem med svenska tecken kan använda orden "baklanges" resp. "lodratt" istället.
 *
 */