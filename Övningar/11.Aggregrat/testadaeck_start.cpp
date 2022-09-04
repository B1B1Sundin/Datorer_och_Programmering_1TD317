#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

// testabildaeck.cpp

//--- Klassen daeck representerar ett bildäck.---

const double MAXdjup = 20.00; // 20 mm

class daeck
{
private:
  double djup; // Mönsterdjup = antal mm gummi.

public:
  daeck();
  daeck(double indjup);
  double haemta_djup();
  int slitage(double slitdjup); // Slit på däcken
                                // om det går.
  void skriv();
};

int main()
{
  double mm;
  // Skapa några bildäck och testa lite:
  cout << "Testa lite med däcksklassen:" << endl;
  cout << "Däck 1 med mönsterdjup på default värde:" << endl;
  daeck daeck_1 = daeck();
  daeck_1.skriv();

  cout << "\n(Skriv in ett värde mellan 0.0 - 20.0)" << endl;
  cin >> mm;
  cout << "\nDäck 2 med mönsterdjup på " << mm << endl;
  daeck daeck_2 = daeck(mm);
  daeck_2.skriv();

  cout << "Däck 1 får ett slitage på 5.0 mm! " << endl;
  if (daeck_1.slitage(5.0) == 1)
  {
    cout << "Gummit är slut!" << endl;
  }
  cout << "Däck 1 får ett slitage på 3.7 mm! " << endl;
  if (daeck_2.slitage(3.7) == 1)
  {
    cout << "Gummit är slut!" << endl;
  }

  cout << "Däck 1: " << daeck_1.haemta_djup() << " mm" << endl;
  cout << "Däck 2: " << daeck_2.haemta_djup() << " mm" << endl;

  //------ Här skall C++-kod in!------

  return 0;
}

//---Implementation av däckmetoder.---

//---Konstruktorer:

daeck::daeck()
    : djup(MAXdjup)
{
}

daeck::daeck(double indjup)
    : djup(indjup)
{
}

//---Selektorer:

double daeck::haemta_djup()
{
  return djup;
}

//---Andra metoder:

int daeck::slitage(double slitdjup)
{
  // Slit ned "slitdjup" mycket av
  // gummit (om det går).
  // Returnera 1 om allt gummi slut,
  // annars 0.

  int slutgummi = 0;

  if (djup - slitdjup < 0)
  {
    djup = 0;
    slutgummi = 1;
  }
  else
    djup -= slitdjup;

  return slutgummi;
}

void daeck::skriv()
{
  cout.setf(ios::fixed);
  cout << " däck = " << setprecision(1) << djup << endl;
}
/* Körningsexempel:

Testa lite med däcksklassen:
 däck = 20.0 däck = 30.0
Nu sliter vi lite på dem...
 däck = 18.5 däck = 27.5

 */
