/*
 * Fufezan Mihai, 2012, lab06, ex 03
 *
 * Starting from the example that uses Matrix class, consider as private
 * attributes the matrix given by a double pointer to allocate an array of
 * pointers to the rows of the matrix (or, simple pointer to the contiguous
 * dynamic allocation of the matrix), and two private attributes of type int for
 * the number of rows and columns. The two-parameter constructor will
 * dynamically allocate space for the array by initializing the elements with 0.
 *
 * Implement an explicit destructor to free up the matrix space. Define a public
 * method void setElement(int r, int c, int v) that will set an element with the
 * value v, on row r and column c. Declare a global function void
 * readMatrix(Matrix m) that will have as parameter a matrix object that will
 * have the dimensions validated in main() so that the dimensions are correct if
 * they are >=1 and <= 10. The function will read the elements of the matrix
 * from the keyboard (it will also use the public method setElement()). The
 * method displayMatrix() from the class will be defined as a global function
 * just like readMatrix() considering the getElement() public method. The method
 * of displaying a column will not validate the column number, the column being
 * validated in main().
 *
 * Fill in the written code specific methods for:
 * - displaying the elements from the main diagonal of the matrix, in case the
 * matrix is square; if not, display a significant message.
 * - displaying the elements which are below the secondary diagonal.
 * - displaying a matrix that has identical dimensions with the original matrix
 * and its elements can have as possible values 0’s (if the corresponding
 * element is less than a previously read value of the threshold) or 1
 * (otherwise), and check if the matrix is rare, >= 67% of the elements are
 * zero);
 *
 * Redo the application in which you consider the getElement() and
 * setElement() private methods and the readMatrix() and displayMatrix()
 * functions, public member methods within the class.
 */

#include <iostream>

using namespace std;

class Matrix {
  int **matrix, rows, cols;

public:
  Matrix(int rows, int cols) {
    this->rows = rows;
    this->cols = cols;

    matrix = new int *[rows];
    for (int i{}; i < rows; i++)
      matrix[i] = new int[cols]{};
    cout << "\nMatrix space allocated.\n";

    cout << "\nEnter the elements of the matrix(" << rows << "x" << cols
         << "):\n";
    for (int i{}; i < rows; i++) {
      cout << "line [" << i << "] = ";
      for (int j{}; j < cols; j++) {
        cin >> matrix[i][j];
      }
    }
  }

  ~Matrix() {
    cout << "\nCalling destructor\n";
    for (int i{}; i < rows; i++)
      delete[] matrix[i];
    delete[] matrix;
  }

  void displayMatrix() {
    cout << "\nMatrix elements: ";
    for (int i{}; i < rows; i++) {
      cout << '\n';
      for (int j{}; j < cols; j++)
        cout << getElement(i, j) << ' ';
    }
    cout << '\n';
  }

  void readMatrix();

  void displayColumn(int col);

  void setElement(int r, int c, int v) { matrix[r][c] = v; }
  int getElement(int row, int col);

  void printDiagonal();
  void printUnderDiagonal();
  void binaryMatrix();
};

int main() {
  Matrix *a = new Matrix(1, 1);
  Matrix *b = new Matrix(3, 3);

  a->readMatrix();

  cout << "\ndisplaying B\n";
  b->displayMatrix();
  cout << "\ndisplaying A\n";
  a->displayMatrix();

  a->printDiagonal();
  a->printUnderDiagonal();
  a->binaryMatrix();
}

int Matrix::getElement(int row, int col) { return matrix[row][col]; }

void Matrix::displayColumn(int col) {
  if (col < 0 || col >= cols) { // validare de facut in main
    cout << "\nColumn #" << col << " does not exist in the matrix!\n";
  } else {
    cout << "\nElements of column #" << col << ": ";
    for (int i = 0; i < rows; i++) {
      cout << getElement(i, col) << ' ';
    }
  }
}

void Matrix::printDiagonal() {
  cout << "\nPrinting diagonal:\n";
  if (rows != cols) {
    cout << "Matrix isn't square!\n";
    return;
  }

  for (int i{}; i < rows; i++)
    cout << matrix[i][i] << ' ';
  cout << '\n';
}

void Matrix::printUnderDiagonal() {
  cout << "\nPrinting elements under the diagonal:\n";
  if (rows != cols) {
    cout << "Matrix isn't square!\n";
    return;
  }

  for (int i{1}; i < rows; i++) {
    for (int j{}; j < cols - 1; j++) {
      if (j < i)
        cout << matrix[i][j];
      else
        cout << ' ';
      cout << ' ';
    }
    cout << '\n';
  }
}

void Matrix::binaryMatrix() {
  int threshold, count{};
  cout << "\nEnter a threshold value: ";
  cin >> threshold;

  cout << "\nThe resulting matrix is:\n";
  for (int i{}; i < rows; i++) {
    for (int j{}; j < cols; j++) {
      if (matrix[i][j] >= threshold) {
        cout << 1;
        count++;
      } else
        cout << 0;
      cout << ' ';
    }
    cout << '\n';
  }

  cout << "\nThe resulting matrix is ";
  if ((float)rows * cols / count < 0.67f)
    cout << "not ";
  cout << "rare.\n";
}

void Matrix::readMatrix() {
  int x;

  // deallocate old matrix
  for (int i{}; i < rows; i++)
    delete[] matrix[i];
  delete[] matrix;

  cout << "Enter the new dimensions of the matrix: ";
  cin >> rows >> cols;

  // reallocate matrix
  matrix = new int *[rows];
  for (int i{}; i < rows; i++)
    matrix[i] = new int[cols];

  // read matrix
  for (int i{}; i < rows; i++) {
    cout << "[" << i << "]: ";
    for (int j{}; j < cols; j++) {
      cin >> x;
      setElement(i, j, x);
    }
  }
}
