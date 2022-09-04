#include <iostream>
using namespace std;

int main()
{
	int i, sum = 0;
	int tal;

	cout << "Skriv in x antal positiva tal. Om ett negativt tal skrivs in kommer summan av tidigare tal att räknas, samt hur många tal som skrevs in." << endl;
	cin >> tal;

	while (tal >= 0)
	{
		sum += tal;
		i++;
		cin >> tal;
	}

	cout << "Du skrev in " << i << " tal. Summan av talen är " << sum << "." << endl;
	return 0;
}