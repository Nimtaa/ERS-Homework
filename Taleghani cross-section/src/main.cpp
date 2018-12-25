#include <mbed.h>

// System Outputs

DigitalOut N_S_Green(PTC7);
DigitalOut N_S_Red(PTC0);
// DigitalOut N_S_Yellow(PTC1);

DigitalOut W_E_Green(PTC5);
DigitalOut W_E_Red(PTC6);
// DigitalOut W_E_Yellow(PTC1);

DigitalOut Turn_Green(PTC3);
DigitalOut Turn_Red(PTC4);
// DigitalOut Turn_Yellow(PTC1);

DigitalOut BUS_Green(PTC10);
DigitalOut BUS_Red(PTC11);
// DigitalOut BUS_Yellow(PTC1);


// System Inputs
InterruptIn button1(PTD1);

//States
const int N_S_STATE_Go = 0;
const int N_S_STATE_Wait = 1;
const int W_E_STATE_Go = 2;
const int W_E_STATE_Wait = 3;


//Global Variables
bool Emergency_pushed = false;
int curr_state = 0;
void state_machine();

void N_S_STATE_Go_task(){
  
    if(Emergency_pushed){
      N_S_Green = 0;
      N_S_Red = 1;
      W_E_Green =0;
      W_E_Red = 1;
      Turn_Red = 1;
      Turn_Green = 0;
      BUS_Green =0 ;
      BUS_Red = 1;
      wait(3);
      Emergency_pushed = false;
    }else{
    N_S_Green = 1;
    N_S_Red = 0;
    W_E_Green =0 ;
    W_E_Red = 1;
    Turn_Green = 0;
    Turn_Red = 1;
    BUS_Green = 1;
    BUS_Red = 0;
    wait(2);
    N_S_Green = 1;
    N_S_Red = 0;
    W_E_Green =0 ;
    W_E_Red = 1;
    Turn_Green = 1;
    Turn_Red = 0;
    BUS_Red = 1;
    BUS_Green = 0;
    wait(2);
    }
  }
void N_S_STATE_Wait_task(){
    N_S_Green = 1;
    N_S_Red = 1;
    W_E_Green =0;
    W_E_Red = 1;
    Turn_Red = 1;
    Turn_Green = 0;
    BUS_Green =0 ;
    BUS_Red = 1;
    wait(2);
  
}
void W_E_STATE_Go_task(){
  
    if(Emergency_pushed){
     N_S_Green = 0;
    N_S_Red = 1;
    W_E_Green =0;
    W_E_Red = 1;
    Turn_Red = 1;
    Turn_Green = 0;
    BUS_Green =0 ;
    BUS_Red = 1;
    wait(3);
    Emergency_pushed = false;
  }
  else{
    N_S_Green = 0;
    N_S_Red = 1;
    W_E_Green =1 ;
    W_E_Red = 0;
    BUS_Red = 1;
    BUS_Green = 0;
    Turn_Green = 0;
    Turn_Red = 1;
    wait(4);
}
}
void W_E_STATE_Wait_task(){
    N_S_Green = 0;
    N_S_Red = 1;
    W_E_Green =1 ;
    W_E_Red = 1;
    BUS_Red = 1;
    BUS_Green = 0;
    Turn_Green = 0;
    Turn_Red = 1;
    wait(2);
}
// void TURN_STATE_Go_task(){
//   Turn_Green = 1;
//   Turn_Red = 0;
//   BUS_Green = 0;
//   BUS_Red = 1;
//   wait(4);
// }
// void TURN_STATE_Wait_task(){
//   Turn_Green = 1;
//   Turn_Red = 1;
//   BUS_Green = 0;
//   BUS_Red = 1;
//   wait(2);
// }
// void BUS_STATE_Go_task(){
//   BUS_Green = 1;
//   BUS_Red = 0;
//   Turn_Red  = 1;
//   Turn_Green = 0;
//   wait(4);
// }
// void BUS_STATE_Wait_task(){
//   BUS_Green = 1;
//   BUS_Red = 1;
//   Turn_Red  = 1;
//   Turn_Green = 0;
//   wait(2);
// }
void Emergency_STATE_task(){
  // Emergency_pushed = true;
  switch (curr_state) {
     case N_S_STATE_Go :{
        N_S_Green = 1;
        N_S_Red = 1;
        W_E_Green =0;
        W_E_Red = 1;
        Turn_Red = 1;
        Turn_Green = 0;
        BUS_Green =0 ;
        BUS_Red = 1;
        wait(2);
        N_S_Green = 0;
        N_S_Red = 1;
        W_E_Green =0;
        W_E_Red = 1;
        Turn_Red = 1;
        Turn_Green = 0;
        BUS_Green =0 ;
        BUS_Red = 1;
        wait(3);
        break;
    }
    case N_S_STATE_Wait:{
      Emergency_pushed = true;
      break;
    }
     case W_E_STATE_Go:{
        N_S_Green = 0;
        N_S_Red = 1;
        W_E_Green =1 ;
        W_E_Red = 1;
        BUS_Red = 1;
        BUS_Green = 0;
        Turn_Green = 0;
        Turn_Red = 1;
        wait(2);
        N_S_Green = 0;
        N_S_Red = 1;
        W_E_Green =0;
        W_E_Red = 1;
        Turn_Red = 1;
        Turn_Green = 0;
        BUS_Green =0 ;
        BUS_Red = 1;
        wait(3);
        break;

    }
    case W_E_STATE_Wait:{
      Emergency_pushed = true;
      break;
    }
  }
}

void state_machine() {
  curr_state = (curr_state+ 1) % 4;
  switch (curr_state){
     case N_S_STATE_Go :{
      N_S_STATE_Go_task();
      break;
    }
    case N_S_STATE_Wait:{
      N_S_STATE_Wait_task();
      break;
    }
     case W_E_STATE_Go:{
      W_E_STATE_Go_task();
      break;
    }
    case W_E_STATE_Wait:{
      W_E_STATE_Wait_task();
      break;
    }
   
    // case TURN_STATE_Go:{
    //   TURN_STATE_Go_task();
    //   break;
    // }
    // case TURN_STATE_Wait:{
    //   TURN_STATE_Wait_task();
    //   break;
    // }
    // case BUS_STATE_Go:{
    //   BUS_STATE_Go_task();
    //   break;
    // }
    // case BUS_STATE_Wait:{
    //   BUS_STATE_Wait_task();
    //   break;
    // }
  }

}

int main() {
  button1.rise(&Emergency_STATE_task);
  while(1) {
    state_machine();
  }
}
