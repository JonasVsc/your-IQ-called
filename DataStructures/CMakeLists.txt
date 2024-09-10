project(DataStructures VERSION 0.1.0 LANGUAGES CXX)


# Array
add_executable(Array Array/src/Array.cpp)

# Matrices
add_executable(DiagonalMatrix        Matrices/src/DiagonalMatrix.cpp)
add_executable(LowerTriangularMatrix Matrices/src/LowerTriangularMatrix.cpp)
add_executable(SymmetricMatrix       Matrices/src/SymmetricMatrix.cpp)