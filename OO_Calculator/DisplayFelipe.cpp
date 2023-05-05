#include "DisplayFelipe.hpp"
#include "ErrorFelipe.hpp"
#include <iostream>


//Display Implementações:
void DisplayFelipe::add(Digit digit) {
  switch (digit) {
  case ZERO:
    std::cout << "0";
    break;
  case ONE:
    std::cout << "1";
    break;
  case TWO:
    std::cout << "2";
    break;
  case THREE:
    std::cout << "3";
    break;
  case FOUR:
    std::cout << "4";
    break;
  case FIVE:
    std::cout << "5";
    break;
  case SIX:
    std::cout << "6";
    break;
  case SEVEN:
    std::cout << "7";
    break;
  case EIGHT:
    std::cout << "8";
    break;
  case NINE:
    std::cout << "9";
    break;
  default:
    std::cout << "E";
    throw CalculatorErrorFelipe("Digit not implemented");
  }
}

void DisplayFelipe::clear(){ 
  std::cout << "\n"; 
}

void DisplayFelipe::addDecimalSeparator(){
  std::cout << ".";
}

void DisplayFelipe::setSignal(Signal s){
  std::cout << (s==NEGATIVE?"-":"");
}