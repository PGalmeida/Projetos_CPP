int sinal = LOW;

void setup()
{
  pinMode(12, INPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
}

void loop(){
   sinal = digitalRead(12);
   digitalWrite(8, sinal);
  sinal = digitalRead(12);
   digitalWrite(7, !sinal);
}