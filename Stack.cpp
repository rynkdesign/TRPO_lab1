#include "Stack.h"
#include "Exception.cpp"

void Stack::push(int value_)
{
     Node* noviy = new Node(value_);

    if(top) //если чёто есть
    {
        noviy->next=top;
        top=noviy;
    }
    else // если стэк пустой
    {
        top=noviy;
        top->next=nullptr;
    }
    size++;
};

void Stack::pop()
{
    if(top)
    {
        Node* tmp=top;
        top=top->next;
        delete tmp;
        size--;
    }
    else
    {
        throw exep_stack::EStackEmpty("Runtime error: stack is empty. Called function pop()\n");
    }
};

int Stack::topFunc() //поменять int
{
    if(top)
    {
          return top->value;
    }
    else
    {
        throw exep_stack::EStackEmpty("Runtime error: stack is empty. Called function top()\n");
    }
};

int Stack::getSize()
{
   return size;
};
