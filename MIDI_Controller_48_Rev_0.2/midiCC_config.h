#ifndef MIDI_MIDICC_CONFIG_H
#define MIDI_MIDICC_CONFIG_H

/// analog input range
#define MIN_ANALOG_INPUT    0
#define MAX_ANALOG_INPUT    1010
#define MIN_CONTROL_VALUE   0
#define MAX_CONTROL_VALUE   127
#define MIN_CHANNEL_VALUE   1
#define MAX_CHANNEL_VALUE   16

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

//////////////////////////////////////////////////
/// preset 1
//////////////////////////////////////////////////

/// A0          channel number, control number
#define A0_00                1,   3
#define A0_01                1,   9
#define A0_02                1,  14
#define A0_03                1,  15
#define A0_04                1,  20
#define A0_05                1,  21
#define A0_06                1,  22
#define A0_07                1,  23
#define A0_08                1,  24
#define A0_09                1,  25
#define A0_10                1,  26
#define A0_11                1,  27
#define A0_12                1,  28
#define A0_13                1,  29
#define A0_14                1,  30
#define A0_15                1,  31

/// A1          channel number, control number
#define A1_00                1,  64
#define A1_01                1,  65
#define A1_02                1,  66
#define A1_03                1,  67
#define A1_04                1,  68
#define A1_05                1,  69
#define A1_06                1,  70
#define A1_07                1,  71
#define A1_08                1,  72
#define A1_09                1,  73
#define A1_10                1,  74
#define A1_11                1,  75
#define A1_12                1,  76
#define A1_13                1,  77
#define A1_14                1,  78
#define A1_15                1,  79

/// A2          channel number, control number
#define A2_00                1,  80
#define A2_01                1,  81
#define A2_02                1,  82
#define A2_03                1,  83
#define A2_04                1,  84
#define A2_05                1,  85
#define A2_06                1,  86
#define A2_07                1,  87
#define A2_08                1,  88
#define A2_09                1,  89 //
#define A2_10                1,  90
#define A2_11                1,  91
#define A2_12                1,  92
#define A2_13                1,  93
#define A2_14                1,  94
#define A2_15                1,  95

/// A3          channel number, control number
#define A3_00                1,  96
#define A3_01                1,  97
#define A3_02                1,  98
#define A3_03                1,  99
#define A3_04                1, 100
#define A3_05                1, 101
#define A3_06                1, 102
#define A3_07                1, 103
#define A3_08                1, 104
#define A3_09                1, 105
#define A3_10                1, 106
#define A3_11                1, 107
#define A3_12                1, 108
#define A3_13                1, 109
#define A3_14                1, 110
#define A3_15                1, 111

///////////////////////////////////////////////////
/// preset 2
///////////////////////////////////////////////////

/// B0          channel number, control number
#define B0_00                1,   3
#define B0_01                1,   9
#define B0_02                1,  14
#define B0_03                1,  15
#define B0_04                1,  20
#define B0_05                1,  21
#define B0_06                1,  22
#define B0_07                1,  23
#define B0_08                1,  24
#define B0_09                1,  25
#define B0_10                1,  26
#define B0_11                1,  27
#define B0_12                1,  28
#define B0_13                1,  29
#define B0_14                1,  30
#define B0_15                1,  31

/// B1          channel number, control number
#define B1_00                1,  64
#define B1_01                1,  65
#define B1_02                1,  66
#define B1_03                1,  67
#define B1_04                1,  68
#define B1_05                1,  69
#define B1_06                1,  70
#define B1_07                1,  71
#define B1_08                1,  72
#define B1_09                1,  73
#define B1_10                1,  74
#define B1_11                1,  75
#define B1_12                1,  76
#define B1_13                1,  77
#define B1_14                1,  78
#define B1_15                1,  79

/// B2          channel number, control number
#define B2_00                1,  80
#define B2_01                1,  81
#define B2_02                1,  82
#define B2_03                1,  83
#define B2_04                1,  84
#define B2_05                1,  85
#define B2_06                1,  86
#define B2_07                1,  87
#define B2_08                1,  88
#define B2_09                1,  89 //
#define B2_10                1,  90
#define B2_11                1,  91
#define B2_12                1,  92
#define B2_13                1,  93
#define B2_14                1,  94
#define B2_15                1,  95

