#include <iostream>
#include <string>
using namespace std;

int main()
{
	string namn;
	cout << "Skriv in ett namn. ";
	getline(cin, namn);
	cout << "Hej " << namn << endl;
	return 0;
}