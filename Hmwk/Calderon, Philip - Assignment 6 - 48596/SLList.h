// Philip Calderon
// October 13, 2014
// SINGLY_LINKED_LIST

#ifndef SLLIST_H_INCLUDED
#define SLLIST_H_INCLUDED

#include <string>

template <class T>
class SLList
{
public:
    SLList();
    ~SLList();

    bool isEmpty();
    T const peekFirst();
    T const peekLast();
    void prepend(T);
    void append(T);
    T deleteFromHead();
    T deleteFromTail();
    void deleteNode(T);
    bool contains(T);

private:
    class Node
    {
    public:
        int data;
        Node *next;

        Node()
        {
            data = 0;
            next = NULL;
        }

        Node(int dataPortion, Node *nextNode = 0)
        {
            data = dataPortion;
            next = nextNode;
        }
    };

    Node *head;
    Node *tail;
};

template <class T>
SLList<T>::SLList()
{
    head = tail = NULL;
}

template <class T>
SLList<T>::~SLList()
{
    Node *p;
    while (!isEmpty())
    {
        p = head->next;
        delete head;
        head = p;
    }
}

template <class T>
bool SLList<T>::isEmpty()
{
    return head == NULL;
}

template <class T>
T const SLList<T>::peekFirst()
{
    return head->data;
}

template <class T>
T const SLList<T>::peekLast()
{
    return tail->data;
}

template <class T>
void SLList<T>::prepend(T newEntry)
{
    head = new Node(newEntry, head);
    if (tail == NULL)
    {
        tail = head;
    }
}

template <class T>
void SLList<T>::append(T newEntry)
{
    if (tail != NULL)
    {
        tail->next = new Node(newEntry);
        tail = tail->next;
    }
    else
    {
        head = tail = new Node(newEntry);
    }
}

template <class T>
T SLList<T>::deleteFromHead()
{
    T entry = head->data;
    Node *tmp = head;
    if (head == tail)
    {
        head = tail = NULL;
    }
    else
    {
        head = head->next;
    }

    delete tmp;
    return entry;
}

template <class T>
T SLList<T>::deleteFromTail()
{
    T entry = tail->data;
    if (head == tail)
    {
        delete head;
        head = tail = NULL;
    }
    else
    {
    Node *tmp;
    for (tmp = head; tmp->next != tail; tmp = tmp->next);
    delete tail;
    tail = tmp;
    tail->next = NULL;
    }

    return entry;
}

template <class T>
void SLList<T>::deleteNode(T entry)
{
    if (head != NULL)
    {
        if (head == tail && entry == head->data)
        {
            delete head;
            head = tail = NULL;
        }
        else if (entry == head->data)
        {
            Node *tmp = head;
            head = head->next;
            delete tmp;
        }
        else
        {
            Node *pred, *tmp;
            for (pred = head, tmp = head->next;
                tmp != NULL && !(tmp->data == entry);
                pred = pred->next, tmp = tmp->next);

            if (tmp != NULL)
            {
                pred->next = tmp->next;

                if (tmp == tail)
                {
                    tail = pred;
                }

                delete tmp;
            }
        }
    }
}

template <class T>
bool SLList<T>::contains(T entry)
{
    Node *tmp;
    for (tmp = head; tmp != NULL && !(tmp->data == entry); tmp = tmp->next);
    return tmp != NULL;
}

#endif // SLLIST_H_INCLUDED
