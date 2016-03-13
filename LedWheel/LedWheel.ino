#include "FastLED.h"
#include "led.h"
#include "C:\Users\Dan\Desktop\LedWheelMavlink\Arduino\ledwheel\mavlink.h"

#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB
#define NUM_LEDS    36

#define BRIGHTNESS 100

const uint8_t LED0 = 0;
const uint8_t LED90 = 1;
const uint8_t LED180 = 2;
const uint8_t LED270 = 3;

CRGB leds0[NUM_LEDS];
CRGB leds90[NUM_LEDS];
CRGB leds180[NUM_LEDS];
CRGB leds270[NUM_LEDS];

void setup() {
	FastLED.addLeds<LED_TYPE, 5, COLOR_ORDER>(leds0, NUM_LEDS).setCorrection(TypicalLEDStrip);
	FastLED.addLeds<LED_TYPE, 4, COLOR_ORDER>(leds90, NUM_LEDS).setCorrection(TypicalLEDStrip);
	FastLED.addLeds<LED_TYPE, 2, COLOR_ORDER>(leds180, NUM_LEDS).setCorrection(TypicalLEDStrip);
	FastLED.addLeds<LED_TYPE, 6, COLOR_ORDER>(leds270, NUM_LEDS).setCorrection(TypicalLEDStrip);

	FastLED.setBrightness(BRIGHTNESS);
	FastLED.setMaxRefreshRate(100, true);

	Serial.begin(57600);

	FastLED.showColor(HUE_GREEN);
	FastLED.show();
}

void loop() {
}

void serialEvent() {
	mavlink_message_t msg;
	mavlink_status_t status;

	while (Serial.available() > 0)
	{
		uint8_t c = Serial.read();
		// Try to get a new message
		if (mavlink_parse_char(MAVLINK_COMM_0, c, &msg, &status)) {
			// Handle message

			switch (msg.msgid)
			{
				case MAVLINK_MSG_ID_SET_RGB:
				{
					__mavlink_set_rgb_t setRGB;
					mavlink_msg_set_rgb_decode(&msg, &setRGB);

					switch (setRGB.led_number) {
					case LED0:
						setLeds(leds0, setRGB.led_strip_colors);
						break;
					case LED90:
						setLeds(leds90, setRGB.led_strip_colors);
						break;
					case LED180:
						setLeds(leds180, setRGB.led_strip_colors);
						break;
					case LED270:
						setLeds(leds270, setRGB.led_strip_colors);
						break;
						FastLED.show();
					} //end set led color
				} //end MAVLINK_MSG_ID_SET_RGB
				default:
					break;
			}//end switch
		} //end if
	} //end while
}

void setLeds(CRGB ledStrip[NUM_LEDS], uint8_t led_colors[36]) {
	for (int counter = 0; counter < 36; counter++) {
		ledStrip[counter].setColorCode8Bit(led_colors[counter]);
	}
}
/*float updateCurrentAngle() {
  long timeElapsed = millis() - startTimeOfRotation;
  if(timeElapsed >= TIMEONEROTATION)
  {
	timeElapsed = 0;
	startTimeOfRotation = millis();
  }

  return 2 * PI * (timeElapsed / TIMEONEROTATION);
}

Coordinate getXY(Coordinate origin, float radius, float angle) {
	xy.x = origin.x + radius * cos(angle);
	xy.y = origin.y + radius * sin(angle);
  return xy;
}
*/