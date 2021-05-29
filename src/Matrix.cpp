
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
    for (int ii = 0; ii < cols; ii++)
    {
        m_matrix[ii].resize(m_cols, 0);
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
            for (int jj = 0; jj < m_cols; ii++)
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
}

double &Matrix::operator()(const int &row, const int &col) { return m_matrix[row][col]; }
double Matrix::operator()(const int &row, const int &col) const { return m_matrix[row][col]; }

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

//void Matrix::print_solver() { m_solver->print(); }
//void Matrix::set_solver(const SOLVER &solver) { m_solver = SolverFactory::create(solver); }

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

// ------------ GETTERS ----------- //
int Matrix::rows() const { return m_rows; }
int Matrix::cols() const { return m_cols; }

// ------------ RELATED ----------- //
Matrix operator*(Matrix rhs, double lhs) { return Matrix::scalar_multiply(lhs, rhs); }
Matrix operator*(double lhs, Matrix rhs) { return Matrix::scalar_multiply(lhs, rhs); }
