
#include <iostream>
using namespace std;

void berakna(int x, int y, int &sum, int &diff);

int main()
{
	int a, b, summa, differens;

	cout << "Mata in två heltal: " << endl;
	cin >> a >> b;

	berakna(a, b, summa, differens);

	cout << "Talens summa är: " << summa << endl;
	cout << "Talens differens är: " << differens << endl;

	return 0;
}

void berakna(int x, int y, int &sum, int &diff)
{
	sum = x + y;
	diff = x - y;
}

// Skriv funktionsdefinitionen själv. Skall det finnas någon return-sats?
/**
 * Mata in två tal:
5 3
Talens summa är: 8
Talens differens är: 2
Programmet frågar efter två heltal. Talens summa och differens beräknas och skrivs ut.

Nedan finns ett ofullständigt program som du skall komplettera så att det fungerar enligt ovan.
Programmet består av funktionen berakna. Summan och differensen returneras till main och skrivs ut där.
Fungerar det med returvärde om två tal skall returneras? Tips: Ett annat sätt att "returnera" (ge tillbaks) värden är att använda referensparametrar.

 *
 */