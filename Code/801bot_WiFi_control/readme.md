# 801bot WiFi Control

Allows control of the robot via a webpage hosted on the device through a wifi network created by the ESP32.

Be sure to set the WiFi SSID and Password in the User Settings section 801bot_WiFi_control.ino

Connect to the WiFi network, then load http://192.168.4.1/ in a web browser to control the robot with the virtual joystick.

### Settings

 Settings are found near the top of the .ino file

`ssid` - The SSID (Name) of the Wifi network created by the robot. Please change from the default.
`password` - The password of the Wifi network created by the robot. Please change from the default.

`rDeadzoneVal` and `lDeadzoneVal` - Adjust these up or down if the motors do not stop when the joystick is released.

`rServoPin` and `lServoPin` - Change if you connected the Servo signal wires to different pins.

### Dependencies

The following libraries are used in the project: 
- [AsyncTCP](https://github.com/me-no-dev/AsyncTCP) by Me No Dev
- [ESPAsyncWebServer](https://github.com/me-no-dev/ESPAsyncWebServer) by Me No Dev
- [ESP32-ESP32S2-AnalogWrite](https://github.com/Dlloydev/ESP32-ESP32S2-AnalogWrite) by David Lloyd


The web page served by the robot to control it is based off of [HTML-Joysticks](https://github.com/stemkoski/HTML-Joysticks) by Lee Stemkoski.

