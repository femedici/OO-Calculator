#include "calculator.hpp"
#include "CpuFelipe.hpp"
#include "DisplayFelipe.hpp"
#include "KeyboardFelipe.hpp"
#include "console.hpp"

class CalculatorFelipe: public Calculator{
    Display *display;
    Cpu *cpu;
    Keyboard *keyboard;
  public:
    void setDisplay(Display*);
    Display* getDisplay();
    void setCpu(Cpu*);
    Cpu* getCpu();
    void setKeyboard(Keyboard*);
    Keyboard* getKeyboard();
};

