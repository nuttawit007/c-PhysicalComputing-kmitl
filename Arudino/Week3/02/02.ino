#include <SPI.h>
#include <Ethernet.h>
#include <PubSubClient.h>

// กำหนดข้อมูลสำหรับเชื่อมต่อ Ethernet
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };  // MAC address
IPAddress server(192, 168, 1, 100);  // IP address ของ MQTT broker (เช่น HiveMQ)

// สร้าง Client สำหรับ Ethernet และ MQTT
EthernetClient ethClient;
PubSubClient client(ethClient);

// กำหนดหัวข้อ (topic) ที่จะ Publish
const char* publish_topic = "sensor/analogValue";

void setup() {
  // เริ่มต้น Serial สำหรับการ debug
  Serial.begin(9600);

  // เริ่มต้นการเชื่อมต่อ Ethernet
  if (Ethernet.begin(mac) == 0) {
    Serial.println("Failed to configure Ethernet using DHCP");
    while (true);
  }

  // กำหนดเซิร์ฟเวอร์ของ MQTT broker
  client.setServer(server, 1883);

  // เชื่อมต่อกับ MQTT broker
  connectToMQTT();
}

void loop() {
  // ตรวจสอบการเชื่อมต่อ
  if (!client.connected()) {
    connectToMQTT();
  }

  client.loop();  // ทำงานของ MQTT client

  // อ่านค่าจากขา A0
  int analogValue = analogRead(A0);

  // แปลงค่าจาก Integer เป็น String
  String val_str = String(analogValue);

  // แปลง String เป็น Char Array เพื่อใช้ส่งผ่าน MQTT
  char messageBuffer[10];
  val_str.toCharArray(messageBuffer, 10);

  // ส่งข้อมูลไปยัง Broker โดย Publish ไปที่ Topic ที่กำหนด
  client.publish(publish_topic, messageBuffer);

  // รอ 1 วินาที ก่อนที่จะอ่านค่าครั้งถัดไป
  delay(1000);
}

// ฟังก์ชันเชื่อมต่อกับ MQTT Broker
void connectToMQTT() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // พยายามเชื่อมต่อกับ Broker
    if (client.connect("arduinoClient")) {
      Serial.println("connected");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);  // รอ 5 วินาทีแล้วลองใหม่
    }
  }
}
