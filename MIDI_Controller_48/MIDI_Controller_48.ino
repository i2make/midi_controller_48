#include <SPI.h>
#include "Multiplexer4067.h"
#include "TM1638SPI_QYF.h"
#include "AnalogInput.h"
#include "midiFunction.h"

#define DEBUG_BAUD                  57600
#define POTENTIOMETER_PIN0          A0
#define POTENTIOMETER_PIN1          A1
#define POTENTIOMETER_PIN2          A2
#define POTENTIOMETER_PIN3          A3

#define TM1638_STB                  12

// global variable
word mode = S01;
String tempString;

// Hardware SPI setting
SPISettings qfy(500000, LSBFIRST, SPI_MODE0);
TM1638SPI_QYF tm1638Qyf1(TM1638_STB, &qfy);

// analog multiplexer object
Multiplexer4067 mux;

// TM1638 display function
void update(TM1638SPI_QYF* module, word* mode);

// functions
void displayStartingMessage();
void setCurrentValue();

void setup() {
    //Serial.begin(DEBUG_BAUD);

    SPI.begin();

    pinMode(POTENTIOMETER_PIN0, INPUT);     // analog input 0-15
    pinMode(POTENTIOMETER_PIN1, INPUT);     // analog input 16-31
    pinMode(POTENTIOMETER_PIN2, INPUT);     // analog input 32-47
    pinMode(POTENTIOMETER_PIN3, INPUT);     // analog input 48-63
    pinMode(TM1638_STB, OUTPUT);            // SPI CS Pin

    mux.begin();                                    // multiplexer pinMode() init

    tm1638Qyf1.setupDisplay(true, 7);   // 7-segment bright

    // display starting message
    displayStartingMessage();

    // setting .current value
    setCurrentValue();

}

//CIN   MIDI_x Size     Description
//0x0   1, 2 or 3       Miscellaneous function codes. Reserved for future extensions.
//0x1   1, 2 or 3       Cable events. Reserved for future expansion.
//0x2   2               Two-byte System Common messages like MTC, SongSelect, etc.
//0x3   3               Three-byte System Common messages like SPP, etc.
//0x4   3               SysEx starts or continues
//0x5   1               Single-byte System Common Message or SysEx ends with following single byte.
//0x6   2               SysEx ends with following two bytes.
//0x7   3               SysEx ends with following three bytes.
//0x8   3               Note-off
//0x9   3               Note-on
//0xA   3               Poly-KeyPress
//0xB   3               Control Change
//0xC   2               Program Change
//0xD   2               Channel Pressure
//0xE   3               PitchBend Change
//0xF   1               Single Byte

void loop() {
    for (uint8_t boardN = 0; boardN < USING_BOARD; boardN++) {
        for (int8_t portsN = 0; portsN < 16; portsN++) {

            // last unused input skip
            //if (boardN == 2 && portsN > 7) continue;    // unused input skip

            a[boardN][portsN].current = mux.read(boardN, portsN);
            a[boardN][portsN].current = map(a[boardN][portsN].current, 0, 1023, 0, 127);

            // write data
            if (a[boardN][portsN].previous != a[boardN][portsN].current) {                 /// value changed

                if (a[boardN][portsN].previous - 1 != a[boardN][portsN].current) {         /// if debounced
                    switch (a[boardN][portsN].controlNumber) {
                        case 0 ... 9:
                            tempString = String("C  ") + a[boardN][portsN].controlNumber;
                            break;
                        case 10 ... 99:
                            tempString = String("C ") + a[boardN][portsN].controlNumber;
                            break;
                        case 100 ... 127:
                            tempString = String("C") + a[boardN][portsN].controlNumber;
                            break;
                        default:
                            break;
                    }
                    switch (a[boardN][portsN].current) {
                        case 0 ... 9:
                            tempString += String("-  ") + a[boardN][portsN].current;
                            break;
                        case 10 ... 99:
                            tempString += String("- ") + a[boardN][portsN].current;
                            break;
                        case 100 ... 127:
                            tempString += String("-") + a[boardN][portsN].current;
                            break;
                        default:
                            break;
                    }

                    // MIDI Send
                    controlChange(a[boardN][portsN].channelNumber, a[boardN][portsN].controlNumber, a[boardN][portsN].current);
                    MidiUSB.flush();
                    // update previous state
                    a[boardN][portsN].previous = a[boardN][portsN].current;
                } // debounced

            } // value changed
        } // loop portsN


        // MIDI TimeCode Reading
        midiEventPacket_t rx;
        rx = MidiUSB.read();
        MidiUSB.flush();

        update(&tm1638Qyf1, &mode);
    } // loop boardN
} // loop()

////////////////////////////////////////////////////
/// functions
////////////////////////////////////////////////////

void displayStartingMessage() {
    tm1638Qyf1.setDisplayToString("   Hello");
    delay(3000);
    tm1638Qyf1.setDisplayToString("  MC-48d");
    delay(3000);
}

void setCurrentValue(){
    for (uint8_t boardN = 0; boardN < USING_BOARD; boardN++) {
        for (int8_t portsN = 0; portsN < 16; portsN++) {

            a[boardN][portsN].current = mux.read(boardN, portsN);
            a[boardN][portsN].current = map(a[boardN][portsN].current, 0, 1023, 0, 127);

            // update previous state
            a[boardN][portsN].previous = a[boardN][portsN].current;

        } // loop portsN
    } // loop boardN
}

void update(TM1638SPI_QYF* module, word* mode) {
    word buttons = module->getButtons();

    // button pressed - change mode
    if (buttons != 0) {
        *mode = buttons;
        Serial.println(*mode);
    }

    switch (*mode) {
        case S01:
            tm1638Qyf1.setDisplayToString(tempString, 0);
            break;
        case S02:
            break;
        case S03:
            break;
        case S04:
            break;
        case S05:
            break;
        case S06:
            break;
        case S07:
            break;
        case S08:
            break;
        case S09:
            break;
        case S10:
            break;
        case S11:
            break;
        case S12:
            break;
        case S13:
            break;
        case S14:
            break;
        case S15:
            break;
        case S16:
            break;
        default:
            break;
    }
}
