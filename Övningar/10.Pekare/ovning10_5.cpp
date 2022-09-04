#include <iostream>
using namespace std;

double sum(double *a, int n);

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

	double result = sum(array, tal);

	cout << "Summan av talen är: " << result << endl;

	return 0;
}

/**
 * @brief som beräknar summan av arrayen a med hjälp av rekursion.
 *
 * @param a
 * @param n
 * @return double
 */
double sum(double *a, int n)
{
	double res = 0;
	if (n <= 0)
	{
		return 0.0;
	}
	else
	{
		return *a + sum(a + 1, n - 1);
	}
}
