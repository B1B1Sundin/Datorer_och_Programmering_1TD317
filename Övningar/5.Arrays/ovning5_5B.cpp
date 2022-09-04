#include <iostream>
using namespace std;

int main()
{
	const int MAXTEMP = 51;
	int frek[MAXTEMP]; // har index 0, 1, 2, ..., MAXTEMP-1
	int temp, min, max, antal = 0;

	cout << "Ge min- och maxtemperatur (så att max-min+1 <= 51 ): " << endl;
	cin >> min >> max;
	int max_index = max - min;

	for (int i = 0; i <= max_index; i++)
	{
		frek[i] = 0;
	}

	cout << "Ge temperaturer (heltal), avsluta med mindre än" << min << "eller eller större än " << max << " : " << endl;
	cin >> temp;
	while (min <= temp && temp <= max)
	{
		frek[temp - min]++;
		antal++;
		cin >> temp;
	}

	cout << "Frekvenstabell:" << endl;
	cout << "Temp.\t"
			 << "Antal\t"
			 << "Procent\t" << endl;

	for (int i = 0; i <= max_index; i++)
	{
		cout
				<< i + min << "\t" << frek[i] << "\t" << 100.0 * frek[i] / antal << endl;
	}

	return 0;
}