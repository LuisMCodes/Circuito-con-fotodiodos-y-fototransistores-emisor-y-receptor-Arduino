/*
Proyecto 1: Circuito con fotodiodos y fototransistores (emisor y receptor)

Integrantes del equipo:
- López Ortiz Evan Derek 18140996
- Morales Bernal Luis Fernando 18141000
- Muñoz Meneses Karla 18140994

Tecnológico Nacional de México, Campus Querétaro
*/
int entrada_infraroja = 2; // primero
int entrada_infraroja2 = 4; // srgundo
int entrada_infraroja3 = 7; // tercero
int led = 12; // primer
int led2 = 13; // segundo
int led3 = 8; // tercero

void setup() {
  pinMode(entrada_infraroja, INPUT); // primero
  pinMode(entrada_infraroja2, INPUT); // segunda
  pinMode(entrada_infraroja3, INPUT); // tercera
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int value_entrada = digitalRead(entrada_infraroja);
  int value_entrada2 = digitalRead(entrada_infraroja2);
  int value_entrada3 = digitalRead(entrada_infraroja3);

  if (value_entrada3 == 1) {
    digitalWrite(led, 1);
    digitalWrite(led2, 1);
    digitalWrite(led3, 1);
    Serial.print("[3] The glass is full \n\n");
  } else if ((value_entrada2 == 1) && (value_entrada3 == 0)) {
    digitalWrite(led, 1);
    digitalWrite(led2, 1);
    digitalWrite(led3,0);
    Serial.print("[2] The glass is half full \n\n");
  } else if ((value_entrada == 1) && (value_entrada2 == 0) && (value_entrada3 == 0)) {
    digitalWrite(led, 1);
    digitalWrite(led2,0);
    digitalWrite(led3,0);
    Serial.print("[1] The glass has little water \n\n");
  } else  {
    digitalWrite(led,0);
    digitalWrite(led2,0);
    digitalWrite(led3,0);
    Serial.print("[0] No object \n\n"); 
  }
  
}
