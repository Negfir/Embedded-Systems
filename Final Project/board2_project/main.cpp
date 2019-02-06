#include "mbed.h"
#include "rtos.h"
#include "Temp.h"
#include "TextLCD.h"
Serial pc(USBTX, USBRX);
Serial uart(PTE0, PTE1);
TextLCD lcd(PTB8,PTB9,PTB10,PTB11,PTE2,PTE3,TextLCD::LCD16x2);
 
int coun = 1;
 
float timer1=0;
float timer4=0;

int new_in;
int old_in=1;

int new_in2;
int old_in2=1;

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

DigitalIn SW1(PTD1);
DigitalIn SW2(PTD2); 

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
char arr[4];
//float temp[48]= {20, 21, 22,23,24,25,26,27,20, 21, 22,23,24,25,26,27,20, 21, 
//22,23,24,25,26,27,20, 21, 22,23,24,25,26,27,20, 21, 22,23,24,25,26,27,20, 21, 22,23,24,25,26,27};
char res[5]={0, 0, 0,0,0};
void updateTime();
void updateAndDisplayTime();
void readTemperature();
void getAverage();

char getChar(int a);
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

int getInt(char a){
    if (a=='1'){
        return 1;}
    else if(a=='2'){
        return 2;}
    else if(a=='3'){
        return 3;}
    else if(a=='4'){
        return 4;}
    else if(a=='5'){
        return 5;}
    else if(a=='6'){
        return 6;}
    else if(a=='7'){
        return 7;}
    else if(a=='8'){
        return 8;}
    else if(a=='9'){
        return 9;}
    else if(a=='0'){
        return 0;}
        
        return -1;
    }

 void updateAndDisplayTime(){ //task4
 //pc.printf("I'm in task4");
 avg_time4++;
    //avg_time4 = program_time.read();
    //pc.printf("Time is %4.2f \r\n",avg_time4);
    pc.printf("time is: ");
         convertTime(avg_time4);



    new_in = SW1;
    if(new_in==0){
        pc.printf("Temperature (in Celsius) is %4.2f \r\n",average2);
        lcd.printf("Temperature (in Celsius) is %4.2f \r\n",average2);
          pc.printf("time is: ");
         convertTime(avg_time2);
        }
    
    
    new_in2 = SW2;
    if(new_in2==0 ){
        pc.printf("Average Temperature (in Celsius) is %4.2f \r\n",average);
        lcd.printf("Average Temperature (in Celsius) is %4.2f \r\n",average);
        
        }
    
    
}
void readTemperature(){ //task2
//avg_time2 = program_time.read();
pc.printf("I'm in task2");
avg_time2+=5;
        
        if(index2==48){
        index2=0;
        
        }
        average2 = temp[index2];
        index2++;
        //uart.putc('c');  
        //printf("Temperature (in Celsius) is %4.2f \r\n",T); 
   
        int k= int(average2*1000);
        
        int i=0;
        while (k > 0 && i<5) {
        int digit = k % 10;
        res[i]=getChar(digit);
         i++;
        k /= 10;
}
       //wait(0.01);    
//        
//        uart.putc('p');
        //wait(0.01);
        
//        uart.putc('o');
//           wait(0.01);
//        uart.putc('i');
//           wait(0.01);
//        uart.putc('h');
//   wait(0.01);   
       
        
//        char * b = (char *) &average2;
//        uart.putc(b[0]);
//        pc.printf("%c",b[0]);
//      uart.putc(b[1]);
//      pc.printf("%c",b[1]);
//      uart.putc(b[2]);
//      pc.printf("%c",b[2]);
//      uart.putc(b[3]);
//      pc.printf("%c",b[3]);
        
        
        //t3.start(getAverage);
       
}

void convertTime(float time)
{
    time_t sec = time;
    // setup time structure for Wed, 28 Oct 2009 11:35:37
    struct tm *t;
    t = localtime(&sec);
    // convert to timestamp and display (1256729737)
    time_t seconds = mktime(t);
    //pc.printf("Time as seconds since January 1, 1970 = %d\n", seconds);
     pc.printf("%s\r\n", ctime(&seconds));
     lcd.printf("%s\r\n", ctime(&seconds));
}

int main() {
        int i=4;
        while(1) {

        if(uart.readable()) {
            char in = uart.getc();
            if(in=='4'){
 //               char num = uart.getc();
//                pc.putc(num);
//                pc.printf("ggggg");
                pc.printf("I'm in 4");
                uart.putc(res[i]); 
                wait(0.01);
                i--;
            t4.start(updateAndDisplayTime);}
            if(in=='2'){
               i=4;
                pc.printf("I'm in 2");  
            t2.start(readTemperature);
            
            }
            pc.printf("\n");
            //pc.putc(in);
          //  if(in=='f'){
                //pc.printf("I'm in aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
                //for(int i=4; i>0; i--){
                
                  //arr[i-1]= getInt(num);
                 
              
            
            //wait(0.01);
            //}
            //average=arr[2]*10+arr[1]+arr[0]*0.1;
          //  }
        }
    }
}
