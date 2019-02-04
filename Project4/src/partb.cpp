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

// Tasks
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
  int i = 0;
  while(i < 10) {
    display=0xBF;
    wait(0.1);
    i++;
    check_flags();
  }
  i = 0;
  while(i < 10) {
    display=0x86;
    wait(0.1);
    i++;
    check_flags();
  }
  i = 0;
  while(i < 10) {
    display=0xDB;
    wait(0.1);
    i++;
    check_flags();
  }
  i = 0;
 while(i < 10) {
    display=0xCF;
    wait(0.1);
    i++;
    check_flags();
  }
  i = 0;
 while(i < 10) {
    display=0xE6;
    wait(0.1);
    i++;
    check_flags();
  }
  i = 0;
  while(i < 10) {
    display=0xED;
    wait(0.1);
    i++;
    check_flags();
  }
  i = 0;
  while(i < 10) {
    display=0xFD;
    wait(0.1);
    i++;
    check_flags();
  }
  i = 0;
 while(i < 10) {
    display=0x87;
    wait(0.1);
    i++;
    check_flags();
  }
  i = 0;
while(i < 10) {
    display=0xFF;
    wait(0.1);
    i++;
    check_flags();
  }
  i = 0;
while(i < 10) {
    display=0xEF;
    wait(0.1);
    i++;
    check_flags();
  }
  i = 0;
    but3_pressed = false;
    // display=0xBF;
    scheduler();
}

void scheduler() {
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
