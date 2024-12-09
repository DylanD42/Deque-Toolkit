#include <iostream>
#include "deque.h"
using namespace std;

int main() {
  deque plsWork;
  for (int i = 1; i < 50; i++){
    plsWork.push_front(i);
  }
  plsWork.print();
  return 0;
}
