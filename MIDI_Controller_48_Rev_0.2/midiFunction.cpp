#include "midiFunction.h"


void noteOn(byte channel, byte pitch, byte velocity) {
    midiEventPacket_t noteOn = {0x09, (byte) (0x90u | channel), pitch,
                                velocity};
    MidiUSB.sendMIDI(noteOn);
}

void noteOff(byte channel, byte pitch, byte velocity) {
    midiEventPacket_t noteOff = {0x08, (byte) (0x80u | channel), pitch,
                                 velocity};
    MidiUSB.sendMIDI(noteOff);
}

void controlChange(byte channel, byte control, byte value) {
    midiEventPacket_t controlChange = {0x0B, (byte) (0xB0u | channel), control,
                                       value};
    MidiUSB.sendMIDI(controlChange);
}

void programChange(byte channel, byte value) {
    midiEventPacket_t programChange = {0x0C, (byte) (0xC0u | channel), value};
    MidiUSB.sendMIDI(programChange);
}

void channelPressure(byte channel, byte value) {
    midiEventPacket_t channelPressure = {0x0D, (byte) (0xD0u | channel), value};
    MidiUSB.sendMIDI(channelPressure);
}