#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

// Jag använder mig av följande kompilator:
// Apple clang version 12.0.5 (clang-1205.0.22.11)
// Target: arm64-apple-darwin20.4.0
// Thread model: posix

class Person
{
private:
	string namn;
	double betalat_andras;
	double skyldig;

public:
	Person();
	~Person();
	Person(const string &n, double b_a, double s);
	Person &operator=(const Person &p);
	string hamtaNamn();
	double hamtaBetalat();
	double hamtaSkyldig();
	void skrivUt(ostream &os);
};

// ###################################################################################################################################################
// Syftet med denna klass är att hålla ordning på unika personer som är med i sammanhanget (t ex vår resa), dvs inklusive deras namn och transaktionsdata.
// Viktigaste metoden är skritUtOchFixa, som talar om vilka som skall ge till potten och vilka som skall ta från potten.
// Denna metod anropar utskriftsmetoden i Person-klassen.

class PersonLista
{
private:
	int antal_personer;
	Person *personer;

public:
	PersonLista();
	~PersonLista();
	void laggTill(Person ny_person);
	void skrivUtOchFixa(ostream &os);
	double summaSkyldig() const;
	double summaBetalat() const;
	bool finnsPerson(const string &namn);
};

// ###################################################################################################################################################
// Syftet med klassen är att den skall kunna lagra värden som hör ihop med ett enda kvitto (s k transaktion).
// Den kommer att användas av klassen TransaktionsLista.

class Transaktion
{
private:
	string datum;
	string typ;
	string namn;
	double belopp;
	int antal_kompisar;
	string *kompisar;

public:
	Transaktion();
	~Transaktion();
	Transaktion &operator=(const Transaktion &t);
	string hamtaNamn() const;
	double hamtaBelopp() const;
	int hamtaAntalKompisar() const;
	bool finnsKompis(const string &namnet) const;
	bool lasIn(istream &is);
	void skrivUt(ostream &os) const;
	void skrivTitel(ostream &os) const;
};

// ###################################################################################################################################################
// Syftet med denna klass är att den skall lagra data om många kvitton (transaktioner).
// t ex läsa många kvitton från en fil, kunna göra vissa operationer på data i dessa,
// t ex sammanställa totalkostnaden för resan och skapa en s k personlista, dvs lista av personer som varit med på resan (samt ekonomiska data för dessa).

class TransaktionsLista
{
private:
	int antal_transaktioner;
	Transaktion *transaktioner;

public:
	TransaktionsLista();
	~TransaktionsLista();
	void lasIn(istream &is);
	void skrivUt(ostream &os);
	void laggTill(Transaktion &t);
	double totalKostnad() const;
	double liggerUteMed(const string &namnet);
	double arSkyldig(const string &namnet);
	PersonLista fixaPersoner();
};

// ###################################################################################################################################################

int main()
{
	cout << "Startar med att läsa från en fil." << endl;
	TransaktionsLista transaktioner;

	ifstream is("resa.txt");

	transaktioner.lasIn(is);

	int operation = 1;
	while (operation != 0)
	{
		cout << endl;
		cout << "Välj i menyn nedan:" << endl;
		cout << "0. Avsluta. Alla transaktioner sparas på fil." << endl;
		cout << "1. Skriv ut information om alla transaktioner." << endl;
		cout << "2. Läs in en transaktion från tangentbordet." << endl;
		cout << "3. Beräkna totala kostnaden." << endl;
		cout << "4. Hur mycket är en viss person skyldig?" << endl;
		cout << "5. Hur mycket ligger en viss person ute med?" << endl;
		cout << "6. Lista alla personer mm och FIXA" << endl;

		cin >> operation;
		cout << endl;

		switch (operation)
		{
		case 1:
		{
			transaktioner.skrivUt(cout);
			break;
		}
		case 2:
		{
			Transaktion transaktion;
			cout << "Ange transaktion i följande format" << endl;
			transaktion.skrivTitel(cout);
			transaktion.lasIn(cin);
			transaktioner.laggTill(transaktion);
			break;
		}
		case 3:
		{
			cout << "Den totala kostnanden för resan var "
					 << transaktioner.totalKostnad() << endl;
			break;
		}
		case 4:
		{
			cout << "Ange personen: ";
			string namn;
			cin >> namn;
			double ar_skyldig = transaktioner.arSkyldig(namn);
			if (ar_skyldig == 0.)
				cout << "Kan inte hitta personen " << namn << endl;
			else
				cout << namn << " är skyldig " << ar_skyldig << endl;
			break;
		}
		case 5:
		{
			cout << "Ange personen: ";
			string namn;
			cin >> namn;
			double ligger_ute_med = transaktioner.liggerUteMed(namn);
			if (ligger_ute_med == 0.)
				cout << "Kan inte hitta personen " << namn << endl;
			else
				cout << namn << " ligger ute med " << ligger_ute_med << endl;
			break;
		}

		case 6:
		{
			cout << "Nu skapar vi en personarray och reder ut det hela!" << endl;
			PersonLista lista = transaktioner.fixaPersoner();
			lista.skrivUtOchFixa(cout);
			break;
		}
		}
	}

	std::ofstream os("transaktioner.txt");
	transaktioner.skrivUt(os);

	return 0;
}

