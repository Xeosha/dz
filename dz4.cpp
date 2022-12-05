#include <iostream>
using namespace std;

int** newMatrix(const int m, const int n);
void deleteMatrix(int** matrix, const int m);
void showMatrix(int** matrix, const int m, const int n);
bool isNegative(int** matrix, const int n, int row_index);
void moveRow(int** matrix, int row_index, const int m, const int n);

int main()
{
	setlocale(LC_ALL, "Rus");
	int n, m;
	cout << "Введите кол-во строк: ";
	cin >> m;

	cout << "Введите кол-во столбцов: ";
	cin >> n;

	int** matrix = newMatrix(m, n);
	showMatrix(matrix, m, n);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (isNegative(matrix, n, i))
			{
				moveRow(matrix, i, m, n);
				j = 0;
			}
		}
	}
	showMatrix(matrix, m, n);
	deleteMatrix(matrix, m);
	system("pause");
	return 0;
}

int** newMatrix(const int m, const int n)
{
	srand(time(0));
	int** matrix = new int* [m];
	for (int i = 0; i < m; i++)
	{
		matrix[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			matrix[i][j] = -3 + rand() % 12;
		}
	}
	return matrix;
}

void deleteMatrix(int** matrix, const int m)
{
	for (int i = 0; i < m; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}

void showMatrix(int** matrix, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << matrix[i][j] << '\t';
		}
		cout << endl;
	}
	cout << endl;
}

bool isNegative(int** matrix, const int n, int row_index)
{
	for (int j = 0; j < n; ++j)
		if (matrix[row_index][j] < 0)
			return true;
	return false;
}
void moveRow(int** matrix, int row_index, const int m, const int n)
{
	int temp;
	for (int j = 0; j < n; j++)
	{
		matrix[row_index][j] = 0;
	}
	if (row_index == m - 1) { return; }

	for (int i = row_index; i < m - 1; i++)
	{
		for (int j = 0; j < n; j++)
		{
			temp = matrix[i][j];
			matrix[i][j] = matrix[i + 1][j];
			matrix[i + 1][j] = temp;
		}
	}


}
