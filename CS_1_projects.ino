#include <LiquidCrystal.h>  // LCD library
#include <Keypad.h>         // keypad library
//int enter = 10; // Pins for enter button
  //LCD setup code
const int rs = A0, e = A1, d4 = A2, d5 = A3, d6 = A4, d7 = A5;
LiquidCrystal lcd(rs, e, d4, d5, d6, d7);
  // 4x4 Keypad Code
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char keys[ROWS][COLS] = {     // think of it like x,y
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'F', '0', 'E', 'D'}
};
byte rowPins[ROWS] = {9,8,7,6};  // connect to the row pinouts
byte colPins[COLS] = {5,4,3,2};  // connect to the column 
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
  // for enter key

void setup(){
  Serial.begin(9600);     //use serial monitor
  pinMode(10,INPUT);
  lcd.begin(16,2);
  lcd.setCursor(0,0);    // set cursor begind at (columns 1, rows 0)
  lcd.print(" Base Converter");
  lcd.setCursor(0,0);
}

void loop() {
 
      if (digitalRead(10) == HIGH ){
        lcd.print("A: bin  ");
        lcd.print("B: deci");
        lcd.setCursor(0,1);
        lcd.print("C: hex  ");
        lcd.print("D: oct");
        delay(1000);
       
       }
  
  char key = keypad.getKey();
      if (key == 'A'){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("B: dec ");
        lcd.print("C: hex  ");
        lcd.setCursor(0,1);
        lcd.print("D: oct  ");
        
        if ( key == 'B'){
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("entaer your number B");
        }
        else if ( key == 'B'){
          lcd.print("enter your number C");
        }
        else if ( key == 'D'){
          lcd.print("enter your number D");
        }
      }
      
      else if (key == 'B'){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("A: bin ");
        lcd.print("C: hex  ");
        lcd.setCursor(0,1);
        lcd.print("D: oct  ");
        
      }
      else if (key == 'C'){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("A: bin ");
        lcd.print("B: dec  ");
        lcd.setCursor(0,1);
        lcd.print("D: oct  ");
        
      }
      else if (key == 'D'){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("A: bin ");
        lcd.print("B: dec  ");
        lcd.setCursor(0,1);
        lcd.print("C: oct  ");
        
      }
}
