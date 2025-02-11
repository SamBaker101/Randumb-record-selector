# Randumb-record-selector
A randomizer for Arduino using a TFT touchscreenshield

## Background
This project is intended to work as a randomizer to assist with selecting records (Or other media). When the touchscreen is tapped the randomizer displays a random direction (Right or Left), letter(A-Z) and Number(1-31). The idea being that you would start at the given letter and count the number of records in the given direction to select one.

The code is written to run on an Arduino using a TFT touchscreen from Adafruit

It's worth noting that the code as shown now is very quick and dirty and borrows heavily from the below tutorial. It is my intention in creating this repo to revisit the project, clean up and re-write the code and design a housing enclosure for the project. If successful in this I may explore other smaller microcontrollers to reduce the size and power draw of the device.

## TODO

  - Initial refactor
  - Replace polling with interrupt based touch detection
  - Verify randomization is true(ish)
  - Look into sleep mode or suspended operation

  - Design and print enclosure
  - Investigate alternate microcontrollers, screens, inputs
