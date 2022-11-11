// #include <ezTime.h>
#include <WiFi.h>
//#include "time.h"
#include "time_h.h"

const char* ntpServer = "pool.ntp.org";
const long  gmtOffset_sec = 3600;
const int   daylightOffset_sec = -18000;

void set_time() {
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);

  struct tm timeinfo;
  if(!getLocalTime(&timeinfo)){
    Serial.println("Failed to obtain time");
    return;
  }
  Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");
}

// int get_angle(){
//     //manually set up hour and angle?
//     int angle =0;
//     if(Toronto.hour() ==1||Toronto.hour() ==13){
//       angle = 30;
//     }
//     if(Toronto.hour() ==2||Toronto.hour() ==14){
//       angle = 60;
//     }
//     if(Toronto.hour() ==3||Toronto.hour() ==15){
//       angle = 90;
//     }
//     if(Toronto.hour() ==4||Toronto.hour() ==16){
//       angle = 120;
//     }
//     if(Toronto.hour() ==5||Toronto.hour() ==17){
//       angle = 150;
//     }
//     if(Toronto.hour() ==6||Toronto.hour() ==18){
//       angle = 180;
//     }
//     if(Toronto.hour() ==7||Toronto.hour() ==19){
//       angle = 210;
//     }
//     if(Toronto.hour() ==8||Toronto.hour() ==20){
//       angle = 240;
//     }
//     if(Toronto.hour() ==9||Toronto.hour() ==21){
//       angle = 270;
//     }
//     if(Toronto.hour() ==10||Toronto.hour() ==22){
//       angle = 300;
//     }
//     if(Toronto.hour() ==9||Toronto.hour() ==23){
//       angle = 330;
//     }
//     if(Toronto.hour() ==0||Toronto.hour() ==24){
//       angle = 0;
//     }

//     return angle;
// }

