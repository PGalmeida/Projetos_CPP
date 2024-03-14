#define NOTE_D4 294
#define NOTE_G4 392
#define NOTE_A4 440
#define NOTE_A5 880

int tons[4] = {NOTE_A5, NOTE_A4, NOTE_G4, NOTE_D4};

int sequencia[100] = {};

int rodadaAtual = 0;

int passoAtualNaSequencia = 0;

int pinoAudio = 7;
int pinosLeds[4] = {8, 9, 10, 11};
int pinosBotoes[4] = {2, 3, 4, 5};

int botao_pressionado = 0;

int perdeuJogo = false;

void setup()
{
  for (int i = 0; i <= 3; i++)
  {
    pinMode(pinosLeds[i], OUTPUT);
  }

  for (int i = 0; i <= 3; i++)
  {
    pinMode(pinosBotoes[i], INPUT);
  }

  pinMode(pinoAudio, OUTPUT);


  randomSeed(analogRead(0));
}

void loop()
{
  if (perdeuJogo)
  {
    iniciarVariaveis();
  }

  if (rodadaAtual == 0)
  {
    tocarSomDeInicio();
    delay(500);
  }

  proximaRodada();

  reproduzirSequencia();

  aguardarJogador();

  delay(1000);
}

void proximaRodada()
{
  int numero_sorteado = random(0, 4);
  sequencia[rodadaAtual++] = numero_sorteado;
}

void reproduzirSequencia()
{
  for (int i = 0; i < rodadaAtual; i++)
  {
   	tone(pinoAudio, tons[sequencia[i]]);

    digitalWrite(pinosLeds[sequencia[i]], HIGH);
    delay(500);

    noTone(pinoAudio);

    digitalWrite(pinosLeds[sequencia[i]], LOW);
    delay(100);
  }

  	noTone(pinoAudio);
}

void aguardarJogador()
{
  for (int i = 0; i < rodadaAtual; i++)
  {
    aguardarJogada();
    verificarJogada();

    if (perdeuJogo)
    {
      break;
    }

    passoAtualNaSequencia++;
  }

  passoAtualNaSequencia = 0;
}

void aguardarJogada()
{
  boolean jogada_efetuada = false;

  while (!jogada_efetuada)
  {
    for (int i = 0; i <= 3; i++)
    {
      if (digitalRead(pinosBotoes[i]) == HIGH)
      {
        botao_pressionado = i;

        tone(pinoAudio, tons[i]);
        digitalWrite(pinosLeds[i], HIGH);

        delay(300);

        digitalWrite(pinosLeds[i], LOW);
       	noTone(pinoAudio);

        jogada_efetuada = true;
      }
    }

    delay(10);
  }
}

void verificarJogada()
{
  if (sequencia[passoAtualNaSequencia] != botao_pressionado)
  {
    for (int i = 0; i <= 3; i++)
    {
      tone(pinoAudio, tons[i]);
      digitalWrite(pinosLeds[i], HIGH);

      delay(200);

      digitalWrite(pinosLeds[i], LOW);
      noTone(pinoAudio);
    }

    tone(pinoAudio, tons[3]);

    for (int i = 0; i <= 3; i++)
    {
      digitalWrite(pinosLeds[0], HIGH);
      digitalWrite(pinosLeds[1], HIGH);
      digitalWrite(pinosLeds[2], HIGH);
      digitalWrite(pinosLeds[3], HIGH);

      delay(100);

      digitalWrite(pinosLeds[0], LOW);
      digitalWrite(pinosLeds[1], LOW);
      digitalWrite(pinosLeds[2], LOW);
      digitalWrite(pinosLeds[3], LOW);

      delay(100);
    }

    noTone(pinoAudio);

    perdeuJogo = true;
  }
}

void tocarSomDeInicio()
{
 tone(pinoAudio, tons[0]);

  digitalWrite(pinosLeds[0], HIGH);
  digitalWrite(pinosLeds[1], HIGH);
  digitalWrite(pinosLeds[2], HIGH);
  digitalWrite(pinosLeds[3], HIGH);

  delay(500);

  digitalWrite(pinosLeds[0], LOW);
  digitalWrite(pinosLeds[1], LOW);
  digitalWrite(pinosLeds[2], LOW);
  digitalWrite(pinosLeds[3], LOW);
  delay(500);
  noTone(pinoAudio);
}

void iniciarVariaveis()
{
  int sequencia[100] = {};

  rodadaAtual = 0;
  passoAtualNaSequencia = 0;

  perdeuJogo = false;
}