#include <iostream>

using namespace std;


char** createListWords(char* row)
{
	char** words = new char* [255];
	for (int i = 0; i < 255; i++)
	{
		words[i] = new char[255];
	}

	char letter;
	int i = 0, j = 0;
	while (*row != '\0')
	{
		letter = *row;
		if (letter == ' ')
		{
			words[i][j] = '\0';
			j = 0;
			i++;
		}
		else
		{
			words[i][j] = letter;
			++j;
		}
		++row;
	}
	words[i][j] = '\0';
	return words;
}
void deleteListWords(char** words)
{
	for (int i = 0; i < 255; i++)
	{
		delete[] words[i];
	}
	delete[] words;
}
bool isTwoWords(char** words)
{
	return strlen(words[0]) != 0 && strlen(words[1]) != 0;
}
void toCrossvord(char* row)
{
	//создание массива слов:
	char** words = createListWords(row);

	//проверка, 2 ли слова в массиве:
	if (!isTwoWords(words)) { cout << "Введено не два слова через пробел!" << endl; return; }

	//2 данных слова и их длина:
	char* str1 = words[0];
	char* str2 = words[1];
	int length1 = strlen(str1);
	int length2 = strlen(str2);

	//Вывод вариантов кроссворда на экран:
	int k = 0;
	for (int i = 0; i < length1; i++)
	{
		for (int j = 0; j < length2; j++)
			if (str1[i] == str2[j])
			{
				for (int p = 0; p < length1; p++)
				{
					for (int q = 0; q < length2; q++)
					{
						if (q == j) cout << str1[p];
						else if (p == i) cout << str2[q];
						else cout << ' ';
					}
					cout << endl;
				}
				cout << endl;
				k += 1;
			}
	}
	if (k == 0) cout << "В ввденых словах нет ни одной одинаковой буквы";

	//Удаление массива слов:
	deleteListWords(words);
}

int main()
{
	setlocale(LC_ALL, "Rus");
	char row[255];
	cout << "Введите два слова через пробел: ";
	cin.getline(row, 255);

	toCrossvord(row);
	
	system("pause");
}
