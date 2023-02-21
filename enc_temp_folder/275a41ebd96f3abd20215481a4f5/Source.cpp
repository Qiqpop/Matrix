#include <iostream>

using namespace std;

class Matrix
{
public:
	Matrix(int n, int m, double** arr);
	Matrix(Matrix& obj);
	~Matrix();
	void printMatrix();
	void rearrangingColumns(int a, int b);
	void rearrangingRows(int a, int b);
	double** transposition();
	double** operator+(Matrix& obj);
	double** operator-(Matrix& obj);
	double** operator*(Matrix& obj);
	double** operator*(double x);
private:
	int height;
	int width;
	double** matrix;
};

Matrix::Matrix(int n, int m, double** arr) {
	try {
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
	catch (double){
		cout << "Не удалось вывести матрицу" << endl;
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
	int a = -1;
	try {
		if (height != obj.width) {
			throw int(a);
		}
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
	catch (int a) {
		cout << "Ошибка, умножение невозможно!" << endl;
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

int main() {
	setlocale(0, "ru");
	int n, m;
	cin >> n >> m;
	double** arr = new double*[n];
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
		delete[]arr[i];
	}
	delete[]arr;
	int n3 = n;
	cin >> n >> m;
	int m3 = m;
	arr = new double* [n];
	for (int i = 0; i < n; i++) {
		arr[i] = new double[m];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	Matrix matrix2(n, m, arr);
	Matrix matrix3(n3, m3, matrix1 * matrix2);
	matrix3.printMatrix();
	return 0;
}