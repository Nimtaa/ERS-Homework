#include "mbed.h"

DigitalIn Switch1(PTD3);
PwmOut  led(PTD2);

int main(){
	led.period(0.01);
	led = 0.0;
    bool rising = 1;
	while(true){
        if(rising && Switch1 == 0){
            led = led +  0.2;
            wait(1);
            if(led == 1){
                rising = 0;
            }
        }
        if(!rising && Switch1 == 0){
            led = led -  0.2;
            wait(1);
            if(led == 0){
                rising = 1;
            }
        }
	}
}