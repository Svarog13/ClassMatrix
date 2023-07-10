#ifndef MATRIX_H
#define MATRIX_H

template <typename T>
class Matrix {
private:
    T** data;
    int rows;
    int cols;

public:
    Matrix(int numRows, int numCols);
    ~Matrix();

    void fillFromKeyboard();
    void fillRandomly(T minValue, T maxValue);
    void print();

    Matrix<T> operator+(const Matrix<T>& other) const;
    Matrix<T> operator-(const Matrix<T>& other) const;
    Matrix<T> operator*(const Matrix<T>& other) const;
    Matrix<T> operator/(T scalar) const;

    T findMin() const;
    T findMax() const;
};

#endif