#include <iostream>
using namespace std;

// Skriv ett program för temperaturomvandling. Skriv allt i samma fil, men ha strukturen: klassdefinition, huvudprogram, metodimplementation.

// Skapa en klass temperatur enligt följande

class temperatur
{
private:
	double grader; // i Celsius.

public:
	temperatur();									 // default-konstruktor
	temperatur(double t);					 // överlagrad konstruktor
	void lasin();									 // inläsning av grader
	void skriv();									 // utskrift av grader
	double haemta_grader();				 // returnerar grader
	double skillnad(temperatur t); // skillnaden mellan 2
	double fahrenheit();					 // return. i Fahrenheit
	void rapport();								 // skriver "rapport"
};

int main()
{
	temperatur temp1, temp2(17), temp3(16);
	cout << "skriv in en temperatur(celsius):";
	temp1.lasin();

	temp1.skriv();
	temp2.skriv();
	temp3.skriv();

	double dif = temp1.skillnad(temp3);
	cout << temp2.haemta_grader() << " celsius -> fahrenheit " << temp2.fahrenheit() << endl;

	temp1.rapport();
	temp2.rapport();
	temp3.rapport();

	return 0;
}
// Implementationer av klassens metoder

temperatur::temperatur()
{
	grader = 15;
}
temperatur::temperatur(double t)
{
	grader = t;
}
void temperatur::lasin()
{
	cin >> grader;
}
void temperatur::skriv()
{
	cout << grader << " celsius" << endl;
}
double temperatur::haemta_grader()
{
	return grader;
}
double temperatur::skillnad(temperatur t)
{
	return (grader - t.grader);
}
double temperatur::fahrenheit()
{
	return 32 + 1.8 * grader;
}

void temperatur::rapport()
{
	if (grader > 15)
	{
		cout << "Oh! Vad varmt det är idag!" << endl;
	}
	else if (grader < 5)
	{
		cout << "Oh! Vad kallt det är idag!" << endl;
	}
	else
	{
		cout << "Det är lagom varmt idag." << endl;
	}
}
