#ifndef MIDI_MIDICC_CONFIG_H
#define MIDI_MIDICC_CONFIG_H

/// select using port number
//#define USING_PORTS_16
//#define USING_PORTS_32
#define USING_PORTS_48
//#define USING_PORTS_64

#ifdef USING_PORTS_16
#define USING_BOARD     1
#endif
#ifdef USING_PORTS_32
#define USING_BOARD     2
#endif
#ifdef USING_PORTS_48
#define USING_BOARD     3
#endif
#ifdef USING_PORTS_64
#define USING_BOARD     4
#endif

/// A0          channel number, control number
#define A0_00                0,   3
#define A0_01                0,   9
#define A0_02                0,  14
#define A0_03                0,  15
#define A0_04                0,  20
#define A0_05                0,  21
#define A0_06                0,  22
#define A0_07                0,  23
#define A0_08                0,  24
#define A0_09                0,  25
#define A0_10                0,  26
#define A0_11                0,  27
#define A0_12                0,  28
#define A0_13                0,  29
#define A0_14                0,  30
#define A0_15                0,  31

/// A1          channel number, control number
#define A1_00                0,  84
#define A1_01                0,  85
#define A1_02                0,  86
#define A1_03                0,  87
#define A1_04                0,  88
#define A1_05                0,  89
#define A1_06                0,  90
#define A1_07                0, 102
#define A1_08                0, 103
#define A1_09                0, 104
#define A1_10                0, 105
#define A1_11                0, 106
#define A1_12                0, 107
#define A1_13                0, 108
#define A1_14                0, 109
#define A1_15                0, 110

/// A2          channel number, control number
#define A2_00                0, 111
#define A2_01                0, 112
#define A2_02                0, 113
#define A2_03                0, 114
#define A2_04                0, 115
#define A2_05                0, 116
#define A2_06                0, 117
#define A2_07                0, 118
#define A2_08                0, 119
#define A2_09                0, 120 //
#define A2_10                0, 121
#define A2_11                0, 122
#define A2_12                0, 124
#define A2_13                0, 125
#define A2_14                0, 126
#define A2_15                0, 127

/// A3          channel number, control number
#define A3_00                0,  32
#define A3_01                0,  33
#define A3_02                0,  34
#define A3_03                0,  35
#define A3_04                0,  36
#define A3_05                0,  37
#define A3_06                0,  38
#define A3_07                0,  39
#define A3_08                0,  40
#define A3_09                0,  41
#define A3_10                0,  42
#define A3_11                0,  43
#define A3_12                0,  44
#define A3_13                0,  45
#define A3_14                0,  46
#define A3_15                0,  47

#endif //MIDI_MIDICC_CONFIG_H
