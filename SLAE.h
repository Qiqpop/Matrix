#include "Matrix.h"

Matrix Gauss(Matrix A, Matrix B) {
	int height = A.getHeight();
	int width = A.getWidth() + 1;
		double** tmp = new double* [height];
	for (int i = 0; i < height; i++) {
		tmp[i] = new double[width];
	}
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			tmp[i][j] = A.getElement(i, j);
		}
	}
	for (int i = 0; i < height; i++) {
		tmp[i][width - 1] = B.getElement(i, 0);
	}


	int k = 0;
	do {
		double max = tmp[k][k];
		int maxi = k;
		for (int i = k; i < height; i++) {
			if (tmp[i][k] > max) {
				max = tmp[i][k];
				maxi = i;
			}
		}
		for (int i = 0; i < width; i++) {
			std::swap(tmp[k][i], tmp[maxi][i]);
		}
		double element = tmp[k][k];
		for (int i = 0; i < width; i++) {
			tmp[k][i] /= element;
		}
		for (int i = k + 1; i < height; i++) {
			int j = k;
			element = -tmp[i][j];
			for (; j < width; j++) {
				tmp[i][j] += tmp[k][j] * element;
			}
		}
		k++;
	} while (k < height);


	k--;
	do {
		for (int i = k - 1; i >= 0; i--) {
			int j = k;
			double element = -tmp[i][j];
			for (; j < width; j++) {
				tmp[i][j] += tmp[k][j] * element;
			}
		}
		k--;
	} while (k > 0);
	Matrix matrix(height, width, tmp);
	return matrix;
}