#ifndef NODE_H
#define NODE_H

class Node
{
  public:

  int value; // потом поменять на теплате
  Node* next;

  Node(int value_=0, Node* next_ = nullptr) // потом поменять на теплате
  {
      value=value_; next=next_;
  }
};


#endif // NODE_H
