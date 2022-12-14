#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// temperatur2.cpp

// Deklaration av klassen:

class temperatur
{
private:
  double grader; // gradtal
  string typ;    // "Celsius" eller "Fahrenheit".

public:
  temperatur();                       // default-konstruktor
  temperatur(double t, string typen); // överlagrad konstruktor
  void lasin();                       // inläsning av grader
  void skriv();                       // utskrift av grader
  double haemta_grader();             // selektor: returnerar grader
  string haemta_typ();                // selektor, returnerar typ.
  double skillnad(temperatur t);      // skillnaden mellan 2 temperaturer
  double fahrenheit();                // returnerar grader i Fahrenheit
  void rapport(int nedre, int oevre); // skriver "rapport"
  void skriv(ostream &ut);
  void lasin(istream &in);
};
//------------------------------------------------------
// Huvudprogram:

int main()
{
  temperatur t1, t2;
  temperatur t3(35, "Celsius"), t4(100, "Fahrenheit");
  t2.lasin();

  cout << "Skriver ut värdena på skärmen:" << endl;
  t1.skriv();
  t2.skriv();
  t3.skriv();
  t4.skriv();
  // cout << "Rapporter:" << endl;
  // t3.rapport(5, 15);
  // t4.rapport(75, 90);
  cout << endl;
  temperatur arr[] = {t1, t2, t3, t4};
  ofstream out_fil("test.txt");
  cout << "Skriver ut temperaturerna till en fil." << endl;
  for (int i = 0; i < 4; i++)
  {
    arr[i].skriv(out_fil);
  }
  out_fil.close();

  ifstream in_fil("test.txt");
  if (in_fil)
  {
    const int MAX = 10;
    temperatur temps[MAX];
    int antal = 0;
    temperatur temp;

    temp.lasin(in_fil);
    while (antal < MAX && !in_fil.eof())
    {
      temps[antal] = temp;
      antal++;
      temp.lasin(in_fil);
    }

    cout << "Hämtar temperatur från en fil." << endl;
    for (int i = 0; i < antal; i++)
    {
      temps[i].skriv(cout);
    }
    cout << endl;
  }

  double temp = t1.haemta_grader();
  string grad_enhet = t1.haemta_typ();
  cout << "Default-objekt: " << temp
       << " " << grad_enhet << endl;

  double f = t1.fahrenheit();
  cout << temp
       << " grader Celsius motsvaras av "
       << f << " grader Fahrenheit." << endl;

  double d = t2.skillnad(t3);
  cout << "Skillnaden mellan " << t2.haemta_grader()
       << " och " << t3.haemta_grader()
       << " = " << d << endl;

  return 0;
}

//------------------------------------------------------
// Implementation av klassens metoder:

// ---Konstruktorer---

temperatur::temperatur() // default-konstruktor
{
  grader = 28;
  typ = "Celsius";
}

temperatur::temperatur(double t, string typen)
{
  grader = t;
  typ = typen;
}

// ---Medlemsfunktioner---

void temperatur::lasin()
{
  cout << "Ange grader: ";
  cin >> grader;
  cin.get(); // Läs förbi returntecknet.

  cout << "Ange typen: ";
  getline(cin, typ);
}

void temperatur::skriv()
{
  cout << "Temperaturen är " << grader << " grader "
       << typ << "." << endl;
}

double temperatur::haemta_grader()
{
  return grader;
}

string temperatur::haemta_typ()
{
  return typ;
}

double temperatur::skillnad(temperatur t)
{
  // Kolla att samma enheter mäts!
  if (typ == t.typ)
    return (grader - t.grader);
  else
  {
    cout << "Olika enheter!!!" << endl;
    return -99999;
  }
}

double temperatur::fahrenheit()
{
  if (typ == "Celsius") // Om Celsius, så konvertera.
    return (32 + 1.8 * grader);
  else
    return grader; // Annars, låt vara.
}

void temperatur::rapport(int nedre, int oevre)
{
  string s1 = "Oh! Vad varmt det är idag.";
  string s2 = "Oh! Vad kallt det är idag.";
  string s3 = "Det är lagom varmt idag.";

  if (grader < nedre)
    cout << s2;
  else if (grader < oevre)
    cout << s3;
  else
    cout << s1;

  cout << endl;
}

// som skriver ut (lagrar) ett objekt av klassen temperatur på en fil, dvs attributvärden skrivs ut.
void temperatur::skriv(ostream &ut)
{
  ut
      << grader << " "
      << typ << endl;
}
// ett objekt av klassen temperatur från en fil, dvs inläsning av attributvärden för ett objekt sker.
void temperatur::lasin(istream &in)
{
  in >> grader >> typ;
}

/* Körningsresultat:
Ange grader: 25
Ange typen: Celsius
Temperaturen är 28 grader Celsius.
Temperaturen är 25 grader Celsius.
Temperaturen är 35 grader Celsius.
Temperaturen är 100 grader Fahrenheit.
Oh! Vad varmt det är idag.
Oh! Vad varmt det är idag.
Default-objekt: 28 Celsius
28 grader Celsius motsvaras av 82.4 grader Fahrenheit.
Skillnaden mellan 25 och 35 = -10


Ange grader: 99
Ange typen: Fahrenheit
Temperaturen är 28 grader Celsius.
Temperaturen är 99 grader Fahrenheit.
Temperaturen är 35 grader Celsius.
Temperaturen är 100 grader Fahrenheit.
Oh! Vad varmt det är idag.
Oh! Vad varmt det är idag.
Default-objekt: 28 Celsius
28 grader Celsius motsvaras av 82.4 grader Fahrenheit.
Olika enheter!!!
Skillnaden mellan 99 och 35 = -99999
 */
