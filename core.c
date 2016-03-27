#include "core.h"

//Systick papameter
int timer=0;

//TASK TABLE
u_int_8 (*TASK_Ptr[TASK_MAX])(void);

//TASK Sched
u_int_8 (*TASK_Sched[TASK_MAX])(void);

//TASK Time
u_int_8 TASK_Time[TASK_MAX];

//Init OS
u_int_8 OS_Start(void)
{
    if(TASK_Init()!=0)return -1;
    return 0;
}

u_int_8 OS_Stop(void)
{
    if(TASK_Init()!=0)return -1;
    return 0;
}

u_int_8 TASK_Init(void)
{
    int i=0;
    for(i=0;i<TASK_MAX-1;i++)
    {
       TASK_Ptr[i]=TASK_NULL;
       TASK_Sched[i]=TASK_NULL;
       TASK_Time[i]=-1;
    }
    return 0;
}
u_int_8 TASK_Create(u_int_8 (*TASK)(),u_int_8 Prior,u_int_8 timer)
{
    TASK_Ptr[Prior]=TASK;
    TASK_Time[Prior]=timer;
    return 0;
}

u_int_8 TASK_Delete(u_int_8 (*TASK)())
{
    int i=0;
    for(i=0;i<TASK_MAX-1;i++)
    {
       if(TASK_Ptr[i]==TASK)
       {
            TASK_Ptr[i]=TASK_NULL;
            TASK_Time[i]=-1;
            break;
       }
    }
    return 0;
}

//TASK Dispatch
u_int_8 TASK_Switch()
{
   int i=0;
   int j=0;

   for(i=0;i<TASK_MAX-1;i++)
   {
     if(TASK_Time[i]!=-1)
     {
       if(timer%TASK_Time[i]==0)
       {
          TASK_Sched[j]=*TASK_Ptr[i];
          j++;
       }
     }
   }
   return 0;
}
u_int_8 TASK_Excute()
{
    int i=0;
    //TASK Excute
    while(TASK_Sched[i]!=TASK_NULL)
    {
      //Excute
      (*TASK_Sched[i])();

      //Empty
      TASK_Sched[i]=TASK_NULL;
      i++;
    }
    TASK_Switch();
    return 0;
}
/*
int *TASK_Where()
{
  static int Get_info[2];
  Get_info[0]=TASK_Now;
  return Get_info;
}*/
//TASK Sned Output ???
u_int_8 TASK_Output(void *parameter,u_int_8 Prior)
{
  TASK_Out[Prior]=parameter;
  //printf("%p\n",ptr);
  //printf("%d\n",(int*)var);
  return 0;
}
u_int_8 TASK_NULL()
{
    return 0;
}
