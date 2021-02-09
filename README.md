# ArduinoGestureController
A simple Arduino media controller using gestures like [BMW](https://www.youtube.com/watch?v=l8l1SZhccW4)


TODO:// ADD STACKOVERFLOW ISSUE
TODO:// ADD ESP8266-01 ISSUE
TODO:// ADD NODEMCU ISSUE

# Introduction

Gestures have become an essential part of our daily lives since the introduction of touch-screen mobile phones. Since the introduction of these actions, they have made our lives much more comfortable since every gesture is a shortcut, and it is easier for our minds to memorize them since they become muscle memory after a while. As technology moves forth, we are introduced to new possibilities, one of which is touchless gestures. Nowadays, we have access to various sensors that can help the development of such technologies easier.

[![Google Watch](https://img.youtube.com/vi/SVwV4uqETbI/0.jpg)](https://www.youtube.com/watch?v=SVwV4uqETbI)

In this project, we aimed to utilize this concept to control media. Since it's a straightforward implementation of media control using a gesture detector, it can handle various usages, such as car manufacturing, where the driver can control the music without further distractions. As another example, it can get integrated with smart homes to act as a remote controller for TV or stereo to facilitate the owners’ lives.

# Requirements

The explained concept consists of three major parts:

1. The gesture sensor
2. A wireless module to transmit the gestures
3. A software to receive the data and transform them into actions

As we have described in our preliminary report, we used the following modules to construct our sensor to satisfy the description and project requirements.

| Module      | Description |
| :---        |    :----:   |
| Arduino Uno board      | The main module that connects all other modules of the project       |
| PAJ7620U2 sensor   | The gesture detection sensor        |
| ESP8266   | WiFi module        |
| Cable   | Connect Arduino board to the computer        |

The flow of the sensor can be described as following.

1. The person moves his hand in front of the gesture sensor.
2. The gesture is captured and processed on the Arduino board.
3. The gesture gets translated into the action performed by the person.
4. The WiFi module receives the action.
5. The module transmits the action to the software present on a device, using a socket.
6. The device receives the action and acts accordingly.
7. 
We have depicted this flow in the following figure.

![volume control][https://github.com/parsaalian/ArduinoGestureController/blob/main/images/volume_control.png?raw=true]

# Code