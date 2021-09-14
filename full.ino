#include <ESP8266WiFi.h>
#include <SPI.h>
#include <BlynkSimpleEsp8266.h>
#define BLYNK_PRINT Serial  
#include <DHT.h>  
char auth[] = "nVcHzq_0LcuwjuuZSP-GTsRRFZ5hn5MK";
char ssid[] = "Vaisakh";
char pass[] = "vaisakhvnair";

#define Buzzer D5
#define DHTPIN 2          // Digital pin 4
#define DHTTYPE DHT11     // DHT 11
DHT dht(DHTPIN, DHTTYPE);
BlynkTimer timer;
 
int mq2 = A0; // smoke sensor is connected with the analog pin A0 
int data = 0; 

void setup() 
{
  pinMode(Buzzer, OUTPUT);
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  dht.begin();
  timer.setInterval(1000L, getSendData);
}
 
void loop() 
{
  timer.run(); // Initiates SimpleTimer
  Blynk.run();
}
 
void getSendData()
{
  data = analogRead(mq2);
  float h = dht.readHumidity();
  float t = dht.readTemperature(); // or dht.readTemperature(true) for Fahrenheit

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  
  Blynk.virtualWrite(V5, h);  //V5 is for Humidity
  Blynk.virtualWrite(V6, t);  //V6 is for Temperature 
  Blynk.virtualWrite(V2, data);
 
  if (data > 700 )
  {
    Blynk.notify("Smoke Detected!"); 
    digitalWrite(Buzzer, HIGH);
  }
  else
  {
    digitalWrite(Buzzer, LOW);
  }
 
}
