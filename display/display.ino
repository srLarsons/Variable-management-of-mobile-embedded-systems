#include "display.h"

char cDisplayBuffer[3] = {0,0,0};

void writetoDisplay(int value) {
  char cBuffer [4];
  
  if(value >= -99 && value < 1000){
    sprintf(cBuffer, "%3d", value);
    cDisplayBuffer[0] = displayMask(cBuffer[0]);
    cDisplayBuffer[1] = displayMask(cBuffer[1]);
    cDisplayBuffer[2] = displayMask(cBuffer[2]);
  }                 
  else if(value < -99 && value > -200) {
    sprintf(cBuffer, "%4d", value);
    cDisplayBuffer[0] = displayMask(cBuffer[0]) | displayMask(cBuffer[1]);
    cDisplayBuffer[1] = displayMask(cBuffer[2]);
    cDisplayBuffer[2] = displayMask(cBuffer[3]);
  } else {
    cDisplayBuffer[0] = displayMask('E'); 
    cDisplayBuffer[1] = displayMask('r');
    cDisplayBuffer[2] = displayMask('r') | displayMask('.');
  }
  
  writetoDisplay(cDisplayBuffer[0], cDisplayBuffer[1], cDisplayBuffer[2]);
}

void writetoDisplay(float value, char dec) {
  switch(dec){
    case 2:{
      writetoDisplay(int(value * 100));
      writetoDisplay(cDisplayBuffer[0]|displayMask('.'), cDisplayBuffer[1], cDisplayBuffer[2]);
      break;   
    }
    case 1:{
      writetoDisplay(int(value * 10));
      writetoDisplay(cDisplayBuffer[0], cDisplayBuffer[1]|displayMask('.'), cDisplayBuffer[2]);
      break;
    }
    default:{
      writetoDisplay(int(value));
      writetoDisplay(cDisplayBuffer[0], cDisplayBuffer[1], cDisplayBuffer[2]|displayMask('.'));
    }
  }
}

uint8_t displayMask(char val){
  switch(val){
    case ' ': return 0b00000000;
    case '0': return 0b11111100;

    case '1': return 0b01100000;
    case '2': return 0b11011010;
    case '3': return 0b11110010;
    case '4': return 0b01100110;
    case '5': return 0b10110110;
    case '6': return 0b10111110;
    case '7': return 0b11100000;
    case '8': return 0b11111110;
    case '9': return 0b11110110;

    case 'a':
    case 'A': return 0b11101110;
    case 'b':
    case 'B': return 0b00111110;
    case 'c': return 0b00011010;
    case 'C': return 0b10011100;
    case 'd':
    case 'D': return 0b01111010;
    case 'e':
    case 'E': return 0b10011110;
    case 'f':
    case 'F': return 0b10001110;
    case 'r': return 0b00001010;

    case '-': return 0b00000010;
    case '.': return 0b00000001;

    default: return 0b00000001;
  }
}

