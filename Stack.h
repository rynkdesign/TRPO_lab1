#ifndef STACK_H
#define STACK_H
#include "Node.h"
#include "Exception.cpp"

template <class T>
class Stack
{
  public:

    Node<T>* top; //Первый элемент Стека - "Голова"
    int size; //Кол-во элементов Стека

    Stack(Node<T>* top_=nullptr,int size_=0)
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

    int getSize(); // Получение размерности Стека
    void push(const T &value_); // Помещение объекта в Стек
    void pop(); // Удаление верхнего объекта из Стека
    T topFunc(); // Извлечение верхнего объекта из Стека
};

template <class T>
void Stack<T>::push(const T &value_)
{
     Node<T>* noviy = new Node<T>(value_);

    if(top) //Если в Стеке что-то есть
    {
        noviy->next=top;
        top=noviy;
    }
    else //Если Стек пустой
    {
        top=noviy;
        top->next=nullptr;
    }
    size++;
};

template <class T>
void Stack<T>::pop()
{
    if(top)
    {
        Node<T>* tmp=top;
        top=top->next;
        delete tmp;
        size--;
    }
    else
    {
        throw exep_stack::EStackEmpty("Runtime error: stack is empty. Called function pop()\n");
    }
};

template <class T>
T Stack<T>::topFunc()
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

template <class T>
int Stack<T>::getSize()
{
   return size;
};



#endif // STACK_H
