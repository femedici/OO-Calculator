#include "KeyboardFelipe.hpp"
#include "ErrorFelipe.hpp"
#include <iostream>


//Keyboard Implementações:
void KeyboardFelipe::receive(Digit d){
  if(this->cpu){
  this->cpu->receive(d);
  }
  else{ 
     std::cout << "Keyboard without cpu!\n";
  }
}

void KeyboardFelipe::receive(Operator o){ 
  if(this->cpu){
    this->cpu->receive(o);
    }
  else{ 
    std::cerr << "Keyboard without cpu!\n";
  } 
}

void KeyboardFelipe::receive(Control c){ 
  if(this->cpu){
    this->cpu->receive(c);
  }
  else{
    std::cout << "Keyboard without cpu!\n";
  } 
}

Key* KeyboardFelipe::getKey(Digit d){ 
for(Key* key: this->keys){
  if(dynamic_cast<KeyDigit*>(key) && ((KeyDigit*)key)->getDigit() == d){
    return key; 
  }
}
throw new CalculatorErrorFelipe("Key with digit not found!"); 
}

Key* KeyboardFelipe::getKey(Operator o){
  for(Key* key: this->keys){
    if(dynamic_cast<KeyOperator*>(key) && ((KeyOperator*)key)->getOperator() == o){ 
      return key; 
    }  
  }
    throw new CalculatorErrorFelipe("Key with operator not found!"); 
  
}

Key* KeyboardFelipe::getKey(Control c){
  for(Key* key: this->keys){ 
    if(dynamic_cast<KeyControl*>(key) && ((KeyControl*)key)->getControl() == c){ 
      return key; 
    }
  }   
      throw new CalculatorErrorFelipe("Key with control not found!");
}

Key* KeyboardFelipe::getKey(Symbol s){
  for(Key* key: this->keys){ 
    if(key->getSymbol() == s) {
      return key; 
    }
  }
    throw new CalculatorErrorFelipe("Key with symbol not found!");
}

void KeyboardFelipe::add(Key* k){
  if (k != NULL){
    this->keys.push_back(k);
    k->setKeyboard(this);
  }
}

void KeyboardFelipe::setCpu(Cpu* cpu){
  this->cpu = cpu;
}



//Key Digit Implementações:

KeyDigitFelipe::KeyDigitFelipe(Symbol symbol, Digit digit){
  this->symbol = symbol;
  this->digit = digit;
}

void KeyDigitFelipe::press(){
  //if(this->keyboard != NULL){
    this->keyboard->receive(this->digit);
  //}
}

Symbol KeyDigitFelipe::getSymbol() { 
  return this->symbol;
}

void KeyDigitFelipe::setKeyboard(Keyboard * keyboard) { 
  this->keyboard = keyboard;
}

Digit KeyDigitFelipe::getDigit() { 
  return this->digit;
}



//Key Control implemtentações:

KeyControlFelipe::KeyControlFelipe(Symbol symbol, Control control) {
  this->symbol = symbol;
  this->control = control;
}

void KeyControlFelipe::press() {
  if (this->keyboard != NULL)
    this->keyboard->receive(this->control);
}

Symbol KeyControlFelipe::getSymbol() { 
  return this->symbol; 
}

void KeyControlFelipe::setKeyboard(Keyboard *keyboard) {
  this->keyboard = keyboard;
}

Control KeyControlFelipe::getControl() { 
  return this->control; 
}



//Key Operator implementações:

KeyOperatorFelipe::KeyOperatorFelipe(Symbol symbol, Operator operator_) {
  this->symbol = symbol;
  this->operator_ = operator_;
}

void KeyOperatorFelipe::press() {
  if (this->keyboard != NULL)
    this->keyboard->receive(this->operator_);
}

Symbol KeyOperatorFelipe::getSymbol() { 
  return this->symbol; 
}

void KeyOperatorFelipe::setKeyboard(Keyboard *keyboard) {
  this->keyboard = keyboard;
}

Operator KeyOperatorFelipe::getOperator() { 
  return this->operator_; 
}