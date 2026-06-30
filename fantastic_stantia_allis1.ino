#include <LiquidCrystal.h>

#include <Adafruit_NeoPixel.h>
#define neopin 5
#define sensor A0
LiquidCrystal LCD(2, 6, 9, 12, 3, 8);
#define boton 13
int botonultim = HIGH;
int act = false;

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(6, 5, NEO_GRB + NEO_KHZ800);
void setup()
{
  pinMode(sensor, INPUT);
  Serial.begin(9800);
  pixels.begin();
  pixels.clear();
  pixels.show();
  pinMode(boton, INPUT_PULLUP);
}

void loop()
{

  int valor = analogRead(sensor);
  
  int porcentaje = map( valor, 1022, 713, 0, 100);
  
  Serial.print("Sensor: ");
  Serial.print(porcentaje);
  Serial.println("% ");
  
  Serial.print(" N: 6 ");
  
  Serial.println(" Color: Rojo");
    
  Serial.print("Estado: ");
  if (act == true)
  {
    Serial.println("Activado");
  }
  else
  {
    Serial.println("Desactivado");
  }
  delay(250);
  
  
  
  int botonprendido = digitalRead(boton);
  
  if (botonprendido == LOW && botonultim == HIGH)
  {
    act = !act;
    delay(250);
    
    pixels.clear();
    pixels.show();
  }
  botonultim = botonprendido;
  
  if (act)
  {
    if(porcentaje <= 15)
    {
      pixels.setPixelColor(0,255,0,0);
      pixels.setPixelColor(1,255,0,0);
      pixels.show();
      delay(250);
      pixels.clear();
    }
    else if (porcentaje >= 50 && porcentaje <= 70)
    {
      pixels.setPixelColor(0,255,0,0);
      pixels.setPixelColor(1,255,0,0);
      pixels.setPixelColor(2,255,0,0);
      pixels.setPixelColor(3,255,0,0);
      pixels.show();
      delay(250);
      pixels.clear();
  	}
    else if (porcentaje >= 70)
    {
      pixels.setPixelColor(0,255,0,0);
      pixels.setPixelColor(1,255,0,0);
      pixels.setPixelColor(2,255,0,0);
      pixels.setPixelColor(3,255,0,0);
      pixels.setPixelColor(4,255,0,0);
      pixels.setPixelColor(5,255,0,0);
      pixels.show();
      delay(250);
      pixels.clear();
    }
  	else
  	{
    
  	}
    LCD.setCursor(0,0);
  	LCD.print("Sensor  Porcen  LED Color");
  	delay(250);
  	LCD.clear();
  	LCD.setCursor(0,1);
  	LCD.print(round(temperatura));
  	LCD.setCursor(5,1);
  	LCD.print(porcentajedeluz);
  	if (porcentaje < 10)
  	{
    	LCD.setCursor(6,1);
    	LCD.print("%");
  	}
  	else if (porcentaje >= 10 && porcentajedeluz < 100)
  	{
    	LCD.setCursor(7,1);
    	LCD.print("%");
  	}
  	else if (porcentaje == 100)
  	{
   		LCD.setCursor(8,1);
   		LCD.print("%");
  	}
  
}
  
 //Codigo desordenado porque pense en primeor hacer los que tenia en mente y despues agruparlos ordenadamente pero con el poco tiempo no se pudo.