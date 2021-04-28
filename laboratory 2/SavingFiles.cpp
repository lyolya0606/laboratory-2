#include <iostream>
#include <string>
#include <fstream>
#include "FormattingInput.h"
#include "ArrayClass.h"

using namespace std;

ofstream OpenFileOutput(void);

Array SavingFilesInput(Array arr) {
  int size = 0;
  size = arr.GetSize();
  cout << endl << "Press 1 if you want to save your input in the file" << endl
    << "Press 2 if you DON'T want to save your input in the file" << endl;
  int choice = GetInt();
  const int SAVING = 1;
  const int NOT_SAVING = 2;

  while (choice != SAVING && choice != NOT_SAVING) {
    cout << "There is no such choice!" << endl << endl
      << "Press 1 if you want to save your input in the file" << endl
      << "Press 2 if you DON'T want to save your input in the file" << endl;

    choice = GetInt();
  }

  if (choice == SAVING) {
    ofstream file = OpenFileOutput();
    
    file << size << endl;

    for (int i = 0; i < size; i++) {
      file << arr[i] << endl;
    }

    file.close();
    cout << "Your input is successfully saved!" << endl;
  } else if (choice == NOT_SAVING) {
  }

  return arr;
}

Array SavingFilesResult(Array arr, int index) {
  int size = 0;
  size = arr.GetSize();

  const int SAVING = 1;
  const int NOT_SAVING = 2;

  cout << endl << "Press 1 if you want to save your result in the file" << endl
    << "Press 2 if you DON'T want to save your result in the file" << endl;
  int choice = GetInt();

  while (choice != SAVING && choice != NOT_SAVING) {
    cout << "There is no such choice!" << endl
      << "Press 1 if you want to save your input in the file" << endl
      << "Press 2 if you DON'T want to save your input in the file" << endl;

    choice = GetInt();
  }

  if (choice == SAVING) {
    ofstream file = OpenFileOutput();

    file << "Saved array:" << endl;

    for (int i = 0; i < size; i++) {
      file << i + 1 << ")" << arr[i] << endl;
    }

    if (index == -1) {
      file << "There is no such element in the array" << endl;
    } else {
      file << "Index of the desired element: " << index + 1;
    }    

    file.close();
    cout << "Your result is successfully saved!" << endl;
  }
  return arr;

}
