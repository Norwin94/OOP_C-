#include <iostream>
#include <vector>

//!!!!!Access violation exception in ntdll when starting debugging of c++ console application!!!!!!!
using namespace std;

struct Position
{
	int x;
	int y;
};

class Object
{
public:
	Position A;
	Position *wsk;
	virtual void getPosition() = 0;
};


//////////////////////////////////////////////////////////////////////////////////
class Player : public Object
{
protected:
	Player *wsk1;
	Position A;
	Position *wsk;
	int strength;
public:
	vector <int> Bag;
	int nr;
	int hp;
	Player() { strength = 0; wsk = new Position; wsk->x = 0; wsk->y = 0; hp = 0; nr = 0; }
	Player(int a, int b, int c)
	{
		wsk = new Position;
		wsk->x = a;
		wsk->y = b;
		strength = c;
		hp = 10;
		nr = 0;
	}
	int returnStrength()
	{
		int a = 0;
		for (int i = 0; i<Bag.size(); i++)
		{
			a += Bag[i];
		}
		return a;
	}
	void getPosition()
	{
		cout << wsk->x << "." << wsk->y << endl;
	}
	~Player()
	{
		delete wsk;
	}
};
//////////////////////////////////////////////////////////////////////////////////
class Interactive
{
public:
	virtual void interact(Player &player) = 0;
};
//////////////////////////////////////////////////////////////////////////////////


class Item : public Object, public Interactive
{
	Position *wsk;
	Position I;

public:
	int strength;
	Item() { strength = 0; wsk = new Position; wsk->x = 0; wsk->y = 0; }
	Item(int a, int b, int c)
	{
		wsk = new Position;
		wsk->x = a;
		wsk->y = b;
		strength = c;
	}
	void interact(Player &player)
	{
		player.Bag.push_back(strength); cout << "push back" << endl;
		delete wsk; cout << "delete wsk" << endl;
	}
	void getPosition()
	{
		cout << wsk->x << "." << wsk->y << endl;
	}
};
//////////////////////////////////////////////////////////////////////////////////


class Enemy : public Object, public Interactive
{
	Enemy *wsk1;
	Position *wsk;
	Position E;
	int strength;
public:
	Enemy() { strength = 0; wsk = new Position; wsk->x = 0; wsk->y = 0; }
	Enemy(int a, int b, int c)
	{
		wsk = new Position;
		wsk->x = a;
		wsk->y = b;
		strength = c;
	}
	void interact(Player &player)
	{
		if (strength > player.returnStrength())
		{
			cout << "tu tu tu tu tu tu tu tum tum <muzyczka z Mario>" << endl;
			player.~Player();
			cout << "GAME OVER!!!" << endl;
		}
		else if (2 * (strength) < player.returnStrength())
		{
			cout << "YOU WIN!!!" << endl;
			delete wsk;
			delete wsk1;
		}
		else if (strength < player.returnStrength())
		{
			player.hp -= (strength / 2);
			cout << "YOU WIN!!!  You loose " << strength / 2 << "HP" << endl;
			delete wsk;
			delete wsk1;
		}
		else if (strength == player.returnStrength())
		{
			player.hp -= (strength / 4);
			cout << "YOU WIN!!!  You loose " << strength / 4 << "HP" << endl;
			delete wsk;
			delete wsk1;
		}
	}
	void getPosition()
	{
		cout << wsk->x << "." << wsk->y << endl;
	}
};
//////////////////////////////////////////////////////////////////////////////////
class Potion : public Object, public Interactive
{
	Potion *wsk1;
	Position P;
	Position *wsk;
	int vitality;
public:
	Potion() { vitality = 0; wsk->x = 0; wsk->y = 0; }
	Potion(int a, int b, int c)
	{
		wsk = new Position;
		vitality = c;
		wsk->x = a;
		wsk->y = b;

	}
	void getPosition()
	{
		cout << wsk->x << "." << wsk->y << endl;
	}
	void interact(Player &player)
	{
		player.hp += vitality; cout << "player.hp += vitality;" << endl;
		delete wsk; cout << "delete wsk;" << endl;
		//delete wsk1; cout << "delete wsk1" << endl;
	}
};
//////////////////////////////////////////////////////////////////////////////////
class Board
{
	int x, y;
public:
	Player Obj;
	Player *wsk;
	vector <Potion> BoxP;
	vector <Enemy> BoxE;
	vector <Item> BoxI;
	vector <Interactive*> BoxA;
	Board() { cout << "Co to za mapka?!?!?!?!" << endl; }
	Board(int a, int b)
	{
		x = a; y = b;
	}

};
//////////////////////////////////////////////////////////////////////////////////

int main()
{
	Potion Food(4, 5, 6);
	Item Rise(2, 1, 7);
	Item Stone(2, 1, 14);
	Player Bat(3, 5, 6);
	Enemy Joker(10, 10, 10);
	Enemy Hulk(4, 7, 4);

	Board Map(20, 20);
	Map.Obj = Bat;
	Map.BoxP.push_back(Food);
	Map.BoxI.push_back(Rise);
	Map.BoxI.push_back(Stone);
	Map.BoxE.push_back(Joker);
	Map.BoxE.push_back(Hulk);
	Map.BoxP[0].getPosition();

	system("pause");
	return 0;
}
