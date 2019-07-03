#ifndef NAGLOWKI_H
#define NAGLOWKI_H
#endif

#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

struct Position
{
	double x, y;
};

class Country;
class City
{
	Position A;
	string name;

public:
	City();
	City(string n, double a, double b, Country &obj);
	double getPositionA();
	double getPositionB();
	string getName();
};

class Stoper : public City
{
	Position *A;
	string name;
	int stamina;
	int health;
	int money;

public:
	Stoper();
	Stoper(string n);
	void hitch(City &Obj);
	void sleep();
	void eat();
	double getPositionA();
	double getPositionB();
	string getName();
	int returnMoney();
	int returnStamina();
	int returnHealth();
};

class Country
{
	int nr;
	int count;
	string name;


public:
	vector <City> city;
	City **tab;
	Country();
	Country(string n, int c, int a);
	int returnNr();
};
