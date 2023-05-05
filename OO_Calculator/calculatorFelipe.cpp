#include "calculatorFelipe.hpp"
#include "ErrorFelipe.hpp"


//Calculator Implementações:
void CalculatorFelipe::setDisplay(Display* display) { 
  this->display = display; 
}

Display* CalculatorFelipe::getDisplay() { 
  return this->display; 
}

void CalculatorFelipe::setCpu(Cpu* cpu) { 
  this->cpu = cpu; 
}

Cpu* CalculatorFelipe::getCpu() { 
  return this->cpu; 
}

void CalculatorFelipe::setKeyboard(Keyboard* keyboard) { 
  this->keyboard = keyboard;
}

Keyboard* CalculatorFelipe::getKeyboard() { 
  return this->keyboard; 
}



