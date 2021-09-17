
#include "Solvers/Jacobi.h"

Jacobi::Jacobi() {}
Jacobi::~Jacobi() {}
Matrix Jacobi::solve(Matrix &A, Matrix &b) { return Matrix(); }
Matrix Jacobi::solve(Matrix &A, std::vector<double> &b) { return Matrix(); }
void Jacobi::print() { std::cout << "Jacobi" << '\n'; }
