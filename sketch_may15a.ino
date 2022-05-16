#include <LiquidCrystal.h>


int buzzerPin = 4;
#define REST 0
int buttonPin = 6;
int buttonPn = 7;
int buttonP = 8;
#include "pitches.h"
int count = 0;
int length = 149;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void playNote(char note, int duration) { //Assigning high time for the notes
  char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
  int tones[] = { 956, 851, 758, 716, 638, 568, 1014, 478 }; 

  // play the tone corresponding to the note name 
  for (int i = 0; i < 8; i++) { 
    if (names[i] == note) { 
      playTone(tones[i], duration); 
    }
  }
}
void playTone(int tone, int duration) {  //created a square wave for given time duration
  for (long i = 0; i < duration * 1000L; i += tone * 2) { 
    digitalWrite(4, HIGH); 
    delayMicroseconds(tone);
    digitalWrite(4, LOW); 
    delayMicroseconds(tone);
  }
}


    
void setup()
{
  lcd.begin(16, 2);
  lcd.setCursor(3,0);
  lcd.print("WELCOME !");
  pinMode(buzzerPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  pinMode(buttonPn, INPUT);
  pinMode(buttonP, INPUT);

}
 
void loop()
{
  int buttonState = digitalRead(buttonPin);
  int buttonStae = digitalRead(buttonPn);
  int buttonSte = digitalRead(buttonP);

  
  if (buttonState==LOW)
  {


    int tempo = 144;
    
    // change this to whichever pin you want to use
    int buzzer = 4;
    
    // notes of the moledy followed by the duration.
    // a 4 means a quarter note, 8 an eighteenth , 16 sixteenth, so on
    // !!negative numbers are used to represent dotted notes,
    // so -4 means a dotted quarter note, that is, a quarter plus an eighteenth!!
    int melody[] = {
    
    
      // Hedwig's theme fromn the Harry Potter Movies
      // Socre from https://musescore.com/user/3811306/scores/4906610
      
      REST, 2, NOTE_D4, 4,
      NOTE_G4, -4, NOTE_AS4, 8, NOTE_A4, 4,
      NOTE_G4, 2, NOTE_D5, 4,
      NOTE_C5, -2, 
      NOTE_A4, -2,
      NOTE_G4, -4, NOTE_AS4, 8, NOTE_A4, 4,
      NOTE_F4, 2, NOTE_GS4, 4,
      NOTE_D4, -1, 
      NOTE_D4, 4,
    
      NOTE_G4, -4, NOTE_AS4, 8, NOTE_A4, 4, //10
      NOTE_G4, 2, NOTE_D5, 4,
      NOTE_F5, 2, NOTE_E5, 4,
      NOTE_DS5, 2, NOTE_B4, 4,
      NOTE_DS5, -4, NOTE_D5, 8, NOTE_CS5, 4,
      NOTE_CS4, 2, NOTE_B4, 4,
      NOTE_G4, -1,
      NOTE_AS4, 4,
         
      NOTE_D5, 2, NOTE_AS4, 4,//18
      NOTE_D5, 2, NOTE_AS4, 4,
      NOTE_DS5, 2, NOTE_D5, 4,
      NOTE_CS5, 2, NOTE_A4, 4,
      NOTE_AS4, -4, NOTE_D5, 8, NOTE_CS5, 4,
      NOTE_CS4, 2, NOTE_D4, 4,
      NOTE_D5, -1, 
      REST,4, NOTE_AS4,4,  
    
      NOTE_D5, 2, NOTE_AS4, 4,//26
      NOTE_D5, 2, NOTE_AS4, 4,
      NOTE_F5, 2, NOTE_E5, 4,
      NOTE_DS5, 2, NOTE_B4, 4,
      NOTE_DS5, -4, NOTE_D5, 8, NOTE_CS5, 4,
      NOTE_CS4, 2, NOTE_AS4, 4,
      NOTE_G4, -1, 
      
    };
    // sizeof gives the number of bytes, each int value is composed of two bytes (16 bits)
    // there are two values per note (pitch and duration), so for each note there are four bytes
    int notes = sizeof(melody) / sizeof(melody[0]) / 2;
    
    // this calculates the duration of a whole note in ms (60s/tempo)*4 beats
    int wholenote = (60000 * 4) / tempo;
    
    int divider = 0, noteDuration = 0;

     
    
      for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {
    
        // calculates the duration of each note
        divider = melody[thisNote + 1];
        if (divider > 0) {
          // regular note, just proceed
          noteDuration = (wholenote) / divider;
        } else if (divider < 0) {
          // dotted notes are represented with negative durations!!
          noteDuration = (wholenote) / abs(divider);
          noteDuration *= 1.5; // increases the duration in half for dotted notes
        }
    
        // we only play the note for 90% of the duration, leaving 10% as a pause
        tone(buzzer, melody[thisNote], noteDuration*0.9);
    
        // Wait for the specief duration before playing the next note.
        delay(noteDuration);
        
        // stop the waveform generation before the next note.
        noTone(buzzer);
      }
  }
  else if (buttonStae==LOW){
    int tempo = 120;
    
    // change this to whichever pin you want to use
    int buzzer = 4;
    
    // notes of the moledy followed by the duration.
    // a 4 means a quarter note, 8 an eighteenth , 16 sixteenth, so on
    // !!negative numbers are used to represent dotted notes,
    // so -4 means a dotted quarter note, that is, a quarter plus an eighteenth!!
    int melody[] = {
      
      // Dart Vader theme (Imperial March) - Star wars 
      // Score available at https://musescore.com/user/202909/scores/1141521
      // The tenor saxophone part was used
      
      NOTE_A4,-4, NOTE_A4,-4, NOTE_A4,16, NOTE_A4,16, NOTE_A4,16, NOTE_A4,16, NOTE_F4,8, REST,8,
      NOTE_A4,-4, NOTE_A4,-4, NOTE_A4,16, NOTE_A4,16, NOTE_A4,16, NOTE_A4,16, NOTE_F4,8, REST,8,
      NOTE_A4,4, NOTE_A4,4, NOTE_A4,4, NOTE_F4,-8, NOTE_C5,16,
    
      NOTE_A4,4, NOTE_F4,-8, NOTE_C5,16, NOTE_A4,2,//4
      NOTE_E5,4, NOTE_E5,4, NOTE_E5,4, NOTE_F5,-8, NOTE_C5,16,
      NOTE_A4,4, NOTE_F4,-8, NOTE_C5,16, NOTE_A4,2,
      
      NOTE_A5,4, NOTE_A4,-8, NOTE_A4,16, NOTE_A5,4, NOTE_GS5,-8, NOTE_G5,16, //7 
      NOTE_DS5,16, NOTE_D5,16, NOTE_DS5,8, REST,8, NOTE_A4,8, NOTE_DS5,4, NOTE_D5,-8, NOTE_CS5,16,
    
      NOTE_C5,16, NOTE_B4,16, NOTE_C5,16, REST,8, NOTE_F4,8, NOTE_GS4,4, NOTE_F4,-8, NOTE_A4,-16,//9
      NOTE_C5,4, NOTE_A4,-8, NOTE_C5,16, NOTE_E5,2,
    
      NOTE_A5,4, NOTE_A4,-8, NOTE_A4,16, NOTE_A5,4, NOTE_GS5,-8, NOTE_G5,16, //7 
      NOTE_DS5,16, NOTE_D5,16, NOTE_DS5,8, REST,8, NOTE_A4,8, NOTE_DS5,4, NOTE_D5,-8, NOTE_CS5,16,
    
      NOTE_C5,16, NOTE_B4,16, NOTE_C5,16, REST,8, NOTE_F4,8, NOTE_GS4,4, NOTE_F4,-8, NOTE_A4,-16,//9
      NOTE_A4,4, NOTE_F4,-8, NOTE_C5,16, NOTE_A4,2,
      
    };
    
    // sizeof gives the number of bytes, each int value is composed of two bytes (16 bits)
    // there are two values per note (pitch and duration), so for each note there are four bytes
    int notes = sizeof(melody) / sizeof(melody[0]) / 2;
    
    // this calculates the duration of a whole note in ms
    int wholenote = (60000 * 4) / tempo;
    
    int divider = 0, noteDuration = 0;
  for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {

    // calculates the duration of each note
    divider = melody[thisNote + 1];
    if (divider > 0) {
      // regular note, just proceed
      noteDuration = (wholenote) / divider;
    } else if (divider < 0) {
      // dotted notes are represented with negative durations!!
      noteDuration = (wholenote) / abs(divider);
      noteDuration *= 1.5; // increases the duration in half for dotted notes
    }

    // we only play the note for 90% of the duration, leaving 10% as a pause
    tone(buzzer, melody[thisNote], noteDuration*0.9);

    // Wait for the specief duration before playing the next note.
    delay(noteDuration);
    
    // stop the waveform generation before the next note.
    noTone(buzzer);
  }
    }

  else if (buttonSte==LOW){
      // notes in the melody:
        if(count==0){
  int melody[] = {
  NOTE_E7, NOTE_E7, 0, NOTE_E7,
  0, NOTE_C7, NOTE_E7, 0,
  NOTE_G7, 0, 0,  0,
  NOTE_G6, 0, 0, 0,
 
  NOTE_C7, 0, 0, NOTE_G6,
  0, 0, NOTE_E6, 0,
  0, NOTE_A6, 0, NOTE_B6,
  0, NOTE_AS6, NOTE_A6, 0,
 
  NOTE_G6, NOTE_E7, NOTE_G7,
  NOTE_A7, 0, NOTE_F7, NOTE_G7,
  0, NOTE_E7, 0, NOTE_C7,
  NOTE_D7, NOTE_B6, 0, 0,
 
  NOTE_C7, 0, 0, NOTE_G6,
  0, 0, NOTE_E6, 0,
  0, NOTE_A6, 0, NOTE_B6,
  0, NOTE_AS6, NOTE_A6, 0,
 
  NOTE_G6, NOTE_E7, NOTE_G7,
  NOTE_A7, 0, NOTE_F7, NOTE_G7,
  0, NOTE_E7, 0, NOTE_C7,
  NOTE_D7, NOTE_B6, 0, 0
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
 
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
 
  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
 
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
 
  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
};

      
    int size = sizeof(melody) / sizeof(int);
    for (int thisNote = 0; thisNote < size; thisNote++) {
 
      // to calculate the note duration, take one second
      // divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 1000 / noteDurations[thisNote];
 
      tone(4, melody[thisNote], noteDuration);
 
      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
 
      // stop the tone playing:
      tone(4, 0, noteDuration);
 
    }
    count++;
    count = count%5;
    }
    else if (count == 1){
      int melody[] = {
  NOTE_C4, NOTE_C5, NOTE_A3, NOTE_A4,
  NOTE_AS3, NOTE_AS4, 0,
  0,
  NOTE_C4, NOTE_C5, NOTE_A3, NOTE_A4,
  NOTE_AS3, NOTE_AS4, 0,
  0,
  NOTE_F3, NOTE_F4, NOTE_D3, NOTE_D4,
  NOTE_DS3, NOTE_DS4, 0,
  0,
  NOTE_F3, NOTE_F4, NOTE_D3, NOTE_D4,
  NOTE_DS3, NOTE_DS4, 0,
  0, NOTE_DS4, NOTE_CS4, NOTE_D4,
  NOTE_CS4, NOTE_DS4,
  NOTE_DS4, NOTE_GS3,
  NOTE_G3, NOTE_CS4,
  NOTE_C4, NOTE_FS4, NOTE_F4, NOTE_E3, NOTE_AS4, NOTE_A4,
  NOTE_GS4, NOTE_DS4, NOTE_B3,
  NOTE_AS3, NOTE_A3, NOTE_GS3,
  0, 0, 0
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  12, 12, 12, 12,
  12, 12, 6,
  3,
  12, 12, 12, 12,
  12, 12, 6,
  3,
  12, 12, 12, 12,
  12, 12, 6,
  3,
  12, 12, 12, 12,
  12, 12, 6,
  6, 18, 18, 18,
  6, 6,
  6, 6,
  6, 6,
  18, 18, 18, 18, 18, 18,
  10, 10, 10,
  10, 10, 10,
  3, 3, 3
};     
      


    int size = sizeof(melody) / sizeof(int);
    for (int thisNote = 0; thisNote < size; thisNote++) {
 
      // to calculate the note duration, take one second
      // divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 1000 / noteDurations[thisNote];
 
      tone(9, melody[thisNote], noteDuration);
 
      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
 
      // stop the tone playing:
      tone(9, 0, noteDuration);
 
    }
    count++;
    count =count%5;

      
      }
     else if (count ==2)
     {
      char notes[] = "cdeeeeeeeeedef eeedddbdc ccgggggggggaf fffffeddf eedeedeggaff eeeeeddbdc cdeeeedf efgggfedfe feeeddbdc ccggggeggggga fffffedfe egc bab aga ccddeedef "; // a space represents a rest
      //char notes[] = "ccddeeeeeeedef eeedddb-dc cggggggggf#ag fffeeedfe eeeeedgggff eeedddb-dc cdeeeedef efgggfedfe eedddb-dc ggggggggggf#ag fffeeedfe egc+ bab aga ccddeedef "; // a space represents a rest
      int beats[] = { 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1,
                      2, 1, 1, 2, 1, 1, 1, 1, 1, 1,
                      2, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1,
                      2, 1, 1, 2, 1, 1, 1, 1, 1, 1,
                      2, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1,
                      2, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1,
                      1, 1, 1, 1, 2, 2, 2, 1, 1,
                      1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1,
                      2, 2, 1, 1, 1, 1, 1, 1, 1, 1,
                      1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 1,
                      2, 1, 1, 2, 1, 1, 1, 1, 1, 1,
                      1, 1, 4, 1, 1, 1, 4, 1, 1, 1, 4, 1,
                      1, 1, 1, 1, 1, 1, 1, 1, 4, 1 };
      
      int tempo = 200; //set tempo
      for (int i = 0; i < length; i++) {  //For the length of the tune array
          if (notes[i] == ' ') {  //take space as rest
            delay(beats[i] * tempo); // rest 
          } else { 
            playNote(notes[i], beats[i] * tempo); //play the corresponding note for the corresponding beat
          } 
          
          // pause between notes 
          delay(tempo / 2); 
          } 
      

     }
  }
  else
  {
    noTone(buzzerPin);
  }


}
