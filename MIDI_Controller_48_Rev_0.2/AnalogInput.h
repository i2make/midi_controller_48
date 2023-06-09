#ifndef MIDI_ANALOGINPUT_H
#define MIDI_ANALOGINPUT_H

#include <Arduino.h>
#include <avr/pgmspace.h>
#include <EEPROM.h>
#include "midiCC_config.h"

class AnalogInput {
public:
    unsigned char current;           // 0 ~ 127
    unsigned char previous;          // 0 ~ 127
    unsigned char channelNumber;    // 0 ~ 15
    unsigned char controlNumber;    // 0 ~ 127
};


void readEEPROM(unsigned char preset);
void factoryInitialization();

extern AnalogInput pot[USING_BOARD][16];

#endif //MIDI_ANALOGINPUT_H
