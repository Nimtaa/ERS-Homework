#include "mbed.h"

Serial pc(USBTX, USBRX); // tx, rx

char buffer[10];
PwmOut speaker(PTD3); 


AnalogIn LM35(PTD0);
float tempC;
float a[10];
float avg;

DigitalOut led(LED1);
DigitalOut outled2(PTA5);
DigitalOut vcc(PTC13);

// void play(){
//   int i;
// // generate a arbitrary frequency tone using PWM hardware output
//     speaker.period(1.0/329.628);
//     speaker =0.3; //30% duty cycle - %50 is  max volume
//     wait(0.625);
//     // speaker=0.0; // turn off audio
//     speaker.period(1.0/415.305);
//     speaker = 0.3;
//     wait(0.625);
//     speaker = 0.0;
//     wait(0.1);
//     speaker.period(1.0/415.305);
//     speaker = 0.3;
//     wait(0.625);
//     speaker = 0.0;
//     wait(0.1);
//     speaker.period(1.0/415.305);
//     speaker = 0.3;
//     wait(0.625);
//     speaker = 0.0;
//     wait(0.1);
//     speaker.period(1.0/369.994);
//     speaker = 0.5;
//     wait(0.31);
   

//     speaker.period(1.0/329.628);
//     speaker = 0.5;
//     wait(0.31);


//     speaker.period(1.0/493.883);
//     speaker = 0.5;
//     wait(0.93);
//     speaker = 0.0;
//     wait(0.1);

//     speaker.period(1.0/493.883);
//     speaker = 0.5;
//     wait(0.31);
//     speaker = 0.0;
//     wait(0.1);

//     speaker.period(1.0/440);
//     speaker = 0.5;
//     wait(0.31);
//     speaker = 0.0;
//     wait(0.1);

//     speaker.period(1.0/415.305);
//     speaker = 0.5;
//     wait(0.625);
//     speaker = 0.0;
//     wait(0.1);

//     speaker.period(1.0/415.305);
//     speaker = 0.5;
//     wait(0.625);
//     speaker = 0.0;
//     wait(0.1);

//     speaker.period(1.0/415.305);
//     speaker = 0.5;
//     wait(0.625);
//     speaker = 0.0;
//     wait(0.1);

//     speaker.period(1.0/369.994);
//     speaker = 0.5;
//     wait(0.31);
 
//     speaker.period(1.0/329.628);
//     speaker = 0.5;
//     wait(0.31);

//     speaker.period(1.0/493.883);
//     speaker = 0.5;
//     wait(0.93);
//     speaker = 0.0;
//     wait(0.1);

//     speaker.period(1.0/493.883);
//     speaker = 0.5;
//     wait(0.31);
//     speaker = 0.0;
//     wait(0.1);

//     speaker.period(1.0/440);
//     speaker = 0.5;
//     wait(0.31);
//     speaker = 0.0;
//     wait(0.1);

// // 1/8 : 0.625
// // 1/16 : 0.31
// // 3/16 : 0.93
//     speaker.period(1.0/415.305);
//     speaker = 0.5;
//     wait(0.625);
//     speaker = 0.0;
//     wait(0.1);
    
//     speaker.period(1.0/440);
//     speaker = 0.5;
//     wait(0.31);
//     speaker = 0.0;
//     wait(0.1);

//     speaker.period(1.0/493.883);
//     speaker = 0.5;
//     wait(0.31);
//     speaker = 0.0;
//     wait(0.1);

//     speaker.period(1.0/440);
//     speaker = 0.5;
//     wait(0.625);
//     speaker = 0.0;
//     wait(0.1);

//     speaker.period(1.0/415.305);
//     speaker = 0.5;
//     wait(0.625);
//     speaker = 0.0;
//     wait(0.1);

//     speaker.period(1.0/369.994);
//     speaker = 0.5;
//     wait(0.625);
//     speaker = 0.0;
//     wait(0.1);

//     speaker.period(1.0/311.127);
//     speaker = 0.5;
//     wait(0.625);
//     speaker = 0.0;
//     wait(0.1);


//     speaker.period(1.0/493.883);
//     speaker = 0.5;
//     wait(0.625);
//     speaker = 0.0;
//     wait(0.1);


//     speaker.period(1.0/329.628);
//     speaker = 0.5;
//     wait(0.625);
//     speaker = 0.0;
//     wait(0.1);
// }

void print_temp(){
  for(int i=0;i<10;i++)
{
  a[i]=LM35.read();
  wait(.02);
 }
 for(int i=0;i<10;i++)
 {
  avg=avg+(a[i]/10);
 }

 tempC=(avg*3.685503686*100);
 pc.printf("%.2f",tempC);
}



int main() {   

  vcc = 1;
    while(1) {
        pc.printf("Enter your command\n");
        pc.gets(buffer,5);
        if(buffer[1]=='e') {//temp
          pc.printf("temp\n");
          print_temp();
        }
        if(buffer[1]=='l') {//temp
          pc.printf("play\n");
        }
         if(buffer[1]=='n') {//temp
          pc.printf("on\n");
        }
         if(buffer[1]=='f') {//temp
          pc.printf("off\n");
        }
    }
}
