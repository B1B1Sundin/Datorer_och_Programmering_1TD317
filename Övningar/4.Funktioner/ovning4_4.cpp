#include <iostream>
using namespace std;

int min(int x, int y); // Funktionsdeklaration.

int main()
{
	int a, b;
	cout << "Skriv in 2 heltal: " << endl;

	cin >> a >> b;

	int result = min(a, b);
	cout << result << " är det minsta av de två talen." << endl;

	return 0;
}

int min(int x, int y)
{
	if (x > y)
	{
		return y;
	}
	else
	{
		return x;
	}
}

/**
 * Skriv en funktion min som har två heltal som indata och som returnerar det minsta av de två talen.
Skriv även ett main som testar funktionen, dvs anropa funktionen med syfte att kontrollera att funktionen fungerar.
 *
 */