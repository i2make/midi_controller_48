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

// typedef function pointer
typedef void(* fp)(); // function pointer 0-argument

typedef void(* fp1)(unsigned char); // function pointer 1-argument

// global variable
word mode = S01, previousMode = S16;
word buttons; // tm1638 button value
String previousString;
String displayString; // display string
uint8_t presetN; // preset number
uint8_t indexBoardN, indexPortsN; // for statement indices
uint8_t selectedChannelN, selectedControlN, selectedBoardN, selectedPortsN;

// Analog input value (0 ~ 1023)
unsigned int current;

// Display Mode starting
bool starting;

// Midi Read
midiEventPacket_t rx;

// Song Position Pointer
unsigned int sixteens;
unsigned int bars;
unsigned char quarters;
unsigned int sixteen;
int ppqn;

// Hardware SPI setting
SPISettings qfy(500000, LSBFIRST, SPI_MODE0);
TM1638SPI_QYF tm1638Qyf1(TM1638_STB, &qfy);

// analog multiplexer object
Multiplexer4067 mux;

// TM1638 display function
void update();

// functions
void displayStartingMessage();

void setCurrentValue();

bool yesOrNo(fp cb);

bool yesOrNo(fp1 cb, unsigned char preset);

void changeChannel();

void changeControl();

void displayControlValue();

void displayChannelControl();

void eepromChannelChange();

void eepromControlChange();

void midiRead();

void midiReadSPP();

void midReadMTC();

// function pointer
void iterateInputRead(fp cb, fp cb2);

// Input object
AnalogInput pot[USING_BOARD][16];

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

    /// factory initialization mode //////////////////////////////////////////////
    buttons = tm1638Qyf1.getButtons();
    if (buttons != 0) {
        if (buttons == S01) {
            tm1638Qyf1.setDisplayToString("INIT y_n");
            while (true) {
                if (yesOrNo(factoryInitialization)) break;
            } // while
            delay(2000);
            mode = S01;
        }
    }
    ////////////////////////////////////////////////////////////////////////

    // read from EEPROM
    presetN = 0;            // preset number 0
    readEEPROM(0);  // read from eeprom

    // setting .current value
    setCurrentValue();

}

void loop() {
    update();
} // loop()

////////////////////////////////////////////////////
/// functions
////////////////////////////////////////////////////

