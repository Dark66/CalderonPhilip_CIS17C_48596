#ifndef LINKED_LIST_QUEUE_H_INCLUDED
#define LINKED_LIST_QUEUE_H_INCLUDED

template <class T>
class LLQueue
{
public:
    LLQueue(){}
    ~LLQueue(){}

    void clear(){}

    bool isEmpty()
    {
        return list.isEmpty();
    }

    void enqueue(T element)
    {
        list.append(element);
    }

    T dequeue()
    {
        return list.deleteFromHead();
    }

    T peek()
    {
        return list.peekFirst();
    }

private:
    SLList<T> list;
};

#endif // LINKED_LIST_QUEUE_H_INCLUDED
