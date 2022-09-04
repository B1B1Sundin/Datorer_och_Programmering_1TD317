#include <iostream>
using namespace std;

int berakna(int x, int y);

int main()
{
	int a, b;

	cout << "Mata in två heltal: " << endl;
	cin >> a >> b;

	cout << "Produkten blir: " << berakna(a, b) << endl;

	return 0;
}

// Skriv funktionsdefinitionen själv
int berakna(int x, int y)
{
	return x * y;
}