/// B3          channel number, control number
#define B3_00                1,  96
#define B3_01                1,  97
#define B3_02                1,  98
#define B3_03                1,  99
#define B3_04                1, 100
#define B3_05                1, 101
#define B3_06                1, 102
#define B3_07                1, 103
#define B3_08                1, 104
#define B3_09                1, 105
#define B3_10                1, 106
#define B3_11                1, 107
#define B3_12                1, 108
#define B3_13                1, 109
#define B3_14                1, 110
#define B3_15                1, 111

///////////////////////////////////////////////////
/// preset 3
///////////////////////////////////////////////////

/// C0          channel number, control number
#define C0_00                1,   3
#define C0_01                1,   9
#define C0_02                1,  14
#define C0_03                1,  15
#define C0_04                1,  20
#define C0_05                1,  21
#define C0_06                1,  22
#define C0_07                1,  23
#define C0_08                1,  24
#define C0_09                1,  25
#define C0_10                1,  26
#define C0_11                1,  27
#define C0_12                1,  28
#define C0_13                1,  29
#define C0_14                1,  30
#define C0_15                1,  31

/// C1          channel number, control number
#define C1_00                1,  64
#define C1_01                1,  65
#define C1_02                1,  66
#define C1_03                1,  67
#define C1_04                1,  68
#define C1_05                1,  69
#define C1_06                1,  70
#define C1_07                1,  71
#define C1_08                1,  72
#define C1_09                1,  73
#define C1_10                1,  74
#define C1_11                1,  75
#define C1_12                1,  76
#define C1_13                1,  77
#define C1_14                1,  78
#define C1_15                1,  79

/// C2          channel number, control number
#define C2_00                1,  80
#define C2_01                1,  81
#define C2_02                1,  82
#define C2_03                1,  83
#define C2_04                1,  84
#define C2_05                1,  85
#define C2_06                1,  86
#define C2_07                1,  87
#define C2_08                1,  88
#define C2_09                1,  89 //
#define C2_10                1,  90
#define C2_11                1,  91
#define C2_12                1,  92
#define C2_13                1,  93
#define C2_14                1,  94
#define C2_15                1,  95

/// C3          channel number, control number
#define C3_00                1,  96
#define C3_01                1,  97
#define C3_02                1,  98
#define C3_03                1,  99
#define C3_04                1, 100
#define C3_05                1, 101
#define C3_06                1, 102
#define C3_07                1, 103
#define C3_08                1, 104
#define C3_09                1, 105
#define C3_10                1, 106
#define C3_11                1, 107
#define C3_12                1, 108
#define C3_13                1, 109
#define C3_14                1, 110
#define C3_15                1, 111

///////////////////////////////////////////////////
/// preset 4
///////////////////////////////////////////////////

/// D0          channel number, control number
#define D0_00                1,  10
#define D0_01                2,  10
#define D0_02                3,  10
#define D0_03                4,  10
#define D0_04                5,  10
#define D0_05                6,  10
#define D0_06                7,  10
#define D0_07                8,  10
#define D0_08                1,   7
#define D0_09                2,   7
#define D0_10                3,   7
#define D0_11                4,   7
#define D0_12                5,   7
#define D0_13                6,   7
#define D0_14                7,   7
#define D0_15                8,   7

/// D1          channel number, control number
#define D1_00                1,  64
#define D1_01                2,  64
#define D1_02                3,  64
#define D1_03                4,  64
#define D1_04                5,  64
#define D1_05                6,  64
#define D1_06                7,  64
#define D1_07                8,  64
#define D1_08                9,  10
#define D1_09               10,  10
#define D1_10               11,  10
#define D1_11               12,  10
#define D1_12               13,  10
#define D1_13               14,  10
#define D1_14               15,  10
#define D1_15               16,  10

/// D2          channel number, control number
#define D2_00                9,   7
#define D2_01               10,   7
#define D2_02               11,   7
#define D2_03               12,   7
#define D2_04               13,   7
#define D2_05               14,   7
#define D2_06               15,   7
#define D2_07               16,   7
#define D2_08                9,  64
#define D2_09               10,  64
#define D2_10               11,  64
#define D2_11               12,  64
#define D2_12               13,  64
#define D2_13               14,  64
#define D2_14               15,  64
#define D2_15               16,  64

