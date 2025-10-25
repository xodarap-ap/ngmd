// Neo Geo LED Marquee Driver v3
// Please note this sketch will not suit revisions of the NGMD PCB older than Revision 1.2 due to recent changes in the PCB design and newly added features

// Integer values for board functions

int selftest = 1; // Change this value to 0 if you do not want the board to complete a self test on boot
int attractdelay = 5000; // Change this value to the number of milliseconds you would like each marquee to light up for in attract mode (1000ms = 1 second)
int bit0=0; // Integer values required to determine which slot is currently active
int bit1=0; // Integer values required to determine which slot is currently active
int bit2=0; // Integer values required to determine which slot is currently active
int x=0; // Integer values required to determine which slot is currently active

// Pin assignments for connections from MVS board

int clk = 2; // These are the pins for the inputs from the MVS board. Please do not change these as they are connected by traces on the PCB
int data0 = 3; // These are the pins for the inputs from the MVS board. Please do not change these as they are connected by traces on the PCB
int data1 = 4; // These are the pins for the inputs from the MVS board. Please do not change these as they are connected by traces on the PCB
int data2 = 5; // These are the pins for the inputs from the MVS board. Please do not change these as they are connected by traces on the PCB

// These are the pins for the marquee outputs - you can change these to suit which connectors you would like to use

// Arduino pin 6 = Slot 1
// Arduino pin 7 = Slot 2
// Arduino pin 8 = Slot 3
// Arduino pin 9 = Slot 4
// Arduino pin 10 = Slot 5
// Arduino pin 11 = Slot 6

// lightout1 = USB connector 1
// lightout2 = USB connector 2
// lightout3 = USB connector 3
// lightout4 = USB connector 4
// lightout5 = USB connector 5
// lightout6 = USB connector 6

int lightout1 = 6; 
int lightout2 = 7; 
int lightout3 = 8; 
int lightout4 = 9; 
int lightout5 = 10;
int lightout6 = 11; 

//Manual change related settings

int changebutton = 12; // Pin the change button is connected to on the Arduino - please do not change this as it is connected via a trace on the PCB
int lightarray[6] = {lightout1, lightout2, lightout3, lightout4, lightout5, lightout6};
int totallights = 6;
int currentlight = 0;
int buttonState = HIGH;

// This is the configuration for the input and output pins on the Arduino board. Please do not change these as they are connected by traces on the PCB

void setup() {
  pinMode(A0, INPUT_PULLUP); // DIP Switch 4
  pinMode(A1, INPUT_PULLUP); // DIP Switch 3
  pinMode(A2, INPUT_PULLUP); // DIP Switch 2
  pinMode(A3, INPUT_PULLUP); // DIP Switch 1
  pinMode(clk, INPUT_PULLUP); // Clock signal from MVS PCB
  pinMode(data0, INPUT_PULLUP); // Data signal from MVS PCB
  pinMode(data1, INPUT_PULLUP); // Data signal from MVS PCB
  pinMode(data2, INPUT_PULLUP); // Data signal from MVS PCB
  pinMode(lightout1, OUTPUT); // Output pin for marquee light 1
  pinMode(lightout2, OUTPUT); // Output pin for marquee light 2
  pinMode(lightout3, OUTPUT); // Output pin for marquee light 3
  pinMode(lightout4, OUTPUT); // Output pin for marquee light 4
  pinMode(lightout5, OUTPUT); // Output pin for marquee light 5
  pinMode(lightout6, OUTPUT); // Output pin for marquee light 6

// Self-test routine

  if (selftest==1)
    digitalWrite (lightout1, HIGH);
    delay (500);
    digitalWrite (lightout1, LOW);
    delay (500);
    digitalWrite (lightout2, HIGH);
    delay (500);
    digitalWrite (lightout2, LOW);
    delay (500);
    digitalWrite (lightout3, HIGH);
    delay (500);
    digitalWrite (lightout3, LOW);
    delay (500);
    digitalWrite (lightout4, HIGH);
    delay (500);
    digitalWrite (lightout4, LOW);
    delay (500);
    digitalWrite (lightout5, HIGH);
    delay (500);
    digitalWrite (lightout5, LOW);
    delay(500);
    digitalWrite (lightout6, HIGH);
    delay(500);
    digitalWrite (lightout6, LOW);
    delay(500);
    
// Manual mode settings

  pinMode(changebutton, INPUT_PULLUP); // Manual change button
  for (int i = 0; i <= 6; i++){
      pinMode(lightarray[i], OUTPUT);
  }


// Determine which mode is active based on the DIP switches and run the correct code if any special functions are enabled
// Priority order is 6 Slot, 4 Slot, Attract Mode, Manual Change

}

