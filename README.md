# VT2040
Portable serial terminal, based on an RP2040 with a Gherkin keyboard and an ILI9488 screen

## Building

These instructions are for Alpine Linux. Adjust them for your distro.

### Install the required packages
As root:
```sh
apk add git cmake gcc-arm-none-eabi g++ python3 newlib-arm-none-eabi make
```

### Download the SDK and the VT2040 repositories
```sh
git clone https://github.com/raspberrypi/pico-sdk
git clone https://github.com/ncrawforth/VT2040
cd VT2040
git submodule update --init
```

### Assign the GPIO pins
``lcd.h``, ``keyb.h`` and ``serial.h`` contain pin assignments for the LCD, keyboard and serial port respectively. Change them to match your hardware.

### Build
```sh
mkdir build
cd build
cmake ..
make
```

### Install
Press and hold the BOOTSEL button on the RP2040 dev board and plug it into your computer's USB port, then release BOOTSEL. It will appear as a USB drive. Copy vt2040.uf2 from the build directory onto it.
