#include <iostream>
using namespace std;

// Funktionsdeklaration
void min_max(int a, int b, int &min, int &max);

int main()
{
	int x, y;
	int max, min;
	cout << "Skriv in 2 heltal: " << endl;

	cin >> x >> y;

	min_max(x, y, min, max);

	cout << "Max: " << max << " / Min: " << min << endl;
	return 0;
}
void min_max(int a, int b, int &min, int &max)
{
	if (a > b)
	{
		max = a;
		min = b;
	}
	else
	{
		max = b;
		min = a;
	}
}

/**
Skriv en funktion min_max som beräknar det minsta samt det största talet av två inmatade heltal.
Skriv även ett main som testar funktionen.

 *
 */