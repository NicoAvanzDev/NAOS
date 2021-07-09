# NAOS

Very basic i386 operating system with GRUB bootloader

## How to build

- You'll need qemu (or bochs) in order to test the OS with an emulator.
- Docker for GCC cross-compiling i386 build environment
- On windows, run _build.bat_ to build project from docker container (make sure you've built the container with _docker build -t naos-buildenv_)