//###############################################################################
// Klassen Person

// Konstruktor
Person::Person()
{
	namn = "";
	betalat_andras = 0.0;
	skyldig = 0.0;
}

// Kosntruktor med givna parametrar
Person::Person(const string &n, double b_a, double s)
{
	namn = n;
	betalat_andras = b_a;
	skyldig = s;
}

// Destruktor
Person::~Person()
{
}

Person &Person::operator=(const Person &p)
{
	if (this != &p)
	{
		skyldig = p.skyldig;
		betalat_andras = p.betalat_andras;
		namn = p.namn;
	}
	return *this;
}

// selektor, returnerar attributvärdet namnn
string Person::hamtaNamn()
{
	return namn;
}
// selektor, returnerar attributvärdet betalat_andras
double Person::hamtaBetalat()
{
	return betalat_andras;
}
// selektor, returnerar attributvärdet skyldig
//
double Person::hamtaSkyldig()
{
	return skyldig;
}

/**
 * @brief  Skriver ut personens namn och hur mycket personen ligger ute med.
 * Samt är skyldig och vad han/hon skall betala till, eller ta ifrån potten (dvs attributen).
 *
 * @param os output till skärmen
 */
void Person::skrivUt(ostream &os)
{
	os << namn << " ligger ute med " << betalat_andras << " och är skyldig " << skyldig;
	if (betalat_andras > skyldig)
	{
		os << ". Skall ha " << betalat_andras - skyldig << " från potten!" << endl;
	}
	else if (skyldig > betalat_andras)
	{
		os << ". Skall lägga " << skyldig - betalat_andras << " till potten!" << endl;
	}
	else
	{
		os << ". Det går jämnt ut!" << endl;
	}
}

//####################################################################################################################################
// Klassen PersonLista

// Konstruktor
PersonLista::PersonLista()
{
	antal_personer = 0;
}

// Destruktor
PersonLista::~PersonLista()
{
	delete[] personer;
}

/**
 * @brief tar ett personobjekt som inparameter, ny_person, och lägger till på slutet i den dynamiska arrayen personer.
 * allokera en ny dynamisk array vid varje anrop av denna metod som innehåller en till person, kopiera över personer från den gamla arrayen, samt ta bort den gamla dynamiska pekaren.
 *
 * @param ny_person av class Person
 */
void PersonLista::laggTill(Person ny_person)
{
	Person *pers = NULL;
	pers = new Person[antal_personer + 1];

	for (int i = 0; i < antal_personer; i++)
	{
		pers[i] = personer[i];
	}
	pers[antal_personer] = ny_person; // skriv in det nya och sista elementet manuellt
	antal_personer++;

	personer = pers;
}

/**
 * @brief skriver ut information om varje personobjekt i arrayen personer.
 * Samt kollar att det belopp som personer lägger till potten är lika med det belopp som andra personer tar från potten.
 *
 * @param os skriver till skärmen som output
 */
void PersonLista::skrivUtOchFixa(ostream &os)
{
	for (int i = 0; i < antal_personer; i++)
	{
		os << personer[i].hamtaNamn() << " ligger ute med " << personer[i].hamtaBetalat() << " och är skyldig " << personer[i].hamtaSkyldig() << ".";
		if (personer[i].hamtaBetalat() > personer[i].hamtaSkyldig())
		{
			os << " Skall ha " << personer[i].hamtaBetalat() - personer[i].hamtaSkyldig() << " från potten!" << endl;
		}
		else if (personer[i].hamtaSkyldig() > personer[i].hamtaBetalat())
		{
			os << " Skall lägga " << personer[i].hamtaSkyldig() - personer[i].hamtaBetalat() << " till potten!" << endl;
		}
		else
		{
			os << " Det går jämnt ut! " << endl;
		}
	}
	os << endl;
}

/**
 * @brief används för kontrollen i utskriftsmetoden, dvs summan av alla skulder.
 *
 * @return double den totala skulden hos alla kompisar
 */
