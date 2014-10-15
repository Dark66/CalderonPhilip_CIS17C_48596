// Philip Calderon
// October 13, 2014
// CIRCULAR_SINGLY_LINKED_LIST

#ifndef CSLLNODE_H_INCLUDED
#define CSLLNODE_H_INCLUDED

template<class T>
class CSLLNode
{
public:
    CSLLNode() { next = NULL; }

    CSLLNode(const T& element, CSLLNode *n = NULL) { info = element; next = n; }

    T info;
    CSLLNode *next;
};

template<class T>
class CSLList
{
public:
    CSLList() { tail = NULL; }
    ~CSLList();

    void addToHead(const T&);
    void addToTail(const T&);
    T deleteFromHead();
    T deleteFromTail();
    void deleteNode(T);
    bool isEmpty();
    bool isInList(T) const;

private:
    CSLLNode *tail;
};

template<class T>
void CSLList<T>::addToHead(const T &element)
{
    if (isEmpty())
    {
        tail = new CSLLNode(element);
        tail->next = tail;
    }
    else
    {
        tail->next = new CSLLNode(element, tail->next);
    }
}

template<class T>
void CSLList<T>::addToTail(const T &element)
{
    if (isEmpty())
    {
        tail = new CSLLNode(element);
        tail->next = tail;
    }
    else
    {
        tail->next = new CSLLNode(element, tail->next);
        tail = tail->next;
    }
}

template<class T>
T CSLList<T>::deleteFromHead()
{
    CSLLNode *tmp = tail->next;
    tail->next = tmp->next;
    delete tmp;
}

template<class T>
T CSLList<T>::deleteFromTail()
{
    CSLLNode *tmp = tail;
    while (tmp->next != tail)
        tmp = tmp->next;
    tail = tmp;
    delete tmp->next;
    tmp->next = NULL;
}

template<class T>
void CSLList<T>::deleteNode(T element)
{
    if (tail != NULL)
    {
        if (element == tail->info)
        {
            delete tail;
            tail = NULL;
        }
        else
        {
            CSLLNode *pred, *tmp;
            for (pred = tail, tmp = tail->next;
            tmp != NULL && !(tmp->info == element);
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

template<class T>
bool CSLList<T>::isEmpty()
{
    return tail == NULL;
}

template<class T>
bool CSLList<T>::isInList(T element) const
{
    CSLLNode *tmp;
    for (tmp = tail; tmp != NULL && !(tmp->info == element); tmp = tmp->next);
    return tmp != NULL;
}

#endif // CSLLNODE_H_INCLUDED
