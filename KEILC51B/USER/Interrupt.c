#include "main.h"

bit usart1_busy;
bit usart3_busy;
extern u8 Rec_Buff[8];
extern u8 Rec_Len;
extern u8 Rec_Finish;
/***********************************************************************************************
*函数名 ： void Uart() interrupt 4  
*函数功能描述 ：主机串口接收中断 
*函数参数 ： NONE
*函数返回值 ： void
*作者 ：WangR
*函数创建日期 ： 20190106
*函数修改日期 ： --
*修改人 ：--
*修改原因 ： --
*版本 ： 1.0
*历史版本 ： --
***********************************************************************************************/
void Uart() interrupt 4   //串口接收解码
{
    if (RI)
    {
				
				if(Rec_Finish == False)
				{
					T4T3M &= ~0x02;                 //定时器3为12T模式
					T3L = 35536;                 //初始化计时值 
					T3H = 35536 >> 8;
					T4T3M |= 0x08;                  //定时器3开始计时
					IE2 |= 0x20;                    //开定时器3中断
				
					Rec_Buff[Rec_Len] = SBUF;
					Rec_Len ++; 
					if(Rec_Len == 8)
					{
						if(Rec_Buff[0] == 0xa5 && Rec_Buff[1] == 0xa5)
						{
							Rec_Len = 0;
							Rec_Finish = True;
							T4T3M &= ~0x08;
							IE2 &= ~0x20;   //关定时器3中断
						}
						else
						{
							memset(Rec_Buff , 0 , sizeof(Rec_Buff));
							Rec_Len = 0;
							Rec_Finish = False;
							T4T3M &= ~0x08;
							IE2 &= ~0x20;   //关定时器3中断
						}
					}
				}
        RI = 0;                 //清除RI位
    }
    if (TI)
    {
        TI = 0;                 //清除TI位
				usart1_busy = 0;
    }
}
/***********************************************************************************************
*函数名 ： void Uart3() interrupt 17
*函数功能描述 ：从机串口接收中断 
*函数参数 ： NONE
*函数返回值 ： void
*作者 ：WangR
*函数创建日期 ： 20190106
*函数修改日期 ： --
*修改人 ：--
*修改原因 ： --
*版本 ： 1.0
*历史版本 ： --
***********************************************************************************************/
void Uart3() interrupt 17
{
    if (S3CON & S3RI)
    {
        S3CON &= ~S3RI;         //清除S3RI位
    }
    if (S3CON & S3TI)
    {
        S3CON &= ~S3TI;         //清除S3TI位
			  usart3_busy = 0;
    }
}
/***********************************************************************************************
*函数名 ： void t3int() interrupt 19 
*函数功能描述 ：定时器3中断
*函数参数 ： NONE
*函数返回值 ： void
*作者 ：WangR
*函数创建日期 ： 20190106
*函数修改日期 ： --
*修改人 ：--
*修改原因 ： --
*版本 ： 1.0
*历史版本 ： --
***********************************************************************************************/
void t3int() interrupt 19           //中断入口
{
	IE2 &= ~0x20;                   //若需要手动清除中断标志,可先关闭中断,此时系统会自动清除内部的中断标志
	T4T3M &= ~0x08;
 	Rec_Len = 0;
	Rec_Finish = False; 
	memset(Rec_Buff , 0 , sizeof(Rec_Buff));	

}