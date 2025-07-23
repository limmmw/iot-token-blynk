#include <HardwareSerial.h>
#include <TinyGPSPlus.h>

HardwareSerial sim800(1); // RX=22, TX=21
HardwareSerial gps(2);    // RX=25, TX=23

TinyGPSPlus gpsData;

String apn = "internet"; // untuk Telkomsel
String server = "http://iot.nightcoding.my.id";

#define BUZZER_PIN 5
unsigned long lastCheck = 0;

void setup() {
  Serial.begin(115200);
  sim800.begin(9600, SERIAL_8N1, 22, 21);
  gps.begin(9600, SERIAL_8N1, 25, 23);
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW);
  delay(1000);
  setupGPRS();
}

void loop() {
  while (gps.available()) {
    gpsData.encode(gps.read());
  }

  if (gpsData.location.isUpdated()) {
    float lat = gpsData.location.lat();
    float lon = gpsData.location.lng();
    sendToServer(lat, lon);
    delay(10000);
  }

  if (millis() - lastCheck > 15000) {
    lastCheck = millis();
    checkBuzzer();
  }
}

void setupGPRS() {
  sendAT("AT");
  sendAT("AT+SAPBR=3,1,\"Contype\",\"GPRS\"");
  sendAT("AT+SAPBR=3,1,\"APN\",\"" + apn + "\"");
  sendAT("AT+SAPBR=1,1");
  delay(2000);
  sendAT("AT+SAPBR=2,1");
}

void sendToServer(float lat, float lon) {
  String url = server + "/update_location.php?lat=" + String(lat, 6) + "&lon=" + String(lon, 6);
  sendAT("AT+HTTPTERM");
  delay(1000);
  sendAT("AT+HTTPINIT");
  sendAT("AT+HTTPPARA=\"CID\",1");
  sendAT("AT+HTTPPARA=\"URL\",\"" + url + "\"");
  sendAT("AT+HTTPACTION=0");
  delay(6000);
  sendAT("AT+HTTPREAD");
  sendAT("AT+HTTPTERM");
}

void checkBuzzer() {
  String url = server + "/get_buzzer_status.php";

  sendAT("AT+HTTPTERM");
  delay(500);
  sendAT("AT+HTTPINIT");
  sendAT("AT+HTTPPARA=\"CID\",1");
  sendAT("AT+HTTPPARA=\"URL\",\"" + url + "\"");
  sendAT("AT+HTTPACTION=0");
  delay(3000);
  sim800.println("AT+HTTPREAD");
  delay(1000);

  String response = "";
  while (sim800.available()) {
    char c = sim800.read();
    response += c;
    Serial.write(c);
  }

  if (response.indexOf("1") >= 0) {
    digitalWrite(BUZZER_PIN, HIGH);
    Serial.println("BUZZER ON");
  } else if (response.indexOf("0") >= 0) {
    digitalWrite(BUZZER_PIN, LOW);
    Serial.println("BUZZER OFF");
  }

  sendAT("AT+HTTPTERM");
}

void sendAT(String cmd) {
  sim800.println(cmd);
  delay(2000);
  while (sim800.available()) {
    Serial.write(sim800.read());
  }
}
