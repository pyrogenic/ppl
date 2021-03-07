#pragma once

#include <DallasTemperature.h>
#include <OneWire.h>

typedef enum {
  kTS_DS3231, // RTC
  kTS_DS18,
  kTS_DHT11,
  kTS_DHT22,
  kTS_DHT21,
} TemperatureSensorType;

class Temperature {
public:
  Temperature(OneWire &oneWire);

  void setup();
  void debug();

private:
  OneWire &oneWire;
  DallasTemperature sensors;
};
