// Philip Calderon
// October 5, 2014
// File: LnkdLst.h

#ifndef LNKDLST_H_INCLUDED
#define LNKDLST_H_INCLUDED

#include <sstream>
#include <string>

using namespace std;

template <class T>
class LnkdLst
{
public:
    LnkdLst(T);
    LnkdLst(const LnkdLst &);
    void append(T);
    void prepend(T);
    void extract(T);
    void insertA(T,T);
    void insertB(T,T);
    string first();
    string last();
    string toString();
    virtual ~LnkdLst();

private:
    struct Node {
    T data;
    Node *next;
    };

    Node *head;
    Node *worker;
};

template <class T>
LnkdLst<T>::LnkdLst(T n)
{
    Node *clink = new Node;
    clink->data = n;
    clink->next = NULL;
    head = clink;
}

template <class T>
LnkdLst<T>::LnkdLst(const LnkdLst& obj){}

template <class T>
void LnkdLst<T>::insertA(T n,T p)
{
    Node *worker1 = new Node;
    worker1->data = n;
    worker1->next = NULL;
    Node *worker2 = head;

    for(int i=0;i<p-1;i++)
    {
        worker2=worker2->next;
    }

    worker1->next = worker2->next;
    worker2->next = worker1;
}

template <class T>
void LnkdLst<T>::insertB(T n, T p)
{
    Node *worker1 = new Node;
    worker1->data = n;
    worker1->next = NULL;
    Node *worker2 = head;

    for(int i=0;i<p-3;i++)
    {
        worker2 = worker2->next;
    }

    worker1->next = worker2->next;
    worker2->next = worker1;
}

template <class T>
void LnkdLst<T>::extract(T n)
{
    Node *worker;
    Node *prev;

    if(head->data==n)
    {
        worker = head->next;
        delete head;
        head = worker;
    }
    else
    {
        worker=head;
        while(worker!=prev&&worker->data!=n)
        {
            prev = worker;
            worker = worker->next;
        }

        if(worker)
        {
            prev->next = worker->next;
            delete worker;
        }
    }
}

template <class T>
void LnkdLst<T>::prepend(T n)
{
    Node *prev = new Node;
    prev->data = n;
    prev->next = head;
    head = prev;
}

template <class T>
void LnkdLst<T>::append(T n)
{
    Node *prev;
    if(head)
    {
        worker = head;
        do{
        prev = worker;
        }while(worker=worker->next);

        Node *clink = new Node;
        clink->data = n;
        clink->next = NULL;
        prev->next = clink;
    }else{
        Node *clink=new Node;
        clink->data = n;
        clink->next = NULL;
        head = clink;
    }
}

template <class T>
string LnkdLst<T>::last()
{
    stringstream ss;
    string build = "";
    if(head)
    {
        worker=head;
        do{
            if(worker->next==NULL)
            {
                ss<<worker->data;

                string data;
                ss>>data;
                build = data;
                return data;
            }
        }while(worker=worker->next);
    }
}

template <class T>
string LnkdLst<T>::first()
{
    stringstream ss;
    string build = "";
    worker = head;
    ss<<worker->data;

    string data;
    ss>>data;
    build = data;
    return data;
}

template <class T>
string LnkdLst<T>::toString()
{
    string build = "";
    char counter = 50;
    if(head)
    {
        worker = head;
        do{
            build+=("Data element in the list ->");
            stringstream ss;
            ss<<worker->data;

            string data;
            ss>>data;
            build+=data;
            build+="\n";
        }while(worker=worker->next);
    }

    return build;
}

template <class T>
LnkdLst<T>::~LnkdLst()
{
    if(head)
    {
        do{
            worker = head;
            head = head->next;
            delete worker;
        }while(head);
    }
}

#endif // LNKDLST_H_INCLUDED
