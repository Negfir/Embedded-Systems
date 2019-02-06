#include "mbed.h"

DigitalOut redled(PTA13);
DigitalOut greenled(PTD5);
DigitalOut g(PTA1);
DigitalOut f(PTA2);
DigitalOut a(PTD4);
DigitalOut b(PTA12);
DigitalOut e(PTA4);
DigitalOut d(PTA5);
DigitalOut c(PTC8);
InterruptIn button1(PTD1);
InterruptIn button2(PTD2);
InterruptIn button3(PTD3);
DigitalOut led1(LED1);
int flag1 =1;
int flag2 =1;
int flag3 =0;
int flag4 =0;
int flag5 =0;
void Task1(){
    redled =1;
    wait(2);
    redled =0;
    wait(2);
}
void Task2() {
    greenled=1;
    wait(2);
    greenled=0;
    wait(2);
}
void Task3() {
    flag3 = 1;
    
}
void Task4() {
    flag4 =1;
}
void Task5() {
    flag5 =1;
}

int main() {

    __enable_irq();
    button1.rise(&Task3);
    button2.rise(&Task4);
    button3.rise(&Task5);
    
    while(1) {
    if(flag5==1){
      //show 0
      
      a=0;
      b=0;
      c=0;
      d=0;
      e=0;
      f=0;
      g=1; 
      wait(1);
      //show 1
    a=1;
      b=0;
      c=0;
      d=1;
      e=1;
      f=1;
      g=1; 
      wait(1);
      //show 2
    a=0;
      b=0;
      c=1;
      d=0;
      e=0;
      f=1;
      g=0;
      wait(1);
      //show3
    a=0;
      b=0;
      c=0;
      d=0;
      e=1;
      f=1;
      g=0;
      wait(1);
      //show4
      a=1;
      b=0;
      c=0;
      d=1;
      e=1;
      f=0;
      g=0;
      wait(1);
      //show5
      a=0;
      b=1;
      c=0;
      d=0;
      e=1;
      f=0;
      g=0;
      wait(1);
      //show6
    a=0;
      b=1;
      c=0;
      d=0;
      e=0;
      f=0;
      g=0;
      wait(1);
      //show7
        a=0;
      b=0;
      c=0;
      d=1;
      e=1;
      f=1;
      g=1;
      wait(1);
      //show 8    
      a=0;
      b=0;
      c=0;
      d=0;
      e=0;
      f=0;
      g=0;
      wait(1);
      //show 9
        a=0;
      b=0;
      c=0;
      d=0;
      e=1;
      f=0;
      g=0;
      wait(1);
      if(flag3==1 | flag4==1){
      flag5=0;}
    }
    else if(flag4==1 && flag5==0){
    greenled=1;
    redled =1;
    wait(2);
    greenled=0;
    redled =0;
    wait(2);
        greenled=1;
    redled =1;
    wait(2);
    greenled=0;
    redled =0;
    wait(2);
    greenled=1;
    redled =1;
    wait(2);
    greenled=0;
    redled =0;
    wait(2);
    greenled=1;
    redled =1;
    wait(2);
    greenled=0;
    redled =0;
    wait(2);
    greenled=1;
    redled =1;
    wait(2);
    greenled=0;
    redled =0;
    wait(2);
    flag4 = 0;
        }
        else if(flag3==1 && flag4==0 && flag5 ==0){
        Task1();
        Task2();
        Task1();
        Task2();
        Task1();
        Task2();
        Task1();
        Task2();
        Task1();
        Task2();  
        flag3 = 0;   
}
}}
