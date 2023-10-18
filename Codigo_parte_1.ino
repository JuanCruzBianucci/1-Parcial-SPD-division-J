#define LED_A 11
#define LED_B 10
#define LED_C 9
#define LED_D 8
#define LED_E 7
#define LED_F 6
#define LED_G 5
#define APAGADOS 0

#define RESET 4
#define SUBE 3
#define BAJA 2
#define VISUALIZADOR_1 A4
#define VISUALIZADOR_2 A5
#define TIMEDISPLAYON 10


int sube =1;
int subePrevia = 1;
int baja = 1;
int bajaPrevia = 1;
int reset = 1;
int resetPrevia = 1;
int countDigit = 0;

void setup()
{
  for (int i = 5; i <= 11; i++)
  {
    configurarLed(i, OUTPUT);
  }
  pinMode(RESET, INPUT_PULLUP);
  pinMode(SUBE, INPUT_PULLUP);
  pinMode(BAJA, INPUT_PULLUP);
  pinMode(VISUALIZADOR_1, OUTPUT);
  pinMode(VISUALIZADOR_2, OUTPUT);
  digitalWrite(VISUALIZADOR_1, LOW);
  digitalWrite(VISUALIZADOR_2, LOW);
  Serial.begin(9600);
}

void loop()
{
  int pressed = keypressed();
  if (pressed == SUBE)
  {
    countDigit++;
    if (countDigit > 99)
      countDigit = 0;
  }
  else if (pressed == BAJA)
  {
    countDigit--;
    if (countDigit < 0)
      countDigit = 99;
  }
  else if (pressed == RESET)
  {
    countDigit = 0;
  }

  
    printCount(countDigit);
  
}

void printCount(int count)
{
  prendeDigito(APAGADOS);
  delay(TIMEDISPLAYON);
  dibujarNumero(LED_A, LED_B, LED_C, LED_D, LED_E, LED_F, LED_G, count / 10);
  prendeDigito(VISUALIZADOR_2);
  delay(TIMEDISPLAYON);
  prendeDigito(APAGADOS);
  dibujarNumero(LED_A, LED_B, LED_C, LED_D, LED_E, LED_F, LED_G, count - 10 * ((int)count / 10));
  prendeDigito(VISUALIZADOR_1);
  delay(TIMEDISPLAYON);
  
}

int keypressed()
{
  sube = digitalRead(SUBE);
  baja = digitalRead(BAJA);
  reset = digitalRead(RESET);
  
  if(sube == 1)
    subePrevia = 1;
  if (baja)
    bajaPrevia = 1;
  if(reset)
    resetPrevia = 1;
    	
    if (sube == 0 && sube != subePrevia)
    {
      subePrevia = sube;
      return SUBE;
    }
    if (baja == 0 && baja != bajaPrevia)
    {
      bajaPrevia = baja;
      return BAJA;
    }
    if (reset == 0 && reset != resetPrevia)
    {
      resetPrevia = reset;
      return RESET;
    }
  return 0;
 }

void dibujarNumero(int led_a, int led_b, int led_c, int led_d, int led_e, int led_f, int led_g ,  int numero)
{
 switch(numero)
  {
    case 0:
    	ConfigurarDisplay(1,1,1,0,1,1,1);
    	break;
    case 1:
    	ConfigurarDisplay(1,0,0,0,0,0,1);
    	break;
    case 2:
    	ConfigurarDisplay(1,1,0,1,1,1,0);
		break;
    case 3:
    	ConfigurarDisplay(1,1,0,1,0,1,1);
        break;
    case 4:
    	ConfigurarDisplay(1,0,1,1,0,0,1);
		break;
    case 5:
    	ConfigurarDisplay(0,1,1,1,0,1,1);
      	break;
    case 6:
    	ConfigurarDisplay(0,1,1,1,1,1,1);
    	break;
    case 7:
    	ConfigurarDisplay(1,1,0,0,0,0,1);
    	break;
    case 8:
    	ConfigurarDisplay(1,1,1,1,1,1,1);
    	break; 
    case 9:
    	ConfigurarDisplay(1,1,1,1,0,1,1);
    	break;
  }
}

void ConfigurarDisplay(int a, int b, int c, int d, int e, int f, int g)
{
  
  digitalWrite(LED_A,a);
  digitalWrite(LED_B,b);
  digitalWrite(LED_C,c);
  digitalWrite(LED_D,d);
  digitalWrite(LED_E,e);
  digitalWrite(LED_F,f);
  digitalWrite(LED_G,g);
}

void configurarLed(int led, int estado)
{
  pinMode(led, estado);
}

void prendeDigito(int digito)
{
  if(digito == VISUALIZADOR_1)
  {
    digitalWrite(VISUALIZADOR_1, LOW);
    digitalWrite(VISUALIZADOR_2, HIGH);
  }
  else if (digito == VISUALIZADOR_2 )
  {
    digitalWrite(VISUALIZADOR_1, HIGH);
    digitalWrite(VISUALIZADOR_2, LOW);
  }
  else
  {
    digitalWrite(VISUALIZADOR_1, HIGH);
    digitalWrite(VISUALIZADOR_2, HIGH);
  }
}


