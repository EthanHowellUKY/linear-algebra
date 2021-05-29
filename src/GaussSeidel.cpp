
#include "Matrix/GaussSeidel.h"

GaussSeidel::GaussSeidel() {}
GaussSeidel::~GaussSeidel() {}
Matrix GaussSeidel::solve(Matrix &A, Matrix &b) { return Matrix(); }
Matrix GaussSeidel::solve(Matrix &A, std::vector<double> &b) { return Matrix(); }
void GaussSeidel::print() { std::cout << "Gauss Seidel" << '\n'; }
