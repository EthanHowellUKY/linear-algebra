
#include "Solvers/LU.h"

// -------------------------------- //
//        PRIVATE FUNCTIONS         //
// -------------------------------- //
void LU::decompose(Matrix &A, Matrix &L, Matrix &U)
{
    for (int ii = 0; ii < A.rows(); ii++)
    {
        for (int kk = ii; kk < A.rows(); kk++)
        {
            int sum = 0;
            for (int jj = 0; jj < ii; jj++)
            {
                sum += ( L(ii, jj) * U(jj, kk) );
            }
            U(ii, kk) = A(ii, kk) - sum;
        }

        for (int kk = ii; kk < A.rows(); kk++)
        {
            if (ii == kk) { L(ii, ii) = 1; }
            else
            {
                int sum = 0;
                for (int jj = 0; jj < ii; jj++)
                {
                    sum += ( L(kk, jj) * U(jj, ii) );
                }

                L(kk, ii) = U(ii, ii) > MIN_TOL ? ( A(kk, ii) - sum ) / U(ii, ii) : 0;
            }
        }
    }
}

// -------------------------------- //
//           CONSTRUCTORS           //
// -------------------------------- //


// -------------------------------- //
//            DESTRUCTOR            //
// -------------------------------- //


// -------------------------------- //
//         PUBLIC FUNCTIONS         //
// -------------------------------- //
Matrix LU::solve(Matrix &A, Matrix &b)
{
    int m = A.rows(), n = A.cols();
    double multiplier;
    Matrix L(m, n), U(m, n), x(m, b.cols());

    decompose(A, L, U);
    
    for (int kk = 0; kk < m-1; kk++)
    {
        for (int ii = kk+1; ii < m; ii++)
        {
            multiplier = L(kk, kk) > MIN_TOL ? L(ii, kk) / L(kk, kk) : 0;
            b(ii, 0) = b(ii, 0) - multiplier * b(kk, 0);
            for (int jj = kk+1; jj < m; jj++)
            {
                L(ii, jj) = L(ii, jj) - multiplier * L(kk, jj);
            }
        }
    }

    x(-1, 0) = U(-1, -1) > MIN_TOL ? b(-1, 0) / U(-1, -1) : 0;
    for (int ii = m-2; ii > -1; ii--)
    {
        for (int jj = ii+1; jj < m; jj++)
        {
            x(ii, 0) += U(ii, jj) * x(jj, 0);
        }
        x(ii, 0) = U(ii, ii) > MIN_TOL ? ( b(ii, 0) - x(ii, 0) ) / U(ii, ii) : 0;
    }

    return x;
}
Matrix LU::solve(Matrix &A, std::vector<double> &b) { return Matrix(); }
void LU::print() { std::cout << "LU" << '\n'; }
