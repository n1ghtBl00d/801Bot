# 801bot WiFi Control

Allows control of the robot via a webpage hosted on the device through a wifi network created by the ESP32.

Be sure to set the WiFi SSID and Password on lines 10-11 of 801bot_WiFi_control.ino

Connect to the WiFi network, then load http://192.168.4.1/ in a web browser to control the robot with the virtual joystick.

### Dependencies:
[AsyncTCP](https://github.com/me-no-dev/AsyncTCP) by Me No Dev
[ESPAsyncWebServer](https://github.com/me-no-dev/ESPAsyncWebServer) by Me No Dev
[ESP32-ESP32S2-AnalogWrite](https://github.com/Dlloydev/ESP32-ESP32S2-AnalogWrite) by David Lloyd
[HTML-Joysticks](https://github.com/stemkoski/HTML-Joysticks) by Lee Stemkoski

