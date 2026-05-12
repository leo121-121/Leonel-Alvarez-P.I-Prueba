
#define RGB1_R 2
#define RGB1_G 3
#define RGB1_B 4

#define RGB2_R 5
#define RGB2_G 6
#define RGB2_B 7

#define RGB3_R 8
#define RGB3_G 9
#define RGB3_B 10

#define SONIDO 11

void setup() {
  pinMode(RGB1_R, OUTPUT); 
  pinMode(RGB1_G, OUTPUT); 
  pinMode(RGB1_B, OUTPUT);
  pinMode(RGB2_R, OUTPUT); 
  pinMode(RGB2_G, OUTPUT); 
  pinMode(RGB2_B, OUTPUT);
  pinMode(RGB3_R, OUTPUT);
  pinMode(RGB3_G, OUTPUT); 
  pinMode(RGB3_B, OUTPUT);
  pinMode(SONIDO, OUTPUT);
}

void loop() {
  analogWrite(RGB1_R, 255); 
  delay(1000);
  analogWrite(RGB1_R, 0); 
  zumbido();
  digitalWrite(RGB2_R, HIGH);
  digitalWrite(RGB2_B, HIGH);
  delay(1000);
  digitalWrite(RGB2_R, LOW);
  digitalWrite(RGB2_B, LOW);
  zumbido();
  analogWrite(RGB3_G, 40); 
  analogWrite(RGB3_B, 40);
  delay(1000);
  analogWrite(RGB3_G, 0);
  analogWrite(RGB3_B, 0);
  zumbido();
}
void zumbido() {
  analogWrite(SONIDO, 127); 
  delay(100);               
  analogWrite(SONIDO, 0);   
}
