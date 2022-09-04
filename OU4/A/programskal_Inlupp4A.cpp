//
// Programskal till inlämningsuppgift 4 - deluppgift A
//
// Hanterar fallet med 26 bokstäver A-Z

#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;

// Globala värden
const int ANTAL_BOKSTAVER = 26; // A-Z

//--------------------------------------------------------
// Funktionsdeklarationer:
void berakna_histogram_abs(string text, int alfabet[ANTAL_BOKSTAVER]);
void skriv_histogram_abs(int alfabet[]);
//--------------------------------------------------------

// Huvudprogram:
int main()
{
  // Deklarera variabler
  string text_rad;
  int alf[ANTAL_BOKSTAVER];

  // Läs in en rad med text fr�n tangentbordet
  cout << "Ge en rad med text: " << endl;
  getline(cin, text_rad);

  // Anropa funktionen berakna_histogram_abs som beräknar histogrammet och antalet bokstäver.

  berakna_histogram_abs(text_rad, alf);

  // Anropa funktion som skriver ut histogrammet
  skriv_histogram_abs(alf);

  return 0;
}

//--------------------------------------------------------
// Funktionsdefinitioner:

/**
 * @brief Funktionen skall gå igenom en sträng och beräkna ett histogram med förekomsten av varje bokstav.
 *
 * @param text Strängen med bokstäver
 * @param alfabet En (int) array som håller värdena för bokstavsfrekvenserna.
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
 * @brief Funktionen skall skriva ut ett förenklat bokstavshistogram som en tabell med två kolumner: bokstav och bokstavens förekomst som ett heltal.
 *
 * @param alfabet Bokstavsfrekvenserna.
 */
void skriv_histogram_abs(int alfabet[])
{
  char letter;
  cout
      << "Bokstavsfördelning:\n"
      << endl;
  for (int i = 0; i < ANTAL_BOKSTAVER; i++)
  {
    letter = char(i + 'A');
    cout << letter << ": " << alfabet[i] << endl;
  }
}

/**
 * Redovisning av uppgiften i ord.
 * berakna_histogram_abs() kollar en char i taget i en loop som går igenom hela text strängen.
 * Om en char är fyller kraven i if-kraven (a-z eller A-Z) så går programmet in i if-satsen,
 * och inkrementerar frekvensen för den bokstaven i en array. Så om en char är 'A', så har 'A' indexet 0 i arrayen.
 * Ifall en char är 'B' så blir indexet 'B' - 'A' (66 -65 i ASCII) = 1. Genom att skilja dem åt med stora och små bokstäver,
 * så kan jag subtrahera med rätt värde ('A' = 65, 'a' = 97) så att indexeringen blir rätt.
 *
 *
 */
