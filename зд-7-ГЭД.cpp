// зд-7-ГЭД.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;

int main()
{
    int n, m;
    int  maxNum = 0;
	int row, col;
	int temp;
	int random;
	srand(time(NULL));
    
    printf("n = "); scanf_s("%d", &n);
    printf("m = "); scanf_s("%d", &m);

	//create dynamic matrix MxN
   	int** a = new int* [n];

	for (int i = 0; i < n; i++) {
		a[i] = new int[m];
	}
	printf("\n");

	//scan matrix elements
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			*(*(a + i) + j) = rand() % 100;
		}
	}

    //print original matrix
	printf("\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << *(*(a + i) + j) << "\t";
		}
		printf("\n\n");
	}
	printf("\n\n\n");

    //sort matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (maxNum < *(*(a + i) + j))
            {
                maxNum = *(*(a + i) + j);
				row = i;
				col = j;
            }

        }
    }

	//swap columns
	temp = 0;
	for (int i = 0; i < n; i++)
	{
		temp = *(*(a + i));
		*(*(a + i)) = *(*(a + i) + col);
		*(*(a + i) + col) = temp;
	}

	//swap rows
		temp = 0;
	for (int j = 0; j < m; j++)
	{
		temp = *(*(a) + j);
		*(*(a) + j) = *(*(a + row) + j);
		*(*(a + row) + j) = temp;
	}


    //print sorted array
	printf("\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << *(*(a + i) + j) << "\t";
		}
		printf("\n\n");
	}
	printf("\n\n\n");

	//delete
	for (int i = 0; i < n; i++)
	{
		delete[] a[i];
	}
	delete[] a;

    return 0;
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
