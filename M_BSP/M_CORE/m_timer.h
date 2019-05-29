#ifndef __M_TIMER_H
#define __M_TIMER_H

#include "stm32f10x.h"


void M_Timer_Init(void);
void M_DelayMS(uint32_t Delay);
__inline void M_DelayUS(volatile uint32_t micros);



#endif
