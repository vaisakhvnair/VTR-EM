#include <SoftwareSerial.h>
SoftwareSerial Bluetooth(10, 9); // RX, TX
int LED = 13; // the on-board LED
int Data; // the data received
int IN1 = 4;
int IN2 = 5;
int IN3 = 6;
int IN4 = 7;

void setup() {
  Bluetooth.begin(9600);
  Serial.begin(9600);
  Serial.println("Waiting for command...");
  Bluetooth.println("Enter command...");
  pinMode(LED,OUTPUT);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,HIGH);
  Serial.println("Stop");

}

void loop() {
  if (Bluetooth.available()){ //wait for data received
    Data=Bluetooth.read();
    if(Data=='1'){  
      digitalWrite(LED,1);
      Serial.println("LED On!");
      Bluetooth.println("LED On!");
    }
    else if(Data=='0'){
       digitalWrite(LED,0);
       Serial.println("LED Off!");
       Bluetooth.println("LED  On D13 Off ! ");
   }
    else if(Data=='s')
   {
     digitalWrite(IN1,HIGH);
     digitalWrite(IN2,HIGH);
     digitalWrite(IN3,HIGH);
     digitalWrite(IN4,HIGH);
     Serial.println("Stop");
     Bluetooth.println("Stop");
   }
   else if(Data=='a')
   {
     digitalWrite(IN1,LOW);
     digitalWrite(IN2,HIGH);
     digitalWrite(IN3,LOW);
     digitalWrite(IN4,HIGH);
     Serial.println("Forward");
     Bluetooth.println("Forward");
   }
   else if(Data=='b')
   {
     digitalWrite(IN1,HIGH);
     digitalWrite(IN2,LOW);
     digitalWrite(IN3,HIGH);
     digitalWrite(IN4,LOW);
     Serial.println("Reverse");
     Bluetooth.println("Reverse");
   }
   else if(Data=='c')
   {
     digitalWrite(IN1,LOW);
     digitalWrite(IN2,HIGH);
     digitalWrite(IN3,LOW);
     digitalWrite(IN4,LOW);
     Serial.println("left");
     Bluetooth.println("left");
   }
   else if(Data=='d')
   {
     digitalWrite(IN1,LOW);
     digitalWrite(IN2,LOW);
     digitalWrite(IN3,LOW);
     digitalWrite(IN4,HIGH);
     Serial.println("Right");
     Bluetooth.println("Right");
   }
    else{;}
  }
delay(100);
}
