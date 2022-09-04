#include <iostream>
using namespace std;
void swap(int &a, int &b);

int main()
{
	int x, y;

	cout << "Skriv in 2 heltal (X, Y) " << endl;
	cin >> x >> y;

	cout << "Före:  X = " << x << " / Y = " << y << endl;
	swap(x, y);
	cout << "Efter:  X = " << x << " / Y = " << y << endl;
	return 0;
}

void swap(int &a, int &b)
{
	int c;
	c = a;
	a = b;
	b = c;
}

/**
 * Skriv en funktion byt som byter värden på två variabler.
Skriv också ett huvudprogram som testar funktionen, dvs läser in två tal, anropar funktionen och sedan skriver ut talen som då bytt värde.
(Denna funktion är en klassiker i programmeringssammanhang :-) )
 *
 */