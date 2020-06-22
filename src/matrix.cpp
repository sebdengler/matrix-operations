#include "matrix.h"


/**
 * Initialize a matrix of given number of rows and columns
 * and set all values to 0
 */
template<typename T>
Matrix<T>::Matrix(int rows, int cols) : num_rows_(rows), num_cols_(cols)
{
  if (num_rows_ < 1 || num_cols_ < 1)
    throw std::invalid_argument("Number of columns and rows for matrix need to be >= 1.");
  
  matrix_cells_ = new T*[num_rows_];
  for (int i = 0; i < num_rows_; i++)
  {
    matrix_cells_[i] = new T[num_cols_];
    for (int j = 0; j < num_cols_; j++)
    {
      matrix_cells_[i][j] = 0;
    }
  }
}

/**
 * Deallocate heap memory
 */
template<typename T>
Matrix<T>::~Matrix()
{
  for (int i = 0; i < num_rows_; i++)
  {
    delete[] matrix_cells_[i];
  }
  delete[] matrix_cells_;
}

/**
 * Set values of this matrix with a nested initializer list
 */
template<typename T>
void Matrix<T>::operator= (const std::initializer_list<std::initializer_list<T>>& values)
{
  if (values.size() != num_rows_)
    throw std::invalid_argument("Wrong inputs given for matrix.");
  
  int row = 0;
  int col = 0;

  for (auto it1 = values.begin(); it1 != values.end(); ++it1, ++row)
  {
    if (it1->size() != num_cols_)
      throw std::invalid_argument("Wrong inputs given for matrix.");
    
    for (auto it2 = it1->begin(); it2 != it1->end(); ++it2, ++col)
    {
      matrix_cells_[row][col] = *it2;
    }
    col = 0;
  }
}

/**
 * Assign a matrix
 */
template<typename T>
void Matrix<T>::operator= (const Matrix<T>& m)
{
  if (m.getNumRows() != num_rows_ || m.getNumCols() != num_cols_)
    throw std::invalid_argument("Matrix dimensions do not match.");
  
  for (int i = 0; i < m.getNumRows(); i++)
  {
    for (int j = 0; j < m.getNumCols(); j++)
    {
      matrix_cells_[i][j] = m.at(i, j);
    }
  }
}

/**
 * Multiply this matrix with a second matrix
 */
template<typename T>
Matrix<T> Matrix<T>::operator* (const Matrix<T>& m)
{
  if (num_cols_ != m.getNumRows())
    throw std::invalid_argument("Columns of first matrix need to be of same size as rows of second.");
  
  Matrix<T> result(this->getNumRows(), m.getNumCols());
  
  for (int i = 0; i < result.getNumRows(); i++)
  {
    for (int j = 0; j < result.getNumCols(); j++)
    {
      for (int k = 0; k < this->getNumCols(); k++)
      {
        result.set(i, j, result.at(i,j) + (this->at(i,k) * m.at(k,j)));
      }
    }
  }

  return result;
}

/**
 * Multiply this matrix with a scalar
 */
template<typename T>
Matrix<T> Matrix<T>::operator* (const T& v)
{
  Matrix<T> result(this->getNumRows(), this->getNumCols());

  for (int i = 0; i < result.getNumRows(); i++)
  {
    for (int j = 0; j < result.getNumCols(); j++)
    {
      result.set(i, j, this->at(i,j) * v);
    }
  }

  return result;
}

/**
 * Add a second matrix to this matrix
 */
template<typename T>
Matrix<T> Matrix<T>::operator+ (const Matrix<T>& m)
{
  if (m.getNumRows() != num_rows_ || m.getNumCols() != num_cols_)
    throw std::invalid_argument("Matrix dimensions do not match.");
  
  Matrix<T> result(this->getNumRows(), this->getNumCols());
  
  for (int i = 0; i < result.getNumRows(); i++)
  {
    for (int j = 0; j < result.getNumCols(); j++)
    {
      result.set(i, j, this->at(i,j) + m.at(i,j));
    }
  }

  return result;
}

/**
 * Multiply this matrix with a vector
 */
template<typename T>
Vector<T> Matrix<T>::operator* (const Vector<T>& v)
{
  if (num_cols_ != v.getDimension())
    throw std::invalid_argument("Columns of matrix need to be of same size as dimension of vector.");
  
  Vector<T> result(this->getNumRows());

  for (int i = 0; i < this->getNumRows(); i++)
  {
    for (int j = 0; j < this->getNumCols(); j++)
    {
      result.set(i, result.at(i) + (this->at(i,j) * v.at(j)));
    }
  }

  return result;
}

/**
 * Print the entries of this matrix to the terminal
 */
template<typename T>
void Matrix<T>::print()
{
  for (int i = 0; i < num_rows_; i++)
  {
    for (int j = 0; j < num_cols_; j++)
    {
      std::cout << matrix_cells_[i][j] << "\t"; 
    }
    std::cout << std::endl;
  }
}