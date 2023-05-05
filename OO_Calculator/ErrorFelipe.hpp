#pragma once
#include "calculator.hpp"

class CalculatorErrorFelipe: public CalculatorError{
  char const* message;
  public:
    CalculatorErrorFelipe(char const* message);
    char const* getMessage();
};