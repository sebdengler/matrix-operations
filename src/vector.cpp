#include "vector.h"


/**
 * Initialize a column-vector of a given dimension and set all values ot 0
 */
template<typename T>
Vector<T>::Vector(int dimension) : dimension_(dimension)
{
  if (dimension_ < 1)
    throw std::invalid_argument("Dimension of vector needs to be >= 1.");

  vector_cells_ = new T[dimension];
  for (int i = 0; i < dimension; i++)
    vector_cells_[i] = 0;
}

/**
 * Deallocate heap memory
 */
template<typename T>
Vector<T>::~Vector()
{
  delete[] vector_cells_;
}

/**
 * Set values of this vector with an initializer list
 */
template<typename T>
void Vector<T>::operator= (const std::initializer_list<T>& values)
{
  if (values.size() != dimension_)
    throw std::invalid_argument("Wrong number of inputs given for vector.");
  
  int idx = 0;

  for (auto it = values.begin(); it != values.end(); ++it, ++idx)
    vector_cells_[idx] = *it;
}

/**
 * Assign a vector
 */
template<typename T>
void Vector<T>::operator= (const Vector<T>& v)
{
  if (v.getDimension() != dimension_)
    throw std::invalid_argument("Vector dimensions do not match.");
  
  for (int i = 0; i < v.getDimension(); i++)
    vector_cells_[i] = v.at(i);
}

/**
 * Calculate the dot product of this vectors and a second one
 */
template<typename T>
T Vector<T>::operator* (const Vector<T>& v)
{
  if (v.getDimension() != dimension_)
    throw std::invalid_argument("Vector dimensions do not match.");

  T result = 0;

  for (int i = 0; i < dimension_; i++)
    result += this->at(i) * v.at(i);

  return result;
}

/**
 * Multiply this vector with a scalar
 */
template<typename T>
Vector<T> Vector<T>::operator* (const T& v)
{
  Vector<T> result(this->getDimension());

  for (int i = 0; i < result.getDimension(); i++)
    result.set(i, this->at(i) * v);

  return result;
}

/**
 * Add a second vector to this vector
 */
template<typename T>
Vector<T> Vector<T>::operator+ (const Vector<T>& v)
{
  if (v.getDimension() != dimension_)
    throw std::invalid_argument("Vector dimensions do not match.");
  
  Vector<T> result(this->getDimension());

  for (int i = 0; i < result.getDimension(); i++)
    result.set(i, this->at(i) + v.at(i));

  return result;
}

/**
 * Print the entries of this vector to the terminal
 */
template<typename T>
void Vector<T>::print()
{
  for (int i = 0; i < dimension_; i++)
    std::cout << vector_cells_[i] << std::endl;
}