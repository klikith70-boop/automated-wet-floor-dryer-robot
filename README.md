# Automated Wet Floor Dryer Robot

An automated floor-drying robot using an Arduino Uno, active IR obstacle detection, geared DC motors, an absorbent mop roller, and a relay-controlled hot-air blower[cite: 6, 10, 11, 28, 30].

## Hardware
- Arduino Uno R3[cite: 28]
- IR Obstacle Sensor[cite: 28]
- Dual L293D Motor Drivers[cite: 29]
- 12V DC Geared Motors + Wheels[cite: 29, 32]
- Absorbent Roller Mop[cite: 31]
- 12V Air Blower + SPDT Relay[cite: 30]
- 12V Rechargeable Battery[cite: 32]

## How It Works
- **Path Clear:** Robot moves forward with the blower and roller running[cite: 6, 11, 34].
- **Obstacle Detected:** Blower cuts off to save power, and the robot stops, reverses, turns left, and resumes forward path[cite: 6, 13, 34].
