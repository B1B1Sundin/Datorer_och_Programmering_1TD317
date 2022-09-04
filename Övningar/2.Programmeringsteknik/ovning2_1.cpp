#include <iostream>
using namespace std;

/**
Heltalsdivision
Skriv ett program som läser in två heltal (variabeln tal1 respektive tal2).
Beräkna sedan tal1/tal2 och float(tal1)/tal2 samt skriv ut resultaten.
Testa programmet med lite olika värden på tal1 och tal2,
t ex 3 och 4, 5 och 3, -3 och 4, samt 5 och 0.

Vad blir resultatet? Och varför?
Spara programmet som ovning_2_2.cpp
 *
 */
int main()
{
	int tal1, tal2, tal3;
	float float3;

	cout << "Skriv in 2 heltal (täljare/nämnare)" << endl;
	cin >> tal1;
	if (tal1 == 0)
	{
		cout << "Täljaren kan inte vara 0, skriv in ett nytt heltal." << endl;
		cin >> tal1;
	}
	cin >> tal2;

	if (tal2 == 0)
	{
		float3 = 0.0;
	}
	else
	{
		float3 = float(tal1) / tal2;
	}
	tal3 = tal1 / tal2;

	cout << "(int) " << tal1 << " / " << tal2 << " = " << tal3 << endl;

	cout << "(float) " << tal1 << " / " << tal2 << " = " << float3 << endl;

	return 0;
}