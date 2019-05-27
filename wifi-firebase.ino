#include <FirebaseArduino.h> //Library สำหรับเชื่อมต่อ Firebase
#include <ESP8266WiFi.h> //Library สำหรับการใช้งาน ESP8266 กับ WiFi

#define WIFI_SSID "Room334" //SSID ของ WiFi ห้อง 334
#define WIFI_PASSWORD "334334334" //รหัสผ่าน WiFi ห้อง 334

#define FIREBASE_HOST "your-firebase.firebaseio.com" //URL ของ Firebase จากใน Realtime Database
#define FIREBASE_AUTH "yourF1rEba5eaUtht0ken8QGQ4Q5UZeK78wmtS7Q" //Database Secret Key (หาได้จาก - เฟือง > Project Settings > Service accounts > Database Secrets)

void setup(){
    Serial.begin(115200);
    
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    Serial.print("Connecting");

    while(WiFi.status() != WL_CONNECTED) {
        Serial.print(".");
        delay(500);
    }
    Serial.println();
    Serial.print("Connected: ");
    Serial.println(WiFi.localIP());

    Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

void loop(){
    Firebase.setInt("analog", 16);
    Firebase.setFloat("analog", 16.16);
    Firebase.setString("name", "ITCAMP");
    Firebase.setBool("status", true);

    Serial.println(Firebase.getInt("analog"));
    Serial.println(Firebase.getFloat("analog"));
    Serial.println(Firebase.getString("name"));
    Serial.println(Firebase.getBool("status"));
    delay(1000);
}