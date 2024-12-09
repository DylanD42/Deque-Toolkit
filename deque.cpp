 //deque cpp file
#include "deque.h"
#include <iostream>

using namespace std;

deque::deque(){
  front_ptr = NULL;
  back_ptr = NULL;
  rows = 0;
  num_of_elements = 0;
  blockmap = new int*[rows];
}
deque::~deque(){
  for(int i = 0; i < rows; i++){
    delete[] blockmap[i];
  }
  delete[] blockmap;
}

void deque::resize(){
  if(front_ptr == NULL && back_ptr == NULL){
    rows = 1;
    blockmap = new int*[rows];
    for (int i = 0; i < rows; i++){
      blockmap[i] = new int[block_size];
    }
  }
  else {
    int ** temp_blockmap;
    temp_blockmap = new int* [rows + 2]; // could change to *2 later

    temp_blockmap[0] = new int[block_size];// this would have to change too
    for (int i = 0; i < rows; i++){
      temp_blockmap[i+1] = blockmap[i];
    }
    temp_blockmap[rows + 1] = new int[block_size];

    delete blockmap;
    blockmap = temp_blockmap;

    rows = rows+2;
    distance_from_front = block_size;
  }

}

void deque::pop_front(){}

void deque::pop_back(){}
//front_ptr == NULL && back_ptr == NULL
void deque::push_front(int value){
  if(front_ptr == NULL && back_ptr == NULL){
    cout << "Resizing" << endl;
    resize();
    cout << "setting value at: ";
    blockmap[0][block_size/2] = value;
    front_ptr = &blockmap[0][block_size/2]; // (cout << *front_ptr) for value
    cout << front_ptr << " with the value of: " << *front_ptr;
    distance_from_front = (block_size/2)-1;
    cout << " " << distance_from_front + 1 << " away from front" << endl;
    cout << " " << distance_from_front << " away from front" << endl;
  } // the +1 is to show how many physical elements away not the index away
  else if (distance_from_front > -1){
    cout << "setting value at: ";
    blockmap[0][distance_from_front] = value;
    front_ptr = &blockmap[0][distance_from_front]; // (cout << *front_ptr) for value
    cout << front_ptr << " with the value of: " << *front_ptr;
    distance_from_front--;
    cout << " " << distance_from_front + 1 << " away from front" << endl;
    cout << " " << distance_from_front << " away from front" << endl;
  }
  else{
    cout << "resizing" << endl;
    resize();
    cout << front_ptr << " with the value of: " << *front_ptr;
    blockmap[0][distance_from_front-1] = value;
    front_ptr = &blockmap[0][distance_from_front]; // (cout << *front_ptr) for value                      cout << front_ptr << " with the value of: " << *front_ptr;
    distance_from_front--;
    cout << " " << distance_from_front + 1 << " away from front" << endl;
    cout << " " << distance_from_front << " away from front" << endl;
  }
  
}

void deque::push_back(int value){
  if(front_ptr == NULL && back_ptr == NULL){
    resize();
  }

}

int deque::front(){}

int deque::back(){}

int deque::size(){}

bool deque::empty(){
  if(front_ptr == NULL && back_ptr == NULL) {
    return true;
  }
  else{
    return false;
  }
}
// [] opperator
void deque::print(){
  for(int i = 0; i < rows; i++){
    for(int j = 0; j < block_size; j++){
      cout << blockmap[i][j] << " ";
    }
    cout << endl;
  }
}
