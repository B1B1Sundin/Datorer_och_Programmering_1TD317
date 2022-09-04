#include <iostream>
using namespace std;

int main()
{
	int x, y, produkt; // sats 1: 3 variabler deklareras

	cout << "Mata in ett tal: "; // sats 2: En text skall stå inom " "
	cin >> x;										 // sats 3: programmet stannar: mata in
															 //  ett tal, tryck <return>

	cout << "Du skrev talet "
			 << x << endl; // sats 4
										 // sats 5: här skrivs ditt tal ut
										 //  på skärman. INGA " " RUNT x!

	cout << "Mata in"
			 << " ett nytt"
			 << " tal: " << endl; // sats 6
	cin >> y;									// sats 7: x får ett nytt värde

	cout << "Summan av talen blir: " << x + y << endl; // sats 8-9: det nya värdet skrivs ut
	produkt = x * y;																	 // sats 10: variabeln produkt får värdet av produkten
																										 //  av dina två inmatade tal
	cout << x << "*" << y << " = " << produkt << endl; // sats 11
	return 0;
}