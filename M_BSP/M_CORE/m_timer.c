#include "m_timer.h"
#include "m_scheduler.h"





/*************************************************
*** Args:   NULL
*** Function: M_Timer初始化（初始化DWT）
*************************************************/
void M_Timer_Init(void)
{
#ifndef RTE_Compiler_EventRecorder
	/* Enable TRC */
	CoreDebug->DEMCR &= ~0x01000000;
	CoreDebug->DEMCR |=  0x01000000;
	/* Enable counter */
	DWT->CTRL &= ~0x00000001;
	DWT->CTRL |=  0x00000001;
	/* Reset counter */
	DWT->CYCCNT = 0;	
	/* 2 dummys */
	__ASM volatile ("NOP");
	__ASM volatile ("NOP");
#endif
}

/*************************************************
*** Args:   Delay
					Null
*** Function: 延时一段毫秒
*************************************************/
void M_DelayMS(uint32_t Delay) {
	/* Delay for amount of milliseconds */
	/* Check if we are called from ISR */
	if (__get_IPSR() == 0) {
		/* Called from thread mode */
		uint32_t tickstart = SchedulerTickCountGet();
		/* Count interrupts */
		while ((SchedulerTickCountGet() - tickstart) < Delay) {
			/* Go sleep, wait systick interrupt */
			__WFI();
		}
	} else {
		/* Called from interrupt mode */
		while (Delay) {
			/* Check if timer reached zero after we last checked COUNTFLAG bit */
			if (SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk) {
				Delay--;
			}
		}
	}
}


/*************************************************
*** Args:   micros 微秒
*** Function: 延时微秒，不影响系统调度
*************************************************/
__inline void M_DelayUS(volatile uint32_t micros) {
	uint32_t start = DWT->CYCCNT;
	/* Go to number of cycles for system */
	micros *= (SystemCoreClock / 1000000);
	/* Delay till end */
	while ((DWT->CYCCNT - start) < micros);
}




