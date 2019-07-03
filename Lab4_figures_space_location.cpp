#include <iostream>

using namespace std;

class Point
{
	int x;
	int y;
public:
	Point()
	{
		this->x = 0;
		this->y = 0;
	}
	Point(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	int GetX()
	{
		return x;
	}
	int GetY()
	{
		return y;
	}

};
class Rectangle
{
protected:
	int a, b, c, d;

public:
	Rectangle()
	{
		a = 0;
		b = 0;
		c = 0;
		d = 0;
	}
	Rectangle(Point S, Point T)
	{
		if (S.GetX() > T.GetX() || T.GetY() > S.GetY()) { cout<<"Zle skonstruowany obiekt!"<<endl; exit(0); }
		else {
			a = S.GetX();
			b = S.GetY();
			c = T.GetX();
			d = T.GetY();
		}
	}
	int getArea()
	{
		return ((b - d)*(c - a)); 
	}
	void collide(Rectangle Rec)
	{
		if (Rec.b >= d && Rec.d <= b && Rec.c >= a && Rec.a <= c)
		{
			if (Rec.a >= a && Rec.c <= c && Rec.b <= b && Rec.d >= d)
			{
				cout << "Drugi obiekt zawiera sie w pierwszym" << endl;
			}
			else if (Rec.a <= a && Rec.c >= c && Rec.b >= b && Rec.d <= d)
			{
				cout << "Pierwszy obiekt zawiera sie w drugim " << endl;
			}
			else
			{
				cout << "Obiekty sie przecinaja" << endl;
			}
		}
		else
		{
			cout << "Obiekty nie przecinaja sie" << endl;
		}
	}
};
class Square: public Rectangle
{
public:

	Square():Rectangle()
	{
	}
	
	Square(Point A, Point B) :Rectangle(A, B)
	{
		if ((B.GetX() - A.GetX()) != (A.GetY() - B.GetY()))
		{
			cout << "To nie jest kwadrat! ";
		}
	}
	Square(Point A, int width)
	{
		a = A.GetX();
		b = A.GetY();
		c = A.GetX() + width;
		d = A.GetY() - width;
	}
};

int main()
{
	Point A(-1, 6);
	Point B(4, 3);
	Point C(0, 6);
	Point D(3, 4);
	Square Zi(A, 7);
	Square Di(C, 3);
	cout<<Zi.getArea()<<endl;
	Rectangle E(A, B);
	Rectangle F(C, D);
	Di.collide(Zi);
	E.collide(F);

	system("pause");
	return 0;
}
