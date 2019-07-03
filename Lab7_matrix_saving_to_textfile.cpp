#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class MyException : public exception
{
	string error;
public:
	MyException(string err)
	{
		error = err;
	}
	virtual const char* what() const throw()
	{
		return error.c_str();
	}
};

template <class T>
class Matrix
{
protected:
	static int count;
	int high, width;
	T **wsk;
	string linia;
	string n;
public:
	friend ostream& operator<<(ostream&staff, Matrix<T>&obj);
	Matrix() { high = 0, width = 0; }
	Matrix(int a, int b, T value)
	{
		if (a < 0 || b < 0)
		{
			throw MyException("WrongSizeException. Constructor");
		}
		high = a, width = b;
		wsk = new T*[a];
		for (int i = 0; i < a; i++)
		{
			wsk[i] = new T[b];
		}
		for (int i = 0; i < a; i++)
		{
			for (int j = 0; j < b; j++)
			{
				wsk[i][j] = value;
			}
		}
		count++;
	}
	void set(int x, int y, T c)
	{
		if (x > high || y > width || x < 0 || y < 0)
		{
			throw MyException("WrongSizeException. Set");
		}
		wsk[x][y] = c;
	}
	T show(int x, int y)
	{
		if (x > high || y > width || x < 0 || y < 0)
		{
			throw MyException("WrongSizeException. Show");
		}
		return wsk[x][y];
	}
	static int getCount()
	{
		if (count < 0)
		{
			throw MyException("CountException");
		}
		return count;
	}
	static void writeToFile(string name, Matrix<T>&obj)
	{
		ofstream file;
		file.open(name);
		for (int i = 0; i < obj.high; i++)
		{
			for (int j = 0; j < obj.width; j++)
			{
				file << "|" << obj.wsk[i][j] << "|";
			}file << endl;
		}
		file.close();

	}
	static void readFromFile(string name, Matrix<T>&obj)
	{
		ifstream file;
		file.open(name);
		if (obj.n != name)
		{
			throw MyException("WrongNameException. Reading");
		}
		while (!file.eof())
		{
			getline(file, obj.linia);
			cout << obj.linia << endl;
		}

		file.close();
	}
	Matrix(const Matrix &Me)
	{
		high = Me.high; cout << "Konstruktor kopiujacy" << endl;
		wsk = new int*[high]; cout << "wsk = new int*[high]" << endl;
		for (int i = 0; i < high; i++)
		{
			wsk[i] = new int[width];
		} cout << "petla wsk[i] = new int[width]" << endl;
		for (int i = 0; i < high; i++)
		{
			for (int j = 0; j < width; j++)
			{
				wsk[i][j] = Me.wsk[i][j];
			}
		}
	}
	Matrix &operator= (const Matrix &Me)
	{
		if (high > Me.high || high < Me.high || width > Me.width || width < Me.width)
		{
			throw MyException("WrongSizeException. Operator");
		}
		if (this == &Me)
		{
			throw MyException("TheSameFileException");
		}
		for (int i = 0; i < high; i++)
		{
			delete[] wsk[i];
		}
		delete[] wsk;
		wsk = new int*[high];
		for (int i = 0; i < high; i++)
		{
			wsk[i] = new int[width];
		}cout << "Przydzielono" << endl;
		for (int i = 0; i < high; i++)
		{
			cout << "Przydziela high" << endl;
			for (int j = 0; j < width; j++)
			{
				wsk[i][j] = Me.wsk[i][j]; cout << "Przydziela width" << endl;
			}
		}
		return *this;
	}

	void streamer(string name)
	{

		if (name == "output")
		{
			for (int i = 0; i < high; i++)
			{
				for (int j = 0; j < width; j++)
				{
					cout << wsk[i][j] << "||";
				} cout << endl;
			}
		}
		else if (name == "input")
		{
			for (int i = 0; i < high; i++)
			{
				for (int j = 0; j < width; j++)
				{
					cout << "Podaj wartosc dla [" << i << "] [" << j << "]  :";
					cin >> wsk[i][j];
				}
			}
		}
		else(throw MyException("NoStreamerException"));
	}
	~Matrix()
	{
		--count;
		for (int i = 0; i < high; i++)
		{
			delete[] wsk[i];
		}
		delete[] wsk;

		cout << "Destruktor" << endl;
	}
};

template <class T>
ostream& operator<<(ostream&staff, Matrix<T>&obj)
{
	for (int i = 0; i < obj.high; i++)
	{
		for (int j = 0; j < obj.width; j++)
		{
			staff << obj.wsk[i][j] << "||";
		} staff << endl;
	}return staff;
}

template <class T>
int Matrix<T>::count = 0;

