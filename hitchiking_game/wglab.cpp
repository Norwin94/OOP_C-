#include "Naglowki.h"


using namespace std;



City::City() { name = "empty"; A.x = 0; A.y = 0; }
City::City(string n, double a, double b, Country &obj) { name = n; A.x = a; A.y = b; obj.city.push_back(*this); }
double City::getPositionA() { double a = A.x; return a; }
double City::getPositionB() { double b = A.y; return b; }
string City::getName() { string n = name; return n; }

///////////////////////////////////////////////////////////////////////////////

Stoper::Stoper() { name = "empty"; health = 0; money = 0; A = new Position; A->x = 0; A->y = 0; };
Stoper::Stoper(string n) { name = n; health = 100; stamina = 100; money = 200; A = new Position; A->x = 51; A->y = 17; }
void Stoper::hitch(City &Obj)
{
	string choice;
	double z = sqrt(((A->x) - (Obj.getPositionA()))*((A->x) - (Obj.getPositionA()))) + sqrt(((A->y) - (Obj.getPositionB()))*((A->y) - (Obj.getPositionB())));
	double a = 40;
	do
	{
		for (int i = 0; i <= a - z; i++)
		{
			int g = rand() % 40;
			cout << g << endl;
			if (z == g)
			{
				A->x = Obj.getPositionA();
				A->y = Obj.getPositionB();
				health -= 10; cout << "Zlapales stopa! Miasto " << Obj.getName() << " wita!" << endl;
				return;
			}
		}
		stamina -= 10; health -= 10; cout << "Nie zlapales stopa. Probujesz znowu?" << endl;
		cin >> choice;
	} while (choice != "nie");
}
void Stoper::sleep()
{
	if (stamina > 90) { cout << "Nie spij bo Cie okradna!!"; money -= 50; }
	else
	{
		cout << "Dobranoc!"; stamina = 100;
		if (health < 20)health = 10; else health -= 20;
	}
}
void Stoper::eat()
{
	if (health > 90) { cout << "Rzyganko!"; money -= 20; stamina -= 20; }
	else { cout << "Smacznego!"; money -= 20; health += 10; }
}
double Stoper::getPositionA() { double a = A->x; return a; }
double Stoper::getPositionB() { double b = A->y; return b; }
string Stoper::getName() { string n = name; return n; }
int Stoper::returnMoney() { int n = money; return n; }
int Stoper::returnStamina() { int n = stamina; return n; }
int Stoper::returnHealth() { int n = health; return n; }

///////////////////////////////////////////////////////////////////////////////////////////

Country::Country() { name = "pusty"; }
Country::Country(string n, int c, int a)
{
	name = n; count = c; nr = a;
	tab = new City *[a];
	for (int i = 0; i < a; ++i)
	{
		tab[i] = new City();
	}
}
int Country::returnNr() { int n = count; return n; }