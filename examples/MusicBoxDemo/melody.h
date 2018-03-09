/*
  Melody adapted from Arduino Mario Bros Tunes With Piezo Buzzer and PWM
  by: Dipto Pratyaksa
  last updated: 31/3/13

  https://create.arduino.cc/projecthub/jrance/super-mario-theme-song-w-piezo-buzzer-and-arduino-1cc2e4

  Melody was rearranged into a single array of tones and durations.
*/

#ifndef MELODY
#define MELODY

#include "pitches.h"

// The melody array contains the tone, duration, and inter-note
// pause duration (the last item is calculated based on the
//internote_pause value. A zero in the tone position indicates a rest.
int melody[][2] = {
  { NOTE_E6,  12}, { NOTE_E6,  12}, { SILENCE,  12},
  { NOTE_E6,  12}, { SILENCE,  12}, { NOTE_C6,  12},
  { NOTE_E6,  12}, { SILENCE,  12}, { NOTE_G6,  12},
  { SILENCE,  12}, { SILENCE,  12}, { SILENCE,  12},
  { NOTE_G5,  12}, { SILENCE,  12}, { SILENCE,  12},
  { SILENCE,  12}, { NOTE_C6,  12}, { SILENCE,  12},
  { SILENCE,  12}, { NOTE_G5,  12}, { SILENCE,  12},
  { SILENCE,  12}, { NOTE_E5,  12}, { SILENCE,  12},
  { SILENCE,  12}, { NOTE_A5,  12}, { SILENCE,  12},
  { NOTE_B5,  12}, { SILENCE,  12}, { NOTE_AS5, 12},
  { NOTE_A5,  12}, { SILENCE,  12}, { NOTE_G5,   9},
  { NOTE_E6,   9}, { NOTE_G6,   9}, { NOTE_A6,  12},
  { SILENCE,  12}, { NOTE_F6,  12}, { NOTE_G6,  12},
  { SILENCE,  12}, { NOTE_E6,  12}, { SILENCE,  12},
  { NOTE_C6,  12}, { NOTE_D6,  12}, { NOTE_B5,  12},
  { SILENCE,  12}, { SILENCE,  12}, { NOTE_C6,  12},
  { SILENCE,  12}, { SILENCE,  12}, { NOTE_G5,  12},
  { SILENCE,  12}, { SILENCE,  12}, { NOTE_E5,  12},
  { SILENCE,  12}, { SILENCE,  12}, { NOTE_A5,  12},
  { SILENCE,  12}, { NOTE_B5,  12}, { SILENCE,  12},
  { NOTE_AS5, 12}, { NOTE_A5,  12}, { SILENCE,  12},
  { NOTE_G5,   9}, { NOTE_E6,   9}, { NOTE_G6,   9},
  { NOTE_A6,  12}, { SILENCE,  12}, { NOTE_F6,  12},
  { NOTE_G6,  12}, { SILENCE,  12}, { NOTE_E6,  12},
  { SILENCE,  12}, { NOTE_C6,  12}, { NOTE_D6,  12},
  { NOTE_B5,  12}, { SILENCE,  12}, { SILENCE,  12},
};
#endif
