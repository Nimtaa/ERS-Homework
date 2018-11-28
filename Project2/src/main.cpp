#include "mbed.h"

PwmOut speaker(PTD3); 

// 1/8 : 0.625
// 1/16 : 0.31
// 3/16 : 0.93

int main()
{
    int i;
// generate a arbitrary frequency tone using PWM hardware output
    speaker.period(1.0/329.628);
    speaker =0.3; //30% duty cycle - %50 is  max volume
    wait(0.625);
    // speaker=0.0; // turn off audio
    speaker.period(1.0/415.305);
    speaker = 0.3;
    wait(0.625);
    speaker = 0.0;
    wait(0.1);
    speaker.period(1.0/415.305);
    speaker = 0.3;
    wait(0.625);
    speaker = 0.0;
    wait(0.1);
    speaker.period(1.0/415.305);
    speaker = 0.3;
    wait(0.625);
    speaker = 0.0;
    wait(0.1);
    speaker.period(1.0/369.994);
    speaker = 0.5;
    wait(0.31);
   

    speaker.period(1.0/329.628);
    speaker = 0.5;
    wait(0.31);


    speaker.period(1.0/493.883);
    speaker = 0.5;
    wait(0.93);
    speaker = 0.0;
    wait(0.1);

    speaker.period(1.0/493.883);
    speaker = 0.5;
    wait(0.31);
    speaker = 0.0;
    wait(0.1);

    speaker.period(1.0/440);
    speaker = 0.5;
    wait(0.31);
    speaker = 0.0;
    wait(0.1);

    speaker.period(1.0/415.305);
    speaker = 0.5;
    wait(0.625);
    speaker = 0.0;
    wait(0.1);

    speaker.period(1.0/415.305);
    speaker = 0.5;
    wait(0.625);
    speaker = 0.0;
    wait(0.1);

    speaker.period(1.0/415.305);
    speaker = 0.5;
    wait(0.625);
    speaker = 0.0;
    wait(0.1);

    speaker.period(1.0/369.994);
    speaker = 0.5;
    wait(0.31);
 
    speaker.period(1.0/329.628);
    speaker = 0.5;
    wait(0.31);

    speaker.period(1.0/493.883);
    speaker = 0.5;
    wait(0.93);
    speaker = 0.0;
    wait(0.1);

    speaker.period(1.0/493.883);
    speaker = 0.5;
    wait(0.31);
    speaker = 0.0;
    wait(0.1);

    speaker.period(1.0/440);
    speaker = 0.5;
    wait(0.31);
    speaker = 0.0;
    wait(0.1);

// 1/8 : 0.625
// 1/16 : 0.31
// 3/16 : 0.93
    speaker.period(1.0/415.305);
    speaker = 0.5;
    wait(0.625);
    speaker = 0.0;
    wait(0.1);
    
    speaker.period(1.0/440);
    speaker = 0.5;
    wait(0.31);
    speaker = 0.0;
    wait(0.1);

    speaker.period(1.0/493.883);
    speaker = 0.5;
    wait(0.31);
    speaker = 0.0;
    wait(0.1);

    speaker.period(1.0/440);
    speaker = 0.5;
    wait(0.625);
    speaker = 0.0;
    wait(0.1);

    speaker.period(1.0/415.305);
    speaker = 0.5;
    wait(0.625);
    speaker = 0.0;
    wait(0.1);

    speaker.period(1.0/369.994);
    speaker = 0.5;
    wait(0.625);
    speaker = 0.0;
    wait(0.1);

    speaker.period(1.0/311.127);
    speaker = 0.5;
    wait(0.625);
    speaker = 0.0;
    wait(0.1);


    speaker.period(1.0/493.883);
    speaker = 0.5;
    wait(0.625);
    speaker = 0.0;
    wait(0.1);


    speaker.period(1.0/329.628);
    speaker = 0.5;
    wait(0.625);
    speaker = 0.0;
    wait(0.1);

 
}