void loop() {
  if (digitalRead(A0) == LOW){
    marquee6slot();
  } else if (digitalRead(A1) == LOW){
    marquee4slot();
  } else if (digitalRead(A2) == LOW){
    attractmode();
  } else if (digitalRead(A3) == LOW){
    manualchange();
  } else {
    marquee2slot();
  }
  }


// This is the main program code for the marquee driver. Depending on how many slots are enabled it will run one of 3 variants of this code

  void marquee6slot() {
  if(digitalRead(clk)){
  bit0=digitalRead(data0);
  bit1=digitalRead(data1);
  bit2=digitalRead(data2);

  if (bit0==0 and bit1==0 and bit2==0){
      for (x=0;x<1;x++){
        digitalWrite(lightout1, HIGH);
      }
      for (x=1;x<2;x++){
        digitalWrite(lightout2, LOW);
      }
      for (x=2;x<3;x++){
        digitalWrite(lightout3, LOW);
      }
      for (x=3;x<4;x++){
        digitalWrite(lightout4, LOW);
      }
      for (x=4;x<5;x++){
        digitalWrite(lightout5, LOW);
      }
      for (x=5;x<6;x++){
        digitalWrite(lightout6, LOW);
      }
    }  

 if (bit0==1 and bit1==0 and bit2==0){
      for (x=0;x<1;x++){  
        digitalWrite(lightout1, LOW);
      }
      for (x=1;x<2;x++){
        digitalWrite(lightout2, HIGH);
      }
      for (x=2;x<3;x++){
        digitalWrite(lightout3, LOW);
      }
      for (x=3;x<4;x++){
        digitalWrite(lightout4, LOW);
      }
      for (x=4;x<5;x++){
        digitalWrite(lightout5, LOW);
      }
      for (x=5;x<6;x++){
        digitalWrite(lightout6, LOW);
      }
    }

  if (bit0==0 and bit1==1 and bit2==0){
      for (x=0;x<1;x++){  
        digitalWrite(lightout1, LOW);
      }
      for (x=1;x<2;x++){
        digitalWrite(lightout2, LOW);
      }
      for (x=2;x<3;x++){
        digitalWrite(lightout3, HIGH);
      }
      for (x=3;x<4;x++){
        digitalWrite(lightout4, LOW);
      }
      for (x=4;x<5;x++){
        digitalWrite(lightout5, LOW);
      }
      for (x=5;x<6;x++){
        digitalWrite(lightout6, LOW);
      }
    }

  if (bit0==1 and bit1==1 and bit2==0){
      for (x=0;x<1;x++){  
        digitalWrite(lightout1, LOW);
      }
      for (x=1;x<2;x++){
        digitalWrite(lightout2, LOW);
      }
      for (x=2;x<3;x++){
        digitalWrite(lightout3, LOW);
      }
      for (x=3;x<4;x++){
        digitalWrite(lightout4, HIGH);
      }
      for (x=4;x<5;x++){
        digitalWrite(lightout5, LOW);
      }
      for (x=5;x<6;x++){
        digitalWrite(lightout6, LOW);
      }
    }
      if (bit0==0 and bit1==0 and bit2==1){
      for (x=0;x<1;x++){  
        digitalWrite(lightout1, LOW);
      }
      for (x=1;x<2;x++){
        digitalWrite(lightout2, LOW);
      }
      for (x=2;x<3;x++){
        digitalWrite(lightout3, LOW);
      }
      for (x=3;x<4;x++){
        digitalWrite(lightout4, LOW);
      }
      for (x=4;x<5;x++){
        digitalWrite(lightout5, HIGH);
      }
      for (x=5;x<6;x++){
        digitalWrite(lightout6, LOW);
      }
    }
      if (bit0==1 and bit1==0 and bit2==1){
      for (x=0;x<1;x++){  
        digitalWrite(lightout1, LOW);
      }
      for (x=1;x<2;x++){
        digitalWrite(lightout2, LOW);
      }
      for (x=2;x<3;x++){
        digitalWrite(lightout3, LOW);
      }
      for (x=3;x<4;x++){
        digitalWrite(lightout4, LOW);
      }
      for (x=4;x<5;x++){
        digitalWrite(lightout5, LOW);
      }
      for (x=5;x<6;x++){
        digitalWrite(lightout6, HIGH);
      } 
    }
   }  
  }

