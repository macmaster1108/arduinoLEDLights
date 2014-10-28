//My first attempt at .ino coding
//This is a hard-coded light show with 3 leds: one RBG, one white (strobe), one bright blue
//by Stephen Keller with help from SparkFun Electronics code
//see more at macmaster1108.tumblr.com

const int RED_PIN = 11;//RGB
const int GREEN_PIN = 10;
const int BLUE_PIN = 9;
const int WHITE_PIN = 12;//White
const int BBLUE_PIN = 13;//Bright Blue LED

int STROBE_TIME = 50;
int DELAY_TIME = 250;
int red = 1000;//in RBClick these are the times red blue LEDs are on
int blue = red *2;
int clock = 0;

void setup(){
  // Here we'll configure the Arduino pins we're using to
  // drive the LED to be outputs:

  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(WHITE_PIN, OUTPUT);
  pinMode(BBLUE_PIN, OUTPUT); 
} 

void loop(){
  //  mainColors();
  //  strobe();
  //  flashBlue();
  // policeLights();
  //RBClick();
  linearFlash();
}







void mainColors(){
  // Off (all LEDs off):

  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(BLUE_PIN, LOW);

  delay(1000);

  // Red (turn just the red LED on):

  digitalWrite(RED_PIN, HIGH);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(BLUE_PIN, LOW);

  delay(1000);

  // Green (turn just the green LED on):

  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, HIGH);
  digitalWrite(BLUE_PIN, LOW);

  delay(1000);

  // Blue (turn just the blue LED on):

  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(BLUE_PIN, HIGH);

  delay(1000);

  // Yellow (turn red and green on):

  digitalWrite(RED_PIN, HIGH);
  digitalWrite(GREEN_PIN, HIGH);
  digitalWrite(BLUE_PIN, LOW);

  delay(1000);

  // Cyan (turn green and blue on):

  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, HIGH);
  digitalWrite(BLUE_PIN, HIGH);

  delay(1000);

  // Purple (turn red and blue on):

  digitalWrite(RED_PIN, HIGH);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(BLUE_PIN, HIGH);

  delay(1000);

  // White (turn all the LEDs on):

  digitalWrite(RED_PIN, HIGH);
  digitalWrite(GREEN_PIN, HIGH);
  digitalWrite(BLUE_PIN, HIGH);

  delay(1000); //the multicolor LED will constantly cycle through colors
}

void flashBlue(){  
  //THE BBLUE LED WILL FLASH
  for(int j =0; j<20; j++){
    digitalWrite(BBLUE_PIN, HIGH);
    delay(1000);
    digitalWrite(BBLUE_PIN, LOW);
    delay(1000);
  }
}

void policeLights(){



  digitalWrite(RED_PIN, HIGH);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(BLUE_PIN, LOW);//RED RGB
  delay(DELAY_TIME);
  digitalWrite(BBLUE_PIN, HIGH);
  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(BLUE_PIN, LOW);
  for(int g = 0; g<3; g++){
    digitalWrite(WHITE_PIN, HIGH);
    delay(STROBE_TIME);
    digitalWrite(WHITE_PIN, LOW);
    delay(STROBE_TIME);
  }
  delay(DELAY_TIME);
  digitalWrite(BBLUE_PIN, LOW);



} 

void linearFlash(){
  digitalWrite(RED_PIN, HIGH);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(BLUE_PIN, LOW);//RED RGB

  delay(100);

  digitalWrite(WHITE_PIN, HIGH);

  delay(100);

  digitalWrite(BBLUE_PIN, HIGH);

  delay(100);

  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(BLUE_PIN, LOW);//RED RGB
  digitalWrite(WHITE_PIN, LOW);
  digitalWrite(BBLUE_PIN, LOW);
  delay(200);

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//void strobe(int clocky){  
//  //THE WHITE LED WILL STROBE
//  int tops = clocky + 400;
//  int curclock = clocky;
//  for(curclock; curclock<tops; curclock++){
//    delay(1);
//    clock++;
//    if(curclock%50 == 0){
//    digitalWrite(WHITE_PIN, LOW);
//    }
//    if(curclock%100 ==0){
//    digitalWrite(WHITE_PIN, HIGH);
//    }
//  }
//}



void RBClick(){
  clock = 0;
  while(clock < (red+blue+1)){
    delay(1);
    clock++;
    if(clock%red == 0){
      //red on
      //blue off
      digitalWrite(RED_PIN, HIGH);
      digitalWrite(GREEN_PIN, LOW);
      digitalWrite(BLUE_PIN, LOW);//RED RGB
      digitalWrite(BBLUE_PIN, LOW);
    }
    if(clock%500 ==0){ 
      for(int i = 0; i<4; i++){
        digitalWrite(WHITE_PIN, HIGH);
        delay(50);
        clock = clock+50;
        if(clock%(red+blue) == 0){
          //blue on 
          //red off
          digitalWrite(BBLUE_PIN, HIGH);
          digitalWrite(RED_PIN, LOW);
          digitalWrite(GREEN_PIN, LOW);
          digitalWrite(BLUE_PIN, LOW);
        }
        digitalWrite(WHITE_PIN, LOW);
        delay(50);
        clock = clock+50;
        if(clock%(red+blue) == 0){
          //blue on 
          //red off
          digitalWrite(BBLUE_PIN, HIGH);
          digitalWrite(RED_PIN, LOW);
          digitalWrite(GREEN_PIN, LOW);
          digitalWrite(BLUE_PIN, LOW);
        }
      } 
    }
    if(clock%blue == 0){
      //blue on 
      //red off
      digitalWrite(BBLUE_PIN, HIGH);
      digitalWrite(RED_PIN, LOW);
      digitalWrite(GREEN_PIN, LOW);
      digitalWrite(BLUE_PIN, LOW);

    }
  }
}






