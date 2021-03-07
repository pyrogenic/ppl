#include "Temperature.h"

#include "Debug.h"

Temperature::Temperature(OneWire &oneWire) : oneWire(oneWire), sensors(&oneWire) {
}

void Temperature::setup() {
  sensors.begin();
  uint8_t count = sensors.getDeviceCount();
  Serial_printf("%d total sensors\n");
  count = sensors.getDS18Count();
  Serial_printf("Temperature Sensors:\n");
  Serial_printf("  DS18: %d\n", count);
};

void Temperature::debug() {
  uint8_t count = sensors.getDeviceCount();
  uint8_t address(0);
  for (int i = 0; i < count; ++i) {
    sensors.getAddress(&address, i);
    bool ppm = sensors.isParasitePowerMode();
    bool connected = sensors.requestTemperaturesByIndex(i);
    auto temp = sensors.getTemp(&address);
    Serial_printf("Temperature: %d°C (DS#%d %s 0x%x) (ppm: %s)\n", temp, i,
                  connected ? "===" : "=/=", address, ppm ? "yes" : "no");
  }
};
