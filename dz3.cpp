#include <iostream>
using namespace std;

int** newMatrix(const int n)
{
	int** matrix = new int* [n];
	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			matrix[i][j] = rand() % 100;
		}
	}
	return matrix;
}

void deleteMatrix(int** matrix, const int n)
{
	for (int i = 0; i < n; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}

void showMatrix(int** matrix, const int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << matrix[i][j] << '\t';
		}
		cout << endl;
	}
	cout << endl;
}

int totalBelowDiagonal(int** matrix, const int n)
{
	int total = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			total += matrix[i][j];
		}
	}
	return total;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	int n, m, total;
	int largest = -2147483;
	cout << "Введите размер квадратной матрицы: ";
	cin >> m;

	cout << "Введите количество матриц: ";
	cin >> n;


	for (int i = 0; i < n; i++)
	{
		int** matrix = newMatrix(m);
		showMatrix(matrix, m);
		total = totalBelowDiagonal(matrix, m);
		if (total > largest) { largest = total;  }
		deleteMatrix(matrix, m);
	}

	cout << "Самое большое значение суммы ниже диагонали: " << largest << endl;
	system("pause");
	return 0;
}
