#ifndef _core_h_
#define _core_h_

#include <stdio.h>
#include <stdlib.h>
#define TASK_MAX 20

//define symbol
typedef unsigned char u_int_8;
typedef signed char s_int_8;
typedef unsigned int u_int_16;
typedef signed int s_int_16;
//OS Start and Task init
u_int_8 OS_Start(void);

//Task init
u_int_8  OS_Stop(void);

//Parameter Output
void *TASK_Out[TASK_MAX];

//Now TASK
//int TASK_Now[TASK_MAX];

/*******************************************/
/*1.Name:TASK_Init                         */
/*2.input:void                             */
/*3.output:int                             */
/*4.excute succeed return 0                */
/*Clear TASK TABLE,TASK Sched and TASK Time*/
/*******************************************/
u_int_8 TASK_Init(void);

/*******************************************/
/*1.Name:TASK_Create                       */
/*2.input:int(*)(),int,int                 */
/*3.output:int                             */
/*4.excute succeed return 0                */
/*Put Task on TASK TABLE                   */
/*put prior on Task prior                  */
/*put TASK Time on TASK Time               */
/*******************************************/
u_int_8 TASK_Create(u_int_8 (*TASK)(),u_int_8 Priormint,u_int_8 timer);

/*****************************************************/
/*1.Name:TASK_Delete                                 */
/*2.input:int(*)()                                   */
/*3.output:int                                       */
/*4.excute succeed return 0                          */
/*Remoce Task on TASK TABLE and put TASK_NULL on TASK*/
/*put -1 on Task Time                                */
/*****************************************************/
u_int_8 TASK_Delete(u_int_8 (*TASK)());

/*****************************************************/
/*1.Name:TASK_Excute                                 */
/*2.input:void                                       */
/*3.output:int                                       */
/*4.excute succeed return 0                          */
/*****************************************************/
u_int_8 TASK_Excute(void);

//int *TASK_Where(void);

//Empty Task
u_int_8 TASK_NULL(void);

u_int_8 TASK_Output(void *parameter,u_int_8 Prior);


#endif
