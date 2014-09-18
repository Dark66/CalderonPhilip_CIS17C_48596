// Philip Calderon
// 9/15/2014

#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H

#include <iostream>
#include <new>      // Needed for exception
#include <cstdlib>  // Need for exit stage right

using namespace std;

template <class T>
class SimpleVector
{
private:
    T *_buffer;       // Pointer
    int _size;        // Size of the array
    int _capacity;
    void memError();  // Memory error handler
    void subError();  // Range error handler
public:
    // Default constructor
    SimpleVector()
    {
        _buffer = 0; _size = 0;
    }
    SimpleVector(int); //Declaration
    SimpleVector(const SimpleVector &); //Copy constructor declaration
    ~SimpleVector(); //Deconstructor
    void push(const T &element); // Adding elements to the top of the array
    void pull(); // Removing the top element of the array

    // Returns the array size
    int size() const
    {
        return _size;
    }

    int capacity() const
    {
        return _capacity;
    }

    // Accessor to return a specific element
    T getElementAt(int position);

    // Overloaded declaration
    T &operator[](const int &);
};

//Sets size of array and allocates memeory
template <class T>
SimpleVector<T>::SimpleVector(int s)
{
    _size = s;
    _capacity = s;

    // Allocate memory for the array.
    try
    {
        _buffer = new T[s];
    }

    catch (bad_alloc)
    {
        memError();
    }

    // Initialize the array.
    for (int count = 0; count < _size; count++)
    {
        *(_buffer + count) = 0;
    }
}

//Copy constructor
template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector &obj)
{
    // Copy the array size.
    _size = obj._size;

    // Allocate memory for the array.
    _buffer = new T[_size];
    if (_buffer == 0)
    {
        memError();
    }

    // Copy the elements of obj's array.
    for (int count = 0; count < _size; count++)
    {
        *(_buffer + count) = *(obj._buffer + count);
    }
}

//Deconstructor
template <class T>
SimpleVector<T>::~SimpleVector()
{
    if (_size > 0)
    {
        delete[] _buffer;
    }
delete[] _buffer;
}

// Termination of program if failed and desplays a message
template <class T>
void SimpleVector<T>::memError()
{
    cout << "ERROR:No allocation of memeory can be processed.\n";
    exit(EXIT_FAILURE);
}

//Subscript range error message and terminates program
template <class T>
void SimpleVector<T>::subError()
{
    cout << "ERROR: The subscript is out of range.\n";
    exit(EXIT_FAILURE);
}

template <class T>
void SimpleVector<T>::push(const T &element)
{
    if (_size == _capacity)
    {
    // ... expand array's capacity by 1
    int newCapacity = _capacity + 1;

    T *newBuffer = new T[newCapacity];

    //copy the array
    std::copy(_buffer, _buffer + _size, newBuffer);
    _capacity = newCapacity;

    //swap the old aray and stored array
    std::swap(_buffer, newBuffer);

    // Delete the stored array
    delete[] newBuffer;
    }

    _buffer[_size++] = element;
}

template <class T>
void SimpleVector<T>::pull()
{
    // Create a new array that has one less
    int newCapacity = _capacity - 1;
    T *newBuffer = new T[newCapacity];

    // Define for decrese in one for size and cap
    _capacity = newCapacity;
    _size--;

    // Copy data stored
    std::copy(_buffer, _buffer + _size, newBuffer);
    std::swap(_buffer, newBuffer);
    delete[] newBuffer;
}

// Returns the stored value
template <class T>
T SimpleVector<T>::getElementAt(int sub)
{
    if (sub < 0 || sub >= _size)
    {
        subError();
    }
    return _buffer[sub];
}

// Overloaded operator
template <class T>
T &SimpleVector<T>::operator[](const int &sub)
{
    if (sub < 0 || sub >= _size)
    {
        subError();
    }
    return _buffer[sub];
}
#endif
