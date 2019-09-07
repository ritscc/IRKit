#include <Arduino.h>
#include <WiFi.h>

const int BAUDRATE = 115200;
const char* ssid = "SSID";
const char* password = "PASS";

const int GREEN_LED = 33;
const int USER_SW = 32;
const int IR_RECEIVE = 17; 
const int IR_LED = 4;

// Function prototype
void connectWiFi();

void setup() {
  Serial.begin(BAUDRATE);
  Serial.println();
  Serial.println("----------------------------");
  Serial.println("KC3-IRKit-Board Test Program");
  Serial.println("----------------------------");
  
  // Setup GPIO pin mode
  pinMode(USER_SW, INPUT_PULLUP);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(IR_RECEIVE, INPUT);
  pinMode(IR_LED, OUTPUT);

  // Connect Wi-Fi
  connectWiFi();

  // GREEN_LED ON
  digitalWrite(GREEN_LED, LOW);
}

void loop() {
  // Push BLACK BUTTON Send IR LED
  if( !digitalRead(USER_SW) ){
    digitalWrite(IR_LED, HIGH);
    delay(1);
    digitalWrite(IR_LED, LOW);
    delay(1);
  }

  // Receive IR LED ON
  digitalWrite(GREEN_LED, !digitalRead(IR_RECEIVE));
}

/**
 * Connect WiFi
 */
void connectWiFi()
{
    WiFi.begin(ssid, password);
    Serial.print("WiFi connecting...");
    while(WiFi.status() != WL_CONNECTED) {
        Serial.print(".");
        digitalWrite(GREEN_LED, HIGH);
        delay(100);
        Serial.print(".");
        digitalWrite(GREEN_LED, LOW);
        delay(100);
    }
    Serial.println("\nConnected.");
    Serial.print("IP ADDRESS: ");
    Serial.println(WiFi.localIP());
}