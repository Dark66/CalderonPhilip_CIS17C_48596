// Philip Calderon
// trees.cpp

#include "Trees.h"

Trees::Trees()
{
    root = NULL;
}

Trees::~Trees()
{
    //dtor
}

Trees::Node* Trees::createLeaf(int data)
{
    Node* n = new Node;
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void Trees::addLeaf(int data)
{
    addLeafp(data, root);
}

void Trees::addLeafp(int data, Node* ptr)
{
    //Check if the current tree is empty
    if(root == NULL)
    {
        root = createLeaf(data);
    }

    //Check the left side of the tree (less than n)
    else if(data < ptr->data)
    {
        //If there is something there (recursive)
        if(ptr->left != NULL)
        {
            addLeafp(data, ptr->left);
        }

        //If nothing is there
        else
        {
            ptr->left = createLeaf(data);
        }
    }

    //Check the right side of the tree (greater than n)
    else if(data > ptr->data)
    {
        //If there is something there (recursive)
        if(ptr->right != NULL)
        {
            addLeafp(data, ptr->right);
        }

        //If nothing is there
        else
        {
            ptr->right = createLeaf(data);
        }
    }

    //If data is equal to same as original data
    else
    {
        cout << "The data " << data << " is already in the current tree" << endl;
    }
}

void Trees::print()
{
    printp(root);
    cout << endl;
}

void Trees::printp(Node* ptr)
{
    //Check to see if empty
    if(root != NULL)
    {
        //Possible to move to the left side of the tree
        if(ptr->left != NULL)
        {
            printp(ptr->left);
        }

        cout << ptr->data << " ";
        //Possibe to move to the right side of the tree
        if(ptr->right != NULL)
        {
            printp(ptr->right);
        }
    }
    else
    {
        cout << "The Tree is empty" << endl;
    }
}

Trees::Node* Trees::returnNode(int data)
{
    return returnNodep(data, root);
}

Trees::Node* Trees::returnNodep(int data, Node* ptr)
{
    //If the pointer is pointing to data
    if(ptr != NULL)
    {
        //Found the Node
        if(ptr->data == data)
        {
            return ptr;
        }
        else
        {
            //If less than n (recursive)
            if(data < ptr->data)
            {
                return returnNodep(data, ptr->left);
            }

            //If greater than n (recursive)
            else
            {
                return returnNodep(data, ptr->right);
            }
        }
    }
    else
    {
        return NULL;
    }
}

int Trees::findsmallest()
{
    findsmallestp(root);
}

int Trees::findsmallestp(Node* ptr)
{
    //If the Tree is Empty
    if(root == NULL)
    {
        cout << "The Tree is empty." << endl;
        return -1000;
    }

    //If the Tree is NOT Empty
    else
    {
        if(ptr->left != NULL)
        {
            return findsmallestp(ptr->left);
        }
        else
        {
            return ptr->data;
        }
    }
}

void Trees::removeNode(int data)
{
    removeNodep(data, root);
}

void Trees::removeNodep(int data, Node* parent)
{
    //If the tree was NOT Empty
    if(root != NULL)
    {
        //If the data was found / delete
        if(root->data == data)
        {
            removeRootMatch();
        }

        //If the data was not found
        else
        {
            //Left child (less than n)
            if(data < parent->data && parent->left != NULL)
            {
                parent->left->data == data ?
                removeMatch(parent, parent->left, true):
                removeNodep(data, parent->left);
            }

            //Right child (greater than n)
            else if(data > parent->data && parent->right != NULL)
            {
                parent->right->data == data ?
                removeMatch(parent, parent->right, false):
                removeNodep(data, parent->right);
            }
            else
            {
                cout << "The data " << data << " was not found in the current tree." << endl;
            }
        }
    }

    //If the tree is empty
    else
    {
        cout << "The tree is empty." << endl;
    }
}

void Trees::removeRootMatch()
{
    if(root != NULL)
    {
        Node* delPtr = root;
        int rootData = root->data;
        int smallestright;

        //No children
        if(root->left == NULL && root->right == NULL)
        {
            root = NULL;
            delete delPtr;
        }

        //1 Child
        //The child on right (greater than n)
        else if(root->left == NULL && root->right != NULL)
        {
            root = root->right;
            delPtr->right = NULL;
            delete delPtr;
        }

        //The child on left (less than n)
        else if(root->left != NULL && root->right == NULL)
        {
            root = root->left;
            delPtr->left = NULL;
            delete delPtr;
        }

        //2 Children
        else
        {
            smallestright = findsmallestp(root->right);
            removeNodep(smallestright, root);
            root->data = smallestright;
        }
    }
    else
    {
        cout<<"Can not remove root, the tree is empty!" << endl;
    }
}

void Trees::removeMatch(Node* parent, Node* match, bool left)
{
    if(root != NULL)
    {
        Node* delPtr;
        int matchData = match->data;
        int smallestright;

        //No Children
        if(match->left == NULL && match->right == NULL)
        {
            delPtr = match;
            left == true?parent->left = NULL:parent->right = NULL;
            delete delPtr;
        }

        //There is 1 Child
        // Right side child (greater than n)
        else if(match->left == NULL && match->right != NULL)
        {
            left == true?parent->left = match->right:parent->right = match->right;
            match->right = NULL;
            delPtr = match;
            delete delPtr;
        }

        // Left side child (less than n)
        else if(match->left != NULL && match->right == NULL)
        {
            left == true?parent->left = match->left:parent->right = match->left;
            match->left = NULL;
            delPtr = match;
            delete delPtr;
        }

        //2 Children
        else
        {
            smallestright = findsmallestp(match->right);
            removeNodep(smallestright, match);
            match->data = smallestright;
        }
    }
    //In the case that the tree is empty
    else
    {
        cout << "Can not remove the item doesn't match. The  Tree is empty." << endl;
    }
}
