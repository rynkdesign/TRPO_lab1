#ifndef STACK_H
#define STACK_H
#include "Node.h"

class Stack
{
  public:

    Stack(Node* top_=nullptr,int size_=0)
    {
        top=top_; size=size_;
    }

    ~Stack()
    {
        while(size)
        {
            pop();
        }
    }

    Node* top;

    int size;
    int getSize();
    void push(int value_);
    void pop();
};


#endif // STACK_H
