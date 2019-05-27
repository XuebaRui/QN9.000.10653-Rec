#ifndef _USART_H_
#define _USART_H_
/*******************Include***********************/
#include "STC15F2K60S2.H"
#include "intrins.h"
#include "typedef.h"
/*********************End*************************/
/********************Define***********************/
#define NONE_PARITY     0       //无校验
#define ODD_PARITY      1       //奇校验
#define EVEN_PARITY     2       //偶校验
#define MARK_PARITY     3       //标记校验
#define SPACE_PARITY    4       //空白校验

#define PARITYBIT NONE_PARITY   //定义校验位
#define S1_S0 0x40              //P_SW1.6
#define S1_S1 0x80              //P_SW1.7
#define S3_S0 0x02              //P_SW2.1
#define S3RI  0x01              //S3CON.0
#define S3TI  0x02              //S3CON.1
#define S3RB8 0x04              //S3CON.2
#define S3TB8 0x08              //S3CON.3
/*********************End*************************/
/********************Extern***********************/
extern bit usart1_busy;
extern bit usart3_busy;

/*********************End*************************/
void MasterUsart_Init(u16 bps);
void MasterUsart_SendByte(u8 byte);
void SlaverUsart_Init(u16 bps);
void SlaverUsart_SendByte(u8 byte);
void MasterUsart_SendBuf(Slaver_State rtn_state);
#endif
/**End**/