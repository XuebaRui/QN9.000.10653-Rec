#ifndef _ADC_H_
#define _ADC_H_
/*******************Include***********************/
#include "STC15F2K60S2.H"
#include "intrins.h"
#include "typedef.h"
/*********************End*************************/
/********************Define***********************/
#define ADC_POWER   0x80            //ADC
#define ADC_FLAG    0x10            //ADC
#define ADC_START   0x08            //ADC
#define ADC_SPEEDLL 0x00            //540
#define ADC_SPEEDL  0x20            //360
#define ADC_SPEEDH  0x40            //180
#define ADC_SPEEDHH 0x60            //90

/*********************End*************************/
/********************Extern***********************/


/*********************End*************************/
void InitADC(void);
u16 Adc_Filter(BYTE ch);
u16 GetADCResult(BYTE ch);
void Delay(WORD n);

#endif