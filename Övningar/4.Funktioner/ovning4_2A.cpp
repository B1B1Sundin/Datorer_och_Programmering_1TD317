#include <iostream>
using namespace std;

// Funktionsdeklaration
void greetings();

int main()
{

	cout << "Jag hälsar på dej!" << endl;
	greetings();
	cout << "Vi ses!" << endl;

	return 0;
}

// funktionsdefinition
void greetings()
{
	int antal_varv;

	cout << "Hur många gånger vill Du bli hälsad?" << endl;
	cin >> antal_varv;

	for (int i = 0; i < antal_varv; i++)
		cout << " HEJ!" << endl;
}