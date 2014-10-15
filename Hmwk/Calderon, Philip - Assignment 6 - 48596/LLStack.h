// Philip Calderon
// October 13, 2014
// LINKED_LIST_STACK

#ifndef LLSTACK_H_INCLUDED
#define LLSTACK_H_INCLUDED

#include "SLList.h"

template <class T>
class LLStack
{
public:
    LLStack(){}
    ~LLStack(){}

    void clear(){}

    bool isEmpty()
    {
        return list.isEmpty();
    }

    void push(T element)
    {
        list.append(element);
    }

    T pop()
    {
        return list.deleteFromTail();
    }

    T peek()
    {
        return list.peekLast();
    }

private:
    SLList<T> list;
};

#endif // LLSTACK_H_INCLUDED
