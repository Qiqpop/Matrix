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
				cin >> arr[i][j];
			}
		}
		Matrix matrix1(n, m, arr);
		for (int i = 0; i < n; i++) {
			cin >> arr[i][0];
		}
		Matrix matrix2(n, 1, arr);
		Matrix matrix3(Gauss(matrix1, matrix2));
		matrix3.printMatrix();
		return 0;
	}
	catch (int) {
		cout << "Произошла ошибка" << endl;
		return 1;
	}
}