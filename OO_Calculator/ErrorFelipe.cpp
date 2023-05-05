#include "ErrorFelipe.hpp"

//CalculatorError Implementações:

CalculatorErrorFelipe::CalculatorErrorFelipe(char const* message){
  this->message = message;
}

char const* CalculatorErrorFelipe::getMessage(){
  return this->message;
}