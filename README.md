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

```cpp
#define FIREBASE_HOST "your-firebase.firebaseio.com"
#define FIREBASE_AUTH "yourF1rEba5et0ken8QGQ4Q5UZeK78wmtS7Qs466"
```

- `FIREBASE_HOST`: ที่อยู่ของ Firebase Realtime Database
- `FIREBASE AUTH`: Key Database Secrets (อยู่ที่ https://console.firebase.google.com/u/0/project/[ชื่อ-Project]/settings/serviceaccounts/databasesecrets)
