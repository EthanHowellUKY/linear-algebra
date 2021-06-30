
- [Linear Algebra Module](#linear-algebra-module)
- [Required Packages](#required-packages)
- [Building the Project](#building-the-project)
- [Supported Linear System Solutions](#supported-linear-systems-solutions)
- [Example](#example)

# Linear Algebra Module

The intent of this module is to provide a drop-in module to handle creation and modification of Matrices.

# Required Packages

A few packages are needed to be able to compile the tracking program. These packages are readily available using [vcpkg](https://github.com/microsoft/vcpkg) provided by Microsoft. The installation of `vcpkg` should reside in the root directory. The following commands will install the needed packages.

```bash
$ vcpkg install --triplet=x64  gtest
```

# Building the Project

This project is configured to build as a library and will produce no executable. The provided `CMakeLists.txt` build file is built to adhere to the following file structure.

```txt
./
+-- libs/
|   +-- LinearAlgebra/
|   |   +-- .gitignore
|   |   +-- .gitattributes
|   |   +-- include/
|   |   |   +-- LinearAlgebra/
|   |   |   |   +-- Cholesky.h
|   |   |   |   +-- GaussSeidel.h
|   |   |   |   +-- Jacobi.h
|   |   |   |   +-- LU.h
|   |   |   |   +-- Matrix.h
|   |   |   |   +-- Solver.h
|   |   |   |   +-- SolverFactory.h
|   |   |   |   +-- SOR.h
|   |   +-- src/
|   |   |   +--- Cholesky.cpp
|   |   |   +--- GaussSeidel.cpp
|   |   |   +--- Jacobi.cpp
|   |   |   +--- LU.cpp
|   |   |   +--- Matrix.cpp
|   |   |   +--- Solver.cpp
|   |   |   +--- SolverFactory.cpp
|   |   |   +--- SOR.cpp
|   |   +-- test/
|   |   |   +-- CMakeLists.txt
|   |   |   +-- matrix-test.cpp
|   |   +-- CHANGELOG.md
|   |   +-- CMakeLists.txt
|   |   +-- LICENSE.md
|   |   +-- README.md
+-- src/
|   +-- main.cpp
|   +-- CMakeLists.txt
+-- CMakeLists.txt
```

To follow this structure, add these lines to  `./CMakeLists.txt`

```cmake
...
set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_subdirectory(libs/LinearAlgebra)
add_subdirectory(src)
...
```

And add these lines to `src/CMakeLists.txt`

```cmake
...
project(${CMAKE_PROJECT_NAME} CXX)
file(GLOB_RECURSE HEADER_FILES *.h)
file(GLOB_RECURSE SRC_FILES *.cpp)
...

...
target_link_libraries(${CMAKE_PROJECT_NAME}
    echo::linearalgebra
)
...
```

# Supported Linear System Solutions

Currently, only solutions via LU Decomposition are supported. However, development is currently in progress to support the following.

- Cholesky Decomposition
- Gauss Seidel
- Jacobi Iteration
- Successive Overrelaxation

# Example

The following example shows how the module can be used to solve a 3x3 linear system using the LU Decomposition method.

```cpp
#include <iostream>
#include "LinearAlgebra/Matrix.h"
#include "LinearAlgebra/SolverFactory.h"

int main(int argc, char *argv[])
{
    Solver *solver = SolverFactory::create(SOLVER::LUDECOMP);
    Matrix A = Matrix({ {2,  -1, -2},
                        {-4,  6,  3},
                        {-4, -2,  8}});

    Matrix b = Matrix({-1, 5, 2});
    Matrix x = solver->solve(A, b);
    x.print();
    /*
        [ 1 ]
        [ 1 ]
        [ 1 ]
	*/

    return 0;
}
```
