#include "mbed.h"

Serial pc(USBTX, USBRX); // tx, rx
PwmOut led(LED1);

float brightness = 0.0;
char buffer[128];
int main() {
    pc.printf("Enter your command");
    while(1) {
        pc.gets(buffer);
        if(strcmp(buffer,"temp")) {//temp
           
        }
        if(strcmp(buffer,"on")) { //on
        } 
        if(strcmp(buffer,"off")) { //off
        } 
        if(strcmp(buffer,"play")) { //play
        
        } 
        

    }
}