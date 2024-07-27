/// @file    Blink.ino
/// @brief   Blink the first LED of an LED strip
/// @example Blink.ino

#include <FastLED.h>

// How many leds in your strip?
const int NUM_STRIPS = 12;
const int NUM_LEDS_PER_STRIP = 13;
const int NUM_LEDS = NUM_STRIPS * NUM_LEDS_PER_STRIP;

#define DATA_PIN 16

// Define the array of leds
CRGB leds[NUM_LEDS];
byte halfBright = 80;
byte fullBright = 255;
int switchTime = 15;

// Function to convert text format to 2D array of CRGB colors
void textToColorArray(char text[NUM_STRIPS][NUM_LEDS_PER_STRIP], CRGB colors[NUM_STRIPS][NUM_LEDS_PER_STRIP]) {
  for (int row = 0; row < NUM_STRIPS; row++) {
    for (int col = 0; col < NUM_LEDS_PER_STRIP; col++) {
      // Map char to CRGB
      char pixelColor = text[row][col];
      CRGB color;
      if (pixelColor == 'R')
        color = CRGB::Red;
      else if (pixelColor == 'O')
        color = CRGB::Orange;
      else if (pixelColor == 'Y')
        color = CRGB::Yellow;
      else if (pixelColor == 'G')
        color = CRGB::Green;
      else if (pixelColor == 'B')
        color = CRGB::Black;
      else if (pixelColor == 'U')
        color = CRGB::Blue;
      else if (pixelColor == 'P')
        color = CRGB::Purple;
      else if (pixelColor == 'W')
        color = CRGB::White;
      else
        color = CRGB::Black; // Default to Black if pixel color not recognized
      // Assign color to array
      colors[row][col] = color;
    }
  }
}

// Function to set and display all LEDs based on the 2D array of colors, displaying the image upside down
void displayLEDs(char text[NUM_STRIPS][NUM_LEDS_PER_STRIP]) {
  CRGB colors[NUM_STRIPS][NUM_LEDS_PER_STRIP];
  textToColorArray(text, colors);
  int ledIndex = 0;
  for (int row = NUM_STRIPS - 1; row >= 0; row--) { // Iterate rows in reverse order
    if (row % 2 == 0) {
      // Forward direction for even-indexed rows
      for (int col = 0; col < NUM_LEDS_PER_STRIP; col++) {
        leds[ledIndex++] = colors[row][col];
      }
    } else {
      // Reverse direction for odd-indexed rows
      for (int col = NUM_LEDS_PER_STRIP - 1; col >= 0; col--) {
        leds[ledIndex++] = colors[row][col];
      }
    }
  }
  // Show all LEDs
  FastLED.setBrightness(halfBright);
  FastLED.show();
}

char UF[][NUM_LEDS_PER_STRIP] = {
                  {'U', 'B', 'B', 'B', 'B', 'U', 'B', 'R', 'R', 'R', 'R', 'R', 'R'},
                  {'U', 'B', 'B', 'B', 'B', 'U', 'B', 'R', 'B', 'B', 'B', 'B', 'B'},
                  {'U', 'B', 'B', 'B', 'B', 'U', 'B', 'R', 'B', 'B', 'B', 'B', 'B'},
                  {'U', 'B', 'B', 'B', 'B', 'U', 'B', 'R', 'B', 'B', 'B', 'B', 'B'},
                  {'U', 'B', 'B', 'B', 'B', 'U', 'B', 'R', 'B', 'B', 'B', 'B', 'B'},
                  {'U', 'B', 'B', 'B', 'B', 'U', 'B', 'R', 'R', 'R', 'R', 'R', 'R'},
                  {'U', 'B', 'B', 'B', 'B', 'U', 'B', 'R', 'B', 'B', 'B', 'B', 'B'},
                  {'U', 'B', 'B', 'B', 'B', 'U', 'B', 'R', 'B', 'B', 'B', 'B', 'B'},
                  {'U', 'B', 'B', 'B', 'B', 'U', 'B', 'R', 'B', 'B', 'B', 'B', 'B'},
                  {'U', 'B', 'B', 'B', 'B', 'U', 'B', 'R', 'B', 'B', 'B', 'B', 'B'},
                  {'U', 'B', 'B', 'B', 'B', 'U', 'B', 'R', 'B', 'B', 'B', 'B', 'B'},
                  {'U', 'U', 'U', 'U', 'U', 'U', 'B', 'R', 'B', 'B', 'B', 'B', 'B'}
                };

