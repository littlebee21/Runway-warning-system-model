#include<reg52.h>
sbit Watch_1=P2^0;
sbit Watch_2=P2^1;
sbit Watch_3=P2^2;
sbit Watch_4=P2^3;
sbit LED_1=P0^0;
sbit LED_2=P0^1;
sbit LED_3=P0^2;
sbit LED_4=P0^3;

void UsartInit()
{
	SCON=0X50;			//设置为工作方式1
	TMOD=0X20;			//设置计数器工作方式2
	PCON=0X80;			//波特率加倍
	TH1=0XFA;				//计数器初始值设置，注意波特率是4800的
	TL1=0XFA;
//	ES=1;						//打开接收中断
//	EA=1;						//打开总中断
	TR1=1;					//打开计数器
}
void main()
{	unsigned char tem;
	UsartInit();
	while(1)
	{	tem=(P0<<4);
		switch (tem)
		{
			case 0x10:
						LED_1=0;
						LED_2=1;
						LED_3=1;
						LED_4=1;	//为真时语句
						break;
					
			case 0x20:
						LED_1=1;
						LED_2=0;
						LED_3=1;
						LED_4=1;	//为真时语句
						break;
			case 0x40:
						LED_1=1;
						LED_2=1;
						LED_3=0;
						LED_4=1;	//为真时语句
						break;
			case 0x80:
						LED_1=1;
						LED_2=1;
						LED_3=1;
						LED_4=0;	//为真时语句
						break;
			case 0x00:
						LED_1=0;										 
						LED_2=0;
						LED_3=0;
						LED_4=0;	//为真时语句
						break;




			case 0x90:
						LED_1=1;										 
						LED_2=1;
						LED_3=1;
						LED_4=1;	//为真时语句
						tem=(P0<<4);
						SBUF=tem;
						while(!TI);
						TI=0;
						break;
						
			case 0xa0:					  
						LED_1=1;										 
						LED_2=1;
						LED_3=1;
						LED_4=1;	//为真时语句
						tem=(P0<<4);
						SBUF=tem;
						while(!TI);
						TI=0;
						break;
			case 0xc0:
						LED_1=1;										 
						LED_2=1;
						LED_3=1;
						LED_4=1;	//为真时语句
						tem=(P0<<4);
						SBUF=tem;
						while(!TI);
						TI=0;
						break;
			case 0x50:
						LED_1=1;										 
						LED_2=1;
						LED_3=1;
						LED_4=1;	//为真时语句
						tem=(P0<<4);
						SBUF=tem;
						while(!TI);
						TI=0;
						break;
			case 0x60:
						LED_1=1;										 
						LED_2=1;
						LED_3=1;
						LED_4=1;	//为真时语句
						tem=(P0<<4);
						SBUF=tem;
						while(!TI);
						TI=0;
						break;
			case 0x30:
						LED_1=1;										 
						LED_2=1;
						LED_3=1;
						LED_4=1;	//为真时语句
						tem=(P0<<4);
						SBUF=tem;
						while(!TI);
						TI=0;
						break;	
				
			default:break;
						
		}
	}
}