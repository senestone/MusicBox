
#pragma #ifndef

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
	int *melody[2];
	float internoteDelay;
	ActionTimer timer;

	void playNote();

	void playPause();

public:
	// constructor
	MusicBox();

	// destructor
	~MusicBox();

  void playMelody();

  void setMelody(int melody[][2]);
  void getMelody();

	void setBuzzerPin(int port);
	int getBuzzerPin();

	void setWholeNoteDuration(int length);
	int getWholeNoteDuration();

	void setInternoteDelay(float delay);
	float getInternoteDelay();
};

#endif /* end of include guard: */
