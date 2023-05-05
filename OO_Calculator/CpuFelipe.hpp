#pragma once
#include "calculator.hpp"

class CpuFelipe: public Cpu{
  Display* display;
  Digit reg1[8];
  Digit reg2[8];
  Digit regmem[8];
  int count_num1;
  int count_num2;
  int count_nummem;
  int count_decimal1;
  int count_decimal2;
  int count_decimalmem;
  Signal signal1;
  Signal signal2;
  Signal signalmem;
  Operator operator_;
  bool flag_first_op;
  bool mrc;
  bool press_equal;
  bool reg_atual;
  
  float transform_digit_to_float(Digit* digits, int count,int pointer, Signal signal_);
  Digit* transform_float_to_digit(float result,int* cont_decimal_pointer,int* count_tamanho,Signal* signal);
  void show_result_display();
  void process_equal(Digit* res);
  void process_multiplication();

  public:
    CpuFelipe();
    void receive(Digit);
    void receive(Operator);
    void receive(Control);
    void setDisplay(Display*);
};
