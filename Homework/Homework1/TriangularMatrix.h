#ifndef _TRIANGULARMATRIX_H_
#define _TRIANGULARMATRIX_H_

#include <cstdlib>
#include <iostream>
#include <ctime>

template <class T>
class TriangularMatrix
{

//Initialize hidden data types
private:
    int _rows;
    int _columns;
    int _columnsPerRow;

//Initialize public data types
public:
    TriangularMatrix();
    TriangularMatrix(int rows, int columnsPerRow);
    ~TriangularMatrix();

    // One-Dementional array data types
    T* FillArray();
    void PrintArray(T *array_1d);
    void DestroyArray(T *array_1d);

    // Triangular array data types
    T** FillArray(T *array_1d);
    void PrintArray(T **arrayTriangular, T *array_1d);
    void DestroyArray(T **arrayTriangular);
};

//Initializing
template <class T>
TriangularMatrix<T>::TriangularMatrix()
{
    _rows = 0;
    _columns = 0;
    _columnsPerRow = 0;
}

template <class T>
TriangularMatrix<T>::TriangularMatrix(int rows, int columnsPerRow)
{
    _rows = rows;
    _columns = rows;
    _columnsPerRow = columnsPerRow;
}

template <class T>int columns = rows;
TriangularMatrix<T>::~TriangularMatrix()
{
    //This destroys the array from the main
}

// One-dementional array location
template <class T>
T* TriangularMatrix<T>::FillArray()
{
    T *array = new T[_columns];
    for (int column = 0; column < _columns; column++)
    {
        array[column] = rand() % 9 + 2;
    }

    return array;
}

//Print the one-dimentional array
template <class T>
void TriangularMatrix<T>::PrintArray(T *array)
{
    std::cout << std::endl;
    for (int column = 0; column < _columns; column++)
    {
        std::cout << array[column] << " ";
        if (column % _columnsPerRow == (_columnsPerRow - 1))
        {
            std::cout << std::endl;
        }
    }

    std::cout << std::endl;
}

// Destroy the one-dimentional array
template <class T>
void TriangularMatrix<T>::DestroyArray(T *array)
{
    delete[] array;
    //Makes sure array is set to value of NULL after it is deleted
    array = NULL;
}

// Triangular matrix location
template <class T>
T** TriangularMatrix<T>::FillArray(T *array_1d)
{
    // Declare the two dimentional
    // array and retrieve the number of rows
    T **array = new T*[_rows];

    // Number of columns in row
    for (int row = 0; row < _rows; row++)
    {
        array[row] = new T[array_1d[row]];
    }

    // Fill each entry of the array with random 2-digit numbers
    for (int row = 0; row < _rows; row++)
    {
        for (int column = 0; column < array_1d[row]; column++)
        {
            array[row][column] = rand() % 90 + 10;
        }
    }

    return array;
}

//Print the Triangular Matrix array
template <class T>
void TriangularMatrix<T>::PrintArray(T **array, T *array_1d)
{
    std::cout << std::endl;

    for (int row = 0; row < _rows; row++)
    {
        for (int column = 0; column < array_1d[row]; column++)
        {
            std::cout << array[row][column] << " ";
        }

        std::cout << std::endl;
    }

    std::cout << std::endl;
}

//Destroy the array
template <class T>
void TriangularMatrix<T>::DestroyArray(T **array)
{
    // Destroy columns.
    for (int row = 0; row < _rows; row++)
    {
        delete[] array[row];
    }

    // Destroy pointers.
    delete[] array;

    //Set array to NULL vaule after array is destroyed
    array = NULL;
}
#endif // TRIANGULARMATRIX_H_INCLUDED
