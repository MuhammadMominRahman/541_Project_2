#include <arduino-timer.h>

auto timeoutTimer = timer_create_default();
int timeoutMS = 5000;
Timer<>::Task timeoutHandle;

int flagState = 0;
int bit = 0;
int lastBit = 0;
int val = 0;
int flagTimes[3];

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
  val = analogRead(A1);
  bit = round((float)val/900);
  if (bit != lastBit && flagState < 4) { // if bit has flipped since last sample, and message hasn't started
    flagState++;
    if (flagState != 1) {
      flagTimes[flagState-2] = timeoutTimer.ticks();// save time between flagstate changes
      timeoutTimer.cancel(timeoutHandle); // cancel timeout if flagstate changes, but not when first bit flips
    }
    timeoutHandle = timeoutTimer.in(timeoutMS, TimeoutHandler); // reset timeout timer when flagState changes
  }
  if (flagState == 4) { // received start flag - 1 0 1 0
    // calculate bit rate

  }

  Serial.print("FlagState: ");
  Serial.print(flagState);
  Serial.println();
  Serial.println("times: ");
  for (int i = 0; i < (sizeof(flagTimes)/sizeof(flagTimes[0])); i++) {
    Serial.println(flagTimes[i]);
  }
  Serial.println();

}

bool TimeoutHandler(void *)
{
   flagState = 0;
   return false; // true: repeat the action, false: to stop the task
}