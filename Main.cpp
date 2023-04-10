#include <iostream>
#include "SLU.h"

using namespace std;

int main() {
		setlocale(0, "ru");
	try {
		/*
		3 3
		2.45 1.75 -3.24
		1.75 -1.16 2.18
		-3.24 2.18 -1.85

		1.23
		3.43
		-0.16
		*/
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
		Matrix matrix3 = Gauss(matrix1,matrix2);
		Matrix matrix4 = SquareRoots(matrix1, matrix2);
		matrix3.printMatrix();
		matrix4.printMatrix();
		return 0;
	}
	catch (int) {
		cout << "Произошла ошибка" << endl;
		return 1;
	}
}