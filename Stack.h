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
      int getSize(); // Получение размерности стека
      void push(int value_); // Помещение объекта в стек
      void pop(); // Удаление верхнего объекта из стека
      int topFunc(); // Извлечение верхнего объекта из стека
};


#endif // STACK_H
