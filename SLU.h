#include "Matrix.h"
#include <cmath>



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
			double temp = tmp[k][i];
			tmp[k][i] = tmp[maxi][i];
			tmp[maxi][i] = temp;
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
	for (int i = 0; i < height; i++) {
		tmp[i][0] = tmp[i][width - 1];
	}
	Matrix matrix(height, 1, tmp);
	return matrix;
}

double signum(double x) {
	if (x > 0) return 1;
	else if (x < 0) return -1;
	else return 0;
}

Matrix SquareRoots(Matrix A, Matrix B) {
	int n = A.getWidth();
	double** a = new double*[n + 1];
	for (int i = 0; i <= n; i++) {
		a[i] = new double[n + 1];
	}
	double* b = new double[n + 1];

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			a[i][j] =  A.getElement(i-1, j-1);
		}
		b[i] = B.getElement(i-1,0);
	}

	double* x = new double[n + 1];

	double* d = new double[n + 1];
	double** s = new double*[n + 1];
	for (int i = 0; i <= n; i++) {
		s[i] = new double[n + 1];
	}

	//Находим 1 строку матрицы Uт
	d[1] = signum(a[1][1]);
	s[1][1] = sqrt(abs(a[1][1]));
	for (int j = 2; j <= n; j++) {
		s[1][j] = a[1][j] / (s[1][1] * d[1]);
	}

	//Находим верхне треугольную матрицу Uт
	for (int i = 2; i <= n; i++) {
		double sum = 0;
		for (int k = 1; k <= i - 1; k++) {
			sum += s[k][i] * s[k][i] * d[k];
		}
		d[i] = signum(a[i][i] - sum);
		s[i][i] = sqrt(abs(a[i][i] - sum));

		double l = 1 / (s[i][i] * d[i]);
		for (int j = i + 1; j <= n; j++) {
			double SDSsum = 0;
			for (int k = 1; k <= i - 1; k++) {
				SDSsum += s[k][i] * d[k] * s[k][j];
			}
			s[i][j] = l * (a[i][j] - SDSsum);
		}
	}


	double* y = new double[n + 1];
	y[1] = b[1] / (s[1][1] * d[1]);

	//Прямой ход, нахождения вектора y
	for (int i = 2; i <= n; i++) {
		double sum = 0;

		for (int j = 1; j <= i - 1; j++) {
			sum += s[j][i] * d[j] * y[j];
		}

		y[i] = (b[i] - sum) / (s[i][i] * d[i]);
	}


	x[n] = y[n] / s[n][n];

	//Обратный ход, нахождение ответа, вектора x
	for (int i = n - 1; i >= 1; i--) {
		double sum = 0;

		for (int k = i + 1; k <= n; k++) {
			sum += s[i][k] * x[k];
		}

		x[i] = (y[i] - sum) / s[i][i];
	}
	double** tmp = new double* [n + 1];
	for (int i = 0; i <= n; i++) {
		tmp[i] = new double[n + 1];
	}
	for (int i = 1; i <= n; i++)
	{
		tmp[i-1][0] = x[i];
	}
	Matrix matrix(n, 1, tmp);
	delete[]tmp;
	return matrix;
}

double normaX(Matrix X) {
	double sum = 0;
	for (int i = 0; i < X.getHeight(); i++) {
		sum += abs(X.getElement(i, 0));
	}
	return sqrt(sum);
}

Matrix SimpleIteration(Matrix A, Matrix B, double eps) {
	int height = A.getHeight();
	for (int i = 0; i < height; i++) {
		double sum = 0;
		for (int j = 0; j < height; j++) {
			if (j != i) {
				sum += abs(A.getElement(i, j));
			}
		}
		if (sum > abs(A.getElement(i, i))) {
			throw -1;
		}
	}
	double** c = new double* [height];
	for (int i = 0; i < height; i++) {
		c[i] = new double[height];
	}
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < height; j++)
		{
			c[i][j] = -(A.getElement(i, j) / A.getElement(i, i));
		}
		c[i][i] = 0;
	}
	double** d = new double*[height];
	for (int i = 0; i < height; i++) {
		d[i] = new double[height];
	}
	for (int i = 0; i < height; i++)
	{
		d[i][0] = B.getElement(i, 0)/A.getElement(i, i);
	}
	Matrix C(height, height, c);
	Matrix D(height, 1, d);
	Matrix X0 = B;
	Matrix X1 = C * X0 + D;
	while (abs(normaX(X0) - normaX(X1)) > eps)
	{
		X0 = X1;
		X1 = C * X0 + D;
	}
	return X1;
}

double TMNN(Matrix R0, Matrix Ar0) {
	int n = R0.getHeight();
	double t1 = 0, t2 = 0;
	for (int i = 0; i < n; i++) {
		t1 += R0.getElement(i, 0) * Ar0.getElement(i, 0);
	}
	for (int i = 0; i < n; i++) {
		t2 += Ar0.getElement(i, 0) * Ar0.getElement(i, 0);
	}
	return t1 / t2;
}

double norma(Matrix X) {
	int n = X.getHeight();
	double sum = 0;
	for (int i = 0; i < n; i++) {
		sum += X.getElement(i, 0) * X.getElement(i, 0);
	}
	return sqrt(sum);
}

Matrix MMN(Matrix A, Matrix B, double eps) {
	int n = A.getHeight();
	int iter = 1;

	Matrix X0(B);
	Matrix R0 = A * B;
	R0 = R0 - B;
	Matrix Ar0 = A * R0;
	double T1 = 0;
	T1 = TMNN(R0, Ar0);
	Matrix TAr0 = Ar0 * T1;
	Matrix R1 =  R0 - TAr0;
	do {
		R0 = R1;
		iter++;
		Ar0 = A * R0;
		T1 = TMNN(R0, Ar0);
		TAr0 = Ar0 * T1;
		R1 = R0 - TAr0;
	} while (norma(R1) > eps);
	std::cout << iter << std::endl;
	return R1;
}

double TMSS(Matrix R0, Matrix Ar0) {
	int n = R0.getHeight();
	double t1 = 0, t2 = 0;
	for (int i = 0; i < n; i++) {
		t1 += R0.getElement(i, 0) * R0.getElement(i, 0);
	}
	for (int i = 0; i < n; i++) {
		t2 += Ar0.getElement(i, 0) * R0.getElement(i, 0);
	}
	return t1 / t2;
}

Matrix MSS(Matrix A, Matrix B, double eps) {
	int n = A.getHeight();
	int iter = 1;

	Matrix X0(B);
	Matrix R0 = A * B;
	R0 = R0 - B;
	Matrix Ar0 = A * R0;
	double T1 = 0;
	T1 = TMSS(R0, Ar0);
	Matrix TAr0 = Ar0 * T1;
	Matrix R1 = R0 - TAr0;
	do {
		R0 = R1;
		iter++;
		Ar0 = A * R0;
		T1 = TMSS(R0, Ar0);
		TAr0 = Ar0 * T1;
		R1 = R0 - TAr0;
	} while (norma(R1) > eps);
	std::cout << iter << std::endl;
	return R1;
}