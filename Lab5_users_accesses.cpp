#include <iostream>
#include <string> 

using namespace std;

enum Acc { low, medium, high, full };

string rename(Acc my)
{
	switch (my)
	{
	case low:
		return("Low");
	case medium:
		return("Medium");
	case high:
		return("High");
	case full:
		return("Full");
	}
}

class Printable
{
public:
	virtual void print(std::ostream& stream) = 0;
};

class Accesible
{
public:
	virtual void setAccess(Acc access) = 0;
	virtual Acc getAccess() = 0;
	virtual void checkAccessible(Acc access) = 0;
};

class User : public Printable, public Accesible
{
protected:
	Acc y;
	int id;
	string name;
public:
	User()
	{
		id = 0;
		name = "pusty";
	}
	User(int iden, string nazwa)
	{
		id = iden;
		name = nazwa;
	}
	void print(ostream& stream)
	{
		stream << "[#" << id << "] " << name << "  Access: " << rename(y) << endl;
	}
	void setAccess(Acc access)
	{
		y = access;
	}
	Acc getAccess()
	{
		return y;
	}
	void checkAccessible(Acc access)
	{
		if (y >= access) { cout << "Odpowiedni poziom uprawnien" << endl; }
		else { cout << "Nieodpowiedni poziom uprawnien" << endl; }
	}
};

class Admin : public User
{
public:
	Admin() : User() {}
	Admin(int a, string b) :User(a, b) { y = full; }
	void setAccess(Acc access)
	{
		try
		{
			throw 1;
		}
		catch (int a)
		{
			cout << "Wystapil blad nr " << a << ". Nie mozna zmienic uprawnien Administratora" << endl;
		}
	}
};



int main()
{
	User A(34, "Karol");
	User B(78, "Jacek");
	A.setAccess(medium);
	B.setAccess(low);
	cout << rename(A.getAccess()) << endl;
	cout << rename(B.getAccess()) << endl;
	A.checkAccessible(high);
	Admin Z(12, "Ziomek");
	Z.checkAccessible(full);
	cout << rename(Z.getAccess()) << endl;
	Z.print(cout);
	Z.setAccess(medium);
	cout << rename(Z.getAccess()) << endl;
	Z.setAccess(full);

	system("pause");
	return 0;
}