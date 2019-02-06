#include "mbed.h"
#include "time.h"


PwmOut buzzer(PTD2);
Serial pc(USBTX, USBRX); // tx, rx
DigitalOut led(PTD5);
AnalogIn tmp(PTE30);
InterruptIn button1(PTD0);
InterruptIn button2(PTA5);
DigitalOut led1(LED1);
//DigitalIn tmp(PTD7);
int i=0;
void flip1() {
    i=100;
    led1 = !led1;
    pc.printf("User interrupt 1 has been received.");
    wait(5);
}
void flip2() {
    led1 = !led1;
    pc.printf("User interrupt 2 has been received.");
    wait(5);
}

int main() {
    button1.rise(&flip1);
    button2.rise(&flip2);
    NVIC_SetPriority(PORTA_IRQn, 2);
    NVIC_SetPriority(PORTD_IRQn, 0);      //set interupt to highest priority 0.
    float tempC,avg;
    pc.printf("-$-> Enter your command:\n");
    char c [5];
    while(1){
     if(pc.readable()){
    pc.printf("Entry:");
    pc.puts( pc.gets(c , 5));
    pc.printf("i got '%s'\n",c);
    
    if(strcmp(c,"on  ")==0){
    led = 1;
    pc.printf("is on\n");
}
else if(strcmp(c,"off ")==0){
    led = 0;
    pc.printf("is off\n");
    }
    
else if(strcmp(c,"play")==0){
    pc.printf("is playing...\n"); 
    wait(0.6);
   
   
    //F3
    buzzer.period(1.0/174.61);
    buzzer =0.05;
    wait(0.125);
    buzzer=0.0;
    wait(0.15);

    //F3
    buzzer.period(1.0/174.61);
    buzzer =0.05;
    wait(0.125);
    buzzer=0.0;
    wait(0.15);

    //F3
    buzzer.period(1.0/174.61);
    buzzer =0.05;
    wait(0.125);
    buzzer=0.0;
    wait(0.15);
   
   
    //C3 
    buzzer.period(1.0/130.81);
    buzzer =0.05;
    wait(0.125);
    buzzer=0.0;
    wait(0.15);
    
    //F3
    buzzer.period(1.0/174.61);
    buzzer =0.05;
    wait(0.25);
    buzzer=0.0;
    wait(0.15);

    //F3
    buzzer.period(1.0/174.61);
    buzzer =0.05;
    wait(0.125);
    buzzer=0.0;
    wait(0.15);

    //C3 
    buzzer.period(1.0/130.81);
    buzzer =0.05;
    wait(0.125);
    buzzer=0.0;
    wait(0.15);
    // end first time
   
     //F3
    buzzer.period(1.0/174.61);
    buzzer =0.05;
    wait(0.125);
    buzzer=0.0;
    wait(0.15);

    //F3
    buzzer.period(1.0/174.61);
    buzzer =0.05;
    wait(0.125);
    buzzer=0.0;
    wait(0.15);

    //Bb2
    buzzer.period(1.0/116.54);
    buzzer =0.05;    
    wait(0.125);
    buzzer=0.0;
    wait(0.15);
     
    //B2
    buzzer.period(1.0/123.47);
    buzzer =0.05;
    wait(0.125);
    buzzer=0.0;
    wait(0.15);

    //C3
    buzzer.period(1.0/130.81);
    buzzer =0.05;
    wait(0.25);
    buzzer=0.0;
    wait(0.15);
    
    wait(0.25);
    
    //end second time

    //F3
    buzzer.period(1.0/174.61);
    buzzer =0.05;
    wait(0.125);
    buzzer=0.0;
    wait(0.15);


    //F3
    buzzer.period(1.0/174.61);
    buzzer =0.05;
    wait(0.125);
    buzzer=0.0;
    wait(0.15);


    //F3
    buzzer.period(1.0/174.61);
    buzzer =0.05;
    wait(0.125);
    buzzer=0.0;
    wait(0.15);

    //C3
    buzzer.period(1.0/130.81);
    buzzer =0.05;
    wait(0.125);
    buzzer=0.0;
    wait(0.15);


    //F3
    buzzer.period(1.0/174.61);
    buzzer =0.05;
    wait(0.25);
    buzzer=0.0;
    wait(0.15);


    //F3
    buzzer.period(1.0/174.61);
    buzzer =0.05;
    wait(0.125);
    buzzer=0.0;
    wait(0.15);


    //C3
    buzzer.period(1.0/130.81);
    buzzer =0.05;
    wait(0.125);
    buzzer=0.0;
    wait(0.15);
    
    }    
else if(strcmp(c,"temp")==0){

avg=tmp.read();
 


 tempC=(avg*3.2*100);

 pc.printf("  Temperature   ");

pc.printf("%.2f C",tempC);
 
 }  
}
}
}