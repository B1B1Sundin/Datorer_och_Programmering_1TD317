
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Blomgrupp
{
private:
	int x, y;		 // Positionen (x,y) i trädgården
	string namn; // Namn på blomgruppen (ex. tulpan)
	int antal;	 // Antal st blommor i blomgruppen

public:
	Blomgrupp();
	Blomgrupp(string namnin, int antalin,
						int xin, int yin);

	//--Returnerar antalet blommor i denna blomgrupp.
	int hamtaAntal();

	//--Returnera sant om blomgr. finns i (xx,yy).
	bool liggeri(int xx, int yy);

	//--Returnerar sant om blomgruppen heter n.
	bool sammanamn(string n);

	//--Läser in data om blomgrupp från fil.
	bool laes(istream &is);

	//--Skriver info om blomgruppen.
	void skriv(ostream &os);
};

int main()
{
	int val;
	const int MAX = 11;
	int antal = 0;
	Blomgrupp blommor[MAX];
	Blomgrupp blomma;

	cout << "Vad vill du göra?" << endl;
	cout << "1) Läsa från fil och skriva på skärmen" << endl;
	cout << "2) Läsa från fil och skriva på ny fil (ny.txt)." << endl;
	cin >> val;

	ifstream in_fil("blommor0.txt");

	if (in_fil)
	{
		while (blomma.laes(in_fil))
		{
			if (antal < MAX)
			{
				blommor[antal] = blomma;
				antal++;
			}
		}
	}

	if (val == 1) // skriver till skärmen.
	{
		for (int i = 0; i < antal; i++)
		{
			blommor[i].skriv(cout);
		}
		cout << "eller utskrift på fil:" << endl;
	}
	in_fil.close();

	if (val == 2) // skriver till en fil.
	{
		cout << "Ny fil (ny.txt) skapas!" << endl;
		cout << "Då ser ny.txt ut så här:" << endl;

		ofstream out_fil("ny.txt");

		for (int i = 0; i < MAX; i++)
		{
			blommor[i].skriv(out_fil);
		}
		out_fil.close();

		for (int i = 0; i < antal; i++)
		{
			blommor[i].skriv(cout);
		}
	}

	return 0;
}
Blomgrupp::Blomgrupp()
{
	namn = "";
	antal = 0;
	x = 0;
	y = 0;
}
Blomgrupp::Blomgrupp(string namnin, int antalin,
										 int xin, int yin)
{
	namn = namnin;
	antal = antalin;
	x = xin;
	y = yin;
}

//--Returnerar antalet blommor i denna blomgrupp.
int Blomgrupp::hamtaAntal()
{
	return antal;
}

//--Returnera sant om blomgr. finns i (xx,yy).
bool Blomgrupp::liggeri(int xx, int yy)
{
	if (xx == x && yy == y)
	{
		return true;
	}

	return false;
}

//--Returnerar sant om blomgruppen heter n.
bool Blomgrupp::sammanamn(string n)
{
	if (n == namn)
	{
		return true;
	}
	return false;
}

//--Läser in data om blomgrupp från fil.
/**
 * @brief Metoden laes läser en rad i filen och tilldelar Blomgrupp-objektet attributvärden.
Metoden returnerar false om filen, efter inläsning en rad, är slut, annars returneras true.
Inläsning i huvudprogrammet måste ske på sådant sätt att man skall kunna läsa från "vilken blomfil som helst", dvs programmeraren skall ej veta antaler rader i filen!
Programmet skall läsa tills filen är slut.
 *
 * @param is
 * @return true
 * @return false
 */
bool Blomgrupp::laes(istream &is)
{
	is >> namn >> antal >> x >> y;
	is.get(); // bort med returtecknet...

	return !is.eof(); // eller denna.
}

//--Skriver info om blomgruppen.
void Blomgrupp::skriv(ostream &os)
{
	os << "Blomgrupp: " << namn << " " << x << " " << y << " " << antal << endl;
}