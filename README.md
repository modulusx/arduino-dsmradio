# arduino-dsmradio
Arduino Library implementing the DSM Serial protocol to enable MLP4DSM or DX4e radio support.

## Minimum hardware requirements
- Arduino with 3.3v power
- mlp4dsm or dx4e/dx5e DSM Radio from Spektrum Controller

## DSM Radio protocol settings and definiton
The DSM Radio protocol transmits 14-byte frames every 22.5 ms.
- The frame includes a 2-byte header and six 2-byte channels of information.
- The header may be set to 0x80 to bind the transmitter to a new receiver, otherwise it is set to 0.
- Each channel is capable of storing a 10-bit value but actually uses a smaller range.
- Instead of 0-1024, the effective range is closer to 170-852.
- The radio should be connected to the serial TX pin which will be set to 125000 baud.

### mlp4dsm pinout
![alt tag](http://mrkunkel.com/images/dsmmod/pinout_mlp4dsm.jpg)

### dx5e pinout
![alt tag](http://mrkunkel.com/images/dsmmod/pinout_dx5e.jpg)

Here's the [full RCGroups forum thread](http://www.rcgroups.com/forums/showthread.php?t=721024) discussing the DSM Radio protocol and its arduino implementation as a PPM to DSM module.
