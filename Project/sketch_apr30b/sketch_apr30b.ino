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
  // for enter 

 //long Num1,Num2;
 long Number;
 char key,action;
 boolean result = false;

int A = 10;
int B = 11;
int C = 12;
int D = 13;
int E = 14;
int F = 15;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);            //We are using a 16*2 LCD display
  lcd.setCursor(0, 0);         //set cursor position
  lcd.print("Base Converter"); //Intro Message
  delay(2000);
  lcd.clear();
}
void Display_Buttons(){     //loop for display the number on LCD
    lcd.clear();


    
    if (key == '0'){       //if 0 is Pressed
    Serial.println("Button 0");  
    if (Number==0)
    Number=0;
    else
    Number = (Number*10) + 0; 
    }

    if (key == '1'){      //If 1 is pressed
    Serial.println("Button 1"); 
    if (Number==0)
    Number=1;
    else
    Number = (Number*10) + 1;
    }
    
      if (key == '2'){     //if 2 is Pressed
    Serial.print("Button 2"); 
    if (Number==0)
    Number=2;
    else
    Number = (Number*10) + 2;
    }
    
     if (key == '3'){       //if 3 is pressed
    Serial.print("Button 3"); 
    if (Number==0)
    Number=3;
    else
    Number = (Number*10) + 3;
    }

     if (key == '4'){        //If 4 is pressed
    Serial.println ("Button 4"); 
    if (Number==0)
    Number=4;
    else
    Number = (Number*10) + 4;
    }

     if (key == '5'){         //if 5 is pressed
    Serial.print("Button 5"); 
    if (Number==0)
    Number=5;
    else
    Number = (Number*10) + 5; 
    }
      
     if (key == '6'){         //if 6 is pressed
    Serial.print("Button 6"); 
    if (Number==0)
    Number=6;
    else
    Number = (Number*10) + 6;
    }

      if (key == '7'){        //If 7 is pressed
    Serial.print("Button 7");
    if (Number==0)
    Number=7;
    else
    Number = (Number*10) + 7;
    }
     
     if (key == '8'){         //If 8 is press
    Serial.print("Button 8"); 
    if (Number==0)
    Number=8;
    else
    Number = (Number*10) + 8; 
    }
    
     if (key == '9'){          //if 9 is pressed
    Serial.print("Button 9");
    if (Number==0)
    Number=9;
    else
    Number = (Number*10) + 9; 
    }  
            ////////////////////////////////////Fix A B C D E F
    if (key == 'A'){          
    Serial.print("Button A");
      if (Number==0)
        Number == A;
      else
        Number = (Number*10) + A; 
    }

    if (key == 'B'){          //////Fix A B C D E F
      Serial.print("Button B");
      if (Number==0)
        Number=11;
      else
        Number = (Number*10) + 10; 
    }

    if (key == 'C'){          //////Fix A B C D E F
      lcd.print("Button C");
      if (Number==0)
        Number=10;
      else
        Number = (Number*10) + 10; 
    }

    if (key == 'D'){          //////Fix A B C D E F
      lcd.print("Button D");
    if (Number==0)
      Number=10;
    else
      Number = (Number*10) + 10; 
    }

    if (key == 'E'){          //////Fix A B C D E F
      lcd.print("Button E");
    if (Number==0)
      Number=10;
    else
      Number = (Number*10) + 10; 
    }

    if (key == 'F'){          //////Fix A B C D E F
      lcd.print("Button F");
      if (Number==0)
      Number=10;
      else
      Number = (Number*10) + 10; 
    }
    
//    if (key == 'Pin10'){                  ////change this to button
//    lcd.println ("Button Equal"); 
//    Num2=Number;
//    result = true;
//    }
  
}

//
//void Calculate_Result(){
//  if (pinMode(10) == HIGH);
//  lcd.print(decimal);
//  lcd.print(binary);
//  lcd.print(hex);
//  lcd.print(octal);
//}

void Display_Result(){     //loop for display the Final result
  if (result==true){      //Display the result
  lcd.print(Number);
  } 
  lcd.setCursor(0, 1);   // set the cursor to column 0, line 1
  lcd.print(Number); //Display the result
}

void loop()     {
key = keypad.getKey(); //storing pressed key value in a char

if (key == NO_KEY)
Display_Buttons();
Display_Result();
if (result == true)
Display_Result(); 
  
}
