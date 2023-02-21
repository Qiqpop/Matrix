#include "Matrix.h"
#include <iostream>

double** createArr(int n, int m)
{
	double** arr = new double* [n];
	for (int i = 0; i < n; i++) {
		arr[i] = new double[m];
	}
	return arr;
}

Matrix::Matrix(int n, int m, double** arr) {
	height = n;
	width = m;
	matrix = createArr(height, width);
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			matrix[i][j] = arr[i][j];
		}
	}
}

Matrix::Matrix(Matrix& obj) {
	height = obj.height;
	width = obj.width;
	matrix = createArr(height, width);
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
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			std::cout << matrix[i][j] << ' ';
		}
		std::cout << std::endl;
	}
}

void Matrix::rearrangingColumns(int a, int b) {
	for (int i = 0; i < height; i++) {
		std::swap(matrix[i][a], matrix[i][b]);
	}
}

void Matrix::rearrangingRows(int a, int b) {
	for (int i = 0; i < width; i++) {
		std::swap(matrix[a][i], matrix[b][i]);
	}
}

double** Matrix::transposition() {
	double** arr = createArr(width, height);
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			arr[i][j] = matrix[j][i];
		}
	}
	return arr;
}

double** Matrix::operator+(Matrix& obj) {
	double** arr = createArr(height, width);
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			arr[i][j] = matrix[i][j] + obj.matrix[i][j];
		}
	}
	return arr;
}

double** Matrix::operator-(Matrix& obj) {
	double** arr = createArr(height, width);
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			arr[i][j] = matrix[i][j] - obj.matrix[i][j];
		}
	}
	return arr;
}

double** Matrix::operator*(Matrix& obj) {
	if (width != obj.height) {
		std::cout << "Умножение не возможно" << std::endl;
		throw - 1;
	}
	else {
		double** arr = createArr(height, obj.width);
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
	double** arr = createArr(height, width);
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			arr[i][j] = matrix[i][j] * x;
		}
	}
	return arr;
}
