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

  Serial.print("Size of melody: " + String(sizeof(melody) / sizeof(melody[0])));
  // set the melody to be played
  player.setMelody(melody, sizeof(melody) / sizeof(melody[0]));

  // set the starting position
  player.setCurrentNote(0);
}

void loop() {
  // do main logic here
  player.playMelody();
}
