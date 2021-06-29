
#include <gtest/gtest.h>
#include "LinearAlgebra/Matrix.h"

// CASE VARIABLES
Matrix m1 = Matrix({{1, 0, 0},
                    {0, 1, 0},
                    {0, 0, 1}});

Matrix m2 = Matrix({
    {1.0, 1.0, 1.0},
    {1.0, 1.0, 1.0},
    {1.0, 1.0, 1.0},
});

Matrix m3 = Matrix({{1.0, 2.0, 3.0},
                    {4.0, 5.0, 6.0},
                    {7.0, 8.0, 9.0}});

// SOLUTION VARIABLES
Matrix addition_solution_m1plusm2 = Matrix({{2.0, 1.0, 1.0},
                                            {1.0, 2.0, 1.0},
                                            {1.0, 1.0, 2.0}});

Matrix subtraction_solution_m1subm2 = Matrix({{0.0, -1.0, -1.0},
                                              {-1.0, 0.0, -1.0},
                                              {-1.0, -1.0, 0.0}});

Matrix subtraction_solution_m2subm1 = Matrix({{0.0, 1.0, 1.0},
                                              {1.0, 0.0, 1.0},
                                              {1.0, 1.0, 0.0}});

Matrix transpose_solution_m3 = Matrix({{1.0, 4.0, 7.0},
                                       {2.0, 5.0, 8.0},
                                       {3.0, 6.0, 9.0}});

Matrix scalarmult_solution_2m1 = Matrix({{2, 0, 0},
                                         {0, 2, 0},
                                         {0, 0, 2}});

TEST(MatrixTest, Addition)
{
    ASSERT_EQ(addition_solution_m1plusm2, m1 + m2);
}

TEST(MatrixTest, Subtraction)
{
    ASSERT_EQ(subtraction_solution_m1subm2, m1 - m2);
    ASSERT_EQ(subtraction_solution_m2subm1, m2 - m1);
}

TEST(MatrixTest, ScalarMultiplication)
{
    ASSERT_EQ(scalarmult_solution_2m1, m1 * 2.0);
    ASSERT_EQ(scalarmult_solution_2m1, 2.0 * m1);
}

TEST(MatrixTest, Transpose)
{
    ASSERT_EQ(transpose_solution_m3, m3.transpose());
}

TEST(MatrixTest, Norm)
{
    ASSERT_EQ(3, Matrix::norm1(m1));
    ASSERT_NEAR(1.732, Matrix::norm2(m1), 0.0001);
}
