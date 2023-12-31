#include <WiFi.h>
#include <WiFiAP.h>
#include <Arduino.h>

#include "src/ESPAsyncWebServer/ESPAsyncWebServer.h"
#include "src/ESP32-ESP32S2-AnalogWrite/Servo.h"

#include "html.h"


// ------ Begin User Settings ------
const char* ssid = "your-ssid";
const char* password = "your-password";

const int rServoPin = 33;
const int lServoPin = 34;

const int rDeadzoneVal = 1500;
const int lDeadzoneVal = 1500;

const int turnFactor = 3;

// ------ End User Settings ------

Servo servo = Servo();

AsyncWebServer server(80);
AsyncWebSocket ws("/ws");

int xValue = 0;
int yValue = 0;

void onEvent(AsyncWebSocket * server, AsyncWebSocketClient * client, AwsEventType type, void * arg, uint8_t *data, size_t len){
  String message = (char*)data;

  if (message.startsWith("X")) {
    xValue = message.substring(1).toInt();
  } else if (message.startsWith("Y")) {
    yValue = message.substring(1).toInt();
  }

  updateServos();
}

void setup() {
  Serial.begin(115200);
  Serial.print("Begin");

  servo.attach(lServoPin);
  servo.attach(rServoPin);

  WiFi.softAP(ssid, password);

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/html", index_html);
  });

  server.onNotFound([](AsyncWebServerRequest *request){
    request->send(404, "text/plain", "Not Found");
  });

  ws.onEvent(onEvent);
  server.addHandler(&ws);

  
  server.begin();

}

void loop() {
}

void updateServos() {
  Serial.println("starting updateServos()");
  
  int rVal = yValue - (xValue/turnFactor);
  int lVal = yValue + (xValue/turnFactor);

  if(rVal > 100) rVal = 100;
  if(rVal < -100) rVal = -100;
  if(lVal > 100) lVal = 100;
  if(lVal < -100) lVal = -100;

  int rValue = map(rVal, -270, 270, 2000, 1000);
  int lValue = map(lVal, -270, 270, 1000, 2000);

  if((abs(rVal) > 10) || (abs(lVal) > 10)){
    servo.writeMicroseconds(lServoPin, lValue);
    servo.writeMicroseconds(rServoPin, rValue);
  }else{
    servo.writeMicroseconds(lServoPin, lDeadzoneVal);
    servo.writeMicroseconds(rServoPin, rDeadzoneVal);
    servo.pause();
  }
}
