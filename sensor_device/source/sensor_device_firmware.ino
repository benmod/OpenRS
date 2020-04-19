#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>

#define BMP_SCL 13
#define BMP_SDO 12
#define BMP_SDA 11

#define BMP_CSB1 10
#define BMP_CSB2 9
#define BMP_CSB3 8
#define BMP_CSB4 7

// This was pre-computed as (tube_area / sqrt((tube_area / neck_area) ** 2 - 1)) * discharge_coefficient * 1000
#define VENTURI_PARAMETER 0.013619255 
// This should be temperature compensated in a future version
#define FLUID_DENSITY 1.29 


// Proximal pressure sensor
Adafruit_BMP280 bmp1(BMP_CSB1, BMP_SDA, BMP_SDO, BMP_SCL);

// Venturi neck pressure sensor
Adafruit_BMP280 bmp2(BMP_CSB2, BMP_SDA, BMP_SDO, BMP_SCL);

// Distal pressure sensor
Adafruit_BMP280 bmp3(BMP_CSB3, BMP_SDA, BMP_SDO, BMP_SCL);

// Ambient pressure sensor
Adafruit_BMP280 bmp4(BMP_CSB4, BMP_SDA, BMP_SDO, BMP_SCL);


float calculate_flowrate(float p1, float p2, float p3) {
  float delta_p = 0;
  bool negative = false;
  if(p1 - p2 > p3 - p2) {
    delta_p = p1 - p2;
  } else {
    delta_p = p3 - p2;
    negative = true;
  }
  if(delta_p > 0) {
    float flowrate = (sqrt((2.0*delta_p)/FLUID_DENSITY) * VENTURI_PARAMETER);
    if(negative) {
      return -flowrate;
    } else {
      return flowrate;
    }
  } else {
    return 0.0;
  }
}


void setup() {
  Serial.begin(9600);
  Serial.println("Started setup...");

  // We init the sensors
  Serial.println("Starting BMP280 device 1...");
  if (!bmp1.begin()) {
    Serial.println("BMP280 device 1 was not found.");
    while (1);
  }
  Serial.println("BMP280 1 started.");

  Serial.println("Starting BMP280 device 2...");
  if (!bmp2.begin()) {
    Serial.println("BMP280 device 2 was not found.");
    while (1);
  }
  Serial.println("BMP280 2 started.");

  Serial.println("Starting BMP280 device 3...");
  if (!bmp3.begin()) {
    Serial.println("BMP280 device 3 was not found.");
    while (1);
  }
  Serial.println("BMP280 3 started.");

  Serial.println("Starting BMP280 device 4...");
  if (!bmp3.begin()) {
    Serial.println("BMP280 device 4 was not found.");
    while (1);
  }
  Serial.println("BMP280 4 started.");
  Serial.println("Finished setup...");
}

void loop() {
  float ambient = bmp4.readPressure();
  float p1 = bmp1.readPressure();
  float p2 = bmp2.readPressure();
  float p3 = bmp3.readPressure();
  float flowrate = calculate_flowrate(p1, p2, p3);
  Serial.print(flowrate*60.0);
  Serial.print(" slm\n");
  float proximal_pressure = p1 - ambient;
  // We convert to hPa for ease of reading in the Arduino Plotter
  Serial.print(proximal_pressure/100.0);
  Serial.print(" hPa\n");
  delay(10);
}
