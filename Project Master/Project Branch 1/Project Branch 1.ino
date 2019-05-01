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

boolean result = false;
long total;

int A = 10;
int B = 11;
int C = 12;
int D = 13;
int E = 14;
int F = 15;

char key = keypad.getKey();

void Display_Buttons(){
  
  int x = 0;
  int total = 0;
  int j = pow(x,total);
  
  for (int i=0; i>=6; i++){
        if (key == '0'){
          total = (0*j) + total;
        }
        if (key == '1'){
          total = (1*j) + total;
        }
        if (key == '2'){
          total = (2*j) + total;
        }
        if (key == '3'){
          total = (3*j) + total;
        }
        if (key == '4'){
          total = (4*j) + total;
        }
        if (key == '5'){
          total = (5*j) + total;
        }
        if (key == '6'){
          total = (6*j) + total;
        }
        if (key == '7'){
          total = (7*j) + total;
        }
        if (key == '8'){
          total = (8*j) + total;
        }
        if (key == '9'){
          total = (9*j) + total;
        }
        if (key == 'A'){
          total = (A*j) + total;
        }
        if (key == 'B'){
          total = (B*j) + total;
        }
        if (key == 'C'){
          total = (C*j) + total;
        }
        if (key == 'D'){
          total = (D*j) + total;
        }
        if (key == 'E'){
          total = (E*j) + total;
        }
        if (key == 'F'){
          total = (F*j) + total;
        }
      }
}
void Display_Result()     //loop for display the Final result
{
  lcd.setCursor(0, 0);   // set the cursor to column 0, line 1
  if(result==true){      //Display the result
//    lcd.print(" =");
    lcd.print(total);
  } 
  lcd.setCursor(0, 1);   // set the cursor to column 0, line 1
  lcd.print(total); //Display the result
}
void setup(){
  lcd.begin(16,2);
  Serial.begin(9600);     //use serial monitor
  lcd.setCursor(1, 0);    // set cursor begind at (columns 0, rows 0)
}
void loop(){
  key = keypad.getKey();
  if (result == true)
  Display_Buttons();
  Display_Result();
  
      
}
