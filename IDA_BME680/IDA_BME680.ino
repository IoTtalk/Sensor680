#include "seeed_bme680.h"
#include <SoftwareSerial.h>
#include <Bridge.h>

#define BME_SCK 13
#define BME_MISO 12
#define BME_MOSI 11
#define BME_CS 10
#define IIC_ADDR  uint8_t(0x76)
Seeed_BME680 bme680(IIC_ADDR); /* IIC PROTOCOL D2(SDA), D3(SCL)*/ 

void setup() {
    Serial.begin(115200); //for debug message

    while (!bme680.init()) {
        Serial.println("bme680 init failed ! can't find device!");
        delay(10000);
    }
    pinMode(13,OUTPUT); //IoTtalk successful registration notification
    Bridge.begin();   // D0 and D1 are used by the Bridge library.
}

void loop() {
    char D13[2];
    char valueStr[23];
    unsigned int valueInt=0;
    
    Bridge.get("Reg_done",  D13, 2);
    digitalWrite(13, atoi(D13));    

    if (bme680.read_sensor_data()) {
        Serial.println("Failed to perform reading :(");
        return;
    }
    
    //BME 大氣壓   D2, D3
    float Temperature = bme680.sensor_result_value.temperature;
    uint32_t AtmosphericPressure = bme680.sensor_result_value.pressure;
    float Humidity = bme680.sensor_result_value.humidity;
    uint32_t Gas = bme680.sensor_result_value.gas;
    dtostrf(Temperature, 6, 2, valueStr);
    Bridge.put("Temperature", valueStr); 
    dtostrf(AtmosphericPressure, 8, 0, valueStr);
    Bridge.put("AtPressure", valueStr);     
    dtostrf(Humidity, 6, 2, valueStr);
    Bridge.put("Humidity", valueStr);        
    dtostrf(Gas, 8, 0, valueStr);
    Bridge.put("Gas", valueStr);     
    Serial.print("Temp: ");        Serial.print(Temperature);    Serial.println(" C");// unit: C
    Serial.print("Humidity: ");    Serial.print(Humidity);    Serial.println(" %"); // unit:%
    Serial.print("Pressure: ");    Serial.print(AtmosphericPressure);    Serial.println(" Pa");     // unit: Pa
    Serial.print("Gas: ");    Serial.print(Gas);    Serial.println(" ohms");     // unit: Pa
    Serial.println("=========================================================================");    
    
    delay(1000);
}
