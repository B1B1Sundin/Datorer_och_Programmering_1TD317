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
	~temperatur();											// destruktor
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
	cout << "Temperaturer, lite gott & blandat" << endl;

	temperatur temp3, temp2(17, "celsius"), temp1(60, "fahrenheit");
	cout << "1. ";
	temp2.skriv();
	cout << "2. ";
	temp1.skriv();

	cout << "skriv den tredje temperaturen och typ (f eller c):" << endl;
	cout << "3. ";
	temp1.lasin();

	temp3.rapport(0, 20);
	temp2.rapport(10, 15);
	temp1.rapport(-10, 0);

	cout << "jämför temperatur 1 och 3";
	double dif = temp1.skillnad(temp3);
	if (dif == 66.6)
	{
		cout << "Kan inte jämföra två olika temperatur typer.";
	}

	cout << "temperatur 2: " << temp2.haemta_grader() << " celsius -> fahrenheit " << temp2.fahrenheit() << endl;

	return 0;
}
// Implementationer av klassens metoder

temperatur::temperatur()
{
	grader = 15;
	temp = "celsius";
	cout << "Jag är default-konstruktor: "
			 << "grader = " << grader << endl;
}
temperatur::temperatur(double t, string s)
{
	grader = t;
	temp = s;
	cout << "Jag är överlagrad konstruktor: "
			 << "grader = " << grader << endl;
}

temperatur::~temperatur()
{
	cout << "Nu dödas objekt med temperatur = "
			 << grader << endl;
}

void temperatur::lasin()
{
	cin >> grader;
	cin >> temp;
}
void temperatur::skriv()
{
	cout << grader << " " << temp << endl;
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