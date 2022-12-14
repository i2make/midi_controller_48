#ifndef MIDI_ANALOGINPUT_H
#define MIDI_ANALOGINPUT_H

#include <Arduino.h>
#include "midiCC_config.h"

class AnalogInput
{
public:
    unsigned int current;
    unsigned int previous;
    unsigned char channelNumber;
    unsigned char controlNumber;
};

#ifdef USING_PORTS_16
// init array
AnalogInput a[1][16] = {{{0, 1, A0_00},
                         {0, 1, A0_01},
                         {0, 1, A0_02},
                         {0, 1, A0_03},
                         {0, 1, A0_04},
                         {0, 1, A0_05},
                         {0, 1, A0_06},
                         {0, 1, A0_07},
                         {0, 1, A0_08},
                         {0, 1, A0_09},
                         {0, 1, A0_10},
                         {0, 1, A0_11},
                         {0, 1, A0_12},
                         {0, 1, A0_13},
                         {0, 1, A0_14},
                         {0, 1, A0_15}}};
#endif

#ifdef USING_PORTS_32
AnalogInput a[2][16] = {{{0, 1, A0_00},
                                {0, 1, A0_01},
                                {0, 1, A0_02},
                                {0, 1, A0_03},
                                {0, 1, A0_04},
                                {0, 1, A0_05},
                                {0, 1, A0_06},
                                {0, 1, A0_07},
                                {0, 1, A0_08},
                                {0, 1, A0_09},
                                {0, 1, A0_10},
                                {0, 1, A0_11},
                                {0, 1, A0_12},
                                {0, 1, A0_13},
                                {0, 1, A0_14},
                                {0, 1, A0_15}},
                        {{0, 1, A1_00},
                                {0, 1, A1_01},
                                {0, 1, A1_02},
                                {0, 1, A1_03},
                                {0, 1, A1_04},
                                {0, 1, A1_05},
                                {0, 1, A1_06},
                                {0, 1, A1_07},
                                {0, 1, A1_08},
                                {0, 1, A1_09},
                                {0, 1, A1_10},
                                {0, 1, A1_11},
                                {0, 1, A1_12},
                                {0, 1, A1_13},
                                {0, 1, A1_14},
                                {0, 1, A1_15}}};
#endif

#ifdef USING_PORTS_48
// init array
AnalogInput a[3][16] = {{{0, 1, A0_00},
                                {0, 1, A0_01},
                                {0, 1, A0_02},
                                {0, 1, A0_03},
                                {0, 1, A0_04},
                                {0, 1, A0_05},
                                {0, 1, A0_06},
                                {0, 1, A0_07},
                                {0, 1, A0_08},
                                {0, 1, A0_09},
                                {0, 1, A0_10},
                                {0, 1, A0_11},
                                {0, 1, A0_12},
                                {0, 1, A0_13},
                                {0, 1, A0_14},
                                {0, 1, A0_15}},
                        {{0, 1, A1_00},
                                {0, 1, A1_01},
                                {0, 1, A1_02},
                                {0, 1, A1_03},
                                {0, 1, A1_04},
                                {0, 1, A1_05},
                                {0, 1, A1_06},
                                {0, 1, A1_07},
                                {0, 1, A1_08},
                                {0, 1, A1_09},
                                {0, 1, A1_10},
                                {0, 1, A1_11},
                                {0, 1, A1_12},
                                {0, 1, A1_13},
                                {0, 1, A1_14},
                                {0, 1, A1_15}},
                        {{0, 1, A2_00},
                                {0, 1, A2_01},
                                {0, 1, A2_02},
                                {0, 1, A2_03},
                                {0, 1, A2_04},
                                {0, 1, A2_05},
                                {0, 1, A2_06},
                                {0, 1, A2_07},
                                {0, 1, A2_08},
                                {0, 1, A2_09},
                                {0, 1, A2_10},
                                {0, 1, A2_11},
                                {0, 1, A2_12},
                                {0, 1, A2_13},
                                {0, 1, A2_14},
                                {0, 1, A2_15}}};
#endif

#ifdef USING_PORTS_64
// init array
AnalogInput a[4][16] = {{{0, 1, A0_00},
                                {0, 1, A0_01},
                                {0, 1, A0_02},
                                {0, 1, A0_03},
                                {0, 1, A0_04},
                                {0, 1, A0_05},
                                {0, 1, A0_06},
                                {0, 1, A0_07},
                                {0, 1, A0_08},
                                {0, 1, A0_09},
                                {0, 1, A0_10},
                                {0, 1, A0_11},
                                {0, 1, A0_12},
                                {0, 1, A0_13},
                                {0, 1, A0_14},
                                {0, 1, A0_15}},
                        {{0, 1, A1_00},
                                {0, 1, A1_01},
                                {0, 1, A1_02},
                                {0, 1, A1_03},
                                {0, 1, A1_04},
                                {0, 1, A1_05},
                                {0, 1, A1_06},
                                {0, 1, A1_07},
                                {0, 1, A1_08},
                                {0, 1, A1_09},
                                {0, 1, A1_10},
                                {0, 1, A1_11},
                                {0, 1, A1_12},
                                {0, 1, A1_13},
                                {0, 1, A1_14},
                                {0, 1, A1_15}},
                        {{0, 1, A2_00},
                                {0, 1, A2_01},
                                {0, 1, A2_02},
                                {0, 1, A2_03},
                                {0, 1, A2_04},
                                {0, 1, A2_05},
                                {0, 1, A2_06},
                                {0, 1, A2_07},
                                {0, 1, A2_08},
                                {0, 1, A2_09},
                                {0, 1, A2_10},
                                {0, 1, A2_11},
                                {0, 1, A2_12},
                                {0, 1, A2_13},
                                {0, 1, A2_14},
                                {0, 1, A2_15}},
                        {{0, 1, A3_00},
                                {0, 1, A3_01},
                                {0, 1, A3_02},
                                {0, 1, A3_03},
                                {0, 1, A3_04},
                                {0, 1, A3_05},
                                {0, 1, A3_06},
                                {0, 1, A3_07},
                                {0, 1, A3_08},
                                {0, 1, A3_09},
                                {0, 1, A3_10},
                                {0, 1, A3_11},
                                {0, 1, A3_12},
                                {0, 1, A3_13},
                                {0, 1, A3_14},
                                {0, 1, A3_15}}};
#endif

#endif //MIDI_ANALOGINPUT_H
