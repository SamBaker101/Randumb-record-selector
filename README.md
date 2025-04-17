# Randumb-record-selector
A randomizer for Arduino using a TFT touchscreen shield

## Background
This project is intended to work as a randomizer to assist with selecting records (Or other media). When the touchscreen is tapped the randomizer displays a random direction (Right or Left), letter(A-Z) and Number(1-31). The idea being that you would start at the given letter and count the number of records in the given direction to select one.

The code is written to run on an Arduino using a TFT touchscreen from Adafruit

![image](assembly_model_01.PNG)

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

### case_bottom_01.FCStd and case_top_01.FCStd

This is a model of a case which I am designing to hold the randomizer. At this point this is still a rough draft and is not functional. I will update this readme once the case has been completed and tested.

## TODO

  - Replace polling with interrupt based touch detection
  - Verify randomization is true(ish)
  - Look into sleep mode or suspended operation

  - Fit test and refine enclosure draft
  - Print finalized enclosure 
  - Investigate alternate microcontrollers, screens, inputs

## Resources

https://electropeak.com/learn/absolute-beginners-guide-to-tft-lcd-displays-by-arduino/

