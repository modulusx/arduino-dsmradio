#ifndef DSMRadio_h
#define DSMRadio_h

#include "WProgram.h"

#define DSMRADIO_CHANNELS 6
#define DSMRADIO_FRAME_LEN 14

class DSMRadio {
  public:
    void bind(bool rebind);
    void send(unsigned int channels[DSMRADIO_CHANNELS]);
  private:
    byte frame[DSMRADIO_FRAME_LEN];
};
#endif
