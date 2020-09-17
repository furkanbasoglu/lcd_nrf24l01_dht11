#include  <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"     //Modül ile ilgili kütüphaneleri ekliyoruz


#include <dht11.h> // dht11 kütüphanesini ekliyoruz.
#define DHT11PIN 4 // DHT11PIN olarak Dijital 2"yi belirliyoruz.

dht11 DHT11;


float deger[2];     //mesaj isminde bir dizi tanımlıyoruz
RF24 verici(9, 10);    //kütüphane tarafından kullanılacak pinleri tanımlıyoruz
const uint64_t pipe = 0xE8E8F0F0E1LL;
int buton = 7;      //butonun bağlı olduğu dijital pin



void setup(void)
{ Serial.begin(9600);
  verici.begin();       //nrf yi başlatıyoruz
  verici.openWritingPipe(pipe);  //kanal id sı tanımlanıyor
}


void loop(void)
/*{// Bir satır boşluk bırakıyoruz serial monitörde.
  Serial.println();
  // Sensörün okunup okunmadığını konrol ediyoruz. 
  // chk 0 ise sorunsuz okunuyor demektir. Sorun yaşarsanız
  // chk değerini serial monitörde yazdırıp kontrol edebilirsiniz.
  int chk = DHT11.read(DHT11PIN);

  // Sensörden gelen verileri serial monitörde yazdırıyoruz.
  Serial.print("Nem (%): ");
  Serial.println((float)DHT11.humidity, 2);

  Serial.print("Sicaklik (Celcius): ");
  Serial.println((float)DHT11.temperature, 2);

  Serial.print("Sicaklik (Fahrenheit): ");
  Serial.println(DHT11.fahrenheit(), 2);

  Serial.print("Sicaklik (Kelvin): ");
  Serial.println(DHT11.kelvin(), 2);

  // Çiğ Oluşma Noktası, Dew Point
  Serial.print("Cig Olusma Noktasi: ");
  Serial.println(DHT11.dewPoint(), 2);

  // 2 saniye bekliyoruz. 2 saniyede bir veriler ekrana yazdırılacak.
  delay(2000);}
  
*/{
  float chk = DHT11.read(DHT11PIN);

  // Sensörden gelen verileri serial monitörde yazdırıyoruz.
  Serial.print("Nem (%): ");
  Serial.println((float)DHT11.humidity, 2);

  Serial.print("Sicaklik (Celcius): ");
  Serial.println((float)DHT11.temperature, 2);

  
  deger[0] = (float)DHT11.temperature,2;
  deger[1] = (float)DHT11.humidity;
  verici.write(deger,sizeof(deger));
  int a =verici.write(deger,sizeof(deger));
  Serial.print("Sicaklik: ");
  Serial.println(deger[0]);
  Serial.print("Nem: ");
  Serial.println(deger[1]);
  Serial.print("gonderim: ");
  Serial.println(a);
  delay(1000);
}
