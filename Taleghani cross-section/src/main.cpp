#include <mbed.h>

// System Outputs
DigitalOut red_led(PTC1);
DigitalOut green_led(PTC2);
BusOut display(PTE5,PTE4,PTE3,PTE2,PTB11,PTB10,PTB9,PTB8);

// System Inputs
DigitalIn push_button1(PTD1);
DigitalIn push_button2(PTD2);
DigitalIn push_button3(PTD3);

// Button Flags
bool but1_pressed = false;
bool but2_pressed = false;
bool but3_pressed = false;

//States
#define N_S_STATE_Wait = 0;
#define N_S_STATE_Go = 1;
#define  W_E_STATE_Wait = 2;
#define W_E_STATE_Go = 3;
#define Emergency_STATE = 4;
#define TURN_STATE_Go = 5;
#define TURN_STATE_Wait = 6;


// Task Counters
int task3_counter = 0;
int task4_counter = 0;

void scheduler();
void check_flags() {
    if(push_button1 == 0) {
      but1_pressed = true;
    }
    if(push_button2 == 0) {
      but2_pressed = true;
    }
    if(push_button3 == 0) {
      but3_pressed = true;
    }
}

// States
void task3(){
  if(task3_counter >= 10) {
    task3_counter = 0;
    red_led = 0;
    green_led = 0;
    but1_pressed = false;
    scheduler();
    return;
  }
  if(task3_counter <= 5) {
    red_led = 1;
    green_led = 0;
    wait(0.2);
  } else {
    red_led = 0;
    green_led = 1; 
    wait(0.2);
  }
  task3_counter++;
  scheduler();
}

void task4(){
  if(task4_counter >= 10) {
    task4_counter = 0;
    green_led = 0;
    red_led = 0;
    but2_pressed = false;
    scheduler();
    return;
  }
  green_led = 1;
  red_led = 1;
  wait(0.2);
  task4_counter++;
  scheduler();
}

void task5(){
    scheduler();
}

void scheduler() {
  
  curr_state = 

  check_flags();
  if (but3_pressed) {
    red_led = 0;
    green_led = 0;
    task5();
  } else if (but2_pressed) {
    task4();
  } else if (but1_pressed) {
    task3();
  }
}

int main() {
  while(1) {
    scheduler();
  }
}
