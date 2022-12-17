#include <iostream>
#include <cmath>
using namespace std;

const double lambda = -0.0714285714;
const double eps = 0.00001;

//изначальная функция
double function(double x)
{
	return pow(x, 3) - 5 * pow(x, 2) + 3 * x + 4;
}
//x = x... (для итераций)
double function_iterations(double x)
{
	return x + lambda * (pow(x, 3) - 5 * pow(x, 2) + 3 * x + 4);
}
//1-ая производная
double der1(double x)
{
	return 3 * pow(x, 2) - 10 * x + 3;
}
//2-ая производная
double der2(double x)
{
	return 6 * x - 10;
}

//метод итераций
double iterations(double a, double b, int &countA)
{
	double x1, x2;
	x1 = a;
	x2 = function_iterations(x1);
	while (abs(x2 - x1) > eps)
	{
		x1 = x2;
		x2 = function_iterations(x1);
		countA += 1;
	}
	return x2;
}

//метод половинного деления
double half_division(double a, double b, int& countB)
{
	double c;
	while (abs(a - b) > eps)
	{
		c = (a + b) / 2;
		if (function(a) * function(c) < 0)
			b = c;
		else a = c;
		countB += 1;
	}
	return (a + b) / 2;
}

//метод Ньютона
double Newton(double a, double b, int& countC)
{
	double x1, x2;
	//для уменьшения кол-ва итераций (выбор начальной точки для касательной)
	if (function(a) * der2(a) > 0)
		x1 = a;
	else x1 = b;
	
	x2 = x1 - function(x1) / der1(x1);
	while (abs(x2 - x1) > eps)
	{
		x1 = x2;
		x2 = x1 - function(x1) / der1(x1);
		countC += 1;
	}
	return x2;
}


int main()
{
	double a, b;
	int countA = 0, countB = 0, countC = 0;
	setlocale(LC_ALL, "Rus");

	cout << "Введите границы интервала для нахождения корня: ";
	cin >> a >> b;

	if (function(a) * function(b) < 0)
	{
		cout << "Метод половинного деления: " << half_division(a, b, countB) << " за кол-во итераций: " << countB << endl;
		cout << "Метод Ньютона: " << Newton(a, b, countC) << " за кол-во итераций: " << countC << endl;
		cout << "Метод итераций: " << iterations(a, b, countA) << " за кол-во итераций: " << countA << endl;
	}
	else
	{
		cout << "Корней на интервале нет!";
	}
}