double PersonLista::summaSkyldig() const
{
	double totala_skuld = 0.0;
	for (int i = 0; i < antal_personer; i++)
	{
		totala_skuld += personer[i].hamtaSkyldig();
	}
	return totala_skuld;
}

/**
 * @brief används för kontrollen i utskriftsmetoden, dvs summan av alla utlägg.
 *
 * @return double den totala summan av utlägg hos alla kompisar
 */
double PersonLista::summaBetalat() const
{
	double totala_utlägg = 0.0;
	for (int i = 0; i < antal_personer; i++)
	{
		totala_utlägg += personer[i].hamtaBetalat();
	}
	return totala_utlägg;
}

/**
 * @brief Kollar om ifall @param namn finns bland listan av personer.
 *
 * @param namn
 * @return true, om namn finns bland personer i lista
 * @return false, om namn inte finns bland personer i lista
 */
bool PersonLista::finnsPerson(const string &namn)
{
	for (int i = 0; i < antal_personer; i++)
	{
		if (personer[i].hamtaNamn() == namn)
		{
			return true;
		}
	}
	return false;
}

//####################################################################################################################################
// Klassen Transaktion

// Konstruktor
Transaktion::Transaktion()
{
	datum = "";
	typ = "";
	namn = "";
	belopp = 0.0;
	antal_kompisar = 0;
	kompisar = 0;
}

// Destruktor
Transaktion::~Transaktion()
{
	delete[] kompisar;
}

// selektor av attributet namn
Transaktion &Transaktion::operator=(const Transaktion &t)
{
	if (this != &t)
	{

		datum = t.datum;
		typ = t.typ;
		namn = t.namn;
		belopp = t.belopp;
		antal_kompisar = t.antal_kompisar;

		delete[] kompisar;
		kompisar = new string[antal_kompisar];

		for (int i = 0; i < antal_kompisar; i++)
			kompisar[i] = t.kompisar[i];
	}
	return *this;
}

// selektor av attributet namn
string Transaktion::hamtaNamn() const
{
	return namn;
}

// selektor av attributet belopp
double Transaktion::hamtaBelopp() const
{
	return belopp;
}

//  selektor av attributet antal_kompisar
int Transaktion::hamtaAntalKompisar() const
{
	return antal_kompisar;
}

/**
 * @brief letar igenom arrayen kompisar och letar efter @param namnet
 *
 * @param namnet
 * @return true,  om namnet finns.
 * @return false, om namnet inte finns
 */
bool Transaktion::finnsKompis(const string &namnet) const
{
	for (int i = 0; i < antal_kompisar; i++)
	{
		if (kompisar[i] == namnet)
		{
			return true;
		}
	}
	return false;
}

/** @brief läser data om en transaktion (kvitto) från  en fil.
 * Denna är av typen bool, eftersom den kan komma att anropas från klassen TransaktionsLista:s metod lasIn med en loop av typen.
 * @param is istream
 * @return true, det finns fortfarande innehåll i filen
 * @return false, filen är tom
 */
bool Transaktion::lasIn(istream &is)
{

	if (!is.eof())
	{

		is >> datum >> typ >> namn >> belopp >> antal_kompisar;
		delete[] kompisar;
		kompisar = new string[antal_kompisar];

		for (int i = 0; i < antal_kompisar; i++)
		{
			is >> kompisar[i];
		}

		return !is.eof();
	}
	return !is.eof();
}

/**
 * @brief Skriver ut information om ett objekt (dvs "aktuella objektet" tillhörande denna klass), dvs attributens värden till skärmen.
 *
 * @param os output stream
 */
void Transaktion::skrivUt(ostream &os) const
{

	os << setw(8) << left << datum << setw(8) << left << typ << setw(8) << left << namn << setw(8) << left << belopp << setw(8) << left << antal_kompisar << setw(8);
	for (int i = 0; i < antal_kompisar; i++)
	{
		os << setw(8) << left << kompisar[i];
	}
	os << endl;
}

// Skriver ut titel
void Transaktion::skrivTitel(ostream &os) const
{
	os << "Datum   Typ     Namn    Belopp  Antal och lista av kompisar" << endl;
	os << "=====================================================================" << endl;
}

// #####################################################################################################################
// Klassen TransaktionsListaç

// Konstruktor
TransaktionsLista::TransaktionsLista()
{
	antal_transaktioner = 0;
	transaktioner = 0; // lagt till 18/8
}

// Destruktor
TransaktionsLista::~TransaktionsLista()
{
	delete[] transaktioner;
}

/**
 * @brief lasIn läser in värden till ett TransaktionsLista-objekt från fil.
 * Använder sig av inläsnings- och utskriftsmetoder i klassen Transaktion.
 * @param is input, fil
 */
