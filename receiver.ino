#include <arduino-timer.h>

auto timeoutTimer = timer_create_default();
int timeoutMS = 1000;
auto timeoutHandle;

int flagState = 0;
int bit = 0;
int lastBit = 0;
int val = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  // max voltage = 4.5
  // min voltage = 0
  timeoutTimer.tick();
  lastBit = bit;
  val = analogRead(A0);
  bit = round((float)val/900);
  if (bit != lastBit && flagState < 4) { // if bit has flipped since last sample, and message hasn't started
    flagState++;
    if (flagState != 1) {
      timeoutHandle.cancel(); // cancel timeout if flagstate changes, but not when first bit flips
    }
    timeoutHandle = timeoutTimer.in(timeoutMS, TimeoutHandler); // reset timeout timer when flagState changes
  }

  Serial.println(bit);
}

bool TimeoutHandler(void *)
{
   flagState = 0;
   return false; // true: repeat the action, false: to stop the task
}