void update() {
    buttons = tm1638Qyf1.getButtons(); // read buttons from tm1638 board
    if (buttons != 0) { // button pressed
        mode = buttons;
    }

    switch (mode) {
        case S01: /// display Control - Value /////////////////////////////////////////////////
            if (previousMode != mode) {
                displayString = " Ctr vlu";
                tm1638Qyf1.setDisplayToString(displayString, 0);
                previousMode = mode;
            }
            iterateInputRead(displayControlValue, midiRead);
            tm1638Qyf1.setDisplayToString(displayString, 0);
            break;
        case S02: /// display Channel - Control /////////////////////////////////////////////////////
            if (previousMode != mode) {
                displayString = " Ch Ctr ";
                tm1638Qyf1.setDisplayToString(displayString, 0);
                previousMode = mode;
            }
            iterateInputRead(displayChannelControl, midiRead);
            tm1638Qyf1.setDisplayToString(displayString, 0);
            break;
        case S03: /// display MTC /////////////////////////////////////////////////////////////
            if (previousMode != mode) {
                displayString = "  MTC   ";
                tm1638Qyf1.setDisplayToString(displayString, 0);
                previousMode = mode;
            }
            iterateInputRead(displayControlValue, midReadMTC);
            break;
        case S04: /// display SPP ////////////////////////////////////////////////////////////
            if (previousMode != mode) {
                displayString = "  SPP   ";
                tm1638Qyf1.setDisplayToString(displayString, 0);
                previousMode = mode;
            }
            iterateInputRead(displayControlValue, midiReadSPP);
            break;
        case S05: /// change Channel number //////////////////////////////////////////////////
            previousString = displayString;
            starting = true; // channel change mode start
            tm1638Qyf1.setDisplayToString("chge chn");
            while (true) {
                iterateInputRead(changeChannel, midiRead); // Execute changeChannel when the input changes

                if (!starting) { // Show "chge chn" until input change
                    tm1638Qyf1.setDisplayToString(displayString, 0);
                }

                if (yesOrNo(eepromChannelChange)) { // execute eepromChannelChange if yes
                    break; // exit while(true)
                }
            } // while
            delay(1000);
            displayString = previousString;
            mode = S01;
            break;
        case S06: /// change Control number ////////////////////////////////////////////////////
            previousString = displayString;
            starting = true; // control change mode start
            tm1638Qyf1.setDisplayToString("chge ctr");
            while (true) {
                iterateInputRead(changeControl, midiRead); // Execute changeControl when the input changes

                if (!starting) { // Show "chge ctr" until input change
                    tm1638Qyf1.setDisplayToString(displayString, 0);
                }

                if (yesOrNo(eepromControlChange)) { // execute eepromChannelChange if yes
                    break; // exit while(true)
                }
            } // while
            delay(1000);
            displayString = previousString;
            mode = S01;
            break;
        case S07: /////////////////////////////////////////////////////////////////////////
            mode = S01;
            break;
        case S08: /////////////////////////////////////////////////////////////////////////
            mode = S01;
            break;
        case S09: /// setting preset 1 /////////////////////////////////////////////////////
            presetN = 0;
            previousString = displayString;
            tm1638Qyf1.setDisplayToString("PSt1 y_n");
            while (true) {
                if (yesOrNo(readEEPROM, presetN)) { // execute readEEPROM if yes
                    break; // exit while(true)
                }
            } // while
            delay(1000);
            displayString = previousString;
            mode = S01;
            break;
        case S10: /// setting preset 2 ///////////////////////////////////////////////////////
            presetN = 1;
            previousString = displayString;
            tm1638Qyf1.setDisplayToString("PSt2 y_n");
            while (true) {
                if (yesOrNo(readEEPROM, presetN)) { // execute readEEPROM if yes
                    break; // exit while(true)
                }
            } // while
            delay(1000);
            displayString = previousString;
            mode = S01;
            break;
        case S11: /// setting preset 3 //////////////////////////////////////////////////////////
            presetN = 2;
            previousString = displayString;
            tm1638Qyf1.setDisplayToString("PSt3 y_n");
            while (true) {
                if (yesOrNo(readEEPROM, presetN)) { // execute readEEPROM if yes
                    break; // exit while(true)
                }
            } // while
            delay(1000);
            displayString = previousString;
            mode = S01;
            break;
        case S12: /// setting preset 4 ////////////////////////////////////////////////////////////
            presetN = 3;
            previousString = displayString;
            tm1638Qyf1.setDisplayToString("PSt4 y_n");
            while (true) {
                if (yesOrNo(readEEPROM, presetN)) { // execute readEEPROM if yes
                    break; // exit while(true)
                }
            } // while
            delay(1000);
            displayString = previousString;
            mode = S01;
            break;
        case S13: /////////////////////////////////////////////////////////////////////////
            mode = S01;
            break;
        case S14: /////////////////////////////////////////////////////////////////////////
            mode = S01;
            break;
        case S15: /////////////////////////////////////////////////////////////////////////
            mode = S01;
            break;
        case S16: /////////////////////////////////////////////////////////////////////////
            mode = S01;
            break;
        default:
            break;
    }
}

void displayStartingMessage() {

    tm1638Qyf1.setDisplayToString("  MC-48d");
    delay(2000);
}

void setCurrentValue() {
    for (indexBoardN = 0; indexBoardN < USING_BOARD; indexBoardN++) {
        for (indexPortsN = 0; indexPortsN < 16; indexPortsN++) {

            current = mux.read(indexBoardN, indexPortsN);
            pot[indexBoardN][indexPortsN].previous = map(current,
                                                         MIN_ANALOG_INPUT, MAX_ANALOG_INPUT,
                                                         MIN_CONTROL_VALUE, MAX_CONTROL_VALUE);
        } // loop portsN
    } // loop boardN
}

void iterateInputRead(fp cb, fp cb2) {
    for (indexBoardN = 0; indexBoardN < USING_BOARD; indexBoardN++) {  /// board numbers
        for (indexPortsN = 0; indexPortsN < 16; indexPortsN++) {        /// ports numbers

            current = mux.read(indexBoardN, indexPortsN);     /// read from ports
            pot[indexBoardN][indexPortsN].current = map(current,
                                                        MIN_ANALOG_INPUT, MAX_ANALOG_INPUT,
                                                        MIN_CONTROL_VALUE, MAX_CONTROL_VALUE); /// scaling number
            if (pot[indexBoardN][indexPortsN].current > 127) {
                pot[indexBoardN][indexPortsN].current = 127;
            }
            if (pot[indexBoardN][indexPortsN].current < 0) {
                pot[indexBoardN][indexPortsN].current = 0;
            }
            // write data
            if (pot[indexBoardN][indexPortsN].previous != pot[indexBoardN][indexPortsN].current) {          /// value changed
                if (pot[indexBoardN][indexPortsN].previous - 1 != pot[indexBoardN][indexPortsN].current) {  /// if debounced
                    cb(); // function pointer 1
                }
            }
            cb2();
        } // for ports
    } // for boards
}

