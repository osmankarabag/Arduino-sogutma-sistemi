#include <TimerOne.h>

const int lm35_pin = A0; //a0 pininin lm35 sıcaklık sensörü için tanımlanması
float dutyCycle = 100; //darbe genişliği modülasyonunun sinyal genişliği(fanın hızı)
int temp_adc_val; // sensörden okunan analog değer değişkeni . 10 bitlik okuma ......
float temp_val; 

void setup() {
  Serial.begin(9600); //seri haberleşme hızının 9600 olarak belirlenmesi(baudrate=9600)
  pinMode(5, OUTPUT);  //l298n motor surucusu IN1
  pinMode(6, OUTPUT);  //l298n motor surucusu IN2
  pinMode(9, OUTPUT);  //l298n motor surucusu EN1
  //fan yönününü belirledim
  digitalWrite(5, LOW);  
  digitalWrite(6, HIGH);
   // non-inverted fast PWM on OC0B with prescalar of 1
  //TCCR0A = (1 << COM0B1) | (1<<WGM01) | (1<<WGM00); 
  //TCCR0B = (1<<WGM02) | (1<<CS00);
  Timer1.initialize(40); // 40 us = 25 kHz
//
}

void loop() {
  temp_adc_val = analogRead(lm35_pin);  // sıcaklık okuma 
  temp_val = (temp_adc_val * 4.88); //adc değerini eşdeğer gerilime çevir 
  temp_val = (temp_val/10); // LM35, 10mv/°C çıkış veriyoruz 
  Serial.print("Temperature = ");
  Serial.print(temp_val);
  if(temp_val > 30)
  {
    Timer1.pwm(9, (dutyCycle / 100) * 1023);
    Serial.println("\t, FAN ÇALIŞIYOR");
  }
  else{
    Timer1.disablePwm(9);
    Serial.println("\t, FAN KAPALI");
  }
  delay(500);
}
