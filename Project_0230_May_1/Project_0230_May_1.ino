//LCD setup code
#include <LiquidCrystal.h>  // LCD library
const int rs = A0, e = A1, d4 = A2, d5 = A3, d6 = A4, d7 = A5;
LiquidCrystal lcd(rs, e, d4, d5, d6, d7);

// 4x4 Keypad Code
#include <Keypad.h>         // keypad library
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char keys[ROWS][COLS] = {     // think of it like x,y
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'F','0','E','D'}
};
byte rowPins[ROWS] = {9,8,7,6};  // connect to the row pinouts
byte colPins[COLS] = {5,4,3,2};  // connect to the column 
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

long first = 0;  
long second = 0;
double total = 0;

int A = 10;
int B = 11;
int C = 12;
int D = 13;
int E = 14;
int F = 15;
int pin10 = digitalRead(10);


//SETUP
void setup(){
  lcd.begin(16,2);
  Serial.begin(9600);    // set up serial monitor
  pinMode(10,INPUT);
  lcd.begin(16,2);       // set up lcd screen
  lcd.setCursor(0,0);    // set cursor origin at (columns 1, rows 0)
  lcd.print(" Base Converter");
  delay(1500);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("A:deci ");
  lcd.print("B:binary ");
  lcd.setCursor(0,1);
  lcd.print("C:hex  ");
  lcd.print("D:octal ");
  
}

void loop() {

  ///extras button for hexa
//  switch (digitalRead(10) == LOW){
//    case true:
//      lcd.print("A: bin  ");
//      lcd.print("B: deci");
//      lcd.setCursor(0,1);
//      //lcd.print("C: hex  "); //technical difficulty with Hexadecimal
//      lcd.print("D: oct");
//      delay(1000);
//      break;
//    case 'A':
//      lcd.clear();
//      lcd.setCursor(0,0);
//      lcd.print("Enter Binary number: ");
//      break;
//   }

  char key = keypad.getKey();
  switch(key) 
  {
  lcd.clear();
  case '0' ... '9':
    lcd.clear();
    lcd.setCursor(0,1);   //display A,B,C option on bottom row
    lcd.print("A:b ");
    lcd.print("B:o ");
    lcd.print("C:h ");
    lcd.print("D:d ");
    lcd.setCursor(0,0);   //display key pressed on top row
    first = first * 10 + (key - '0');   //to store value and repeat
    Serial.println(first);
    lcd.print(first);
    break;

  case 'A':
    lcd.clear();
    lcd.print(first);
    lcd.print(" is ");
    lcd.print(first,BIN);
    lcd.setCursor(0,1);
    lcd.print(" in Binary");
    Serial.println(first,BIN);
    break;
  case 'B':
    lcd.clear();
    lcd.print(first);
    lcd.print(" is ");
    lcd.print(first,OCT);
    lcd.setCursor(0,1);
    lcd.print(" in Octal");
    Serial.println(first,OCT);
    break;
  case 'C':
    lcd.clear();
    lcd.print(first);
    lcd.print(" is ");
    lcd.print(first,HEX);
    lcd.setCursor(0,1);
    lcd.print(" in Hexadecimal");
    Serial.println(first,HEX);
    break;
  case 'D':
    lcd.clear();
    lcd.print(first);
    lcd.print(" is ");
    lcd.print(first,DEC);
    lcd.setCursor(0,1);
    lcd.print(" in Decimal");
    Serial.println(first,DEC);
    break;
  case 'F': //Clear Memory
    total = 0;
    first = 0;
    second = 0;
    Serial.println("Clear");
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("A:b ");
    lcd.print("B:o ");
    lcd.print("C:h ");
    lcd.print("D:d ");
    lcd.setCursor(0,0);
    break;
    
/////Hexadecimal currently not working
//  case 'A':
//    lcd.clear();
//    first = first * 10 + (key - '7' );
//    Serial.println(first);
//    lcd.print(first);
//    break;
//  case 'B':
//    lcd.clear();
//    first = first * 10 + (key -'7');
//    Serial.println(first);
//    lcd.print(first);
//    break;
//  case 'C':
//    lcd.clear();
//    first = first * 10 + (key -'7');
//    Serial.println(first);
//    lcd.print(first);
//    break;
//  case 'D':
//    lcd.clear();
//    first = first * 10 + (key -'7');
//    Serial.println(first);
//    lcd.print(first);
//    break;
//  case 'E':
//    lcd.clear();
//    first = first * 10 + (key -'7');
//    Serial.println(first);
//    lcd.print(first);
//    break;
//  case 'F':
//    lcd.clear();
//    first = first * 10 + (key -'7');
//    Serial.println(first);
//    lcd.print(first);
//    break;
  }
}
