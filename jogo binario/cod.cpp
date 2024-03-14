#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

const int Pin0 = 6;
const int Pin1 = 5;
const int Pin2 = 4;
const int Pin3 = 3;
const int Pin4 = A4;
const int Pin5 = A3;
const int Pin6 = A2;
const int Pin7 = A1;
const int easyMode = A0;

int BinaryValue;

int correctNumber = 0;
int wrongNumber = 0;

const int buzzer = 13;
int freg;

const int buttonPin = 2;

int buttonState;
long randNumber;

void setup(){

lcd.begin(16, 2);
  
  pinMode(Pin0, INPUT_PULLUP);
  pinMode(Pin1, INPUT_PULLUP);
  pinMode(Pin2, INPUT_PULLUP);
  pinMode(Pin3, INPUT_PULLUP);
  pinMode(Pin4, INPUT_PULLUP);
  pinMode(Pin5, INPUT_PULLUP);
  pinMode(Pin6, INPUT_PULLUP);
  pinMode(Pin7, INPUT_PULLUP);
  
  pinMode(easyMode, INPUT_PULLUP);
  
  pinMode(buttonPin, INPUT_PULLUP);
  
  pinMode(buzzer, OUTPUT);
  
  randomSeed(analogRead(5));
  
  if (digitalRead(easyMode) == HIGH)
  {
   randNumber = random(0, 15);
  }
  else
  {
   randNumber = random(0,225);
  }

  lcd.print("Your number is");
  
  lcd.setCursor(0, 1);
  
  lcd.print(randNumber);
  
}

void checkNumber(){

  if (digitalRead(Pin0) == HIGH)
  {
   BinaryValue = 1;
  }
  else
  {
   BinaryValue = 0;
  }
  
  if (digitalRead(Pin1) == HIGH)
  {
   BinaryValue = BinaryValue + 2;
  }
  
  if (digitalRead(Pin2) == HIGH)
  {
   BinaryValue = BinaryValue + 4;
  }
  
  if (digitalRead(Pin3) == HIGH)
  {
   BinaryValue = BinaryValue + 8;
  }
  
  if (digitalRead(Pin4) == HIGH)
  {
   BinaryValue = BinaryValue + 16;
  }
  
  if (digitalRead(Pin5) == HIGH)
  {
   BinaryValue = BinaryValue + 32;
  }
  
  if (digitalRead(Pin6) == HIGH)
  {
   BinaryValue = BinaryValue + 64;
  }
  
  if (digitalRead(Pin7) == HIGH)
  {
   BinaryValue = BinaryValue + 128;
  }
  
  if (BinaryValue == randNumber)
  {
   correctNumber = 1;
  }
  else
  {
   wrongNumber = 1;
  }

}

void printBinary(){
  if (digitalRead(Pin7) ==LOW)
  {
   lcd.print("0");
  }
  else
  {
   lcd.print("1");
  }
  
  if (digitalRead(Pin6) ==LOW)
  {
   lcd.print("0");
  }
  else
  {
   lcd.print("1");
  }
  
  if (digitalRead(Pin5) ==LOW)
  {
   lcd.print("0");
  }
  else
  {
   lcd.print("1");
  }
  
  if (digitalRead(Pin4) ==LOW)
  {
   lcd.print("0");
  }
  else
  {
   lcd.print("1");
  }
  
  if (digitalRead(Pin3) ==LOW)
  {
   lcd.print("0");
  }
  else
  {
   lcd.print("1");
  }
  
  if (digitalRead(Pin2) ==LOW)
  {
   lcd.print("0");
  }
  else
  {
   lcd.print("1");
  }
  
  if (digitalRead(Pin1) ==LOW)
  {
   lcd.print("0");
  }
  else
  {
   lcd.print("1");
  }
  
  if (digitalRead(Pin0) ==LOW)
  {
   lcd.print("0");
  }
  else
  {
   lcd.print("1");
  }

}

void loop(){
  attachInterrupt (digitalPinToInterrupt(buttonPin), checkNumber, FALLING);
  
  lcd.setCursor(7, 1);
  
  printBinary();
  
  if (wrongNumber == 1)
  {
    
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Try again");
    lcd.setCursor(0, 1);
    lcd.print(randNumber);
    tone(buzzer, 200);
    delay(400);
    noTone(buzzer);
    wrongNumber = 0;
    correctNumber = 0;
  
  }
  
  if (correctNumber == 1)
  {
    tone(buzzer, 600);
    delay(100);
    tone(buzzer, 1000);
    delay(100);
    tone(buzzer, 800);
    delay(100);
    noTone(buzzer);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("correct!");
    lcd.setCursor(0, 1);
    lcd.print(randNumber);
    lcd.print(" is ");
    
    printBinary();
    
    delay(3000);
    
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Your number is");
    lcd.setCursor(0, 1);
    
    if (digitalRead(easyMode) == HIGH)
        {
         randNumber = random(0, 15);
        }
        else
        {
         randNumber = random(0, 225);
        }
    
    lcd.print(randNumber);
        
    correctNumber = 0;
    wrongNumber = 0;
  
  }

}

