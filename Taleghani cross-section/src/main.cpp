#include <mbed.h>

// System Outputs
DigitalOut N_S_Green(PTC1);
DigitalOut N_S_Red(PTC1);
DigitalOut N_S_Yellow(PTC1);

DigitalOut W_E_Green(PTC1);
DigitalOut W_E_Red(PTC1);
DigitalOut W_E_Yellow(PTC1);

DigitalOut Turn_Green(PTC1);
DigitalOut Turn_Red(PTC1);
DigitalOut Turn_Yellow(PTC1);

DigitalOut BUS_Green(PTC1);
DigitalOut BUS_Red(PTC1);
DigitalOut BUS_Yellow(PTC1);


// System Inputs
InterruptIn button1(PTD1);

DigitalIn push_button1(PTD1);
DigitalIn push_button2(PTD2);
DigitalIn push_button3(PTD3);



//States
#define N_S_STATE_Wait 0;
#define N_S_STATE_Go 1;
#define W_E_STATE_Wait 2 ;
#define W_E_STATE_Go 3 ;
#define Emergency_STATE  4;
#define TURN_STATE_Go  5;
#define TURN_STATE_Wait  6;
#define BUS_STATE_Go 7;
#define BUS_STATE_Wait 8;

//Global Variables
int curr_state;
int transition[9]={
      
  };



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




void N_S_STATE_Go_task(){

}
void N_S_STATE_Wait_task(){

}
void W_E_STATE_Go_task(){

}
void W_E_STATE_Wait_task(){

}
void TURN_STATE_Go_task(){

}
void TURN_STATE_Wait_task(){

}
void BUS_STATE_Go_task(){

}
void BUS_STATE_Wait_task(){

}
void Emergency_STATE_task(){
  switch (curr_state) {
    
    case W_E_STATE_Wait:
    
    case N_S_STATE_Wait:
  }
}

void state_machine() {
    
  curr_state = transition[(curr_state+1) % 9];
  
  switch (curr_state){
    case N_S_STATE_Wait:
    case N_S_STATE_Go:
    case W_E_STATE_Wait:
    case W_E_STATE_Go:
    case Emergency_STATE:
    case TURN_STATE_Go:
    case TURN_STATE_Wait:
    case BUS_STATE_Go:
    case BUS_STATE_Wait:

  }

}

int main() {
  button1.rise(&Emergency_STATE_task);
  while(1) {
    state_machine();
  }
}
