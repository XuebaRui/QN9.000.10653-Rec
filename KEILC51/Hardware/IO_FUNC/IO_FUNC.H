#ifndef _IO_FUNC_H_
#define _IO_FUNC_H_
/*******************Include***********************/
#include "STC15F2K60S2.H"
#include "intrins.h"
#include "typedef.h"
/*********************End*************************/
/********************Define***********************/
sbit ST = P7^6;  //自检
sbit STY = P2^4; //自检
sbit PSA = P7^7; //陷波
sbit SSS0 = P2^3;// 自检源频段开关
sbit SSS1 = P2^2;// 自检源频段开关
sbit CS0 = P6^2; // 通道频段开关
sbit CS0_n = P5^2;
sbit CS1_n = P0^4;
sbit CS1 = P6^3; // 通道频段开关
sbit S1Y = P4^4; // 380-520/420-700
sbit S1N = P2^0; //
sbit S2Y1 = P3^3;//700-1100/1100-1500/1500-
sbit S2N1 = P3^4;
sbit S2Y2 = P4^3;
sbit S2N2 = P4^2;
sbit S3Y = P7^5; //V1
sbit S3N = P7^4; //V1
sbit S4_1 = P3^5;//6-10
sbit S4_2 = P3^6;//12-18
sbit S4_3 = P3^7;//9.5-12
sbit GJ = P1^1; 
sbit A1_0_5dB  = P5^5;
sbit A1_1dB = P5^4;
sbit A1_2dB = P1^7;
sbit A1_4dB = P1^6;
sbit A1_8dB = P1^5;
sbit A1_16dB = P1^4;
sbit A1_15dB = P2^1;

sbit A2_0_5dB = P3^2;
sbit A2_1dB = P4^0;
sbit A2_2dB = P6^5;
sbit A2_4dB = P6^7;
sbit A2_8dB = P6^6;
sbit A2_16dB = P6^4;
sbit A2_15dB = P4^7;

sbit A3_5dB = P2^7;
sbit A3_10dB = P2^6;
sbit A3_15dB = P2^5;

sbit A4_5dB = P6^1;
sbit A4_10dB = P6^0;
sbit A4_15dB = P0^7;

sbit PDA = P7^3;
sbit PDB = P4^1;
sbit PDC = P1^0;
sbit PDD = P5^0;

sbit LED1 = P7^0;
sbit LED2 = P5^1;
sbit LED3 = P7^1;
sbit LED4 = P7^2;
/*********************End*************************/
/********************Extern***********************/
/*********************End*************************/
void IO_init(void);
#endif
/**End**/