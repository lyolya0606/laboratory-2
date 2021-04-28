#pragma once
#include "ArrayClass.h"

class Input {
public:

  virtual Array Read() = 0;

};

class KeyboardInput : public Input {

  Array Read();

};

class RandomInput : public Input {

  Array Read();

};

class FileInput : public Input {

  Array Read();

};