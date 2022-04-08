#ifndef NODE_H
#define NODE_H

template <class T>
class Node
{
  public:

  T value; // данные
  Node<T>* next;

  Node(T value_ = nullptr, Node<T>* next_ = nullptr)
  {
      value=value_; next=next_;
  }
};


#endif // NODE_H
