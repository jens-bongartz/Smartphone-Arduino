#include <TimerOne.h>
#include <Adafruit_NeoPixel.h>

#define PIN 6
#define NUMPIXELS 64
#define BRIGHTNESS 50

int posX = 4;
int posY = 4;
int fa = 1;
long counter = 0;
long counter_alt;

Adafruit_NeoPixel pixels(NUMPIXELS,PIN,NEO_GRB + NEO_KHZ800);

void setPixelXYColor(int x, int y, int r, int g, int b) {
    int index = (y-1)*8+(x-1);
    pixels.setPixelColor(index,r,g,b);   
}
void readCounter() {
  Serial.print(counter);
  Serial.print(" ; ");
  Serial.println(counter-counter_alt);
  counter_alt = counter;
}

void setup(){
    pixels.begin();
    pixels.setBrightness(BRIGHTNESS);
    Serial.begin(9600);
    Timer1.initialize(1000000/fa);             
    Timer1.attachInterrupt(readCounter);     
}

void loop(){
    // Mögliche Bewegungsrichtungen
    // Y| X 1 + +
    // ----------- 
    // 1|   7 0 1
    // +|   6 X 2
    // +|   5 4 3
    // 
    // Würfeln zwischen 0 und 7
    int direction = int(random(8));
    // Abhängig 
    switch(direction) {
      case 0:
        if (posY > 1) { 
          posY--;
        }
        break;
      case 1:
        if ((posX < 8) && (posY > 1)){
          posX++;
          posY--;
        }
        break;
      case 2:
        if (posX < 8) {
          posX++;
        }
        break;
      case 3:
        if ((posX < 8) && (posY < 8)){
          posX++;
          posY++;
        }
        break;
      case 4:
        if (posY < 8) { 
          posY++;
        }
        break;
      case 5:
        if ((posX > 1) && (posY < 8)){
          posX--;
          posY++;
        }
        break;
      case 6:
        if (posX > 1) {
          posX--;
        }
        break;
      case 7:
        if ((posX > 1) && (posY > 1)){
          posX--;
          posY--;
        }
        break;        
    }
    pixels.clear(); 
    setPixelXYColor(posX, posY, 255, 0, 0);
    pixels.show();
    counter++;
    //delay(50);
}
