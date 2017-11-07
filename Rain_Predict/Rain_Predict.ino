#include "dht.h"
#include <LiquidCrystal.h>
#define dht_apin A0 // Analog Pin sensor is connected to
#define LDRpin A5 // pin where we connected the LDR and the resistor
dht DHT;
float LDRValue = 0.0;     // result of reading the analog pin
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup(){
 // set up the LCD’s number of columns and rows:

  lcd.begin(16, 2);
  
  Serial.begin(9600);
  Serial.println("DHT11 Humidity & temperature Sensor\n\n");
  delay(1000);//Wait before accessing Sensor
 
}//end "setup()"
 
void loop(){
  //Start of Program 
 
    DHT.read11(dht_apin);
    
    Serial.print("Current humidity = ");
    Serial.print(DHT.humidity);
    Serial.print("%  ");
    Serial.print("temperature = ");
    Serial.print(DHT.temperature); 
    Serial.println("C  \n");
    LDRValue = (float)analogRead(LDRpin); // read the value from the LDR
    Serial.println(LDRValue);      // print the value to the serial port
    float Humidity = DHT.humidity;
    float Temperature = DHT.temperature;
    float Light = LDRValue;
    delay(2000);//Wait 5 seconds before accessing sensor again.
    int possibility;
    if(Humidity  > 70.0)
      if(Temperature >= -4.0 && Temperature < 10)
        if(Light < 500) possibility = 3;
        else if(Light < 700) possibility = 2;
        else if(Light < 800) possibility = 1;
        else if(Light < 1000) possibility = 0;
        else possibility = -1;
      else if(Temperature >= 10 && Temperature < 23)
        if(Light < 500) possibility = 4;
        else if(Light < 700) possibility = 3;
        else if(Light < 800) possibility = 2;
        else if(Light < 1000) possibility = 1;
        else possibility = 0;
      else if(Temperature >=23 && Temperature < 30)
        if(Light < 500) possibility = 5;
        else if(Light < 700) possibility = 4;
        else if(Light < 800) possibility = 3;
        else if(Light < 1000) possibility = 1;
        else possibility = 0;
      else if(Temperature >=30)
        if(Light < 500) possibility = 5;
        else if(Light < 700) possibility = 4;
        else if(Light < 800) possibility = 3;
        else if(Light < 1000) possibility = 1;
        else possibility = 0;
    else if(Humidity <= 65.0) possibility = 0;
    lcd.setCursor(0, 0);
    //lcd.autoscroll();
    switch (possibility){
      case -1:
        Serial.print("There is no possibility of rain \n");
        lcd.print("no chance");
        delay(2000);
        showdata(Humidity,Temperature,Light);
        break;
      case 0:
        Serial.print("There is a very low possibility of rain \n");
        lcd.print("very low chance");
        delay(2000);
        showdata(Humidity,Temperature,Light);
        break;
      case 1:
        Serial.print("There is a low possibility of rain \n");
        lcd.print("low chance");
        delay(2000);
        showdata(Humidity,Temperature,Light);
        break;
      case 2:
        Serial.print("There is a slight chance of rain \n");
        lcd.print("slight chance");
        delay(2000);
        showdata(Humidity,Temperature,Light);
        break;
      case 3:
        Serial.print("There is moderate chance of rain \n");
        lcd.print("moderate chance");
        delay(2000);
        showdata(Humidity,Temperature,Light);
        break;
      case 4:
        Serial.print("There is a high possibility of rain \n");
        lcd.print("high chance ");
        delay(2000);
        showdata(Humidity,Temperature,Light);
        break;
      case 5:
        Serial.print("There is a very high possibility of rain \n");
        lcd.print("very high chance");
        delay(2000);
        showdata(Humidity,Temperature,Light);
    }

 return;
}// end loop() 

void showdata(float humidity,float temperature,float light)
{
  String y="Hum Temp light";
  lcd.setCursor(0,0);
  lcd.print("                ");
  lcd.setCursor(0,0);
  lcd.print(y);
  delay(2000);
  lcd.setCursor(0,0);
  lcd.print("                ");
  
  lcd.setCursor(0,0);
  String g="";
  g=g+humidity+" ";
  g=g+temperature+" ";
  g=g+light+" ";
  lcd.print(g);
  delay(2000);
  lcd.setCursor(0,0);
  lcd.print("                ");
  
}

