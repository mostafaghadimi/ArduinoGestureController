# Gesture Media Controller


# Usages

Since it's a really simple implementation of media control using gesture detector, it has wide variety of usages such as car manufacturing. It can also implemented for different approaches not only controling media. 

- BMW Gesture Control is an innovative feature that is available in select BMW models and will allow drivers to use simple hand gestures to perform various actions in the vehicle with 3D technology – turn the volume up or down, accept or decline a phone call, change the rearview camera angle or select navigation on the BMW iDrive infotainment system.


# Physical Modules

NodeMCU, Jumper Wires, PAJ7620

# Challenges


TODO:// ADD STACKOVERFLOW ISSUE
https://arduino.stackexchange.com/questions/81294/cant-connect-paj7620-gesture-detector-module-to-nodemcu/81302#81302

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

![volume control](images/volume_control.png)

# Code

In the distinct phases, we have implemented the code for each of the modules.

## PAJ7620U2

First, we define gesture timings and import header files.

![paj header](images/header.png)

-- description

![paj setup](images/setup.png)

-- description

![paj setup](images/loop.png)

## ESP8266

TODO

## Web Socket Client

After connecting the modules in the previous sections, we need to connect them to a client in order to control a media player. We used [howler.js](https://github.com/goldfire/howler.js) as the base javascript library to create a music player.

![howler music player](images/player.png)

The player is controlled by events. We create a websocket on the player side in order to translate Arduino transferred data into music player actions.

![socket constants](images/constants.png)

![socket cases](images/socket_client_events.png)

Each case converts the input from the socket server into an action.
