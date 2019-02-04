#include "mbed.h"
#include "rtos.h"
#include "string.h"
#include "stdio.h"
#include "stdlib.h"
#include "data.h"

Thread thread2;
Thread thread3;
Thread thread4;
Thread thread5;

DigitalOut L6(LED_BLUE);

int pcTemperature;

char pcTime[5];


Serial pc(USBTX, USBRX); // tx, rx

void task1(void);

void task2(void);
void task3(void);
void task4(void);
void task5(void);

void setTime();


int temprature[32];
double average;

DigitalIn SW1(PTE0);
DigitalIn SW2(PTE1);

struct time
{
    int hour;
    int minute;
    int second;
    int milisecond;
};

struct time currentTime;
struct time currentTimeTemp;
int temp_index = -1;

int read_file(void){
temp_index ++;

if(temp_index<64){
    return data_set[temp_index];
}else{
    temp_index = -1;
}
return 0;

}
int execution = 0;


void task2(void)
{
    while (true)
    {
        Thread::signal_wait(0x2);
        L6 = !L6;
        pcTemperature = read_file();

        char buffer [1];
        int temp_to_be_sent = 0;

        temp_to_be_sent = pcTemperature;

        sprintf(buffer, "%d", temp_to_be_sent);
        pc.printf("%s\n", buffer);
    }
}

void task4(void)
{
    while (true)
    {
        Thread::signal_wait(0x04);

        int sw1 = !SW1;
        int sw2 = !SW2;
        if(sw1) {

            // Send 1
            pc.printf("1\n");
        } else if (sw2) {

            // Send 2
            pc.printf("2\n");
        } else {

            // Send 0
            pc.printf("0\n");
        }
    }
}

void task5(void)
{
    while (true)
    {
        Thread::signal_wait(0x5);
    }
}

void setTime()
{
    currentTime.milisecond += 100;
    if (currentTime.milisecond == 1000)
    {
        currentTime.milisecond = 0;
        currentTime.second += 1;
        if (currentTime.second == 60)
        {
            currentTime.second = 0;
            currentTime.minute += 1;
            if (currentTime.minute == 60)
            {
                currentTime.minute = 0;
                currentTime.hour += 1;
                if (currentTime.hour == 24)
                {
                    currentTime.hour = 0;
                }
            }
        }
    }
}

int main()
{


    thread2.start(task2);
    thread4.start(task4);
    thread5.set_priority(osPriorityIdle);
    thread5.start(task5);
    pc.baud(110);

    while(true) {
        // Main loop
        if(pc.readable()){

            // Got data from serial
            char ch[10];
            pc.scanf("%s",ch);

            if(strcmp(ch, "chek4") == 0){
                thread4.signal_set(0x04);

            } else if(strcmp(ch, "get_temp") == 0) {
                thread2.signal_set(0x02);
            }
        }
    }

    Thread::wait(osWaitForever);
}
