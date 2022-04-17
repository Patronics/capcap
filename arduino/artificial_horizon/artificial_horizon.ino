#include <Arduino.h>
#include <U8g2lib.h>

#include "LIS3DHTR.h"
#include <Wire.h>
#define WIRE Wire
LIS3DHTR<TwoWire> LIS; //IIC

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE);  // High speed I2C

int soundPin = A2; // Analog sound sensor is to be attached to analog
int ledPin = 4; // Digital LED is to be attached to digital
int loudest= 0;
int quietest = 9999;
int average;
int sum;
void setup(void)
{
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  
  u8g2.begin();
  u8g2.setFlipMode(1);

  LIS.begin(WIRE,0x19); //IIC init
  LIS.setFullScaleRange(LIS3DHTR_RANGE_2G);
  LIS.setOutputDataRate(LIS3DHTR_DATARATE_50HZ);
  
}
 
void loop(void)
{

  //Serial.println(soundState);   // if the sound sensor’s value is greater than 200, the light will be on for 5 seconds.
  int xCoord=0;
  int yCoord=0;
  int zCoord=0;
  if (!LIS)
  {
    Serial.println("LIS3DHTR didn't connect.");
  } else {
    xCoord=1000*LIS.getAccelerationX();
    yCoord=1000*LIS.getAccelerationY();
    zCoord=1000*LIS.getAccelerationZ();
  }

  u8g2.setFont(u8g2_font_ncenB08_tr);
  u8g2.setCursor(0, 0);
  /*
  if(soundState > 250)
  {
    u8x8.print("Its loud  ");
    u8x8.println(soundState);
    if(soundState > loudest){
      loudest = soundState;
    }
    //delay(2000);
  }
  else
  {
    u8x8.print("Its quiet ");
    u8x8.println(soundState);
    if(soundState < quietest) {
      quietest = soundState;
    }
    //delay(200);
  }
  */
  /*for(int i=0; i <= 1000; i++) {
        int soundState = analogRead(soundPin); // Read sound sensor’s value
        if (soundState > 200)
      {
        digitalWrite(ledPin, HIGH);
       // delay(1000);
      }
      else
      {
        digitalWrite(ledPin, LOW);
      }
    sum =+ soundState;
    delay(1);
  }*/
  average = yCoord;
  u8g2.clearBuffer();
  //u8g2.print("Average = ");
  //u8g2.drawStr(0,10,(char*) String(average).c_str());   //write a number for debugging
  u8g2.drawCircle(64+(yCoord/25),32-(zCoord/30),5);
  u8g2.drawCircle(64,32,1);
  //u8g2.drawTriangle(20,20,20,100,100, 100-average);
  //u8g2.drawStr(100,10,String());
  //u8g2.print("  ");
  u8g2.drawLine(115,32,115, 32-xCoord/100);
  u8g2.drawLine(120,32,120, 32-yCoord/100);
  u8g2.drawLine(125,32,125, 32-zCoord/100);
  
  u8g2.sendBuffer();
  
  
}
