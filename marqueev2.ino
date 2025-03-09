// Non MVS related settings
int selftest = 1; // Change this to 0 if you do not want the self-test routine to run and check all panels are working when the board is powered on
int attractmodeenable = 0; // Change this to 1 if you are not using on a multi-slot MVS board and you want the marquee lights to cycle through on a timer
int attractdelay = 500; // Change this value to the number of milliseconds you would like each marquee to light up for in attract mode (1000ms = 1 second)

// These are the pins for the inputs. Please do not change these as they are connected by traces on the PCB

int clk = 2;
int data0 = 3;
int data1 = 4;
int data2 = 5;
int bit0=0;
int bit1=0;
int bit2=0;

// These are the pins for the marquee outputs - you can change these to suit which connectors you would like to use

// Arduino pin 6 = Slot 1
// Arduino pin 7 = Slot 2
// Arduino pin 8 = Slot 3
// Arduino pin 9 = Slot 4
// Arduino pin 10 = Slot 5
// Arduino pin 11 = Slot 6

// lightout1 = USB connector 1/Output pins 1/2
// lightout2 = USB connector 2/Output pins 3/4
// lightout3 = USB connector 3/Output pins 5/6
// lightout4 = USB connector 4/Output pins 7/8
// lightout5 = USB connector 5/Output pins 9/10
// lightout6 = USB connector 6/Output pins 11/12

int lightout1 = 6; 
int lightout2 = 7; 
int lightout3 = 8; 
int lightout4 = 9; 
int lightout5 = 10;
int lightout6 = 11; 

//Manual change related settings

int manualchangeenable = 0; // Change this to 1 if you want to manually change the marquee lights with a button
int changebutton = 12; // Pin the change button is connected to on the Arduino - please do not change this as it is connected via a trace on the PCB
const int totallights = 6; // If using manual change mode. Change this to the number of marquee lights you have connected
int buttonpress = 0;
byte lightpinarray[totallights] = { lightout1,
                                    lightout2,
                                    lightout3,
                                    lightout4,
                                    lightout5,
                                    lightout6, };
int lightnumber = 0;

// This is the configuration for the input and output pins on the Arduino board. Please do not change these as they are connected by traces on the PCB

void setup() {
  pinMode(changebutton, INPUT_PULLUP);
  pinMode(clk, INPUT_PULLUP);
  pinMode(data0, INPUT_PULLUP);
  pinMode(data1, INPUT_PULLUP);
  pinMode(data2, INPUT_PULLUP);
  pinMode(lightout1, OUTPUT);
  pinMode(lightout2, OUTPUT);
  pinMode(lightout3, OUTPUT);
  pinMode(lightout4, OUTPUT);
  pinMode(lightout5, OUTPUT);
  pinMode(lightout6, OUTPUT);

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
    delay (500);
    digitalWrite (lightout6, HIGH);
    delay (500);
    digitalWrite (lightout6, LOW);
    

// Determine which mode is active and run the correct code

}

void loop() {
  if (attractmodeenable==1) {
    attractmode();
  } else if (manualchangeenable==1){
    manualchange();
  }  else {
    marquee();
    }
  }

// This is the main program code for the marquee driver

void marquee() {
  if(digitalRead(clk)){
  bit0=digitalRead(data0);
  bit1=digitalRead(data1);
  bit2=digitalRead(data2);

  if (bit0==0 and bit1==0 and bit2==0){
      digitalWrite(lightout1, HIGH);
      digitalWrite(lightout2, LOW);
      digitalWrite(lightout3, LOW);
      digitalWrite(lightout4, LOW);
      digitalWrite(lightout5, LOW);
      digitalWrite(lightout6, LOW); 
    }  

 if (bit0==1 and bit1==0 and bit2==0){
      digitalWrite(lightout1, LOW);
      digitalWrite(lightout2, HIGH);
      digitalWrite(lightout3, LOW);
      digitalWrite(lightout4, LOW);
      digitalWrite(lightout5, LOW);
      digitalWrite(lightout6, LOW);
    }

  if (bit0==0 and bit1==1 and bit2==0){
      digitalWrite(lightout1, LOW);
      digitalWrite(lightout2, LOW);
      digitalWrite(lightout3, HIGH);
      digitalWrite(lightout4, LOW);
      digitalWrite(lightout5, LOW);
      digitalWrite(lightout6, LOW);
    }

  if (bit0==1 and bit1==1 and bit2==0){
      digitalWrite(lightout1, LOW);
      digitalWrite(lightout2, LOW);
      digitalWrite(lightout3, LOW);
      digitalWrite(lightout4, HIGH);
      digitalWrite(lightout5, LOW);
      digitalWrite(lightout6, LOW);
    }

    if (bit0==0 and bit1==0 and bit2==1){
      digitalWrite(lightout1, LOW);
      digitalWrite(lightout2, LOW);
      digitalWrite(lightout3, LOW);
      digitalWrite(lightout4, LOW);
      digitalWrite(lightout5, HIGH);
      digitalWrite(lightout6, LOW);
    }

  if (bit0==1 and bit1==0 and bit2==1){
      digitalWrite(lightout1, LOW);
      digitalWrite(lightout2, LOW);
      digitalWrite(lightout3, LOW);
      digitalWrite(lightout4, LOW);
      digitalWrite(lightout5, LOW);
      digitalWrite(lightout6, HIGH);
    }
   }  
  }

// Run attract mode if enabled

void attractmode() {
  digitalWrite (lightout1, HIGH);
  delay (attractdelay);
  digitalWrite (lightout1, LOW);
  delay (attractdelay);
  digitalWrite (lightout2, HIGH);
  delay (attractdelay);
  digitalWrite (lightout2, LOW);
  delay (attractdelay);
  digitalWrite (lightout3, HIGH);
  delay (attractdelay);
  digitalWrite (lightout3, LOW);
  delay (attractdelay);
  digitalWrite (lightout4, HIGH);
  delay (attractdelay);
  digitalWrite (lightout4, LOW);
  delay (attractdelay);
  digitalWrite (lightout5, HIGH);
  delay (attractdelay);
  digitalWrite (lightout5, LOW);
  delay (attractdelay);
  digitalWrite (lightout6, HIGH);
  delay (attractdelay);
  digitalWrite (lightout6, LOW);
}

void manuallight(int index) {
    for (int i = 1; i < totallights; i++){
      if (i == index) {
        digitalWrite(lightpinarray[i], HIGH);
      }
      else {
        digitalWrite(lightpinarray[i], LOW);
      }
      }
}

void manualchange() {
  digitalRead(changebutton);
    if(changebutton == HIGH); {
      lightnumber++;
      if(lightnumber >= totallights); {
        lightnumber = 1;
      }
      manuallight(lightnumber);
    }
}
