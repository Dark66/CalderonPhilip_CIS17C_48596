// Philip Calderon
// October 13, 2014
// DOUBLY_LINKED_LIST

#ifndef DLLNODE_H_INCLUDED
#define DLLNODE_H_INCLUDED

template<class T>
class DLLNode
{
public:
    DLLNode()
    {
        next = prev = NULL;
    }

    DLLNode(const T& element, DLLNode *n = NULL, DLLNode *p = NULL)
    {
        info = element; next = n; prev = p;
    }

    T info;
    DLLNode *next, *prev;
};

template<class T>
class DLList
{
public:
    DLLList(){ head = tail = NULL; }
    void addToHead(const T&);
    void addToTail(const T&);
    T deleteFromHead();
    T deleteFromTail();
    void deleteNode(T);
    bool isEmpty();
    bool isInList(T) const;
    private:
    DLLNode<T> *head, *tail;
};

template<class T>
void DLList<T>::addToHead(const T& element)
{
    head = new DLLNode(element, head);
    if (tail == NULL)
    {
        tail = head;
    }
}

template<class T>
void DLList<T>::addToTail(const T& element)
{
    if (tail != NULL)
    {
        tail = new DLNode<T>(element, NULL, tail);
        tail->prev->next = tail;
    }
    else
    {
        head = tail = new DLNode<T>(element);
    }
}

template<class T>
T DLList<T>::deleteFromHead()
{
    T element = head->info;
    DLLNode *temp = head;
    if (head == tail)
    {
        head = tail = NULL;
    }
    else
    {
        head = head->next;
    }
    delete temp;
    return element;
}

template<class T>
T DLList<T>::deleteFromTail()
{
    T element = tail->info;

    if (head == tail)
    {
        delete head;
        head = tail = NULL;
    }
    else
    {
        tail = tail->prev;
        delete tail->next;
        tail->next = NULL;
    }

    return element;
}

template<class T>
void DLList<T>::deleteNode(T element)
{
    if (head != NULL)
    {
        if (head == tail && element == head->info)
        {
            delete head;
            head = tail = NULL;
        }
        else if (element == head->info)
        {
            DLLNode *temp = head;
            head = head->next;
            delete temp;
        }
        else
        {
            DLLNode *pred, *temp;
            for (pred = head, temp = head->next;
            temp != NULL && !(temp->info == element);
            pred = pred->next, temp = temp->next);
            if (temp != NULL)
            {
                pred->next = temp->next;
                if (temp == tail)
                {
                    tail = pred;
                }
                delete temp;
            }
        }
    }
}

template<class T>
bool DLList<T>::isEmpty()
{
    return head == NULL;
}

template<class T>
bool DLList<T>::isInList(T element) const
{
    DLLNode *temp;
    for (temp = head; temp != NULL && !(temp->info == element); temp = temp->next);
    return temp != NULL;
}

#endif // DLLNODE_H_INCLUDED
