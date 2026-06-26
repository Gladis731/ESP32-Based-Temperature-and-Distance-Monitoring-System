# ESP32-Based Temperature and Distance Monitoring System

## Project Description
This project uses an ESP32 development board to monitor temperature and distance values. A DHT22 sensor is used to measure temperature, and an HC-SR04 ultrasonic sensor is used to measure distance. If the temperature or distance crosses the threshold value, the LED and buzzer are activated as an alert.

## Components Used
- ESP32 Development Board
- DHT22 Temperature Sensor
- HC-SR04 Ultrasonic Sensor
- LED
- Buzzer
- 220 ohm resistor
- Jumper wires

## Pin Connections
- DHT22 Data Pin → GPIO 4
- HC-SR04 TRIG Pin → GPIO 5
- HC-SR04 ECHO Pin → GPIO 18
- LED → GPIO 2
- Buzzer → GPIO 19

## Working
1. The DHT22 sensor reads the temperature.
2. The HC-SR04 sensor measures the distance.
3. The readings are displayed on the Serial Monitor every 2 seconds.
4. If temperature is greater than 35°C or distance is less than 20 cm, the LED and buzzer turn ON.
5. Otherwise, the LED and buzzer remain OFF.

## Output
- Temperature value in Celsius
- Distance value in centimeters
- Alert message when threshold is exceeded

## Platform
- Arduino IDE
- Wokwi Simulator
