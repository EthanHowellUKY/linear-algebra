
#include "LinearAlgebra/SOR.h"

SOR::SOR() {}
SOR::~SOR() {}
Matrix SOR::solve(Matrix &A, Matrix &b) { return Matrix(); }
Matrix SOR::solve(Matrix &A, std::vector<double> &b) { return Matrix(); }
void SOR::print() { std::cout << "SOR" << '\n'; }
