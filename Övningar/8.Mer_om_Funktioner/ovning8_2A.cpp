#include <iostream>
using namespace std;

void hurra(int n);

int main()
{
	int antal;
	cout << "Hej! Hur många gånger skall vi hurra?" << endl;
	cin >> antal;

	hurra(antal);

	return 0;
}

void hurra(int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Hurra!" << endl;
	}
}