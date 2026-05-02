#include "input_capture_mode_handlers.h"
#include "timer_setup.h"
#include "variables.h"


void setup() {
  Serial.begin(115200);
  delay(1000);

  timer_setup();

  // put your setup code here, to run once:
}

void loop() {
  Serial.print("Channel_1:");
  Serial.print(channel_1);
  Serial.print("\tChannel_2:");
  Serial.print(channel_2);
  Serial.print("\tChannel_3:");
  Serial.print(channel_3);
  Serial.print("\tChannel_4:");
  Serial.println(channel_4);
  
  // put your main code here, to run repeatedly:
}
