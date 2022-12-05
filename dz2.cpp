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

int** newTransposeMatrix(int** matrix, const int n)
{
	int** transp_matrix = new int* [n];
	for (int i = 0; i < n; i++)
	{
		transp_matrix[i] = new int[n];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			transp_matrix[i][j] = matrix[n - j - 1][i];
		}
	}
	return transp_matrix;
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
}

bool isSymmetry(int** matrix1, int** matrix2, const int n)
{
	bool flag = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (matrix1[i][j] != matrix2[i][j])
				return false;
		}
	}
	return true;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	int n;

	cout << "Введите размер квадратной матрицы: ";
	cin >> n;

	int** matrix = newMatrix(n);
	int** transpose_matrix = newTransposeMatrix(matrix, n);
	showMatrix(matrix, n);
	cout << endl;
	showMatrix(transpose_matrix, n);

	if (isSymmetry(matrix, transpose_matrix, n))
	{
		cout << "Матрицы симметричны" << endl;
	}
	else cout << "Матрицы не симметричны" << endl;
	deleteMatrix(matrix, n);
	deleteMatrix(transpose_matrix, n);

	system("pause");
	return 0;
}
