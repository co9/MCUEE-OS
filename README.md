#MCUEE-OS
Simple Time-Sharing and Task Scheduler Dispatch

#ChangLog:
2015/12/29:

Kernel V1.0:

Basic Task Scheduler and Time-Sharing

#1.Test Environment
Windows 10 x86

GNU GCC

#2.How to use test program?
1.make main

2.execute "main"

#3.How to transplant?
1.Need to Systick let's timer increase.

2.Add OS_Start() in your program startup.

3.Add TASK_Create() in your program

4.Execute "TASK_Excute()" after timer increase

#4.For Embedded
Arduino test OK!(In Arduino Folder)

AT89S51 test OK!(In AT89S51 Folder;MAX 9 TASK)

PIC18F4520 test not ready!

STM32F407 test not ready!
