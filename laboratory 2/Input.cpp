#include <iostream>
#include "FormattingInput.h"
#include "ArrayClass.h"
#include "InputClass.h"
#include "Beginning.h"
#include <string>
#include <fstream>
#include <ctime>

using namespace std;

ifstream OpenFileInput(void);

enum choiceInput {
  CHOICE_KEYBOARD = 1,
  CHOICE_RANDOM,
  CHOICE_FILE
};

Array KeyboardInput::Read() {
  int size = 0;

  do {

    cout << "Enter the array size: ";
    size = GetInt();
    if (size <= 0) {
      cout << "The array size cannot be less than one!" << endl;
    }
  } while (size <= 0);

  Array arrFilled(size);

  for (int i = 0; i < size; i++) {
    cout << i + 1 << ")";
    arrFilled[i] = GetDouble();

    if (i >= 1) {

      if (arrFilled[0] < arrFilled[1]) {

        if (arrFilled[i] < arrFilled[i - 1]) {
          cout << "The array must be sorted. Enter this element again." << endl;
          i--;
        }
      } else {

        if (arrFilled[i] > arrFilled[i - 1]) {
          cout << "The array must be sorted. Enter this element again." << endl;
          i--;
        }
      }
    }
  }
  return arrFilled; 
  
}


Array RandomInput::Read() {
  const int ASCENDING_SORT = 0;
  const int DESCENDING_SORT = 1;
  const double LEFT_BOARDER = 1.0;
  const double RIGHT_BOARDER = 100.0;

  int size = 0;
  srand(static_cast<unsigned int>(time(NULL)));

  do {

    cout << "Enter the array size: ";
    size = GetInt();

    if (size <= 0) {
      cout << "The array size cannot be less than one!" << endl;
    }

  } while (size <= 0);

  Array arrFilled(size);
  double tmp;

  for (int i = 0; i < size; i++) {
    tmp = LEFT_BOARDER + RIGHT_BOARDER * rand() / (static_cast<double>(RAND_MAX));
    arrFilled[i] = (int)(tmp * 100) / 100.0;
  }

  int sorting = rand() & DESCENDING_SORT + ASCENDING_SORT;

  if (sorting == ASCENDING_SORT) {
    arrFilled.AscendingSort();
  } else arrFilled.DescendingSort();

  for (int i = 0; i < size; i++) {
    cout << i + 1 << ")";
    cout << arrFilled[i] << endl;

  }
  return arrFilled;
  
}

Array FileInput::Read() {
  int size = 0;
  string path;
  string line;
  int checkingSize = 0;
  bool checkingData = true;
  int counterAscending = 0;
  int counterDescending = 0;
  ifstream file;

  do {

    do {

      do {
        file = OpenFileInput();
        checkingSize = 0;
        try {
          getline(file, line);
          size = stoi(line);

          if (size <= 0) {
            throw 1;
          }
          checkingData = true;
        }
        catch (invalid_argument size) {
          cout << "Incorrect data in the file! Try again." << endl;
          checkingData = false;

        }
        catch (int negativeSize) {
          if (negativeSize == 1) {
            checkingSize++;
            cout << "Incorrect data in the file! Try again." << endl;
          }
        }
   
      } while (checkingSize != 0 || checkingData == false);

      if (checkingSize == 0) {
        try {
          Array arrFilled(size);

          for (int i = 0; i < size; i++) {
            getline(file, line);
            arrFilled[i] = stod(line);
          }

          checkingData = true;

          counterAscending = 0;
          counterDescending = 0;
          for (int i = 0; i < size; i++) {

            if (i >= 1) {

              if (arrFilled[0] < arrFilled[1]) {

                if (arrFilled[i] > arrFilled[i - 1]) {
                  counterAscending++;

                }
              } else {

                if (arrFilled[i] < arrFilled[i - 1]) {
                  counterDescending++;
                }
              }
            }
          }

          if (counterAscending == size - 1 || counterDescending == size - 1) {
            cout << "Read data:" << endl;

            for (int i = 0; i < size; i++) {
              cout << i + 1 << ")";
              cout << arrFilled[i] << endl;
            }
            return arrFilled;
          }
        }

        catch (invalid_argument arrFilled) {
          cout << "Incorrect data in the file! Try again." << endl;
          checkingData = false;
        }
      }
    } while (checkingData == false);
    
    
    if (counterAscending != 0 || counterDescending != 0) {
      cout << "The array must be sorted. Choose another file." << endl;
    }

  } while (counterAscending != 0 || counterDescending != 0);
  return -1;

}

Input *ChoiceInput(int *result) {
  int choice = 0;

  do {
    MenuWorkArray();
    choice = GetInt();

    switch (choice) {

    case CHOICE_KEYBOARD:
    {
      KeyboardInput *keyboardInput = new KeyboardInput;
      (*result) = CHOICE_KEYBOARD;
      return keyboardInput;
    }

    case CHOICE_RANDOM:
    {     
      RandomInput *randomInput = new RandomInput;
      (*result) = CHOICE_RANDOM;
      return randomInput;
    }

    case CHOICE_FILE:
    {
      FileInput *fileInput = new FileInput;
      (*result) = CHOICE_FILE;
      return fileInput;
    }

    default:
      cout << "There is no such choice!" << endl;
      (*result) = 0;
      break;
    }
  } while (true);
}

