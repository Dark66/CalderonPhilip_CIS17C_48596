// Philip Caldeorn
// October 27, 2014
// Hash_Comparison with linear and binary searches

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

//Function Prototypes
char getRandom(char *,int);
int linearSearch(char *,int);
int binarySearch(char *,int);
void sort(char *,int);
unsigned int sHash(string);

int main(int argc, char** argv)
{
    //Each of these takes different times if you run them with different
    //variables multiple times
    //Size 20 to N 10 takes 57.649 seconds
    //Size 20 to N 20 takes 58.130 seconds
    //Size 20 to N 30 takes 58.430/ 58.881 seconds
    //Size 30 to N 40 takes 67.552 seconds
    //Size 10 to N 50 takes 49.709 seconds
    //So as the size decreses and N increases it takes less time
    //But as N increases when the size is a set it increases in compiling times
    int SIZE = 20;
    long long N = 50;
    char array[SIZE];

    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));

    //Generate a random string
    getRandom(array,SIZE);
    cout<<"The Random String is: "<<array<<endl;

    //Linear Search
    int timerOneStart = time(0);
    for(int i=0;i<N;i++)
    {
        linearSearch(array,SIZE);
    }

    int timerOneEnd = time(0);
    cout<<"The Linear Search Time was = "<<timerOneEnd-timerOneStart<<endl;

    //Binary Search (sorted first)
    sort(array,SIZE);
    cout<<"The Sorted String array is: "<<array<<endl;
    int timerTwoStart = time(0);
    for(int i=0;i<N;i++)
    {
        binarySearch(array,SIZE);
    }

    int timerTwoEnd = time(0);
    cout<<"Binary Search Time was = "<<timerTwoEnd-timerTwoStart<<endl;

    //Hash Function (must convert to a string)
    string bArray=string(array);
    int timerThreeStart = time(0);
    N=100000000;
    for(int i=0;i<N;i++)
    {
        sHash(bArray);
    }

    int timerThreeEnd = time(0);
    cout<<"Hash Time Taken was = "<<timerThreeEnd-timerThreeStart<<endl;

    return 0;
}

unsigned int sHash(string str)
{
    unsigned int b = 845961;
    unsigned int a = 68456;
    unsigned int hash = 0;
    for(std::size_t i = 0; i < str.length(); i++)
    {
        hash = hash * a + str[i];
        a = a * b;
    }

    return (hash & 0x7FFFFFFF);
}

//Sort function
void sort(char *a,int l)
{
    //Find the minimum at the start
    for(int i=0;i<l-1;i++)
    {
        //Swap the larger values through the list
        for(int j=i+1;j<l;j++)
        {
            //Check the swap positions
            if(a[i]>a[j])swap(a[i],a[j]);
        }
    }
}


int binarySearch(char *b,int l)
{
    //Find numbers 1-9 or any options for strings
    int find = 1; //finds the start position
    int firstNum = 0; //First postion
    int lastNum = l - 1; //Last position in the string
    int middleNum;
    int position =-1; // Goes to the next position
    bool found = false;
    while(!found&&firstNum<=lastNum)
    {
        middleNum =(firstNum + lastNum)/2;
        if((b[middleNum]-48)==find)
        {
            found = true;
            position = middleNum;
        }
        else if((b[middleNum]-48)>find)
        {
            lastNum = middleNum - 1;
        }
        else
        {
            firstNum = middleNum + 1;
        }

        return position;
    }
}

int linearSearch(char *a, int l)
{
    //Find numbers 1-9 randomly
    int find=1+rand()%9;
    int firstNum = 0,
    lastNum = l-1,
    middleNum,
    position = -1;
    bool found=false;
    while(!found&&firstNum<=lastNum)
    {
        middleNum=(firstNum+lastNum)/2;
        if((a[middleNum]-48)==find)
        {
            found = true;
            position = middleNum;
        }
        else if((a[middleNum]-48)>find)
        {
            lastNum = middleNum - 1;
        }
        else
        {
            firstNum = middleNum + 1;
        }

        return position;
    }
}

char getRandom(char *n,int l)
{
    static const char randomNum[]= "0123456789";
    //We can use any of these in order for the random number
    // "0123456789"
    //"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    //"abcdefghijklmnopqrstuvwxyz";
    //"abcdefghij";
    for(int i=0;i<l;i++)
    {
        n[i]=randomNum[rand()%(sizeof(randomNum)-1)];
    }
    n[l]=0;
}
