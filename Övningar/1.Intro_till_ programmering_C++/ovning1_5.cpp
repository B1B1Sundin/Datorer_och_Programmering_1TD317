#include <iostream>
using namespace std;

int main()
{
	int day, month, year;
	cout << "Skriv ett datum som tre tal, ex 2008 10 11" << endl;
	cin >> year >> month >> day;

	cout << day << "/" << month << " " << year << endl;
	return 0;
}