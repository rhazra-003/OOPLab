#ifndef PROJ1_MATRIX_H
#define PROJ1_MATRIX_H
#include <iostream>

class Matrix {
    
    int rows, columns;
    float **ptr;

    float determinant(float **A, int n);
    void CofactorMatrix(float **A, float **temp, int p, int q, int n);
    void AdjointMatrix(float **A,float **adj,int size);

public:
    Matrix();
    Matrix(int, int);
    Matrix(const Matrix &obj);
    ~Matrix();

    Matrix operator+ (const Matrix&) const;
    Matrix operator- (const Matrix&) const;
    Matrix operator* (const Matrix&) const;
    Matrix operator/ (Matrix&) const;
    Matrix operator! ();

    bool operator==(const Matrix&) const;

    float operator[](std::pair<int,int> &);
    Matrix &operator= (const Matrix&);

    friend std::ostream &operator<<(std::ostream &output, Matrix const&);
    friend std::istream &operator>>(std::istream &input, Matrix &);
};

#endif //PROJ1_MATRIX_H