/// D3          channel number, control number
#define D3_00                1,  96
#define D3_01                1,  97
#define D3_02                1,  98
#define D3_03                1,  99
#define D3_04                1, 100
#define D3_05                1, 101
#define D3_06                1, 102
#define D3_07                1, 103
#define D3_08                1, 104
#define D3_09                1, 105
#define D3_10                1, 106
#define D3_11                1, 107
#define D3_12                1, 108
#define D3_13                1, 109
#define D3_14                1, 110
#define D3_15                1, 111

const unsigned char a0[4][128] PROGMEM = {{A0_00, A0_01, A0_02, A0_03, A0_04, A0_05, A0_06, A0_07,
                                                  A0_08, A0_09, A0_10, A0_11, A0_12, A0_13, A0_14, A0_15,
                                                  A1_00, A1_01, A1_02, A1_03, A1_04, A1_05, A1_06, A1_07,
                                                  A1_08, A1_09, A1_10, A1_11, A1_12, A1_13, A1_14, A1_15,
                                                  A2_00, A2_01, A2_02, A2_03, A2_04, A2_05, A2_06, A2_07,
                                                  A2_08, A2_09, A2_10, A2_11, A2_12, A2_13, A2_14, A2_15,
                                                  A3_00, A3_01, A3_02, A3_03, A3_04, A3_05, A3_06, A3_07,
                                                  A3_08, A3_09, A3_10, A3_11, A3_12, A3_13, A3_14, A3_15},
                                          {B0_00, B0_01, B0_02, B0_03, B0_04, B0_05, B0_06, B0_07,
                                                  B0_08, B0_09, B0_10, B0_11, B0_12, B0_13, B0_14, B0_15,
                                                  B1_00, B1_01, B1_02, B1_03, B1_04, B1_05, B1_06, B1_07,
                                                  B1_08, B1_09, B1_10, B1_11, B1_12, B1_13, B1_14, B1_15,
                                                  B2_00, B2_01, B2_02, B2_03, B2_04, B2_05, B2_06, B2_07,
                                                  B2_08, B2_09, B2_10, B2_11, B2_12, B2_13, B2_14, B2_15,
                                                  B3_00, B3_01, B3_02, B3_03, B3_04, B3_05, B3_06, B3_07,
                                                  B3_08, B3_09, B3_10, B3_11, B3_12, B3_13, B3_14, B3_15},
                                          {C0_00, C0_01, C0_02, C0_03, C0_04, C0_05, C0_06, C0_07,
                                                  C0_08, C0_09, C0_10, C0_11, C0_12, C0_13, C0_14, C0_15,
                                                  C1_00, C1_01, C1_02, C1_03, C1_04, C1_05, C1_06, C1_07,
                                                  C1_08, C1_09, C1_10, C1_11, C1_12, C1_13, C1_14, C1_15,
                                                  C2_00, C2_01, C2_02, C2_03, C2_04, C2_05, C2_06, C2_07,
                                                  C2_08, C2_09, C2_10, C2_11, C2_12, C2_13, C2_14, C2_15,
                                                  C3_00, C3_01, C3_02, C3_03, C3_04, C3_05, C3_06, C3_07,
                                                  C3_08, C3_09, C3_10, C3_11, C3_12, C3_13, C3_14, C3_15},
                                          {D0_00, D0_01, D0_02, D0_03, D0_04, D0_05, D0_06, D0_07,
                                                  D0_08, D0_09, D0_10, D0_11, D0_12, D0_13, D0_14, D0_15,
                                                  D1_00, D1_01, D1_02, D1_03, D1_04, D1_05, D1_06, D1_07,
                                                  D1_08, D1_09, D1_10, D1_11, D1_12, D1_13, D1_14, D1_15,
                                                  D2_00, D2_01, D2_02, D2_03, D2_04, D2_05, D2_06, D2_07,
                                                  D2_08, D2_09, D2_10, D2_11, D2_12, D2_13, D2_14, D2_15,
                                                  D3_00, D3_01, D3_02, D3_03, D3_04, D3_05, D3_06, D3_07,
                                                  D3_08, D3_09, D3_10, D3_11, D3_12, D3_13, D3_14, D3_15}};

#endif //MIDI_MIDICC_CONFIG_H
