
#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>
#include <math.h>

// #include "Matrix/SolverFactory.h"

class Matrix
{
public:
    // -------------------------------- //
    //           CONSTRUCTORS           //
    // -------------------------------- //
    Matrix() {}
    Matrix(int rows, int cols);
    Matrix(const std::vector<double> &mat) {}
    Matrix(const std::vector<std::vector<double>> &mat);
    Matrix(const char *filename) {}

    // COPY CONSTRUCTOR
    //Matrix(const Matrix &);

    // -------------------------------- //
    //            DESTRUCTOR            //
    // -------------------------------- //
    ~Matrix();

    // -------------------------------- //
    //            OPERATORS             //
    // -------------------------------- //
    Matrix operator+(Matrix &rhs);
    Matrix operator-(Matrix &rhs);
    Matrix operator*(Matrix &rhs);
    Matrix operator=(const std::vector<std::vector<double>> &rhs);
    std::vector<double> operator*(std::vector<double> &rhs);
    double &operator()(const int &row, const int &col);
    double operator()(const int &row, const int &col) const;
    bool operator==(const Matrix &rhs) const;
    bool operator==(const std::vector<std::vector<double>> &rhs) const;
    friend Matrix operator*(Matrix rhs, double lhs);
    friend Matrix operator*(double lhs, Matrix rhs);

    // -------------------------------- //
    //         PUBLIC FUNCTIONS         //
    // -------------------------------- //
    Matrix transpose();
    void print();
    void print_solver();
    // void set_solver(const SOLVER &solver);
    static double norm1(const Matrix &u);
    static double norm1(const std::vector<double> &u);
    static double norm1(const std::vector<std::vector<double>> &u);
    static double norm2(const Matrix &u);
    static double norm2(const std::vector<double> &u);
    static double norm2(const std::vector<std::vector<double>> &u);
    static Matrix scalar_multiply(double &scalar, Matrix &mat);

    // ------------ GETTERS ----------- //
    int rows() const;
    int cols() const;

    // ------------ SETTERS ----------- //

private:
    // -------------------------------- //
    //        PRIVATE FUNCTIONS         //
    // -------------------------------- //
    bool is_valid();
    void add_sub(Matrix &mat, Matrix &lhs, Matrix &rhs, const int &op);
    static double pnorm(const Matrix &u, const int &p);
    static double pnorm(const std::vector<double> &u, const int &p);
    static double pnorm(const std::vector<std::vector<double>> &u, const int &p);

    // -------------------------------- //
    //        PRIVATE VARIABLES         //
    // -------------------------------- //
    int m_rows;
    int m_cols;
    std::vector<std::vector<double>> m_matrix;
    // Solver *m_solver = SolverFactory::create(SOLVER::JACOBI);
};

#endif // MATRIX_H
