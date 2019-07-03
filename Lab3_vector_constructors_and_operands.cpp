#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

class Vector
{
public:
	double *w;
	int s;
	Vector() {}
	Vector(int size)
	{
		s = size; cout << "Utworzenie nowego Vector o (s) rozmiarze" << endl;
		w = new double[size];
		for (int i = 0; i < size; i++)
		{
			w[i] = 0;
		}
	}
	Vector(const Vector &Vector1)
	{
		s = Vector1.s; cout << "Konstruktor kopiujacy. s = Vector1.s" << endl;
		w = new double[Vector1.s]; cout << "Konstruktor kopiujacy. w = new double[Vector1.s]" << endl;
		for (int i = 0; i < s; i++)
		{
			w[i] = Vector1.w[i]; cout << "Konstruktor kopiujacy. w[i] (" << w[i] << ") = Vector1.w[i](" << Vector1.w[i] << ")" << endl;
		}
	}
	~Vector()
	{
		delete[]w;
	}
	double &operator[](int liczba)
	{
		if (liczba > s && liczba<0) { cout << "Nie ten rozmiar!"; exit(0); }
		return w[liczba];
	}
	Vector operator+ (const Vector &M)
	{
		if (s > M.s || s < M.s) { cout << "Wektory nie pasuja do siebie. Dodawanie" << endl; exit(0); }
		Vector Temp(s); cout << "Operator +. Utworzenie Vecotr Temp(s)" << endl;
		for (int i = 0; i < s; i++)
		{
			Temp.w[i] = w[i] + M.w[i]; cout << "Operator +. Temp.w[i]= " << Temp.w[i] << endl;
		}return Temp;
	}
	Vector operator- (const Vector &M)
	{
		if (s > M.s || s < M.s) { cout << "Wektory nie pasuja do siebie. Odejmowanie" << endl; exit(0); }
		Vector Temp(s); cout << "Ktos" << endl;
		for (int i = 0; i < s; i++)
		{
			Temp.w[i] = w[i] - M.w[i]; cout << Temp.w[i] << endl;
		}return Temp;
	}
	Vector operator* (const Vector &M)
	{
		if (s > M.s || s < M.s) { cout << "Wektory nie pasuja do siebie. Mnozenie" << endl; exit(0); }
		Vector Temp(s); cout << "Ktos" << endl;
		for (int i = 0; i < s; i++)
		{
			Temp.w[i] = w[i] * M.w[i]; cout << Temp.w[i] << endl;
		}return Temp;
	}
	Vector operator/ (const Vector &M)
	{
		if (s > M.s || s < M.s) { cout << "Wektory nie pasuja do siebie. Dzielenie" << endl; exit(0); }
		Vector Temp(s); cout << "Ktos" << endl;
		for (int i = 0; i < s; i++)
		{
			Temp.w[i] = w[i] / M.w[i]; cout << Temp.w[i] << endl;
		}return Temp;
	}
	Vector operator= (const Vector &Me)
	{
		if (s > Me.s || s < Me.s) { cout << "Wektory nie pasuja do siebie. Przypisanie" << endl; exit(0); }
		cout << "Operator przypisania" << endl;
		if (this != &Me)
		{
			delete[]w; cout << "delete[]w" << endl;
			w = new double[s]; cout << "w = new double[s]" << endl;

			for (int i = 0; i < s; i++)
			{
				w[i] = Me.w[i]; cout << "w[i] = Me.w[i]  wypisanie Me.w[i]= " << Me.w[i] << endl;
			}
		}
		return *this;
	}
};


int main()
{
	Vector A(5);
	Vector B(5);
	A = A;

	system("pause");
	return 0;
}