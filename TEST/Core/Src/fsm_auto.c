/*
 * fsm_auto.c
 *
 *  Created on: Apr 9, 2024
 *      Author: banba
 */

#include "fsm_auto.h"
#include "trafic.h"

void fsm_autorun(){
	switch(status){
	case INIT:
		HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_YELOW_GPIO_Port, LED_YELOW_Pin, GPIO_PIN_SET);
		status = AUTO_RED;
		setTimer1(3000);
		break;
	case AUTO_RED:
		trafic_RED();
		if (timer1_flag == 1){
			status = AUTO_GREEN;
			setTimer1(2000);
		}
		if (isButton1Press() ==1){
			status = MAN_RED;
			setTimer1(5000);
		}

		break;
	case AUTO_GREEN:
		trafic_GREEN();
		if (timer1_flag == 1){
			status = AUTO_YELLOW;
			setTimer1(1000);
		}
		if (isButton1Press() ==1){
			status = MAN_RED;
			setTimer1(5000);
		}

		break;
	case AUTO_YELLOW:
		trafic_YELLOW();
		if (timer1_flag == 1){
			status = AUTO_RED;
			setTimer1(3000);
		}
		if (isButton1Press() ==1){
			status = MAN_RED;
			setTimer1(5000);
		}

		break;
	default:
		break;
	}
}
