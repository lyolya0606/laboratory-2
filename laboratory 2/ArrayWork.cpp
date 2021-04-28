#include <iostream>
#include "ArrayClass.h"
#include "InputClass.h"
#include "FormattingInput.h"
#include "Beginning.h"
#include "SavingData.h"
#include <windows.h>

using namespace std;

enum choiceInput {
  CHOICE_KEYBOARD = 1,
  CHOICE_RANDOM,
  CHOICE_FILE
};

Input *ChoiceInput(int *result);

void ArrayWork(void) {
  int result = 0;
  double searchingElement = 0;
  int index = 0;
  Input *input = ChoiceInput(&result);
  Array arr = input->Read();
  delete input;
  const int WHITE = 15;
  const int COLOR = 4;

  cout << "Enter the element whose index you want to find: ";
  searchingElement = GetDouble();
  
  if (arr[0] < arr[1]) {
    index = arr.BinarySearchAscending(searchingElement);
  } else index = arr.BinarySearchDescending(searchingElement);

  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

  if (index == -1) {
    SetConsoleTextAttribute(hConsole, (WORD)(WHITE << COLOR | FOREGROUND_RED));
    cout << "There is no such element in the array" << endl;
    SetConsoleTextAttribute(hConsole, (WORD)(WHITE << COLOR | 0));
  } else {
    cout << endl;
    arr.Print(index);
    cout << endl << "Index: " << index + 1 << endl;
  }

  if (result == CHOICE_KEYBOARD || result == CHOICE_RANDOM) {
    Array arrSaving = SavingFilesInput(move(arr));
    SavingFilesResult(move(arrSaving), index);
  } else {
    Array arrSaving = SavingFilesResult(move(arrSaving), index);
  }
}