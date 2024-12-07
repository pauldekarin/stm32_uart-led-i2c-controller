/* USER CODE BEGIN Header */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "i2c.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define DEFAULT_IO_TIMEOUT 10
#define SLAVE_ADDR 0xA0
#define MEM_ADDR 0x00
#define NUM_BYTES 128
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */
void UART_Read(uint8_t*, uint16_t);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */
  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */
  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */
  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART1_UART_Init();
  MX_I2C1_Init();
  MX_TIM3_Init();
  /* USER CODE BEGIN 2 */
  

  uint8_t pData[128];
  uint16_t pSize = sizeof(pData);

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while(1){
    if(__HAL_UART_GET_FLAG(&huart1, UART_FLAG_RXNE)){
        memset(pData, 0, pSize);
        UART_Read(pData, pSize);
        
        if(strncmp((char*)pData, "on led1", 7) == 0){
          HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
          printf("ON LED1\n");
        }
        else if(strncmp((char*)pData, "off led1", 8) == 0)
        { 
          HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
          printf("OFF LED1\n");
        }
        else if(strncmp((char*)pData, "on led2", 7) == 0)
        {
          HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
          for(uint32_t i = 0; i < htim3.Init.Period; i++){
            __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, i);
            HAL_Delay(5);
          }
          printf("ON LED2(PWM)\n");
        }
        else if(strncmp((char*)pData, "off led2", 8) == 0)
        {
          for(uint32_t i = __HAL_TIM_GET_COMPARE(&htim3, TIM_CHANNEL_1); i > 0; --i){
            __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, i);
            HAL_Delay(5);
          }
          HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_1);
          printf("OFF LED2(PWM)\n");
        }
        else if(strncmp((char*)pData, "read i2c", 8) == 0){
          uint8_t i2c_buffer[128];
          HAL_StatusTypeDef status = HAL_I2C_Mem_Read(&hi2c1, SLAVE_ADDR,MEM_ADDR, I2C_MEMADD_SIZE_8BIT, i2c_buffer, NUM_BYTES, DEFAULT_IO_TIMEOUT);

          if(status == HAL_OK){
           HAL_UART_Transmit(&huart1, i2c_buffer, 128, DEFAULT_IO_TIMEOUT);
          }
        }
        else
        {
          char mData[11 + strlen((char*)pData)];
          sprintf(mData, "unknown: %s\n", (char*)pData);
          printf(mData);
        }
    }
    HAL_Delay(1000);
  }
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
PUTCHAR_PROTOTYPE
{
  HAL_UART_Transmit(&huart1, (uint8_t *)&ch, 1, DEFAULT_IO_TIMEOUT);

  return ch;
}

void UART_Read(uint8_t *str, uint16_t size){
  if(str == NULL) return;
  for(uint16_t read_bytes = 0; read_bytes < size && HAL_UART_Receive(&huart1, str, 1, DEFAULT_IO_TIMEOUT) == HAL_OK && *str; str++, read_bytes++);
}

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
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
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
