#pragma once

class Array {
private:
  int size = 0;
  double *arr = nullptr;

public:
  Array(int inputSize);

  Array(Array&& oldArray);

  double &operator[](int index);
  
  int BinarySearchAscending(double searchingElement);

  int BinarySearchDescending(double searchingElement);

  void AscendingSort();

  void DescendingSort();

  int GetSize();

  void Print(int index, char sep = ' ');

  ~Array();
};

