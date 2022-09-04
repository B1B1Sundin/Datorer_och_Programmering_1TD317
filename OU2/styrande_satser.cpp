#include <iostream>
using namespace std;

int main()
{
	int vinnande_tid = 864000; // MAX tiden, en dag i sekunder.
	int antal_tävlande = 0;
	int flag = true;
	int start_H, start_M, start_S, start_tid; // Start tider; input variabler och totala start tiden (s)
	int mål_H, mål_M, mål_S, mål_tid;					// Mål tider; input variabler och totala mål tiden (s)
	int tid, H, M, S;													// Generalla tider
	int vinnande_nummer, start_nummer;

	while (flag)
	{
		cout << "Startnummer? ";
		cin >> start_nummer;

		if (start_nummer > 0) // Checka om startnummret är tillåtet, alltså inte 0 eller negativt.
		{
			antal_tävlande++;

			cout << "Starttid? (HH:MM:SS) " << endl;
			cin >> start_H >> start_M >> start_S;
			start_tid = start_H * 60 * 60 + start_M * 60 + start_S; // Den totala starttiden i sekunder.

			cout << "Målttid? (HH:MM:SS) " << endl;
			cin >> mål_H >> mål_M >> mål_S;
			mål_tid = mål_H * 60 * 60 + mål_M * 60 + mål_S; // Den totala måltiden i sekunder.

			if (start_tid > mål_tid) // Gäller vid dygns skifte. ex. 23:59 - 00.00
			{
				mål_tid = mål_tid + 86400;
				tid = mål_tid - start_tid;
			}
			else
			{
				tid = mål_tid - start_tid;
			}

			if (tid < vinnande_tid) // Kolla om den nya tiden är lägre än den hittills kortaste tiden.
			{
				vinnande_tid = tid;
				vinnande_nummer = start_nummer;
			}
		}
		else // om start_nummer är mindre eller lika med 0.
		{
			flag = false;
		}
	}

	if (antal_tävlande > 0) // Kolla om det fanns några tävlande.
	{
		S = vinnande_tid; // konverta sekunder till timmar, minuter och sekunder.
		M = S / 60;
		H = M / 60;

		cout
				<< "Vinnare är startnr: " << vinnande_nummer << endl;
		cout << "Tim: " << int(H)
				 << " Min: " << int(M % 60)
				 << " Sek: " << int(S % 60) << endl;
		cout << "Antal tävlande: " << antal_tävlande << endl;
		cout << "Programmet avslutas" << endl;
	}
	else
	{
		cout << "Inga tävlande" << endl;
		cout << "Programmet avslutas" << endl;
	}
	return 0;
}
