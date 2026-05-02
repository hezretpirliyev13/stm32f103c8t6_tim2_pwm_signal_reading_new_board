#ifndef _TIMER_SETUP_H
#define _TIMER_SETUP_H

#include "input_capture_mode_handlers.h"
#include <HardwareTimer.h>
HardwareTimer Timer2(TIM2);

void timer_setup() {
  Timer2.attachInterrupt(1, handler_channel_1);
  Timer2.attachInterrupt(2, handler_channel_2);
  Timer2.attachInterrupt(3, handler_channel_3);
  Timer2.attachInterrupt(4, handler_channel_4);
  TIM2->CR1 = TIM_CR1_CEN;
  TIM2->CR2 = 0;
  TIM2->SMCR = 0;
  TIM2->DIER = TIM_DIER_CC1IE | TIM_DIER_CC2IE | TIM_DIER_CC3IE | TIM_DIER_CC4IE;
  TIM2->EGR = 0;
  TIM2->CCMR1 = 0b100000001;
  TIM2->CCMR2 = 0b100000001;
  TIM2->CCER = TIM_CCER_CC1E | TIM_CCER_CC2E | TIM_CCER_CC3E | TIM_CCER_CC4E;
  TIM2->PSC = 71;
  TIM2->ARR = 0xFFFF;
  TIM2->DCR = 0;

}
#endif