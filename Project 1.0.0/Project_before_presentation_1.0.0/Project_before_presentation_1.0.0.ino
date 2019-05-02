//**********************  Week 8.py  *********************
//
// Name: Tai Tran
//
// Course: CSCI 1470
//
// Assignment: Homework #8
//
// Algorithm: Pseudocode
//
//  inport LCD library
//  set lcd variable to analog pin
//  call lcd pins(pins we using)
//  
//  import Keypad library
//  set ROWS to 4 and COLS to 4
//  get value key equal 1,2,3,A,4,5,6,B,7,8,9,C,F,0,E,D
//  called pin 9,8,7,6,5,4,3,2
//  
//  set variable number for storing input digits
//  
//  void setup() 
//  setup 16,2 LCD
//  setup Serial Monitor for testing
//  set LCD cursor start at (0,0)
//  intro message, delay 3 second, show menu
//  
//  void loop()
//  let key be key press
//  switch case 
//  if case 0 to 9 display number
//  if case A to D convert the number
//  if case F clear memory
// ***********************************************************

//LCD setup code
#include <LiquidCrystal.h>  // LCD library
const int rs = A0, e = A1, d4 = A2, d5 = A3, d6 = A4, d7 = A5;  // set lcd variable to analog pin
LiquidCrystal lcd(rs, e, d4, d5, d6, d7);   // call lcd pins(pins we using)

// 4x4 Keypad Code
#include <Keypad.h>         // keypad library
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char keys[ROWS][COLS] = {     // think of it like parameter (x,y)
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'F','0','E','D'}
};
byte rowPins[ROWS] = {9,8,7,6};  // connect to the row pinouts
byte colPins[COLS] = {5,4,3,2};  // connect to the column 
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

long number = 0;  // storing number for input(indexing)


int A = 10;   // set variable for Hex
int B = 11;
int C = 12;
int D = 13;
int E = 14;
int F = 15;
int pin10 = digitalRead(10);


//SETUP
void setup(){
  lcd.begin(16,2);        //setup 16,2 LCD
  Serial.begin(9600);     //use serial monitor
  pinMode(10,INPUT);
  lcd.setCursor(0,0);    // set cursor begind at (columns 1, rows 0)
  lcd.print(" Base Converter");
  lcd.setCursor(0,1);
  lcd.print(" by Tai V.Tran");
  delay(6000);
  lcd.clear();
  lcd.setCursor(0,0);     //intro message
  lcd.print("A:Dec ");
  lcd.print(" B:Binary ");
  lcd.setCursor(0,1);
  lcd.print("C:Hex ");
  lcd.print(" D:Octal ");
}

