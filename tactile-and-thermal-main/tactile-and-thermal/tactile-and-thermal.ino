#include <OneWire.h>
#include <DallasTemperature.h>

#include "pineapple.h"

const int sensor_bits = 9;
const int sensor_pin = A5;
const int GSR = ANLG1;  // GSRセンサのアナログピン番号をANLG1に設定

OneWire oneWire(sensor_pin);
DallasTemperature ths(&oneWire);

void setup() {
  pinMode(GATE, OUTPUT);
  digitalWrite(GATE, HIGH);
  Serial.begin(9600);
  ths.setResolution(sensor_bits);
}

void show_temp() {
  //ths.requestTemperatures();
  //Serial.print("THS, ");
  //Serial.print(ths.getTempCByIndex(0));
}

void show_press() {
  //int p;
  //p = analogRead(ANLG0);
  //Serial.print("ANLG0, ");
  //Serial.print(p);
}

void show_gsr() {
  int sensorValue = 0;
  long sum = 0;
  int gsr_average = 0;

  for(int i = 0; i < 10; i++) {  // Average the 10 measurements to remove the glitch
    sensorValue = analogRead(GSR) * 100;  // Scale the value by 100
    sum += sensorValue;
    delay(5);
  }
  gsr_average = sum / 10;
  // int last_three_digits = gsr_average % 1000;  // Extract the last three digits
  int scaled_value = gsr_average;
  Serial.print("GSR, ");
  Serial.println(scaled_value);  // Print the scaled value
}

void loop() {
  //show_temp();
  //Serial.print(", ");
  //show_press();
  show_gsr();
  Serial.println("");
  delay(100);  // 次のデータ取得まで100ミリ秒待機
}
