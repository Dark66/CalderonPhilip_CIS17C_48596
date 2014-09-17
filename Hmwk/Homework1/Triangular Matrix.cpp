// Author: Philip Calderon
// Date: September 10, 2014
// Title: One-Dimensional, Two-Dimensional Matrix, and
// Triangular Matrix with the implementation of floats and integers

#include<iostream>
#include "TriangularMatrix.h"

using namespace std;

int main(int argc, char *argv[])
{
    // Initialize the dimensions of the one-dimentional array and triangular matrix
    int rows = 10;
    int columnsPerLine = 10;
    std::cout << "Start of the demo. \n";

    // Start of (int) data type
    // Initialize a TriangularMatrix class that can handle int data types
    TriangularMatrix<int> triangularMatrixInt(rows, columnsPerLine);

    // Fill the one-dimentional array and triangular matrix with random numbers
    int *array1dInt = triangularMatrixInt.FillArray();
    int **arrayTriangularInt = triangularMatrixInt.FillArray(rows, array1dInt);

    // Print the one-dimentional array
    std::cout << "Integer of the one-dimentional arra: \n";
    triangularMatrixInt.PrintArray(array1dInt);

    //Print the triangular matrix array
    std::cout << "Integer of the  triangular matrix: \n";
    triangularMatrixInt.PrintArray(arrayTriangularInt, array1dInt);

    // Destroy the arrays
    triangularMatrixInt.DestroyArray(arrayTriangularInt);
    triangularMatrixInt.DestroyArray(array1dInt);

    std::cout<< "Start of the float data type.";

    // Initialize a float data type for triangular matrix
    TriangularMatrix<float> triangularMatrixFloat(rows, columnsPerRow);

    // Fill the one-dimensional array and triangular matrix with random numbers
    float *array1dFloat = triangularMatrixFloat.FillArray();
    float **arrayTriangularFloat = triangularMatrixFloat.FillArray(array1dFloat);

    // Print the arrays
    std::cout << "Float one-dimentional array: \n";
    triangularMatrixFloat.PrintArray(array1dFloat);
    std::cout << "Float tri matrix: \n";
    triangularMatrixFloat.PrintArray(arrayTriangularFloat, array1dFloat);

    // Destroy arrays
    triangularMatrixFloat.DestroyArray(arrayTriangularFloat);
    triangularMatrixFloat.DestroyArray(array1dFloat);
    std::cout << "\n Exit stage right... come again.";

    return 0;
}
