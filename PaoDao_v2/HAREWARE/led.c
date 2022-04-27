#include "reg52.h"
#include "led.h"
#include "watch.h"

void Change_Warning_Led()
{
	switch (Taxiway_Watch){
					case 0x80:	Led_R3=1;
											Led_R2=0;
											Led_R1=0;		
											break;
					case 0x40: 	Led_R3=0;
											Led_R2=1;
											Led_R1=0;
											break;
					case 0x20: 	Led_R3=0;
											Led_R2=0;
											Led_R1=1;
											break;
	}
}	

void Change_Taking_Off_Led()//∫Ïµ∆¡¡
{
	Led_R4=1;
	Led_Y5=0;
	Led_G6=0;
	
}
void Change_Occupy_Led()//ª∆µ∆
{	Led_R4=0;
	Led_Y5=1;
	Led_G6=0;
}
void Change_Nothing_Led()//∂º≤ª¡¡
{	
	Led_R4=0;
	Led_Y5=0;
	Led_G6=0;
}
void Change_Landing_Led()//¡¡ª∆µ∆
{
	Led_R4=0;
	Led_Y5=0;
	Led_G6=1;
}