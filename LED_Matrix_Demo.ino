#include <Adafruit_NeoPixel.h>

#define PIN 6
#define NUMPIXELS 64
#define BRIGHTNESS 50

Adafruit_NeoPixel pixels(NUMPIXELS,PIN,NEO_GBR + NEO_KHZ800);

void setup(){
    pixels.begin();
    pixels.setBrightness(BRIGHTNESS);
}

void loop(){
    pixels.clear();
    pixels.setPixelColor(27,255,0,0);
    pixels.setPixelColor(28,0,255,0);
    pixels.setPixelColor(35,0,0,255);
    pixels.setPixelColor(36,85,85,85);
    pixels.show();
}