// Philip Calderon
// trees.h

#ifndef TREES_H
#define TREES_H

//System Libraries
#include <iostream>
#include <cstdlib>

using namespace std;

class Trees
{
public:
        Trees();
        virtual ~Trees();

        //Add to the tree
        void addLeaf(int);

        //Print tree
        void print();

        //Delete
        void removeNode(int);
        Node* returnNode(int);
        int findsmallest();

private:
    struct Node
    {
        int data;
        Node* left;
        Node* right;
    };

    Node* root;
    Node* createLeaf(int);

    void addLeafp(int, Node*);
    void printp(Node*);
    void removeNodep(int, Node*);

    Node* returnNodep(int, Node*);
    int findsmallestp(Node*);
    void removeRootMatch();
    void removeMatch(Node*, Node*, bool);
};

#endif // TREES_H
