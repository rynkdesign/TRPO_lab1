#include "Stack.h"

void Stack::push(int value_)
{
    Node* noviy;
    noviy->value=value_;

    if(top->next) //если чёто есть
    {
        noviy->next=top->next;
        top->next=noviy;
    }
    else // если стэк пустой
    {
        top->next=noviy;
        noviy->next=nullptr;
    }
    size++;
};

void Stack::pop()
{
    if(top->next)
    {
        top->next=top->next->next;
        size--;
    }
};

int Stack::getSize()
{
   return size;
};
