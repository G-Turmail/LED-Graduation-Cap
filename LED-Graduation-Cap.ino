#include <FastLED.h>

// Define LED matrix parameters
const int NUM_STRIPS = 12;
const int NUM_LEDS_PER_STRIP = 13;
const int NUM_LEDS = NUM_STRIPS * NUM_LEDS_PER_STRIP;
#define DATA_PIN 16

// Define the array of leds
CRGB leds[NUM_LEDS];
byte halfBright = 50;
byte fullBright = 255;

// Function to set colors of the entire LED matrix
void setMatrixColors(CRGB colors[NUM_STRIPS][NUM_LEDS_PER_STRIP]) {
  for (int strip = 0; strip < NUM_STRIPS; strip++) {
    for (int led = 0; led < NUM_LEDS_PER_STRIP; led++) {
      leds[strip * NUM_LEDS_PER_STRIP + led] = colors[strip][led];
    }
  }
  FastLED.setBrightness(halfBright);
  FastLED.show();
}

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

void setup() { 
    FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);  // GRB ordering is assumed
}

void loop() {
  // Example usage
  String textImage1 = "Red Red Red Red Red Red Red Red Red Red Red Red Red "  // Row 1
                    "Orange Orange Orange Orange Orange Orange Orange Orange Orange Orange Orange Orange Orange " // Row 2
                    "Yellow Yellow Yellow Yellow Yellow Yellow Yellow Yellow Yellow Yellow Yellow Yellow Yellow " // Row 3
                    "Green Green Green Green Green Green Green Green Green Green Green Green Green " // Row 4
                    "Blue Blue Blue Blue Blue Blue Blue Blue Blue Blue Blue Blue Blue " // Row 5
                    "Purple Purple Purple Purple Purple Purple Purple Purple Purple Purple Purple Purple Purple " // Row 6
                    "Red Red Red Red Red Red Red Red Red Red Red Red Red " // Row 7
                    "Orange Orange Orange Orange Orange Orange Orange Orange Orange Orange Orange Orange Orange " // Row 8
                    "Yellow Yellow Yellow Yellow Yellow Yellow Yellow Yellow Yellow Yellow Yellow Yellow Yellow " // Row 9
                    "Green Green Green Green Green Green Green Green Green Green Green Green Green " // Row 10
                    "Blue Blue Blue Blue Blue Blue Blue Blue Blue Blue Blue Blue Blue " // Row 11
                    "Purple Purple Purple Purple Purple Purple Purple Purple Purple Purple Purple Purple Purple"; // Row 12
  
  CRGB colors1[NUM_STRIPS][NUM_LEDS_PER_STRIP]; // Declare a 2D array of RGB colors for image 1
  
  // Convert text format to color arrays
  textToColorArray(textImage1, colors1);
  
  // Set the LED matrix to the first image
  setMatrixColors(colors1);

  delay(50000);
}
