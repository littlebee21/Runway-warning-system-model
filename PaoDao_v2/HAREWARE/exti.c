#include "reg52.h"
#include "main.h"
#include "exti.h"
#include "watch.h"
/*********************************************************************************************
函数名：定时/计数器初始化函数
调  用：T_C_init();
参  数：无
返回值：无
结  果：设置SFR中T/C1和（或）T/C0相关参数
备  注：本函数控制T/C1和T/C0，不需要使用的部分可用//屏蔽
/**********************************************************************************************/
void T0_init (void){
	TMOD=0X21;			//设置计数器1和0  计数器1工作方式2   计数器0工作方式1
	EA = 1;	//中断总开关
	
	
	TH0 = 0x3C; //16位计数寄存器T0高8位
	TL0 = 0xB0; //16位计数寄存器T0低8位（0x3CB0 = 50mS延时）
	ET0 = 1; //T/C0中断开关
	TR0 = 1; //T/C0启动开关
}
/**********************************************************************************************/


/*********************************************************************************************
函数名：定时/计数器0中断处理函数
调  用：[T/C0溢出后中断处理]
参  数：无
返回值：无
结  果：重新写入16位计数寄存器初始值，处理用户程序
备  注：必须允许中断并启动T/C本函数方可有效，重新写入初值需和T_C_init函数一致
/**********************************************************************************************/
void T0_Check (void) interrupt 1  using 1{ //切换寄存器组到1
	TH0 = 0x3C; //16位计数寄存器T0高8位（重新写入初值）
	TL0 = 0xB0; //16位计数寄存器T0低8位（0x3CB0 = 50mS延时）
	State=Watch_State();
	Irrupt=Watch_Irrupt();
	//函数内容
}
/**********************************************************************************************/