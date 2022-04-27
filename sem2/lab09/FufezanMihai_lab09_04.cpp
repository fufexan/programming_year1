/*
 * Fufezan Mihai, 2012, lab09, ex 04
 *
 * Starting with the matrix 5-th example, verify/resolve the following tasks:
 * a. reading/writing a matrix with dimensions from KB;
 * b. test all the overloaded operators. Implement variants in which member
 * methods are used for overloading of operators.
 * c. displays the elements located on both diagonals.
 * d. implement matrix operations using member methods.
 */

#include <iostream>
using namespace std;

const int lines = 2;
const int columns = 3;

class Matrix {
  int rows;
  int cols;
  int *elems;

public:
  Matrix();
  Matrix(int rows, int cols);
  Matrix(const Matrix &);
  ~Matrix() { delete[] elems; }

  int &operator()(int row, int col);
  Matrix &operator=(const Matrix &);
  Matrix operator+(Matrix &); // mMatrix::ethod
  Matrix operator-(Matrix &);
  Matrix operator*(Matrix &);

  int getRows() { return rows; }
  int getCols() { return cols; }
  void init(int r, int c);
  void read();
  void display();
};

Matrix::Matrix() : rows(lines), cols(columns) {
  elems = new (nothrow) int[rows * cols];
}

Matrix::Matrix(int r, int c) : rows(r), cols(c) {
  elems = new (nothrow) int[rows * cols];
}

Matrix::Matrix(const Matrix &m) : rows(m.rows), cols(m.cols) {
  int n = rows * cols;
  if (elems)
    delete[] elems;
  elems = new (nothrow) int[n];
  for (int i = 0; i < n; i++)
    elems[i] = m.elems[i];
}

void Matrix::init(int r, int c) {
  rows = r;
  cols = c;
  if (elems)
    delete[] elems;
  elems = new (nothrow) int[rows * cols];
}

int &Matrix::operator()(int row, int col) { return elems[row * cols + col]; }
Matrix &Matrix::operator=(const Matrix &m) {
  if (this != &m) {
    delete[] elems;
    rows = m.rows;
    cols = m.cols;
    int n = rows * cols;
    elems = new (nothrow) int[n];
    for (int i = 0; i < n; i++)
      elems[i] = m.elems[i];
  }
  return *this;
}

Matrix Matrix::operator+(Matrix &p) {
  Matrix m(p.rows, p.cols);
  for (int r = 0; r < p.rows; ++r)
    for (int c = 0; c < p.cols; ++c)
      m(r, c) = p(r, c) + elems[r * cols + c];
  return m;
}
Matrix Matrix::operator-(Matrix &p) {
  Matrix q = *this;
  Matrix m(p.rows, p.cols);
  for (int r = 0; r < p.rows; ++r)
    for (int c = 0; c < p.cols; ++c)
      m(r, c) = p(r, c) - q(r, c);
  return m;
}
Matrix Matrix::operator*(Matrix &p) {
  Matrix q = *this;
  Matrix m(p.rows, q.cols);
  for (int r = 0; r < p.rows; ++r)
    for (int c = 0; c < q.cols; ++c) {
      m(r, c) = 0;
      for (int i = 0; i < p.cols; ++i)
        m(r, c) += p(r, i) * q(i, c);
    }
  return m;
}

void Matrix::read() {
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < cols; j++) {
      cout << "[" << i << "][" << j << "] = ";
      cin >> elems[cols * i + j];
    }
}
void Matrix::display() {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++)
      cout << elems[cols * i + j] << "\t";
    cout << endl;
  }
}

int main() {
  int i, j;

  cout << "Enter the dimensions of a matrix: ";
  cin >> i >> j;
  Matrix m(i, j);

  cout << "\nEnter the matrix:\n";
  m.read();

  int l, c;
  cout << "\nVerify the overloaded operator() for an element at the specified "
          "position: ";
  cin >> l >> c;

  if ((l >= 1 && l <= m.getRows()) && (c >= 1 && c <= m.getCols()))
    cout << "Element m[" << l << "][" << c << "] = " << m(l - 1, c - 1) << endl;
  else
    cout << "Invalid indices!" << endl;

  cout << "\nCopy constructor usage:" << endl;
  if (m.getRows() > 0 && m.getCols() > 0) {
    Matrix mcopy = m;
    cout << "Matrix \"mcopy\" is:" << endl;
    mcopy.display();
  } else
    cout << "Invalid dimensions for copy-instantiated matrix!" << endl;

  cout << "\nInstantiating a new matrix object:\n";
  Matrix n(lines, columns);
  cout << "\nEnter matrix:\n";
  n.read();
  cout << "\nMatrix \"n\" is:" << endl;
  n.display();

  cout << "\nOverloading operator=, copying matrix \"m\" in matrix \"n\"\n";
  if (m.getRows() == n.getRows() && m.getCols() == n.getCols()) {
    n = m;
    for (i = 0; i < lines; i++) {
      for (j = 0; j < columns; j++)
        cout << n(i, j) << "\t";
      cout << endl;
    }
  } else
    cout << "\nMatrices have different dimensions, thus can't be copied.\n";

  cout << "\nInstantiating a new matrix object \"m1\":\n";
  Matrix m1(lines, columns);
  cout << "Enter matrix:";
  m1.read();
  cout << "\nMatrix \"m1\" is:\n";
  m1.display();

  Matrix m2(lines, columns);
  cout << "\nOverloading operator+\n";
  if (m.getRows() == m1.getRows() && m.getCols() == m1.getCols()) {
    m2 = m + m1;
    cout << "m+m1:\n";
  }
  m2.display();

  cout << "\nOverloading operator-\n";
  if (m.getRows() == m1.getRows() && m.getCols() == m1.getCols()) {
    m2 = m - m1;
    cout << "m-m1:\n";
  }
  m2.display();

  cout << "\nEnter matrix \"m3\" (number of rows has to be equal with number "
          "of columns): "
       << endl;
  cin >> l >> c;
  Matrix m3;
  if (l > 0 && c > 0)
    m3.init(l, c);
  else
    cout << endl
         << "Negative dimensions! Matrix will be created using default "
            "dimensions (2 rows, 3 cols)\n";
  m3.read();
  cout << endl << "Matrix \"m3\" is:" << endl;
  m3.display();

  cout << "\nOverloading operator*\n";
  if (m.getCols() == m3.getRows()) {
    Matrix m4(m.getRows(), m3.getCols());
    m4 = m * m3;
    cout << "m*m3:\n";
    m4.display();
  } else
    cout << "Matrices can't be multiplied - number of rows != number of cols\n";
}