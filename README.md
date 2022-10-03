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

- select using ports
```c++
/// select using port number
//#define USING_PORTS_16
//#define USING_PORTS_32
#define USING_PORTS_48
//#define USING_PORTS_64
```

- change channel, midi cc
