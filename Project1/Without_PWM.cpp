 #include "mbed.h"

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
                for(int i=0; i<(5-counter); i++){
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
                for(int i=0; i<(5-counter); i++){
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
                for(int i=0; i<(5-counter); i++){
                    led = 0;
                    wait(0.0001);
                }
            }
        }
    }
