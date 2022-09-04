#include <iostream>
using namespace std;

// Skriv ett program för temperaturomvandling. Skriv allt i samma fil, men ha strukturen: klassdefinition, huvudprogram, metodimplementation.

// Skapa en klass temperatur enligt följande

class temperatur
{
private:
	double grader; //
	string temp;	 // celsius eller fahrenheit

public:
	temperatur();												// default-konstruktor
	temperatur(double t, string s);			// överlagrad konstruktor
	void lasin();												// inläsning av grader
	void skriv();												// utskrift av grader
	double haemta_grader();							// returnerar grader
	double skillnad(temperatur t);			// skillnaden mellan 2
	double fahrenheit();								// return. i Fahrenheit
	void rapport(int nedre, int oevre); // skriver "rapport"
	string haemta_temp();
};

int main()
{

	int MAX = 7;
	temperatur juli2020[MAX];
	double temp;
	string typ;
	cout << "Fahrenheit eller Celsius?" << endl;
	cin >> typ;

	cout << "Ge sju st medeltemperaturer i angiven enhet:" << endl;
	for (int i = 0; i < MAX; i++)
	{
		cin >> temp;
		juli2020[i] = temperatur(temp, typ);
	}
	cout << "Nu testar vi att skriva ut alla i vacker tabell:" << endl;
	for (int i = 0; i < MAX; i++)
	{
		juli2020[i].skriv();
		juli2020[i].rapport(10, 20);
	}

	return 0;
}
// Implementationer av klassens metoder

temperatur::temperatur()
{
	grader = 15;
	temp = "celsius";
}
temperatur::temperatur(double t, string s)
{
	grader = t;
	temp = s;
}
void temperatur::lasin()
{
	cin >> grader;
	cin >> temp;
}
void temperatur::skriv()
{
	// Temperaturen är 15 grader Celsius.
	cout << "Temperaturen är " << grader << " grader " << temp << "." << endl;
}
double temperatur::haemta_grader()
{
	return grader;
}
string temperatur::haemta_temp()
{
	return temp;
}
double temperatur::skillnad(temperatur t)
{
	if (temp == t.temp)
	{
		return (grader - t.grader);
	}
	return -66.6;
}
double temperatur::fahrenheit()
{
	if (temp != "fahrenheit")
	{
		return 32 + 1.8 * grader;
	}
	return grader;
}

/**
 * void temperatur::rapport( int nedre, int oevre )
 * dvs kontrollera om temperaturen är större än oevre grader, mindre än nedre, eller mellan nedre och oevre grader och skriv ut lämplig text.
 *
 */
void temperatur::rapport(int nedre, int oevre)
{
	if (grader > oevre)
	{
		cout << "Oh! Vad varmt det är idag!" << endl;
	}
	else if (grader < nedre)
	{
		cout << "Oh! Vad kallt det är idag!" << endl;
	}
	else
	{
		cout << "Det är lagom varmt idag." << endl;
	}
}