char numbah1[][NUM_LEDS_PER_STRIP] = {
                  {'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'U', 'B', 'B'},
                  {'B', 'R', 'B', 'B', 'R', 'B', 'B', 'B', 'B', 'U', 'U', 'B', 'B'},
                  {'B', 'R', 'B', 'B', 'R', 'B', 'B', 'B', 'U', 'B', 'U', 'B', 'B'},
                  {'R', 'R', 'R', 'R', 'R', 'R', 'B', 'B', 'B', 'B', 'U', 'B', 'B'},
                  {'B', 'R', 'B', 'B', 'R', 'B', 'B', 'B', 'B', 'B', 'U', 'B', 'B'},
                  {'B', 'R', 'B', 'B', 'R', 'B', 'B', 'B', 'B', 'B', 'U', 'B', 'B'},
                  {'B', 'R', 'B', 'B', 'R', 'B', 'B', 'B', 'B', 'B', 'U', 'B', 'B'},
                  {'B', 'R', 'B', 'B', 'R', 'B', 'B', 'B', 'B', 'B', 'U', 'B', 'B'},
                  {'R', 'R', 'R', 'R', 'R', 'R', 'B', 'B', 'B', 'B', 'U', 'B', 'B'},
                  {'B', 'R', 'B', 'B', 'R', 'B', 'B', 'B', 'B', 'B', 'U', 'B', 'B'},
                  {'B', 'R', 'B', 'B', 'R', 'B', 'B', 'B', 'B', 'B', 'U', 'B', 'B'},
                  {'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'U', 'U', 'U', 'U', 'U'}
                };

char Blank[][NUM_LEDS_PER_STRIP] = {
                  {'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B'},
                  {'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B'},
                  {'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B'},
                  {'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B'},
                  {'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B'},
                  {'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B'},
                  {'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B'},
                  {'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B'},
                  {'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B'},
                  {'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B'},
                  {'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B'},
                  {'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B'}
                };

  char TEST[][NUM_LEDS_PER_STRIP] = {
                  {'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G'},
                  {'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G'},
                  {'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G'},
                  {'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G'},
                  {'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G'},
                  {'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G'},
                  {'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G'},
                  {'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G'},
                  {'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G'},
                  {'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G'},
                  {'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G'},
                  {'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G'}
                };
          
  char Albert[][NUM_LEDS_PER_STRIP] = {
                  {'B', 'B', 'B', 'B', 'B', 'R', 'R', 'B', 'B', 'B', 'B', 'B', 'B'},
                  {'B', 'B', 'B', 'B', 'B', 'R', 'R', 'R', 'R', 'B', 'B', 'B', 'B'},
                  {'B', 'B', 'B', 'B', 'G', 'G', 'G', 'G', 'B', 'B', 'G', 'B', 'B'},
                  {'B', 'B', 'B', 'B', 'G', 'W', 'U', 'G', 'G', 'G', 'B', 'B', 'B'},
                  {'B', 'B', 'B', 'B', 'G', 'G', 'G', 'G', 'G', 'W', 'B', 'B', 'B'},
                  {'B', 'B', 'B', 'R', 'R', 'G', 'G', 'R', 'R', 'B', 'B', 'B', 'B'},
                  {'B', 'B', 'R', 'R', 'R', 'R', 'R', 'R', 'R', 'R', 'B', 'B', 'B'},
                  {'B', 'B', 'G', 'R', 'B', 'R', 'R', 'G', 'R', 'G', 'B', 'B', 'B'},
                  {'B', 'G', 'B', 'B', 'B', 'R', 'R', 'G', 'B', 'B', 'B', 'B', 'B'},
                  {'B', 'B', 'G', 'G', 'G', 'G', 'G', 'G', 'B', 'B', 'B', 'B', 'B'},
                  {'B', 'B', 'B', 'B', 'G', 'G', 'B', 'G', 'G', 'B', 'B', 'B', 'B'},
                  {'B', 'B', 'B', 'B', 'G', 'G', 'B', 'G', 'G', 'B', 'B', 'B', 'B'}
                };

  char Gator[][NUM_LEDS_PER_STRIP] = {
                  {'B', 'B', 'B', 'G', 'B', 'B', 'G', 'B', 'B', 'B', 'B', 'B', 'B'},
                  {'B', 'B', 'G', 'G', 'G', 'G', 'G', 'G', 'B', 'B', 'B', 'B', 'B'},
                  {'B', 'G', 'G', 'U', 'W', 'G', 'G', 'G', 'G', 'G', 'B', 'B', 'G'},
                  {'B', 'G', 'G', 'W', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G'},
                  {'G', 'G', 'G', 'G', 'G', 'W', 'G', 'W', 'G', 'W', 'G', 'W', 'B'},
                  {'B', 'G', 'G', 'G', 'G', 'G', 'W', 'B', 'W', 'B', 'W', 'B', 'B'},
                  {'G', 'G', 'G', 'G', 'G', 'R', 'R', 'W', 'R', 'W', 'B', 'W', 'B'},
                  {'B', 'G', 'G', 'G', 'G', 'R', 'W', 'R', 'W', 'R', 'W', 'R', 'W'},
                  {'B', 'B', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G'},
                  {'B', 'B', 'B', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'B', 'B'},
                  {'B', 'B', 'B', 'B', 'B', 'G', 'G', 'G', 'B', 'B', 'B', 'B', 'B'},
                  {'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B'}
                };  

char Sean[][NUM_LEDS_PER_STRIP] = {
                  {'B', 'B', 'B', 'B', 'R', 'R', 'B', 'R', 'R', 'B', 'B', 'B', 'B'},
                  {'B', 'B', 'R', 'R', 'R', 'R', 'B', 'R', 'R', 'R', 'R', 'B', 'B'},
                  {'B', 'R', 'R', 'R', 'R', 'R', 'B', 'R', 'R', 'R', 'R', 'R', 'B'},
                  {'B', 'R', 'R', 'R', 'R', 'R', 'B', 'R', 'R', 'R', 'G', 'R', 'B'},
                  {'R', 'R', 'R', 'G', 'R', 'R', 'R', 'R', 'R', 'G', 'Y', 'R', 'R'},
                  {'R', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'Y', 'R', 'R', 'R'},
                  {'U', 'U', 'U', 'Y', 'G', 'Y', 'Y', 'G', 'Y', 'U', 'U', 'U', 'U'},
                  {'U', 'U', 'U', 'U', 'G', 'U', 'U', 'G', 'U', 'U', 'U', 'U', 'U'},
                  {'B', 'U', 'U', 'U', 'U', 'U', 'U', 'B', 'B', 'B', 'B', 'B', 'B'},
                  {'B', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'B'},
                  {'B', 'B', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'B'},
                  {'B', 'B', 'B', 'B', 'B', 'U', 'U', 'U', 'B', 'B', 'B', 'B', 'B'}
                };                      

void setup() { 
    FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);  // GRB ordering is assumed
}

void loop() { 
  displayLEDs(Gator);
  delay(switchTime * 1000);
  displayLEDs(numbah1);
  delay(switchTime * 1000);
  displayLEDs(Albert);
  delay(switchTime * 1000);
  displayLEDs(Sean);
  delay(switchTime * 1000);
  displayLEDs(UF);
  delay(switchTime * 1000);
}
