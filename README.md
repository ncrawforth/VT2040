# VT2040
Portable serial terminal, based on an RP2040 with a Gherkin keyboard and an ILI9488 screen

## Building

These instructions are for Alpine Linux. Adjust them for your distro.

### Install the required packages
As root:
```sh
apk add git cmake gcc-arm-none-eabi g++ python3 make
```

### Download the VT2040 repositories
```sh
git clone https://github.com/raspberrypi/pico-sdk
git clone https://github.com/ncrawforth/VT2040
cd VT2040
git submodule update --init
```

### Build
```sh
mkdir build
cd build
cmake ..
make
```