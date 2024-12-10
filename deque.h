//deque.h file
#ifndef DEQUE_H
#define DEQUE_H

#include <iostream>

using namespace std;

class deque {
 private:
  int rows;
  int block_size;
  int frontRow;
  int backRow;
  int frontColumn;
  int backColumn;
  int num_of_elements;
  int** blockmap; 

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
