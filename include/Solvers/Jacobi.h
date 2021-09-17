
#ifndef JACOBI_H
#define JACOBI_H

#include <iostream>
#include "Solvers/Solver.h"

class Jacobi : public Solver
{
public:
    Jacobi();
    ~Jacobi();
    Matrix solve(Matrix &A, Matrix &b) override;
    Matrix solve(Matrix &A, std::vector<double> &b) override;
    void print() override;

private:
};

#endif // JACOBI_H
