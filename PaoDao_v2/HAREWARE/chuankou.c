/*******************************************************************************
* 函数名         :UsartInit()
* 函数功能		 :设置串口（使用定时器1）      设置定时器0（）
* 波特率         ：9600
* 输入           : 无
* 输出         	 : 无
*******************************************************************************/
#include "reg52.h"
#include "main.h"
#include "chuankou.h"
#include "watch.h"

void Usart_Init()
{
	SCON=0X50;			//设置为工作方式1
	TMOD=0X21;			//设置计数器1和0  计数器1工作方式2   计数器0工作方式1
	PCON=0X80;			//波特率加倍
	TH1=0XFA;				//计数器初始值设置，注意波特率是4800的
	TL1=0XFA;
	
//	ES=1;						//打开接收中断
//	EA=1;						//打开总中断
//	ET0=1;         				//打开定时器0中断
	TR1=1;					//打开计数器1
//	TR0=1; 					//打开计数器0
}




void Send_Warning()
{
	char Tem=0;
	Tem=Taxiway_Watch;    //寄存器 的值装入变量
	SBUF=Tem;
	while(!TI);
	TI=0;
}

//要求 
//接受一段时间后自动解除 
char Receive_L_Signal() 
{	
	char Tem=0;
	RI=0;
	Tem=SBUF;
	if(Tem==0x90)
	{	return 1;
	}	
	else
	{	return 0;
	}
}