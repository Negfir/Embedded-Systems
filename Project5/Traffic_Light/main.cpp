#include "mbed.h"

DigitalOut myled(LED1);
DigitalOut GN(PTA1);
DigitalOut AN(PTA2);
DigitalOut RN(PTD4);
DigitalOut GNE(PTA12);
DigitalOut ANE(PTA4);
DigitalOut RNE(PTA5);
DigitalOut GBRT(PTC8);
DigitalOut ABRT(PTC9);
DigitalOut RBRT(PTC11);
DigitalOut GE(PTC10);
DigitalOut AE(PTC6);
DigitalOut RE(PTC5);

DigitalOut GPNS(PTC12);
DigitalOut RPNS(PTC13);
DigitalOut GPE(PTC16);
DigitalOut RPE(PTC17);
DigitalOut GPW(PTA16);
DigitalOut RPW(PTA17);
InterruptIn button(PTD5);

int a;
int i1=0;
int i2=0;
int i3=0;
int i4=0;
int i5=0;


enum State { 
  GreenN1,
  GreenN2,
  WaitN,
  GreenE,
  WaitE,
  GreenNE,
  WaitNE,
  EMWait,
  Emergency 
}state = GreenN1;
int EM=0;

void EMG() {
 EM=1;
}

int main() {
    myled=1;
    __enable_irq();
    button.rise(&EMG);
    while(1) {
  enum State next_state = state;
  switch (state)
  {
    
    case GreenN1:
    i5=0;
    a=1;
    if(EM==1){
        EM=0;
        next_state=EMWait;
        }
    else{ 
    
        GN=1;
        AN=0;
        RN=0;
        GE=0;
        AE=0;
        RE=1;
        GNE=0;
        ANE=0;
        RNE=1;
        GBRT=1;
        ABRT=0;
        RBRT=0;
        GPNS=0;
        RPNS=1;
        GPE=1;
        RPE=0;
        GPW=1;
        RPW=0;
        
        next_state=GreenN2;
        while(i1<4){
            wait(0.5);
            i1++;
            if(EM==1){
                EM=0;
                next_state=EMWait;
                break;
        }
        
        }
        
        }
      
      break;
    
    case GreenN2:
    i1=0;
    a=2;
    if(EM==1){
        EM=0;
        next_state=EMWait;
        }
    else{ 
    
        GN=1;
        AN=0;
        RN=0;
        GE=0;
        AE=0;
        RE=1;
        GNE=1;
        ANE=0;
        RNE=0;
        GBRT=0;
        ABRT=0;
        RBRT=1;
        GPNS=0;
        RPNS=1;
        GPE=0;
        RPE=1;
        GPW=1;
        RPW=0;
        next_state=WaitN;
       while(i2<4){
            wait(0.5);
            i2++;
            if(EM==1){
                EM=0;
                next_state=EMWait;
                break;
        }
        }
        
        }
    
      break;  
      
    case WaitN:
    i2=0;
    a=3;
    if(EM==1){
        EM=0;
        next_state=EMWait;
        }
    else{ 
        GN=0;
        AN=1;
        RN=0;
        GE=0;
        AE=1;
        RE=0;
        GNE=0;
        ANE=1;
        RNE=0;
        GBRT=0;
        ABRT=0;
        RBRT=1;
        
        GPNS=0;
        RPNS=1;
        GPE=0;
        RPE=1;
        GPW=0;
        RPW=1;
        
        next_state=GreenE;
        while( i3<4){
            wait(0.5);
            i3++;
            if(EM==1){
                EM=0;
                next_state=EMWait;
                break;
        }
        }
        }
      
      break;
    case GreenE:
    i3=0;
    a=4;
    if(EM==1){
        EM=0;
        next_state=EMWait;
        }
    else{ 
        GN=0;
        AN=0;
        RN=1;
        GE=1;
        AE=0;
        RE=0;
        GNE=0;
        ANE=0;
        RNE=1;
        GBRT=0;
        ABRT=0;
        RBRT=1;
        GPNS=1;
        RPNS=0;
        GPE=0;
        RPE=1;
        GPW=0;
        RPW=1;
        
        next_state=WaitE;
        while( i4<8){
            wait(0.5);
            i4++;
            if(EM==1){
                EM=0;
                next_state=EMWait;
                break;
        }
        }}
        
      break;
    case WaitE:
    i4=0;
    a=5;
    if(EM==1){
        EM=0;
        next_state=EMWait;
        }
    else{ 
        GN=0;
        AN=1;
        RN=0;
        GE=0;
        AE=1;
        RE=0;
        GNE=0;
        ANE=0;
        RNE=1;
        GBRT=0;
        ABRT=1;
        RBRT=0;
        GPNS=0;
        RPNS=1;
        GPE=0;
        RPE=1;
        GPW=0;
        RPW=1;
        
        next_state=GreenN1;
       while( i4<4){
            wait(0.5);
            i4++;
            if(EM==1){
                EM=0;
                next_state=EMWait;
                break;
        }
        }}
       
      break;
    
  
  
    case EMWait:
        if(a==1){
            GN=0;
            AN=1;
            GBRT=0;
            ABRT=1;
            
            }
        else if(a==2){
            GN=0;
            AN=1;
            GNE=0;
            ANE=1;
            }
        else if(a==4){
            GE=0;
            AE=1;
            }
            wait(2);
        next_state=Emergency;
      break;
  
  
    case Emergency:
    myled=0;
        GN=0;
        AN=0;
        RN=1;
        GE=0;
        AE=0;
        RE=1;
        GNE=0;
        ANE=0;
        RNE=1;
        GBRT=0;
        ABRT=0;
        RBRT=1;
        wait(3);
        if(a==1){
            
            next_state=GreenN1;
            }
        else if(a==3){
            
            next_state=WaitN;
            }
        else if(a==4){
            next_state=GreenE;
            }
        else if(a==5){
            next_state=WaitE;
            }
        else if(a==2){
            next_state=GreenN1;
            }

            
        myled=1;
        
      break;
  }    
  state = next_state;
    }
}
