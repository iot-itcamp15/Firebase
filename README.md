# Firebase

การติดตั้งและเชื่อมต่อ Firebase Realtime Database

## Prerequisite
- `ESP8266` Compatible Board
- [Firebase Realtime Database](https://console.firebase.google.com)

### Library

- [`ESP8266WiFi.h`](https://github.com/esp8266/Arduino)
- [`FirebaseArduino.h`](https://github.com/FirebaseExtended/firebase-arduino/)
- [`ArduinoJson.h`](https://github.com/bblanchon/ArduinoJson/tree/v5.13.1) - `v5.13.1` ขึ้นไป (ไม่รองรับ `v6+`)

## Set-up

### WiFi Set-up

```cpp
#define WIFI_SSID "SSID_HERE"
#define WIFI_PASSWORD "PASSWORD_HERE"
```
- `WIFI_SSID`: SSID ของ WiFi
- `WIFI_PASSWORD`: รหัสผ่านของ WiFi

### Firebase Set-up

#### Firebase

ตั้ง Rules ทั้ง `.read` และ `.write` เป็น `true`

```json
{
  "rules": {
    ".read": true,
    ".write": true
  }
}
```

**หมายเหตุ** - การตั้งค่าแบบนี้ใช้สำหรับขึ้นตอนการพัฒนา (For development purposes only) ไม่ควรนำไปตั้งสำหรับการใช้งานจริง เนื่องจากจะมีปัญหาด้านความปลอดภัย

#### Arduino

```cpp
#define FIREBASE_HOST "your-firebase.firebaseio.com"
#define FIREBASE_AUTH "yourF1rEba5et0ken8QGQ4Q5UZeK78wmtS7Qs466"
```

- `FIREBASE_HOST`: ที่อยู่ของ Firebase Realtime Database (อยู่ในรูปแบบ `[ชื่อ-Project].firebaseio.com`)
- `FIREBASE AUTH`: Database Secrets 40 หลัก (อยู่ที่ `https://console.firebase.google.com/u/0/project/[ชื่อ-Project]/settings/serviceaccounts/databasesecrets`)

## Usage

### การเชื่อมต่อ

**Serial Monitor (`Ctrl` + `Shift` + `M`)**
```
Connecting.........
Connected: XXX.XXX.X.X
```
หากเชื่อมต่อสำเร็จจะขึ้นดังนี้ใน Serial Monitor (`XXX.XXX.X.X` - จะแสดงเป็น IP ที่เชื่อมต่อ)

### การส่งค่าขึ้น Realtime Database

**Syntax**

```cpp
Firebase.set[type](ชื่อตัวแปรที่ต้องการตั้ง, ค่าที่ต้องการตั้ง);
```

- `Firebase.setInt("analog", 1);` - เปลี่ยนค่าจำนวนเต็ม (Int)
- `Firebase.setFloat("analog", 1.1);` - เปลี่ยนค่าทศนิยม (Floating Point)
- `Firebase.setString("name", "ITCAMP");` - เปลี่ยนค่า String
- `Firebase.setBool("status", true);` - เปลี่ยนค่า Boolean

### การรับค่าจาก Realtime Database

**Syntax**

```cpp
Firebase.get[type](ชื่อตัวแปรที่ต้องการรับค่า);
```

- `Firebase.getInt("analog");` - รับค่าจำนวนเต็ม (Int)
- `Firebase.getFloat("analog");` - รับค่าทศนิยม (Floating Point)
- `Firebase.getString("name");` - รับค่า String
- `Firebase.getBool("status");` - รับค่า Boolean

## Author

- [phwt](https://github.com/phwt)
- [maizerocom](https://github.com/maizerocom)
