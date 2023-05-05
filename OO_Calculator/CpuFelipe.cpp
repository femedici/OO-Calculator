#include "CpuFelipe.hpp"
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>

//Cpu Implementações:
float CpuFelipe::transform_digit_to_float(Digit* digits, int count,int pointer, Signal signal_){
  float aux_float = 0;
       for(int i = 0; i < count; i++){
          switch (digits[i]){
            case ZERO:  aux_float = aux_float+0;  break;
            case ONE:   aux_float = aux_float+1;  break;
            case TWO:   aux_float = aux_float+2;  break;
            case THREE: aux_float = aux_float+3;  break;
            case FOUR:  aux_float = aux_float+4;  break;
            case FIVE:  aux_float = aux_float+5;  break;
            case SIX:   aux_float = aux_float+6;  break;
            case SEVEN: aux_float = aux_float+7;  break;
            case EIGHT: aux_float = aux_float+8;  break;
            case NINE:  aux_float = aux_float+9;  break;
          }
         if(i!=(count-1)){  //verifica até o penultimo registrado, assim não multiplica por 10 no ultimo numero.
           aux_float = aux_float*10;
         }
       }
       if(pointer!=0){
           for(int i=count;i!=pointer;i--){
             //vai fazer até chegar a direita da onde o indicador de posição está apontando o "."
             aux_float = aux_float/10;
           }
         }
         if(signal_ == NEGATIVE){
          aux_float = aux_float*(-1);
         }
      return aux_float;
}

Digit* CpuFelipe::transform_float_to_digit(float result,int* cont_decimal_pointer,int* count_tamanho,Signal* signal){
  Digit* aux_memory = new Digit[8];
  if(result<0){
    *signal = NEGATIVE;
  }
  float aux_float;
  int aux_int;
  int count_aux_dec = 0;
  //pegar a parte decimal;
  aux_int = result;                            //pega a parte inteira
  aux_float = result - aux_int;                //pega a parte inteira
  if(aux_float!=0){                            //só vai verificar se tiver parte decimal
    if(aux_int == 0){
      count_aux_dec++;
    } 
    for(count_aux_dec; aux_int!=0;count_aux_dec++){
      aux_int = aux_int/10;
    }
  }

  *cont_decimal_pointer = count_aux_dec;
  
  std::string str;
  std::string str_aux;
  std::stringstream aux;

  //printf("RESULTADO:%f",result);
  if(result<0.1){
    aux << result;
    str = aux.str();
  }
  else{
    aux <<std::setprecision(8) << result;   
    str = aux.str();
    size_t found = str.find('e');
    if(found != std::string::npos) {
      str.erase(found, 1); // remove o caractere 'e'
    }
  }
  
  int count = 0;

  for (int i = 0; str[i]!= 0; i++) {
    if (str[i] != '-' && str[i] != '.') {
      str_aux[count] = str[i];
      count++;
    }
  }

  *count_tamanho = count;

  for(int i = 0;str_aux[i]!= 0; i++){
    switch (str_aux[i]){
      case '0':
        aux_memory[i] = ZERO;
        break;
      case '1':
        aux_memory[i] = ONE;
        break;
      case '2':
        aux_memory[i] = TWO;
        break;
      case '3':
        aux_memory[i] = THREE;
        break;
      case '4':
        aux_memory[i] = FOUR;
        break;
      case '5':
        aux_memory[i] = FIVE;
        break;
      case '6':
        aux_memory[i] = SIX;
        break;
      case '7':
        aux_memory[i] = SEVEN;
        break;
      case '8':
        aux_memory[i] = EIGHT;
        break;
      case '9':
        aux_memory[i] = NINE;
        break;
    }
  }

  return aux_memory;  
}

