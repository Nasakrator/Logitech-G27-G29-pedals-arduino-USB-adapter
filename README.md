
# Logitech-G27-G29-pedals-arduino-USB-adapter

Arduino code that makes Logitech pedals works via arduino usb adapter.

## Installation

You only have to change pins assigment to yours.
They are in the upper part of file.

```
const int throttle = A0;
const int brake = A1;
const int clutch = A2;
```
A0, A1, A2 are yours pins on arduino, so if you have different ones, change them to yours.

## FAQ

#### Which pedals works?

This code works with G29 pedals and G27, on G25 I didn't tested.

#### Which arduino supports it?

Every arduino that supports Joystick.h liblary.

#### On which OS it is working?

I only tested it on windows 10.
