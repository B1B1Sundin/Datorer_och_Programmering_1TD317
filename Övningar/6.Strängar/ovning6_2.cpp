#include <iostream>
using namespace std;

int main()
{
	string namn;
	cout << "Skriv in ett namn. ";
	getline(cin, namn);

	cout << "Lodrätt:" << endl;
	for (int i = 0; i < namn.length(); i++)
	{
		cout << namn.at(i) << endl;
	}

	cout << "\nBaklänges:" << endl;
	for (int i = namn.length() - 1; i >= 0; i--)
	{
		cout << namn.at(i);
	}
	cout << endl;
	return 0;
}