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
int button_NOTE_B = 13;
int count = 0;
int length = 149;
int button_MODE = 1;
#define echoPin 2 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 3 //attach pin D3 Arduino to pin Trig of HC-SR04

// defines variables
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement
int notes[] = {NOTE_C4,NOTE_E4,NOTE_F4,NOTE_G4,NOTE_A4,493};// Set notes C, D, E, F, G, A, B
int notes1[] = {NOTE_C5,NOTE_E5,NOTE_F5,NOTE_G5,NOTE_A5,NOTE_B5};
int notes2[] = {NOTE_C6,NOTE_E6,NOTE_F6,NOTE_G6,NOTE_A6,NOTE_B6};
int notes3[] = {NOTE_C7,NOTE_E7,NOTE_F7,NOTE_G7,NOTE_A7,NOTE_B7};
void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
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
  int but_C = digitalRead(button_NOTE_C);
  int but_D = digitalRead(button_NOTE_D);
  int but_E = digitalRead(button_NOTE_E);
  int but_F = digitalRead(button_NOTE_F);
  int but_G = digitalRead(button_NOTE_G);
  int but_A = digitalRead(button_NOTE_A);
  int but_B = digitalRead(button_NOTE_B);

  if (distance<=20 && count == 0)
  {
    count++;
    count = count%4;
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
  else if (distance<=20 && count==1)
  {
    count++;
    count = count%4;
          if(but_C == LOW)  {
        tone(buzzerPin, notes1[0]); // C
        } // end if
        
      else if(but_D == LOW)  {
        tone(buzzerPin, notes1[1]); // D
        } // end else if
  
      else if(but_E == LOW)  {
        tone(buzzerPin, notes1[2]); // E
        } // end else if
      
      else if(but_F == LOW)  {
        tone(buzzerPin, notes1[3]); // F
        } // end else if
      
      else if(but_G == LOW)  {
        tone(buzzerPin, notes1[4]); // G
        } // end else if
      
      else if(but_A == LOW)  {
        tone(buzzerPin, notes1[5]); // A
        } // end else if
      
      else if(but_B == LOW)  {
        tone(buzzerPin, notes1[6]); // B
        } // end else if
      
      else{ // if no switch is pressed, do not play tone
        noTone(buzzerPin);
        } // end else if    
  }
  else if (distance<=20 && count==2)
  {
    count++;
    count = count%4;
          if(but_C == LOW)  {
        tone(buzzerPin, notes2[0]); // C
        } // end if
        
      else if(but_D == LOW)  {
        tone(buzzerPin, notes2[1]); // D
        } // end else if
  
      else if(but_E == LOW)  {
        tone(buzzerPin, notes2[2]); // E
        } // end else if
      
      else if(but_F == LOW)  {
        tone(buzzerPin, notes2[3]); // F
        } // end else if
      
      else if(but_G == LOW)  {
        tone(buzzerPin, notes2[4]); // G
        } // end else if
      
      else if(but_A == LOW)  {
        tone(buzzerPin, notes2[5]); // A
        } // end else if
      
      else if(but_B == LOW)  {
        tone(buzzerPin, notes2[6]); // B
        } // end else if
      
      else{ // if no switch is pressed, do not play tone
        noTone(buzzerPin);
        } // end else if    
  }
  else if (distance<=20 && count==3)
  {
    count++;
    count = count%4;
          if(but_C == LOW)  {
        tone(buzzerPin, notes3[0]); // C
        } // end if
        
      else if(but_D == LOW)  {
        tone(buzzerPin, notes3[1]); // D
        } // end else if
  
      else if(but_E == LOW)  {
        tone(buzzerPin, notes3[2]); // E
        } // end else if
      
      else if(but_F == LOW)  {
        tone(buzzerPin, notes3[3]); // F
        } // end else if
      
      else if(but_G == LOW)  {
        tone(buzzerPin, notes3[4]); // G
        } // end else if
      
      else if(but_A == LOW)  {
        tone(buzzerPin, notes3[5]); // A
        } // end else if
      
      else if(but_B == LOW)  {
        tone(buzzerPin, notes3[6]); // B
        } // end else if
      
      else{ // if no switch is pressed, do not play tone
        noTone(buzzerPin);
        } // end else if    
  }
  else
  {
    count++;
    count = count%4;
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
        tone(buzzerPin, 493); // B
        } // end else if
      
      else{ // if no switch is pressed, do not play tone
        noTone(buzzerPin);
        } // end else if    
    
    
  }


//  }
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
