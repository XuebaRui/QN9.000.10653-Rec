#ifndef _TIM_H_
#define _TIM_H_
/*******************Include***********************/
#include "STC15F2K60S2.H"
#include "intrins.h"
#include "typedef.h"
/*********************End*************************/
/********************Define***********************/
#define TIMCntIrq_Disable IE2 &= ~0x20
#define TIMCntIrq_Enable  IE2 |= 0x20

/*********************End*************************/
/********************Extern***********************/


/*********************End*************************/
void TimCnt_Init(u16 cnt) ;

#endif
/**End**/