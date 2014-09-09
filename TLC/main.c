/**
  *****************************************************************************
  * @title   SPI_Tansfer.c
  * @author  CooCox
  * @date    31 Oct 2012
  * @brief
  *******************************************************************************
  */
////// The above comment is automatically generated by CoIDE ///////////////////

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"
#include "TLC5940.h"

/* Private functions ---------------------------------------------------------*/
//void LedInit(void);
//void initGPIO(void);
//void initTLC(void);

void LedInit(void)
{
  GPIO_InitTypeDef  GPIO_InitStructure;

  /* Enable the GPIO_LED Clock */
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);

  /* Configure the GPIO_LED pin */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
  GPIO_Init(GPIOD, &GPIO_InitStructure);
}


///**
//  * @}
//  */
//
///**
//  * @}
//  */
//
//#define TLCPORT GPIOA
//#define GSCLK GPIO_Pin_0
//#define SCLK GPIO_Pin_1
//#define SIN GPIO_Pin_2
//#define VPRG GPIO_Pin_3
//#define XLAT GPIO_Pin_4
//#define BLANK GPIO_Pin_5
//#define DCPRG GPIO_Pin_6
//
//void initGPIO(void)
//{
//	GPIO_InitTypeDef  GPIO_InitStructure;
//
//	  /* Enable the GPIO_LED Clock */
//	  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
//
//	  /* Configure the GPIO_LED pin */
//	  GPIO_InitStructure.GPIO_Pin = GSCLK | SCLK | SIN | VPRG | XLAT | BLANK | DCPRG;
//	  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
//	  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
//	  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
//	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
//	  GPIO_Init(TLCPORT, &GPIO_InitStructure);
//}
//
//uint8_t gsData[192] = {
//// MSB LSB
//1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, // Channel 15
//0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, // Channel 14
//0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, // Channel 13
//0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, // Channel 12
//0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, // Channel 11
//0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, // Channel 10
//0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, // Channel 9
//0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, // Channel 8
//0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, // Channel 7
//0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, // Channel 6
//0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, // Channel 5
//0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, // Channel 4
//0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, // Channel 3
//0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, // Channel 2
//1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, // Channel 1
//1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, // Channel 0
//};
//
//void initTLC(void) {
//  GPIO_ResetBits(TLCPORT, GSCLK);
//  GPIO_ResetBits(TLCPORT, SCLK);
//  GPIO_ResetBits(TLCPORT, DCPRG);
//  GPIO_SetBits(TLCPORT, VPRG);
//  GPIO_ResetBits(TLCPORT, XLAT);
//  GPIO_SetBits(TLCPORT, BLANK);
//  //GPIO_SetBits(TLCPORT, SIN);
//}
//
//void runTLCinGS(uint16_t value) {
//
//  GPIO_ResetBits(TLCPORT, VPRG);
//  uint16_t GSCLK_Counter = 0;
//  uint8_t Data_Counter = 0;
//
//  GPIO_ResetBits(TLCPORT, BLANK);
//
//  while(GSCLK_Counter < 4096)
//  {
//    if(Data_Counter < 192)
//    {
//      //set SIN
//      uint16_t temp = (value & 0x0FFF);
//      temp = temp >> (11 - (Data_Counter % 12));
//      temp = temp & 0x0001;
//
//      if(temp){
//        GPIO_SetBits(TLCPORT, SIN);
//      }
//      else{
//    	  GPIO_ResetBits(TLCPORT, SIN);
//      }
//
//      GPIO_SetBits(TLCPORT, SCLK);
//      GPIO_ResetBits(TLCPORT, SCLK);
//      Data_Counter++;
//    }
//    GPIO_SetBits(TLCPORT, GSCLK);
//    GPIO_ResetBits(TLCPORT, GSCLK);
//    GSCLK_Counter++;
//
//  }
//  GPIO_SetBits(TLCPORT, BLANK);
//  GPIO_SetBits(TLCPORT, XLAT);
//  GPIO_ResetBits(TLCPORT, XLAT);
//
//}
void delay (void)
{
	for(uint32_t i = 0; i < 100; i++)
	{

	}
}
int main(void)
{
	SystemInit();
	SystemCoreClockUpdate();

	LedInit();
	//initGPIO();

	//initTLC();

	volatile uint16_t value = 0x0000;

	TLC5940_Init();
	TLC5940_SetAllGS(0x0000);

	int8_t faktor = 1;


#define MAX 4095
#define MIN 2000
    int16_t count = MIN;
    while(1)
    {

    	//TLC5940_SetAllGS(value/1000);
    	for( ;(count <= MAX) && (count >= MIN); count += faktor)
    	{
			TLC5940_SetGS(14, count);
			TLC5940_UpdateGS();

			GPIO_ToggleBits(GPIOD, GPIO_Pin_12 << (value%4));
			value++;
			delay();
    	}
    	faktor = faktor * (-1);
    	if(count > MIN)
    		count--;
    	else
    		count++;
    }

}
