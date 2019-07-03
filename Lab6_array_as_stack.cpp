//http://kodatnik.blogspot.com/2009/11/stos-implementacja-tablicowa.html

#include <string>
#include <iostream>

using namespace std;

class Item
{
	string name;
public:
	Item() { name = "pusty"; }
	Item(string n) { name = n; }
	~Item() {};

};
class Stack
{

public:
	virtual void push(Item *obj) = 0;
	virtual void pop() = 0;
	virtual Item* get() = 0;
};
class ArrayStack : public Stack
{
protected:
	int top;
	int max;
	Item *wsk;
public:
	ArrayStack() { max = 0; }
	ArrayStack(int m)
	{
		if (m < 0)
		{
			try
			{
				string a = "WrongSizeException";
				throw a;
			}
			catch (string a)
			{
				cout << a << endl;
			}
		}
		else
		{
			max = m; wsk = new Item[m]; top == -1;
		}
	}
	void push(Item *obj)
	{
		if (top >= max)
		{
			try
			{
				string a = "StackFullException";
				throw a;
			}
			catch (string a)
			{
				cout << a << endl;
			}
		}
		else
		{
			wsk[++top] = *obj;
		}
	}
	void pop()
	{
		if (top == -1)
		{
			try
			{
				string a = "StackEmptyException";
				throw a;
			}
			catch (string a)
			{
				cout << a << endl;
			}
		}
		else
		{
			wsk[top--];
			wsk[top--].~Item();
		}
	}
	Item *get()
	{
		if (top == -1)
		{
			try
			{
				string a = "StackEmptyException";
				throw a;
			}
			catch (string a)
			{
				cout << a << endl;
			}
		}
		else
		{
			return &wsk[top];
		}
	}

};
class DynamicArrayStack : public ArrayStack
{
	int starting_size;
public:
	DynamicArrayStack() { starting_size == 0; }
	DynamicArrayStack(int a) : ArrayStack(a)
	{

	}
	void push(Item *obj)
	{
		if (top >= max)
		{
			wsk = new Item[sizeof(wsk) * 2];
			starting_size = 2 * (starting_size);
		}
	}
	void pop()
	{
		starting_size--;
	}
};
int main()
{
	ArrayStack Zeus(5);
	DynamicArrayStack Morfeus(1);
	Item A("Byl dobry");
	Item *p;
	p = &A;
	Item B("Byl zly");
	Item *r;
	r = &B;
	Item C("Byl brzydki");
	Item *t;
	t = &C;
	Zeus.push(p);
	Zeus.get();
	Zeus.pop();
	Zeus.get();
	Morfeus.push(t);
	Morfeus.get();
	Morfeus.push(r);
	Morfeus.get();
	Morfeus.push(p);
	Morfeus.get();
	Morfeus.pop();
	Morfeus.get();
	Morfeus.push(p);
	Morfeus.get();

	system("pause");
	return 0;
}