# Intelligent-Occupancy-Based-Energy-Management-System
Design a smart, automated, and energy-efficient lighting system that reduces energy wastage by automating lighting decisions based on real-time occupancy and ambient light conditions.

Required hardware components:
1. Arduino Uno - 1
2. USB Cable (Type-B) - 1
3. PIR Sensor (HC-SR501) - 1
4. LDR (Light Dependent Resistor) - 1
5. 10kΩ Resistor (brown-black-orange) - 1
6. 16x2 LCD Display with I2C module - 1
7. 5V Relay Module - 1
8. LED (any colour, 5mm) - 1
9. 220Ω Resistor (red-red-brown) - 1
10. Breadboard (large, 830 points) - 1
11. Jumper Wires (M-M and M-F pack) - 1 pack each (around 10 wires each)

<img width="1968" height="1070" alt="image" src="https://github.com/user-attachments/assets/dd557ad0-666a-4771-b7d8-3d5559c50502" />


Steps to integrate the software, once the hardware is all connected:
1. Download [Arduino IDE](https://www.arduino.cc/en/software)
2. Run Arduino code.c file once the USB is connected to both the Arduino and the source. Ensure all the hardware conections are tight to not short any of the components.

Expected Output:
1. Room is dark AND motion is detected → Light turns ON
2. No motion detected → Timer starts counting
3. After 2 seconds of inactivity → Light automatically turns OFF
4. LCD updates occupancy and light status dynamically.



