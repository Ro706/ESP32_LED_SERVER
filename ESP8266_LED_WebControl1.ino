#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid = "WIFI_NAME";
const char* password = "WIFI_PASSWORD";

const int ledPin = 2; // D4 on NodeMCU (onboard LED - active LOW)

ESP8266WebServer server(80);
bool ledState = LOW;

String htmlPage() {
  String stateStr = ledState ? "ON" : "OFF";
  return "<!DOCTYPE html><html><head><meta charset='utf-8'><title>ESP8266 LED Control</title></head><body>"
         "<h1>LED is " + stateStr + "</h1>"
         "<form action='/toggle' method='POST'><button type='submit'>Toggle LED</button></form>"
         "</body></html>";
}

void handleRoot() {
  server.send(200, "text/html", htmlPage());
}

void handleToggle() {
  ledState = !ledState;
  digitalWrite(ledPin, ledState);
  server.sendHeader("Location", "/");
  server.send(302, "text/plain", "");
}

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, ledState);

  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nConnected! IP address: ");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);
  server.on("/toggle", HTTP_POST, handleToggle);
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
}
