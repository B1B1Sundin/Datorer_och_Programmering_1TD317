#include <iostream>
using namespace std;
void histo(string text);

int main()
{

	string text;

	cout << "Skriv in en radtext (engelska bokstäver). ";
	getline(cin, text);

	histo(text);

	return 0;
}
void histo(string text)
{
	int index;
	int antal = 26;
	int alfabet[antal];

	for (int i = 0; i < 26; i++)
	{
		alfabet[i] = 0;
	}

	for (int i = 0; i < text.length(); i++)
	{
		if (text.at(i) >= 'a' && text.at(i) <= 'z')
		{
			index = text.at(i) - 'a';

			alfabet[index]++;
		}
		else if (text.at(i) >= 'A' && text.at(i) <= 'Z')
		{
			index = text.at(i) - 'A';

			alfabet[index]++;
		}
	}
	cout << "Frekvens" << endl;
	for (int i = 0; i < antal; i++)
	{

		char b = char(i + 'A');
		if (alfabet[i] > 0)
		{
			cout << b << " = " << alfabet[i] << endl;
		}
	}
}

/**
 * Som uppgift 5, men där beräkning och utskrift av frekvensen görs av en funktion histo.
Skriv alltså en main-funktion som läser in en rad text och därefter anropar funktionen histo.
 */