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

#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <initializer_list>
#include <stdexcept>


/**
 * @brief Templated column-vector class
 * @detail This templated class implements a column-vector of user-defined type.
 * It enables the addition of vectors as well as scalar multiplication and the
 * calculation of the dot product of two vectors.
 */
template<typename T>
class Vector
{
public:
  Vector(int dimension);

  ~Vector();

  /**
   * Get value at defined index
   */
  T const& at(int idx) const {return vector_cells_[idx];}

  /**
   * Set value at defined index
   */
  void set(const int& idx, const T& value) {vector_cells_[idx] = value;}

  /**
   * Get dimension
   */
  int const& getDimension() const {return dimension_;}

  void operator= (const std::initializer_list<T>& values);
  void operator= (const Vector<T>& v);

  T operator* (const Vector<T>& v);
  Vector operator* (const T& v);
  Vector operator+ (const Vector<T>& v);

  void print();

private:
  T* vector_cells_; /**< Pointer to entries of vector */

  int dimension_; /**< Dimension of vector */
};

#endif // VECTOR_H