/**
 * Copyright (C) 2020  Sebastian Dengler <sebastian.dengler92@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person 
 * obtaining a copy of this software and associated documentation 
 * files (the "Software"), to deal in the Software without restriction, 
 * including without limitation the rights to use, copy, modify, merge, 
 * publish, distribute, sublicense, and/or sell copies of the Software, 
 * and to permit persons to whom the Software is furnished to do so, 
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be 
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, 
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF 
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. 
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY 
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, 
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH 
 * THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <initializer_list>
#include <stdexcept>

#include "vector.h"

/**
 * @brief Templated matrix class
 * @detail This templated class implements a matrix of user-defined type.
 * It enables the multiplication of matrices, the addition of matrices,
 * the scalar multiplication of a matrix as well as the multiplication
 * of a matrix with a vector.
 */
template<typename T>
class Matrix
{
public:
  Matrix(int rows, int cols);

  ~Matrix();

  /**
   * Get value at defined position
   */
  T const& at(int row, int col) const {return matrix_cells_[row][col];}

  /**
   * Set value at defined position
   */
  void set(const int& row, const int& col, const T& value) {matrix_cells_[row][col] = value;}

  /**
   * Get number of rows
   */
  int const& getNumRows() const {return num_rows_;}
  
  /**
   * Get number of columns
   */
  int const& getNumCols() const {return num_cols_;}

  void operator= (const std::initializer_list<std::initializer_list<T>>& values);
  void operator= (const Matrix<T>& m);

  Matrix operator* (const Matrix<T>& m);
  Matrix operator* (const T& v);
  Matrix operator+ (const Matrix<T>& m);
  Vector<T> operator* (const Vector<T>& v);
  
  void print();

private:
  T** matrix_cells_; /**< Pointer to entries of matrix */

  int num_rows_; /**< Number of rows of matrix */
  int num_cols_; /**< Number of columns of matrix */
};

#endif // MATRIX_H