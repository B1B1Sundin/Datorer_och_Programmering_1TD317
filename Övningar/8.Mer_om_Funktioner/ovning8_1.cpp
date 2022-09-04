#include <iostream>
using namespace std;

const int MAX = 10;

double summa(double array[], int n, int low = 0, int hi = MAX);

int main()
{
  double a[MAX] = {1.1, 3.1, 2.1, 5.4, 1.3,
                   17.0, 1.4, 1.2, 1.1, 1.7};

  cout << "Här är alla arrayelement:" << endl;

  for (int i = 0; i < MAX; i++)
    cout << a[i] << " ";

  cout << endl;

  cout << "Summa av alla arrayelement: "
       << summa(a, MAX) << endl;
  cout << "Summa från index = 2 t.o.m 4: "
       << summa(a, MAX, 2, 4) << endl;
  return 0;
}

double summa(double array[], int n, int low, int hi)
{
  double sum = 0;
  for (int i = low; i < hi + 1; i++)
  {
    sum += array[i];
  }
  return sum;
}

/**
 *

 *
 */