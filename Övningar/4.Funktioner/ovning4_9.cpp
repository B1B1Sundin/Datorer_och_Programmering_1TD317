#include <iostream>
using namespace std;

/* Funktion som beräknar siffersumman */

int sifferSumma(int x)
{
	int sum = 0;

	while (x > 0)
	{
		sum += x % 10;

		x /= 10;
	}
	return sum;
}

int main()
{
	int a;

	cout << "Skriv in ett tal (siffersumma): " << endl;
	cin >> a;

	cout << "Siffersumman = " << sifferSumma(a) << endl;

	return 0;
}
