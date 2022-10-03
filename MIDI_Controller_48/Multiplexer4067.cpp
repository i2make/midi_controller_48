#include "Multiplexer4067.h"

void Multiplexer4067::begin() const {
    // using resister
    // pin is fixed, don't change
    pinMode(8, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);
}

int Multiplexer4067::read(unsigned char _analogInputPin, unsigned char channel) {
    // select port
    switch (channel) {
        case 0:
            C0
            break;
        case 1:
            C1
            break;
        case 2:
            C2
            break;
        case 3:
            C3
            break;
        case 4:
            C4
            break;
        case 5:
            C5
            break;
        case 6:
            C6
            break;
        case 7:
            C7
            break;
        case 8:
            C8
            break;
        case 9:
            C9
            break;
        case 10:
            C10
            break;
        case 11:
            C11
            break;
        case 12:
            C12
            break;
        case 13:
            C13;
            break;
        case 14:
            C14
            break;
        case 15:
            C15
            break;
        default:
            break;
    }
    return analogRead(_analogInputPin);
}
