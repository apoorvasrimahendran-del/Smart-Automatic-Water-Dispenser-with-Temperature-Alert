#include<DHT.h>
DHT dht(3,DHT11);
int ir=7;
int ldr=6;
int relay=5;
int buzzer = 4;
int hand;
int light;
void setup(){
  pinMode(ldr,INPUT);
  pinMode(ir,INPUT);
  pinMode(relay,OUTPUT);
  pinMode(buzzer,OUTPUT);
  Serial.begin(9600);
  dht.begin();
}
void loop(){
  hand=digitalRead(ir);
  light=digitalRead(ldr);

  if(hand==LOW&&light==LOW){
    digitalWrite(relay,LOW);
    delay(2000);
    digitalWrite(relay,HIGH);
    Serial.println("HAND DETECTED");
    delay(1000);
  }
  else{
    digitalWrite(relay,HIGH);
    Serial.println("NO HAND");
    delay(1000);
  }
  float temp = dht.readTemperature();
  Serial.println(temp);
  if (temp>=31){
    digitalWrite(buzzer,HIGH);
  }
  else{
    digitalWrite(buzzer,LOW);
  }
}
