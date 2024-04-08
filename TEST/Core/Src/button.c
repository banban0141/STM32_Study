/*
 * button.c
 *
 *  Created on: Apr 7, 2024
 *      Author: banba
 */
#include "button.h"



int KeyReg0 = NORMAL_STATE;
int KeyReg1 = NORMAL_STATE;
int KeyReg2 = NORMAL_STATE;

int KeyReg3 = NORMAL_STATE;
int TimerForKeyPress = 200;
int button1_flag = 0;

int isButton1Press(){
	if (button1_flag == 1){
		button1_flag = 0;
		return 1;
	}
	else return 0;
}
void subKeyProcess(){
	button1_flag = 1;
}

void getKeyInput(){
	KeyReg0 = KeyReg1;
	KeyReg1 = KeyReg2;
	KeyReg2 = HAL_GPIO_ReadPin(Button1_GPIO_Port, Button1_Pin);

	if((KeyReg0 == KeyReg1)&&(KeyReg2 == KeyReg1)){
		if(KeyReg3 != KeyReg2){
			KeyReg3 = KeyReg2;
			if(KeyReg2 == PRESSED_STATE){
				//TO DO WHEN BUTTON CLICK
				subKeyProcess();
				HAL_GPIO_TogglePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin);
				TimerForKeyPress = 200;

			}
		}
		else {
			TimerForKeyPress--;
			if(TimerForKeyPress == 0){
				// TO DO WHEN PRESS OVER 2000ms
				if(KeyReg2 == PRESSED_STATE){
				subKeyProcess();
				}
				TimerForKeyPress = 200;
			}
		}
	}
}

