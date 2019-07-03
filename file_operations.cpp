#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>


using namespace std;
fstream plik;
string nazwa;
void Utworz();
void Napisz();
void Dodaj();
void Odczytaj();



int main() {
	Utworz();
	Napisz();
	Dodaj();
	Odczytaj();
	
	return 0;
}

void Utworz()
{
	cout << "Podaj nazwe pliku: ";
	cin >> nazwa; cin.ignore(); 
	nazwa += ".txt";
	plik.open(nazwa, ios::out);
	if (plik.good() == false) { cout << "Nie mozna otworzyc pliku!" << endl; exit(0); }
	plik.close();
}
void Napisz()
{
	string napis;
	cout << "Podaj co chcesz napisac: ";  getline(cin, napis); 
	plik.open(nazwa, ios::out);
	if (plik.good() == false) { cout << "Nie mozna otworzyc pliku!" << endl; exit(0); }
	plik << napis << endl;
	plik.close();
}
void Dodaj()
{
	string nap;
	cout << "Podaj co chcesz dodac: ";  getline(cin, nap); 
	plik.open(nazwa, ios::app);
	if (plik.good() == false) { cout << "Nie mozna otworzyc pliku!" << endl; exit(0); }
	plik << nap << endl;
	plik.close();
}
void Odczytaj()
{
	string name;
	plik.open(nazwa, ios::in);
	if (plik.good() == false) { cout << "Nie mozna otworzyc pliku!" << endl; exit(0); }
	while (getline(plik, name))
	{
		cout << name << endl;
	}
	plik.close();
}


/*

-----------------------------------------------------------------------------------------------------------


#include <iostream>
#include <string>
using namespace std;


class Logger
{
public:
	FILE *pFile;
	Logger(string hrj);
	void append(string nazwa);
	~Logger();
};

Logger::Logger(string hrj)
{
	pFile = fopen(hrj.c_str(), "w");
}
void Logger::append(string nazwa)
{
	cout << "Dodaj tekst: "; fscanf(pFile, "%s\n", nazwa);
}
Logger::~Logger()
{
	fclose(pFile);
}
int main()
{

	Logger pisz("Chalupy.txt");
	pisz.append("No siema");
	pisz.Logger::~Logger();
	return 0;
}
*/