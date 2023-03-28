class Matrix
{
public:
	friend double** createArr(int n, int m);
	Matrix(int n = 0, int m = 0, double** arr = {});
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
	int getHeight();
	int getWidth();
	double getElement(int i, int j);
	void setElement(int i, int j, double x);
protected:
	int height;
	int width;
	double** matrix;
};
