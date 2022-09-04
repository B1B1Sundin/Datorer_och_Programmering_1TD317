#include <iostream>
using namespace std;

int main()
{
	int array[5];

	int tal;

	cout << "Skriv in 5 tal" << endl;
	for (int i = 0; i < sizeof(array) / sizeof(int); i++)
	{
		cin >> tal;
		array[i] = tal;
	}

	cout << "Talen i omvänd ordning är då:" << endl;
	for (int i = sizeof(array) / sizeof(int) - 1; i >= 0; i--)
	{
		cout << array[i] << endl;
	}

	return 0;
}
/**
 * Skriv ett program som läser in fem heltal i en array och därefter skriver ut talen i omvänd ordning.
En körning kan se ut på följande sätt (indata som användaren ger är i fet stil):
Ge 5 tal.
Ange tal 1: 3
Ange tal 2: 1
Ange tal 3: 23
Ange tal 4: -2
Ange tal 5: 7
Talen i omvänd ordning: 7 -2 23 1 3
 *
 */