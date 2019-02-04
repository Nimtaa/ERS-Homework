# -*- coding: utf-8 -*-
"""
Created on Sun Jan 20 18:35:36 2019

@author: Nima
"""
import socket
import time
import datetime
import serial
import re
import math


currentTemp = 0
lastTimeReadTemp = ""
lastRealTimeReadTemp = datetime.datetime.now().time()
averageTemp = 0


ser_left = serial.Serial(
    port='COM7',
    baudrate=110,
    parity=serial.PARITY_NONE,
    stopbits=serial.STOPBITS_ONE,
    bytesize=serial.EIGHTBITS,
)

ser_right = serial.Serial(
    port='COM8',
    baudrate=110,
    parity=serial.PARITY_NONE,
    stopbits=serial.STOPBITS_ONE,
    bytesize=serial.EIGHTBITS,
)


def write_to_left(command):
    ser_left.write(command.encode());

def read_from_left():
    command = ser_left.readline()
    command =command.decode('ascii')
    return command

def write_to_right(command):
    ser_right.write(command.encode());

def read_from_right():
    command = ser_right.readline()
    command = command.decode('ascii')
    return command

def checkingTask4(l_command):
    global lastTimeReadTemp
    global lastRealTimeReadTemp

    print("********************************")

    stripped = l_command.strip('\n')
    if(int(stripped[len(stripped) - 1]) % 5 == 0):
        lastTimeReadTemp = l_command
        lastRealTimeReadTemp = datetime.datetime.now().time()

    write_to_right('chek4\n')
    r_command = read_from_right();
    c = r_command.strip('\n');
    print("Switch pressed: ",c)

    try:
        if (c == '1'):
            temp = "LTemp: " + currentTemp.strip('\n') + " Time: " + lastTimeReadTemp.strip('\n') + " RTime: " + str(lastRealTimeReadTemp) + '\n'
            lcd_temp = currentTemp.strip('\n') + '|' + lastTimeReadTemp.strip('\n') + '|' + str(lastRealTimeReadTemp) + '\n'
            print(temp)
            print(lcd_temp.encode());

        elif (c == '2'):
            temp = "ATemp: " + str(int(averageTemp) - 100) + " Time: " + l_command.strip('\n') + " RTime: " + str(datetime.datetime.now().time()) + '\n'
            lcd_temp = str(int(averageTemp) - 100) + '|' + l_command.strip('\n') + '|' + '\n'
            print(temp)
            print(lcd_temp.encode());

        else:
            true_time = l_command.strip('\n')
            time_seconds = int(true_time) % 100
            time_minutes = int(math.floor(int(true_time) / 100))
            temp = "Time: " + str(time_minutes) + ":" + str(time_seconds) + " " + " RTime: " + str(datetime.datetime.now().time()) + '\n'
            lcd_temp = str(time_minutes)  + ':' + str(time_seconds) + '|' +  '\n'
            print(temp)
            print(lcd_temp.encode())

    except Exception as ex:
        pass
    print("********************************")


print("Connected to port: ", ser_left.portstr)
print("Connected to port: ", ser_right.portstr)

while True:

    l_command = read_from_left()
    if(l_command == 'get_temp\n'):
        write_to_right(l_command)
        r_command = read_from_right()
        currentTemp = r_command
        write_to_left(r_command)
        l_command = read_from_left()
        averageTemp = l_command
    else:
        checkingTask4(l_command)
