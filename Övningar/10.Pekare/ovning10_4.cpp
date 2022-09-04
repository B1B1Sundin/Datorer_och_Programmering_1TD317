#include <iostream>
using namespace std;

double *sort(const double *arr, int antal);
void skriv(double *array, int n, int k);

int main()
{
	int tal, rader;
	cout << "Skriv in ett tal." << endl;
	cin >> tal;

	double *array = 0;
	array = new double[tal];
	cout << "Skriv in " << tal << " tal." << endl;

	for (int i = 0; i < tal; i++)
	{
		cin >> *(array + i);
	}

	double *arr = sort(array, tal);

	cout << "Skriv in hur många kolumnner du vill att arrayen ska skrivas ut i. " << endl;
	cin >> rader;

	skriv(arr, tal, rader);

	return 0;
}

/**
som returnerar en sorterad array. Talen kommer från inparametern arr.
Varför har vi deklarerat arr som en const? - eftersom den ska inte ändras
 *
 * @param arr
 * @param antal längden
 * @return double*
 */
double *sort(const double *arr, int antal)
{
	int i, j, min_in;
	double *new_arr = 0;
	new_arr = new double[antal];

	for (int i = 0; i < antal; i++)
	{
		new_arr[i] = arr[i];
	}

	double copy;
	for (i = 0; i < antal; i++)
	{
		min_in = i;
		for (j = i + 1; j < antal; j++)
			if (new_arr[j] < new_arr[min_in])
			{
				min_in = j;
			}
		copy = new_arr[i];
		new_arr[i] = new_arr[min_in];
		new_arr[min_in] = copy;
	}

	return new_arr;
}

/**
 * @brief som skriver ut talen i arrayen array med k st tal per rad. n är längden på arrayen.
 *
 * @param array
 * @param n
 * @param k
 */
void skriv(double *array, int n, int k)
{
	for (int i = 0; i < n; i++)
	{
		cout << *(array + i) << "\t";
		if (((i + 1) % k) == 0)
		{
			cout << endl;
		}
	}
	cout << endl;
}
