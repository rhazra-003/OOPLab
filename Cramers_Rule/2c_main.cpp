#include <bits/stdc++.h>
using namespace std;
 
struct Matrix
{
   double **ptr;
   int n, m;
};
 
void alloc2DArray(Matrix *mat)
{
   mat->ptr = new double *[mat->n];
   for (int i = 0; i < mat->n; ++i)
       mat->ptr[i] = new double[mat->m];
   return;
}
 
void dealloc2DArray(Matrix *mat)
{
   for (int i = 0; i < mat->n; ++i)
       delete[] mat->ptr[i];
}
 
void read2DArray(Matrix *mat)
{
   for (int i = 0; i < mat->n; ++i)
   {
       for (int j = 0; j < mat->m; ++j)
       {
           mat->ptr[i][j] = rand() % 51;
           // cin>>mat->ptr[i][j];
       }
   }
}
 
void display2DArray(Matrix *mat)
{
   for (int i = 0; i < mat->n; ++i)
   {
       for (int j = 0; j < mat->m; ++j)
           cout << mat->ptr[i][j] << ' ';
       cout << endl;
   }
}
 
double det(Matrix *mat)
{
   if (mat->n == 2)
   {
       return mat->ptr[0][0] * mat->ptr[1][1] - (mat->ptr[0][1] * mat->ptr[1][0]);
   }
   double soln = 0;
   for (int col = 0; col < mat->m; ++col)
   {
       Matrix *nxt = new Matrix;
       nxt->n = mat->n - 1;
       nxt->m = mat->m - 1;
       alloc2DArray(nxt);
       for (int i = 1; i < mat->n; ++i)
       {
           for (int j = 0; j < mat->m; ++j)
           {
               if (j == col)
                   continue;
               if (j < col)
                   nxt->ptr[i - 1][j] = mat->ptr[i][j];
               else
                   nxt->ptr[i - 1][j - 1] = mat->ptr[i][j];
           }
       }
       soln += pow(-1, col) * mat->ptr[0][col] * det(nxt);
       dealloc2DArray(nxt);
   }
   return soln;
}
 
void Cramer(Matrix *coeff, Matrix *cnst, Matrix *soln)
{
   double coeff_det = det(coeff);
   Matrix *tmp = new Matrix;
   tmp->n = coeff->n;
   tmp->m = coeff->m;
   alloc2DArray(tmp);
   for (int k = 0; k < soln->m; ++k)
   {
       for (int i = 0; i < coeff->n; ++i)
       {
           for (int j = 0; j < coeff->m; ++j)
           {
               if (j == k)
                   tmp->ptr[i][j] = cnst->ptr[i][0];
               else
                   tmp->ptr[i][j] = coeff->ptr[i][j];
           }
       }
       double det_v = det(tmp);
       soln->ptr[0][k] = det_v / coeff_det;
   }
   dealloc2DArray(tmp);
}
int main()
{
   srand(time(0));
   int n;
   cout << "Enter number of variables : \n";
   cin >> n;
   Matrix *coeff = new Matrix;
   coeff->n = n;
   coeff->m = n;
 
   alloc2DArray(coeff);
   read2DArray(coeff);
 
   Matrix *cnst = new Matrix;
   cnst->n = coeff->n;
   cnst->m = 1;
 
   alloc2DArray(cnst);
   read2DArray(cnst);
 
   cout << "Coefficients : " << endl;
   display2DArray(coeff);
   cout << "Constants : " << endl;
   display2DArray(cnst);
   Matrix *soln = new Matrix;
   soln->n = 1;
   soln->m = coeff->n;
   alloc2DArray(soln);
   Cramer(coeff, cnst, soln);
   cout << "Solution : " << endl;   
   display2DArray(soln);
   dealloc2DArray(coeff);
   dealloc2DArray(cnst);
 
}
