#include <iostream>
using namespace std;

int main()
{
	int tal, i;
	int max, sum = 0;

	cout << "Skriv in 10 tal" << endl;
	for (i = 0; i < 10; i++)
	{
		cin >> tal;
		sum += tal;
		if (tal > max)
		{
			max = tal;
		}
	}
	cout << "Summan av talen är " << sum << endl;
	cout << "Det högsta talet är " << max << endl;

	return 0;
}