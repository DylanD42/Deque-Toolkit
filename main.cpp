#include <iostream>
#include "deque.h"
using namespace std;

int main() {
  deque plsWork;/*
  for (int i = 1; i < 50; i++){
    plsWork.push_front(i);
  }
  */
  
  //plsWork.push_back(1);

  //plsWork.push_back(2);
  //plsWork.push_back(3);
  //plsWork.push_back(4);
  
  plsWork.push_back(4);
  plsWork.push_front(10);
  plsWork.push_front(12);
  plsWork.push_front(12);
  plsWork.push_front(12);
  plsWork.push_front(12);
  plsWork.push_back(4);
  plsWork.push_back(4);
  plsWork.push_back(4);
  plsWork.push_back(4);
  plsWork.push_back(4);
  
  
  
  plsWork.print();
  return 0;
}
