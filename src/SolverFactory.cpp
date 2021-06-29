
#include "LinearAlgebra/SolverFactory.h"

Solver *SolverFactory::create(const SOLVER &solver)
{
    switch (solver)
    {
    case LUDECOMP:
        return new LU();
        break;
    case JACOBI:
        return new Jacobi();
        break;
    case GAUSSSEIDEL:
        return new GaussSeidel();
        break;
    case SORELAX:
        return new SOR();
        break;
    case CHOLESKY:
        return new Cholesky();
        break;

    default:
        return new Jacobi();
        break;
    }
}

Solver *SolverFactory::create() { return new Jacobi(); }
