/*
  Randomizer for Arduino using TFT shield
  Sam Baker

  Referencing code available at
  https://electropeak.com/learn/
*/

#include <Adafruit_GFX.h>
#include <Adafruit_TFTLCD.h>
#include <stdint.h>
#include "TouchScreen.h"

#define YP A2  
#define XM A3 
#define YM 8   
#define XP 9   

#define LCD_CS A3
#define LCD_CD A2
#define LCD_WR A1
#define LCD_RD A0
#define LCD_RESET A4

#define BLACK       0x0000
#define BLUE        0x001F
#define RED         0xF800
#define GREEN       0x07E0
#define CYAN        0x07FF
#define MAGENTA     0xF81F
#define YELLOW      0xFFE0
#define WHITE       0xFFFF
#define ORANGE      0xFD20
#define GREENYELLOW 0xAFE5
#define NAVY        0x000F
#define DARKGREEN   0x03E0
#define DARKCYAN    0x03EF
#define MAROON      0x7800
#define PURPLE      0x780F
#define OLIVE       0x7BE0
#define LIGHTGREY   0xC618
#define DARKGREY    0x7BEF

Adafruit_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);
TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);
int i = 0;
TSPoint p;

void setup() {

  Serial.begin(115200);
  Serial.println(F("TFT LCD test"));

  randomSeed(analogRead(5));
  
  tft.reset();
  
  uint16_t identifier = bootSerial();

  tft.begin(identifier);

  
  delay(500);
  bootText();

  Serial.print(F("Screen fill              "));
  
  return 0;
}

void loop(void) {
  auto p = ts.getPoint();
  pinMode(LCD_CS, OUTPUT); 
  pinMode(LCD_CD, OUTPUT);
  
  if (p.z > ts.pressureThreshhold) {
    writeRandom();
  }
  delay(100);
}

int getRandomColor(){
  return random(0, 0xFFFF);
  }

String getRandom(){
    int dir = 0;
    int letter = 0;
    int num = 0;

    String str_dir, str_letter, str_num, str_output;

    dir = random(0,2);
    letter = random(0,26);
    num = random(1,31);

    str_dir = (dir == 0) ? "LEFT" : "RIGHT";
    str_letter = (char) (letter + 65);
    str_num = String(num);

    str_output = str_letter + " \n" + str_dir + " \n" + str_num;

    return str_output;
  };

void writeRandom(){
    String str; 
    Serial.print("X = "); Serial.print(p.x);
    Serial.print("\tY = "); Serial.print(p.y);
    Serial.print(F(" Screen fill              \n"));
    tft.fillScreen(getRandomColor());
    delay(1);
    tft.fillScreen(getRandomColor());
    delay(1);
    str = getRandom();
    tft.fillScreen(PURPLE);
    tft.setTextColor(CYAN);
    tft.setCursor(00, 20);
    tft.setTextSize(6);
    tft.println(str);

};

void printText(String text, uint16_t colour){
  tft.setTextColor(colour);
  tft.setCursor(90, 120);
  tft.setTextSize(1);
  tft.println(text);
};

void bootText(){
  delay(75);
  printText("Kitty", getRandomColor());
  delay(75);
  printText("Kitty", getRandomColor());
  delay(75);
  printText("Kitty", getRandomColor());
  delay(75);
  printText("Kitty", getRandomColor());
  delay(300);
  tft.fillScreen(PURPLE);
  delay(500);
};

uint16_t bootSerial(){
#ifdef USE_ADAFRUIT_SHIELD_PINOUT
  Serial.println(F("Using Adafruit 2.4\" TFT Arduino Shield Pinout"));
#else
  Serial.println(F("Using Adafruit 2.4\" TFT Breakout Board Pinout"));
#endif
  Serial.print("TFT size is ");
  Serial.print(tft.width());
  Serial.print("x");
  Serial.println(tft.height());

  uint16_t identifier = tft.readID();

  if (identifier == 0x9325) {
    Serial.println(F("Found ILI9325 LCD driver"));
  } else if (identifier == 0x9328) {
    Serial.println(F("Found ILI9328 LCD driver"));
  } else if (identifier == 0x7575) {
    Serial.println(F("Found HX8347G LCD driver"));
  } else if (identifier == 0x9341) {
    Serial.println(F("Found ILI9341 LCD driver"));
  } else if (identifier == 0x8357) {
    Serial.println(F("Found HX8357D LCD driver"));
  } else {
    Serial.print(F("Unknown LCD driver chip: "));
    Serial.println(identifier, HEX);
    Serial.println(F("If using the Adafruit 2.4\" TFT Arduino shield, the line:"));
    Serial.println(F("  #define USE_ADAFRUIT_SHIELD_PINOUT"));
    Serial.println(F("should appear in the library header (Adafruit_TFT.h)."));
    Serial.println(F("If using the breakout board, it should NOT be #defined!"));
    Serial.println(F("Also if using the breakout, double-check that all wiring"));
    Serial.println(F("matches the tutorial."));
    return;
  }

  Serial.println(F("Benchmark                Time (microseconds)"));
};
