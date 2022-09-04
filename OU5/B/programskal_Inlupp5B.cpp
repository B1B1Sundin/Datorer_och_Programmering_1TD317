//
// Programskal till Inlupp5A
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

// Globala variabler är ej tillåtna

//--------------------------------------------------------
// klassdeklaration:
class Text
{
private:
  string text;
  int histo[ANTAL_BOKSTAVER];
  double rel_histo[ANTAL_BOKSTAVER];
  int antal_bokstaver;

public:
  Text();                             // Standardkonstruktor
  void setText(const string &nyText); // En metod som sätter värdet på textsträngen i klassen
  bool beraknaHistogramAbs();         // En metod som beräknar histogrammet av texten. Metoden ska också beräkna antalet bokstäver i histogrammet.
  void skrivHistogramAbs();           // En metod som skriver ut ett bokstavshistogram som en tabell med två kolumner:
  string tolka();
  void beraknaHistogram();
  void absTillRel();
  void plottaHistogram();
};
// -------------------------------------------------------
// Funktionsdefinintioner:

string inlasning(string fil_namn);
string namn_pa_fil();

// -------------------------------------------------------

// Huvudprogram:

int main()
{

  string text;
  Text minText; // Ett objekt av typen Text skapas

  text = inlasning(namn_pa_fil());

  // Skicka strängen text till objektet minText
  minText.setText(text);

  // Ber�kna och skriv ut histogrammet
  minText.beraknaHistogram();
  minText.skrivHistogramAbs();    // kallar på beraknaHistogramAbs() och absTillRel().
  minText.plottaHistogram();      // skriver ut *.
  string sprak = minText.tolka(); // löser ut vilket språk det är.
  cout << "Det är mest troligt att språket är " << sprak << ".\n"
       << endl;

  return 0;
}
// -------------------------------------------------------
// Klassimplementationen

// Standardkonstruktor
Text::Text()
{
  text = "";
  antal_bokstaver = 0;
  for (int i = 0; i < ANTAL_BOKSTAVER; i++)
  {
    histo[i] = 0;
  }
}

/**
 * @brief En metod som sätter värdet på textsträngen i klassen
 *
 * @param nyText sträng
 */
void Text::setText(const string &nyText)
{
  text = nyText;
}

/**
 * @brief En metod som beräknar histogrammet av texten.
 * Metoden ska också beräkna antalet bokstäver i histogrammet.
 *
 * @return true Om det finns bokstäver i histogrammet.
 * @return false Om det inte finns bokstäver i histogrammet.
 */
bool Text::beraknaHistogramAbs()
{
  int index;

  for (int i = 0; i < text.length(); i++)
  {
    if (isalpha(text.at(i)))
    {
      if (text.at(i) >= 'a' && text.at(i) <= 'z')
      {
        index = text.at(i) - 'a';

        histo[index]++;
      }
      else if (text.at(i) >= 'A' && text.at(i) <= 'Z')
      {
        index = text.at(i) - 'A';

        histo[index]++;
      }
    }
  }
  for (int i = 0; i < ANTAL_BOKSTAVER; i++)
  {
    if (histo[i] > 0)
    {
      antal_bokstaver += histo[i];
    }
  }
  if (antal_bokstaver > 0)
  {
    return true;
  }
  return false;
}

/**
 * @brief En metod som skriver ut ett bokstavshistogram som en tabell med två kolumner:
 * bokstav och bokstavens förekomst som ett heltal.
 *
 */
void Text::skrivHistogramAbs()
{
  char letter;

  cout << "Resultat för bokstäverna A-Z\n"
       << "Totala antalet bokstäver: " << antal_bokstaver << "\n\nBokstavsfördelning:\n"
       << endl;
  for (int i = 0; i < ANTAL_BOKSTAVER; i++)
  {
    letter = char(i + 'A');
    cout << letter << ": " << histo[i] << endl;
  }
}

/**
 * @brief En metod som beräknar det relativa histogrammet från det absoluta.
 * För varje bokstav anges förekomsten relativt totala antalet bokstäver i histogrammet.
 *
 */
void Text::absTillRel()
{
  double sum = 0;

  for (int i = 0; i < ANTAL_BOKSTAVER; i++)
  {
    sum += histo[i];
  }

  for (int i = 0; i < ANTAL_BOKSTAVER; i++)
  {
    rel_histo[i] = (double)(histo[i] / sum) * 100.0;
  }
}

/**
 * @brief En metod som plottar det relativ histogrammet på samma sätt som i Inlämningsuppgift 4, med symboler.
 * En procent ska motsvaras av två symboler.
 *
 */
void Text::plottaHistogram()
{
  double temp;
  char letter;
  int counter = 0;

  cout << "\nBokstavsfördelning:\n"
       << endl;

  for (int i = 0; i < ANTAL_BOKSTAVER; i++)
  {
    letter = char(i + 'A');
    temp = trunc(rel_histo[i] * 2);
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

/**
 * @brief Anropar funktionerna beraknaHistogramAbs samt absTillRel.
  Det absoluta histogrammet beräknas först i funktionen och sedan det relativa.
  Det relativa histogrammet ska endast beräknas om det finns bokstäver i det absoluta histogrammet.
 *
 */
void Text::beraknaHistogram()
{
  if (beraknaHistogramAbs())
  {
    absTillRel();
  }
}

/**
 * @brief En metod för att jämföra ett beräknat relativt histogram med fyra fördefinierade språkhistogram samt bestämma vilket språk den ursprungliga texten mest troligt är skriven på.
 * Metoden ska returnera resultatet, t ex svenska, som en string.
 *
 * @return string
 */
string Text::tolka()
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
      skillnad = TOLK_HJALP[i][j] - rel_histo[j];
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
  cout << "\nEngelska har kvadratsumman = " << sums[0] << endl;
  cout << "Franska har kvadratsumman = " << sums[1] << endl;
  cout << "Svenska har kvadratsumman = " << sums[2] << endl;
  cout << "Tyska har kvadratsumman = " << sums[3] << endl;

  return sprak[index];
}

//--------------------------------------------------------
// Funktionsdefinitioner:

/**
 * @brief Kolla om filen är tillåten
 * Om filen inte är tillåten så skickas "failed" tillbaka.
 *
 * @return string Namnet på filen.
 */
string namn_pa_fil()
{
  string fil_namn;
  string nyckel = ".txt";

  cout << "Ge filnamn: " << endl;
  getline(cin, fil_namn);

  // Kollar om den slutar på .txt. Om så, kolla om filen finns i mappen.
  if (fil_namn.rfind(nyckel) != string::npos)
  {
    ifstream ifile;
    ifile.open(fil_namn);

    if (ifile)
    {
      ifile.close();
      return fil_namn;
    }
    ifile.close();
    return "failed";
  }
  else
  {
    fil_namn += string(".txt");
    // checka ifall filen finns med .txt tillagd på slutet.
    ifstream ifile;
    ifile.open(fil_namn);

    if (ifile)
    {
      ifile.close();
      return fil_namn;
    }
    ifile.close();
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
// -------------------------------------------------------
// Rapport om uppgiften
