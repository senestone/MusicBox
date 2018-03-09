#include <MusicBox.h>
#include "melody.h"

#include <SoftwareSerial.h>

MusicBox player;

void setup() {
  Serial.begin(9600);

  // set the pin number associated with the buzzer
  player.setBuzzerPin(8);

	// set the desired length of a whole note
	player.setWholeNoteDuration(1250);

	// set the delay between the notes
	player.setInternoteDelay(1.3);
}

void loop() {
  // do main logic here
}
