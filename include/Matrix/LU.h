
#ifndef LU_H
#define LU_H

#include <iostream>
#include "Matrix/Solver.h"

class LU : public Solver
{
public:
    LU();
    ~LU();
    Matrix solve(Matrix &A, Matrix &b) override;
    Matrix solve(Matrix &A, std::vector<double> &b) override;
    void print() override;

private:
};

#endif // LU_H
