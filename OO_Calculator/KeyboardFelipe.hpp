#pragma once
#include "calculator.hpp"
#include <vector>



class KeyboardFelipe: public Keyboard{
  Cpu* cpu;
  std::vector<Key*> keys;
  char keysCount = 0;
  public:
    void receive(Digit);
    void receive(Operator);
    void receive(Control);
    Key* getKey(Digit);
    Key* getKey(Operator);
    Key* getKey(Control);
    Key* getKey(Symbol);
    void add(Key*);
    void setCpu(Cpu*); 
    
};

class KeyDigitFelipe: public KeyDigit{
  Symbol symbol;
  Digit digit;
  Keyboard* keyboard;
  public:
    KeyDigitFelipe(Symbol, Digit);
    void press();
    Symbol getSymbol();
    void setKeyboard(Keyboard*);
    Digit getDigit();
};

class KeyControlFelipe: public KeyControl{
    Symbol symbol;
    Control control;
    Keyboard* keyboard;
  public:
    KeyControlFelipe(Symbol, Control);
    void press();
    Symbol getSymbol();
    void setKeyboard(Keyboard*);
    Control getControl();
};

class KeyOperatorFelipe: public KeyOperator{
    Symbol symbol;
    Operator operator_;
    Keyboard* keyboard;
  public:
    KeyOperatorFelipe(Symbol, Operator);
    void press();
    Symbol getSymbol();
    void setKeyboard(Keyboard*);
    Operator getOperator();
};