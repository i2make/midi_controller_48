#ifndef MIDI_MIDIFUNCTION_H
#define MIDI_MIDIFUNCTION_H
#include <Arduino.h>
#include <MIDIUSB.h>

// MIDI function
void noteOn(byte channel, byte pitch, byte velocity);

void noteOff(byte channel, byte pitch, byte velocity);

void controlChange(byte channel, byte control, byte value);

void programChange(byte channel, byte value);

void channelPressure(byte channel, byte value);

#endif //MIDI_MIDIFUNCTION_H
