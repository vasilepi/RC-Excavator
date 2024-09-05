# RC-Excavator
### This repository is for developing a remote controlled, robotic, mini excavator.
## About the excavator
The excavator will be an _8-DOF_ robotic excavator made entirely from 3D-printed in-house and commercial parts. Main material used for the in-house parts is Resin and PLA. The excavator DOFs are the following:
- 4 rotational for the **track wheels**
- 1 rotational for the **body**
- 1 rotational for the **boom**
- 2 linear for the **arm** and the **bucket movement**
\
![image](https://github.com/user-attachments/assets/486ad526-c18b-404e-a091-e9f16a10fc38)

The whole concept consists of 8 motor direction and speed control. For the RF communication BLE protocol is used with a PS3 controller and a [EPS32-DevKitc V4](https://docs.espressif.com/projects/esp-idf/en/stable/esp32/hw-reference/esp32/get-started-devkitc.html#get-started-esp32-devkitc-board-front). The code is written in the Arduino IDE using [PS3 Controller Host](https://github.com/jvpernis/esp32-ps3) library.
