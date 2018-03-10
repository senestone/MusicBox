#include "MusicBox.h"

MusicBox::MusicBox() {
  buzzerPin = -1;
}

MusicBox::~MusicBox() {

}

void MusicBox::setBuzzerPin(int pin) {
  buzzerPin = pin;
}

void MusicBox::setWholeNoteDuration(int length) {
	wholeNoteDuration = length;
}

void MusicBox::setInternoteDelay(float delay) {
	internoteDelay = delay;
}

void MusicBox::playNote() {
  Serial.print("playNote: " + String(currentNote) + "\n");

	if (timer.isExpired()) {
		// change the state of the playingNote flag
		playingNote = false;

		// calculate the internote pause duration
		pauseDuration = (int)(noteDuration * internoteDelay);

		// restart the timer
		timer.start(pauseDuration);
	} else {
		// play the tone for one millisecond per pass)
    digitalWrite(buzzerPin, melody[currentNote]);
	}
}

void MusicBox::playPause() {
  Serial.print("playPause: " + String(currentNote) + "\n");

	// test the timer to see if it has expired
	if (timer.isExpired() == true) {
		// change the state of the playingNote flag
		playingNote = true;

		// increment the current note in the melody
		currentNote += 1;

		// calculate the current note duration
		noteDuration = (int)(wholeNoteDuration / melody[currentNote][1]);

		// restart the timer
		timer.start(noteDuration);
	}
}

void MusicBox::playMelody()
  if (currentNote < melodySize) {
	   (playingNote == true) ? playNote() : playPause();
   }
}

void MusicBox::setMelody(int melodyArray[][2], size_t size) {
  melody = melodyArray;
  melodySize = size;
}

void MusicBox::setCurrentNote(int pos) {
  currentNote = pos;
}
