/***********************************************************************
 * Program:     MusicBox Demonstration Program
 *
 * Author:      Charles McKnight
 *
 * Description:
 *   This program demonstrates the use of the MusicBox library to play
 * simple melodies on a piezobuzzer connected to an Arduino. The
 * program uses the ActionTimer library to provide a non-blocking timer
 * that is used to play each note of the melody without preventing the
 * rest of the program from running.
 ***********************************************************************/

#include <MusicBox.h>
#include "melody.h"

/****************** Global Declarations ********************************/
// declare the MusicBox object
MusicBox player(8);

// declare the currentMelody variable
int currentMelody;
/************** End of Global Declarations *****************************/


/***********************************************************************
 * Method:      setup
 *
 * Arguments:   N/A
 *
 * Returns:     N/A
 *
 * Description:
 *   The setup method performs all of the initialization tasks for the
 * sketch before proceeding to call the loop method.
 ***********************************************************************/
void setup() {

  // set the desired length of a whole note
  player.setWholeNoteDuration(1250);

  // set the delay between the notes
    player.setInternoteDelay(1.3);

  // set the initial melody to the overworld theme
  currentMelody = OVERWORLD_THEME;
  player.setMelody(overworld_theme,
                   sizeof(overworld_theme) / sizeof(overworld_theme[0]));
}


/***********************************************************************
 * Method:      loop
 *
 * Arguments:   N/A
 *
 * Returns:     N/A
 *
 * Description:
 *   The loop method performs all of the main program logic after the
 * setup method completes its tasks.
 ***********************************************************************/
void loop() {
  // play the selected melody
  player.playMelody();

  // determine if the current melody has ended
  if (player.isMelodyOver() == true) {
    if (currentMelody == OVERWORLD_THEME) {
      // change to underworld theme
      currentMelody = UNDERWORLD_THEME;
      player.setMelody(underworld_theme,
                       sizeof(underworld_theme) / sizeof(underworld_theme[0]));
    } else {
      // if underworld theme, change to overworld theme
      currentMelody = OVERWORLD_THEME;
      player.setMelody(overworld_theme,
                       sizeof(overworld_theme) / sizeof(overworld_theme[0]));
    }
  }
}