void marquee4slot() {
  if(digitalRead(clk)){
  bit0=digitalRead(data0);
  bit1=digitalRead(data1);
  bit2=digitalRead(data2);

  if (bit0==0 and bit1==0 and bit2==0){
      for (x=0;x<1;x++){
        digitalWrite(lightout2, HIGH);
      }
      for (x=1;x<2;x++){
        digitalWrite(lightout3, LOW);
      }
      for (x=2;x<3;x++){
        digitalWrite(lightout4, LOW);
      }
      for (x=3;x<4;x++){
        digitalWrite(lightout5, LOW);
      }
    }  

 if (bit0==1 and bit1==0 and bit2==0){
      for (x=0;x<1;x++){  
        digitalWrite(lightout2, LOW);
      }
      for (x=1;x<2;x++){
        digitalWrite(lightout3, HIGH);
      }
      for (x=2;x<3;x++){
        digitalWrite(lightout4, LOW);
      }
      for (x=3;x<4;x++){
        digitalWrite(lightout5, LOW);
      }
    }

  if (bit0==0 and bit1==1 and bit2==0){
      for (x=0;x<1;x++){  
        digitalWrite(lightout2, LOW);
      }
      for (x=1;x<2;x++){
        digitalWrite(lightout3, LOW);
      }
      for (x=2;x<3;x++){
        digitalWrite(lightout4, HIGH);
      }
      for (x=3;x<4;x++){
        digitalWrite(lightout5, LOW);
      }
    }

  if (bit0==1 and bit1==1 and bit2==0){
      for (x=0;x<1;x++){  
        digitalWrite(lightout2, LOW);
      }
      for (x=1;x<2;x++){
        digitalWrite(lightout3, LOW);
      }
      for (x=2;x<3;x++){
        digitalWrite(lightout4, LOW);
      }
      for (x=3;x<4;x++){
        digitalWrite(lightout5, HIGH);
      }
    }
   }  
  }

void marquee2slot() {
  if(digitalRead(clk)){
  bit0=digitalRead(data0);
  bit1=digitalRead(data1);
  bit2=digitalRead(data2);

  if (bit0==0 and bit1==0 and bit2==0){
      for (x=0;x<1;x++){
        digitalWrite(lightout3, HIGH);
      }
      for (x=1;x<2;x++){
        digitalWrite(lightout4, LOW);
      }
    }  

 if (bit0==1 and bit1==0 and bit2==0){
      for (x=0;x<1;x++){  
        digitalWrite(lightout3, LOW);
      }
      for (x=1;x<2;x++){
        digitalWrite(lightout4, HIGH);
      }
    }
   }
  }

// Run attract mode if enabled

