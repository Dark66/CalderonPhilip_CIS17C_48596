// File: stack.cpp
// Philip Calderon
// November 10, 2014
// Project 1

#ifndef SIMP_H_INCLUDED
#define SIMP_H_INCLUDED

#include <stack>
#include <vector>

using namespace std;
class sImp
{
public:
    sImp()
    {
        stkI.push(6); // Ends Here (If reversed it just ends first turn)
        stkI.push(5);
        stkI.push(4);
        stkI.push(3);
        stkI.push(2);
        stkI.push(1);
        stkI.push(0); // Starts here
    }

    void sLow()
    {
        stkI.pop();
    }

    int getS()
    {
        return stkI.top();
    }

private:
    stack<int> stkI;
};

#endif // STACKIMP_H_INCLUDED
