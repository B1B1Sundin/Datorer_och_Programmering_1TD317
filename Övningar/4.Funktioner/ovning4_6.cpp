#include <iostream>
using namespace std;
int ant_sek(int H, int M, int S);

int main()
{
	int h, m, s;
	cout << "Skriv in en tid (HH:MM:SS)" << endl;
	cin >> h >> m >> s;
	int sekunder = ant_sek(h, m, s);
	cout << "Totala antalet sekunder är: " << sekunder << endl;
	return 0;
}

int ant_sek(int H, int M, int S)
{
	return H * 60 * 60 + M * 60 + S;
}
/**
Skriv en funktion ant_sek som givet ett antal timmar, minuter och sekunder beräknar antalet sekunder som detta motsvarar.
Skriv även ett main som testar funktionen ant_sek, dvs läser in tre heltal och returnerar ett heltal.
 *
 */