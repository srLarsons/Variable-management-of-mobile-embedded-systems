#include <essDisplay.h>
#include "display.h"

bool __attribute__((OS_buttonPress)) buttonPress(bool button) {
  bool press = 0;
  asm volatile ("  cpi %1, 1          \n\t" 
                "  brne button1       \n\t"
                "button0:             \n\t"
                "  sbis %2, 5         \n\t"
                "  jmp returnFalse    \n\t"
                "  jmp returnTrue     \n\t"
                "button1:             \n\t"
                "  sbis %3, 4         \n\t"
                "  jmp returnFalse    \n\t"
                "  jmp returnTrue     \n\t"
                "returnTrue:          \n\t"
                "  ldi %0, 1          \n\t"
                "  jmp end            \n\t"
                "returnFalse:         \n\t"
                "  ldi %0, 0          \n\t"
                "end:                 \n\t"
                : "=r" (press) 
                : "w"  (button), "I"(_SFR_IO_ADDR(PING)), "I"(_SFR_IO_ADDR(PINF)) );
  
  return press;
}

short int counter0 =0;
float counter1     =0;
bool  direction    =1;
bool  counter      =0;

void setup() {
  float version = 0.4;
    
  Serial.begin(9600);
  Serial.println("----------------------------------");
  Serial.println("PKES Wintersemester 2014/15"       );
  Serial.print  ("Vorlage 1. essBot - Version "      );
  Serial.println(version                             );
  Serial.println("----------------------------------");

  initDisplay();
}

void loop() {
  delay(100);
 
  if(buttonPress(0)) direction=!direction;
  
  if(buttonPress(1)) counter  =!counter;
  
  if(counter){
    counter1 += direction ? 0.1 : -0.1;
    writetoDisplay(counter1);
    Serial.print("Float: "); Serial.println(counter1);
  }
  else{
    writetoDisplay(direction ? (int)counter0++ : (int)counter0--);
    Serial.print("Int: "); Serial.println((int)counter0);
  }
}

