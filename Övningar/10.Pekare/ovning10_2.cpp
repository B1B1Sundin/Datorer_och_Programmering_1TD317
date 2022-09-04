#include <iostream>
using namespace std;

int main()
{
	int n;
	cout << "skriv in ett tal" << endl;
	cin >> n;

	int *array = 0;
	array = new int[n];

	int *kopia = 0;
	kopia = new int[n];

	cout << "skriv in " << n << " tal" << endl;

	for (int i = 0; i < n; i++)
	{
		cin >> *(array + i);
	}
	cout << endl;

	for (int i = 0; i < n; i++)
	{
		*(kopia + i) = *(array + i);
	}

	for (int i = 0; i < n; i++)
	{
		cout << *(kopia + i) << "\t";
		if (((i + 1) % 5) == 0)
		{
			cout << endl;
		}
	}
	cout << endl;

	delete[] array;
	delete[] kopia;
}