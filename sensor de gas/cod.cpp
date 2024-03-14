int const PinA2 = A2;
int Pin7 = 7;
int Pin6 = 6;
int Pin5 = 5;
int Pin4 = 4;
int Pin3 = 3;
const int buzzer = 12;


void setup(){
  pinMode(Pin7, OUTPUT);
  pinMode(Pin6, OUTPUT);
  pinMode(Pin5, OUTPUT);
  pinMode(Pin4, OUTPUT);
  pinMode(Pin3, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop(){
int valor = analogRead(PinA2);
valor = map(valor, 300, 750, 0, 100);
digitalWrite(Pin7, HIGH);
noTone(buzzer);
  
  if (valor >= 20){
    digitalWrite(Pin6, HIGH);
    Serial.println("A fumaça se aproximou da camada 2");
  }else{
    digitalWrite(Pin6, LOW);
  }
  
  if (valor >= 40){
    digitalWrite(Pin5, HIGH);
    Serial.println("A fumaça se aproximou da camada 3");
  }else{
    digitalWrite(Pin5, LOW);
  }
  
  if (valor >= 60){
    digitalWrite(Pin4, HIGH);
    Serial.println("A fumaça se aproximou da camada 4");
  }else{
    digitalWrite(Pin4, LOW);
  }
  
  if (valor >= 80){
    digitalWrite(Pin3, HIGH);
    tone(buzzer, 300);
    delay(200);
    Serial.println("A fumaça se aproximou da camada 5");
  }else{
    noTone(buzzer);
    digitalWrite(Pin3, LOW);
  }

delay(250);
  
}