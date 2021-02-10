#include <ESP8266WiFi.h>
#include <Wire.h>
#include "paj7620.h"

// Gesture Time Interval Configuration
#define GES_REACTION_TIME    800
#define GES_QUIT_TIME     1000

// WiFi Configuration
const uint16_t port = 8090;
const char * host = "<YOUR_IP>";

void setup()
{

  // PAJ7620  
  uint8_t error = 0;

  Serial.begin(9600);
  Serial.println("\nPAJ7620U2 TEST DEMO: Recognize 15 gestures.");

  error = paj7620Init();      // initialize Paj7620 registers
  if (error) 
  {
    Serial.print("INIT ERROR,CODE:");
    Serial.println(error);
  }
  else
  {
    Serial.println("INIT OK");
  }
  Serial.println("Please input your gestures:");

  // WiFi 
  Serial.begin(115200);
  WiFi.begin("<Your-SSID>", "<Your-WiFi-Password>");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("...");
  }

  Serial.print("WiFi connected with IP: ");
  Serial.println(WiFi.localIP());

}

void connectWifi(char * gesture){
  WiFiClient client;
    if (!client.connect(host, port)) {
        Serial.println("Connection to host failed");
//        delay(1000);
        return;
    }

    
    Serial.println("Connected to server successful!");
    client.print(gesture);
    Serial.println("Disconnecting...");
    client.stop();
}

void loop()
{
    uint8_t data = 0, data1 = 0, error; 
    error = paj7620ReadReg(0x43, 1, &data);
    
   if (!error) 
 {
    switch (data)                   // When different gestures be detected, the variable 'data' will be set to different values by paj7620ReadReg(0x43, 1, &data).
    {
      case GES_RIGHT_FLAG:
        delay(GES_REACTION_TIME);
        paj7620ReadReg(0x43, 1, &data);
        if(data == GES_LEFT_FLAG) 
        {
          Serial.println("Right-Left");
          connectWifi("Right-Left");
        }
        else if(data == GES_FORWARD_FLAG) 
        {
          Serial.println("Forward");
          connectWifi("Forward");
          delay(GES_QUIT_TIME);
        }
        else if(data == GES_BACKWARD_FLAG) 
        {
          Serial.println("Backward");
          connectWifi("Backward");
          delay(GES_QUIT_TIME);
        }
        else
        {
          Serial.println("Right");
          connectWifi("Right");
        }          
        break;
      case GES_LEFT_FLAG:
        delay(GES_REACTION_TIME);
        paj7620ReadReg(0x43, 1, &data);
        if(data == GES_RIGHT_FLAG) 
        {
          Serial.println("Left-Right");
          connectWifi("Left-Right");
        }
        else if(data == GES_FORWARD_FLAG) 
        {
          Serial.println("Forward");
          connectWifi("Forward");
          delay(GES_QUIT_TIME);
        }
        else if(data == GES_BACKWARD_FLAG) 
        {
          Serial.println("Backward");
          connectWifi("Backward");
          delay(GES_QUIT_TIME);
        }
        else
        {
          Serial.println("Left");
          connectWifi("Left");
        }          
        break;
      case GES_UP_FLAG:
        delay(GES_REACTION_TIME);
        paj7620ReadReg(0x43, 1, &data);
        if(data == GES_DOWN_FLAG) 
        {
          Serial.println("Up-Down");
          connectWifi("Up-Down");
        }
        else if(data == GES_FORWARD_FLAG) 
        {
          Serial.println("Forward");
          connectWifi("Forward");
          delay(GES_QUIT_TIME);
        }
        else if(data == GES_BACKWARD_FLAG) 
        {
          Serial.println("Backward");
          connectWifi("Backward");
          delay(GES_QUIT_TIME);
        }
        else
        {
          Serial.println("Up");
          connectWifi("Up");
        }
        break;
      case GES_DOWN_FLAG:
        delay(GES_REACTION_TIME);
        paj7620ReadReg(0x43, 1, &data);
        if(data == GES_UP_FLAG) 
        {
          Serial.println("Down-Up");
          connectWifi("Down-Up");
        }
        else if(data == GES_FORWARD_FLAG) 
        {
          Serial.println("Forward");
          connectWifi("Forward");
          delay(GES_QUIT_TIME);
        }
        else if(data == GES_BACKWARD_FLAG) 
        {
          Serial.println("Backward");
          connectWifi("Backward");
          delay(GES_QUIT_TIME);
        }
        else
        {
          Serial.println("Down");
          connectWifi("Down");
        }
        break;
      case GES_FORWARD_FLAG:
        delay(GES_REACTION_TIME);
        paj7620ReadReg(0x43, 1, &data);
        if(data == GES_BACKWARD_FLAG) 
        {
          Serial.println("Forward-Backward");
          connectWifi("Forward-Backward");
          delay(GES_QUIT_TIME);
        }
        else
        {
          Serial.println("Forward");
          connectWifi("Forward");
          delay(GES_QUIT_TIME);
        }
        break;
      case GES_BACKWARD_FLAG:     
        delay(GES_REACTION_TIME);
        paj7620ReadReg(0x43, 1, &data);
        if(data == GES_FORWARD_FLAG) 
        {
          Serial.println("Backward-Forward");
          connectWifi("Backward-Forward");
          delay(GES_QUIT_TIME);
        }
        else
        {
          Serial.println("Backward");
          connectWifi("Backward");
          delay(GES_QUIT_TIME);
        }
        break;
      case GES_CLOCKWISE_FLAG:
        Serial.println("Clockwise");
        connectWifi("Clockwise");
        break;
      case GES_COUNT_CLOCKWISE_FLAG:
        Serial.println("anti-clockwise");
        connectWifi("anti-clockwise");
        break;  
      default:
        paj7620ReadReg(0x44, 1, &data1);
        if (data1 == GES_WAVE_FLAG) 
        {
          Serial.println("wave");
          connectWifi("wave");
        }
        break;
    }
  }
  delay(100);
}
