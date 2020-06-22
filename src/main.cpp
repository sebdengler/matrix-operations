#include <iostream>

#include "matrix.h"
#include "matrix.cpp"

#include "vector.h"
#include "vector.cpp"


int main (int argc, char** argv)
{
  std::cout << "Initialize matrices ... ";
  
  Matrix<int> m1(3,4);
  Matrix<int> m2(4,3);
  Matrix<int> m3(3,3);
  Matrix<int> m4(2,2);
  Matrix<int> m5(2,2);
  Matrix<int> m6(2,2);
  Matrix<int> m7(2,2);

  std::cout << "done" << std::endl;

  std::cout << "Set entries of matrices ... ";

  m1 = {{2, 2, 2, 2},
        {2, 2, 2, 2},
        {2, 2, 2, 2}};
  m2 = {{1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {1, 2, 3}};

  m4 = {{1, 2},
        {3, 4}};
  m5 = {{21, 22},
        {23, 24}};

  std::cout << "done" << std::endl;

  std::cout << "Initialize vectors ... ";

  Vector<int> v1(3);
  Vector<int> v2(3);
  Vector<int> v3(3);
  Vector<int> v4(3);
  Vector<int> v5(4);
  Vector<float> v6(2);
  Vector<float> v7(2);
  Vector<float> v8(2);

  std::cout << "done" << std::endl;

  std::cout << "Set entries of vectors ... ";

  v1 = {1, 2, 3};
  v2 = {7, 8, 9};
  v6 = {1.1, 2.2};
  v7 = {5.4, 3.6};

  std::cout << "done" << std::endl;

  std::cout << "--- Do matrix multiplication: ---" << std::endl;

  m3 = m1 * m2;

  std::cout << "-> m1:" << std::endl;
  m1.print();
  std::cout << "-> m2:" << std::endl;
  m2.print();
  std::cout << "-> m3 = m1 * m2:" << std::endl;
  m3.print();

  std::cout << "--- Do matrix addition: ---" << std::endl;

  m6 = m4 + m5;

  std::cout << "-> m4:" << std::endl;
  m4.print();
  std::cout << "-> m5:" << std::endl;
  m5.print();
  std::cout << "-> m6 = m4 + m5:" << std::endl;
  m6.print();

  std::cout << "--- Do scalar multiplication of matrix: ---" << std::endl;

  m7 = m4 * 2;

  std::cout << "-> m4:" << std::endl;
  m4.print();
  std::cout << "-> m7 = m4 * 2:" << std::endl;
  m7.print();


  std::cout << "--- Get dot product of vectors: ---" << std::endl;

  int x = v1 * v2;

  std::cout << "-> v1:" << std::endl;
  v1.print();
  std::cout << "-> v2:" << std::endl;
  v2.print();
  std::cout << "-> v1 * v2 = " << x << std::endl;

  std::cout << "--- Do vector addition: ---" << std::endl;

  v3 = v1 + v2;

  std::cout << "-> v1:" << std::endl;
  v1.print();
  std::cout << "-> v2:" << std::endl;
  v2.print();
  std::cout << "-> v3 = v1 + v2:" << std::endl;
  v3.print();

  std::cout << "--- Do scalar multiplication of vector: ---" << std::endl;

  v4 = v1 * 4;

  std::cout << "-> v1:" << std::endl;
  v1.print();
  std::cout << "-> v4 = v1 * 4:" << std::endl;
  v4.print();

  std::cout << "--- Do matrix/vector multiplication: ---" << std::endl;

  v5 = m2 * v1;

  std::cout << "-> m2:" << std::endl;
  m2.print();
  std::cout << "-> v1:" << std::endl;
  v1.print();
  std::cout << "-> v5 = m2 * v1:" << std::endl;
  v5.print();

  std::cout << "--- Add vectors of type float: ---" << std::endl;

  v8 = v6 + v7;

  std::cout << "-> v6:" << std::endl;
  v6.print();
  std::cout << "-> v7:" << std::endl;
  v7.print();
  std::cout << "-> v8 = v6 + v7:" << std::endl;
  v8.print();

  std::cout << "--- Show exception handling: ---" << std::endl;
  
  try
  {
    Matrix<int> m8(0,3);
  }
  catch (std::invalid_argument& ex)
  {
    std::cerr << "Error: " << ex.what() << std::endl;
  }

  return 0;
}