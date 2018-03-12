/*
  Melody adapted from Arduino Mario Bros Tunes With Piezo Buzzer and PWM
  by: Dipto Pratyaksa
  last updated: 31/3/13

  https://create.arduino.cc/projecthub/jrance/super-mario-theme-song-w-piezo-buzzer-and-arduino-1cc2e4

  Each melody was rearranged into a single array of tones and durations.
*/

#ifndef MELODY
#define MELODY

#include "pitches.h"

const int OVERWORLD_THEME  = 1;
const int UNDERWORLD_THEME = 2;

// The melody array contains the tone, duration, and inter-note
// pause duration (the last item is calculated based on the
//internote_pause value. A zero in the tone position indicates a rest.
int overworld_theme[][2] = {
  { NOTE_E6,  12 }, { NOTE_E6,  12 }, { SILENCE,  12 },
  { NOTE_E6,  12 }, { SILENCE,  12 }, { NOTE_C6,  12 },
  { NOTE_E6,  12 }, { SILENCE,  12 }, { NOTE_G6,  12 },
  { SILENCE,  12 }, { SILENCE,  12 }, { SILENCE,  12 },
  { NOTE_G5,  12 }, { SILENCE,  12 }, { SILENCE,  12 },
  { SILENCE,  12 }, { NOTE_C6,  12 }, { SILENCE,  12 },
  { SILENCE,  12 }, { NOTE_G5,  12 }, { SILENCE,  12 },
  { SILENCE,  12 }, { NOTE_E5,  12 }, { SILENCE,  12 },
  { SILENCE,  12 }, { NOTE_A5,  12 }, { SILENCE,  12 },
  { NOTE_B5,  12 }, { SILENCE,  12 }, { NOTE_AS5, 12 },
  { NOTE_A5,  12 }, { SILENCE,  12 }, { NOTE_G5,   9 },
  { NOTE_E6,   9 }, { NOTE_G6,   9 }, { NOTE_A6,  12 },
  { SILENCE,  12 }, { NOTE_F6,  12 }, { NOTE_G6,  12 },
  { SILENCE,  12 }, { NOTE_E6,  12 }, { SILENCE,  12 },
  { NOTE_C6,  12 }, { NOTE_D6,  12 }, { NOTE_B5,  12 },
  { SILENCE,  12 }, { SILENCE,  12 }, { NOTE_C6,  12 },
  { SILENCE,  12 }, { SILENCE,  12 }, { NOTE_G5,  12 },
  { SILENCE,  12 }, { SILENCE,  12 }, { NOTE_E5,  12 },
  { SILENCE,  12 }, { SILENCE,  12 }, { NOTE_A5,  12 },
  { SILENCE,  12 }, { NOTE_B5,  12 }, { SILENCE,  12 },
  { NOTE_AS5, 12 }, { NOTE_A5,  12 }, { SILENCE,  12 },
  { NOTE_G5,   9 }, { NOTE_E6,   9 }, { NOTE_G6,   9 },
  { NOTE_A6,  12 }, { SILENCE,  12 }, { NOTE_F6,  12 },
  { NOTE_G6,  12 }, { SILENCE,  12 }, { NOTE_E6,  12 },
  { SILENCE,  12 }, { NOTE_C6,  12 }, { NOTE_D6,  12 },
  { NOTE_B5,  12 }, { SILENCE,  12 }, { SILENCE,  12 },
};

int underworld_theme[][2] = {
  { NOTE_C4,  12 }, { NOTE_C5,  12 }, { NOTE_A3,  12 },
  { NOTE_A4,  12 }, { NOTE_AS3, 12 }, { NOTE_AS4, 12 },
  { SILENCE,   6 }, { SILENCE,   3 }, { NOTE_C4,  12 },
  { NOTE_C5,  12 }, { NOTE_A3,  12 }, { NOTE_A4,  12 },
  { NOTE_AS3, 12 }, { NOTE_AS4, 12 }, { SILENCE,   6 },
  { SILENCE,   3 }, { NOTE_F3,  12 }, { NOTE_F4,  12 },
  { NOTE_D3,  12 }, { NOTE_D4,  12 }, { NOTE_DS3, 12 },
  { NOTE_DS4, 12 }, { SILENCE,   6 }, { SILENCE,   3 },
  { NOTE_F3,  12 }, { NOTE_F4,  12 }, { NOTE_D3,  12 },
  { NOTE_D4,  12 }, { NOTE_DS3, 12 }, { NOTE_DS4, 12 },
  { SILENCE,   6 }, { SILENCE,   6 }, { NOTE_DS4, 18 },
  { NOTE_CS4, 18 }, { NOTE_D4,  18 }, { NOTE_CS4,  6 },
  { NOTE_DS4,  6 }, { NOTE_DS4,  6 }, { NOTE_GS3,  6 },
  { NOTE_G3,   6 }, { NOTE_CS4,  6 }, { NOTE_C4,  18 },
  { NOTE_FS4, 18 }, { NOTE_F4,  18 }, { NOTE_E3,  18 },
  { NOTE_AS4, 18 }, { NOTE_A4,  18 }, { NOTE_GS4, 10 },
  { NOTE_DS4, 10 }, { NOTE_B3,  10 }, { NOTE_AS3, 10 },
  { NOTE_A3,  10 }, { NOTE_GS3, 10 }, { SILENCE,   3},
  { SILENCE,   3 }, { SILENCE,   3 }
};
#endif
