 //deque cpp file
#include "deque.h"
#include <iostream>

using namespace std;

deque::deque(){
  front_ptr = NULL;
  back_ptr = NULL;
  rows = frontRow = backRow = 0;
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
    rows = frontRow = backRow = 1;
     // set to 1 for math later
    blockmap = new int*[rows];
    for (int i = 0; i < rows; i++){
      blockmap[i] = new int[block_size];
    }
    front_ptr = back_ptr = &blockmap[0][(block_size/2)];
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
    frontRow = 1;
  }
  //frontRow = 1;
  cout << "rows: " << rows << " front row: " << frontRow <<endl;
  frontRow = (rows/(2*frontRow));
  cout << "new front row: " << frontRow <<endl;
  
}

void deque::pop_front(){}

void deque::pop_back(){}
//front_ptr == NULL && back_ptr == NULL

void deque::push_front(int value){
  if(front_ptr == NULL && back_ptr == NULL){
    cout << "Resize NULL" << endl;
    resize();
    *front_ptr = value;
    cout << "setting value at: " << front_ptr << " with the value of: " << *front_ptr << endl;
    front_ptr = front_ptr - 1;
  }
  else if(front_ptr >= &blockmap[frontRow][0]){
    
    *front_ptr = value;
    cout << "setting value at: " << front_ptr << " with the value of: " << *front_ptr << endl;
    front_ptr = front_ptr - 1;
    cout << front_ptr << " " << &blockmap[frontRow][0] << endl;
  }
  else{
    cout << "Resize" << endl;
    resize();
    // rows / 2*frontrow
    //front_ptr = &block_size[]
    
    front_ptr = &blockmap[frontRow-1][block_size-1]; 
    *front_ptr = value;
    cout << "setting value at: " << front_ptr << " with the value of: " << *front_ptr << endl;
    front_ptr = front_ptr - 1;
  }
}

void deque::push_back(int value){
  if(front_ptr != NULL && back_ptr == NULL){
    if(rows = 1){
      blockmap[0][(block_size/2)+1] = value;
      back_ptr = &blockmap[0][(block_size/2)+1];
    }
    else {
      blockmap[(rows-1)/2][(block_size/2)+1] = value;
      back_ptr = &blockmap[(rows-1)/2][(block_size/2)+1];
    }
    distance_to_back = (block_size/2)+1;
    distance_to_back--;
  }
if(front_ptr == NULL && back_ptr == NULL){
    cout << "Resizing" << endl;
    resize();
    cout << "setting value at: ";
    blockmap[0][block_size/2] = value;
    back_ptr = &blockmap[0][block_size/2]; // (cout << *front_ptr) for value
    cout << back_ptr << " with the value of: " << *back_ptr;
    distance_to_back = (block_size/2)-1;
    cout << " " << distance_to_back << " slots to back" << endl;
 }// (x%2)*((x/2)+1) ((rows%2)*((rows/2)+1))
 else if (distance_to_back > 0){
   cout << "setting value at: ";
   blockmap[rows-1][block_size - distance_to_back] = value;
   back_ptr = &blockmap[rows-1][block_size - distance_to_back]; // (cout << *front_ptr) for value
   cout << back_ptr << " with the value of: " << *back_ptr;
   distance_to_back--;
   cout << " " << distance_to_back << " away from front" << endl;
  }
  else{
    cout << "resizing" << endl;
    resize();
    distance_to_back = block_size;
    cout << back_ptr << " with the value of: " << *back_ptr;
    blockmap[rows-1][block_size - distance_to_back] = value;
    back_ptr = &blockmap[rows-1][block_size - distance_to_back]; // (cout << *front_ptr) for value                      cout << front_ptr << " with the value of: " << *front_ptr;
    distance_to_back--;
    cout << " " << distance_to_back << " away to back" << endl;
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