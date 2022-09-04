#include <iostream>
using namespace std;

int main()
{
	int tal; // fyll i de variable du behöver (kan fyllas i sist)
	int sum = 0;
	int i = 1; // i ges ett startvärde!

	cout << "Skriv in 5 tal för att beräkna dess summa." << endl;
	for (i = 1; i <= 5; i++) // variabeln i räknar fr o m 1  t o m 5, ett steg i taget
	{												 // satserna mellan { och } utförs 5 gånger
		cin >> tal;						 // Mata in ett tal.
		sum += tal;						 // summera talet till variabeln sum,
	}
	cout << "Summan av talen är " << sum << endl; // skriv ut summan med lämplig ledtext

	return 0;
}