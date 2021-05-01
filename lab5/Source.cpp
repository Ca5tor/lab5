#include <iostream>
#include <iomanip>

double f(double x) {
	return (x * sin(x + 1) - cos(x - 5));
}

// Схема алгоритма м.золотого сечения
void Gold(double a, double b, double E) {

	double k2 = (std::sqrt(5) - 1) / 2;
	double k1 = 1 - k2;

	double x1 = a + k1 * (b - a);
	double x2 = a + k2 * (b - a);

	// Процедура вычисления целевой функции
	double F1 = f(x1);
	double F2 = f(x2);
	int N = 0;
	std::cout << "N \t a \t b \t x1 \t x2 \t f(x1) \t f(x2)\n";
	while ((b - a) > E) {
		
		if (F1 < F2) {
			b = x2;
			x2 = x1;
			F2 = F1;

			x1 = a + k1 * (b - a);
			F1 = f(x1);
		}
		else {
			a = x1;
			x1 = x2;
			F1 = F2;

			x2 = a + k2 * (b - a);
			F2 = f(x2);
		}

		N++;
		std::cout<<std::setprecision(5) << N <<"\t" << a << "\t" << b << "\t" << x1 << "\t" << x2 << "\t" << F1 << "  " << F2 << std::endl;
		
	}

	double x = (a + b) / 2;
	double y = f(x);
	std::cout << "\nКоординаты точки минимума на отрезке [3.5,4.5]\n";
	std::cout << "X= " << x << "\tY= " << y << std::endl;
}
void main() {
	setlocale(0, "");
	double a = 3.5, b = 4.5; // Границы отрезка неопределенности
	double E = 0.0001; 
	Gold(a, b, E); // Вызов функции м.золотого сечения
	system("pause");
}