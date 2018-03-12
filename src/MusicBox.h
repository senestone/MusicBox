
/***********************************************************************
 * Program:     MusicBox
 *
 * Author:      Charles McKnight
 *
 * File:      MusicBox.h
 *
 * Description:
 *  This file contains the class definition of the MusicBox class.
 ***********************************************************************/
#pragma once

#ifndef MUSICBOX
#define MUSICBOX

#include <Arduino.h>
#include <ActionTimer.h>
#include <SoftwareSerial.h>

class MusicBox {
private:
	int buzzerPin;					// pin associated with the piezobuzzer
	int currentNote;				// current note counter
	int noteDuration;				// note duration from melody array
	int pauseDuration;			// calculated pause duration
	bool playingNote;				// state flag indicating note or pause is being played
	int wholeNoteDuration;	// duration of a whole note in milliseconds
	int melodySize;					// size of the current melody array
	int (*melody)[2];				// pointer to the current melody array
	float internoteDelay;		// factor to pause between notes
	bool melodyOver;				// flag to indicate that the melody has ended
	ActionTimer timer;			// timer object used to control play times

	void playNote();				// private method to play a single note

	void playPause();				// private method to play an internote pause

public:
	// constructor
	MusicBox(int pin	);

	// destructor
	~MusicBox();

	// main play method
  void playMelody();

	// test to determine whether or not melody has finished
	bool isMelodyOver();

	// setters (mutators) for private attributes
	void setBuzzerPin(int port);
	void setCurrentNote(int pos);
	void setInternoteDelay(float delay);
  void setMelody(int melody[][2], size_t size);
	void setWholeNoteDuration(int length);
};

#endif /* end of include guard: */
