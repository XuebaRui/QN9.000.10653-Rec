#include "usart.h"

/***********************************************************************************************
*函数名 ： void MasterUsart_Init(u16 bps)
*函数功能描述 ：初始化主机串口 
*函数参数 ： BPS-波特率
*函数返回值 ： void
*作者 ：WangR
*函数创建日期 ： 20190106
*函数修改日期 ： --
*修改人 ：--
*修改原因 ： --
*版本 ： 1.0
*历史版本 ： --
***********************************************************************************************/
void MasterUsart_Init(u16 bps)
{
	  ACC = P_SW1;
    ACC &= ~(S1_S0 | S1_S1);    //S1_S0=0 S1_S1=0
    P_SW1 = ACC;                //(P3.0/RxD, P3.1/TxD)
    
		SCON = 0x50;		//8位数据,可变波特率
		AUXR |= 0x40;		//定时器1时钟为Fosc,即1T
		AUXR &= 0xFE;		//串口1选择定时器1为波特率发生器
		TMOD &= 0x0F;		//设定定时器1为16位自动重装方式
		TL1 = 0xD0;		//设定定时初值
		TH1 = 0xFF;		//设定定时初值
		ET1 = 0;		//禁止定时器1中断
	  ES = 1;     //使能串口中断
		TR1 = 1;		//启动定时器1
}
/***********************************************************************************************
*函数名 ： void MasterUsart_SendByte(u8 byte)
*函数功能描述 ： 主机串口发送一个字节
*函数参数 ： byte--发送数据
*函数返回值 ： void
*作者 ：WangR
*函数创建日期 ： 20190106
*函数修改日期 ： --
*修改人 ：--
*修改原因 ： --
*版本 ： 1.0
*历史版本 ： --
***********************************************************************************************/
void MasterUsart_SendByte(u8 byte)
{
    while (usart1_busy);               //等待前面的数据发送完成
    ACC = byte;                  //获取校验位P (PSW.0)
    if (P)                      //根据P来设置校验位
    {
#if (PARITYBIT == ODD_PARITY)
				TB8 = 0;                //设置校验位为0
#elif (PARITYBIT == EVEN_PARITY)
				TB8 = 1;                //设置校验位为1
#endif
		}
		else
		{
#if (PARITYBIT == ODD_PARITY)
				TB8 = 1;                //设置校验位为1
#elif (PARITYBIT == EVEN_PARITY)
				TB8 = 0;                //设置校验位为0
#endif
		}
    usart1_busy = 1;
    SBUF = ACC;                 //写数据到UART数据寄存器
}
/***********************************************************************************************
*函数名 ： void void MasterUsart_SendBuf(sys_para rtn_para,unsigned long int det)
*函数功能描述 ： 
*函数参数 ： 
*函数返回值 ： void
*作者 ：WangR
*函数创建日期 ： 20190115
*函数修改日期 ： --
*修改人 ：--
*修改原因 ： --
*版本 ： 1.0
*历史版本 ： --
***********************************************************************************************/
void MasterUsart_SendBuf(sys_para rtn_para, Slaver_State rtn_state)
{
	MasterUsart_SendByte(0xa5);
	MasterUsart_SendByte(0xa5);
	MasterUsart_SendByte((rtn_para.ST << 7) | (rtn_para.sss << 5) | rtn_para.CS);
	MasterUsart_SendByte((rtn_para.AA << 5) | ((rtn_para.FS&0x0f00) >> 8));
	MasterUsart_SendByte( rtn_para.FS & 0x00ff );
	MasterUsart_SendByte((rtn_para.Pow_Warning << 4) | (rtn_para.PD ));
	MasterUsart_SendByte(rtn_para.DETA);
	MasterUsart_SendByte(rtn_state.DETB);
	MasterUsart_SendByte(rtn_state.DETC);
	MasterUsart_SendByte(rtn_para.DETD);
	MasterUsart_SendByte(0x5a);
	MasterUsart_SendByte(0x5a);
}
/***********************************************************************************************
*函数名 ： void SlaverUsart_Init(u16 bps)
*函数功能描述 ：初始化从机串口 
*函数参数 ： BPS-波特率
*函数返回值 ： void
*作者 ：WangR
*函数创建日期 ： 20190106
*函数修改日期 ： --
*修改人 ：--
*修改原因 ： --
*版本 ： 1.0
*历史版本 ： --
***********************************************************************************************/
void SlaverUsart_Init(u16 bps)
{

    P_SW2 &= ~S3_S0;            //S3_S0=0 (P0.0/RxD3, P0.1/TxD3)
//  P_SW2 |= S3_S0;             //S3_S0=1 (P5.0/RxD3_2, P5.1/TxD3_2)

#if (PARITYBIT == NONE_PARITY)
    S3CON = 0x10;               //8位可变波特率
#elif (PARITYBIT == ODD_PARITY) || (PARITYBIT == EVEN_PARITY) || (PARITYBIT == MARK_PARITY)
    S3CON = 0x9a;               //9位可变波特率,校验位初始为1
#elif (PARITYBIT == SPACE_PARITY)
    S3CON = 0x92;               //9位可变波特率,校验位初始为0
#endif

    T2L = 0xd0;   //设置波特率重装值
    T2H = 0xff;
    AUXR |= 0x14;                //T2为1T模式, 并启动定时器2
    IE2 |= 0x08;                 //使能串口3中断
    EA = 1;

}
/***********************************************************************************************
*函数名 ： void SlaverUsart_SendByte(u8 byte)
*函数功能描述 ： 从机串口发送一个字节
*函数参数 ： byte--发送数据
*函数返回值 ： void
*作者 ：WangR
*函数创建日期 ： 20190106
*函数修改日期 ： --
*修改人 ：--
*修改原因 ： --
*版本 ： 1.0
*历史版本 ： --
***********************************************************************************************/
void SlaverUsart_SendByte(u8 byte)
{
	  while (usart3_busy);               //等待前面的数据发送完成
    ACC = byte;                  //获取校验位P (PSW.0)
    if (P)                      //根据P来设置校验位
    {
#if (PARITYBIT == ODD_PARITY)
        S3CON &= ~S3TB8;        //设置校验位为0
#elif (PARITYBIT == EVEN_PARITY)
        S3CON |= S3TB8;         //设置校验位为1
#endif
    }
    else
    {
#if (PARITYBIT == ODD_PARITY)
        S3CON |= S3TB8;         //设置校验位为1
#elif (PARITYBIT == EVEN_PARITY)
        S3CON &= ~S3TB8;        //设置校验位为0
#endif
    }
    usart3_busy = 1;
    S3BUF = ACC;                //写数据到UART3数据寄存器
}
/***********************************************************************************************
*函数名 ： void SlaverUsart_SendBuf(unsigned char Rec_Data[8])
*函数功能描述 ： 
*函数参数 ： 
*函数返回值 ： void
*作者 ：WangR
*函数创建日期 ： 20190115
*函数修改日期 ： --
*修改人 ：--
*修改原因 ： --
*版本 ： 1.0
*历史版本 ： --
***********************************************************************************************/
void SlaverUsart_SendBuf(unsigned char Rec_Data[8])
{
	unsigned char i = 0;
	for(i = 0 ; i < 8 ; i++)
	{
		SlaverUsart_SendByte(Rec_Data[i]);
	}
}

