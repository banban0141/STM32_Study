/*
 * button.h
 *
 *  Created on: Apr 7, 2024
 *      Author: banba
 */



#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"
#include "sofware_Timer.h"

#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET

extern int button1_flag;

int isButton1Press();
void getKeyInput();

#endif /* INC_BUTTON_H_ */
