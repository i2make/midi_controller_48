#ifndef MIDI_MULTIPLEXER4067_H
#define MIDI_MULTIPLEXER4067_H

#include <Arduino.h>

// select pin (8, 9, 10, 11)
#define S0_HIGH      PORTB |=  0b00010000    // PB4(pin 8)
#define S0_LOW       PORTB &= ~0b00010000    // PB4(pin 8)
#define S1_HIGH      PORTB |=  0b00100000    // PB5(pin 9)
#define S1_LOW       PORTB &= ~0b00100000    // PB5(pin 9)
#define S2_HIGH      PORTB |=  0b01000000    // PB6(pin 10)
#define S2_LOW       PORTB &= ~0b01000000    // PB6(pin 10)
#define S3_HIGH      PORTB |=  0b10000000    // PB7(pin 11)
#define S3_LOW       PORTB &= ~0b10000000    // PB7(pin 11)

#define C0              S0_LOW;S1_LOW;S2_LOW;S3_LOW;
#define C1              S0_HIGH;S1_LOW;S2_LOW;S3_LOW;
#define C2              S0_LOW;S1_HIGH;S2_LOW;S3_LOW;
#define C3              S0_HIGH;S1_HIGH;S2_LOW;S3_LOW;
#define C4              S0_LOW;S1_LOW;S2_HIGH;S3_LOW;
#define C5              S0_HIGH;S1_LOW;S2_HIGH;S3_LOW;
#define C6              S0_LOW;S1_HIGH;S2_HIGH;S3_LOW;
#define C7              S0_HIGH;S1_HIGH;S2_HIGH;S3_LOW;
#define C8              S0_LOW;S1_LOW;S2_LOW;S3_HIGH;
#define C9              S0_HIGH;S1_LOW;S2_LOW;S3_HIGH;
#define C10             S0_LOW;S1_HIGH;S2_LOW;S3_HIGH;
#define C11             S0_HIGH;S1_HIGH;S2_LOW;S3_HIGH;
#define C12             S0_LOW;S1_LOW;S2_HIGH;S3_HIGH;
#define C13             S0_HIGH;S1_LOW;S2_HIGH;S3_HIGH;
#define C14             S0_LOW;S1_HIGH;S2_HIGH;S3_HIGH;
#define C15             S0_HIGH;S1_HIGH;S2_HIGH;S3_HIGH;

class Multiplexer4067 {
public:
    explicit Multiplexer4067(unsigned char pin = 0)     // analog pin
            : mPin(pin) {}

    void begin() const;

    int read(unsigned char analogInputPin, unsigned char channel);

private:
    unsigned char mPin;
};

#endif //MIDI_MULTIPLEXER4067_H
