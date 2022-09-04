#include <iostream>
using namespace std;

int main()
{
	int year;

	cout << "Vilket årtusende är du född?" << endl;
	cout << "Vilket år är du född? "; // fråga efter födelseår
	cin >> year;											// inmatning av födelseår

	if (year < 2000)
	{
		cout << "Du föddes förra årtusendet." << endl;
	}

	return 0;
}