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
			matrix[i][j] = -3 + rand() % 12;
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

bool isNegative(int** matrix, int row_index, int m) 
{
	for (int j = 0; j < m; ++j)
		if (matrix[row_index][j] < 0)
			return true;
	return false;
}
int** moveRow(int **matrix, )

int main()
{
	setlocale(LC_ALL, "Rus");
	int n, m;
	cout << "Введите кол-во строк: ";
	cin >> m;

	cout << "Введите кол-во столбцов: ";
	cin >> n;


	for (int i = 0; i < n; i++)
	{
		int** matrix = newMatrix(m);
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (isNegative(matrix, i, m))
				{
					moveRow();
				}
			}
		}
	}

	system("pause");
	return 0;
}
