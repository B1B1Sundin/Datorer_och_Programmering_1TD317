#include <iostream>
using namespace std;

int main()
{
	int tal; // fyll i de variable du behöver (kan fyllas i sist)
	int sum = 0;
	int i = 1; // i ges ett startvärde!

	cout << "Skriv in 5 tal för att beräkna dess summa." << endl;
	while (i <= 5) // satserna mellan { och } utförs om det stämmer att i<=5
	{
		cin >> tal;																	// Mata in ett tal. Använd inte 5 olika variabelnamn!
		sum += tal;																	// summera talet till variabeln sum, se uppgift 3 ovan
		i = i + 1;																	//öka  i  med 1.
	}																							// När i blivit 6 är det slut på while-loopen
	cout << "Summan av talen är " << sum << endl; // skriv ut summan med lämplig ledtext

	return 0;
}