#include "adc.h"
void Delay(WORD n)
{
    WORD x;

    while (n--)
    {
        x = 5000;
        while (x--);
    }
}
void InitADC(void)
{
    P1ASF = 0x0e;                   
    ADC_RES = 0;                   
    ADC_CONTR = ADC_POWER | ADC_SPEEDLL;
    Delay(2);                       
}
u16 GetADCResult(BYTE ch)
{
    ADC_CONTR = ADC_POWER | ADC_SPEEDLL | ch | ADC_START;
    _nop_();                        
    _nop_();
    _nop_();
    _nop_();
    while (!(ADC_CONTR & ADC_FLAG));
    ADC_CONTR &= ~ADC_FLAG;         //Close ADC
    return (((u16)ADC_RES) << 2) | ADC_RESL;            
}
u16 Adc_Filter(BYTE ch)
{
	u16 adc_val[12],temp =0;
	u16 adc_val_sum = 0;
	u8 i = 0,j=0;
	for(i = 0 ;i < 12 ; i++)
	{
		adc_val[i] = GetADCResult(ch);
	}
	for(i = 0 ;i < 12 - 1 ; i++)
	{
		for(j = 0 ;j < 12 - 1 - i ; j++)
		{
			if(adc_val[j] > adc_val[j+1])
			{
				temp = adc_val[j];
				adc_val[j] = adc_val[j + 1];
				adc_val[j + 1] = temp;
			}
		}
	}
	for(i = 1; i < 11 ;i ++)
	{
		adc_val_sum += adc_val[i];
	}
	return adc_val_sum / 10;
}