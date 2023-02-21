class Matrix
{
public:
	friend double** createArr(int n, int m);
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
