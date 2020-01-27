//          OLED
//  SCK -------------- A5
//  SCA -------------- A4
//  VDD -------------- 5V
//  GND -------------- GND

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
 
#define OLED_Address 0x3C
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

// SENSOR TEMPERATURA MLX90615
// VCC -------------- 3,3V
//  SCL -------------- D2
//  SCA -------------- D3
//  GND -------------- GND 

#include "MLX90615.h"
#include <I2cMaster.h>

#define SDA_PIN 10   //define the SDA pin
#define SCL_PIN 11   //define the SCL pin

SoftI2cMaster i2c(SDA_PIN, SCL_PIN);
MLX90615 mlx90615(DEVICE_ADDR, &i2c);

#define ledverm 7
#define ledverde 6



void setup() {

  pinMode(ledverm, OUTPUT);
  pinMode(ledverde, OUTPUT);

  
  Serial.begin(9600); 
  display.begin(SSD1306_SWITCHCAPVCC, OLED_Address);
  display.clearDisplay();
  display.display();
  delay(50);
  
  
  //mlx90615.writeEEPROM(Default_Emissivity); //write data into EEPROM when you need to adjust emissivity.
  //mlx90615.readEEPROM(); //read EEPROM data to check whether it's a default one.

}

void loop() {



float x = mlx90615.getTemperature(MLX90615_OBJECT_TEMPERATURE);


if ( x < 35.5 ){
 
}

else if ( x >= 35.5 && x <= 37.5){

 display.setTextSize(1);
 display.setTextColor(WHITE);
 display.setCursor(40,0);
 display.print("Normal");
 digitalWrite(ledverde, HIGH);
 delay(2000);
 digitalWrite(ledverde, LOW);
 delay(500);
  
}

else if ( x > 37.5 && x <= 39.5){

 display.setTextSize(1);
 display.setTextColor(WHITE);
 display.setCursor(40,0);
 display.print("Febre");
 digitalWrite(ledverm, HIGH);
 delay(500);
 digitalWrite(ledverm, LOW);
 delay(500);
  
}

else if ( x > 39.5 && x <= 41){

 display.setTextSize(1);
 display.setTextColor(WHITE);
 display.setCursor(35,0);
 display.print("Febre alta");
 digitalWrite(ledverm, HIGH);
 delay(350);
 digitalWrite(ledverm, LOW);
 delay(500);
  
}

else if ( x > 41){

 display.setTextSize(1);
 display.setTextColor(WHITE);
 display.setCursor(35,0);
 display.print("Hipertermia!");
 digitalWrite(ledverm, HIGH);
 delay(200);
 digitalWrite(ledverm, LOW);
 delay(500);
  
}


 
display.setTextSize(1);
display.setTextColor(WHITE);

//Temperatura objeto 
display.setCursor(0,15);
display.print("Objeto");
display.setCursor(0,25);
display.print(mlx90615.getTemperature(MLX90615_OBJECT_TEMPERATURE));
display.print(" C");

//Temperatura ambiente
display.setCursor(80,15);
display.println("Ambiente");
display.setCursor(80,25);
display.print(mlx90615.getTemperature(MLX90615_AMBIENT_TEMPERATURE));
display.println(" C");


display.display();
delay(1000);
display.clearDisplay();
 
}
  
  
  
  
  
  
  
  



