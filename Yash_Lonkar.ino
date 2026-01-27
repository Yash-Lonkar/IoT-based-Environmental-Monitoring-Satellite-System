#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ESP8266HTTPUpdateServer.h>
#include <Wire.h>
#include <Adafruit_BMP280.h>
#include <DHT11.h>

// Pin configuration for DHT11 sensor
#define DHT11_PIN D4  // GPIO2 on NodeMCU

// Wi-Fi AP credentials
const char* ssid = "NodeMCU-AP";
const char* password = "123456789";

// Sensor instances
DHT11 dht11(DHT11_PIN);
Adafruit_BMP280 bmp;  // I2C BMP280

// Flag to remember if BMP280 is found successfully
bool bmp280Found = false;

// Web server on port 80
ESP8266WebServer server(80);
ESP8266HTTPUpdateServer httpUpdater;

void handleDataRequest() {
  int temperature = 0;
  int humidity = 0;
  int err = dht11.readTemperatureHumidity(temperature, humidity);

  String json = "{";

  // Check if DHT11 read succeeded (no timeout or checksum error)
  if (err != DHT11::ERROR_TIMEOUT && err != DHT11::ERROR_CHECKSUM) {
    json += "\"temperature\":" + String(temperature) + ",";
    json += "\"humidity\":" + String(humidity) + ",";
  } else {
    json += "\"dht11_error\":\"" + String(DHT11::getErrorString(err)) + "\",";
    json += "\"temperature\":null,";
    json += "\"humidity\":null,";
  }

  // BMP280 pressure reading if available
  if (bmp280Found) {
    float pressure = bmp.readPressure() / 100.0F; // Convert Pa to hPa
    json += "\"pressure\":" + String(pressure, 2);
  } else {
    json += "\"pressure\":null";
  }

  json += "}";

  server.send(200, "application/json", json);
}

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println();
  Serial.println("Starting NodeMCU in AP mode with OTA support...");

  // Attempt to initialize BMP280 sensor at both common I2C addresses
  if (bmp.begin(0x76)) {
    bmp280Found = true;
    Serial.println("BMP280 found at 0x76");
  } else if (bmp.begin(0x77)) {
    bmp280Found = true;
    Serial.println("BMP280 found at 0x77");
  } else {
    Serial.println("BMP280 not found. Check wiring.");
  }

  // Start Wi-Fi Access Point
  WiFi.softAP(ssid, password);
  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(IP);

  // Setup /data endpoint
  server.on("/data", HTTP_GET, handleDataRequest);

  // Setup OTA update handler
  httpUpdater.setup(&server);

  // Start the web server
  server.begin();
  Serial.println("HTTP server started. Connect to the AP and:");
  Serial.println("  - GET /data for sensor data");
  Serial.println("  - GET /update for OTA firmware upload");
}

void loop() {
  server.handleClient();
}