void CpuFelipe::show_result_display(){
      if(this->operator_ == MULTIPLICATION){
        if(this->signal1 == NEGATIVE){
          this->display->setSignal(NEGATIVE);
        }
        for(int i = 0; i < this->count_num1; i++){
          if(i==this->count_decimal1 && this->count_decimal1!=0){
            this->display->addDecimalSeparator();
          }
          this->display->add(this->reg1[i]);
        }
        this->reg_atual = 0;
      }
      else{
        if(this->signal2 == NEGATIVE){
          this->display->setSignal(NEGATIVE);
        }
        for(int i=0; i < this->count_num2;i++){
          if(i==this->count_decimal2 && this->count_decimal2!=0){
            this->display->addDecimalSeparator();
          } 
          this->display->add(this->reg2[i]);
        }
        this->reg_atual = 1;
      }
}

void CpuFelipe::process_equal(Digit* res){
  int flag;
  float result;
  float reg1;
  float reg2;
  int cont_decimal = 0;
  int tamanho_result = 0;
  Signal signal = POSITIVE;
  if(this->count_num2 == 0){
    flag = 1;
  }
  else{
    flag = 0;
  }
  reg1 = transform_digit_to_float(this->reg1,this->count_num1,this->count_decimal1,this->signal1); //Transformando o registrador 1 em float.
  reg2 = transform_digit_to_float(this->reg2,this->count_num2,this->count_decimal2,this->signal2); // Transformando o registrador 2 em float.
  //printf("REG1:%f\n\n",reg1);
  //printf("REG2:%f\n\n",reg2);

  if(this->operator_ == SUM){
    result = reg2 + reg1;
  }
  else if(this->operator_ == SUBTRACTION){
    result = reg2 - reg1;
  }
  else if(this->operator_ == DIVISION){
    result = reg2/reg1;
  }
  else if(this->operator_ == MULTIPLICATION){
    result = reg2*reg1;
  }

  //printf("RESULT:%f\n\n\n",result);
  res = transform_float_to_digit(result,&cont_decimal,&tamanho_result,&signal);  
  
  // printf("\n\n\n");
  // for(int i = 0; i < tamanho_result;i++){
  //   this->display->add(res[i]);
  // }
  // printf("\n\n\n");


  if(this->operator_ == MULTIPLICATION){  //Multiplicação se comporta de forma diferente, pois ela guarda o primeiro número digitado e não o segundo Ex: 20*2=40=(20*40)
    for(int i = 0; i < tamanho_result; i++){
      this->reg1[i] = res[i];
    }
    this->count_num1 = tamanho_result;
    this->count_decimal1 = cont_decimal;
    this->signal1 = signal;

  }
  else{                                    //Se não for multiplicação todos funciona da mesma forma
    for(int i = 0; i < 8; i++){            //Passando o resultado do res para o registrador2, não perdendo o último valor digitado que está no registrador1, fazendo com que um comando de '=' '=' '=' funcione.
      this->reg2[i] = res[i];
    }
    this->count_num2 = tamanho_result;
    this->count_decimal2 = cont_decimal;
    this->signal2 = signal;
  }
  this->press_equal = 1;
  printf("\n");
  if(flag!=1){
    this->show_result_display();
  }
}

void CpuFelipe::process_multiplication(){
    float reg1;
    float reg2;
    float result;
    int count_decimal;
    int tamanho_result;
    Signal signal = POSITIVE;

    reg1 = transform_digit_to_float(this->reg1,this->count_num1,this->count_decimal1,this->signal1);
    reg2 = transform_digit_to_float(this->reg2,this->count_num2,this->count_decimal2,this->signal2);

    result = reg2 * reg1;

    Digit* res = transform_float_to_digit(result,&count_decimal, &tamanho_result,&signal);


    for(int i = 0; i < tamanho_result; i++){
        this->reg2[i] = res[i];
    }
    this->count_decimal2 = count_decimal;
    this->count_num2 = tamanho_result;
    this->signal2 = signal;
    
    this->operator_ = SUM;
    this->display->clear();
    this->show_result_display();
}

