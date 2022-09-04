// ExtArray0.cpp
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
  void write();
  void addToEnd(int newItem);
  bool empty();
  void append(ExtArray other);
};

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

  cout << "test test" << endl;

  cout << "Resize arr2 with 5" << endl;
  cout << "arr2: ";
  arr2.resize(5);
  arr2.write();

  cout << "\nAdd 5 to the end of arr5 and arr4" << endl;
  cout << "arr5: ";
  arr5.addToEnd(6);
  arr5.write();
  cout << "arr4: ";
  arr4.addToEnd(6);
  arr4.write();

  cout << "\nAssign contents of arr1 to arr3" << endl;
  arr3.assign(arr1);

  cout << "arr1: ";
  arr1.write();
  cout << "arr3: ";
  arr3.write();

  cout << "\nAppend contents of arr1 to arr4" << endl;
  arr4.append(arr1);
  cout << "arr1: ";
  arr1.write();
  cout << "arr4: ";
  arr4.write();

  return 0;
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

// returnerar true om listan är tom, annars returneras false.
bool ExtArray::empty()
{
  if (bufSize == 0)
  {
    return true;
  }
  return false;
}

// Tar listan other och lägger in direkt efter sista elementet i aktuella listan.
void ExtArray::append(ExtArray other)
{
  int old_size = bufSize;
  int new_size = bufSize + other.bufSize;

  resize(new_size);
  int other_size = 0;
  for (int i = old_size; i < new_size; i++)
  {
    change(i, other.array[other_size]);
    other_size++;
  }
  cout << endl;
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

*/
