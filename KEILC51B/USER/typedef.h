#ifndef _TYPEDEF_H_
#define _TYPEDEF_H_
/*******************Include***********************/

/*********************End*************************/
/********************Define***********************/
typedef unsigned char   u8;
typedef unsigned int    u16;
#define FOSC 22118400L          //系统频率
typedef unsigned char BYTE;
typedef unsigned int WORD;
typedef struct 
{
	u8 ST;
	u8  sss;
	u8 PSA;
	u8  CS; 
	u8  AA;
	u16 FS;
	u8  PD;
}sys_para;
typedef struct 
{
	u8 DETB;
	u8 DETC;
	u8 WARN;
}Slaver_State;
/*********************End*************************/
/********************Extern***********************/


/*********************End*************************/
#endif
/**End**/