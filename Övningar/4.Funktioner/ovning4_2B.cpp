
#include <iostream>
using namespace std;

int berakna(); // fyll i funktionsdeklarationen för berakna

int main()
{
	int resultat;

	resultat = berakna();
	cout << "Produkten blir: " << resultat << endl;

	return 0;
}

int berakna()
{
	int a, b;
	cout << "Mata in två heltal: " << endl;
	cin >> a >> b;

	return a * b;
}
