#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	float flyttal;
	int heltal;

	cout << "Skriv in ett flyttal. (float)" << endl;
	cin >> flyttal;
	heltal = round(flyttal);

	cout << heltal << endl;

	return 0;
}