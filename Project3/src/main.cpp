#include "mbed.h"

Serial pc(USBTX, USBRX); // tx, rx

char buffer[10];
PwmOut speaker(PTD3); 
bool b1=false, b2=false;
Timer t;
float t1,t2;

bool print1= false,print2 = false;
AnalogIn LM35(PTD0);
float tempC;
float a[10];
float avg;
InterruptIn button1(PTA4);
InterruptIn button2(PTD1);

DigitalOut led(LED1);

DigitalOut outled2(PTA5);
DigitalOut vcc(PTC13);

void play(){
  int i;
// generate a arbitrary frequency tone using PWM hardware output
    speaker.period(1.0/329.628);
    speaker =0.3; //30% duty cycle - %50 is  max volume
    wait(0.625);
    // speaker=0.0; // turn off audio
    speaker.period(1.0/415.305);
    speaker = 0.3;
    wait(0.625);
    speaker = 0.0;
    wait(0.1);
    speaker.period(1.0/415.305);
    speaker = 0.3;
    wait(0.625);
    speaker = 0.0;
    wait(0.1);
    speaker.period(1.0/415.305);
    speaker = 0.3;
    wait(0.625);
    speaker = 0.0;
    wait(0.1);
    speaker.period(1.0/369.994);
    speaker = 0.5;
    wait(0.31);
   

    speaker.period(1.0/329.628);
    speaker = 0.5;
    wait(0.31);


    speaker.period(1.0/493.883);
    speaker = 0.5;
    wait(0.93);
    speaker = 0.0;
    wait(0.1);

    speaker.period(1.0/493.883);
    speaker = 0.5;
    wait(0.31);
    speaker = 0.0;
    wait(0.1);

    speaker.period(1.0/440);
    speaker = 0.5;
    wait(0.31);
    speaker = 0.0;
    wait(0.1);

    speaker.period(1.0/415.305);
    speaker = 0.5;
    wait(0.625);
    speaker = 0.0;
    wait(0.1);

    speaker.period(1.0/415.305);
    speaker = 0.5;
    wait(0.625);
    speaker = 0.0;
    wait(0.1);

    speaker.period(1.0/415.305);
    speaker = 0.5;
    wait(0.625);
    speaker = 0.0;
    wait(0.1);

    speaker.period(1.0/369.994);
    speaker = 0.5;
    wait(0.31);
 
    speaker.period(1.0/329.628);
    speaker = 0.5;
    wait(0.31);

    speaker.period(1.0/493.883);
    speaker = 0.5;
    wait(0.93);
    speaker = 0.0;
    wait(0.1);

    speaker.period(1.0/493.883);
    speaker = 0.5;
    wait(0.31);
    speaker = 0.0;
    wait(0.1);

    speaker.period(1.0/440);
    speaker = 0.5;
    wait(0.31);
    speaker = 0.0;
    wait(0.1);

// 1/8 : 0.625
// 1/16 : 0.31
// 3/16 : 0.93
    speaker.period(1.0/415.305);
    speaker = 0.5;
    wait(0.625);
    speaker = 0.0;
    wait(0.1);
    
    speaker.period(1.0/440);
    speaker = 0.5;
    wait(0.31);
    speaker = 0.0;
    wait(0.1);

    speaker.period(1.0/493.883);
    speaker = 0.5;
    wait(0.31);
    speaker = 0.0;
    wait(0.1);

    speaker.period(1.0/440);
    speaker = 0.5;
    wait(0.625);
    speaker = 0.0;
    wait(0.1);

    speaker.period(1.0/415.305);
    speaker = 0.5;
    wait(0.625);
    speaker = 0.0;
    wait(0.1);

    speaker.period(1.0/369.994);
    speaker = 0.5;
    wait(0.625);
    speaker = 0.0;
    wait(0.1);

    speaker.period(1.0/311.127);
    speaker = 0.5;
    wait(0.625);
    speaker = 0.0;
    wait(0.1);


    speaker.period(1.0/493.883);
    speaker = 0.5;
    wait(0.625);
    speaker = 0.0;
    wait(0.1);


    speaker.period(1.0/329.628);
    speaker = 0.5;
    wait(0.625);
    speaker = 0.0;
    wait(0.1);
}

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

void button1_pushed() {
    if(b2){
      return;
    }
    t1 = 0;
    b1 = true;
    led = 0;
    t.reset();
    t.start();
    pc.printf("interrupt 1 received\n");
    // while(t.read() < 6 );
}
void button2_pushed() {
    if(b1){
      b1 = false;
    }
    b2 = true;
    t1=0;
    t.reset();
    t.start();
    led = 0;
    pc.printf("interrupt 2 received\n");
    // while(t.read() < 6 );
}

int main() {   
//   t.reset();  
  vcc = 1;
  NVIC_SetPriority(PORTA_IRQn, 1);
  NVIC_SetPriority(PORTD_IRQn, 0);
  led = 1;
  button1.rise(&button1_pushed);
  button2.rise(&button2_pushed);   
    while(1) {
          if(b1 || b2){
          if(t.read() > 5){
            led = 1;
            b1 = false;
            b2 = false;
            t.stop();
            t.reset();
            }
          }
    }
}
