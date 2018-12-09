#include <mbed.h>

// Outputs
DigitalOut red_led(PTA1);
DigitalOut green_led(PTA2);
// DigitalOut VDD(PTA4);
// BusOut Disp(PTC6);
unsigned int i;

// Intrupts
InterruptIn push_button1(PTD1);
InterruptIn push_button2(PTD2);
InterruptIn push_button3(PTD3);

bool but1_presed = false;
bool but2_presed = false;
bool but3_presed = false;

bool task3_running = false;
bool task4_running = false;
bool task5_running = false;


void delay(void) {
  // for(volatile unsigned int x=0;x<3500000;x=x+1);
  return;
}

void scheduler();

void task3(){
    task3_running = true;
    red_led = 1;
    green_led = 0; 
    wait(2);
    red_led = 0;
    green_led = 1; 
    wait(2);
    task3_running = false;
    scheduler();
}

void task4(){
  task4_running = true;
  green_led = 1; 
  red_led = 1;
  wait(2);
  green_led = 0; 
  red_led = 0;
  wait(2);
  task4_running = false;
  scheduler();
}

void task5(){
  task5_running = true;
  red_led=1;
  green_led = 0;
  wait(2);
  task5_running = false;
  scheduler();
}
// Intrrupt Service Routines
void isr1() {
    but1_presed = true; 
    // but2_presed = false;
    // but3_presed = false;
    // scheduler();
}
void isr2() {
    but2_presed = true; 
    // but1_presed = false;
    // but3_presed = false;
    // scheduler();
}
void isr3() {
    but3_presed = true; 
    // but2_presed = false;
    // but1_presed = false;
    // scheduler();
}

void scheduler() {
  if (but3_presed) {
        but3_presed = false;
        task5();
        red_led = 0;
        green_led = 0;
        wait(2);
  }else if (but2_presed) {
        but2_presed = false;
        task4();
        red_led = 0;
        green_led = 0;
        wait(2);
  }else if (but1_presed) {
        but1_presed = false;
        task3();
        red_led = 0;
        green_led = 0;
        wait(2);
  }
}

int main() {
  push_button1.rise(&isr1);
  push_button2.rise(&isr2);
  push_button3.rise(&isr3);
  while(1) {
    scheduler();
  }
}