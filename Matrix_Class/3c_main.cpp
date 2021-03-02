#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;
class matrix
{
	public:
		int **allocatespace(int, int);
	int **readMatrix(int **, int, int);
	void displayMatrix(int **, int, int);
	void addMatrix(int **, int **, int **, int, int, int, int);
	void multMatrix(int **, int **, int **, int, int, int, int);
	int detMatrix(matrix, int **, int);
	int **cofactor(matrix, int **, int, int);
	int **numr_matrix(matrix, int **, int *, int, int);
	void CramerRule(matrix, int **, int);
	void getdata();
};
void matrix::getdata()
{
	int a, b;
	cin >> a;
	cin >> b;
}

int **matrix::cofactor(matrix m8, int **t, int index, int s)
{
	int **c = m8.allocatespace((s - 1), (s - 1));
	int ci = 0, cj = 0;
	int i, j;
	for (i = 1; i < s; i++)
	{
		cj = 0;
		for (j = 0; j < s; j++)
		{
			if (j != index)
				c[ci][cj++] = t[i][j];
		}

		ci++;
	}

	return c;
}

int **matrix::allocatespace(int r, int c)
{
	int **arr;
	arr = new int *[r];
	for (int i = 0; i < r; i++)
	{
		arr[i] = new int[c];
	}

	return arr;
}

int **matrix::readMatrix(int **d, int r, int c)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			d[i][j] = rand() % 10;
		}
	}

	return d;
}

void matrix::displayMatrix(int **e, int r, int c)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << setw(5) << e[i][j];
		}

		cout << endl;
	}
}

void matrix::addMatrix(int **k, int **l, int **s, int r1, int c1, int r2, int c2)
{
	if (r1 != r2 && c1 != c2)
	{
		cout << "addtion can't be performed" << endl;
	}
	else
	{
		for (int i = 0; i < r1; i++)
		{
			for (int j = 0; j < c1; j++)
			{
				s[i][j] = k[i][j] + l[i][j];
				cout << setw(5) << s[i][j];
			}

			cout << endl;
		}
	}
}

void matrix::multMatrix(int **n, int **l, int **s, int r1, int c1, int r2, int c2)
{
	if (c1 != r2)
	{
		cout << "multiplication can't be performed" << endl;
	}
	else
	{
		for (int i = 0; i < r1; i++)
		{
			for (int j = 0; j < c2; j++)
			{
				for (int k = 0; k < c1; k++)
				{
					s[i][j] += n[i][k] *l[k][j];
				}

				cout << setw(10) << s[i][j];
			}

			cout << endl;
		}
	}
}

int matrix::detMatrix(matrix m, int **l, int r1)
{
	if (r1 == 1)
		return l[0][0];
	else if (r1 == 2)
		return ((l[0][0] *l[1][1]) - (l[0][1] *l[1][0]));
	else
	{
		int res = 0, i = 0;
		for (int j = 0; j < r1; j++)
		{
			int **cofMat = m.cofactor(m, l, j, r1);
			res += (pow(-1, (i + j)) *l[0][j] *(m.detMatrix(m, cofMat, (r1 - 1))));
		}

		return res;
	}
}

int **matrix::numr_matrix(matrix A1, int **A, int *C, int n, int index)
{
	int **N = A1.allocatespace(n, n);
	int ni = 0, nj = 0;
	for (int i = 0; i < n; i++)
	{
		nj = 0;
		for (int j = 0; j < n; j++)
		{
			if (i == index)
				N[nj++][ni] = C[j];
			else
				N[nj++][ni] = A[j][i];
		}

		ni++;
	}

	return N;
}

void matrix::CramerRule(matrix A1, int **A, int n)
{
	int *C = new int[n];
	cout << "elements of c are" << endl;
	for (int i = 0; i < n; i++)
	{
		C[i] = rand() % 10;
		cout << setw(5) << C[i] << " ";
	}

	cout << endl;
	int D = A1.detMatrix(A1, A, n);
	cout << "determinant is " << D << endl;
	int *Dx = new int[n];
	float x;
	cout << "\nThe values Xi's are : \n";
	for (int i = 0; i < n; i++)
	{
		int **num_Mat = A1.numr_matrix(A1, A, C, n, i);
		Dx[i] = A1.detMatrix(A1, num_Mat, n);
		x = float(Dx[i]) / D;
		cout << setw(5) << "X" << i << " = " << x << endl;
	}
}

int main()
{
	matrix m1;
	matrix m2;
	matrix m;
	matrix m3;
	matrix A1;
	int **mat1;
	int **mat2;
	int **mat3;
	int **mat4;
	int **sum;
	int **mult;
	int **A;
	int **A2;
	int choice, a, b, x, y, det;
	cout << "enter rows of matrix 1:" << endl;
	cin >> a;
	cout << "enter columns of matrix 1:" << endl;
	cin >> b;
	cout << "enter rows of matrix 2:" << endl;
	cin >> x;
	cout << "enter columns of matrix 2:" << endl;
	cin >> y;
	mat1 = m1.allocatespace(a, b);
	cout << "allocation successful for matrix 1" << endl;
	mat3 = m2.allocatespace(x, y);
	cout << "allocation successful for matrix 2" << endl;
	sum = m.allocatespace(a, b);
	cout << "allocation successful for matrix sum" << endl;
	mult = m3.allocatespace(a, y);
	cout << "allocation successful for matrix multiplication" << endl;
	do {
		cout << "0-exit" << endl;
		cout << "1-read matrix" << endl;
		cout << "2-display matrix" << endl;
		cout << "3-adding matrices" << endl;
		cout << "4-multiplying matrices" << endl;
		cout << "5-determinant" << endl;
		cout << "6-finding solutions" << endl;
		cout << "Enter your choice:";
		cin >> choice;
		switch (choice)
		{
			
			case 0:
				break;
			case 1:
				
				mat2 = m1.readMatrix(mat1, a, b);
				cout << " inputs successfull for matrix 1" << endl;

				mat4 = m2.readMatrix(mat3, x, y);
				cout << " inputs successfull for matrix 2" << endl;
				break;
			case 2:
				cout << "elements of 1st matrix:" << endl;
				m1.displayMatrix(mat2, a, b);
				cout << "elements of 2nd matrix:" << endl;
				m2.displayMatrix(mat4, x, y);
				break;
			case 3:
				m.addMatrix(mat2, mat4, sum, a, b, x, y);
				break;
			case 4:
				m3.multMatrix(mat2, mat4, mult, a, b, x, y);
				break;
			case 5:
				if (a != b)
					cout << "determinant can't be found" << endl;
				else
					det = m1.detMatrix(m1, mat2, a);
				cout << "determinant of matrix 1 is " << det << endl;
				if (x != y)
					cout << "determinant can't be found" << endl;
				else
					det = m2.detMatrix(m2, mat4, x);
				cout << "determinant of matrix 2 is " << det << endl;
				break;
			case 6:
				int n;
				cout << "enter number of linear equations" << endl;
				cin >> n;
				A2 = A1.allocatespace(n, n);
				cout << "allocated space successfully for A" << endl;
				A = A1.readMatrix(A2, n, n);
				cout << "taken inputs successfully for A" << endl;
				A1.displayMatrix(A, n, n);
				A1.CramerRule(A1, A, n);
				break;
		}
	} while (choice != 0);
	return 0;
}
