#include <iostream>
#include "deque.h"

void testingBasics() {
  deque d;
  
  cout << "----- Basic Testing -----" << endl;

  d.push_back(22);
  d.push_back(11);
  d.push_back(55);
  d.print();

  cout << "Front: " << d.front() << endl;
  cout << "Back: " << d.back() << endl;

  // popping from the front
  d.pop_front();
  d.print();

  // popping from the back
  d.pop_back();
  d.print();

  cout << "Size: " << d.size() << endl;
  cout << "Empty: " << d.empty() << endl;
}

void testing1000() {
  deque d;
  const int NUMBER = 1000;

  cout << "----- Testing Big -----" << endl;
  cout << "Pushing 1 to " << NUMBER << " at the back . . . " << endl;

  for (int i = 1; i <= NUMBER; i++) {
    d.push_back(i);
  }

  cout << "Current size after push_back: " << d.size() << endl;

  cout << "Popping all elements from the back . . . " << endl;
  for (int i = 0; i < NUMBER; i++) {
    d.pop_back();
  }

  cout << "Current size after pop_back: " << d.size() << endl;
}

void testingMixed() {
  deque d;

  cout << "----- Testing Mixed Operations -----" << endl;

  cout << "Pushing 1 to 10 at the front . . . " << endl;
  for (int i = 1; i <= 10; i++) {
    d.push_front(i);
  }
  d.print();
  cout << "Size after push_front: " << d.size() << endl;

  // verifying front and back after push_front
  cout << "Front: " << d.front() << endl;
  cout << "Back: " << d.back() << endl;
  
  // alternating push_back and pop_front
  cout << "Alternating push_back and pop_front . . . " << endl;
  for (int i = 11; i <= 20; i++) {
    d.push_back(i);
    d.pop_front();
  }
  d.print();
  cout << "Size after: " << d.size() << endl;

  // verifying front and back after alternating push_back and pop_front
  cout << "Verifying front and back . . . " << endl;
  cout << "Front: " << d.front() << endl;
  cout << "Back: " << d.back() << endl;

  // popping all elements
  cout << "Popping all elements . . ." << endl;
  while (!d.empty()) {
    d.pop_front();
  }
  cout << "Size after popping all elements: " << d.size() << endl;
}

void testingPopToEmptyDeque() {
  deque d;
  
  cout << "----- Pop to Empty Deque Test -----" << endl;
  
  cout << "Attempting to pop from an empty deque . . . " << endl;
  d.pop_front();
  d.pop_back();
}

using namespace std;

int main() {
  // tests
  testingBasics();

  cout << endl;
  
  testing1000();

  cout << endl;
  
  testingMixed();

  cout << endl;
  
  testingPopToEmptyDeque();
  
  return 0;
}
