/***********************************************************************
 * Program:     MusicBox
 *
 * Author:      Charles McKnight
 *
 * Description:
 *   This file contains the implementation of the MusicBox class.
 ***********************************************************************/

#include "MusicBox.h"

/***********************************************************************
 * Method:      MusicBox::MusiBox
 *
 * Arguments:   pin - pin associated with the piezobuzzer
 *
 * Returns:     Fully constructed MusicBox object
 *
 * Description:
 *   This is the constructor for the MusicBox class.
 ***********************************************************************/
MusicBox::MusicBox(int pin) {
  buzzerPin = pin;
}


/***********************************************************************
 * Method:      MusicBox::~MusicBox
 *
 * Arguments:   N/A
 *
 * Returns:     N/A
 *
 * Description:
 *   This is the destructor for the MusicBox class.
 ***********************************************************************/
MusicBox::~MusicBox() {
}


/***********************************************************************
 * Method:      MusicBox::setBuzzerPin
 *
 * Arguments:   pin - pin associated with the piezobuzzer
 *
 * Returns:     N/A
 *
 * Description:
 *   This method sets the pin associated with the piezobuzzer.
 ***********************************************************************/
void MusicBox::setBuzzerPin(int pin) {
  buzzerPin = pin;
}


/***********************************************************************
 * Method:      MusicBox::setWholeNoteDuration
 *
 * Arguments:   length - length of a whole note in milliseconds
 *
 * Returns:     M/A
 *
 * Description:
 *   This method sets the length of a whole note in milliseconds. This
 * value is used to calculate note durations and internote pauses.
 ***********************************************************************/
void MusicBox::setWholeNoteDuration(int length) {
	wholeNoteDuration = length;
}


/***********************************************************************
 * Method:      MusicBox::setInternoteDelay
 *
 * Arguments:   delay - delay factor used to calculate internote pauses.
 *
 * Returns:     N/A
 *
 * Description:
 *   This method sets the factor used to calculate internote pauses.
 ***********************************************************************/
void MusicBox::setInternoteDelay(float delay) {
	internoteDelay = delay;
}


/***********************************************************************
 * Method:      MusicBox::setMelody
 *
 * Arguments:   melodyArray - array of tones and their durations
 *                     size - size of the array
 *
 * Returns:     N/A
 *
 * Description:
 *   This method allows the program to set the current melody.
 ***********************************************************************/
void MusicBox::setMelody(int melodyArray[][2], size_t size) {
  // assign argument values to class variables
  melody = melodyArray;
  melodySize = size;

  // reset the note counter to the beginning of the melody
  setCurrentNote(0);

  // set the note duration for the first note
  noteDuration = (int)(wholeNoteDuration / melody[currentNote][1]);

  // set playingState to true
  melodyOver = false;
}


/***********************************************************************
 * Method:      MusicBox::setCurrentNote
 *
 * Arguments:   pos - position in the melody array
 *
 * Returns:     N/A
 *
 * Description:
 *   This method allows the program to specify the current position in
 * the melody array.
 ***********************************************************************/
void MusicBox::setCurrentNote(int pos) {
  currentNote = pos;
}


/***********************************************************************
 * Method:      MusicBox::playNote
 *
 * Arguments:   N/A
 *
 * Returns:     N/A
 *
 * Description:
 *   This method manages playing a single note and changing state to
 * play a pause when the note’s duration has expired.
 ***********************************************************************/
void MusicBox::playNote() {
  ActionTimer lclTimer;

	if (timer.isExpired()) {
		// change the state of the playingNote flag
		playingNote = false;

		// calculate the internote pause duration
		pauseDuration = (int)(noteDuration * internoteDelay);

		// restart the timer
		timer.start(pauseDuration);
	} else {
		// play the tone for one millisecond per pass)
    tone(buzzerPin, melody[currentNote][0], noteDuration);
	}
}


/***********************************************************************
 * Method:      MusicBox::playPause
 *
 * Arguments:   N/A
 *
 * Returns:     N/A
 *
 * Description:
 *   This method manages playing an internote pause and changing state
 * to play a note when the internote pause duration has expired.
 ***********************************************************************/
void MusicBox::playPause() {

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


/***********************************************************************
 * Method:      MusicBox::playMelody
 *
 * Arguments:   N/A
 *
 * Returns:     N/A
 *
 * Description:
 *   This method manages playing the melody in a non-blocking fashion.
 ***********************************************************************/
void MusicBox::playMelody() {
  if (currentNote < melodySize) {
	   (playingNote == true) ? playNote() : playPause();
   } else {
     melodyOver = true;
   }
}


/***********************************************************************
 * Method:      MusicBox::isMelodyOver
 *
 * Arguments:   N/A
 *
 * Returns:      true - melody has finished playing
 *              false - melody is still playing
 *
 * Description:
 *   This method allows a program to determine whether or not the
 * melody is still being played.
 ***********************************************************************/
bool MusicBox::isMelodyOver() {
  return melodyOver;
}
