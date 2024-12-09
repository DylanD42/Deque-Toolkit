//deque.h file
#ifndef DEQUE_H
#define DEQUE_H

#include <iostream>

using namespace std;

class deque{
 private:
  int *front_ptr, *back_ptr, rows, num_of_elements, distance_from_front, distance_to_back;
  int frontRowIndex, backRowIndex;
  int added_front_rows, added_back_rows;
  static const int block_size = 16;
  int ** blockmap;
  void resize();
 public:
  deque();
  ~deque();
  void push_front(int value);
  void pop_front();
  void push_back(int value);
  void pop_back();
  int front();
  int back();
  bool empty();
  int size();
  void print();
  // [] operator
  
};


#endif //DEQUE_H
