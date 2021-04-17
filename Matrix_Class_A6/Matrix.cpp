#include "Matrix.h"
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

Matrix::Matrix(): rows{}, columns{}, ptr{nullptr}
{}
Matrix::Matrix(int m, int n): rows{m}, columns{n}
{
    ptr = new float*[rows];

    for(int i=0; i<rows; i++)
        ptr[i] = new float[columns];

}

Matrix::Matrix(const Matrix &obj) : Matrix(obj.rows, obj.columns)   // Use of delegating constructor
{
    for(int i=0; i<obj.rows; i++)
        for(int j=0; j<obj.columns; j++)
            ptr[i][j] = *(*(obj.ptr + i) + j);

}

Matrix::~Matrix()
{
    for(int i=0; i<rows; i++)
        delete[] ptr[i];

    delete[] ptr;
}

Matrix Matrix::operator+(const Matrix &obj) const
{
    Matrix Sum(rows, columns);

    for(int i=0; i<rows; i++)
        for(int j=0; j<columns; j++)
            *(*(Sum.ptr + i) + j) = ptr[i][j] + *(*(obj.ptr + i) + j);

    return Sum;
}

Matrix Matrix::operator-(const Matrix &obj) const
{
    Matrix Diff(rows, columns);

    for(int i=0; i<rows; i++)
        for(int j=0; j<rows; j++)
            *(*(Diff.ptr + i) + j) = ptr[i][j] - *(*(obj.ptr + i) + j);

    return Diff;
}

Matrix Matrix::operator*(const Matrix &obj) const
{
    Matrix Pro(rows, columns);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            *(*(Pro.ptr + i) + j) = 0;
            for (int k = 0; k < columns; k++)
            {
                *(*(Pro.ptr + i) + j) += ptr[i][k] * *(*(obj.ptr + k) + j);
            }
        }
    }

    return Pro;
}

Matrix Matrix::operator/(Matrix &obj) const
{
    return (*this) * (!obj);
}

Matrix Matrix::operator!()
{
    float det = determinant(ptr, rows);

    float **adj = new float *[rows];

    for(int i=0; i<rows ;i++)
        adj[i] = new float;

    AdjointMatrix(ptr, adj, rows);

    Matrix inverseMat(rows,rows);

    for (int i=0; i<rows; i++)
        for (int j=0; j<rows; j++)
            inverseMat.ptr[i][j] = adj[i][j]/float(det);

    for(int i=0; i<rows; i++)
        delete[] adj[i];

    delete[] adj;

    return inverseMat;
}

bool Matrix::operator==(const Matrix &obj) const
{
    if(rows != obj.rows or columns != obj.columns)
        return false;

    bool flag = true;

    for(int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
            if (ptr[i][j] != *(*(obj.ptr + i) + j)) {
                flag = false;
                break;
            }

        if(!flag)
            break;
    }

    return flag;
}

float Matrix::operator[](std::pair<int, int> &p)
{
    if((p.first - 1) > rows and (p.second - 1) > columns)
    {
            cout << "Array index out of bounds!";
            return -1;
    }
    return ptr[p.first - 1][p.second - 1];
}

Matrix &Matrix::operator=(const Matrix &obj)
{
    if(this != &obj)
    {
        if(ptr)
        {
            for(int i=0; i<rows; i++)
                delete[] ptr[i];

            delete[] ptr;

            ptr = nullptr;
        }

        rows = obj.rows;
        columns = obj.columns;

        ptr = new float*[rows];

        for(int i=0; i<rows; i++)
            ptr[i] = new float[columns];


        for(int i=0; i<rows; i++)
            for(int j=0; j<columns; j++)
                ptr[i][j] = *(*(obj.ptr + i) + j);
    }

    return *this;
}

ostream &operator<<(ostream &output, Matrix const &obj)
{
    for(int i=0; i<obj.rows; i++)
    {   output << "[ ";
        for(int j=0; j<obj.columns; j++)
            output << *(*(obj.ptr + i) + j) << " ";
        output << "]"<<endl;
    }

    return output;
}

istream &operator>>(istream &input, Matrix &obj)
{

    if(obj.ptr)
    {
        for(int i=0; i<obj.rows; i++)
            delete[] obj.ptr[i];

        delete[] obj.ptr;
        obj.ptr = nullptr;
    }

    int m, n;
    cout << "Enter number of rows:";  input >> m;
    cout << "Enter number of columns:";   input>> n;

    obj.rows = m;
    obj.columns = n;

    obj.ptr = new float*[obj.rows];

    for(int i=0; i<obj.rows; i++)
        obj.ptr[i] = new float[obj.columns];


    cout << "Enter the elements:" << endl;
    for(int i=0; i<obj.rows; i++)
    {
        for(int j=0; j<obj.columns; j++)
            input >> *(*(obj.ptr + i) + j);
    }

    return input;
}

float Matrix::determinant(float **CurrentMat, int n)//determinant of matrix
{
    float Det = 0;
    if (n == 1)
        return CurrentMat[0][0];

    float **temp = new float* [n];
    for(int i=0; i<n ;i++)
        temp[i]=new float;

    int sign = 1;
    for (int i = 0; i < n; i++)
    {
        CofactorMatrix(CurrentMat, temp, 0, i, n);
        Det += (float)sign * CurrentMat[0][i] * determinant(temp, n - 1);
        sign = -sign;
    }

    return Det;
}

void Matrix::CofactorMatrix(float **CurrentMat, float **CofactMat, int p, int q, int n)//finds cofactor matrix
{
    int i = 0, j = 0;

    for (int r = 0; r < n; r++)
        for (int c = 0; c < n; c++)
            if (r != p && c != q)
            {
                CofactMat[i][j++] = CurrentMat[r][c];
                if (j == n - 1)
                {
                    j = 0;
                    i++;
                }
            }
}

void Matrix::AdjointMatrix(float **CurrentMat,float **AdjMat,int size)//finds adjoint matrix
{
    if (size == 1)
    {
        AdjMat[0][0] = 1;
        return;
    }
    int sign = 1;
    float ** temp= new float *[size];

    for(int i=0; i<size ;i++)
        temp[i]=new float;

    for (int i=0; i<size; i++)
    {
        for (int j=0; j<size; j++)
        {
            CofactorMatrix(CurrentMat, temp, i, j, size);
            if((i+j)%2)
            {
                sign=-1;
            }
            else{
                sign=1;
            }
            AdjMat[j][i] = (sign)*(determinant(temp, size-1));
        }
    }
}