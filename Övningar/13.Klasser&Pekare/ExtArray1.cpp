// ExtArray1.cpp, svarsfilen.
//
// Extensible array, dvs tänjbar array.
// Anm om kopieringskonstruktor/tilldelning:
//
// Tilldelningar: om arr1 = arr3. Då delar arr1 och arr3
// minne! Dvs om arr3 ändras, så ändras arr1!!!
// Det kan bli mycket fel!
// Okay tilldelning om egen tilldelningsoperator eller
// "assign"-funktion finns. Dvs
// void assign( ExtArray a );  + kopieringskonstruktor.
//

#include <iostream>
using namespace std;

const int blank = 0;

class ExtArray
{
private:
  int *array;
  int bufSize;

public:
  ExtArray();
  ExtArray(int siz, int val);
  ~ExtArray();
  ExtArray(const ExtArray &a); // kopieringskonstr.

  void change(int i, int num);
  int size();
  void resize(int n);
  void assign(const ExtArray &a); // &a ty ingen kopier.konst.
  void write();                   // skulle kunna vara "void write() const;" också.
  void addToEnd(int newItem);
  int last();
  int value(int index);

  //---Extrametoder---
  bool empty();

  void append(ExtArray other);
};
int sum(ExtArray &v);
void kvadrera(ExtArray &v);

int main()
{
  ExtArray arr1(5, -1); // 5 element, alla är -1.
  ExtArray arr2;        // 0 element.
  ExtArray arr3 = ExtArray(2, -99);
  ExtArray arr4(arr3);  // copy...varning
  ExtArray arr5 = arr2; // copy...varning

  cout << "arr1: ";
  arr1.write();
  cout << "arr2: ";
  arr2.write();
  cout << "arr3: ";
  arr3.write();
  cout << "arr4: ";
  arr4.write();
  cout << "arr5: ";
  arr5.write();

  cout << "Testar litegrand..." << endl;
  if (arr1.empty())
    cout << "Tom lista!" << endl;
  else
    cout << "Icketom lista med " << arr1.size() << " st element." << endl;

  arr1.append(arr3);
  arr3.append(arr1); // testar lite kors och tvärs...

  arr1.write();
  arr3.write();

  cout << "Sista elementet i arr3: " << arr3.last() << endl;
  cout << "Det femte elementet i arr1: " << arr1.value(5) << endl;

  cout << "Kvadrera" << endl;
  kvadrera(arr1);
  arr1.write();

  cout << "Summan" << endl;
  cout << "arr3: " << sum(arr3) << endl;
}

ExtArray::ExtArray()
    : bufSize(0)
{
  array = 0; // NULLpointer
  cout << "Hello default " << bufSize << endl;
}

ExtArray::ExtArray(int siz, int val)
    : bufSize(siz)
{
  if (bufSize > 0)
  {
    array = new int[bufSize];
    for (int i = 0; i < bufSize; i++)
      array[i] = val;
  }
  else
  {
    array = 0; // NULL-pekare
  }
  cout << "Hello överlagrad " << bufSize << endl;
}

ExtArray::ExtArray(const ExtArray &a)
    : bufSize(a.bufSize)
{
  cout << "Hello kopiering: ny längd: "
       << bufSize << endl;

  if (bufSize > 0)
  {
    array = new int[bufSize]; // Allokera nytt minne
    for (int i = 0; i < bufSize; i++)
      array[i] = a.array[i]; // Kopiera elementen
  }
  else
    array = 0; // NULL
}

ExtArray::~ExtArray()
{
  delete[] array;
}

void ExtArray::resize(int n)
{
  int *p = 0;

  if (n > 0) // Om ny storlek ej är noll
  {
    p = new int[n]; // Skapa array med n elem.

    int i;
    for (i = 0; i < n // Fyll med element.
                && i < bufSize;
         i++)
    {
      p[i] = array[i];
    }
    for (; i < n; i++) // Fyll resten med blanka .
      p[i] = blank;
  }

  delete[] array; // Avallokera minne.
  array = p;      // Sätt array till nya arrayen.
  bufSize = n;    // Sätt bufSize till nya storleken.
}

int ExtArray::size()
{
  return bufSize;
}

void ExtArray::write()
{
  cout << "Antal element är " << bufSize;
  if (bufSize > 0)
  {
    cout << ":";

    for (int i = 0; i < bufSize; i++)
      cout << '\t' << array[i];
  }
  else
    cout << ".";

  cout << endl;
}

void ExtArray::assign(const ExtArray &a)
{
  // Tilldela: aktuella objektet = a.

  bufSize = a.bufSize;
  cout << "Hello assign " << bufSize << endl;

  if (bufSize > 0)
  {
    delete[] array;           // Frigör minne.
    array = new int[bufSize]; // Allokera nytt minne.

    for (int i = 0; i < bufSize; i++)
    {
      array[i] = a.array[i]; // Kopiera elementen
    }
  }
  else
    array = 0; // NULL
}

void ExtArray::addToEnd(int newItem)
{
  // Öka på arrayen med ett element till.
  resize(bufSize + 1); // Fixar även bufSize++;

  // Tilldela nu sista elementet, dvs plats bufSize-1:
  array[bufSize - 1] = newItem;
}

void ExtArray::change(int i, int num)
{
  if (i < bufSize)
    array[i] = num;
}

bool ExtArray::empty()
{
  if (bufSize == 0)
    return true;
  return false;
}

void ExtArray::append(ExtArray other)
{
  int oldSize = bufSize;
  int newSize = bufSize + other.bufSize;

  resize(newSize); // Förläng lagom mycket.

  int other_i = 0;

  for (int i = oldSize; i < newSize; i++)
  {
    change(i, other.array[other_i]);
    other_i++;
  }
  // bufSize redan uppdaterad i "resize".
}

// returnerar värdet på sista index.
int ExtArray::last()
{
  return array[bufSize - 1];
}

// returnerar värdet på plats index i listan.
int ExtArray::value(int index)
{
  return array[index];
}

// beräknar och returnerar summan av elementen i listan.
// Här har vi referensparameter för att slippa anrop till kopieringskonstruktorer.
int sum(ExtArray &v)
{
  int sum = 0;
  for (int i = 0; i <= v.size(); i++)
  {
    sum += v.value(i);
  }
  return sum;
}

// ändrar i listan så att varje element kvadreras.
void kvadrera(ExtArray &v)
{
  for (int i = 0; i <= v.size(); i++)
  {
    int tal = v.value(i);
    v.change(i, tal * tal);
  }
}
/*
Hello överlagrad 5
Hello default 0
Hello överlagrad 2
Hello kopiering: ny längd: 2
Hello kopiering: ny längd: 0
arr1: Antal element är 5:       -1      -1      -1      -1      -1
arr2: Antal element är 0.
arr3: Antal element är 2:       -99     -99
arr4: Antal element är 2:       -99     -99
arr5: Antal element är 0.
Testar litegrand...
Icketom lista med 5 st element.
Hello kopiering: ny längd: 2
Hello kopiering: ny längd: 7
Antal element är 7:     -1      -1      -1      -1      -1      -99     -99
Antal element är 9:     -99     -99     -1      -1      -1      -1      -1      -99     -99

 */
