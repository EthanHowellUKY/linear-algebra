
#include "Matrix/LU.h"

LU::LU() {}
LU::~LU() {}
Matrix LU::solve(Matrix &A, Matrix &b) { return Matrix(); }
Matrix LU::solve(Matrix &A, std::vector<double> &b) { return Matrix(); }
void LU::print() { std::cout << "LU" << '\n'; }
