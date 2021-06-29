
#ifndef CHOLESKY_H
#define CHOLESKY_H

#include "LinearAlgebra/Solver.h"

class Cholesky : public Solver
{
public:
    Matrix solve(Matrix &A, Matrix &b) override;
    Matrix solve(Matrix &A, std::vector<double> &b) override;
    void print() override;
private:
    Matrix decompose(const Matrix &A);
};

#endif // CHOLESKY_H
