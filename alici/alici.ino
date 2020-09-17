#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
float deger[2];
 
RF24 radio(9, 10);
const uint64_t pipe = 0xE8E8F0F0E1LL;
 
void setup(void) {
Serial.begin(9600);
radio.begin();
radio.openReadingPipe(1, pipe);
radio.startListening();
lcd.begin();
lcd.backlight();
lcd.clear();
lcd.setCursor(0, 0);
lcd.print("Humidity    %");
lcd.setCursor(0, 1);
lcd.print("Temperature C");
delay(1500);
lcd.clear();
lcd.print("Connecting.....");
delay(1250);
}
 // temperature
void loop(void)
{
  Serial.println(deger[0]);
  delay (100);
if ( radio.available() )
{
bool done = false;
while (!done)
{
done = radio.read(deger, sizeof(deger));
lcd.clear();
delay(50);
lcd.setCursor(0, 0);
lcd.print("Box temperature");
lcd.setCursor(5, 1);
lcd.print(deger[0]);
lcd.print("C");
delay(1000);
lcd.clear();
lcd.setCursor(0, 0);
lcd.print("Box humidity");
lcd.setCursor(5, 1);
lcd.print(deger[1]);
lcd.print("%");
delay(1000);


}
}
else{
  lcd.setCursor(0, 0);
lcd.print("couldn't");
lcd.setCursor(5, 1);
lcd.print("connect");
lcd.print("");
delay(500);
lcd.clear();
}
}
