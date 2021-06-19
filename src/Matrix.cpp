
#include "Matrix/Matrix.h"

// -------------------------------- //
//        PRIVATE FUNCTIONS         //
// -------------------------------- //
void Matrix::add_sub(Matrix &mat, Matrix &lhs, Matrix &rhs, const int &op)
{
    for (int ii = 0; ii < lhs.rows(); ii++)
    {
        for (int jj = 0; jj < lhs.cols(); jj++)
        {
            mat(ii, jj) = lhs(ii, jj) + op * rhs(ii, jj);
        }
    }
}

double Matrix::pnorm(const Matrix &u, const int &p)
{
    double tmp = 0.0;
    for (int ii = 0; ii < u.rows(); ii++)
    {
        for (int jj = 0; jj < u.cols(); jj++)
        {
            tmp += pow(u(ii, jj), p);
        }
    }
    return pow(tmp, 1.0 / p);
}

double Matrix::pnorm(const std::vector<double> &u, const int &p)
{
    double tmp = 0.0;
    for (int ii = 0; ii < u.size(); ii++)
    {
        tmp += pow(u[ii], p);
    }
    return pow(tmp, 1.0 / p);
}

double Matrix::pnorm(const std::vector<std::vector<double>> &u, const int &p)
{
    double tmp = 0.0;
    for (int ii = 0; ii < u.size(); ii++)
    {
        for (int jj = 0; jj < u[ii].size(); jj++)
        {
            tmp += pow(u[ii][jj], p);
        }
    }
    return pow(tmp, 1.0 / p);
}

// -------------------------------- //
//           CONSTRUCTORS           //
// -------------------------------- //
Matrix::Matrix(int rows, int cols)
{
    m_rows = rows;
    m_cols = cols;
    m_matrix.resize(m_rows);
    for (int ii = 0; ii < rows; ii++)
    {
        m_matrix[ii].resize(m_cols, 0);
    }
}

Matrix::Matrix(const std::vector<double> &mat)
{
    m_rows = mat.size();
    m_cols = 1;
    m_matrix.resize(m_rows);
    for (int ii=0; ii<m_rows; ii++)
    {
        m_matrix[ii].push_back(mat[ii]);
    }
}

Matrix::Matrix(const std::vector<std::vector<double>> &mat)
{
    m_rows = mat.size();
    m_cols = mat[0].size();
    m_matrix = mat;
}

// -------------------------------- //
//            DESTRUCTOR            //
// -------------------------------- //
Matrix::~Matrix() {  }

// -------------------------------- //
//            OPERATORS             //
// -------------------------------- //
Matrix Matrix::operator+(Matrix &rhs)
{
    Matrix sum(m_rows, m_cols);
    if (rhs.rows() != m_rows || rhs.cols() != m_cols)
    {
        std::cout << "Dimension mismatch in addition" << '\n';
        return sum;
    }

    add_sub(sum, *this, rhs, 1);
    return sum;
}

Matrix Matrix::operator-(Matrix &rhs)
{
    Matrix sum(m_rows, m_cols);
    if (rhs.rows() != m_rows || rhs.cols() != m_cols)
    {
        std::cout << "Dimension mismatch in subtraction" << '\n';
        return sum;
    }

    add_sub(sum, *this, rhs, -1);
    return sum;
}

Matrix Matrix::operator*(Matrix &rhs)
{
    Matrix result(m_rows, rhs.cols());
    if (m_cols == rhs.rows())
    {
        for (int ii = 0; ii < m_rows; ii++)
        {
            for (int jj = 0; jj < m_cols; jj++)
            {
                for (int kk = 0; kk < rhs.rows(); kk++)
                {
                    result(ii, jj) += (*this)(ii, kk) * rhs(kk, jj);
                }
            }
        }
    }

    return result;
}

std::vector<double> Matrix::operator*(std::vector<double> &rhs)
{
    return (*this) * rhs;
    /*
    std::vector<double> result;
    if (m_rows != rhs.size())
    {
        std::cout << "Dimensions do not match" << '\n';
        return result;
    }

    result.resize(m_rows, 0.0);
    for (int ii = 0; ii < m_rows; ii++)
    {
        double value = 0.0;
        for (int jj = 0; jj < m_cols; jj++)
        {
            value += m_matrix[ii][jj] * rhs[jj];
        }
        result[ii] = value;
    }
    return result;
    */
}

double &Matrix::operator()(const int &row, const int &col) { return m_matrix[row == -1 ? m_rows-1 : row][col == -1 ? m_cols-1 : col]; }
double Matrix::operator()(const int &row, const int &col) const { return m_matrix[row == -1 ? m_rows-1 : row][col == -1 ? m_cols-1 : col]; }

