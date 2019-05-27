#ifndef _IO_FUNC_H_
#define _IO_FUNC_H_
/*******************Include***********************/
#include "STC15F2K60S2.H"
#include "intrins.h"
#include "typedef.h"
/*********************End*************************/
/********************Define***********************/
sbit ST = P7^6;  //自检
sbit STY = P2^3; //自检
sbit PSA = P7^5; //陷波
sbit SSS0 = P7^3;// 自检源频段开关
sbit SSS1 = P7^2;// 自检源频段开关
sbit CS0 = P4^0; // 通道频段开关
//sbit CS0_n = P5^2;
//sbit CS1_n = P0^4;
sbit CS1 = P6^4; // 通道频段开关
sbit S1Y = P7^7; // 380-520/420-700
sbit S1N = P4^5; //
sbit S2Y1 = P4^6;//700-1100/1100-1500/1500-
sbit S2N1 = P0^2;
sbit S2Y2 = P5^4;
sbit S2N2 = P1^7;
sbit S3Y = P2^5; //V1
sbit S3N = P2^4; //V1
sbit S4_1 = P4^2;//6-10
sbit S4_2 = P4^3;//12-18
sbit S4_3 = P4^4;//9.5-12
sbit GJ = P6^5; 
sbit A1_0_5dB  = P5^3;
sbit A1_1dB = P0^5;
sbit A1_2dB = P0^6;
sbit A1_4dB = P0^7;
sbit A1_8dB = P6^0;
sbit A1_16dB = P6^1;
sbit A1_15dB = P6^2;

sbit A2_0_5dB = P6^3;
sbit A2_1dB = P1^0;
sbit A2_2dB = P1^1;
sbit A2_4dB = P4^7;
sbit A2_8dB = P1^4;
sbit A2_16dB = P1^5;
sbit A2_15dB = P1^6;

sbit A3_5dB = P2^6;
sbit A3_10dB = P2^7;
sbit A3_15dB = P7^4;

sbit A4_5dB = P3^2;
sbit A4_10dB = P6^7;
sbit A4_15dB = P6^6;

sbit PDA = P5^2;
sbit PDB = P0^3;
sbit PDC = P5^5;
sbit PDD = P0^4;
/*********************End*************************/
/********************Extern***********************/
/*********************End*************************/
void IO_init(void);
#endif
/**End**/