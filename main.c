//Test On Windows 10
//GNU GCC C99
#include "core.h"
#include <windows.h>

extern int timer;
int task1()
{
  printf("I am first task\n");
  return 0;
}
int task2()
{
  printf("I am second task\n");
  return 0;
}
int task3()
{
  printf("I am third task\n");
  return 0;
}

int main()
{

  OS_Start();

  //TASK Create
  TASK_Create(task1,0,2);
  TASK_Create(task2,1,5);
  TASK_Create(task3,2,6);
  while(1)
  {
    timer++;
    TASK_Excute();

    //print timer value
    printf("timer:%d\n",timer);

    //TASK Delete test
    if(timer==20)TASK_Delete(task1);

    //OS Stop test
    if(timer==40)OS_Stop();

    //delay 1s
    sleep(1);
  }

}
