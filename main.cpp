#include <iostream>
#include "deque.h"
using namespace std;

int main() {
  deque plsWork;
  for (int i = 1; i < 50; i++){
    plsWork.push_back(i);
    }
  plsWork.pop_front();
  plsWork.pop_back();
  plsWork.pop_back();
  plsWork.print();
  
  cout << "size: " << plsWork.size() << endl;
  cout << "first element: " << plsWork.front() << endl;
  cout << "last element: " << plsWork.back() << endl;
  cout << "Is it empty? :";
  if (plsWork.empty() == true){
    cout << " Yes." << endl;
  }
  else if (plsWork.empty() == false){
    cout << " No." << endl;
  }
  
  return 0;
}
