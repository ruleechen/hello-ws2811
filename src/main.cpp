#include <vector>
#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

// Which pin on the Arduino is connected to the NeoPixels?
int pin = 0;

// How many NeoPixels are attached to the Arduino?
int numPixels = 2;

// NeoPixel color format & data rate. See the strandtest example for information on possible values.
int pixelFormat = NEO_RGB + NEO_KHZ800;

Adafruit_NeoPixel *pixels;
std::vector<uint32_t> colors;

void setup() {
  Serial.begin(115200);

  pixels = new Adafruit_NeoPixel(numPixels, pin, pixelFormat);
  pixels->setBrightness(20);
  pixels->begin();

  colors.push_back(pixels->Color(255, 0, 0)); // red
  colors.push_back(pixels->Color(0, 255, 0)); // green
  colors.push_back(pixels->Color(0, 0, 255)); // blue

  pixels->clear(); // Set all pixel colors to 'off'
  pixels->show();  // Send the updated pixel colors to the hardware.

  Serial.println("setup");
}

int times = 0;

void loop() {
  times += 1;
  auto index = times % 3;
  Serial.println(index);

  pixels->setPixelColor(0, colors[index]);
  pixels->show();
  delay(500);

  pixels->setPixelColor(1, colors[index]);
  pixels->show();
  delay(500);
}
