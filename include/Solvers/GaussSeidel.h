
#ifndef GAUSSSEIDEL_H
#define GAUSSSEIDEL_H

#include <iostream>
#include "Solvers/Solver.h"

class GaussSeidel : public Solver
{
public:
    GaussSeidel();
    ~GaussSeidel();
    Matrix solve(Matrix &A, Matrix &b) override;
    Matrix solve(Matrix &A, std::vector<double> &b) override;
    void print() override;

private:
    
};

#endif // GAUSSSEIDEL_H
