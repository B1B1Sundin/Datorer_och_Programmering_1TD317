#include <iostream>
using namespace std;
void byt_priser(double x[], const bool r[], int antal);
// TO DO LATER

int main()
{

	bool rea;
	double pris;
	int artiklar;

	cout << "Hur många artiklar? ";
	cin >> artiklar;

	double pris_array[artiklar];
	bool rea_array[artiklar];

	cout << "Ge priserna: " << endl;

	for (int i = 0; i < artiklar; i++)
	{
		cin >> pris;
		pris_array[i] = pris;
	}

	cout << "Ge 1:or och 0:or: " << endl;
	for (int i = 0; i < artiklar; i++)
	{
		cin >> rea;
		rea_array[i] = rea;
	}

	byt_priser(pris_array, rea_array, artiklar);

	// cout << "Nya priser: " << endl;
	// for (int i = 0; i < artiklar; i++)
	// {
	// 	if (rea_array[i] == 1)
	// 	{
	// 		pris_array[i] *= 0.7;
	// 	}
	// }

	for (int i = 0; i < artiklar; i++)
	{
		cout << pris_array[i] << " ";
	}

	return 0;
}

// x = priserna, antal priser i x, r = array med 1 och 0
void byt_priser(double x[], const bool r[], int antal)
{
	for (int i = 0; i < antal; i++)
	{
		if (r[i] == 1)
		{
			x[i] *= 0.7;
		}
	}
}

/**
I den här uppgiften ska du sänka priserna på vissa varor med 30%.
Du har två arrayer pris och rea. Båda kan innehålla max 20 stycken element.

Variabeln pris är av typen double och rea av typen int.
I rea är varje tal antingen 1 eller 0, där 1 står för prissänkning (dvs rea) och 0 står betyder att det inte är någon prissänkning på motsvarande vara.
I pris står priserna som ska sänkas om motsvarande element i rea är lika med 1.
Din uppgift är att skriva ett program som läser in priserna och lagrar dem i arrayen pris samt läser in talen (1 eller 0) och lagrar dem i arrayen rea.
Programmet ska sedan ändra priserna och skriva ut de nya priserna.
Körningsexempel:

Hur många artiklar? 10
Ge priserna:
99.50 24.5 44.5 66.78 22.30 100.00 100.00 50.60 55.50 10.40
Ge 1:or och 0:or:
1 1 1 0 0 0 1 1 1 0
Nya priser:
69.65  17.15  31.15  66.78  22.3  100   70   35.42  38.85  10.4
 *
 */