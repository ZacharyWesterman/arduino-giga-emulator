# arduino-giga-emulator

This project aims to allow emulating certain features of the Arduino Giga and choice hardware on a PC.
The goal is to allow rapid prototyping, especially of larger projects.

Emulation is only *officially* supported on Linux. If you can get it running on Windows, power to you!

## Requirements

- The Arduino IDE (installed via `apt`, not `snap`!)
- `rsync`
- A C++ compiler (if not `g++`, you'll have to tweak `emulate` to add the `CC=<your_compiler>` flag to the `make command`)
- The "Arduino Community Edition" VS Code extension, if uploading with VS Code.
- All the Arduino libraries that your project would need in order to be uploaded to your board.

## Installing

To install on your system, run `./install.sh emulate`.
This just makes a symlink to the `./emulate` script.

## Usage

After installing, you can run `emulate --help` to see usage.

To emulate a sketch, run:

```
emulate your_sketch.ino
```

All of the above (required) libraries are supported, and any that don't rely on specific hardware are also supported! (it's just C++ code after all).
`Serial` and `String` are supported as basic wrappers for `std::cout` and `std::string`, respectively.

## Adding emulation support for your project

The emulator defines the `EMULATE` directive, so you can wrap any hardware-specific
logic or includes with an `#ifndef EMULATE` guard to enable testing of your main application code.
This does mean that testing the actual hardware-specific code is not possible when emulating,
but it's a necessary sacrifice to be able to test the rest of the application.

To add special compile flags and dependencies for emulating your project, add a `.emulate` file in the root of your project. It should look something like this:
```
#Comments start with a hash symbol.
compiler_flags = # Any extra compiler flags. Usually not needed.
linker_flags = # Any extra linker flags. Usually not needed.
sources = # Any .cpp files from libraries that need to be compiled into the project
objects = # Any .o file that needs including. Usually not needed.
includes = Adafruit_GFX_Library Arduino_GigaDisplayTouch/src # Etc. any include path you'll need from Arduino libraries.
