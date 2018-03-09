#include "MusicBox.h"

MusicBox::MusicBox() {
  buzzerPin = -1;
}

MusicBox::~MusicBox() {

}

void MusicBox::setBuzzerPin(int pin) {
  buzzerPin = pin;
}

int MusicBox::getBuzzerPin() {
  return buzzerPin;
}

void MusicBox::setWholeNoteDuration(int length) {
	wholeNoteDuration = length;
}

int MusicBox::getWholeNoteDuration() {
	return wholeNoteDuration;
}

void MusicBox::setInternoteDelay(float delay) {
	internoteDelay = delay;
}

float MusicBox::getInternoteDelay() {
	return internoteDelay;
}

void MusicBox::playNote() {
	if (timer.isExpired()) {
		// change the state of the playingNote flag
		playingNote = false;

		// calculate the internote pause duration
		pauseDuration = (int)(noteDuration * internoteDelay);

		// restart the timer
		timer.start(pauseDuration);
	} else {
		// play the tone for one millisecond per pass)
	}
}

void MusicBox::playPause() {
	// test the timer to see if it has expired
	if (timer.isExpired() == true) {
		// change the state of the playingNote flag
		playingNote = true;

		// increment the current note in the melody
		currentNote += 1;

		// calculate the current note duration
		noteDuration = (int)(wholeNoteDuration / melody[currentNote][1])

		// restart the timer
		timer.start(noteDuration);
	}
}

void MusicBox::playMelody() {
	(playingNote == true) ? playNote() : playPause();
	}
}

void MusicBox::setMelody(int melody[][2], size_t size) {
	
}
