#include <Arduino.h>
#include <U8x8lib.h>
U8X8_SSD1306_128X64_ALT0_HW_I2C u8x8(/* reset=*/ U8X8_PIN_NONE);

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
  
  u8x8.begin();
  u8x8.setFlipMode(1);

}
 
void loop(void)
{

  //Serial.println(soundState);   // if the sound sensor’s value is greater than 200, the light will be on for 5 seconds.
  

  u8x8.setFont(u8x8_font_chroma48medium8_r);
  u8x8.setCursor(0, 0);
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
  for(int i=0; i <= 1000; i++) {
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
  }
  average = sum;

  u8x8.print("Average = ");
  u8x8.print(average);
  u8x8.print("  ");
  //delay(1000);
  //u8x8.print("Loudest = ");
  //u8x8.println(loudest);
  //u8x8.print("Quietest = ");
  //u8x8.println(quietest);
  
}
