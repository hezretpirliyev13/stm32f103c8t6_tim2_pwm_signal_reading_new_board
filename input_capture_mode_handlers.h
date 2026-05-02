#ifndef _INPUT_CAPTURE_MODE_HANDLERS_H
#define _INPUT_CAPTURE_MODE_HANDLERS_H

#include "variables.h"

void handler_channel_1(void) {
  if (0b1 & GPIOA->IDR >> 0) {
    channel_1_start = TIM2->CCR1;
    TIM2->CCER |= TIM_CCER_CC1P;
  } else {
    channel_1 = TIM2->CCR1 - channel_1_start;
    if (channel_1 < 0) channel_1 += 0xFFFF;
    TIM2->CCER &= ~TIM_CCER_CC1P;
  }
}
void handler_channel_2(void) {
  if (0b1 & GPIOA->IDR >> 1) {
    channel_2_start = TIM2->CCR2;
    TIM2->CCER |= TIM_CCER_CC2P;
  } else {
    channel_2 = TIM2->CCR2 - channel_2_start;
    if (channel_2 < 0) channel_2 += 0xFFFF;
    TIM2->CCER &= ~TIM_CCER_CC2P;
  }
}
void handler_channel_3(void) {
  if (0b1 & GPIOA->IDR >> 2) {
    channel_3_start = TIM2->CCR3;
    TIM2->CCER |= TIM_CCER_CC3P;
  } else {
    channel_3 = TIM2->CCR3 - channel_3_start;
    if (channel_3 < 0) channel_3 += 0xFFFF;
    TIM2->CCER &= ~TIM_CCER_CC3P;
  }
}
void handler_channel_4(void) {
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