# Matrix/Vector Operations

This project includes a Matrix class as well as a Vector class. Both classes are templated, so the user can define their data type.

The Vector class allows the following mathematical operations:
* Calculation of the dot product of two vectors
* Scalar multiplication of a vector
* Addition of two vectors

The Matrix class allows the following mathematical operations:
* Multiplication of two matrices
* Scalar multiplication of a matrix
* Addition of two matrices
* Multiplication of a matrix with a vector

An executable was implemented that makes use of the matrix and vector functionality and prints the results of the mathematical operations to the terminal.

### Build
```
git clone https://github.com/sebdengler/matrix-operations.git
cd matrix-operations
mkdir build && cd build
cmake ..
make
```

## Run
```
./matrix_operations
```