#include "TesteFelipe.hpp"
#include "calculatorFelipe.hpp"
#include "ErrorFelipe.hpp"
#include <functional>
#include <iostream>

Calculator* build(){
    Calculator* calculator = new CalculatorFelipe();
    Display* display = new DisplayFelipe();
    Keyboard* keyboard = new KeyboardFelipe();
    Cpu* cpu = new CpuFelipe();

    KeyDigit *keyZero = new KeyDigitFelipe("0", ZERO);
  KeyDigit *keyOne = new KeyDigitFelipe("1", ONE);
  KeyDigit *keyTwo = new KeyDigitFelipe("2", TWO);
  KeyDigit *keyThree = new KeyDigitFelipe("3", THREE);
  KeyDigit *keyFour = new KeyDigitFelipe("4", FOUR);
  KeyDigit *keyFive = new KeyDigitFelipe("5", FIVE);
  KeyDigit *keySix = new KeyDigitFelipe("6", SIX);
  KeyDigit *keySeven = new KeyDigitFelipe("7", SEVEN);
  KeyDigit *keyEight = new KeyDigitFelipe("8", EIGHT);
  KeyDigit *keyNine = new KeyDigitFelipe("9", NINE);

  KeyOperator *keySum = new KeyOperatorFelipe("+", SUM);
  KeyOperator *keySubtraction = new KeyOperatorFelipe("-", SUBTRACTION);
  KeyOperator *keyMultiplication = new KeyOperatorFelipe("*", MULTIPLICATION);
  KeyOperator *keyDivision = new KeyOperatorFelipe("/", DIVISION);

  KeyControl *keyEqual = new KeyControlFelipe("=", EQUAL);
  KeyControl *keyDecimalSeparator = new KeyControlFelipe(".", DECIMAL_SEPARATOR);
  KeyControl *keyClearError = new KeyControlFelipe("ON_CE", ON_CLEAR_ERROR);
  KeyControl *keyOff = new KeyControlFelipe("OFF", OFF);
  KeyControl *keyMemoryReadClear =
      new KeyControlFelipe("MRC", MEMORY_READ_CLEAR);
  KeyControl *keyMemorySum = new KeyControlFelipe("M+", MEMORY_SUM);
  KeyControl *keyMemorySubtraction =
      new KeyControlFelipe("M-", MEMORY_SUBTRACTION);

  /* ... Inserir todas as teclas no teclado  */
  keyboard->add(keyZero);
  keyboard->add(keyOne);
  keyboard->add(keyTwo);
  keyboard->add(keyThree);
  keyboard->add(keyFour);
  keyboard->add(keyFive);
  keyboard->add(keySix);
  keyboard->add(keySeven);
  keyboard->add(keyEight);
  keyboard->add(keyNine);

  keyboard->add(keySum);
  keyboard->add(keySubtraction);
  keyboard->add(keyMultiplication);
  keyboard->add(keyDivision);

  keyboard->add(keyEqual);
  keyboard->add(keyClearError);
  keyboard->add(keyDecimalSeparator);
  keyboard->add(keyOff);
  keyboard->add(keyMemoryReadClear);
  keyboard->add(keyMemorySum);
  keyboard->add(keyMemorySubtraction);

  keyboard->setCpu(cpu);

  cpu->setDisplay(display);

  /* Conectando as partes da calculadora */
  calculator->setDisplay(display);
  calculator->setCpu(cpu);
  calculator->setKeyboard(keyboard);

  return calculator;
}

void test1(Calculator *calculator)
{
  calculator->getKeyboard()->getKey(ONE)->press();
  calculator->getKeyboard()->getKey(SUM)->press();
  calculator->getKeyboard()->getKey(ONE)->press();
  calculator->getKeyboard()->getKey(SUM)->press();
  calculator->getKeyboard()->getKey(ONE)->press();
  calculator->getKeyboard()->getKey(EQUAL)->press();

}

void test2(Calculator *calculator)
{
  calculator->getKeyboard()->getKey(ONE)->press();
  calculator->getKeyboard()->getKey(ONE)->press();
  calculator->getKeyboard()->getKey(ONE)->press();
  calculator->getKeyboard()->getKey(ONE)->press();
  calculator->getKeyboard()->getKey(ONE)->press();
  calculator->getKeyboard()->getKey(ONE)->press();
  calculator->getKeyboard()->getKey(SUM)->press();
  calculator->getKeyboard()->getKey(ONE)->press();
  calculator->getKeyboard()->getKey(ONE)->press();
  calculator->getKeyboard()->getKey(ONE)->press();
  calculator->getKeyboard()->getKey(ONE)->press();
  calculator->getKeyboard()->getKey(ONE)->press();
  calculator->getKeyboard()->getKey(ONE)->press();
  calculator->getKeyboard()->getKey(ONE)->press();
  calculator->getKeyboard()->getKey(EQUAL)->press();
}

void test3(Calculator *calculator)
{
  calculator->getKeyboard()->getKey(ONE)->press();
  calculator->getKeyboard()->getKey(TWO)->press();
  calculator->getKeyboard()->getKey(THREE)->press();
  calculator->getKeyboard()->getKey(SUM)->press();
  calculator->getKeyboard()->getKey(FOUR)->press();
  calculator->getKeyboard()->getKey(FIVE)->press();
  calculator->getKeyboard()->getKey(SIX)->press();
  calculator->getKeyboard()->getKey(EQUAL)->press();
  calculator->getKeyboard()->getKey(EQUAL)->press();
  calculator->getKeyboard()->getKey(EQUAL)->press();
  calculator->getKeyboard()->getKey(EQUAL)->press();
  calculator->getKeyboard()->getKey(SUM)->press();
  calculator->getKeyboard()->getKey(ONE)->press();
  calculator->getKeyboard()->getKey(EQUAL)->press();
}

void test4(Calculator *calculator)
{
  calculator->getKeyboard()->getKey(ON_CLEAR_ERROR)->press();
  calculator->getKeyboard()->getKey(DECIMAL_SEPARATOR)->press();
  calculator->getKeyboard()->getKey(ONE)->press();
  calculator->getKeyboard()->getKey(SUM)->press();
  calculator->getKeyboard()->getKey(DECIMAL_SEPARATOR)->press();
  calculator->getKeyboard()->getKey(ONE)->press();
  calculator->getKeyboard()->getKey(EQUAL)->press();
}

int main(){
  try{
  Calculator* calculator = build();

  calculator->getKeyboard()->getKey(ONE)->press();
  calculator->getKeyboard()->getKey(MEMORY_SUM)->press();
  calculator->getKeyboard()->getKey(SUM)->press();
  calculator->getKeyboard()->getKey(ONE)->press();
  calculator->getKeyboard()->getKey(ONE)->press();
  calculator->getKeyboard()->getKey(EQUAL)->press();
  calculator->getKeyboard()->getKey(MEMORY_SUM)->press();
  calculator->getKeyboard()->getKey(MEMORY_READ_CLEAR)->press();
  
  }catch(CalculatorErrorFelipe error){
    std::cout <<"Ocorreu um erro:" << error.getMessage();
  }

  return 0;
}