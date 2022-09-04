#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	string namn1, namn2, in_fil;
	double belopp, belopp1, belopp2 = 0.0;
	string namn;

	ifstream in("betalat.txt");

	getline(in, namn1);
	getline(in, namn2);

	while (in >> namn >> belopp)
	{
		if (namn == namn1)
		{
			belopp1 += belopp;
			cout << belopp1 << endl;
		}
		else if (namn == namn2)
		{
			belopp2 += belopp;
		}
	}
	belopp = 0;
	cout << "belopp för " << namn1 << " = " << belopp1 << endl;
	cout << "belopp för " << namn2 << " = " << belopp2 << endl;

	if (belopp1 > belopp2)
	{
		belopp = (belopp1 + belopp2) / 2;
		cout << namn2 << " ska betala " << belopp - belopp2 << " kr till " << namn1 << endl;
	}
	else if (belopp2 > belopp1)
	{
		belopp = (belopp1 + belopp2) / 2;
		cout << namn1 << " ska betala " << belopp - belopp1 << " kr till " << namn1 << endl;
	}
	else
	{
		cout << "De har betalat lika mycket." << endl;
	}

	in.close();
	return 0;
}
/**
 *
De första två raderna anger namnen på de två personerna. Sedan kommer en följd av rader som anger vem som betalat och hur mycket.
Exempelvis så Eva betalade 200 kr då de åt glass, Bosse 300 kr då de tankade bilen etc.

De vill att du skriver programmet som skall se ut så här vid körning (ungefär):

Läser in namn och belopp från filen betalat.txt
Eva har betalat 500 kr totalt.
Bosse har betalat 400 kr totalt.
Resultat: Bosse skall betala Eva 50 kr.
Skriv programmet som läser från betalat.txt och beräknar summorna samt ger utskrift liknande den ovan. De två första raderna i filen anger alltid två olika namn.
I exemplet ovan följer sedan fem (5) rader, men programmet skall klara av kvittolistor (filer) av olika längd naturligtvis.
 *
 */
