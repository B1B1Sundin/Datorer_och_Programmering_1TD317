#include <iostream>
using namespace std;

int main()
{
	int tal1, tal2, summa; // Du behöver tre variabler

	cout << "Mata in ett tal: ";
	cin >> tal1;

	cout << "Mata in ett tal till: ";
	cin >> tal2;
	summa = tal1 + tal2;

	cout << "Talen är " << tal1 << " och " << tal2 << ". Summan av talen blir " << summa << endl;
}