#include <stdio.h>
#include <math.h>
#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
    int n, m;
	int count;
	int goodStudent;
	const char check[] = "отлично";
	char temp[] = " ";

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

    printf("n = "); scanf_s("%d", &n);
    printf("m = "); scanf_s("%d", &m);

	//create dynamic matrix MxN
   	char** a = new char* [n];

	for (int i = 0; i < n; i++) {
		a[i] = new char[150][m];
	}
	printf("\n");

	//scan matrix elements
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			gets_s(temp);
			*(*(a + i) + j) = temp;
		}
	}

    //print original matrix
	printf("\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << *(*(a + i) + j) << " ";
		}
		printf("\n");
	}
	printf("\n");

	//check
	for (int i = 0; i < n; i++)
	{
		count = 0;
		goodStudent = 1;
		for (int j = 0; j < m; j++)
		{
			if (strcmp(check, &a[i][j]))
			{
				count++;
			}
		}
		if (count == m)
		{
			goodStudent++;
		}
	}

	cout << "Отличники: " << goodStudent << endl;

	//delete
	for (int i = 0; i < n; i++)
	{
		delete[] a[i];
	}
	delete[] a;

    return 0;
}