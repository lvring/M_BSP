#ifndef __M_PORT_H
#define __M_PORT_H

#include "stm32f1xx_hal.h"
#include "board_uart.h"

void Error_Handler(void);
#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line);
#endif /* USE_FULL_ASSERT */





#endif
