#include <iostream>
#include "Matrix.h"

using namespace std;

int main() {
		setlocale(0, "ru");
	try {
		int n, m;
		cin >> n >> m;
		double** arr = new double* [n];
		for (int i = 0; i < n; i++) {
			arr[i] = new double[m];
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				arr[i][j] = i + j;
			}
		}
		Matrix matrix1(n, m, arr);
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			delete[]arr[i];
		}
		delete[]arr;
		arr = new double* [n];
		for (int i = 0; i < n; i++) {
			arr[i] = new double[m];
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				arr[i][j] = i + j;
			}
		}
		Matrix matrix2(n, m, arr);
		for (int i = 0; i < n; i++) {
			delete[]arr[i];
		}
		delete[]arr;
		Matrix matrix3(5 * matrix2);
		matrix2.printMatrix();
		matrix3.printMatrix();
		return 0;
	}
	catch (int) {
		cout << "Произошла ошибка" << endl;
		return 1;
	}
}