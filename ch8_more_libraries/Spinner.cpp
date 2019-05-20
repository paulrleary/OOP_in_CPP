#include "Arduino.h"
#include <Adafruit_NeoPixel.h>
#include "Spinner.h"

Spinner::Spinner(int pin, int interval)
{
	ringPin = pin;
	updateInterval = interval;
	ring = Adafruit_NeoPixel(24, ringPin, NEO_GRB + NEO_KHZ800);

	ring.begin();
	ring.show();

	color = ring.Color(0,50,0);

	lastUpdate = millis();
}

void Spinner::Update()
{
	if((millis() - lastUpdate)>updateInterval){
		lastUpdate = millis();

		int prev_pixel = pixel;

		if ((angle >= 180)){
			angle = -180;
		}
		angle += updateIncrement;
		pixel = pixelAngle(angle);
		ring.setPixelColor(prev_pixel, 0);
		ring.setPixelColor(pixel, color);
    ring.show();

	}

}

int Spinner::pixelAngle(int angle){

  int pixel = angle*24/360;
  pixel+=12;
  return pixel;
}
