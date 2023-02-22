class Matrix
{
public:
	friend double** createArr(int n, int m);
	Matrix(int n, int m, double** arr);
	Matrix(Matrix& obj);
	//~Matrix();
	void printMatrix();
	void rearrangingColumns(int a, int b);
	void rearrangingRows(int a, int b);
	Matrix& transposition();
	Matrix& operator+(Matrix& obj);
	Matrix& operator-(Matrix& obj);
	Matrix& operator*(Matrix& obj);
	Matrix& operator*(double x);
	friend Matrix& operator*(double x, Matrix& matrix);
private:
	int height;
	int width;
	double** matrix;
};
