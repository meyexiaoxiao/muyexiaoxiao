// 点亮一个LED
#include "stm32f10x.h"
void delay(ui); 
int main (void)
{
	#if 0
	//打开GPIOB端口的时钟
	*((unsigned int *)0x40021018) |= (1<< 3);
	
	//配置IO口 CRL   设置输出
//*((unsigned int *)0x40011800) &= ~(0x0f<<(4*5));
	*((unsigned int *)0x40011800) |= (1<<(4*5));

	//配置ODR寄存器
	while(1)
	{
	*(unsigned int *)0x4001180C &= ~(1<<5);
	delay(5000);
	*(unsigned int *)0x4001180C |= (1<<5);
			delay(5000);
	}
	#else
//打开GPIOB端口的时钟
//	RCC_APB2ENR |= (1<< 6);
	
	//配置IO口 CRL   设置输出
//  GPIOE_CRL &= ~(0x0f<<(4*5));
//	GPIOE_CRL |= (1<<(4*5));

	//配置ODR寄存器
	while(1)
	{
	//打开GPIOB端口的时钟
			RCC_APB2ENR |= (1<< 6);
		  GPIOE_CRL &= ~(0x0f<<(4*5));
			GPIOE_CRL |= (1<<(4*5));
			GPIOE_ODR &= ~(1<<5);   //高16位设置0
			delay(5000);
			GPIOE_BSRR |= (1<<5);     //低16位设置1
			delay(5000);
		
//			RCC_APB2ENR &= ~(0x0f<< 6);	
			RCC_APB2ENR |= (1<< 3);
		  GPIOB_CRL &= ~(0x0f<<(4*5));
			GPIOB_CRL |= (1<<(4*5));
			GPIOB_BRR |= (1<<5);   //高16位设置0
			delay(5000);
			GPIOB_BSRR |= (1<<5);     //低16位设置1
			delay(5000);
	}	
	#endif
	
}

void SystemInit(void)
{
		//骗过编译器
}

void delay(ui z)
{
	ui i,j;
	for(i=z;i>0;i--)
		for(j=110;j>0;j--);
}
