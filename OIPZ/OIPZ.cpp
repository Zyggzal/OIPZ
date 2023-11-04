#include <iostream>
#include<fstream>
using namespace std;

int main() {
	double y = 0;
	int n;

	int min, max;
	int h;
	cout << "Enter n: ";
	cin >> n;

	cout << "Enter the boundaries(min; max): ";
	cin >> min >> max;

	cout << "Enter step: ";
	cin >> h;

	for (int x = min; x <= max; x += h) {
		cout << "With x = " << x << " ";
		if (x < 0) {
			y = 0;
			if (n >= 1) {

				for (int i = 1; i <= n; i++) {
					for (int j = 1; j <= n; j++) {
						y += 1.0 / (x - i - j);
					}
				}
				cout << "y = " << y << endl;
			}
			else {
				cout << "ERROR: n can't be less than 0\n";
			}
		}
		else {
			y = 1;
			if (n - 3 >= 0) {
				for (int i = 0; i <= n - 3; i++) {
					y *= (x - i);
				}
				cout << "y = " << y << endl;
			}
			else {
				cout << "ERROR: n - 3 can't be less than 0\n";
			}
		}
	}
}
