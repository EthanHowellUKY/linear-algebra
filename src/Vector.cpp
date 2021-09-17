
#include "Vector.h"

// -------------------------------- //
//        PRIVATE FUNCTIONS         //
// -------------------------------- //
Vector::Vector(int rows)
    : Matrix(rows, 1)
{
}

Vector::Vector(const std::vector<double> &vec)
    : Matrix(vec)
{
}

// -------------------------------- //
//           CONSTRUCTORS           //
// -------------------------------- //

// -------------------------------- //
//            DESTRUCTOR            //
// -------------------------------- //

// -------------------------------- //
//            OPERATORS             //
// -------------------------------- //
double &Vector::operator()(const int &row) { return this->m_matrix[row == -1 ? this->m_rows-1 : row][0]; }
double Vector::operator()(const int &row) const { return this->m_matrix[row == -1 ? this->m_rows-1 : row][0]; }

// -------------------------------- //
//         PUBLIC FUNCTIONS         //
// -------------------------------- //

// ------------ GETTERS ----------- //

// ------------ SETTERS ----------- //
