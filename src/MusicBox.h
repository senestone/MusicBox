
#pragma once

#ifndef MUSICBOX
#define MUSICBOX

#include <Arduino.h>
#include <ActionTimer.h>

class MusicBox {
private:
	int buzzerPin;
	int currentNote;
	int noteDuration;
	int pauseDuration;
	bool playingNote;
	int wholeNoteDuration;
	int melodySize;
	int (*melody)[2];
	float internoteDelay;
	ActionTimer timer;

	void playNote();

	void playPause();

public:
	// constructor
	MusicBox();

	// destructor
	~MusicBox();

	// main play method
  void playMelody();

	// setters (mutators) for private attributes
  void setMelody(int melody[][2], size_t size);
	void setBuzzerPin(int port);
	void setWholeNoteDuration(int length);
	void setInternoteDelay(float delay);
	void setCurrentNote(int pos);
};

#endif /* end of include guard: */
