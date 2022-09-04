
#include <iostream>
using namespace std;

// funktionsdeklaration
// fyll i funktionsdeklarationen. Ledtråd: se funktionsanropet i main
void berakna(int x, int y);
int main()
{
	int a, b;

	cout << "Mata in två heltal: " << endl;
	cin >> a >> b;

	berakna(a, b); // funktionsanrop med två värdeparametrar. Inget returvärde.
	return 0;
}

// funktionsdefinition
void berakna(int x, int y)
{ // Satserna mellan { och } kallas för funktionens kropp.
	cout << "Talens summa är: " << x + y << endl;
	cout << "Talens differens är: " << x - y << endl;
	cout << "Talens produkt är: " << x * y << endl;
}
