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
	if (n != 0)
	{
		cout << "Hurra!" << endl;
		hurra(n - 1);
	}
}