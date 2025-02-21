# Randumb-record-selector
A randomizer for Arduino using a TFT touchscreen shield

## Background
This project is intended to work as a randomizer to assist with selecting records (Or other media). When the touchscreen is tapped the randomizer displays a random direction (Right or Left), letter(A-Z) and Number(1-31). The idea being that you would start at the given letter and count the number of records in the given direction to select one.

The code is written to run on an Arduino using a TFT touchscreen from Adafruit

I wrote a very quick and dirty version of this code which I uploaded onto one of my Arduinos and have been using for quite a while. It's my hope though to clean this code up and extend it to make a more robust device. I've begun the process of refactoring but there is still more to do. I'd also like to look into making an enclosure using freeCAD (or similar) to hold the randomizer.

## Requirements

The following headers are required to run this project:

  - #include \<Adafruit_GFX.h\>

  - #include \<Adafruit_TFTLCD.h\>
  
  - #include "TouchScreen.h"

All three of these should be downloadable through the Arduino IDE

## Hardware

2.4 inch LCD TFT Screen:

https://www.canadarobotix.com/products/2316

Arduino Uno

https://docs.arduino.cc/hardware/uno-rev3/


## Models

The models I created for this project were made using FreeCAD 1.0 which is a free and open source 3d Parametric CAD program. FreeCAD can be downloaded at the following link to access or modify the files:

https://www.freecad.org/

### device.FCstd

This is a combined model of the Arduino Uno and the TFT screen.

## TODO

  - Initial refactor
  - Replace polling with interrupt based touch detection
  - Verify randomization is true(ish)
  - Look into sleep mode or suspended operation

  - Design and print enclosure
  - Investigate alternate microcontrollers, screens, inputs

## Resources

https://electropeak.com/learn/absolute-beginners-guide-to-tft-lcd-displays-by-arduino/

