#include <LiquidCrystal.h>
#include "pitches.h"

int buzzerPin = 4;
#define REST 0
int button_NOTE_C = 6;
int button_NOTE_D = 7;
int button_NOTE_E = 8;
int button_NOTE_F = 9;
int button_NOTE_G = 10;
int button_NOTE_A = 11;
int button_NOTE_B = 12;
int count = 0;
int length = 149;
int button_MODE = 1;
#define echoPin 2 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 3 //attach pin D3 Arduino to pin Trig of HC-SR04

// defines variables
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement


int notes[] = {262, 294, 330, 349, 392, 440, 494}; // Set notes C, D, E, F, G, A, B

void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
  Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor
  Serial.println("with Arduino UNO R3");
  pinMode(buzzerPin, OUTPUT);
  pinMode(button_NOTE_C, INPUT);
  pinMode(button_NOTE_D, INPUT);
  pinMode(button_NOTE_E, INPUT);
  pinMode(button_NOTE_F, INPUT);
  pinMode(button_NOTE_G, INPUT);
  pinMode(button_NOTE_A, INPUT);
  pinMode(button_NOTE_B, INPUT);
  pinMode(button_MODE, INPUT);
}

void loop() {
  int but_C = digitalRead(button_NOTE_C);
  int but_D = digitalRead(button_NOTE_D);
  int but_E = digitalRead(button_NOTE_E);
  int but_F = digitalRead(button_NOTE_F);
  int but_G = digitalRead(button_NOTE_G);
  int but_A = digitalRead(button_NOTE_A);
  int but_B = digitalRead(button_NOTE_B);

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

  if (distance <=20   )
  {
        if (but_C==LOW)
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
    else if (but_D==LOW){
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
  
    else if (but_E==LOW){
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
  else
  {
      if(but_C == LOW)  {
        tone(buzzerPin, notes[0]); // C
        } // end if
        
      else if(but_D == LOW)  {
        tone(buzzerPin, notes[1]); // D
        } // end else if
  
      else if(but_E == LOW)  {
        tone(buzzerPin, notes[2]); // E
        } // end else if
      
      else if(but_F == LOW)  {
        tone(buzzerPin, notes[3]); // F
        } // end else if
      
      else if(but_G == LOW)  {
        tone(buzzerPin, notes[4]); // G
        } // end else if
      
      else if(but_A == LOW)  {
        tone(buzzerPin, notes[5]); // A
        } // end else if
      
      else if(but_B == LOW)  {
        tone(buzzerPin, notes[6]); // B
        } // end else if
      
      else{ // if no switch is pressed, do not play tone
        noTone(buzzerPin);
        } // end else if    
  }
  // put your main code here, to run repeatedly:
//    LCDswitchState = digitalRead(LCDswitchPin);
//    int keyVal = analogRead(A0);
//    Serial.println(keyVal);
//    lcd.noDisplay();
//    digitalWrite(blueLED, LOW); // Turn LED back off every time main loop starts
//  
//
//
//
//    if (LCDswitchState == HIGH)  {
//      digitalWrite(blueLED, HIGH); // Turn LED on to show piano keys are disabled and device is in "menu mode"
//      lcd.display();
//      lcd.clear();
//      LCDstart();
//      }
   
   

} //end frequency tone loop

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
