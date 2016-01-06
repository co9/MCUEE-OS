#include <reg51.h>
#include "core.h"
#define LED P2

extern int timer;
int count=0;

//LED Open
int  TASK1()
{
	LED=0xFF;
	return 0;
}

//LED Close
int  TASK2()
{
	LED=0x00;
	return 0;
}

//Timer0 Init
int Timer_Init()
{
	TMOD=0x01;
	TH0=(65536-50000)/256;
	TL0=(65536-50000)%256;
	IE=0x82;
	TR0=1;
	return 0;
}

//Timer0 interrupt
void timer0(void) interrupt 1 using 2
{
	//1S
	if(count>20)
	{
		timer++;
		count=0;
		
	}
	else
	{
		TR0=0;
		count++;	
		TH0=(65536-50000)/256;
		TL0=(65536-50000)%256;
		TR0=1;
	}
}

//Main programming
int main()
{
	Timer_Init();
	
	OS_Start();
	TASK_Create(TASK1,0,2);
	TASK_Create(TASK2,1,5);
	while(1)
	{
		TASK_Excute();
		if(timer>20)TASK_Delete(TASK1);
		if(timer>60)OS_Stop();
	}

	return 0;
}
