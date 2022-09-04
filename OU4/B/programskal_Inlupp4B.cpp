//
// Programskal till inl�mningsuppgift 4 - deluppgift B
//
// Hanterar fallet med 26 bokst�ver A-Z

#include <string>
#include <cctype>
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

// Globala konstanter:

const int ANTAL_BOKSTAVER = 26; // A-Z
const int ANTAL_SPRAK = 4;

// 2d-arrayen TOLK_HJALP innehåller bokstavsfrekvensen i %
// för fyra språk. TOLK_HJALP[0][0] är frekvensen av
// bokstaven a för engelska. TOLK_HJALP[0][25] är frekvensen av
// bokstaven z för engelska.

const double TOLK_HJALP[ANTAL_SPRAK][ANTAL_BOKSTAVER] =
    {{8.27, 1.48, 2.94, 4.03, 11.78, 2.22, 1.72, 6.77, // engelska
      7.39, 0.12, 0.81, 3.76, 2.85, 6.71, 7.79, 1.54,
      0.05, 5.95, 6.69, 9.07, 2.66, 1.13, 2.14, 0.19,
      1.89, 0.03},
     {7.97, 1.40, 3.55, 3.79, 16.89, 1.02, 1.00, 0.75, // franska
      7.08, 0.38, 0.04, 5.51, 2.82, 8.11, 5.19, 2.78,
      1.01, 6.69, 8.35, 7.22, 6.09, 1.35, 0.02, 0.54,
      0.30, 0.15},
     {9.50, 1.11, 1.53, 5.30, 8.94, 1.74, 3.57, 3.94, // svenska
      3.98, 0.89, 3.26, 4.93, 3.41, 8.46, 5.01, 1.77,
      0.00, 6.73, 5.56, 9.20, 1.94, 2.42, 0.00, 0.05,
      0.45, 0.00},
     {5.12, 1.95, 3.57, 5.07, 16.87, 1.35, 3.00, 5.79, // tyska
      8.63, 0.19, 1.14, 3.68, 3.12, 10.64, 1.74, 0.42,
      0.01, 6.30, 6.99, 5.19, 3.92, 0.77, 1.79, 0.01,
      0.69, 1.24}};

//--------------------------------------------------------
// Funktionsdeklarationer:
string namn_pa_fil();
string inlasning(string fil_namn);
void berakna_histogram_abs(string text, int alfabet[ANTAL_BOKSTAVER]);
void abs_till_rel(int alfabet[], double alfabet_rel[]);

void plotta_histogram_rel(double alfabet[]);

void tolkning(double alfabet[]);

//--------------------------------------------------------
// Huvudprogram:

int main()
{
  // "skall innehålla anrop av de fem funktionerna (men naturligtvis får det finnas någon if-sats och return 0; i huvudprogrammet)."
  int alfa[ANTAL_BOKSTAVER];
  double alfa_rel[ANTAL_BOKSTAVER];

  char letter;
  string fil_namn = namn_pa_fil();
  string text = inlasning(fil_namn);
  berakna_histogram_abs(text, alfa);
  abs_till_rel(alfa, alfa_rel);
  tolkning(alfa_rel);
  plotta_histogram_rel(alfa_rel);
  return 0;
}

//--------------------------------------------------------
// Funktionsdefinitioner:

/**
 * @brief Kolla om filen är tillåten (innehåller ändelsen '.txt' eller bara är 'doyle', 'lagerlof').
 * Om filen inte är tillåten så skickas "failed" tillbaka.
 *
 * @return string Namnet på filen.
 */
string namn_pa_fil()
{
  string fil_namn;
  string nyckel = ".txt";
  string sv = "lagerlof";
  string eng = "doyle";

  cout << "Ge filnamn: ";
  getline(cin, fil_namn);

  if (fil_namn.rfind(nyckel) != string::npos)
  {
    return fil_namn;
  }
  else if (fil_namn.rfind(sv) != string::npos)
  {
    sv.append(nyckel);
    return sv;
  }
  else if (fil_namn.rfind(eng) != string::npos)
  {
    eng.append(nyckel);
    return eng;
  }
  else
  {
    return "failed";
  }
}

/**
 * @brief Funktionen läser in en fil med fil_namn och sparar texten i filen i en sträng.
 *
 * @param fil_namn Namnet på filen returnerad från namn_pa_fil().
 * @return string Innehållet i filen skriven till en sträng.
 */
string inlasning(string fil_namn)
{
  string text;

  ifstream fil(fil_namn.c_str());

  if (!fil.good() || fil_namn == "failed")
  {
    cout << "Det finns ingen fil med namnet " << fil_namn << endl;
    exit(EXIT_FAILURE);
  }

  char c;

  fil.get(c);
  text.push_back(c);

  while (!fil.eof())
  {
    fil.get(c);
    text.push_back(c);
  }
  fil.close();
  return text;
}

