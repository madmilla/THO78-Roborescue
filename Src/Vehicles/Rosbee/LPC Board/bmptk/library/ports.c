#include "ports.h"
#include "LPC11xx.h"

void pin_configure_as_input(int port, int pin){
  if(port == 0){
    LPC_GPIO0->DIR = LPC_GPIO0->DIR & ~ (1 << pin);
  }else if(port == 1){
    LPC_GPIO1->DIR = LPC_GPIO1->DIR & ~ (1 << pin);
  }
}

void pin_configure_as_output(int port, int pin){
  if(port == 0){
    LPC_GPIO0->DIR = LPC_GPIO0->DIR | (1 << pin);
  }else if(port == 1){
    LPC_GPIO1->DIR = LPC_GPIO1->DIR | (1 << pin);
  }
}

void pin_set(int port, int pin, unsigned char x){
  if(port == 0){
    if(!x){
      LPC_GPIO0->DATA = LPC_GPIO0->DATA & ~ (1 << pin);
    }else{
      LPC_GPIO0->DATA = LPC_GPIO0->DATA | (1 << pin);
    }
  }else if(port == 1){
    if(!x){
      LPC_GPIO1->DATA = LPC_GPIO1->DATA & ~ (1 << pin);
    }else{
      LPC_GPIO1->DATA = LPC_GPIO1->DATA | (1 << pin);
    }
  }
}

unsigned char switch_get(int port, int pin){
    if(port == 0){
      return (LPC_GPIO0->DATA & (1 << pin)) == 0;
    }else if(port == 1){
      return (LPC_GPIO1->DATA & (1 << pin)) == 0;
    }
    return 255; //error code
}

unsigned char pin_get(int port, int pin){
    if(port == 0){
      return (LPC_GPIO0->DATA & (1 << pin)) != 0;
    }else if(port == 1){
      return (LPC_GPIO1->DATA & (1 << pin)) != 0;
    }
    return 255; //error code
}
