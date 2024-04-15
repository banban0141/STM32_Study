/*
 * fsm_man.c
 *
 *  Created on: Apr 15, 2024
 *      Author: banba
 */

#include "fsm_man.h"

void fsm_man_run(){
	switch (status){
	case MAN_RED:
		trafic_RED();

		if (timer1_flag == 1){
			status = AUTO_RED;
			setTimer1(3000);
		}
		if (isButton1Press() ==1){
			status = MAN_GREEN;
			setTimer1(5000);
		}
		break;
	case MAN_GREEN:
		trafic_GREEN();
		if (timer1_flag == 1){
			status = AUTO_RED;
			setTimer1(3000);
		}
		if (isButton1Press() ==1){
			status = MAN_YELLOW;
			setTimer1(5000);
		}
		break;
	case MAN_YELLOW:
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
