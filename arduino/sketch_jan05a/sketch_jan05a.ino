extern "C"
{
  #include "core.h" 
}
extern int timer;
int time_b=0,time_a=0;
int task1()
{
  return 0;  
}
int task2()
{
  return 0;  
}
void setup() {
  // put your setup code here, to run once:
  OS_Start();
  TASK_Create(task1,0,2);
  TASK_Create(task2,1,5);
}

void loop() {
  // put your main code here, to run repeatedly:
  time_a=millis();
  if(time_a-time_b>=1000)
  {
    timer++;
    TASK_Excute();
    time_b=time_a;  
  }
  
}
