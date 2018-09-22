#include <LiquidCrystal.h>               //library for LCD interface
#include <SPI.h>                         //library for SPI communication for SD card
#include <SD.h>                          // library for SD card interface
#include <Keypad.h>
#include <ctype.h>

File logfile;

const byte ROWS = 4; // Four rows
const byte COLS = 3; // Three columns
// Define the Keymap
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
const int countOfGR=2;
const int solenoidPin=8;
char database[countOfGR][7] = {   //database of all GR nums
  {'1','6','3','4','5','6','7'},
  {'1','2','3','4','5','6','8'}
};

char readNumber[7];
void appendNumber(char);
void compareNumber();
void writeToSDCard(bool);
uint8_t count=0;
// Connect keypad ROW0, ROW1, ROW2 and ROW3 to these Arduino pins.
byte rowPins[ROWS] = { 10, 9, 2, 7 };
// Connect keypad COL0, COL1 and COL2 to these Arduino pins.
byte colPins[COLS] = { 3, 5, 6}; 

const int rs = A0, en = A1, d4 = A2, d5 = A3, d6 = A4, d7 = A5; //LCD Pins

Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );  //initializing keypad
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);  //initializing LCD

void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(9600);
  pinMode(solenoidPin,OUTPUT);
  kpd.addEventListener(keypadEvent_num);
  kpd.setHoldTime(500);   //debouncing time
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.clear();
  lcd.print("Enter Password");
  lcd.setCursor(0,1);
}
static byte kpadState;

void loop() {
  // put your main code here, to run repeatedly:
  char key = kpd.getKey();
}

void keypadEvent_num( KeypadEvent key ) {
    // in here when using number keypad
    kpadState = kpd.getState( );
    switch(kpadState){
    case 0:     //IDLE
    break;

    case 1:     //PRESSED  
    break;
    
    case 2:     //HOLD  
    break;
    
    case 3:     //RELEASED
    appendNumber(key);
    break;
    
    default:
    break;
  }
    //Serial.println( kpadState );
}

void appendNumber(char recdData){
  lcd.print("*");
  readNumber[count]=recdData;
  count++;
  if(count>6){    //resetting count
    count=0;
    lcd.clear();
    compareNumber();
  }
}

void compareNumber(){
  lcd.clear();
  int diff;
  bool access=0;  //flag for access, if granted 1, if not granted 0
  for(int i=0;i<countOfGR;i++){
    diff=memcmp(readNumber, database[i], sizeof(readNumber));
    if(diff==0){
      lcd.print("Access Granted");
      digitalWrite(solenoidPin,HIGH);
      access=1;
    }
  }
  if(access==0){
    lcd.print("Access Denied");
  }
  writeToSDCard(access);
  delay(2000);
  digitalWrite(solenoidPin,LOW);
  lcd.clear();
  lcd.print("Enter Password");
  lcd.setCursor(0,1);
}

void writeToSDCard(bool status){
    if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    }
  status?myFile = SD.open("granted.txt",FILE_WRITE);:Serial.println("Denied");
}

