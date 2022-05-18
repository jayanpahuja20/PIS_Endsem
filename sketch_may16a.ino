

// include the library code:
#include <LiquidCrystal.h>
#include "pitches.h"
int buzzerPin = 4;
int count = 0;
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement
#define echoPin 6 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 7 //attach pin D3 Arduino to pin Trig of HC-SR04
#define REST 0
int button_NOTE_C = 6;
int button_NOTE_D = 7;
int button_NOTE_E = 8;
int button_NOTE_F = 9;
int button_NOTE_G = 10;
int button_NOTE_A = 11;
int button_NOTE_B = 13;
// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  lcd.setCursor(4, 0);
  lcd.print("WELCOME");
  lcd.setCursor(5, 1);
  lcd.print("PIANO");
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  if (distance<=10)
  {
      lcd.clear();
      lcd.setCursor(1, 0);
      lcd.print("Now playing...");
      lcd.setCursor(0, 1);
      lcd.print("HEDWIG THEME - HP");
      int tempo = 144;
      
      // change this to whichever pin you want to use
      int buzzer = 9;
      
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
    // iterate over the notes of the melody. 
    // Remember, the array is twice the number of notes (notes + durations)
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
      delay(100);
      lcd.clear();
      lcd.setCursor(4, 0);
      lcd.print("WELCOME");
      lcd.setCursor(5, 1);
      lcd.print("PIANO");
  }

  else if(distance>10 && distance<=20){
      lcd.clear();
      lcd.setCursor(1, 0);
      lcd.print("Now playing...");
      lcd.setCursor(0, 1);
      lcd.print("MARIO THEME SONG");
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
 
      tone(9, melody[thisNote], noteDuration);
 
      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
 
      // stop the tone playing:
      tone(9, 0, noteDuration);
    }      
      delay(100);
      lcd.clear();
      lcd.setCursor(4, 0);
      lcd.print("WELCOME");
      lcd.setCursor(5, 1);
      lcd.print("PIANO");
      count++;
      count = count%5;
      }
  else if (distance>20 && distance<=30){
      lcd.clear();
      lcd.setCursor(1, 0);
      lcd.print("Now playing...");
      lcd.setCursor(0, 1);
      lcd.print("HAPPY BIRTHDAY");
     // change this to make the song slower or faster
    int tempo = 140;
    
    // change this to whichever pin you want to use
    int buzzer = 9;
    
    // notes of the moledy followed by the duration.
    // a 4 means a quarter note, 8 an eighteenth , 16 sixteenth, so on
    // !!negative numbers are used to represent dotted notes,
    // so -4 means a dotted quarter note, that is, a quarter plus an eighteenth!!
    int melody[] = {
    
      // Happy Birthday
      // Score available at https://musescore.com/user/8221/scores/26906
    
      NOTE_C4,4, NOTE_C4,8, 
      NOTE_D4,-4, NOTE_C4,-4, NOTE_F4,-4,
      NOTE_E4,-2, NOTE_C4,4, NOTE_C4,8, 
      NOTE_D4,-4, NOTE_C4,-4, NOTE_G4,-4,
      NOTE_F4,-2, NOTE_C4,4, NOTE_C4,8,
    
      NOTE_C5,-4, NOTE_A4,-4, NOTE_F4,-4, 
      NOTE_E4,-4, NOTE_D4,-4, NOTE_AS4,4, NOTE_AS4,8,
      NOTE_A4,-4, NOTE_F4,-4, NOTE_G4,-4,
      NOTE_F4,-2,
     
    };
    
    // sizeof gives the number of bytes, each int value is composed of two bytes (16 bits)
    // there are two values per note (pitch and duration), so for each note there are four bytes
    int notes = sizeof(melody) / sizeof(melody[0]) / 2;
    
    // this calculates the duration of a whole note in ms
    int wholenote = (60000 * 4) / tempo;
    
    int divider = 0, noteDuration = 0;
  // iterate over the notes of the melody.
  // Remember, the array is twice the number of notes (notes + durations)
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
    tone(buzzer, melody[thisNote], noteDuration * 0.9);

    // Wait for the specief duration before playing the next note.
    delay(noteDuration);

    // stop the waveform generation before the next note.
    noTone(buzzer); 
  } 
      delay(100);
      lcd.clear();
      lcd.setCursor(4, 0);
      lcd.print("WELCOME");
      lcd.setCursor(5, 1);
      lcd.print("PIANO");    
  }
  else if (distance>30 && distance<=40){
      lcd.clear();
      lcd.setCursor(1, 0);
      lcd.print("Now playing...");
      lcd.setCursor(0, 1);
      lcd.print("PINK PANTHER");
       int tempo = 120;
      
      // change this to whichever pin you want to use
      int buzzer = 9;
      
      // notes of the moledy followed by the duration.
      // a 4 means a quarter note, 8 an eighteenth , 16 sixteenth, so on
      // !!negative numbers are used to represent dotted notes,
      // so -4 means a dotted quarter note, that is, a quarter plus an eighteenth!!
      int melody[] = {
      
        // Pink Panther theme
        // Score available at https://musescore.com/benedictsong/the-pink-panther
        // Theme by Masato Nakamura, arranged by Teddy Mason
      
        REST,2, REST,4, REST,8, NOTE_DS4,8, 
        NOTE_E4,-4, REST,8, NOTE_FS4,8, NOTE_G4,-4, REST,8, NOTE_DS4,8,
        NOTE_E4,-8, NOTE_FS4,8,  NOTE_G4,-8, NOTE_C5,8, NOTE_B4,-8, NOTE_E4,8, NOTE_G4,-8, NOTE_B4,8,   
        NOTE_AS4,2, NOTE_A4,-16, NOTE_G4,-16, NOTE_E4,-16, NOTE_D4,-16, 
        NOTE_E4,2, REST,4, REST,8, NOTE_DS4,4,
      
        NOTE_E4,-4, REST,8, NOTE_FS4,8, NOTE_G4,-4, REST,8, NOTE_DS4,8,
        NOTE_E4,-8, NOTE_FS4,8,  NOTE_G4,-8, NOTE_C5,8, NOTE_B4,-8, NOTE_G4,8, NOTE_B4,-8, NOTE_E5,8,
        NOTE_DS5,1,   
        NOTE_D5,2, REST,4, REST,8, NOTE_DS4,8, 
        NOTE_E4,-4, REST,8, NOTE_FS4,8, NOTE_G4,-4, REST,8, NOTE_DS4,8,
        NOTE_E4,-8, NOTE_FS4,8,  NOTE_G4,-8, NOTE_C5,8, NOTE_B4,-8, NOTE_E4,8, NOTE_G4,-8, NOTE_B4,8,   
        
        NOTE_AS4,2, NOTE_A4,-16, NOTE_G4,-16, NOTE_E4,-16, NOTE_D4,-16, 
        NOTE_E4,-4, REST,4,
        REST,4, NOTE_E5,-8, NOTE_D5,8, NOTE_B4,-8, NOTE_A4,8, NOTE_G4,-8, NOTE_E4,-8,
        NOTE_AS4,16, NOTE_A4,-8, NOTE_AS4,16, NOTE_A4,-8, NOTE_AS4,16, NOTE_A4,-8, NOTE_AS4,16, NOTE_A4,-8,   
        NOTE_G4,-16, NOTE_E4,-16, NOTE_D4,-16, NOTE_E4,16, NOTE_E4,16, NOTE_E4,2,
       
      };
      
      // sizeof gives the number of bytes, each int value is composed of two bytes (16 bits)
      // there are two values per note (pitch and duration), so for each note there are four bytes
      int notes = sizeof(melody) / sizeof(melody[0]) / 2;
      
      // this calculates the duration of a whole note in ms
      int wholenote = (60000 * 4) / tempo;
      
      int divider = 0, noteDuration = 0;

  // iterate over the notes of the melody.
  // Remember, the array is twice the number of notes (notes + durations)
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
    tone(buzzer, melody[thisNote], noteDuration * 0.9);

    // Wait for the specief duration before playing the next note.
    delay(noteDuration);

    // stop the waveform generation before the next note.
    noTone(buzzer);
  }     
      delay(100);
      lcd.clear();
      lcd.setCursor(4, 0);
      lcd.print("WELCOME");
      lcd.setCursor(5, 1);
      lcd.print("PIANO");      
  }
  else
  {
      lcd.clear();
      lcd.setCursor(4, 0);
      lcd.print("WELCOME");
      lcd.setCursor(5, 1);
      lcd.print("PIANO");     
  }
}
