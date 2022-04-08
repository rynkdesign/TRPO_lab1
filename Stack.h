#ifndef STACK_H
#define STACK_H
#include "Node.h"
#include "Exception.cpp"

template <class T> // Объявление шаблонного класса для Стека
class Stack
{
private:
    Node<T>* top; // Первый элемент Стека - "Голова"

  public:


    int size; // Кол-во элементов Стека

    Stack(Node<T>* top_=nullptr,int size_=0) // Конструктор
    {
        top=top_; size=size_;
    }

    ~Stack() // Деструктор
    {
        while(size)
        {
            pop();
        }
    }

    Stack(const Stack<T>& copy); // Конструктор копирования

    bool empty() const; // Проверка пустой ли Стек?
    int getSize() const; // Получение размерности Стека
    void push(T value_); // Помещение объекта в Стек
    void pop(); // Удаление верхнего объекта из Стека
    T topFunc() const; // Извлечение верхнего объекта из Стека

    //Перегрузки
    Stack& operator = (const Stack& other); // Оператор присваивания
    const T& operator[] (unsigned index) const; // Оператор [], для того, чтобы передвигаться по элементам Стека
};

template <class T>
void Stack<T>::push(T value_) // Помещение объекта в Стек
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
void Stack<T>::pop() // Удаление верхнего объекта из Стека
{
    if(top) //Если в Стеке что-то есть
    {
        Node<T>* tmp=top; // Перенаправляем указатели на следующий элемент
        top=top->next;
        delete tmp;
        size--;
    }
    else // Иначе исключение
    {
        throw exep_stack::EStackEmpty("Runtime error: stack is empty. Called function pop()\n");
    }
};

template <class T>
T Stack<T>::topFunc() const // Извлечение верхнего объекта из Стека
{
    if(top) //Если в Стеке что-то есть
    {
          return top->value; // Возвращаем значение Головы
    }
    else // Иначе исключение
    {
        throw exep_stack::EStackEmpty("Runtime error: stack is empty. Called function top()\n");
    }
};

template <class T>
int Stack<T>::getSize() const // Получение размерности Стека
{
   return size;
};

template <class T>
bool Stack<T>::empty() const // Проверка пустой ли Стек?
{
     return top == nullptr;
}

template<typename T>
const T& Stack<T>::operator[] (unsigned index) const // Оператор [], для того, чтобы передвигаться по элементам Стека
{
    Node<T>* tmp = top;
        unsigned i = 0;
        for (; tmp != nullptr && i < index; tmp = tmp->next, ++i);

        if (tmp == nullptr)
            throw "Index > list size";
        else
            return tmp->value;
}

template<typename T>
Stack<T>::Stack(const Stack& copy) // Конструктор копирования
{
    top = nullptr;
    size = 0;

    if (copy.top) // Запись первого элемента в Стек
    {
        top = new Node<T>;
        top->value = copy.top->value;
        size++;

        Node<T>* copyElem = copy.top->next;
        Node<T>* thisElem = top;
        while (copyElem) // Пока есть элементы в копируемом Стеке, происходит запись
        {
            thisElem->next = new Node<T>;
            thisElem = thisElem->next;
            thisElem->value = copyElem->value;

            copyElem = copyElem->next;
            size++;
        }
        thisElem->next = nullptr; // Так как, элементов для записи больше нет, ставим указатель на nullptr
    }
}

template<typename T>
Stack<T>& Stack<T>::operator = (const Stack& other) // Оператор присваивания
{
    if (this == &other) // Если Стеки совпадают, то возвращаем наш Стек
        return *this;

    delete Stack(); // Удаляем наш Стек

    this = new Stack<T>(other); // Через конструктор копирования, копируем Стек

    return *this;
}

#endif // STACK_H
