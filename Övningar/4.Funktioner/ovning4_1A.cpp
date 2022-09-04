#include <iostream>
using namespace std;

// Funktionsdeklaration:
// En in-parameter (s.k. värdeparameter): antal
// Inget returvärde, dvs void

void greetings(int varv);

int main() // huvudprogram
{
	int antal;

	cout << "Jag hälsar på dej!" << endl;
	cout << "Hur många gånger vill Du bli hälsad?" << endl;
	cin >> antal; // main frågar efter antalet

	greetings(antal);

	cout << "Vi ses!" << endl;

	return 0;
}

/**
 * Funktionen skriver ut " HEJ!" x antal gånger som parametern anger
 *
 * @param varv
 */
void greetings(int varv)
{
	for (int i = 0; i < varv; i++)
		cout << " HEJ!" << endl;
}