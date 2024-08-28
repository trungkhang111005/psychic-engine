# Electronics Setup

## Components Needed
- **Microcontroller**: ESP32
- **Motor**: Surpass Hobby Platinum Waterproof Series, 28 mm diameter, 47 mm length
- **ESC**: Surpass Hobby Platinum Waterproof 45 A
- **Buck Converter**: LM2596
- **Servo**: SG 5010
- **MOSFET**: IRL 530N
- **Resistor**: 1 x 100 ohm
- **Jumper Wires**
- **Breadboard**: 1 x mini 20-holes long breadboard
- **Battery**: 2S/3S lithium polymer battery 1500mAh
- **Double-Sided Tape**
- **Rubber Bands**

## Setting Up ESP32 and Bluepad on Arduino IDE
1. **Install the ESP32 Board in Arduino IDE**:
   - Open Arduino IDE.
   - Go to `File > Preferences`.
   - Add these URLs in the "Additional Boards Manager URLs" field:
     ```
     https://espressif.github.io/arduino-esp32/package_esp32_dev_index.json
     https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
     https://raw.githubusercontent.com/ricardoquesada/esp32-arduino-lib-builder/master/bluepad32_files/package_esp32_bluepad32_index.json
     ```
   - Go to `Tools > Board > Boards Manager`, search for "ESP32", and install.

2. **Install Bluepad32 Library**:
   - Go to `Tools > Manage Libraries`, search for "Bluepad32", and install it.

3. **Upload the Arduino Script**:
   - Connect the ESP32 via USB.
   - Open the script from the `Arduino` folder.
   - Select the correct board and port, then upload the script.

## Layout and Wiring
1. **Component Placement**:
   - Place the MOSFET and buck converter on the breadboard.
   - Use double-sided tape and rubber bands for securing components.

2. **Wiring**:
   - **Buck Converter Setup**:
     - Connect the positive of the BEC to the buck converter input.
     - Connect the ground of the BEC to the buck converter ground.
     - Adjust the output to 3.3V.
     - Connect the buck converter output to the 3V3 pin on the ESP32.

   - **Servo Connection**:
     - Place MOSFET on the breadboard without shorting pins.
     - Connect a 100 ohm resistor between the MOSFET gate (1st pin) and ESP32 pin 27.
     - Connect the servo signal wire to ESP32 pin 13.
     - Connect servo power to the same row as BEC positive.

## Testing
1. Power up the setup and verify connections.
2. Use the Arduino IDE serial monitor for debugging.

## Usage
- Power on the car by connecting the battery to the ESP32.
- Use the RC controller or a mobile app to navigate the car.
