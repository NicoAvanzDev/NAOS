# NAOS

Very basic i386 operating system with GRUB bootloader

## How to build

- You'll need qemu (or bochs) in order to test the OS with an emulator.
- Docker for GCC cross-compiling i386 build environment
- Run `docker build -t naos-buildenv-i386 buildenv`
- On windows, run `build.bat` (from project root) to build project from docker container
