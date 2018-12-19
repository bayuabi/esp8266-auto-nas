#include <FirebaseArduino.h>

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char* SSID = "Lab_Elka";
const char* PASS = "daftaraslabdulu";

#define FIREBASE_HOST "jamur-ca24c.firebaseio.com" 
#define FIREBASE_AUTH "lDoJVczo5IoOg0fc0KsEpS4M7i8HMvstzl0IB9WQ"

void setup() {
  Serial.begin(9600);
  WiFi.begin(SSID, PASS);
  while(WiFi.status() != WL_CONNECTED){
    delay(200);
    Serial.println("Connecting...");
  }
  HTTPClient http;
  http.begin("http://nas.ub.ac.id/ac_portal/login.php");
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");
  int httpCode = http.POST("opr=pwdLogin&userName=165060300111007&pwd=bayumalang1998&rememberPwd=1");
  if(httpCode > 0){
    Serial.println(http.getString());
    
  }
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

void loop() {
  //Serial.println(Firebase.getString("wereng-app/FREKUENSI"));
  Firebase.setInt("suhu", 7);
  if(Firebase.failed()){
    Serial.println("error");
    Serial.println(Firebase.error());
  }
  delay(500);
}
