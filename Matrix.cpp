#include "Matrix.h"
#include <iostream>

using namespace std;

Matrix::Matrix(int n, int m, double** arr) {
	height = n;
	width = m;
	matrix = new double* [height];
	for (int i = 0; i < height; i++) {
		matrix[i] = new double[width];
	}
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			matrix[i][j] = arr[i][j];
		}
	}
}

Matrix::Matrix(Matrix& obj) {
	height = obj.height;
	width = obj.width;
	matrix = new double* [height];
	for (int i = 0; i < height; i++) {
		matrix[i] = new double[width];
	}
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			matrix[i][j] = obj.matrix[i][j];
		}
	}
}

Matrix::~Matrix() {
	for (int i = 0; i < height; i++) {
		delete[]matrix[i];
	}
	delete[]matrix;
}

void Matrix::printMatrix() {
	cout << endl;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			cout << matrix[i][j] << ' ';
		}
		cout << endl;
	}
}

void Matrix::rearrangingColumns(int a, int b) {
	for (int i = 0; i < height; i++) {
		swap(matrix[i][a], matrix[i][b]);
	}
}

void Matrix::rearrangingRows(int a, int b) {
	for (int i = 0; i < width; i++) {
		swap(matrix[a][i], matrix[b][i]);
	}
}

double** Matrix::transposition() {
	double** arr = new double* [width];
	for (int i = 0; i < width; i++) {
		arr[i] = new double[height];
	}
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			arr[i][j] = matrix[j][i];
		}
	}
	return arr;
}

double** Matrix::operator+(Matrix& obj) {
	double** arr = new double* [height];
	for (int i = 0; i < height; i++) {
		arr[i] = new double[width];
	}
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			arr[i][j] = matrix[i][j] + obj.matrix[i][j];
		}
	}
	return arr;
}

double** Matrix::operator-(Matrix& obj) {
	double** arr = new double* [height];
	for (int i = 0; i < height; i++) {
		arr[i] = new double[width];
	}
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			arr[i][j] = matrix[i][j] - obj.matrix[i][j];
		}
	}
	return arr;
}

double** Matrix::operator*(Matrix& obj) {
	if (width != obj.height) {
		cout << "Умножение не возможно" << endl;
		throw - 1;
	}
	else {
		double** arr = new double* [height];
		for (int i = 0; i < height; i++) {
			arr[i] = new double[obj.width];
		}
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < obj.width; j++) {
				double res = 0;
				int k = 0;
				while (k < width) {
					res += matrix[i][k] * obj.matrix[k][j];
					k++;
				}
				arr[i][j] = res;
			}
		}
		return arr;
	}
}

double** Matrix::operator*(double x)
{
	double** arr = new double* [height];
	for (int i = 0; i < height; i++) {
		arr[i] = new double[width];
	}
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			arr[i][j] = matrix[i][j] * x;
		}
	}
	return arr;
}