/**
 * @brief Funktionen skall gå igenom en sträng och beräkna ett histogram med förekomsten av varje bokstav.
 *
 * @param text Strängen med text som funktionen ska gå igenom.
 * @param alfabet En (int) array som representerar frekvensen av bokstäverna.
 */
void berakna_histogram_abs(string text, int alfabet[ANTAL_BOKSTAVER])
{
  int counter = 0;
  int index;

  // nollställ array
  for (int i = 0; i < 26; i++)
  {
    alfabet[i] = 0;
  }

  // räkna frekvens
  for (int i = 0; i < text.length(); i++)
  {
    if (isalpha(text.at(i)))
    {
      if (text.at(i) >= 'a' && text.at(i) <= 'z')
      {
        index = text.at(i) - 'a';

        alfabet[index]++;
      }
      else if (text.at(i) >= 'A' && text.at(i) <= 'Z')
      {
        index = text.at(i) - 'A';

        alfabet[index]++;
      }
    }
  }

  // räkna ut antal bokstäver
  for (int i = 0; i < ANTAL_BOKSTAVER; i++)
  {
    if (alfabet[i] > 0)
    {
      counter += alfabet[i];
    }
  }
  cout << "\nResultat för bokstäverna A - Z " << endl;
  cout << "\nTotala antalet bokstäver: " << counter << endl;
}

/**
 * @brief Ett histogram kan också representeras i relativa frekvenser, d v s hur stor andel av texten som utgörs av en specifik bokstav.
 * Arrayen innehåller då värden mellan 0.0 och 100.0% för varje bokstav, där den totala summan för alla bokstäver är 100.0%.
 * Funktionen ska ta ett histogram med absoluta värden och räkna om dessa till relativa värden.
 *
 * @param alfabet Array med frekvensen av bokstäverna (absoluta värden, int)
 * @param alfabet_rel Array med frekvensen av bokstäverna (relativa värden, double)
 */
void abs_till_rel(int alfabet[], double alfabet_rel[])
{
  double sum = 0;

  for (int i = 0; i < ANTAL_BOKSTAVER; i++)
  {
    sum += alfabet[i];
  }

  for (int i = 0; i < ANTAL_BOKSTAVER; i++)
  {
    alfabet_rel[i] = (double)(alfabet[i] / sum) * 100.0;
  }
}

/**
 * @brief Funktionen skall jämföra ett beräknat histogram med fyra fördefinierade språks histogram.
 * Funktionen ska sedan bestämma vilket språk den ursprungliga texten troligtvis är skriven på.
 *
 * @param alfabet
 */
void tolkning(double alfabet[])
{
  double skillnad = 0;
  double sum = 0;
  double sums[4] = {0.0, 0.0, 0.0, 0.0};
  string sprak[4] = {"engelska", "franska", "svenska", "tyska"};
  int index;
  double min;

  for (int i = 0; i < ANTAL_SPRAK; i++)
  {

    for (int j = 0; j < ANTAL_BOKSTAVER; j++)
    {
      skillnad = TOLK_HJALP[i][j] - alfabet[j];
      if (i == 0)
      {
        sums[i] += (skillnad * skillnad);
      }
      else if (i == 1)
      {
        sums[i] += (skillnad * skillnad);
      }
      else if (i == 2)
      {
        sums[i] += (skillnad * skillnad);
      }
      else
      {
        sums[i] += (skillnad * skillnad);
      }
    }
    skillnad = 0;
  }

  min = sums[0]; // Anta att första elementet är lägst först.
  index = 0;
  for (int i = 1; i < ANTAL_SPRAK; i++)
  {
    if (min > sums[i])
    {
      min = sums[i];
      index = i;
    }
  }

  cout << "Engelska har kvadratsumman = " << sums[0] << endl;
  cout << "Franska har kvadratsumman = " << sums[1] << endl;
  cout << "Svenska har kvadratsumman = " << sums[2] << endl;
  cout << "Tyska har kvadratsumman = " << sums[3] << endl;
  cout << "Det är mest troligt att språket är " << sprak[index] << ".\n"
       << endl;
}

/**
 * @brief Funktionen ritar ut ett bokstavshistogram (bokstav och förekomsten av denna bokstav i form av '*').
 * En procent ska motsvaras av två symboler. Den här funktionen använder trunc().
 *
 * @param alfabet
 */
void plotta_histogram_rel(double alfabet[])
{
  double temp;
  char letter;
  int counter = 0;

  cout << "Bokstavsfördelning:\n"
       << endl;

  for (int i = 0; i < ANTAL_BOKSTAVER; i++)
  {
    letter = char(i + 'A');
    temp = trunc(alfabet[i] * 2);
    cout << letter << " ";

    while (counter != temp)
    {
      cout << "*";
      counter++;
    }

    cout << endl;
    counter = 0;
  }
}

// -------------------------------------------------------
// Rapport om uppgiften
/**
 *
 *
 */
