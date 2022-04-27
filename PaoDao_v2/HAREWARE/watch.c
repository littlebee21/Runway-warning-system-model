#include "reg52.h"
#include "main.h"
#include "watch.h"


char Watch_State()
{		
		if(Runaway_have)				   //����������
		{	if(Watch_TakingOff())									//��⵽��� ��Ϊ���
			{	return TAKINGOFF;
			}
			else if(Watch_Landing())					//�յ������ź� ��Ϊ����	
			{	return LANDING;								
			}
			else																//���������Ϊ ��·ռ�û���
			{	return ROAD_OCCUPY;
			}		
		}
		else 									   // ����û������
		{								   
			if(Watch_Landing())					//�յ������ź�	��Ϊ����
			{	return LANDING;								
			}
			else			   							
			{	return NOTHING;					 			//��Ϊû��ʹ��
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
	char Time_Between=0;	  //����ʱ�����
	if(Test_Speed_have)				         //��⵽��ͨ����ʼ��ʱ	                                 //
	{	Time_Between++;			//��ʱ���жϵļ�ʱ����ʹ��
		return 0;
	}
	else 	   					//���̽���û��
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


