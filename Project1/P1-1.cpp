#include "mbed.h"

PwmOut led(PTD2);
DigitalIn Switch1(PTD3);

int main() {
    led.period(0.01);
    led=0.0;
    float val=0.0;
    int cnt=0;
    while(1) {
        if(Switch1==0){
            //wait(1);
            if(cnt==11){
                cnt=0;}
            cnt=cnt+1;
            if(cnt==1){
                val=0.2;
                wait(0.5);
                }
            else if(cnt==2){
                val=0.4;
                wait(0.5);
                }
            else if(cnt==3){
                val=0.6;
                wait(0.5);}
                
            else if(cnt==4){
                val=0.8;
                wait(0.5);}
                
            else if(cnt==5){
                val=1.0;
                wait(0.5);}
                
            else if(cnt==6){
                val=0.8;
                wait(0.5);} 
                
            else if(cnt==7){
                val=0.6;
                wait(0.5);
                }
            else if(cnt==8){
                val=0.4;
                wait(0.5);}
                
            else if(cnt==9){
                val=0.2;
                wait(0.5);}
                
            else if(cnt==10){
                val=0.0;
                wait(0.5);}
                
            led=val; 

                   
            
        

     }       

    }
}
