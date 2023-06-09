#include "AnalogInput.h"

void readEEPROM(unsigned char preset) {
    int eepromAddress = preset * 128; // preset 0 ~ 3
    unsigned char channel;
    unsigned char control;

    for (int i = 0; i < USING_BOARD; i++) {
        for (int j = 0; j < 16; j++) {
            if (eepromAddress >= EEPROM.length()) return;
            channel = EEPROM.read(eepromAddress);
            control = EEPROM.read(eepromAddress + 1);
            pot[i][j] = {0, 1, channel, control};
            eepromAddress += 2;
        }
    }
}

void factoryInitialization() {
    unsigned char channel;
    unsigned char control;

    for (int preset = 0; preset < 4; preset++) {
        for (int i = 0; i < USING_BOARD; i++) {
            for (int j = 0; j < 16; j++) {
                channel = pgm_read_byte(&(a0[preset][i * 32 + j * 2]));
                control = pgm_read_byte(&(a0[preset][i * 32 + j * 2 + 1]));
                EEPROM.update(preset * 128 + i * 32 + j * 2, channel);
                EEPROM.update(preset * 128 + i * 32 + j * 2 + 1, control);
            }
        }
    }
 }
