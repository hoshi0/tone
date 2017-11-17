/*
  Melody

  Plays a melody

  circuit:
  - 8 ohm speaker on digital pin 8

  created 21 Jan 2010
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Tone
*/

#include "pitches.h"

// notes in the melody:
int melody[] = {
    0       , NOTE_C4
  , NOTE_C4 , NOTE_A4 , NOTE_G4 , NOTE_F4 , NOTE_C4 , 0 , NOTE_C4
  , NOTE_C4 , NOTE_A4 , NOTE_G4 , NOTE_F4 , NOTE_D4 , 0 , NOTE_D4
  , NOTE_D4 , NOTE_AS4, NOTE_A4 , NOTE_G4 , NOTE_E4 , 0 , NOTE_C5
  , NOTE_D5 , NOTE_C5 , NOTE_AS4, NOTE_G4 , NOTE_A4 , 0 , NOTE_C4

  , NOTE_C4 , NOTE_A4 , NOTE_G4 , NOTE_F4 , NOTE_C4 , 0 , NOTE_C4
  , NOTE_C4 , NOTE_A4 , NOTE_G4 , NOTE_F4 , NOTE_D4 , 0 , NOTE_D4
  , NOTE_D4 , NOTE_AS4, NOTE_A4 , NOTE_G4 , NOTE_C5 , NOTE_C5 , NOTE_C5 , NOTE_C5
  , NOTE_D5 , NOTE_C5 , NOTE_AS4, NOTE_G4 , NOTE_F4 , 0

  , NOTE_A4 , NOTE_A4 , NOTE_A4 , NOTE_A4 , NOTE_A4 , NOTE_A4
  , NOTE_A4 , NOTE_C5 , NOTE_F4 , NOTE_G4 , NOTE_A4 , 0
  , NOTE_AS4, NOTE_AS4, NOTE_AS4, NOTE_AS4, NOTE_AS4, NOTE_A4 , NOTE_A4 , NOTE_A4 , NOTE_A4
  , NOTE_A4 , NOTE_G4 , NOTE_G4 , NOTE_F4 , NOTE_G4 , NOTE_C5 , 0

  , NOTE_A4 , NOTE_A4 , NOTE_A4 , NOTE_A4 , NOTE_A4 , NOTE_A4
  , NOTE_A4 , NOTE_C5 , NOTE_F4 , NOTE_G4 , NOTE_A4 , 0
  , NOTE_AS4, NOTE_AS4, NOTE_AS4, NOTE_AS4, NOTE_AS4, NOTE_A4 , NOTE_A4, NOTE_A4
  , NOTE_C5 , NOTE_C5 , NOTE_AS4, NOTE_G4 , NOTE_F4 , 0
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
    8, 8
  , 8, 8, 8, 8, 4, 8, 8
  , 8, 8, 8, 8, 4, 8, 8
  , 8, 8, 8, 8, 4, 8, 8
  , 8, 8, 8, 8, 4, 8, 8

  , 8, 8, 8, 8, 4, 8, 8
  , 8, 8, 8, 8, 4, 8, 8
  , 8, 8, 8, 8, 8, 8, 8, 8
  , 8, 8, 8, 8, 4, 4

  , 8, 8, 4, 8, 8, 4
  , 8, 8, 5, 16, 4, 4
  , 8, 8, 5, 16, 8, 8, 8, 16, 16
  , 8, 8, 8, 8, 8, 4, 8

  , 8, 8, 4, 8, 8, 4
  , 8, 8, 5, 16, 4, 4
  , 8, 8, 5, 16, 8, 8, 8
  , 8, 8, 8, 8, 8, 4
};

void setup() {
  // iterate over the notes of the melody:
  int note_size = sizeof(melody) / sizeof(melody[0]);
  int tempo = 110;
  // 4 * 60(s) * 1000(ms) = 240000
  int baseDuration = 240000 / tempo;
  for (int thisNote = 0; thisNote < note_size; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = baseDuration / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(8);
  }
}

void loop() {
  // no need to repeat the melody.
}