CpuFelipe::CpuFelipe(){
  this->count_decimal1 = 0;
  this->count_decimal2 = 0;
  this->count_decimalmem = 0;
  this->count_num1 = 0;
  this->count_num2 = 0;
  this->count_nummem = 0;
  this->operator_ = SUM;
  this->flag_first_op = 1;
  this->mrc = 0;
  this->reg_atual = 0;
  for(int i = 0; i < 8; i++){
    this->reg1[i] = ZERO;
    this->reg2[i] = ZERO;
    this->regmem[i] = ZERO;
  }
}

void CpuFelipe::receive(Digit digit){
  if(this->display){
    this->mrc = 0;
    if(((digit == ZERO) && (this->count_num1 == 1) && (this->reg1[0] == ZERO && this->count_decimal1 == 0)) || (this->count_num1 == 8)){
      return;
    }
    this->reg1[count_num1] = digit;
    count_num1++;
    this->display->add(digit);
  }
}

void CpuFelipe::receive(Operator o){
  if(this->display){ 
    this->mrc = 0;
    if((this->operator_ == SUM) || (this->operator_ == SUBTRACTION) || (this->operator_ == DIVISION)){
      if(this->press_equal == 1){
        for(int i = 0; i < this->count_num1; i++){
          this->reg1[i] = ZERO;
        }
        this->operator_ = o;
        this->press_equal = 0;
        std::cout << "\n";
        return;
      }
      this->receive(EQUAL);
      this->press_equal = 0;
      for(int i = 0; i < 8; i++){
        this->reg1[i] = ZERO;
      }
      this->count_num1 = 0;
      this->count_decimal1 = 0;
      this->signal1 = POSITIVE;
      this->operator_ = o;
      if(this->flag_first_op == 0){
        this->display->clear();
      }
      this->flag_first_op = 0;
      return;
    }
    else if(this->operator_ == MULTIPLICATION){
        if(this->press_equal == 1){
          for(int i = 0; i < this->count_num1; i++){
            this->reg2[i] = this->reg1[i];
            this->reg1[i] = ZERO;
          }
          this->count_decimal2 = this->count_decimal1;
          this->count_num2 = this->count_num1;
          this->signal2 = this->signal1;
          this->count_decimal1 = 0;
          this->count_num1 = 0;
          this->signal1 = POSITIVE;
          this->operator_ = o;
          this->press_equal = 0;
          this->display->clear();
          return;
        }
        process_multiplication();
        this->display->clear();
        for(int i = 0; i < 8; i++){
            this->reg1[i] = ZERO;
        }
        this->count_num1 = 0;
        this->count_decimal1 = 0;
        this->signal1 = POSITIVE;
        this->operator_ = o;
    }
     
  }
}