void attractmode() {
  if (digitalRead(A2) == LOW){
      for (x=0;x<1;x++){  
        digitalWrite(lightout1, HIGH);
      }
      for (x=1;x<2;x++){
        digitalWrite(lightout2, LOW);
      }
      for (x=2;x<3;x++){
        digitalWrite(lightout3, LOW);
      }
      for (x=3;x<4;x++){
        digitalWrite(lightout4, LOW);
      }
      for (x=4;x<5;x++){
        digitalWrite(lightout5, LOW);
      }
      for (x=5;x<6;x++){
        digitalWrite(lightout6, LOW);
      } 
    }

  delay (attractdelay);

  if (digitalRead(A2) == LOW){
      for (x=0;x<1;x++){  
        digitalWrite(lightout1, LOW);
      }
      for (x=1;x<2;x++){
        digitalWrite(lightout2, HIGH);
      }
      for (x=2;x<3;x++){
        digitalWrite(lightout3, LOW);
      }
      for (x=3;x<4;x++){
        digitalWrite(lightout4, LOW);
      }
      for (x=4;x<5;x++){
        digitalWrite(lightout5, LOW);
      }
      for (x=5;x<6;x++){
        digitalWrite(lightout6, LOW);
      } 
    }

  delay (attractdelay);

  if (digitalRead(A2) == LOW){
      for (x=0;x<1;x++){  
        digitalWrite(lightout1, LOW);
      }
      for (x=1;x<2;x++){
        digitalWrite(lightout2, LOW);
      }
      for (x=2;x<3;x++){
        digitalWrite(lightout3, HIGH);
      }
      for (x=3;x<4;x++){
        digitalWrite(lightout4, LOW);
      }
      for (x=4;x<5;x++){
        digitalWrite(lightout5, LOW);
      }
      for (x=5;x<6;x++){
        digitalWrite(lightout6, LOW);
      } 
    }

  delay (attractdelay);

  if (digitalRead (A2) == LOW){
      for (x=0;x<1;x++){  
        digitalWrite(lightout1, LOW);
      }
      for (x=1;x<2;x++){
        digitalWrite(lightout2, LOW);
      }
      for (x=2;x<3;x++){
        digitalWrite(lightout3, LOW);
      }
      for (x=3;x<4;x++){
        digitalWrite(lightout4, HIGH);
      }
      for (x=4;x<5;x++){
        digitalWrite(lightout5, LOW);
      }
      for (x=5;x<6;x++){
        digitalWrite(lightout6, LOW);
      } 
    }

  delay (attractdelay);

  if (digitalRead (A2) == LOW){
      for (x=0;x<1;x++){  
        digitalWrite(lightout1, LOW);
      }
      for (x=1;x<2;x++){
        digitalWrite(lightout2, LOW);
      }
      for (x=2;x<3;x++){
        digitalWrite(lightout3, LOW);
      }
      for (x=3;x<4;x++){
        digitalWrite(lightout4, LOW);
      }
      for (x=4;x<5;x++){
        digitalWrite(lightout5, HIGH);
      }
      for (x=5;x<6;x++){
        digitalWrite(lightout6, LOW);
      } 
    }
   
  delay (attractdelay);
  
  if (digitalRead (A2) == LOW){
      for (x=0;x<1;x++){  
        digitalWrite(lightout1, LOW);
      }
      for (x=1;x<2;x++){
        digitalWrite(lightout2, LOW);
      }
      for (x=2;x<3;x++){
        digitalWrite(lightout3, LOW);
      }
      for (x=3;x<4;x++){
        digitalWrite(lightout4, LOW);
      }
      for (x=4;x<5;x++){
        digitalWrite(lightout5, LOW);
      }
      for (x=5;x<6;x++){
        digitalWrite(lightout6, HIGH);
      } 
    }
  delay (attractdelay);
}

// Run manual change mode if enabled

void manualchange() {
  buttonState = digitalRead(changebutton);
  if (buttonState == LOW) {
      for (int i = 0; i < totallights; i++){
        if (currentlight % totallights == i) {
            digitalWrite(lightarray[i], HIGH);
        }
        else {
            digitalWrite(lightarray[i], LOW);
        }
        }
        currentlight++;
        delay(400);
      }
}