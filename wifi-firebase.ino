#include <FirebaseArduino.h> //Library สำหรับเชื่อมต่อ Firebase
#include <ESP8266WiFi.h> //Library สำหรับการใช้งาน ESP8266 กับ WiFi

#define WIFI_SSID "Room334" //SSID ของ WiFi ห้อง 334
#define WIFI_PASSWORD "334334334" //รหัสผ่าน WiFi ห้อง 334

#define FIREBASE_HOST "your-firebase.firebaseio.com" //URL ของ Firebase จากใน Realtime Database
#define FIREBASE_AUTH "yourF1rEba5eaUtht0ken8QGQ4Q5UZeK78wmtS7Q" //Database Secret Key (หาได้จาก - เฟือง > Project Settings > Service accounts > Database Secrets)

void setup(){
    Serial.begin(115200); //เริ่ม Serial Monitor ที่ 115200 baud
    
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD); //เริ่มเชื่อมต่อ WiFi ด้วยค่าที่กำหนดไว้ที่บรรทัดที่ 4 และ 5
    Serial.print("Connecting"); //บอกสถานะว่ากำลังเชื่อมต่ออยู่

    while(WiFi.status() != WL_CONNECTED){ //ทำการวนรอบจนกว่า WiFi จะเชื่อมต่อได้
        Serial.print(".");
        delay(500);
    }
    //เมื่อเชื่อมต่อได้แล้วแสดงที่อยู่ IP ที่เชื่อมต่อ
    Serial.println();
    Serial.print("Connected: ");
    Serial.println(WiFi.localIP());

    Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH); //เชื่อมต่อ Firebase ด้วยค่าที่กำหนดไว้ที่บรรทัดที่ 7 และ 8
}

void loop(){
    Firebase.setInt("analog", 1); //เปลี่ยนค่าจำนวนเต็ม (Int)
    Firebase.setFloat("analog_f", 1.1); //เปลี่ยนค่าทศนิยม (Floating Point)
    Firebase.setString("name", "ITCAMP"); //เปลี่ยนค่า String
    Firebase.setBool("status", true); //เปลี่ยนค่า Boolean

    Serial.println(Firebase.getInt("analog")); //รับค่าจำนวนเต็ม (Int)
    Serial.println(Firebase.getFloat("analog_f")); //รับค่าทศนิยม (Floating Point)
    Serial.println(Firebase.getString("name")); //รับค่า String
    Serial.println(Firebase.getBool("status")); //รับค่า Boolean
    delay(1000);
}