bool Matrix::operator==(const Matrix &rhs) const
{
    if (m_rows != rhs.rows() || m_cols != rhs.cols())
    {
        return false;
    }
    for (int ii = 0; ii < m_rows; ii++)
    {
        for (int jj = 0; jj < m_cols; jj++)
        {
            if (m_matrix[ii][jj] != rhs(ii, jj))
            {
                return false;
            }
        }
    }
    return true;
}

bool Matrix::operator==(const std::vector<std::vector<double>> &rhs) const
{
    if (m_rows != rhs.size() || m_cols != rhs[0].size())
    {
        return false;
    }
    for (int ii = 0; ii < m_rows; ii++)
    {
        for (int jj = 0; jj < m_cols; jj++)
        {
            if (m_matrix[ii][jj] != rhs[ii][jj])
            {
                return false;
            }
        }
    }

    return true;
}

// -------------------------------- //
//         PUBLIC FUNCTIONS         //
// -------------------------------- //
bool Matrix::is_square() const { return m_rows == m_cols; }

Matrix Matrix::transpose()
{
    Matrix T_(m_cols, m_rows);
    for (int ii = 0; ii < m_rows; ii++)
    {
        for (int jj = 0; jj < m_cols; jj++)
        {
            T_(jj, ii) = m_matrix[ii][jj];
        }
    }

    return T_;
}

void Matrix::print()
{
    for (int ii=0; ii<m_rows; ii++)
    {
        std::cout << "[";
        for (int jj=0; jj<m_cols; jj++)
        {
            std::cout << " " << (*this)(ii, jj) << " ";
        }
        std::cout << "]" << '\n';
    }
}
double Matrix::trace()
{
    double result = 0.0;
    if (is_square())
    {
        for (int ii = 0; ii<m_rows; ii++)
        {
            result += m_matrix[ii][ii];
        }
    }
    else
    {
        std::cout << "Cannot get trace of a non-square matrix" << '\n';
    }

    return result;
}

double Matrix::norm1(const Matrix &u) { return pnorm(u, 1.0); }
double Matrix::norm1(const std::vector<double> &u) { return pnorm(u, 1.0); }
double Matrix::norm1(const std::vector<std::vector<double>> &u) { return pnorm(u, 1.0); }
double Matrix::norm2(const Matrix &u) { return pnorm(u, 2.0); }
double Matrix::norm2(const std::vector<double> &u) { return pnorm(u, 2.0); }
double Matrix::norm2(const std::vector<std::vector<double>> &u) { return pnorm(u, 2.0); }
Matrix Matrix::scalar_multiply(double &scalar, Matrix &mat)
{
    for (int ii = 0; ii < mat.rows(); ii++)
    {
        for (int jj = 0; jj < mat.cols(); jj++)
        {
            mat(ii, jj) *= scalar;
        }
    }
    return mat;
}

double Matrix::dot(const std::vector<double> &x, const std::vector<double> &y)
{
    double sum = -1;
    if (x.size() == y.size())
    {
        for (int ii = 0; ii<x.size(); ii++)
        {
            sum += ( x[ii] * y[ii] );
        }
    }
    return sum;
}

double Matrix::scalar_projection(const std::vector<double> &x, const std::vector<double> &y) { return dot(x, y) / norm2(y); }

std::vector<double> Matrix::projection(const std::vector<double> &x, const std::vector<double> &y)
{
    std::vector<double> solution;
    double scalar_val = scalar_projection(x, y) * ( 1 / norm2(y) );
    for (int ii = 0; ii<y.size(); ii++)
    {
        solution.push_back(scalar_val * y[ii]);
    }
    return solution;
}

Matrix Matrix::eye(int rows)
{
    Matrix result(rows, rows);
    for (int ii = 0; ii<rows; ii++)
    {
        result(ii, ii) = 1;
    }
    return result;
}

// ------------ GETTERS ----------- //
int Matrix::rows() const { return m_rows; }
int Matrix::cols() const { return m_cols; }

// ------------ RELATED ----------- //
Matrix operator*(Matrix rhs, double lhs) { return Matrix::scalar_multiply(lhs, rhs); }
Matrix operator*(double lhs, Matrix rhs) { return Matrix::scalar_multiply(lhs, rhs); }
Matrix operator*(Matrix lhs, Matrix rhs)
{
    Matrix result(lhs.rows(), rhs.cols());
    if (lhs.cols() == rhs.rows())
    {
        for (int ii = 0; ii < lhs.rows(); ii++)
        {
            for (int jj = 0; jj < lhs.cols(); jj++)
            {
                for (int kk = 0; kk < rhs.rows(); kk++)
                {
                    result(ii, jj) += lhs(ii, kk) * rhs(kk, jj);
                }
            }
        }
    }

    return result;
}
