#include <iostream>
#include "ArrayClass.h"

using namespace std;

bool Test1() {
  int size = 3;
  Array arr(size);
  arr[0] = 1;
  arr[1] = 2;
  arr[2] = 3;
  int searchingElement = 1;
  int index = -1;

  int correctIndex = 0;
  index = arr.BinarySearchAscending(searchingElement);
  if (index == correctIndex) {
    return true;
  } else {
    cout << "Test 1 failed" << endl;
    for (int i = 0; i < arr.GetSize(); i++) {
      cout << i + 1 << ")";
      cout << arr[i] << endl;
    }
    cout << "Correct index: " << correctIndex + 1 << endl;
    cout << "The resulting index: " << index + 1 << endl;
  
    return false;
  }

}

bool Test2() {
  int size = 5;
  int index = -1;
  Array arr(size);
  arr[0] = 5;
  arr[1] = 7;
  arr[2] = 8;
  arr[3] = 9;
  arr[4] = 20;
  int searchingElement = 20;

  int correctIndex = 4;
  index = arr.BinarySearchAscending(searchingElement);
  if (index == correctIndex) {
    return true;
  } else {
    cout << "Test 2 failed" << endl;
    for (int i = 0; i < arr.GetSize(); i++) {
      cout << i + 1 << ")";
      cout << arr[i] << endl;
    }
    cout << "Correct index: " << correctIndex + 1 << endl;
    cout << "The resulting index: " << index + 1 << endl;

    return false;
  }

}

bool Test3() {
  int size = 4;
  int index = -1;
  Array arr(size);
  arr[0] = 6;
  arr[1] = 13;
  arr[2] = 79;
  arr[3] = 90;
  int searchingElement = 13;

  int correctIndex = 1;
  index = arr.BinarySearchAscending(searchingElement);
  if (index == correctIndex) {
    return true;
  } else {
    cout << "Test 3 failed" << endl;
    for (int i = 0; i < arr.GetSize(); i++) {
      cout << i + 1 << ")";
      cout << arr[i] << endl;
    }
    cout << "Correct index: " << correctIndex + 1 << endl;
    cout << "The resulting index: " << index + 1 << endl;

    return false;
  }

}

bool Test4() {
  int size = 3;
  int index = -1;
  Array arr(size);
  arr[0] = 100;
  arr[1] = 128;
  arr[2] = 400;
  int searchingElement = 100;

  int correctIndex = 0;
  index = arr.BinarySearchAscending(searchingElement);
  if (index == correctIndex) {
    return true;
  } else {
    cout << "Test 4 failed" << endl;
    for (int i = 0; i < arr.GetSize(); i++) {
      cout << i + 1 << ")";
      cout << arr[i] << endl;
    }
    cout << "Correct index: " << correctIndex + 1 << endl;
    cout << "The resulting index: " << index + 1 << endl;

    return false;
  }
}

bool Test5() {
  int size = 6;
  int index = -1;
  Array arr(size);
  arr[0] = 2;
  arr[1] = 4;
  arr[2] = 6;
  arr[3] = 8;
  arr[4] = 10;
  arr[5] = 12;
  int searchingElement = 12;

  int correctIndex = 5;
  index = arr.BinarySearchAscending(searchingElement);
  if (index == correctIndex) {
    return true;
  } else {
    cout << "Test 5 failed" << endl;
    for (int i = 0; i < arr.GetSize(); i++) {
      cout << i + 1 << ")";
      cout << arr[i] << endl;
    }
    cout << "Correct index: " << correctIndex + 1 << endl;
    cout << "The resulting index: " << index + 1 << endl;

    return false;
  }
}


void CheckingTests() {
  int counter = 0;
  bool check;
  const int ALL_TESTS_PASSED = 5;

  check = Test1();

  if (check == true) {
    counter++;
  } 

  check = Test2();

  if (check == true) {
    counter++;
  }

  check = Test3();

  if (check == true) {
    counter++;
  }

  check = Test4();

  if (check == true) {
    counter++;
  }

  check = Test5();

  if (check == true) {
    counter++;
  }
 

  if (counter == ALL_TESTS_PASSED) {
    cout << "All tests passed successfully!" << endl;
  }
}
