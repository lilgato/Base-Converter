#include <LiquidCrystal.h>  // LCD library
#include <Keypad.h>

//https://www.cs.cmu.edu/~pattis/15-1XX/common/handouts/ascii.html

const int rs = A0, e = A1, d4 = A2, d5 = A3, d6 = A4, d7 = A5;
LiquidCrystal lcd(rs, e, d4, d5, d6, d7);

long first = 0;  
long second = 0;
double total = 0;

char customKey;
const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1','2','3','+'},
  {'4','5','6','-'},
  {'7','8','9','*'},
  {'C','0','=','/'}
};
byte rowPins[ROWS] = {2,3,4,5};
byte colPins[COLS] = {17,16,15,14};

Keypad customKeypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS); 

void setup()
{
  lcd.begin(16,2);
  Serial.begin(9600);
}

void loop()
{
  customKey = customKeypad.getKey();
  switch(customKey) 
  {
  case '0' ... '9':
    first = first * 10 + (customKey - '0');
    Serial.println(first);
    lcd.print(first);
    break;

  case '+':
    first = (total != 0 ? total : first);
    Serial.println("+");
    second = SecondNumber();
    total = first + second;
    Serial.println(total);
    first = 0, second = 0;
    break;

  case '-':
    first = (total != 0 ? total : first);
    Serial.println("-");
    second = SecondNumber();
    total = first - second;
    Serial.println(total);
    first = 0, second = 0;
    break;

  case '*':
    first = (total != 0 ? total : first);
    Serial.println("*");
    second = SecondNumber();
    total = first * second;
    Serial.println(total);
    first = 0, second = 0;
    break;

  case '/':
    first = (total != 0 ? total : first);
    Serial.println("/");
    second = SecondNumber();

    second == 0 ? Serial.println("Invalid") : total = (float)first / (float)second;

    Serial.println(total);
    first = 0, second = 0;
    break;

  case 'C':
    total = 0;
    break;
  }
}

long SecondNumber()
{
  while( 1)
  {
    customKey = customKeypad.getKey();
    if(customKey >= '0' && customKey <= '9')
    {
      second = second * 10 + (customKey - '0');
      Serial.println(second);
    }

    if(customKey == '=') break;  //return second;
  }
 return second; 
}
