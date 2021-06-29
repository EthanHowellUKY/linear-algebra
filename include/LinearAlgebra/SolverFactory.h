
#ifndef SOLVERFACTORY_H
#define SOLVERFACTORY_H

#include "LinearAlgebra/LU.h"
#include "LinearAlgebra/Jacobi.h"
#include "LinearAlgebra/GaussSeidel.h"
#include "LinearAlgebra/SOR.h"
#include "LinearAlgebra/Cholesky.h"

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
