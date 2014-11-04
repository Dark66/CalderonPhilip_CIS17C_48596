// Philip Caldeorn
// October 30, 2014
// Recursion
// Creating a Recursive savings function with a sum function used with logN (pow)

#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

//Function Prototypes
float Recursion(float, float, float);

//Execution Begins Here
int main(int argc, char** argv)
{
    float interest = 0.7;
    float years = 120;
    float pv = 3684;

    for(int i = 1; i <= years; i++)
    {
        // Savings
        // pv = present value
        // i = interest rate
        cout << Recursion(pv, interest, i) << endl;
    }

    return 0;
}

float Recursion(float pv, float i, float n)
{
    if(n==1)
    {
        return (pv*(1+i));
    }

    return(pv * pow((1+i), n));
}