bool yesOrNo(fp cb) {
    buttons = tm1638Qyf1.getButtons();
    if (buttons == S13) {
        tm1638Qyf1.setDisplayToString("EXEC");
        cb();
        return true;
    } else if (buttons == S16) {
        tm1638Qyf1.setDisplayToString("CANCEL");
        return true;
    }
    return false;
}

bool yesOrNo(fp1 cb, unsigned char preset) {
    buttons = tm1638Qyf1.getButtons();
    if (buttons == S13) {
        tm1638Qyf1.setDisplayToString("EXEC");
        cb(preset);
        return true;
    } else if (buttons == S16) {
        tm1638Qyf1.setDisplayToString("CANCEL");
        return true;
    }
    return false;
}

void changeChannel() {
    unsigned char displayChannel = pot[indexBoardN][indexPortsN].channelNumber;
    switch (displayChannel) { /// display channel number
        case 1 ... 9:
            displayString = String("Ch ") + (displayChannel);
            break;
        case 10 ... 99:
            displayString = String("Ch") + (displayChannel);
            break;
        default:
            break;
    }

    selectedChannelN = map(current,
                           MIN_ANALOG_INPUT, MAX_ANALOG_INPUT,
                           MIN_CHANNEL_VALUE, MAX_CHANNEL_VALUE);
    switch (selectedChannelN) { /// display channel number
        case 1 ... 9:
            displayString += String("Ch ") + (selectedChannelN);
            break;
        case 10 ... 99:
            displayString += String("Ch") + (selectedChannelN);
            break;
        default:
            break;
    }
    selectedBoardN = indexBoardN;
    selectedPortsN = indexPortsN;
    pot[indexBoardN][indexPortsN].previous = pot[indexBoardN][indexPortsN].current;
    starting = false; // display channel info
}

void changeControl() {
    switch (pot[indexBoardN][indexPortsN].controlNumber) { /// display control number
        case 0 ... 9:
            displayString = String("C  ") + pot[indexBoardN][indexPortsN].controlNumber;
            break;
        case 10 ... 99:
            displayString = String("C ") + pot[indexBoardN][indexPortsN].controlNumber;
            break;
        case 100 ... 127:
            displayString = String("C") + pot[indexBoardN][indexPortsN].controlNumber;
            break;
        default:
            break;
    } //switch

    selectedControlN = map(current,
                           MIN_ANALOG_INPUT, MAX_ANALOG_INPUT,
                           MIN_CONTROL_VALUE, MAX_CONTROL_VALUE);
    switch (selectedControlN) {  /// display control value
        case 0 ... 9:
            displayString += String("C  ") + selectedControlN;
            break;
        case 10 ... 99:
            displayString += String("C ") + selectedControlN;
            break;
        case 100 ... 127:
            displayString += String("C") + selectedControlN;
            break;
        default:
            break;
    } //switch

    selectedBoardN = indexBoardN;
    selectedPortsN = indexPortsN;
    pot[indexBoardN][indexPortsN].previous = pot[indexBoardN][indexPortsN].current;
    starting = false; // display channel info
}

void eepromChannelChange() {
    pot[selectedBoardN][selectedPortsN].channelNumber = selectedChannelN;
    EEPROM.update(presetN * 128 + selectedBoardN * 32 + selectedPortsN * 2, selectedChannelN);
}

void eepromControlChange() {
    pot[selectedBoardN][selectedPortsN].controlNumber = selectedControlN;
    EEPROM.update(presetN * 128 + selectedBoardN * 32 + selectedPortsN * 2 + 1, selectedControlN);
}

/// display controller number & controller value
void displayControlValue() {
    switch (pot[indexBoardN][indexPortsN].controlNumber) { /// display control number
        case 0 ... 9:
            displayString = String("C  ") + pot[indexBoardN][indexPortsN].controlNumber;
            break;
        case 10 ... 99:
            displayString = String("C ") + pot[indexBoardN][indexPortsN].controlNumber;
            break;
        case 100 ... 127:
            displayString = String("C") + pot[indexBoardN][indexPortsN].controlNumber;
            break;
        default:
            break;
    } //switch
    switch (pot[indexBoardN][indexPortsN].current) {  /// display control value
        case 0 ... 9:
            displayString += String("-  ") + pot[indexBoardN][indexPortsN].current;
            break;
        case 10 ... 99:
            displayString += String("- ") + pot[indexBoardN][indexPortsN].current;
            break;
        case 100 ... 127:
            displayString += String("-") + pot[indexBoardN][indexPortsN].current;
            break;
        default:
            break;
    } //switch

    // MIDI Send
    controlChange(pot[indexBoardN][indexPortsN].channelNumber - 1, pot[indexBoardN][indexPortsN].controlNumber, pot[indexBoardN][indexPortsN].current);
    MidiUSB.flush();
    // update previous state
    pot[indexBoardN][indexPortsN].previous = pot[indexBoardN][indexPortsN].current;
}

