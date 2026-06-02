#include <LiquidCrystal.h>

int sensorl = A0;
int pir = 13;
int trigg = 4;
int echo = 7;
int sensortp = A1;
int buzz = A5;
int rojo = 5;
int azul = 10;
int verde = 11;

LiquidCrystal LCD(2, 6, 9, 12, 3, 8);

void setup()
{
  Serial.begin(9800);
  //LCD
  LCD.begin( 16 , 2 );
  LCD.setCursor(0, 0);
  //luz
  pinMode( sensorl, INPUT );
  //mov
  pinMode( pir, INPUT);
  //dist
  pinMode( trigg, OUTPUT);
  pinMode( echo, INPUT);
  //temp
  pinMode(sensortp, INPUT);
  //buzzer
  pinMode(buzz, OUTPUT);
  //rgb
  pinMode( rojo, OUTPUT);
  pinMode( azul, OUTPUT);
  pinMode( verde, OUTPUT);
}

void loop()
{
  //luz
  int valorlz = analogRead(sensorl);
  
  int porcentajedeluz = map( valorlz, 1022, 713, 0, 100);
  porcentajedeluz = constrain(porcentajedeluz, 0, 100);
 
  //movimiento
  int movimiento = digitalRead(pir);
  
  //distancia
  digitalWrite( trigg, LOW);
  delayMicroseconds( 4 );
  digitalWrite( trigg, HIGH);
  delayMicroseconds( 10 );
  digitalWrite( trigg, LOW); 
  
  float duracion = pulseIn(echo, HIGH);
  int distancia = duracion * 0.01753;

  //temperatura
  float tension = analogRead( sensortp );
  tension = tension * 5.0;
  tension = tension / 1024.0;
  
  float temperatura = (tension - 0.5) * 100;
  
  Serial.println(round(temperatura));
  
  
  
  
  //mostrar en el LCD
  LCD.setCursor(0,0);
  LCD.print("Tem  Luz  Mv Cms");
  delay(250);
  LCD.clear();
  LCD.setCursor(0,1);
  LCD.print(round(temperatura));
  LCD.setCursor(5,1);
  LCD.print(porcentajedeluz);
  if (porcentajedeluz < 10)
  {
    LCD.setCursor(6,1);
    LCD.print("%");
  }
  else if (porcentajedeluz >= 10 && porcentajedeluz < 100)
  {
    LCD.setCursor(7,1);
    LCD.print("%");
  }
  else if (porcentajedeluz == 100)
  {
   LCD.setCursor(8,1);
   LCD.print("%");
  }
  
  LCD.setCursor(10,1);
  if (movimiento == 1)
  {
    LCD.print("Si");
  }else{
    LCD.print("No");
  }	
  
  LCD.setCursor(13,1);
  LCD.print(distancia);
  
  
  
  //Activacion de monitoreo nocturno
  if (porcentajedeluz <= 20)
  {
    //mov
    if (movimiento == 1)
    {
      analogWrite(rojo, 255);
      tone(buzz, 900);
      delay(400);
      noTone(buzz);
      analogWrite(rojo, 0);
      analogWrite(rojo, 255);
      tone(buzz, 900);
      delay(500);
      noTone(buzz);
      analogWrite(rojo, 0);
      analogWrite(rojo, 255);
      tone(buzz, 900);
      delay(400);
      noTone(buzz);
      analogWrite(rojo, 0);
      analogWrite(rojo, 255);
      tone(buzz, 900);
      delay(500);
      noTone(buzz);
      analogWrite(rojo, 0);
      analogWrite(rojo, 255);
      tone(buzz, 900);
      delay(400);
      noTone(buzz);
      analogWrite(rojo, 0); 
    }
    //temp
    if (temperatura >= 39)
    {
      analogWrite(rojo, 255);
      tone(buzz, 900);
      delay(400);
      noTone(buzz);
      analogWrite(rojo, 0);
      analogWrite(rojo, 255);
      tone(buzz, 900);
      delay(1500);
      noTone(buzz);
      analogWrite(rojo, 0);
      analogWrite(rojo, 255);
      tone(buzz, 900);
      delay(400);
      noTone(buzz);
      analogWrite(rojo, 0);
      analogWrite(rojo, 255);
      tone(buzz, 900);
      delay(1500);
      noTone(buzz);
      analogWrite(rojo, 0);
      analogWrite(rojo, 255);
      tone(buzz, 900);
      delay(400);
      noTone(buzz);
      analogWrite(rojo, 0); 
    }
    
    
  
  }
  //Monitoreo normal
  else{
    if (distancia < 100)
    {
      analogWrite(rojo, 255);
      tone(buzz, 900);
      delay(450);
      noTone(buzz);
      analogWrite(rojo, 0);
    }
    
    else if (temperatura >= 39)
    {
      tone(buzz,670);
      analogWrite(rojo,255);
      delay(300);
      noTone(buzz);
      delay(800);
      analogWrite(rojo,0);
    }
    else if (movimiento == 1)
    {
      tone(buzz,270);
      analogWrite(rojo,255);
      analogWrite(verde,255);
      delay(300);
      noTone(buzz);
      delay(1500);
      analogWrite(rojo,0);
      analogWrite(verde,0);
     //temp 
     
      
    } 
  }
}