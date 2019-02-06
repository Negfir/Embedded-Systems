#include "mbed.h"

DigitalOut LedOut(PTD2);
DigitalIn SwitchIn(PTE4);

int period=120;
int LightOn=0;
int cnt=0;
int Led1;
int s=1;

int pres;
int prev=1;

int main(){
    while(1){
        pres = SwitchIn;
        if(cnt <= LightOn){
            cnt++;
            Led1=1;
            }
        else if(cnt> LightOn && cnt <= period){
            cnt ++;
            Led1=0;
            }
        else if( cnt >period){   
                cnt=0;
        }
                
        if(pres==1 && prev == 0 && LightOn<110 && s==1) {
            
            LightOn+=20;
            if (LightOn>100){
                s=0;}
                }
        
        if(pres==1 && prev == 0 && s==0){
            LightOn-=20;
            if (LightOn<0){
                s=1;}
        }
        LedOut=Led1;
        prev=pres;
    }
}