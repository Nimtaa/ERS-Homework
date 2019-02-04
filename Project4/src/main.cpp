// #include <mbed.h>

// // System Outputs
// DigitalOut red_led(PTC1);
// DigitalOut green_led(PTC2);
// BusOut display(PTE5,PTE4,PTE3,PTE2,PTB11,PTB10,PTB9,PTB8);


// // Intrupts
// InterruptIn push_button1(PTD1);
// InterruptIn push_button2(PTD2);
// InterruptIn push_button3(PTD3);

// bool but1_presed = false;
// bool but2_presed = false;
// bool but3_presed = false;

// bool task3_running = false;
// bool task4_running = false;
// bool task5_running = false;

// unsigned int i;

// void scheduler();
// // Tasks
// void task5(){
//   task5_running = true;
//     display=0xBF;
//     wait(1);
//     display=0x86;
//     wait(1);
//     display=0xDB;
//     wait(1);
//     display=0xCF;
//     wait(1);
//     display=0xE6;
//     wait(1);
//     display=0xED;
//     wait(1);
//     display=0xFD;
//     wait(1);
//     display=0x87;
//     wait(1);
//     display=0xFF;
//     wait(1);
//     display=0xEF;
//     wait(1);
//     display=0x00;
//     wait(1);
//     task5_running = false;
//     scheduler();
// }


// void task3(){
//     task3_running = true;
//     red_led = 1;
//     green_led = 0; 
//     wait(2);
//     red_led = 0;
//     green_led = 1; 
//     wait(2);
//     task3_running = false;
//     scheduler();
// }
// void task4(){
//   task4_running = true;
//   green_led = 1; 
//   red_led = 1;
//   wait(2);
//   green_led = 0; 
//   red_led = 0;
//   wait(2);
//   task4_running = false;
//   scheduler();
// }

// // ISRs
// void isr1() {
//     but1_presed = true; 
// }
// void isr2() {
//     but2_presed = true; 
// }
// void isr3() {
//     but3_presed = true; 
// }

// void scheduler() {
//   if (but3_presed) {
//         but3_presed = false;
//         red_led = 0;
//         green_led = 0;
//         task5();
//         red_led = 0;
//         green_led = 0;
//         wait(2);
//   }else if (but2_presed) {
//         but2_presed = false;
//         task4();
//         red_led = 0;
//         green_led = 0;
//         wait(2);
//   }else if (but1_presed) {
//         but1_presed = false;
//         task3();
//         red_led = 0;
//         green_led = 0;
//         wait(2);
//   }
// }

// int main() {
//   push_button1.rise(&isr1);
//   push_button2.rise(&isr2);
//   push_button3.rise(&isr3);
//   while(1) {
//     scheduler();
//   }
// }