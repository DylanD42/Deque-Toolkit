//deque cpp file
#include "deque.h"
#include <iostream>

using namespace std;


/**
 * This is the constructor that initializes the deque, allocates memory, and sets the number of rows,
 * block size, front and back positions, and the element count.  
 *
 * @pre The deque is empty before initialized. 
 * @post Initialized with 1 row and block size of 6, the front and back pointers are set to the middle
 *       of the 1st row. The number of elements is set to 0. 
 * 
 */
deque::deque() : rows(1), block_size(6), frontRow(0), backRow(0), frontColumn(block_size / 2),
                 backColumn(block_size / 2),  num_of_elements(0) {
  blockmap = new int*[rows]; // allocating memory for rows
  for (int i = 0; i < rows; i++) {
    blockmap[i] = new int[block_size]();
  }
}



/**
 * Destructor that cleans up the deque.
 *
 * @pre The deque must be created.
 * @post The deque's blockmap is deallocated and all memory is freed (dynamic).
 * 
 */
deque::~deque(){
  for(int i = 0; i < rows; i++){
    delete[] blockmap[i];
  }
  delete[] blockmap;
}



/**
 * This functions resizes the blockmap to allow more elements whenever the blockmap is full.
 *
 * @pre The deque must be full or close to being full. 
 * @return void 
 * @post The blockmap's number of rows double, existing elements are copied over, and the front and back pointers are now to reflect the new.
 * 
 */
void deque::resize(){
  cout << "Resizing ... Current Rows: " << rows << endl;

  int newRows = rows * 2;

  // allocates new blockmap with more rows
  int** newBlockmap = new int*[newRows];
  for (int i = 0; i < newRows; i++) {
    newBlockmap[i] = new int[block_size]();
  }

  // calculating the new position of frontRow and backRom
  int newFrontRow = (newRows - rows) / 2 + frontRow;
  int newBackRow = (newRows - rows) / 2+ backRow;
  
  // copy old blockmap to new one
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < block_size; j++) {
      newBlockmap[i + (newRows - rows) / 2][j] = blockmap[i][j];
    }
  }
  
  // deletes the old blockmap
  for (int i = 0; i < rows; i++) {
    delete[] blockmap[i];
  }
  delete[] blockmap;

  // points blockmap to the new one
  blockmap = newBlockmap;
  rows = newRows;
  
  // updates blockmap and row info
  blockmap = newBlockmap;
  rows = newRows;
  frontRow = newFrontRow;
  backRow = newBackRow;
}



/**
 * This function removes an element from the front of the deque.
 *
 * @pre The deque cannot be empty. 
 * @return void 
 * @post The deque's element at the front is removed. The front pointer points to the next spot. 
 * 
 */
void deque::pop_front() {
  if (num_of_elements == 0) {
    cout << "deque is empty, cannot pop front" << endl;
    return;
  }

  blockmap[frontRow][frontColumn] = 0;

  num_of_elements--;

  // move front pointer
  if (frontColumn < block_size - 1) {
    frontColumn++; // move right within the same row
  } else if (frontRow < rows - 1) {
    frontRow++; // move down to the next row
    frontColumn = 0;
  }
}


/**
 * This function removes an element fro mthe back of the deque. 
 *
 * @pre The deque can't be empty.
 * @return void 
 * @post The deque's back element is removed. The back pointer points at previous spot. 
 * 
 */
void deque::pop_back(){
  if (num_of_elements == 0) {
    cout << "Deque is empty; cannot pop back" << endl;
    return;
  }

  // calculate the actual position of the last element
  int lastBackCol = (backColumn == 0) ? (block_size - 1) : (backColumn - 1);
  int lastBackRow = (backColumn == 0 && backRow > 0) ? (backRow - 1) : backRow;

  // removes the element
  blockmap[lastBackRow][lastBackCol] = 0;
  num_of_elements--;

  // updates pointers
  backColumn = lastBackCol;
  backRow = lastBackRow;
}


/**
 * Function adds an element to the front of the deque.
 *
 * @param int value The value to be inserted.
 * @pre The front pointer must be correctly set.
 * @return void 
 * @post The deque contains the new element at the front. 
 * 
 */
void deque::push_front(int value){
  //cout << "Push front called. Value: " << value << endl;
  
  if (num_of_elements == 0) {
    cout << "Deque is empty, resizing . . . " << endl;
    resize();
  }

  blockmap[frontRow][frontColumn] = value;

  num_of_elements++;

  // moves the front pointer 
  if (frontColumn > 0) {
    frontColumn--; // moves left within the current row 
  } else if (frontRow > 0) {
    frontRow--; // moves up to the previous row 
    frontColumn = block_size - 1; // resets to the far-right column
  } else {
    resize();
  }
}


/**
 * This function adds an element to the back of the deque. 
 *
 * @param int value The value to be inserted.  
 * @pre The back pointer must be correctly set.
 * @return void 
 * @post The deque contains the new element at the back. 
 * 
 */
void deque::push_back(int value){
  // cout << "Push back called. Value: " << value << endl;
  
  if (num_of_elements == 0) {
    cout << "Deque is empty, resizing . . . " << endl;
    resize();
  }
  blockmap[backRow][backColumn] = value;

  
  num_of_elements++;

  // moves the back pointer
  if (backColumn < block_size - 1) {
    backColumn++; // moves right in current row 
  } else if (backRow < rows - 1) {
    backRow++; // moves down to the next row
    backColumn = 0; // resets to the leftmost column
  } else {
    resize();
    backRow = 0; // resets backRow to the start after resizing
    backColumn = 0; // resets backColumn to the first position in the row
  }
}
                                              

/**
 * This function returns whether the deque is empty.
 *
 * @pre 
 * @return bool 
 * @post Returns true if the deque is empty; false if not.
 * 
 */
bool deque::empty() {                         
  return (num_of_elements == 0);              
} 
    

/**
 * This function returns the element at the front of the deque.
 *
 * @pre The deque cannot be empty.
 * @return int 
 * @post The element at the front of the deque is returned.
 * 
 */
int deque::front() {
  if (num_of_elements > 0) {
    return blockmap[frontRow][frontColumn];
  }
  return -1;
}


/**
 * This function returns the element at the back of the deque.
 *
 * @pre The deque cannot be empty.
 * @return int 
 * @post The element at the back of the deque is returned.
 * 
 */
int deque::back() {
  if (num_of_elements > 0) {
    // calculates the position of the actual "back" element
    int lastBackCol = (backColumn == 0) ? (block_size - 1) : (backColumn - 1);
    int lastBackRow = (backColumn == 0 && backRow > 0) ? (backRow - 1) : backRow;

    return blockmap[lastBackRow][lastBackCol];
  }
  return -1;
}    


/**
 * This function returns the current size of the deque / the number of elements.
 *
 * @pre 
 * @return int 
 * @post The number of elements in the deque is returned.
 * 
 */
int deque::size() {
  return num_of_elements;
}

// [] opperator


/**
 * This function prints the current state of the deque.
 *
 * @pre 
 * @return void 
 * @post The state of the deque is printed, which shows elements in each row
 *       of the block map and the positions of the front and back pointers.
 * 
 */
void deque::print() {
  cout << "deque state:" << endl;
  for(int i = 0; i < rows; i++){
    for(int j = 0; j < block_size; j++){
      cout << blockmap[i][j] << " ";
    }
    cout << endl;
  }
}
