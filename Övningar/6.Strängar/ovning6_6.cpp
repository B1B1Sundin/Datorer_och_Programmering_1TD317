#include <iostream>
using namespace std;

int main()
{
	const int MAX = 4;
	int nyckel;
	string chiffer[MAX];

	for (int i = 0; i < 4; i++)
	{
		cout << "Mata in en rad med text: " << endl;
		getline(cin, chiffer[i]); // Läs in 1:a strängen
	}

	cout << "Get ett tal: ";
	cin >> nyckel;

	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < (int)chiffer[i].length(); j++)
		{

			chiffer[i].at(j) = chiffer[i].at(j) + nyckel;
		}
	}

	for (int i = 0; i < MAX; i++)
	{
		cout << i << ". " << chiffer[i] << endl;
	}
	return 0;
}
