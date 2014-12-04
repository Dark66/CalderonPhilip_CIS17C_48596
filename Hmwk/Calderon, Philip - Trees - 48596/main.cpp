// Philip Calderon
// Creating a Tree then adding a number to it

//System Libraries
#include <iostream>
#include <cstdlib>

//Created Libraries
#include "Trees.h"

using namespace std;



int main(int argc, char** argv)
{
    int treeData[16]={55,86,22,7,33,68,17,52,13,100,81,1,2,70,87,80};
    Trees theTree;

    cout << "Printing the tree: Before adding numbers." << endl;
    theTree.print();

    cout << "Printing the tree: After adding numbers." << endl;

    for(int i = 0; i < 16; i++)
    {
        theTree.addLeaf(treeData[i]);
    }
    theTree.print();
    cout << endl;

    cout << "Removing number 52" << endl;
    theTree.removeNode(52);
    theTree.print();
    cout << endl;

    cout << "Adding number 77" << endl;
    theTree.addLeaf(77);
    theTree.print();
    return 0;
}
