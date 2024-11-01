#include <WiFiS3.h>
#include <MQTTClient.h>
#include <R4HttpClient.h>

const char* ssid = "Winniw"; //username    
const char* password = "Wineiei1234";  // password
WiFiSSLClient client;

R4HttpClient http;

const char MQTT_BROKER_ADRRESS[] = "phycom.it.kmitl.ac.th"; //ชื่อ Host
const int MQTT_PORT = 1883;                          
const char MQTT_CLIENT_ID[] = "Nuttawit66070065"; // ชื่อไรก็ได้
const char MQTT_USERNAME[] = "";                          
const char MQTT_PASSWORD[] = "";                        

const char PUBLISH_TOPIC[] = "66070065/light";  // ชื่อ topic
const char SUBSCRIBE_TOPIC[] = "66070065/venus"; // ชื่อ tpoic

const int PUBLISH_INTERVAL = 5000;

unsigned long lastPublishTime = 0;
const int RED_PIN = 9;    // ขา Red
const int GREEN_PIN = 10;  // ขา Green
const int BLUE_PIN = 11;   // ขา Blue

WiFiClient network;
MQTTClient mqtt = MQTTClient(256);

void setup() {
  Serial.begin(9600);

  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  pinMode(RED_PIN, OUTPUT); // ตั้งค่าขา
  pinMode(GREEN_PIN, OUTPUT); // ตั้งค่าขา
  pinMode(BLUE_PIN, OUTPUT); // ตั้งค่าขา

  Serial.println("\nConnected to WiFi network");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  connectToMQTT();
}

void loop() {
  // ตรง loop มีแค่ mqtt.loop พอ
  mqtt.loop(); 

  // int sensorValue = analogRead(A0);
  // digitalWrite (4, HIGH) ; delayMicroseconds (10) ; digitalWrite (4, LOW) ;
  // int pulseWidth = pulseIn(2, HIGH) ;
  // Serial.print("Pulse Width: ");
  // Serial.println(pulseWidth);
  // long distance = pulseWidth/29/2;
  // Serial.print("Distance: ");
  // Serial.println(distance) ;
  
  // if (millis() - lastPublishTime > PUBLISH_INTERVAL) {
  // sendToMQTT(distance); 
    // lastPublishTime = millis();
  // }

}


void connectToMQTT() {
  mqtt.begin(MQTT_BROKER_ADRRESS, MQTT_PORT, network);

  mqtt.onMessage(messageHandler);

  Serial.print("Arduino UNO R4 - Connecting to MQTT broker");

  while (!mqtt.connect(MQTT_CLIENT_ID, MQTT_USERNAME, MQTT_PASSWORD)) {
    Serial.print(".");
    delay(100);
  }
  Serial.println();

  if (!mqtt.connected()) {
    Serial.println("Arduino UNO R4 - MQTT broker Timeout!");
    return;
  }

  if (mqtt.subscribe(SUBSCRIBE_TOPIC))
    Serial.print("Arduino UNO R4 - Subscribed to the topic: ");
  else
    Serial.print("Arduino UNO R4 - Failed to subscribe to the topic: ");

  Serial.println(SUBSCRIBE_TOPIC);
  Serial.println("Arduino UNO R4 - MQTT broker Connected!");
}

void sendToMQTT(float value) {
  char messageBuffer[10];
  dtostrf(value, 1, 2, messageBuffer);

  mqtt.publish(PUBLISH_TOPIC, messageBuffer);
  Serial.println("Arduino UNO R4 - sent to MQTT: topic: " + String(PUBLISH_TOPIC) + " | payload: " + String(messageBuffer));
}

void sendToMQTT(const String& message) {
  mqtt.publish(PUBLISH_TOPIC, message.c_str());

  Serial.println("Arduino UNO R4 - sent to MQTT: topic: " + String(PUBLISH_TOPIC) + " | payload: " + message);
}

void messageHandler(String& topic, String& payload) {
  Serial.println("Arduino UNO R4 - received from MQTT: topic: " + topic + " | payload: " + payload);
  // ---------- แปลงค่า payload จาก string เป็น int ----------
  int val = payload.toInt();
  // ---------- เงื่อนไขการแสดงผลตามโจทย์ ---------
  if (val >= 36 && val <= 50) {
      digitalWrite(RED_PIN, LOW);
      digitalWrite(GREEN_PIN, HIGH);
      digitalWrite(BLUE_PIN, HIGH);
  } else if(val >= 26 && val <= 35) {
      // Turn off all LEDs
      digitalWrite(RED_PIN, HIGH);
      digitalWrite(GREEN_PIN, HIGH);
      digitalWrite(BLUE_PIN, LOW);
  }  else if(val >= 10 && val <= 25) {
      // Turn off all LEDs
      digitalWrite(RED_PIN, HIGH);
      digitalWrite(GREEN_PIN, LOW);
      digitalWrite(BLUE_PIN, HIGH);
  }
   // ---------- เงื่อนไขการแสดงผลตามโจทย์ ---------
}