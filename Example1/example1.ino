#include <DSMRadio.h>

#define BIND_SWITCH_PIN 2
#define NUM_OF_CHANNELS 6

unsigned int channels[NUM_OF_CHANNELS] = {170,511,511,511,852,511};
DSMRadio dsm_tx;

void setup() {
  pinMode(BIND_SWITCH_PIN, INPUT);
  dsm_tx.bind(digitalRead(BIND_SWITCH_PIN)==1);
}

void loop() {
  for(int i=170; i<853; i+=32) {
    channels[0]=i;
    dsm_tx.send(channels);
  }
  for(int i=852; i>169; i-=32) {
    channels[0]=i;
    dsm_tx.send(channels);
  }
  for(int c=1; c<4; c++) {
    for(int i=511; i<853; i+=32) {
      channels[c]=i;
      dsm_tx.send(channels);
    }   
    for(int i=511; i>169; i-=32) {
      channels[c]=i;
      dsm_tx.send(channels);
    }   
    for(int i=170; i<512; i+=32) {
      channels[c]=i;
      dsm_tx.send(channels);
    }   
  }
}