typedef Matrix<int> MatrixInt;
typedef Matrix<string> MatrixString;
typedef Matrix<char> MatrixChar;
typedef Matrix<double> MatrixDouble;

int main()
{
	try
	{


		MatrixInt A(5, 5, 10);
		A.writeToFile("neew.txt", A);
		MatrixInt B(5, 5, 0);
		MatrixString C(4, 4, "null.txt");
		cout << "Podaj nazwe";
		A.streamer("input");
		A.writeToFile("neew.txt", A);
	}
	catch (MyException &e)
	{
		cout << e.what() << endl;
	}

	system("pause");
	return 0;
}

//-------------------------------------------------------------
//Same programm as above but with declared matrix
/*



class MyException : public exception
{
string error;
public:
MyException(string err)
{
error = err;
}
virtual const char* what() const throw()
{
return error.c_str();
}
};

template <class T>
class Matrix
{
protected:
static int count;
int high, width;
T **wsk;
string linia;
string n;
public:
friend ostream& operator<< (ostream&staff, const Matrix<T>&obj);
Matrix() { high = 0, width = 0; }
Matrix(int a, int b, T value)
{
if (a < 0 || b < 0)
{
throw MyException("WrongSizeException. Constructor");
}
high = a, width = b;
wsk = new T*[a];
for (int i = 0; i < a; i++)
{
wsk[i] = new T[b];
}
for (int i = 0; i < a; i++)
{
for (int j = 0; j < b; j++)
{
wsk[i][j] = value;
}
}
count++;
}
void set(int x, int y, T c)
{
if (x > high || y > width || x < 0 || y < 0)
{
throw MyException("WrongSizeException. Set");
}
wsk[x][y] = c;
}
T show(int x, int y)
{
if (x > high || y > width || x < 0 || y < 0)
{
throw MyException("WrongSizeException. Show");
}
return wsk[x][y];
}
static int getCount()
{
if (count < 0)
{
throw MyException("CountException");
}
return count;
}
static void writeToFile(string name, Matrix&obj)
{
obj.n = name;
ofstream file;
file.open(name);
for (int i = 0; i < obj.high; i++)
{
for (int j = 0; j < obj.width; j++)
{
file << "|" << obj.wsk[i][j] << "|";
}file << endl;
}
file.close();

}
static void readFromFile(string name, Matrix&obj)
{
ifstream file;
file.open(name);
if (obj.n != name)
{
throw MyException("WrongNameException. Reading");
}
else
{
while (!file.eof())
{
getline(file, obj.linia);
cout << obj.linia << endl;
}

file.close();
}
}
Matrix &operator= (const Matrix &Me)
{
if (high > Me.high || high < Me.high || width > Me.width || width < Me.width)
{
throw MyException("WrongSizeException. Operator");
}
if (this == &Me)
{
throw MyException("SameFileException");
}
for (int i = 0; i < high; i++)
{
delete[] wsk[i];
}
delete[] wsk;
wsk = new int*[high];
for (int i = 0; i < high; i++)
{
wsk[i] = new int[width];
}cout << "Przydzielono" << endl;
for (int i = 0; i < high; i++)
{
cout << "Przydziela high" << endl;
for (int j = 0; j < width; j++)
{
wsk[i][j] = Me.wsk[i][j]; cout << "Przydziela width" << endl;
}
}
return *this;
}

void streamer(string name)
{

if (name == "output")
{
for (int i = 0; i < high; i++)
{
for (int j = 0; j < width; j++)
{
cout << wsk[i][j] << "||";
} cout << endl;
}
}
else if (name == "input")
{
for (int i = 0; i < high; i++)
{
for (int j = 0; j < width; j++)
{
cout << "Podaj wartosc dla [" << i << "] [" << j << "]  :";
cin >> wsk[i][j];
}
}
}
else(throw MyException("NoStreamerException"));
}
~Matrix()
{
count--;
for (int i = 0; i < high; i++)
{
delete[] wsk[i];
}
delete[] wsk;

cout << "Destruktor" << endl;
}
};

template <class T> ostream& operator<< (ostream&staff, const Matrix<T>&obj)
{
for (int i = 0; i < obj.high; i++)
{
for (int j = 0; j < obj.width; j++)
{
staff << obj.wsk[i][j] << "||";
} staff << endl;
}return staff;
}

template <class T>
int Matrix<T>::count = 0;

typedef Matrix<int> MatrixInt;
typedef Matrix<string> MatrixString;
typedef Matrix<char> MatrixChar;
typedef Matrix<double> MatrixDouble;

int main()
{
try
{


MatrixInt A(5, 5, 10);
A.writeToFile("neew.txt", A);
A.readFromFile("neew.txt", A);
}
catch (MyException &e)
{
cout << e.what() << endl;
}

system("pause");
return 0;
}
*/