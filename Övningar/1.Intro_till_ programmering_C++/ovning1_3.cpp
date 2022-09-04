#include <iostream>
using namespace std;

int main()
{
	int year, month, day; // Tre variabler av typen int, dvs heltal deklareras

	cout << "Hur gammal är du? "; // ger utskrift på skärmen, se exemplet ovan
	cin >> year;									// inmatning från tangentbordet av ett heltal, se exemplet
	month = year * 12;						// beräkning av antalet månader - inget syns på skärmen
	day = year * 365;							// beräkning av antalet dagar. Skriv raden själv. Vi antar att alla månader har 30 dagar...
	cout
			<< "Du är " << month << " månader dvs " << day << " dagar." << endl; // utskrift: Text står inom <<" ... "<<  eller <<" ... ";  vid radslut. Variabler inom <<...<<  eller <<...;  vid radslut. Fyll i det som fattas. Se exemplet.

	return 0;
}