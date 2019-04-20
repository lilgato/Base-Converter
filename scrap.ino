#include <LiquidCrystal.h>  // LCD library
#include <Keypad.h>         // keypad library
//int enter = 10; // Pins for enter button
  //LCD setup code
const int rs = A0, e = A1, d4 = A2, d5 = A3, d6 = A4, d7 = A5;
LiquidCrystal lcd(rs, e, d4, d5, d6, d7);
  // 4x4 Keypad Code
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'F', '0', 'E', 'D'}
};
byte rowPins[ROWS] = {9,8,7,6};  // connect to the row pinouts
byte colPins[COLS] = {5,4,3,2};  // connect to the column 
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
  // for enter key



void setup() {
  Serial.begin(9600);     //use serial monitor
  lcd.setCursor(1, 0);    // set cursor begind at (columns 0, rows 0)
}

void loop() {

  char key = keypad.getKey();
    //print the pressed key
   if (key){
    Serial.print("Key ");
    Serial.print(key);
    Serial.println(" is pressed");
    lcd.setCursor(1,0);   // reset cursor again
    lcd.print("Key ");
    lcd.print(key);
    lcd.println(" is pressed");
   }
  
//  lcd.print("Arduino");
//  delay(3000);
//  lcd.setCursor(2,1);   // set cursor at location (columns,rows)
//  lcd.print("LCD TUTorial"); // print LCD Tutorial on (collums 2, rows1)
//  delay(3000);
//
//  lcd.clear();

}