//LOOP
void loop() {
  char key = keypad.getKey();   //let key get value from keypad
  switch(key)     // similar to if/else statement
  {
  lcd.clear();
  case '0':
    lcd.clear();
    lcd.setCursor(0,1);   //display A,B,C,D option on bottom row
    lcd.print("A:b ");
    lcd.print("B:o ");
    lcd.print("C:h ");
    lcd.print("D:d ");
    lcd.setCursor(0,0);   //display key pressed on top row
    number = number * 10 + (key - '0');   //to store value and repeat
    Serial.println(number);
    lcd.print(number);
    break;

  case '1':
    lcd.clear();
    lcd.setCursor(0,1);   
    lcd.print("A:b ");
    lcd.print("B:o ");
    lcd.print("C:h ");
    lcd.print("D:d ");
    lcd.setCursor(0,0);   
    number = number * 10 + (key - '0');   
    Serial.println(number);
    lcd.print(number);
    break;
   case '2':
    lcd.clear();
    lcd.setCursor(0,1);   
    lcd.print("A:b ");
    lcd.print("B:o ");
    lcd.print("C:h ");
    lcd.print("D:d ");
    lcd.setCursor(0,0);   
    number = number * 10 + (key - '0');   
    Serial.println(number);
    lcd.print(number);
    break;
  case '3':
    lcd.clear();
    lcd.setCursor(0,1);   
    lcd.print("A:b ");
    lcd.print("B:o ");
    lcd.print("C:h ");
    lcd.print("D:d ");
    lcd.setCursor(0,0);   
    number = number * 10 + (key - '0');   
    Serial.println(number);
    lcd.print(number);
    break;
  case '4':
    lcd.clear();
    lcd.setCursor(0,1);   
    lcd.print("A:b ");
    lcd.print("B:o ");
    lcd.print("C:h ");
    lcd.print("D:d ");
    lcd.setCursor(0,0);   
    number = number * 10 + (key - '0');   
    Serial.println(number);
    lcd.print(number);
    break;
  case '5':
    lcd.clear();
    lcd.setCursor(0,1);   
    lcd.print("A:b ");
    lcd.print("B:o ");
    lcd.print("C:h ");
    lcd.print("D:d ");
    lcd.setCursor(0,0);   
    number = number * 10 + (key - '0');   
    Serial.println(number);
    lcd.print(number);
    break;
  case '6':
    lcd.clear();
    lcd.setCursor(0,1);   
    lcd.print("A:b ");
    lcd.print("B:o ");
    lcd.print("C:h ");
    lcd.print("D:d ");
    lcd.setCursor(0,0);   
    number = number * 10 + (key - '0');   
    Serial.println(number);
    lcd.print(number);
    break;
  case '7':
    lcd.clear();
    lcd.setCursor(0,1);   
    lcd.print("A:b ");
    lcd.print("B:o ");
    lcd.print("C:h ");
    lcd.print("D:d ");
    lcd.setCursor(0,0);   
    number = number * 10 + (key - '0');   
    Serial.println(number);
    lcd.print(number);
    break;
  case '8':
    lcd.clear();
    lcd.setCursor(0,1);   
    lcd.print("A:b ");
    lcd.print("B:o ");
    lcd.print("C:h ");
    lcd.print("D:d ");
    lcd.setCursor(0,0);   
    number = number * 10 + (key - '0');   
    Serial.println(number);
    lcd.print(number);
    break;
  case '9':
    lcd.clear();
    lcd.setCursor(0,1);   
    lcd.print("A:b ");
    lcd.print("B:o ");
    lcd.print("C:h ");
    lcd.print("D:d ");
    lcd.setCursor(0,0);   
    number = number * 10 + (key - '0');   
    Serial.println(number);
    lcd.print(number);
    break;

  case 'A':   //convert to Binary
    lcd.clear();
    lcd.print(number);
    lcd.print(" in Binary ");
    lcd.setCursor(0,1);
    lcd.print(" is ");
    lcd.print(number,BIN);
    Serial.println(number,BIN);
    break;
  case 'B':   //convert to Octal
    lcd.clear();
    lcd.print(number);
    lcd.print(" in Octal ");
    lcd.setCursor(0,1);
    lcd.print(" is ");
    lcd.print(number,OCT);
    Serial.println(number,OCT);
    break;
  case 'C':   //convert to Hex
    lcd.clear();
    lcd.print(number);
    lcd.print(" in Hexadecimal ");
    lcd.setCursor(0,1);
    lcd.print(" is ");
    lcd.print(number,HEX);
    Serial.println(number,HEX);
    break;
  case 'D':   //convert to Decimal
    lcd.clear();
    lcd.print(number);
    lcd.print(" in Decimal ");
    lcd.setCursor(0,1);
    lcd.print(" is ");
    lcd.print(number,DEC);
    Serial.println(number,DEC);
    break;
  case 'F': //Clear Memory
    number = 0;
    Serial.println("Clear");
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("A:b ");
    lcd.print("B:o ");
    lcd.print("C:h ");
    lcd.print("D:d ");
    lcd.setCursor(0,0);
    break;
    
//// Additional button for Hexa
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

//Acknowledgement/Source:

//  UHCL’s IEEE Workshop
//  https://sce.uhcl.edu/ieee/
//  
//  7-segment display guide:
//  https://www.youtube.com/watch?v=QRWN95K400w
//  http://thomas.bibby.ie/using-the-kyx-5461as-4-digit-7-segment-led-display-with-arduino/
//  
//  LCD guide:
//  https://www.youtube.com/watch?v=dZZynJLmTn8
//  
//  Arduino Reference Page:
//  https://www.arduino.cc/reference/en/#page-title
//  https://www.arduino.cc/en/Serial/Print
//  https://forum.arduino.cc/index.php?topic=248355.0
//  
//  4x4 Keypad Guide:
//  https://www.youtube.com/watch?v=GyprsoB887Y
//  https://learn.parallax.com/tutorials/language/propeller-c/propeller-c-simple-devices/read-4x4-matrix-keypad
