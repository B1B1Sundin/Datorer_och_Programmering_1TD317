#include <iostream>
using namespace std;

int main()
{
	int antal = 26;
	int alfabet[antal];
	string text;
	int index;

	for (int i = 0; i < 26; i++)
	{
		alfabet[i] = 0;
	}

	cout << "Skriv in en radtext (engelska bokstäver). ";
	getline(cin, text);

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

	return 0;
}

/**
 * Skriv ett program som läser in en rad text, beräknar och skriver ut frekvenser av de olika bokstäverna. Antag att texten består av enbart engelska bokstäver.
 *
 */