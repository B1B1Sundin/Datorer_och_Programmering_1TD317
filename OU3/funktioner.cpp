#include <iostream>
using namespace std;

// Deklarationer av funktionerna
void skrivInfo();
int lasEttTal();
char lasOp();
void ordna(int &a, int &b);
int berakna(int a, int b, char op);
void skrivResultat(int res);

int main()
{
	int tal1, tal2, svar;
	char op;

	skrivInfo();

	tal1 = lasEttTal();
	tal2 = lasEttTal();

	op = lasOp();

	ordna(tal1, tal2);

	svar = berakna(tal1, tal2, op);

	skrivResultat(svar);

	return 0;
}

// Definitioner av funktionerna

/**
 * @brief Funktionen skriver ut en text som kort förklarar vad programmet gör.
 */
void skrivInfo()
{
	cout << "Välkommen! Programmet kommer att läsa in två tal(int). \nBeroende din valda beräkning (a, m eller k), så kommer alla tal fr o m det minsta t o m det största av dem summeras, multipliceras eller kvadratsummeras.\n " << endl;
	cout << " - För a & b och operand 'a' -> a + (a+1) + (a+2) ... + b" << endl;
	cout << " - För a & b och operand 'm' -> a * (a+1) * (a+2) ... * b" << endl;
	cout << " - För a & b och operand 'k' -> a*a + (a+1)*(a+1) + (a+2)*(a+2) +  ... + b*b\n"
			 << endl;
}

/**
 * @brief Funktionen ska skriva ut en ledtext och läsa in och returnera ett (1) heltal.
 * Ledtext skrivs ut så att användaren vet vad som ska matas in.
 *
 * @return int Input värdet
 */
int lasEttTal()
{
	int tal;
	cout << "Skriv in ett tal (int): "; // ledtext
	cin >> tal;
	return tal;
}

/**
 * @brief Funktionen läser in och returnerar ett tecken som representerar den valda beräkningen (tecknet a, m eller k).
 *  Ledtext skrivs ut så att användaren vet vad som ska matas in.
 *
 * @return char Den valda operanden.
 */
char lasOp()
{
	char op;
	cout << "\na - Addera tal\nm - Multiplicera tal\nk - Beräkna kvadratsumman av tal\n"
			 << "\nSkriv in någon av dessa operander (char): ";

	cin >> op;
	while (!(op == 'a' || op == 'k' || op == 'm'))
	{
		cin >> op;
	}
	return op;
}

/**
 * @brief Funktionen ska sortera de två inlästa talen i storleksordning. Funktionen har 2 referensparametrar.
 * Endast nödvändigt ifall if a > b.
 *
 * @param a MIN värde
 * @param b MAX värde
 */
void ordna(int &a, int &b)
{
	int c;

	if (a > b)
	{
		c = a;
		a = b;
		b = c;
	}
}

/**
 * @brief Funktionen returnerar resultatet av den valda beräkningen.
 *
 * @param a Den undre gränsen.
 * @param b Den övre gränsen.
 * @param op Den valda operanden eller beräkning.
 * @return int resultatet av beräkningen.
 */
int berakna(int a, int b, char op)
{
	int i, sum;

	switch (op)
	{
	case 'a':
		if (a == b)
		{
			return a;
		}
		else
		{
			sum = 0;
			for (i = a; i <= b; i++)
			{
				sum += i;
			}
			return sum;
		}
		break;

	case 'm':
		if (a == b)
		{
			return a;
		}
		else if (a < 1)
		{
			return 0;
		}
		else
		{
			sum = 1;
			for (i = a; i <= b; i++)
			{
				sum = sum * i;
			}
			return sum;
		}
		break;
	case 'k':
		sum = 0;
		if (a == b)
		{
			cout << "hiphopp1" << endl;
			return a * b;
		}
		else
		{

			for (i = a; i <= b; i++)
			{
				sum = sum + i * i;
			}
			return sum;
		}
		break;
	}

	return 0;
}

/**
 * @brief Funktionen ska skriva ut resultatet av beräkningen.
 *
 * @param res resulatet av beräkningen.
 */
void skrivResultat(int res)
{
	cout << "Resultat: " << res << endl;
}
