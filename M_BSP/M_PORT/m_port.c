#include "m_port.h"
#include "m_scheduler.h"

/**
  ******************************************************************************
  * @file    port
  * @author  JQ ->>https://github.com/lvring
  * @brief   需要实现的函数
  * @version V1.0 2019/4/15 
	* @History V1.0 创建
  ******************************************************************************
  */


void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}
void assert_failed(u8* file, u32 line)
{
    /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
    /* Infinite loop */
    printf("assert failed at %s:%d \n", file, line);
    while (1) {
    }
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */


void _putchar(char character)
{
	Com_Send(COM_1,(uint8_t *)&character,1);
	//HAL_UART_Transmit(&UartHandle[USART_DEBUG].UartHalHandle,(uint8_t *)&character,1,0xFFFFFFFF);
}


void SysTick_Handler(void)
{
	SchedulerSysTickIntHandler();
}


