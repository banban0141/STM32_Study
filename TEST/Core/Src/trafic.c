/*
 * trafic.c
 *
 *  Created on: Apr 7, 2024
 *      Author: banba
 */
#include "trafic.h"
#include "main.h"
#include "stm32f1xx_hal.h"

void trafic_RED(){
	  HAL_GPIO_WritePin(LED_RED_GPIO_Port,LED_RED_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(LED_GREEN_GPIO_Port,LED_GREEN_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(LED_YELOW_GPIO_Port,LED_YELOW_Pin, GPIO_PIN_SET);
}
void trafic_YELLOW(){
	  HAL_GPIO_WritePin(LED_RED_GPIO_Port,LED_RED_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(LED_GREEN_GPIO_Port,LED_GREEN_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(LED_YELOW_GPIO_Port,LED_YELOW_Pin, GPIO_PIN_RESET);
}
void trafic_GREEN(){
	  HAL_GPIO_WritePin(LED_RED_GPIO_Port,LED_RED_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(LED_GREEN_GPIO_Port,LED_GREEN_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(LED_YELOW_GPIO_Port,LED_YELOW_Pin, GPIO_PIN_SET);
}
//	  switch(status){
//	  	  case 1:
//				trafic_RED();
//				if (timer1_flag==1){
//					setTimer1(1500);
//					status = 2;
//				}
//	  		  break;
//	  	  case 2:
//		  		trafic_GREEN();
//				if (timer1_flag==1){
//					setTimer1(1000);
//					status = 3;
//				}
//	  		  break;
//	  	  case 3:
//		  		trafic_YELLOW();
//		  		if (timer1_flag==1){
//		  			setTimer1(2000);
//		  			status = 1;
//		  		}
//	  		  break;
//	  	  default:
//	  		  break;
//	  }


