#include "mbed.h"
#include "rtos.h"
Serial pc(USBTX, USBRX);
Serial uart(PTE0, PTE1);
 
int coun = 1;
 
float timer1=0;
float timer4=0;

int new_in;
int old_in=1;

int new_in2;
int old_in2=1;
int avg_num;
int count=0;
float avg_time1;
float avg_time2;
float avg_time3;
float avg_time4=0;
Thread t1;
Thread t2;
Thread t3;
Thread t4;
Thread t5;
int f=0;
DigitalIn SW1(PTD1);
DigitalIn SW2(PTD2); 
float sum =0.0;
float T; // average temperature
int buffer[32];
int index2=0;
int index3=0;
int swap=0;
int test=0;
float average1=0.0;
float average2=0.0;
float average=0.0;
Timer program_time;
char arr[5];
float temp[48]= {20, 21, 22,23,24,25,26,27,20, 21, 22,23,24,25,26,27,20, 21, 
22,23,24,25,26,27,20, 21, 22,23,24,25,26,27,20, 21, 22,23,24,25,26,27,20, 21, 22,23,24,25,26,27};
char res[5];
void updateTime();
void updateAndDisplayTime();
void readTemperature();
void getAverage();
void call_thread3();
void convertTime(float time);

char getChar(int a){
    if (a==1){
        return '1';}
    else if(a==2){
        return '2';}
    else if(a==3){
        return '3';}
    else if(a==4){
        return '4';}
    else if(a==5){
        return '5';}
    else if(a==6){
        return '6';}
    else if(a==7){
        return '7';}
    else if(a==8){
        return '8';}
    else if(a==9){
        return '9';}
    else if(a==0){
        return '0';}
        
        return 'e';
    }

float getInt(char a){
    if (a=='1'){
        return 1.0;}
    else if(a=='2'){
        return 2.0;}
    else if(a=='3'){
        return 3.0;}
    else if(a=='4'){
        return 4.0;}
    else if(a=='5'){
        return 5.0;}
    else if(a=='6'){
        return 6.0;}
    else if(a=='7'){
        return 7.0;}
    else if(a=='8'){
        return 8.0;}
    else if(a=='9'){
        return 9.0;}
    else if(a=='0'){
        return 0.0;}
        
        return -1.0;
    }

int main() {
  int cnt=0;
  int i=4;
  int c=0;
        while(1) {
            
            
            
        wait(0.01);
        
//        if (f==1){
//            c++;
//            uart.putc(res[c]); 
//           if(c<5){
//            f=0;}
//            }
        
        t1.start(updateTime);
        if(uart.readable()) {
            
            char in;
            in=uart.getc();
            arr[i]=getInt(in);
            //pc.printf("arr: %d is",arr[i]);
            i--;
            cnt++;
            pc.putc(in);
            pc.printf("-");
            if(cnt%5==0){
                i=4;
            
                average2=arr[4]*10.0+arr[3]*1.0+arr[2]*0.1+arr[1]*0.01;
                pc.printf("num: %f",average2);
t3.start(getAverage);
}
}
        wait(0.1);
    }
    
   
     
    
}



void getAverage(){//task3



    
 
 
    if(index3<32 ){
         
        buffer[index3] = average2;
        sum+=average2;
        avg_num = index3;
        }
        
        else if(index3== 32){ 
        buffer[index3]=average2;   
   
        sum+=buffer[index3];
           avg_num=32.0;
        
        }
        else{
            sum=0.0;
            buffer[index3%32]=average2;
            
            for(int i=0;i<32;i++){
        sum+=buffer[i];
            avg_num=32.0;
            }
            }
            index3++;
            avg_time3 = program_time.read();
            
            average=sum/avg_num;
            pc.printf("ave: %f",average);
            int k= int(average*100);
            
            int i=0;
            while (k > 0 && i<4) {
            int digit = k % 10;
            res[i]=getChar(digit);
            i++;
            k /= 10;
            }
            f=1;
      //  uart.putc('a');
//        wait(0.01);
//        uart.putc(res[3]);
//        wait(0.01);
//        uart.putc(res[2]);
//
//        wait(0.01);
//        uart.putc(res[1]);
//
//        wait(0.01);
    }


void updateTime() { //task1


        
    

    avg_time1 = program_time.read();
    timer1+=0.1;
    count++;
    //printf("timer: %f \n",timer1);  updating but not showing
    if(count%10==0){  
//    if(uart.writeable())
//        {
           uart.putc('4');  
//        } 
        //t4.start(updateAndDisplayTime);
        }  
        if(count%50==0){
//            if(uart.writeable())
//        {
           uart.putc('2');  
//        } 
            //t2.start(readTemperature);
            }
}