void CpuFelipe::receive(Control c){
  Digit* res = new Digit[8];
  float regmem_aux;
  float reg_atual_aux; 
  Digit* reg_return;
  if(c != MEMORY_READ_CLEAR){
    this->mrc = 0;
  }
  if(this->display){
    switch (c){
      case DECIMAL_SEPARATOR:
        if(this->count_num1 == 0){              //Se o contador estiver zerado, significa que não há nenhum número no registrador
          this->reg1[0]=ZERO;                   //coloca o zero
          this->count_num1 ++;                  //encrementa e trata para a posicao do "."
        } 
        this->count_decimal1 = count_num1;      //Se já houver algum número no registrador, ele o número de digits que há, isso mostrará ao lado de qual deles a vírgula estará
        this->display->addDecimalSeparator();
        break;

      case EQUAL:
        process_equal(res);
        break;

      case ON_CLEAR_ERROR:                        //Ainda nao finalizado. Como dar clear no operator e no control?
        for(int i = 0; i < 8; i++){            //Zerando todos os valores dos dois registradores
          this->reg1[i] = ZERO;
          this->reg2[i] = ZERO;
        }
        this->count_decimal1 = 0;              //Zerando a posicao da virgula dos dois registradores
        this->count_decimal2 = 0;
        this->count_num1 = 0;                  //Zerando o contador de numeros dos dois registradores
        this->count_num2 = 0;
        this->signal1 = POSITIVE;
        this->signal2 = POSITIVE;
        this->flag_first_op = 1;
        this->operator_ = SUM;

        break;

      case OFF:
        return;
        break;
      
      case MEMORY_READ_CLEAR:
          this->display->clear();
        if(this->mrc == 1){
          this->count_decimalmem = 0;
          this->count_nummem = 0;
          this->signalmem = POSITIVE;
          for(int i = 0; i < 8; i++){
            this->regmem[i] = ZERO;
          }  
          this->mrc = 0;
        }
        else{
          for(int i = 0; i < this->count_nummem; i++){
            this->reg1[i] = this->regmem[i];
          }
          this->count_decimal1 = this->count_decimalmem;
          this->count_num1 = this->count_nummem; 
          this->signal1 = this->signalmem;
          this->operator_ = MULTIPLICATION; //Transformando em multiplication para mostrar o primeiro registrador no show display. 
          this->show_result_display();
          this->operator_ = SUM;
          this->mrc = 1;
        }
        break;

      case MEMORY_SUM:
          this->display->clear();
          if(this->reg_atual == 0){
            regmem_aux = transform_digit_to_float(this->regmem,this->count_nummem,this->count_decimalmem,this->signal1);
            reg_atual_aux = transform_digit_to_float(this->reg1,this->count_num1,this->count_decimal1,this->signal1);
            regmem_aux += reg_atual_aux;
            reg_return = transform_float_to_digit(regmem_aux,&this->count_decimalmem,&this->count_nummem,&this->signalmem);
          }
          else if(this->reg_atual == 1){
            regmem_aux = transform_digit_to_float(this->regmem,this->count_nummem,this->count_decimalmem,this->signalmem);
            reg_atual_aux = transform_digit_to_float(this->reg2,this->count_num2,this->count_decimal2,this->signal2);
            regmem_aux += reg_atual_aux;
            reg_return = transform_float_to_digit(regmem_aux,&this->count_decimalmem,&this->count_nummem,&this->signalmem);
          }
          for(int i = 0; i < this->count_nummem; i++){
            this->regmem[i] = reg_return[i];
          }

          if(this->signalmem == NEGATIVE){
          this->display->setSignal(NEGATIVE);
          }
          for(int i=0; i < this->count_nummem;i++){
            if(i==this->count_nummem && this->count_nummem!=0){
              this->display->addDecimalSeparator();
            } 
            this->display->add(this->regmem[i]);
          }
       break;

      case MEMORY_SUBTRACTION:
          this->display->clear();
          if(this->reg_atual == 0){
            regmem_aux = transform_digit_to_float(this->regmem,this->count_nummem,this->count_decimalmem,this->signal1);
            reg_atual_aux = transform_digit_to_float(this->reg1,this->count_num1,this->count_decimal1,this->signal1);
            regmem_aux -= reg_atual_aux;
            reg_return = transform_float_to_digit(regmem_aux,&this->count_decimalmem,&this->count_nummem,&this->signalmem);
          }
          else if(this->reg_atual == 1){
            regmem_aux = transform_digit_to_float(this->regmem,this->count_nummem,this->count_decimalmem,this->signalmem);
            reg_atual_aux = transform_digit_to_float(this->reg2,this->count_num2,this->count_decimal2,this->signal2);
            regmem_aux -= reg_atual_aux;
            reg_return = transform_float_to_digit(regmem_aux,&this->count_decimalmem,&this->count_nummem,&this->signalmem);
          }
          for(int i = 0; i < this->count_nummem; i++){
            this->regmem[i] = reg_return[i];
          }
          
          if(this->signalmem == NEGATIVE){
          this->display->setSignal(NEGATIVE);
          }
          for(int i=0; i < this->count_nummem;i++){
          if(i==this->count_nummem && this->count_nummem!=0){
            this->display->addDecimalSeparator();
          } 
          this->display->add(this->regmem[i]);
          }
       break;

    }
  
  }
}

void CpuFelipe::setDisplay(Display* display){
  this->display = display;
}