
#ifndef VECTOR_H
#define VECTOR_H

#include "Matrix.h"

class Vector : public Matrix
{
public:
    // -------------------------------- //
    //           CONSTRUCTORS           //
    // -------------------------------- //
    explicit Vector() {}
    explicit Vector(int rows);
    explicit Vector(const std::vector<double> &vec);

    // -------------------------------- //
    //            DESTRUCTOR            //
    // -------------------------------- //
    ~Vector() {}

    // -------------------------------- //
    //            OPERATORS             //
    // -------------------------------- //
    double &operator()(const int &row);
    double operator()(const int &row) const;

    // -------------------------------- //
    //         PUBLIC FUNCTIONS         //
    // -------------------------------- //

    // ------------ GETTERS ----------- //

    // ------------ SETTERS ----------- //
private:
    // -------------------------------- //
    //        PRIVATE FUNCTIONS         //
    // -------------------------------- //

    // -------------------------------- //
    //        PRIVATE VARIABLES         //
    // -------------------------------- //
};

#endif // VECTOR_H
