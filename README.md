# midi_controller_48
48 pot midi cc control surface  
# used parts
arduino leonardo x 1  
74HC4076 16-channel multiplexer board x 3  
QYF-TM1638 board x 1  
10K potentiometer x 48  
external DC 5V adapter x 1  

## The QYF-TM1638 board may not be used.  
If you don't use it, you don't even need an DC 5V adapter.

# Wiring Schematics
![picture](https://github.com/i2make/midi_controller_48/blob/main/midi_controller_48.jpg)
![picture](https://github.com/i2make/midi_controller_48/blob/main/midi_controller_48_small.png)

# step 1
Install MIDIUSB library
![picture](https://github.com/i2make/midi_controller_48/blob/main/manage_library.png)
![picture](https://github.com/i2make/midi_controller_48/blob/main/install_midiusb.png)

# step 2
Change configuration
- select using ports (file: midiCC_config.h)
```c++
/// select using port number
//#define USING_PORTS_16
//#define USING_PORTS_32
#define USING_PORTS_48
//#define USING_PORTS_64
```

- change channel, midi cc (file: midiCC_config.h)
```c++
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
...
...
```

# step 3
If the value of the potentiometer moves in the opposite direction

