#include "mbed.h"
#include "rtos.h"
#include "string.h"
#include "stdio.h"
#include "stdlib.h"
#include "data.h"
using namespace std;
DigitalOut L5(LED_GREEN) ;
DigitalOut L6(LED_RED);


Thread thread2;
Thread thread3;
Thread thread4;
Thread thread5;


int pcTemperature;

char pcTime[5];


Serial pc(USBTX, USBRX); // tx, rx

void task1(void);

void task3(void);
void task5(void);

void setTime();


int temprature[32];
double average;

DigitalIn SW1(PTD4);
DigitalIn SW2(PTD5);

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

int execution = 0;



void task1(void)
{
    L5 = !L5;
    execution++;
    setTime();
    if (execution % 10 == 0) {
        char buffer [1];
        int time = 0;
        time = currentTime.minute * 100 + currentTime.second;
        sprintf(buffer, "%d", time);
        pc.printf("%s\n", buffer);
        L6 = !L6;

    }
    if (execution == 50)
    {
        execution = 0;
        pc.printf("get_temp\n");
        wait(0.1);
    }
}


void task3(void)
{
    static int value = 0;
    while (true)
    {
        if(pc.readable()) {
            char ch[10];
            pc.scanf("%s", ch);
            pcTemperature = atoi(ch);
        value++;
        if (value < 32) {
            average = ((value - 1.0) * average + pcTemperature) / value;
        } else {
            average = (average * 32 - temprature[value % 32] + pcTemperature) / 32;
        }
        temprature[value % 32] = pcTemperature;
        char buffer [1];
        int printable_avg = average + 100;

        sprintf(buffer, "%d", printable_avg);
        pc.printf("%s\n", buffer);
        }
    }
}

void task5(void)
{
    pc.printf("this is task5\n");
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
    pc.baud(110);
    currentTime.hour = 0;
    currentTime.minute = 0;
    currentTime.second = 0;
    currentTime.milisecond = 0;
    thread3.start(task3);
    thread5.set_priority(osPriorityIdle);
    thread5.start(task5);
    RtosTimer task1Timer(task1);
    task1Timer.start(100);
    Thread::wait(osWaitForever);
}
