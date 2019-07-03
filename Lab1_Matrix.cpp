#include <cstdlib>
#include <ctime>
#include <stdio.h>
using namespace std;

void Matrix(float x, float y, float **tab);
void Matrix_Complex(float x, float y);
void Show(float x, float y);
void Save(char name[], float x, float y);

struct Complex {
	int Re;
	int Im;
}**tabl;

int main()
{
	srand(time(NULL));
	int choose;
	char name[20];
	float a, b;
	printf("Matrix high:");
	scanf("%f", &a);
	printf("\nMatrix width:");
	scanf("%f", &b); printf("\n\n");

	float **arr = new float *[a];
	for (int i = 0; i < a; i++)
	{
		arr[i] = new float[b];
	}
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			arr[i][j] = rand() % 3 - 1;
		}
	}

	Matrix(a, b, arr);
	Matrix_Complex(a, b);

	printf("It is time for the matrix with complex numbers. Do you want to see it (1) or save it to the file (2)?");
	scanf("%d", &choose);
	while (choose != 1 && choose != 2) { printf("Wrong number!"); scanf("%d", &choose); }
	if (choose == 1)
	{
		Show(a, b);
	}
	else if (choose == 2)
	{
		printf("Please write a file name (.txt format at the end):");
		scanf("%s", &name);
		Save(name, a, b);
		printf("Done!\n\n");
	}

	for (int i = 0; i < a; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;



	for (int i = 0; i < a; i++)
	{
		delete[] tabl[i];
	}
	delete[] tabl;

	system("pause");

	return 0;
}
void Matrix(float x, float y, float **tab)
{
	for (int h = 1; h <= y; h++) { printf("%8d", h); }
	printf("\n\n");
	for (int i = 0; i < x; i++)
	{
		printf("%2d|", i + 1);
		for (int j = 0; j < y; j++)
		{
			printf("%7.3f|", tab[i][j]);
		}printf("\n  ");  for (int k = 0; k <= 8 * y; k++) { printf("-"); } printf("\n");
	}
	printf("\n\n");
}
void Matrix_Complex(float x, float y)
{
	tabl = new Complex *[x];
	for (int h = 0; h < x; h++)
	{
		tabl[h] = new Complex[y];
	}
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			tabl[i][j].Re = rand() % 3 - 1;
			tabl[i][j].Im = rand() % 3 - 1;
		}
	}
}
void Show(float x, float y)
{

	for (int h = 1; h <= y; h++) { printf("%6d", h); }
	printf("\n\n");
	for (int i = 0; i < x; i++)
	{
		printf("%2d|", i + 1);
		for (int j = 0; j < y; j++)
		{
			if (tabl[i][j].Im == 0)
			{
				printf("%5d|", tabl[i][j].Re);
			}
			if (tabl[i][j].Im > 0)
			{
				printf("%2d+%di|", tabl[i][j].Re, tabl[i][j].Im);
			}
			if (tabl[i][j].Im < 0)
			{
				printf("%2d%di|", tabl[i][j].Re, tabl[i][j].Im);
			}

		}printf("\n  ");  for (int k = 0; k <= 6 * y; k++) { printf("-"); } printf("\n");
	}
	printf("\n\n");
}
void Save(char name[], float x, float y)
{


	FILE *pFile;
	if ((pFile = fopen(name, "w")) == NULL)
	{
		printf("Can't open the file!");
		exit(1);
	}
	for (int h = 1; h <= y; h++) { fprintf(pFile, "%6d", h); }
	fprintf(pFile, "\n\n");
	for (int i = 0; i < x; i++)
	{
		fprintf(pFile, "%2d|", i + 1);
		for (int j = 0; j < y; j++)
		{
			if (tabl[i][j].Im == 0)
			{
				fprintf(pFile, "%5d|", tabl[i][j].Re);
			}
			if (tabl[i][j].Im > 0)
			{
				fprintf(pFile, "%2d+%di|", tabl[i][j].Re, tabl[i][j].Im);
			}
			if (tabl[i][j].Im < 0)
			{
				fprintf(pFile, "%2d%di|", tabl[i][j].Re, tabl[i][j].Im);
			}

		}fprintf(pFile, "\n  ");  for (int k = 0; k <= 6 * y; k++) { fprintf(pFile, "-"); } fprintf(pFile, "\n");
	}
	fprintf(pFile, "\n\n");
}
















/*struct struktura {
int Re;
int Im;
}**Baza;

int main()
{
int g = 7;
int h = 9;

Baza=new struktura*[g];
for (int i = 0; i < g; i++)
{
Baza[i] = new struktura[h];
}
for (int i = 0; i < g; i++)
{
for (int j = 0; j < h; j++)
{
Baza[i][j].Re=i+2;
Baza[i][j].Im=i+7;
}
}
for (int i = 0; i < g; i++)
{
for (int j = 0; j < h; j++)
{
cout<<Baza[i][j].Re;
cout<<Baza[i][j].Im;
cout << "  ";
}cout << endl;
}
for (int i = 0; i < g; i++)
{
delete[] Baza[i];
}
delete[] Baza;

g = 10;
h = 2;

Baza = new struktura*[g];
for (int i = 0; i < g; i++)
{
Baza[i] = new struktura[h];
}
for (int i = 0; i < g; i++)
{
for (int j = 0; j < h; j++)
{
Baza[i][j].Re = i + 2;
Baza[i][j].Im = i + 7;
}
}
for (int i = 0; i < g; i++)
{
for (int j = 0; j < h; j++)
{
cout << Baza[i][j].Re;
cout << Baza[i][j].Im;
cout << "  ";
}cout << endl;
}






return 0;
}  */