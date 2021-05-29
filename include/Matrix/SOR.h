
#ifndef SOR_H
#define SOR_H

#include <iostream>
#include "Matrix/Solver.h"

class SOR : public Solver
{
public:
    SOR();
    ~SOR();
    Matrix solve(Matrix &A, Matrix &b) override;
    Matrix solve(Matrix &A, std::vector<double> &b) override;
    void print() override;

private:
};

#endif // SOR_H
