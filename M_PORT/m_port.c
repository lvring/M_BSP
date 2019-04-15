#include "m_port.h"
#include "m_scheduler.h"

/**
  ******************************************************************************
  * @file    port
  * @author  JQ ->>https://github.com/lvring
  * @brief   ��Ҫʵ�ֵĺ���
  * @version V1.0 2019/4/15 
	* @History V1.0 ����
  ******************************************************************************
  */


void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}
#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */


void _putchar(char character)
{
	HAL_UART_Transmit(&UartHandle[USART_DEBUG].UartHalHandle,(uint8_t *)&character,1,0xFFFFFFFF);
}



void SysTick_Handler(void)
{
	SchedulerSysTickIntHandler();
}
