#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS D3
#define ERROR_DATA -555
OneWire oneWire(ONE_WIRE_BUS);

DallasTemperature sensors(&oneWire);

void setup(void){
  Serial.begin(9600);
  Serial.println("Data Formate");
  Serial.println("")
  sensors.begin();
}

void loop(void){
  sensors.requestTemperatures();
  float tempC = sensors.getTempCByIndex(0);

  if(tempC != DEVICE_DISCONNECTED_C)
    Serial.println(tempC);
  else Serial.println(ERROR_DATA);
}
