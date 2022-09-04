#include <iostream>
using namespace std;

// Funktionsdeklaration
int mindre_an(const double x[], int antal, double specialtal);

int main()
{
	int max;
	float tal, extra_Tal;

	cout << "Hej! Ge antal tal: ";
	cin >> max;
	double array[max];

	cout << "Ge de " << max << " st reella talen efter varandra:" << endl;
	for (int i = 0; i < max; i++)
	{
		cin >> tal;
		array[i] = tal;
	}
	cout << "Ge nu ett enda extratal: ";
	cin >> extra_Tal;

	int res = mindre_an(array, max, extra_Tal);
	cout << "Antal tal som är mindre än " << extra_Tal << " är " << res << endl;
	return 0;
}

int mindre_an(const double x[], int antal, double specialtal)
{
	int res;

	for (int i = 0; i < antal; i++)
	{
		if (x[i] < specialtal)
		{
			res++;
		}
	}
	return res;
}
