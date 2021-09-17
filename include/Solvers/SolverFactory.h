
#ifndef SOLVERFACTORY_H
#define SOLVERFACTORY_H

#include "Solvers/LU.h"
#include "Solvers/Jacobi.h"
#include "Solvers/GaussSeidel.h"
#include "Solvers/SOR.h"
#include "Solvers/Cholesky.h"

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
