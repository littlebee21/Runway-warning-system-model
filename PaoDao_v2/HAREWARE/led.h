#ifndef __led_h__
#define __led_h__


sbit Led_R1=P2^0;
sbit Led_R2=P2^1;
sbit Led_R3=P2^2;


sbit Led_R4=P2^3; 				 //ºìÉ«
sbit Led_Y5=P2^4;				//»ÆÉ«
sbit Led_G6=P2^5;			   //ÂÌÉ«




void Change_Warning_Led();
void Change_Taking_Off_Led();
void Change_Occupy_Led();
void Change_Nothing_Led();
void Change_Landing_Led();


#endif /*__led_h_*/