
#include "Matrix/Cholesky.h"

// -------------------------------- //
//        PRIVATE FUNCTIONS         //
// -------------------------------- //
Matrix Cholesky::decompose(const Matrix &A)
{
    Matrix L(A.rows(), A.cols());
    for (int ii=0; ii<A.rows(); ii++)
    {
        for (int jj=0; jj<A.cols(); jj++)
        {
            int sum = 0;
            double diff;
            bool diag = ii == jj;
            for (int kk=0; kk<jj; kk++)
            {
                sum += diag ? pow(L(jj, kk), 2) : ( L(ii, kk) * L(jj, kk) );
            }
            diff = A(ii, jj) - sum;
            L(ii, jj) = diag ? sqrt(diff) : ( diff / L(jj, jj) );
        }
    }
    return L;
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
Matrix Cholesky::solve(Matrix &A, Matrix &b)
{
    Matrix L = decompose(A);
    Matrix LT = L.transpose();
    Matrix x(A.rows(), b.cols()), y(A.rows(), b.cols());
    
    double multiplier;

    // Forward elimination
    for (int kk = 0; kk < L.rows()-1; kk++)
    {
        for (int ii = kk+1; ii < L.rows(); ii++)
        {
            multiplier = L(ii, kk) / L(kk, kk);
            b(ii, 0) = b(ii, 0) - multiplier * b(kk, 0);
            for (int jj = kk+1; jj < L.rows(); jj++)
            {
                L(ii, jj) = L(ii, jj) - multiplier * L(kk, jj);
            }
        }
    }

    // Backward substitution
    x(L.rows()-1, 0) = b(b.rows()-1, 0);
    for (int ii = L.rows()-2; ii > -1; ii--)
    {
        for (int jj = ii+1; jj < L.rows(); jj++)
        {
            x(ii, 0) += L(ii, jj) * x(jj, 0);
        }
        x(ii, 0) = (b(ii, 0) - x(ii, 0)) / L(ii, ii);
    }

    return x;
}
Matrix Cholesky::solve(Matrix &A, std::vector<double> &b) { return Matrix(); }
void Cholesky::print() { std::cout << "Cholesky" << '\n'; }
