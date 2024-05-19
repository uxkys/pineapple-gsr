#include <OneWire.h>
#include <DallasTemperature.h>

#include "pineapple.h"

const int sensor_bits = 9;
const int sensor_pin = A5;

OneWire oneWire(sensor_pin);
DallasTemperature ths(&oneWire);

void setup() {
  pinMode(GATE, OUTPUT);
  digitalWrite(GATE, HIGH);
  Serial.begin(9600);
  ths.setResolution(sensor_bits);
}

void show_temp() {
  ths.requestTemperatures();
  Serial.print("THS, ");
  Serial.print(ths.getTempCByIndex(0));
}

void show_press() {
  int p;
  p = analogRead(ANLG0);
  Serial.print("ANLG0, ");
  Serial.print(p);
}

void show_gsr() {
  int g;
  g = analogRead(ANLG1);
  Serial.print("ANLG1, ");
  Serial.print(g);
}

void loop() {
  show_temp();
  Serial.print(", ");
  show_press();
  Serial.print(", ");
  show_gsr();
  Serial.println("");
  delay(1000); // 次のループまで1秒待機
}

