# VT2040
Portable serial terminal, based on an RP2040 with a Gherkin keyboard and an ILI9488 screen

## Building

These instructions are for Alpine Linux. Adjust them for your distro, or create an Alpine Linux chroot:
```sh
mkdir alpine-linux
curl https://dl-cdn.alpinelinux.org/alpine/v3.17/releases/x86_64/alpine-minirootfs-3.17.1-x86_64.tar.gz | tar xzC alpine-linux
chroot alpine-linux
```
