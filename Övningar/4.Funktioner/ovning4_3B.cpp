#include <iostream>
using namespace std;

void berakna(int &sum, int &diff); // fyll i funktionsdeklarationen

int main()
{
	int summa, differens;

	berakna(summa, differens);

	cout
			<< "Talens summa är: " << summa << endl;
	cout << "Talens differens är: " << differens << endl;

	return 0;
}

void berakna(int &sum, int &diff)
{
	int a, b;
	cout << "Skriv in 2 heltal: " << endl;
	cin >> a >> b;
	sum = a + b;
	diff = a - b;
}

// Skriv funktionsdefinitionen själv. OBS: inmatningen av de två
// talen skall ske i funktionen, inte i main.

/**
 *Funktionen berakna frågar efter två heltal. Talens summa och differens beräknas i funktionen.
Resultatet skrivs ut av main. Se uppgift 3A) hur utskriften kan se ut.
 *
 */