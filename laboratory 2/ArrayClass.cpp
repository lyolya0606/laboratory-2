#include "ArrayClass.h"
#include <iostream>
#include <windows.h>

using namespace std;

Array::Array(int inputSize) : size(inputSize) {
  arr = new double[inputSize];
}

double &Array::operator[](int index) {
  return arr[index];
}

Array::Array(Array&& oldArray) {
  arr = oldArray.arr;
  size = oldArray.size;
  oldArray.arr = nullptr;
  oldArray.size = 0;
}

int Array::BinarySearchAscending(double searchingElement) {
  bool repeat = true;
  int checkElement = 0;
  int middle = 0;
  int leftBorder = 0;
  int rightBorder = size - 1;

  for (int i = 0; i < size; i++) {
    if (arr[i] == searchingElement) {
      checkElement++;
    }
  }

  if (checkElement == 0) {
    return -1;
  }

  do {
    middle = (rightBorder + leftBorder) / 2;

    if (arr[middle] == searchingElement) {
      return middle;
    } else {

      if ((rightBorder - leftBorder) == 1) {
        return middle + 1;
      }

      if (searchingElement <= arr[middle]) {
        rightBorder = middle;
        repeat = false;
      } else {
        leftBorder = middle;
        repeat = false;
      }
    }
  } while (repeat == false);

  return -1;

}

int Array::BinarySearchDescending(double searchingElement) {
  bool repeat = true;
  int checkElement = 0;
  int middle = 0;
  int leftBorder = 0;
  int rightBorder = size - 1;

  for (int i = 0; i < size; i++) {
    if (arr[i] == searchingElement) {
      checkElement++;
    }
  }

  if (checkElement == 0) {
    return -1;
  }

  do {
    middle = (rightBorder + leftBorder) / 2;

    if (arr[middle] == searchingElement) {
      return middle;
    } else {

      if ((rightBorder - leftBorder) == 1) {
        return middle + 1;
      }

      if (searchingElement >= arr[middle]) {
        rightBorder = middle;
        repeat = false;
      } else {
        leftBorder = middle;
        repeat = false;
      }
    }
  } while (repeat == false);

  return -1;

}

void Array::Print(int index, char sep) {
  const int WHITE = 15;
  const int COLOR = 4;
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

  for (int i = 0; i < size; i++) {

    if (index == i) {
      SetConsoleTextAttribute(hConsole,(WORD) (WHITE << COLOR | FOREGROUND_GREEN));
      cout << arr[i] << sep;
      SetConsoleTextAttribute(hConsole, (WORD)(WHITE << COLOR | 0));
      i++;
    }

    if (i == size) {
      break;
    }

    cout << arr[i] << sep;
  }
      
}

void Array::AscendingSort() {
  for (int j = size - 1; j > 0; j--) {
    for (int i = 0; i < j; i++) {

      if (abs(arr[i]) > abs(arr[i + 1])) {
        swap(arr[i], arr[i + 1]);
      }
    }
  }
}

void Array::DescendingSort() {
  for (int j = size - 1; j > 0; j--) {
    for (int i = 0; i < j; i++) {

      if (abs(arr[i]) < abs(arr[i + 1])) {
        swap(arr[i], arr[i + 1]);
      }
    }
  }
}

int Array::GetSize() {
  return size;
}

Array::~Array() {
  delete[] arr;
}

