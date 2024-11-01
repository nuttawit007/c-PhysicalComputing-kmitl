#include <WiFiS3.h>
#include <MQTTClient.h>
#include <R4HttpClient.h>

const char* ssid = "Winniw"; //username
const char* password = "Wineiei1234";  //password
WiFiSSLClient client;

R4HttpClient http;

const char MQTT_BROKER_ADRRESS[] = "phycom.it.kmitl.ac.th"; //ชื่อ Host
const int MQTT_PORT = 1883;                          
const char MQTT_CLIENT_ID[] = "Nuttawit66070065";  // ชื่อไรก็ได้
const char MQTT_USERNAME[] = "";                          
const char MQTT_PASSWORD[] = "";                        

const char PUBLISH_TOPIC[] = "66070065/food"; // ชื่อ topic  
const char SUBSCRIBE_TOPIC[] = "66070065/food"; // ชื่อ topic

const int PUBLISH_INTERVAL = 5000;

unsigned long lastPublishTime = 0;

WiFiClient network;
MQTTClient mqtt = MQTTClient(256);

void setup() {
  Serial.begin(9600);

  pinMode(4, OUTPUT); // ตั้งค่ารับขา
  pinMode(2, INPUT); // ตั้งค่ารับขา

  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nConnected to WiFi network");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  connectToMQTT();
}

void loop() {
  mqtt.loop();
  // ----------code ที่แก้ไขเพิ่มเติมจาก tinkercat----------
  // ดูขาให้ถูก 4 หรือ 2
  long duration;
  int distanceCm, distanceInch;
  // Clear the trigPin
  digitalWrite(4, LOW);
  delayMicroseconds(2);
  
  // Set the trigPin HIGH for 10 microseconds
  digitalWrite(4, HIGH);
  delayMicroseconds(10);
  digitalWrite(4, LOW);
  
  // Read the echoPin, return the sound wave travel time in microseconds
  duration = pulseIn(2, HIGH);
  
  // Calculate the distance in cm and inches
  distanceCm = duration * 0.034 / 2;
  distanceInch = duration * 0.0133 / 2;
  // ----------code ที่แก้ไขเพิ่มเติมจาก tinkercat----------
  
  if (millis() - lastPublishTime > PUBLISH_INTERVAL) {
    sendToMQTT(distanceCm);  // ส่งค่า distanceCM เข้าไปโจทย์สั่ง
    lastPublishTime = millis();
  }

  delay(1000);
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

void sendToMQTT(int distanceCm) { // ตั้งชื่อ distanceCM 
  char messageBuffer[10];
  // ---------- เงื่อนไขการ แสดงผลตามโจทย์ ----------
  if (distanceCm > 20) {
    strcpy(messageBuffer, "off"); // การส่งค่าเป็น string เข้าไป
  } else {
    dtostrf(distanceCm, 1, 2, messageBuffer);
  }
  // ---------- เงื่อนไขการ แสดงผลตามโจทย์ ----------

  mqtt.publish(PUBLISH_TOPIC, messageBuffer);

  Serial.println("Arduino UNO R4 - sent to MQTT: topic: " + String(PUBLISH_TOPIC) + " | payload: " + String(messageBuffer));
}

void messageHandler(String& topic, String& payload) {
  Serial.println("Arduino UNO R4 - received from MQTT: topic: " + topic + " | payload: " + payload);
}