#include <iostream>
using namespace std;

int main()
{
	const int MAXTEMP = 51;
	int frek[MAXTEMP]; // har index 0, 1, 2, ..., MAXTEMP-1
	int temp, max, antal = 0;

	cout << "Ge maxtemperatur (mellan 0 och 50): ";
	cin >> max;
	for (int i = 0; i < MAXTEMP; i++)
	{
		frek[i] = 0;
	}

	cout << "Ge temperaturer (heltal),avsluta med negativt eller större än 7 : " << endl;
	cin >> temp;
	while (0 <= temp && temp <= max)
	{
		frek[temp] += 1;
		antal++;
		cin >> temp;
	}
	cout << "Frekvenstabell:" << endl;
	cout << "Temp.\t"
			 << "Antal\t"
			 << "Procent\t" << endl;
	for (int i = 0; i <= max; i++)
	{

		cout
				<< i << "\t" << frek[i] << "\t" << 100.0 * frek[i] / antal << endl;
	}
	return 0;
}
