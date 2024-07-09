# IoT-based-Accident-Detection-System

Road accidents continue to be a pressing global issue, causing immense loss of life, injuries, and property damage. Prompt and effective emergency response is critical in mitigating the impact of accidents and saving lives. However, traditional accident reporting mechanisms may suffer from delays, inaccuracies, and limited coverage, which can hinder timely intervention. To address these challenges, an Internet of Things (IoT) based accident detection system is proposed in this project.

The proposed system utilizes the advancements in IoT, sensor technologies, and communication networks to enable real-time detection of accidents and automatic alert generation. It employs Arduino Uno as the main controller board, and integrates GPS and GSM modules for location tracking and SMS alerting, as well as tilt, impact, and fire sensors for accurate detection of various accident scenarios. ESP32 CAMs are installed around the vehicle and triggered by the sensors to capture images of the accident scene. When an accidentis detected, the system sends SMS alerts with GPS location and vehicle details to emergency services and registered contacts, and captures images of the accident scene using triggered cameras, which are sent as email alerts.

The proposed system aims to provide a reliable and efficient solution for accident detection, notification, and emergency response, leveraging the capabilities of IoT technologies.

The insights gained from this project are expected to contribute to the field of road safety
and emergency services, and can be valuable for researchers in the transportation domain.

## How to Use
1. Connect the components as per the schematic.
2. Upload the `Accident_Detection_System.ino` file to your Arduino board.
3. Ensure the GSM module has an active SIM card.
4. Power on the system and test the sensors for impact, tilt, and flame detection.

## Components
- Arduino Uno
- GPS Module
- GSM Module
- Impact Sensors
- Tilt Sensor
- Flame Sensor
- ESP32-CAM

## NOTE
The car driveing system is independent from this project. 
Here we have built a wifi controlled car using Node MCU ESP 8266

![image](https://github.com/ParthChande/IoT-based-Accident-Detection-System/assets/119730313/d38baca8-3d46-4f81-8050-197e2027b876)
![image](https://github.com/ParthChande/IoT-based-Accident-Detection-System/assets/119730313/861a38cd-36d4-439f-a1c8-3ad7ea339e8a)
![image](https://github.com/ParthChande/IoT-based-Accident-Detection-System/assets/119730313/b31c3550-9363-4dba-b2bf-ad152cd79465)
![image](https://github.com/ParthChande/IoT-based-Accident-Detection-System/assets/119730313/c0a5bd01-1f5b-4641-9af7-9af7ed9343f5)
