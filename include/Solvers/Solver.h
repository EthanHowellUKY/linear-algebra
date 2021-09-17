
#ifndef SOLVER_H
#define SOLVER_H

#define MIN_TOL 0.00001

#include <math.h>
#include <vector>
#include "Matrix.h"

class Solver
{
public:
    virtual Matrix solve(Matrix &A, Matrix &b) = 0;
    virtual Matrix solve(Matrix &A, std::vector<double> &b) = 0;
    virtual void print() = 0;
};

#endif // SOLVER_H
