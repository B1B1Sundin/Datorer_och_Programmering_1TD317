#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	string in_fil, ut_fil, rad;

	cout << "Skriv filnamnet for den skadade filen: ";
	getline(cin, in_fil);
	ifstream infil(in_fil.c_str());

	if (!infil.good())
	{
		cout << "Filen gick inte att öppna!" << endl;
		return 0;
	}

	cout << "Ge filnamn för den återställda filen: ";
	getline(cin, ut_fil);
	ofstream utfil(ut_fil.c_str());

	if (!utfil.good())
	{
		cout << "Filen gick inte att öppna!" << endl;
		return 0;
	}

	while (getline(infil, rad))
	{

		for (int i = rad.length() - 1; i >= 0; i--)
			utfil << rad.at(i);
		utfil << endl;
	}

	infil.close();
	utfil.close();

	return 0;
}