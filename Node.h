#ifndef NODE_H
#define NODE_H

template <class T>
class Node // Класс узлов Стека
{
  public:

  T value; // Данные
  Node<T>* next; //Указатель на следующий элемент Стека

  Node(const T& value_ = T(), Node<T>* next_ = nullptr) // Конструктор
  {
      value=value_; next=next_;
  }

};


#endif // NODE_H
