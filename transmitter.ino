#include <IRremote.h>

#define TX_pin 1

IRsend irsend;

void setup() {
  // Initialize the Serial communication
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    String message = Serial.readString();

    if (message == "on") {
      // Send the IR signal for "ON" (modify with your specific IR codes)
      unsigned int rawData[] = {4500, 4500, 560, 560, 560, 1690, 560, 1690,
                                  560, 560, 560, 560, 560, 560, 560, 560,
                                  560, 1690, 560, 1690, 560, 1690, 560, 1690,
                                  560, 560, 560, 560, 560, 1690, 560, 560,
                                  560, 560, 560, 1690, 560, 560, 560, 1690,
                                  560, 560, 560, 560, 560, 1690, 560, 560,
                                  560, 560, 560, 1690, 560, 560, 560, 560,
                                  560, 1690, 560, 1690, 560, 560, 560, 560,
                                  560, 560, 560, 560, 560, 560, 560, 560,
                                  560, 560, 560, 560, 560, 560, 560, 560};
      irsend.sendRaw(rawData, sizeof(rawData) / sizeof(rawData[0]), 38); // 38kHz carrier frequency
      digitalWrite(TX_pin, HIGH);
      delay(50); // Optional delay to prevent multiple sends for a single message
    }
  }
}





