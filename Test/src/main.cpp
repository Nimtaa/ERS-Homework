 #include "mbed.h"

// DigitalIn Switch1(PTD3);
// DigitalOut myled(PTD2);

// int main(){
//  myled = 0;
//     float low = 0;
//     float high = 1;
//     bool rising = true;
//  while(true){
//      if(rising && Switch1 == 0 ){
//             myled = 1;
//             wait(low);
//             myled = 0;
//             wait(high);
//             low = low + 0.2;
//             high = high - 0.2;
//             if(high==0){
//                 rising =false;
//             }
//         }
//         if(!rising && Switch1 == 0){
//             myled = 1;
//             wait(low);
//             myled = 0;
//             wait(high);
//             low = low - 0.2;
//             high = high + 0.2;
//             wait(1);
//             if(high==1){
//                 rising = true;
//             }
            
//         }
//         }
//  }

// #include <mbed.h>
// DigitalOut led(PTD2);
// int state = 0 ; 
// double HighePeriod = 0.1; 
// double LowPeriod = 0.1;
// DigitalIn sw(PTD3);
// int main() {
//     while(1) {
//  if (state == 1) {
//    if (sw == 1){
//         if (HighePeriod == 0.2){
//         state = 0 ; 
//         wait(1);
//         }
//         else{
//         HighePeriod = HighePeriod + 0.02;
//         LowPeriod = LowPeriod - 0.02;
//         }
//   }
//     else{
//     led = 1; 
//     wait(HighePeriod);
//     led = 0 ;
//     wait(LowPeriod);
//     }
//  }
//  else{
//      if (sw == 1){
//         if (HighePeriod == 0){
//         state = 1 ; 
//         wait(1);
//         }
//         else{
//         HighePeriod = HighePeriod - 0.02;
//         LowPeriod = LowPeriod + 0.02;
//         }
//   }
//     else{
//     led = 1; 
//     wait(HighePeriod);
//     led = 0 ;
//     wait(LowPeriod);
//     }
//  }}}


// #include "mbed.h"
    
// DigitalOut led(PTD2);
// DigitalIn button(PTD3);
// int main() {
//     led = 0;
//     double LOW_PERIOD = 0.00;
//     double HIGH_PERIOD = 0.01; 
//     int i = 1;
//     int j = -1;
//     while(1) 
//     {
//         if (button == 0) {
//             // Update Periods
//             LOW_PERIOD += i * 0.002;
//             HIGH_PERIOD += j * 0.002;
//             if (LOW_PERIOD == 0.01 || LOW_PERIOD == 0) {
//                 // Rise and Fall Switch
//                 i *= -1;
//                 j *= -1;
//             }
//             while(button == 0){
//                 led = 0;
//                 wait(LOW_PERIOD);
//                 led = 1;
//                 wait(HIGH_PERIOD);
//             }  
//         }
//     }
// }

DigitalIn Switch1(PTD3);
DigitalOut led(PTD2);
int main(){
	led = 0;
    int counter = 0;
    bool rising = true;
	while(true){
        if(Switch1 == 0){
            if(rising){
                wait(0.5);
                counter += 1;
                 for(int i=0; i<counter; i++){
        led = 1;
        wait(0.0001);
    }
    for(int j=0; j<(5-counter); j++){
        led = 0;
        wait(0.0001);
    }
                if(counter == 5){
                    rising = false;
                }
            }   
            else{
                wait(0.5);
                counter -= 1;
                 for(int i=0; i<counter; i++){
        led = 1;
        wait(0.0001);
    }
    for(int j=0; j<(5-counter); j++){
        led = 0;
        wait(0.0001);
    }
                if(counter == 0){
                    rising = true;
                }
            }
            wait(0.05);
        }else {
                for(int i=0; i<counter; i++){
            led = 1;
            wait(0.0001);
        }
        for(int j=0; j<(5-counter); j++){
            led = 0;
            wait(0.0001);
        }
        }
	}
}
// DigitalIn Switch1(PTD3);
// PwmOut  led(PTD2);

// int main(){
//     led.period(0.01);
// 	led = 0.0;
//     float val = 0;
//     bool increaseState = true;
// 	while(true){
//         if(Switch1 == 0){
//             if(increaseState){
//                 val += 0.2;
//                 led = val;
//                 if(val >= 1.0){
//                     increaseState = false;
//                 }
//             }   
//             else{
//                 val -= 0.2;
//                 led = val;
//                 if(val <= 0.0){
//                     increaseState = true;
//                 }
//             }
//             wait(0.05);
//         }else {
//             led = val;
//         }
// 	}
// }


// DigitalIn Switch1(PTD3);
// DigitalOut myled(PTD2);

// int main(){
// 	myled = 0;
//     double low = 0.00;
//     double high = 0.001;
//     int increase = 1;
//     while(true){
//         myled = 1;
//         wait(low);
//         myled = 0;
//         wait(0.0002 - low);
//         int counter = 0;
//         if(Switch1==0){
//             if(increase==1){
//                 myled = 1;
//                 wait(low);
//                 myled = 0;
//                 wait(high);
//                 low = low + 0.0002;
//                 high = high - 0.0002;
//                 counter++;
//                 wait(0.5);
//                 if(counter == 5 ){
//                     increase = 0;
//                 }
//             }
//             else  {
//             myled = 1;
//             wait(low);
//             myled = 0;
//             wait(high);
//             low = low - 0.0002;
//             high = high + 0.0002;
//             counter--;
//             wait(0.5);
//             if(counter == 0){
//                 increase = 1;
//             }
//          }
//     }
//     }
// }
