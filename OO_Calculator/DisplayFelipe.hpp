#pragma once
#include "calculator.hpp"

class DisplayFelipe: public Display{
  Signal signal = POSITIVE;
  public:
    void add(Digit digit);
    void addDecimalSeparator();
    void setSignal(Signal);
    void clear();
};