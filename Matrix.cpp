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

Matrix& operator*(double x, Matrix& obj)
{
	double** arr = createArr(obj.height, obj.width);
	for (int i = 0; i < obj.height; i++) {
		for (int j = 0; j < obj.width; j++) {
			arr[i][j] = obj.matrix[i][j] * x;
		}
	}
	Matrix matrix(obj.height, obj.width, arr);
	return matrix;
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

Matrix::Matrix(const Matrix& obj) {
	height = obj.height;
	width = obj.width;
	matrix = createArr(height, width);
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			matrix[i][j] = obj.matrix[i][j];
		}
	}
}

//Matrix::~Matrix() {
//	for (int i = 0; i < height; i++) {
//		delete[]matrix[i];
//	}
//	delete[]matrix;
//}

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

Matrix& Matrix::transposition() {
	double** arr = createArr(width, height);
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			arr[i][j] = this->matrix[j][i];
		}
	}
	Matrix matrix(width, height, arr);
	return matrix;
}

Matrix& Matrix::operator+(Matrix& obj) {
	double** arr = createArr(height, width);
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			arr[i][j] = this->matrix[i][j] + obj.matrix[i][j];
		}
	}
	Matrix matrix(height, width, arr);
	return matrix;
}

Matrix& Matrix::operator-(Matrix& obj) {
	double** arr = createArr(height, width);
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			arr[i][j] = this->matrix[i][j] - obj.matrix[i][j];
		}
	}
	Matrix matrix(height, width, arr);
	return matrix;
}

Matrix& Matrix::operator*(Matrix& obj) {
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
					res += this->matrix[i][k] * obj.matrix[k][j];
					k++;
				}
				arr[i][j] = res;
			}
		}
		Matrix matrix(height, obj.width, arr);
		return matrix;
	}
}

Matrix& Matrix::operator*(double x)
{
	double** arr = createArr(height, width);
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			arr[i][j] = this->matrix[i][j] * x;
		}
	}
	Matrix matrix(height, width, arr);
	return matrix;
}

int Matrix::getHeight()
{
	return height;
}

int Matrix::getWidth()
{
	return width;
}

double Matrix::getElement(int i, int j)
{
	return this->matrix[i][j];
}

void Matrix::setElement(int i, int j, double x)
{
	matrix[i][j] = x;
}
