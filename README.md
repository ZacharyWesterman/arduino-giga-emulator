# arduino-giga-emulator

This project aims to allow emulating certain features of the Arduino Giga and choice hardware on a PC.
The goal is to allow rapid prototyping, especially of larger projects.

Emulation is only *officially* supported on Linux. If you can get it running on Windows, power to you!

## Requirements

- The Arduino IDE (installed via `apt`, not `snap`!)
- `rsync`
- A C++ compiler (if not `g++`, you'll have to tweak `emulate` to add the `CC=<your_compiler>` flag to the `make command`)
- The "Arduino Community Edition" VS Code extension, if uploading with VS Code.
- The following Arduino libraries:
  - `Arduino_GigaDisplayTouch`
  - `Arduino_GigaDisplay_GFX`
  - `JPEGDEC` - Provides support for rendering JPG-encoded data.
  - `PNGdec` - Provides support for rendering PNG-encoded data.

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