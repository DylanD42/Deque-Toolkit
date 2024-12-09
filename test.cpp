
#include <iostream>

using namespace std;

int main() {
  int rows, cols, current = 0;
  cout << "enter the number of rows:";
  cin >> rows;
  cout << "enter the number of columns: ";  
  cin >> cols;

  int ** array;
  array = new int* [rows];
  for (int i = 0; i < rows; i++){
    array[i] = new int[cols];
  }
  for (int i = 0; i < rows; i++){
    for (int j = 0; j < cols; j++){
      array[i][j] = current;
      current++;
    }
  }

  cout << "before resize:" << endl; 
  for (int i = 0; i < rows; i++){
    for(int j = 0; j < cols; j++){
      cout << array[i][j] << " ";
    }
    cout << endl;
  }
  
  // resize
  int ** arr2;
  arr2 = new int* [rows + 2];
  

  arr2[0] = new int[cols];
  for (int i = 0; i < rows; i++){
    arr2[i+1] = array[i];
  }
  arr2[rows + 1] = new int[cols];

  
  delete[] array;
  array = arr2;

  cout << "afrter resize: " << endl;
  for (int i = 0; i < rows + 2; i++){
    for(int j = 0; j < cols; j++){
      cout << array[i][j] << " ";
    }
    cout << endl;
  }

  
  // clean things up
  for(int i = 0; i < rows + 2; i++){
    delete[] array[i];
  }
  
  delete[] array;
  
  return 0;
}
