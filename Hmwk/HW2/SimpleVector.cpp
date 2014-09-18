// Philip Calderon
// 9/15/2014

#include "SimpleVector.h"
#include <iostream>
#include <ctime>

int main(int argc, char **argv)
{
    int size = 10;
    int howManyToPush = 5;
    int howManyToPull = 2;
    int randomNum = 1;

    SimpleVector<int> list(size);

    // Initialze starting vector
    std::cout << "Initializing a vector with a size " << size << " with random 1-digit integers...\n\n"
    for (int i = 0; i < size; i++)
    {
        list[i] = rand() % 9 + 2;
    }

    // Print starting vector to show its contents
    for (int i = 0; i < list.size(); i++)
    {
        std::cout << list.getElementAt(i) << " ";
    }
    std::cout << "Demonstrating SimpleVector::push()\n";

    // Push a number of elements into the vector
    for (int i = 0; i < howManyToPush; i++)
    {
        // Pushing a random number into the vector
        randomNum = rand() % 200 + 2;
        std::cout << "Pushing: " << randomNum << endl;
        list.push(randomNum);
        std::cout << "The Vector's new size: " << list.size() << endl;
        std::cout << "The Vector's new capacity: " << list.capacity() << endl;
        std::cout << "The Vector's new list: ";
        for (int i = 0; i < list.size(); i++)
        {
            std::cout << list.getElementAt(i) << " ";
        }
        std::cout << endl << endl;
    }
    std::cout << endl << endl << endl;
    std::cout << "Demonstrating a SimpleVector::pull()\n";
    for (int i = 0; i < list.size(); i++)
    {
        std::cout << list.getElementAt(i) << " ";
    }
    std::cout << endl << endl;
    howManyToPull = list.size();
    for (int i = 0; i < howManyToPull; i++)
    {
        std::cout << "Now Pulling: " << list.getElementAt(list.size() - 1) << endl;
        list.pull();
        std::cout << "The Vector's new size: " << list.size() << endl;
        std::cout << "The Vector's new capacity: " << list.capacity() << endl;
        std::cout << "The Vector's new list: ";
        for (int i = 0; i < list.size(); i++)
        {
            std::cout << list.getElementAt(i) << " ";
        }
        std::cout << endl;
    }
    std::cout << endl;

    return 0;
}
