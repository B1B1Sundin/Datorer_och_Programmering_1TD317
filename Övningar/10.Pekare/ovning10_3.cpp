#include <iostream>
using namespace std;

double *laes(int &n);
double medel(double *arr, int antal);

int main()
{
	int tal;

	double *a = laes(tal);
	double medel_varde = medel(a, tal);
	cout << medel_varde << endl;
	return 0;
}

/**
 * läser in heltalet n och n st flyttal (double) i en array, och returnerar denna array som en pekare.
Skriv en funktion som tar en array som inparameter, och beräknar och returnerar medelvärdet.
 *
 * @param n
 * @return double*
 */
double *laes(int &n)
{
	cout << "Ange n: ";
	cin >> n;

	double *array = 0;
	array = new double[n];

	cout << "Ange " << n << " stycken tal: " << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> *(array + i);
	}

	return array;
}

/**
 * @brief Skriv en funktion som tar en array som inparameter, och beräknar och returnerar medelvärdet.
 *
 * @param arr
 * @param antal
 * @return double
 */
double medel(double *arr, int antal)
{
	double sum = 0;
	for (int i = 0; i < antal; i++)
	{
		sum += *(arr + i);
	}

	return sum / antal;
}