/// display channel number & controller number
void displayChannelControl() {
    unsigned char displayChannel = pot[indexBoardN][indexPortsN].channelNumber;
    switch (displayChannel) { /// display channel number
        case 0 ... 9:
            displayString = String("Ch ") + (displayChannel);
            break;
        case 10 ... 99:
            displayString = String("Ch") + (displayChannel);
            break;
        default:
            break;
    }
    switch (pot[indexBoardN][indexPortsN].current) {  /// display control value
        case 0 ... 9:
            displayString += String("C  ") + pot[indexBoardN][indexPortsN].current;
            break;
        case 10 ... 99:
            displayString += String("C ") + pot[indexBoardN][indexPortsN].current;
            break;
        case 100 ... 127:
            displayString += String("C") + pot[indexBoardN][indexPortsN].current;
            break;
        default:
            break;
    } //switch

    // MIDI Send
    controlChange(pot[indexBoardN][indexPortsN].channelNumber - 1, pot[indexBoardN][indexPortsN].controlNumber, pot[indexBoardN][indexPortsN].current);
    MidiUSB.flush();
    // update previous state
    pot[indexBoardN][indexPortsN].previous = pot[indexBoardN][indexPortsN].current;
}

void midiRead() {
    rx = MidiUSB.read();
}

void displaySPP() {
    bars = int(sixteens / 16) + 1;
    quarters = (sixteens % 16) / 4 + 1;
    sixteen = (sixteens % 16) % 4 + 1;
    switch (bars) {
        case 0 ... 9:
            displayString = "   " + String(bars);
            break;
        case 10 ... 99:
            displayString = "  " + String(bars);
            break;
        case 100 ... 999:
            displayString = " " + String(bars);
            break;
        default:
            displayString = String(bars);
            break;
    }
    displayString += " " + String(quarters) + " " + String(sixteen);
    tm1638Qyf1.setDisplayToString(displayString, 0);
}

void midiReadSPP() {
    rx = MidiUSB.read();
    if (rx.byte1 == 0xF2) {
        sixteens = rx.byte3 * 128 + rx.byte2; // total sixteens
        displaySPP();
    }
    if (rx.byte1 == 0xF8) {
        ppqn++;
        if (ppqn > 5) {
            sixteens++;
            displaySPP();
            ppqn = 0;
        }
    }
}

void midReadMTC() {
    ///////////////////////////////////////
    /// MTC data
    /// byte1   byte2
    /// 0xF1    data (x000 0000)
    ///                 ^    ^
    ///            indices  data
    ///             0 ~ 7
    ///////////////////////////////////////
    rx = MidiUSB.read();
    if (rx.byte1 == 0xF1) {
        enum {
            F24 = 0, F25 = 2, F30DF = 4, F30 = 6
        }; // Frames type

        static unsigned char h, m, s, f;      // hour, minutes, seconds, frames time code
        static unsigned char frameType;       // speed of MTC : 24fps / 25fps / 30 drop frame / 30 fps
        static unsigned char tc[7];          // array to old timecode

        int indices = (rx.byte2 & 0xF0) >> 4;   // indices, storing high 4-digit

        tc[indices] = rx.byte2 & 0x0F;         // data, storing low 4-digit

        if (indices == 7) {
            //h = (tc[7] & 0x01) * 16 + tc[6];
            m = tc[5] * 16 + tc[4];
            s = tc[3] * 16 + tc[2];
            f = tc[1] * 16 + tc[0];

            switch (m) { /// display minutes
                case 0 ... 9:
                    displayString = String(" ") + m;
                    break;
                case 10 ... 99:
                    displayString = m;
                    break;
                default:
                    break;
            } //switch

            switch (s) { /// display seconds
                case 0 ... 9:
                    displayString += String("  ") + s;
                    break;
                case 10 ... 99:
                    displayString += String(" ") + s;
                    break;
                default:
                    break;
            } //switch

            switch (f) { /// display frames
                case 0 ... 9:
                    displayString += String("  ") + f;
                    break;
                case 10 ... 99:
                    displayString += String(" ") + f;
                    break;
                default:
                    break;
            } //switch

//                    frameType = tc[7] & 0x06;   // 0000 0110
//                    // 0=24fps, 2=25fps, 4=30(df)fps, 6=30fps
//                    switch (frameType) {
//                        case F24:
//                            displayString = "24 fps";
//                            break;
//                        case F25:
//                            displayString = "25 fps";
//                            break;
//                        case F30DF:
//                            displayString = "30df fps";
//                            break;
//                        case F30:
//                            displayString = "30 fps";
//                            break;
//                        default:
//                            displayString = "Error";
//                            break;
//                    }
            tm1638Qyf1.setDisplayToString(displayString, 0);
        } // if(indices == 7)
    } //if
}