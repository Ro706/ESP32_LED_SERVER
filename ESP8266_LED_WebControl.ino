#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid = "WIFI_NAME";
const char* password = "WIFI_PASSWORD";

const int ledPin = 2; // D4 on NodeMCU (onboard LED - active LOW)

ESP8266WebServer server(80);
bool ledState = LOW;

String htmlPage() {
  String stateStr = ledState ? "ON" : "OFF";
  String buttonColor = ledState ? "#ff4444" : "#44ff44"; // Red if ON, Green if OFF
  String ledColor = ledState ? "#ff0000" : "#00ff00";    // Red if ON, Green if OFF

  return R"=====(
<!DOCTYPE html>
<html>
<head>
  <meta charset='utf-8'>
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>ESP8266 LED Control</title>
  <style>
    body {
      font-family: Arial, sans-serif;
      text-align: center;
      background-color: #f0f0f0;
      margin: 0;
      padding: 20px;
    }
    h1 {
      color: #333;
    }
    .led-status {
      font-size: 24px;
      font-weight: bold;
      margin: 20px 0;
    }
    .led-indicator {
      display: inline-block;
      width: 20px;
      height: 20px;
      border-radius: 50%;
      background-color: )=====" + ledColor + R"=====(;
      margin-left: 10px;
      vertical-align: middle;
      box-shadow: 0 0 10px )=====" + ledColor + R"=====(;
    }
    .toggle-btn {
      background-color: )=====" + buttonColor + R"=====(;
      color: white;
      border: none;
      padding: 12px 24px;
      font-size: 18px;
      border-radius: 5px;
      cursor: pointer;
      transition: background-color 0.3s;
    }
    .toggle-btn:hover {
      opacity: 0.8;
    }
    .container {
      max-width: 400px;
      margin: 50px auto;
      padding: 20px;
      background: white;
      border-radius: 10px;
      box-shadow: 0 4px 8px rgba(0, 0, 0, 0.1);
    }
  </style>
</head>
<body>
  <div class="container">
    <h1>ESP8266 LED Control</h1>
    <div class="led-status">
      LED: <span>)=====" + stateStr + R"=====(</span>
      <span class="led-indicator"></span>
    </div>
    <form action='/toggle' method='POST'>
      <button type='submit' class='toggle-btn'>Toggle LED</button>
    </form>
  </div>
</body>
</html>
)=====";
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
  while (!Serial) {
    delay(10);
  }
  Serial.println("\nSerial monitor initialized!");

  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, ledState);

  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi...");
  
  unsigned long startTime = millis();
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    if (millis() - startTime > 10000) {
      Serial.println("\nFailed to connect to WiFi!");
      break;
    }
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\nWiFi connected!");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
  } else {
    Serial.println("Could not connect to WiFi. Check credentials.");
  }

  server.on("/", handleRoot);
  server.on("/toggle", HTTP_POST, handleToggle);
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
}
