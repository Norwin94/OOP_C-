#include "Naglowki.h"


using namespace std;

int main()
{
	srand(time(NULL));

	Country Polska("Polska", 5, 2);
	//Polska
	City Krakow("Krakow", 50, 20, Polska);
	City Szczecin("Szczecin", 53, 14, Polska);
	City Rzeszow("Rzeszow", 50, 22, Polska);
	City Poznan("Poznan", 52, 17, Polska);
	City Wroclaw("Wroclaw", 51, 17, Polska);
	City Warszawa("Warszawa", 52, 21, Polska);
	City Lublin("Lublin", 51, 22, Polska);
	City Bialystok("Bialystok", 53, 23, Polska);
	City Gdansk("Gdansk", 54, 18, Polska);

	Country Ukraina("Ukraina", 6, 2);
	//Ukraina
	City Lwow("Lwow", 49, 24, Ukraina);
	City Kijow("Kijow", 50, 30, Ukraina);
	City Odessa("Odessa", 46, 30, Ukraina);
	City Sewastopol("Sewastopol", 46, 33, Ukraina);
	City Donieck("Donieck", 48, 37, Ukraina);
	City Charków("Charków", 56, 36, Ukraina);

//	*Portugalia.tab[0] = Lizbona;
//	*Portugalia.tab[1] = Porto;

	vector <City> citiesVect; 
	citiesVect.push_back(Krakow);
	citiesVect.push_back(Szczecin);
	citiesVect.push_back(Rzeszow);
	citiesVect.push_back(Poznan);
	citiesVect.push_back(Wroclaw);
	citiesVect.push_back(Kijow);
	citiesVect.push_back(Odessa);
	citiesVect.push_back(Sewastopol);
	citiesVect.push_back(Donieck);
	//want more cities? push back others from Database!

	string name;
	cout << "Witaj nieznajomy. Nawet nie wiem jak na imie masz.. ?" << endl;
	cin >> name;
	Stoper A(name);
	cout << "Witaj " << A.getName() << "! Co chcesz robic?" << endl;
	while (true)
	{
		cout << "Money: " << A.returnMoney() << "     Health: " << A.returnHealth() << "     Stamina: " << A.returnStamina() << endl;
		cout << "---------------------------------------------------------------------------" << endl;
		cout << "Lapac stopa" << endl << "Eat" << endl << "Sleep" << endl << "ReturnHome" << endl;
		cout << "---------------------------------------------------------------------------" << endl;
		int choice;
		cin >> choice;

		{
			switch (choice)
			{
			case 1:
			{
				cout << "Lapac stopa" << endl;
				City **tab = new City *[9];
				for (int i = 0; i < 10; ++i)
				{
					tab[i] = new City();
				}
				int count = 0;
				int choose;
				for (int i = 0; i < citiesVect.size(); i++)
				{
					double z = sqrt(((A.getPositionA()) - (citiesVect[i].getPositionA()))*((A.getPositionA()) - (citiesVect[i].getPositionA()))) + sqrt(((A.getPositionB()) - (citiesVect[i].getPositionB()))*((A.getPositionB()) - (citiesVect[i].getPositionB())));
					if (z < 10 && z > 0)
					{
						*tab[count] = citiesVect[i]; count++;
					}
				}
				cout << "Ktore miasto chcesz wybrac?" << endl;
				for (int i = 0; i < count; i++)
				{
					cout << i + 1 << ". " << tab[i]->getName() << endl;
				}
				cin >> choose;
				while (choose<1 || choose>count) { cout << "Nie ta liczba!. Podaj prawidlowa!: "; cin >> choose; }
				A.hitch(*tab[choose - 1]);
				break;
			}
			case 2: A.eat(); break;
			case 3: A.sleep(); break;
			case 4: cout << "ReturnHome\n"; cout << "Game over!"; system("pause"); return 0;
			default: cout << "Nie ta liczba"; break;
			}
		}
		getchar(); getchar();
		system("cls");
	}


	cout << A.getPositionA() << endl;
	cout << A.getPositionB() << endl;

	return 0;
}