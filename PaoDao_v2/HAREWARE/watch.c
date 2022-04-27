#include "reg52.h"
#include "main.h"
#include "watch.h"


char Watch_State()
{		
		if(Runaway_have)				   //道上有物体
		{	if(Watch_TakingOff())									//检测到起飞 视为起飞
			{	return TAKINGOFF;
			}
			else if(Watch_Landing())					//收到降落信号 视为降落	
			{	return LANDING;								
			}
			else																//其余情况视为 道路占用滑行
			{	return ROAD_OCCUPY;
			}		
		}
		else 									   // 道上没有物体
		{								   
			if(Watch_Landing())					//收到降落信号	视为降落
			{	return LANDING;								
			}
			else			   							
			{	return NOTHING;					 			//视为没有使用
		 	}
		}
		
}
char Watch_Irrupt()
{
	if(Taxiway_have)
	{		return 1;
	}
	else 
	{		return 0;
	}
}






char Watch_TakingOff()
{	
	char Time_Between=0;	  //检测的时间变量
	if(Test_Speed_have)				         //检测到有通过开始计时	                                 //
	{	Time_Between++;			//定时器中断的计时功能使用
		return 0;
	}
	else 	   					//检测探测口没有
	{	if(Watch_Time_Ok)
		{	Time_Between=0;
			return 1;
		}
		else
		{	return 0;
		}		
	}
}






char Watch_Landing()
{	
	if(Receive_L_Signal())
	{	return 1;
	}
	else
	{	return 0;
	}
}


