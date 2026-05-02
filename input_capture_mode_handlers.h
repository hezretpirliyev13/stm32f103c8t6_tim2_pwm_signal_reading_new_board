#ifndef _INPUT_CAPTURE_MODE_HANDLERS_H
#define _INPUT_CAPTURE_MODE_HANDLERS_H

#include "variables.h"

void handler_channel_1(void) {
  if (0b1 & GPIOA->IDR >> 0) {                //PA0 is HIGH?
    channel_1_start = TIM2->CCR1;             //Assigning TIM2 Counter value to the channel_1_start
    TIM2->CCER |= TIM_CCER_CC1P;              //Capture/compare enable reg is CC1 is rising edge
  } else {                                    //PA0 is LOW
    channel_1 = TIM2->CCR1 - channel_1_start;  //counter value-channel_1_start = 
    if (channel_1 < 0) channel_1 += 0xFFFF;    //when counter reaches 65535 then it will reset and channel_1 will be minus value and we need to add 65 535
    TIM2->CCER &= ~TIM_CCER_CC1P;              //capture/compare reg is cc1 is falling edge
  }
}
void handler_channel_2(void) {                  //PA1
  if (0b1 & GPIOA->IDR >> 1) {
    channel_2_start = TIM2->CCR2;
    TIM2->CCER |= TIM_CCER_CC2P;
  } else {
    channel_2 = TIM2->CCR2 - channel_2_start;
    if (channel_2 < 0) channel_2 += 0xFFFF;
    TIM2->CCER &= ~TIM_CCER_CC2P;
  }
}
void handler_channel_3(void) {                  //PA2
  if (0b1 & GPIOA->IDR >> 2) {
    channel_3_start = TIM2->CCR3;
    TIM2->CCER |= TIM_CCER_CC3P;
  } else {
    channel_3 = TIM2->CCR3 - channel_3_start;
    if (channel_3 < 0) channel_3 += 0xFFFF;
    TIM2->CCER &= ~TIM_CCER_CC3P;
  }
}
void handler_channel_4(void) {                    //PA3
  if (0b1 & GPIOA->IDR >> 3) {
    channel_4_start = TIM2->CCR4;
    TIM2->CCER |= TIM_CCER_CC4P;
  } else {
    channel_4 = TIM2->CCR4 - channel_4_start;
    if (channel_4 < 0) channel_4 += 0xFFFF;
    TIM2->CCER &= ~TIM_CCER_CC4P;
  }
}
#endif
