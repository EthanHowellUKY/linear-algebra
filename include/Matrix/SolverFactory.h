
#ifndef SOLVERFACTORY_H
#define SOLVERFACTORY_H

#include "Matrix/LU.h"
#include "Matrix/Jacobi.h"
#include "Matrix/GaussSeidel.h"
#include "Matrix/SOR.h"
#include "Matrix/Cholesky.h"

enum SOLVER
{
    LUDECOMP = 0,
    JACOBI,
    GAUSSSEIDEL,
    SORELAX,
    CHOLESKY
};

class SolverFactory
{
public:
    static Solver *create(const SOLVER &solver);
    static Solver *create();
};

#endif // SOLVERFACTORY_H
