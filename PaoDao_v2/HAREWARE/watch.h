#ifndef __watch_h__
#define __watch_h__
#include "reg52.h"



sbit Watch_1=P1^0;
sbit Watch_2=P1^1;
sbit Watch_3=P1^2;

char Watch_TakingOff(void);
char Watch_Landing(void);

char Watch_State();
char Watch_Irrupt();

char Receive_L_Signal();


#define Watch_Time_Ok     ((Time_Between>3)&&(Time_Between<40))

#define Taxiway_Watch  (P1<<5)
#define Taxiway_have  ((P1<<5)!=0)
#define Taxiway_no		((P1<<5)==0)


#define Runaway_Watch  (P0<<2)
#define Runaway_have	((P0<<2)!=0)
#define Runaway_no		((P0<<2)==0)

sbit Test_Speed=P0^1;  //寄存器使用其他名称
#define Test_Speed_have  (Test_Speed==1)
#define Test_Speed_no		 (Test_Speed==0)


#endif