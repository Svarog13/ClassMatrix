#include "matrix.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>

template <typename T>
Matrix<T>::Matrix(int numRows, int numCols) : rows(numRows), cols(numCols) {
    data = new T * [rows];
    for (int i = 0; i < rows; ++i) {
        data[i] = new T[cols]();
    }
}

template <typename T>
Matrix<T>::~Matrix() {
    for (int i = 0; i < rows; ++i) {
        delete[] data[i];
    }
    delete[] data;
}

template <typename T>
void Matrix<T>::fillFromKeyboard() {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << "Enter element [" << i << "][" << j << "]: ";
            std::cin >> data[i][j];
        }
    }
}

template <typename T>
void Matrix<T>::fillRandomly(T minValue, T maxValue) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            data[i][j] = rand() % (maxValue - minValue + 1) + minValue;
        }
    }
}

template <typename T>
void Matrix<T>::print() {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << std::setw(4) << data[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& other) const {
    if (rows != other.rows || cols != other.cols) {
        std::cout << "Matrix dimensions don't match for addition." << std::endl;
        return Matrix<T>(0, 0);
    }

    Matrix<T> result(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result.data[i][j] = data[i][j] + other.data[i][j];
        }
    }
    return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T>& other) const {
    if (rows != other.rows || cols != other.cols) {
        std::cout << "Matrix dimensions don't match for subtraction." << std::endl;
        return Matrix<T>(0, 0);
    }

    Matrix<T> result(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result.data[i][j] = data[i][j] - other.data[i][j];
        }
    }
    return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& other) const {
    if (cols != other.rows) {
        std::cout << "Matrix dimensions don't match for multiplication." << std::endl;
        return Matrix<T>(0, 0);
    }

    Matrix<T> result(rows, other.cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < other.cols; ++j) {
            result.data[i][j] = 0;
            for (int k = 0; k < cols; ++k) {
                result.data[i][j] += data[i][k] * other.data[k][j];
            }
        }
    }
    return result;
}