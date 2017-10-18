#include <Arduino.h>
#include "DSMRadio.h"

#define BIND_HEADER 0x80
#define DSMRADIO_CHANNELS 6
#define DSMRADIO_FRAMELEN 14

void DSMRadio::bind(bool rebind) {
  Serial.begin(125000);
  delay(100);
  if (rebind) frame[0] = BIND_HEADER;
  Serial.write(frame,DSMRADIO_FRAMELEN);
  delay(20);
  frame[0]=0;
}

void DSMRadio::send(unsigned int channels[]) {
  for(int c = 0; c < DSMRADIO_CHANNELS; c++) {
    channels[c] = constrain(channels[c], 170, 852);
    frame[2*c+2] = (byte)(c<<2) | highByte(channels[c]);
    frame[2*c+3] = lowByte(channels[c]);
  }
  Serial.write(frame,DSMRADIO_FRAMELEN);
  delay(20);
}
