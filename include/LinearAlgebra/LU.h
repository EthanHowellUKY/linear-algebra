
#ifndef LU_H
#define LU_H

#include <iostream>
#include "LinearAlgebra/Solver.h"

class LU : public Solver
{
public:
    Matrix solve(Matrix &A, Matrix &b) override;
    Matrix solve(Matrix &A, std::vector<double> &b) override;
    void print() override;

private:
    void decompose(Matrix &A, Matrix &L, Matrix &U);
};

#endif // LU_H
