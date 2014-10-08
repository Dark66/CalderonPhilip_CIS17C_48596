// Philip Calderon
// October 5, 2014
// File: main.cpp

#include <iostream>
#include "LnkdLst.h"

using namespace std;

int main(int argc, char** argv)
{
    //Creating the linked list
    LnkdLst<int> list(0);

    //Append 3 more chains
    int clinks=3;
    for(int i=1;i<=clinks;i++)
    {
        list.append(i);
    }

    //Print the data
    cout<<list.toString()<<endl;

    //Print First
    cout<<list.first()<<endl;

    //Print Last
    cout<<list.last()<<endl;

    //Prepend add one
    list.prepend(12);

    //Print the data
    cout<<list.toString()<<endl;

    //Extract chain with value 10
    list.extract(12);

    //Print the data
    cout<<list.toString()<<endl;

    //Insert Number with Position (InsertAfter)
    list.insertA(22,4);

    //Print the data
    cout<<list.toString()<<endl;

    //Insert Number with Position (InsertBefore)
    list.insertB(17,5);

    //Print the data
    cout<<list.toString()<<endl;

    //End program
    return 0;
}
