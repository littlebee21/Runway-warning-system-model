/**************************************************************************************
*		              跑道入侵	主函数
*
																				  
***************************************************************************************/
#include "reg52.h"
#include "main.h"
#include "chuankou.h"
#include "exti.h"
#include "led.h"

char State=0x55;
char Irrupt=0x55;

void main(void)
{	
	Usart_Init();
	T0_init ();
	while(1)
	{	
		switch(State)
    {     
			case TAKINGOFF:
            if(Irrupt)
						{	
								Send_Warning();
								Change_Warning_Led();
						}
						else
						{		Change_Taking_Off_Led();							
						}
            break;
        
				
				
				
				
				case LANDING:
            if(Irrupt) 
						{		
								Send_Warning();
								Change_Warning_Led();
						}							
            else
						{		Change_Landing_Led();							
						}
						break;
						
						
				case ROAD_OCCUPY:
           if(Irrupt) 
						{		
								Send_Warning();
								Change_Warning_Led();
						}							
            else
						{		Change_Occupy_Led();							
						}
						break;
						
						
						
						
        case NOTHING:
            if(Irrupt) 
						{									
								Change_Occupy_Led();
						}							
            else
						{		Change_Nothing_Led();							
						}
            break;
        
    }
	}
}