void TransaktionsLista::lasIn(istream &is)
{
	Transaktion t;
	// Så länge det går bra att läsa (filen ej slut)

	while (t.lasIn(is))
	{
		laggTill(t);
	}
}

/**
 * @brief läser in värden till ett TransaktionsLista-objekt till skärm.
 * Använder sig av inläsnings- och utskriftsmetoder i klassen Transaktion.
 * @param os output stream
 */
void TransaktionsLista::skrivUt(ostream &os)
{

	os << "Antal transaktioner: " << antal_transaktioner << endl;
	transaktioner[0].skrivTitel(os);
	for (int i = 0; i < antal_transaktioner; i++)
	{
		transaktioner[i].skrivUt(os);
	}
	os << endl;
}

/**
 * @brief ska lägga till ett nytt transaktionsobjekt sist i arrayen transaktioner.
 * Alltså efter det sista icketomma objektet i arrayen.
 *
 * @param t av class Transaktion. Det som ska läggas till i arrayen transaktioner.
 */
void TransaktionsLista::laggTill(Transaktion &t)
{

	Transaktion *trans = NULL;
	trans = new Transaktion[antal_transaktioner + 1];

	for (int i = 0; i < antal_transaktioner; i++)
	{
		trans[i] = transaktioner[i];
	}

	trans[antal_transaktioner] = t;
	antal_transaktioner++;

	delete[] transaktioner;
	transaktioner = trans;
}

/** @brief beräknar och returnerar summan av alla utgifter på resan (så man kan jämföra olika år och se om det t ex blir dyrare).
 *
 * @return double den totala kostnaden för resan.
 */
double TransaktionsLista::totalKostnad() const
{
	double totala_kostnad = 0.0;
	for (int i = 0; i < antal_transaktioner; i++)
	{
		totala_kostnad += transaktioner[i].hamtaBelopp();
	}

	return totala_kostnad;
}

/**
 * @brief räknar ut hur mycket en viss person, dvs med namnet namnet har betalat för andra personer och alltså ligger ute med.
 * Detta belopp räknas ut genom att gå igenom alla transaktioner.
 * @param namnet
 * @return double
 */
double TransaktionsLista::liggerUteMed(const string &namnet)
{
	double summa = 0.0;

	for (int i = 0; i < antal_transaktioner; i++)
	{
		if (transaktioner[i].hamtaNamn() == namnet)
		{
			summa += transaktioner[i].hamtaBelopp() *
							 (1.0 - 1.0 / (transaktioner[i].hamtaAntalKompisar() + 1));
		}
	}

	return summa;
}

/**
 * @brief räknar ut hur mycket en viss person, dvs med namnet namnet är skyldig andra.
 * Vilket igen räknas ut genom att gå igenom alla transaktioner och andelen av personen av transaktionen.
 * @param namnet
 * @return double summan personen är skyldig
 */
double TransaktionsLista::arSkyldig(const string &namnet)
{
	double skyldig_summa = 0.0;

	for (int i = 0; i < antal_transaktioner; i++)
	{
		if (transaktioner[i].finnsKompis(namnet))
		{
			skyldig_summa += (transaktioner[i].hamtaBelopp() / (transaktioner[i].hamtaAntalKompisar() + 1));
		}
	}
	return skyldig_summa;
}

/**
 * @brief ska skapa och returnera ett objekt av typen PersonLista genom att gå igenom transaktionslistan och plocka ut alla unika personer som förekommer i transaktionerna.
 *
 * Sedan skall personobjekt skapas som läggs till objektet av typen PersonLista, som slutligen returneras.
 * Dvs man bygger upp med fler och fler personer till den array som är attribut inne objekt av typen PersonLista.
 *
 * @return PersonLista alla_kompisar
 */
PersonLista TransaktionsLista::fixaPersoner()
{
	PersonLista alla_kompisar;

	string namn;
	double betalat_andra = 0.0;
	double skyldig = 0.0;

	for (int i = 0; i < antal_transaktioner; i++)
	{

		namn = transaktioner[i].hamtaNamn(); // kolla varje transaktion

		if (!alla_kompisar.finnsPerson(namn)) // om den kompisens inte finns i PersonLista
		{

			skyldig = arSkyldig(namn);
			betalat_andra = liggerUteMed(namn);

			Person person = Person(namn, betalat_andra, skyldig);
			alla_kompisar.laggTill(person);

			// nollställ
			namn = "";
			betalat_andra = 0.0;
			skyldig = 0.0;
		}
	}
	return alla_kompisar;
}
