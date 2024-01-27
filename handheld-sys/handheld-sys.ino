/*
  This is the main script for a pseudo assembly language interpreter I'm developing. Enjoy!

  Oh, and it incorporates `Adafruit_GFX.h` and `Adafruit_SSD1306.h`
  as well as `SparkFun_Qwiic_OpenLog_Arduino_Library.h`. Be sure to have those installed!

  Author: Brett Warren
*/

#include <Wire.h>
#include <SparkFun_Qwiic_OpenLog_Arduino_Library.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Constants.
#define UP_BUTTON 32
#define DOWN_BUTTON 33
#define LEFT_BUTTON 26
#define RIGHT_BUTTON 25

#define SCREEN_ADDR 0x3C
#define SCREEN_X 128
#define SCREEN_Y 64

// Memory and registers. Note that the display buffer is allocated in a function called later.
int16_t regs[26];  // 26 16-bit registers -- one for each letter of the alphabet.
int16_t ram[51200];  // 100 kB for the stack and the heap. I don't feel the need for this to be any bigger.

// Variables necessary for navigation.
unsigned long stackPointer = 0;
unsigned long heapPointer = 51199;
unsigned long programCounter = 0;

// Enumeration of the different instructions.
enum INSTRUCTION_TYPE {
  NO_OP,
  ADDITION,
  SUBTRACTION,
  AND_OPERATION,
  OR_OPERATION,
  XOR_OPERATION,
  NOT_OPERATION,
  JUMP_UNCONDITIONAL,
  JUMP_GREATER_EQUAL,
  STORE_MEMORY,
  LOAD_MEMORY,
} instructionType = NO_OP;

// Object instantiations.
Adafruit_SSD1306 display(SCREEN_X, SCREEN_Y, &Wire, -1);
OpenLog card;

void setup() {
  Serial.begin(115200);
  memset(&regs, 0, 26 * 2);
  memset(&ram, 0, 51200 * 2);
  // FIXME: Set up interrupts for the button inputs.

  if (!display.begin(SSD1306_SWITCHCAPVCC, screenAddr)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ;
  }

  display.clearDisplay();
  display.display();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  if (!card.begin()) {
    Serial.println("Error reading SD card. Is it plugged in?");
    display.setCursor(0, 0);
    display.print("No card inserted.");
    display.display();
    while(true);
  } else Serial.println("Card read successful.");
}

void loop() {
  // FIXME: Implement reading a line from the SD card.
  // FIXME: Implement interpretation of the line read.
  // FIXME: IDK what else needs to be done...
}
