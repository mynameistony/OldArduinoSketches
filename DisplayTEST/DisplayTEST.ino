#include <Display.h>

Display latch(5);
Display data(6);
Display clock(7);

Display digit1(8);
Display digit2(9);
Display digit3(10);
Display digit4(11);

int num1;
int num2;
int num3;
int num4;

int number[]={
  32, 55, 12, 6, 19, 66, 64, 39, 0, 2};

void setup(){}

void loop(){
  num1=3;
  num2=4;
  num3=5;
  num4=6;
  
  Display Show();
