/*
 * sofware_Timer.c
 *
 *  Created on: Apr 6, 2024
 *      Author: banban
 */

#include "sofware_Timer.h"
#define TICK	10;

int timer1_counter = 0;
int timer1_flag = 0;


void setTimer1(int duration){
	timer1_counter =  duration / TICK;
	timer1_flag = 0;

}

void timerRun(){
	if(timer1_counter > 0){
		timer1_counter--;
		if(timer1_counter <= 0){
			timer1_flag = 1;
		}
	}
}
