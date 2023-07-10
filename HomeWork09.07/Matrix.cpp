#include <iostream>
#include "matrix.h"

int main() {
    int numRows, numCols;
    std::cout << "Enter the number of rows: ";
    std::cin >> numRows;
    std::cout << "Enter the number of columns: ";
    std::cin >> numCols;

    Matrix<int> matrix(numRows, numCols);
    matrix.fillFromKeyboard();

    std::cout << "Matrix:" << std::endl;
    matrix.print();

    std::cout << "Min element: " << matrix.findMin() << std::endl;
    std::cout << "Max element: " << matrix.findMax() << std::endl;

    Matrix<int> randomMatrix(numRows, numCols);
    randomMatrix.fillRandomly(1, 10);

    std::cout << "Randomly generated matrix:" << std::endl;
    randomMatrix.print();

    Matrix<int> sumMatrix = matrix + randomMatrix;
    std::cout << "Sum of matrices:" << std::endl;
    sumMatrix.print();

    Matrix<int> diffMatrix = matrix - randomMatrix;
    std::cout << "Difference of matrices:" << std::endl;
    diffMatrix.print();

    Matrix<int> productMatrix = matrix * randomMatrix;
    std::cout << "Product of matrices:" << std::endl;
    productMatrix.print();

    Matrix<int> scalarDividedMatrix = matrix / 2;
    std::cout << "Matrix divided by scalar:" << std::endl;
    scalarDividedMatrix.print();

    return 0;
}
