//deque.h file
#ifndef DEQUE_H
#define DEQUE_H

#include <iostream>

using namespace std;

class deque{
 private:
  int *front_ptr, *back_ptr, rows;
  static const int block_size = 4;
  int ** blockmap;
  void resize();
 public:
  deque();
  ~deque();
  void push_front();
  void pop_front();
  void push_back();
  void pop_back();
  int front();
  int back();
  bool empty();
  int size();
  // [] operator
  
}


#endif //DEQUE_H
