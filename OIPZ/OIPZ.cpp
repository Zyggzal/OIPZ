#include <iostream>
#include<fstream> //Біліотека для роботи з файлами
using namespace std;


//Введення користувачем даних було реалізовано функцією
bool RequestInput(int& min, int& max, int& h, int& n) {
	cout << "Enter n: ";
	cin >> n;

	cout << "Enter the boundaries(min; max): ";
	cin >> min >> max;
	if (min > max) { swap(min, max); }

	cout << "Enter step: ";
	cin >> h;

	if (h > 0) { return true; }
	else { cout << "Step can't be less than one!"; return false; }
}
//Функція знаходження значення Y відповідно формулі
double Task5(int x, int n, bool& error) {
	double y = 0;
	if (x < 0) {
		if (n >= 1) {

			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					y += 1.0 / (x - i - j);
				}
			}

			return y;
		}
		else {
			cout << "ERROR: n can't be less than 0\n";
			error = true;
			return 0;
		}
	}
	else {
		y = 1;
		if (n - 3 >= 0) {
			for (int i = 0; i <= n - 3; i++) {
				y *= (x - i);
			}
			return y;
		}
		else {
			cout << "ERROR: n - 3 can't be less than 0\n";
			error = true;
			return 0;
		}
	}
}
//Функція виведення результатів до консолі та внесення даних до файлу
void PrintLoop(int min, int max, int h, int n) {
	double y = 0;
	bool stop = false;
	ofstream o("oipz.txt"); //Файл відкривається

	for (int x = min; x <= max; x += h) {
		y = Task5(x, n, stop);
		if (!stop) {
			cout << "With x = " << x << " y = " << y << endl;
			o << "(" << x << ";" << y << ")\n"; //Дані записуються до файла
		}
		else {
			return;
		}
	}
	o.close(); //Файл закривається
}

int main() {
	int n;
	int min, max;
	int h;

	if (RequestInput(min, max, h, n)) {
		PrintLoop(min, max, h, n);
	}
}