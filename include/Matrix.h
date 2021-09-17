
#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>
#include <math.h>

class Matrix
{
public:
    // -------------------------------- //
    //           CONSTRUCTORS           //
    // -------------------------------- //
    explicit Matrix() {}
    explicit Matrix(int rows, int cols);
    explicit Matrix(const std::vector<double> &mat);
    explicit Matrix(const std::vector<std::vector<double>> &mat);
    explicit Matrix(const char *filename) {}

    // COPY CONSTRUCTOR
    //Matrix(const Matrix &);

    // -------------------------------- //
    //            DESTRUCTOR            //
    // -------------------------------- //
    ~Matrix();

    // -------------------------------- //
    //            OPERATORS             //
    // -------------------------------- //
    Matrix operator+(const Matrix &rhs);
    Matrix operator-(const Matrix &rhs);
    Matrix operator*(const Matrix &rhs);
    Matrix operator=(const std::vector<std::vector<double>> &rhs);
    Matrix operator+=(const Matrix &rhs);
    std::vector<double> operator*(std::vector<double> &rhs);
    double &operator()(const int &row, const int &col);
    double operator()(const int &row, const int &col) const;
    bool operator==(const Matrix &rhs) const;
    bool operator==(const std::vector<std::vector<double>> &rhs) const;
    friend Matrix operator*(Matrix rhs, double lhs);
    friend Matrix operator*(double lhs, Matrix rhs);
    friend Matrix operator-(const Matrix &lhs, const Matrix &rhs);
    // friend Matrix operator*(Matrix lhs, Matrix rhs);

    // -------------------------------- //
    //         PUBLIC FUNCTIONS         //
    // -------------------------------- //
    bool is_square() const;
    Matrix transpose();
    void print();
    double trace();
    //void print_solver();
    static double norm1(const Matrix &u);
    static double norm1(const std::vector<double> &u);
    static double norm1(const std::vector<std::vector<double>> &u);
    static double norm2(const Matrix &u);
    static double norm2(const std::vector<double> &u);
    static double norm2(const std::vector<std::vector<double>> &u);
    static Matrix scalar_multiply(double &scalar, Matrix &mat);
    static double dot(const std::vector<double> &x, const std::vector<double> &y);
    static double scalar_projection(const std::vector<double> &x, const std::vector<double> &y);
    static std::vector<double> projection(const std::vector<double> &x, const std::vector<double> &y);
    static Matrix eye(int rows);
        
    // ------------ GETTERS ----------- //
    int rows() const;
    int cols() const;

    // ------------ SETTERS ----------- //

protected:
    // -------------------------------- //
    //        PRIVATE FUNCTIONS         //
    // -------------------------------- //
    bool is_valid();
    void add_sub(Matrix &mat, Matrix &lhs, const Matrix &rhs, const int &op);
    static double pnorm(const Matrix &u, const int &p);
    static double pnorm(const std::vector<double> &u, const int &p);
    static double pnorm(const std::vector<std::vector<double>> &u, const int &p);

    // -------------------------------- //
    //        PRIVATE VARIABLES         //
    // -------------------------------- //
    int m_rows;
    int m_cols;
    std::vector<std::vector<double>> m_matrix;
};

#endif // MATRIX_H
