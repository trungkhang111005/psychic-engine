#include <Arduino.h>
#include <Bluepad32.h>
#include <ESP32Servo.h>

// Define the GPIO pin connected to the MOSFET
#define MOSFET_PIN 27
Servo myMotor;
Servo myServo;

ControllerPtr myControllers[BP32_MAX_GAMEPADS];
unsigned long controllerConnectedTime = 0;
bool controllerJustConnected = false;

void setup() {
  pinMode(MOSFET_PIN, OUTPUT);
  digitalWrite(MOSFET_PIN, LOW);  // Start with the MOSFET off

  myServo.attach(13);
  myMotor.attach(14);  // Attach the servo to GPIO 12
  BP32.setup(onConnectedController, onDisconnectedController);
  Serial.begin(115200);
  BP32.forgetBluetoothKeys();  // Optional, for clean pairing
}

void loop() {
  if (BP32.update()) {  // Check for controller updates
    for (auto &ctl : myControllers) {
      if (ctl && ctl->isConnected() && ctl->hasData()) {
        if (ctl->isGamepad()) {
          processGamepad(ctl);
        }
      }
    }
  }

  // Check if the controller was just connected and 3 seconds have passed
  if (controllerJustConnected && (millis() - controllerConnectedTime >= 3000)) {
    digitalWrite(MOSFET_PIN, HIGH);  // Turn on the MOSFET
    controllerJustConnected = false; // Reset the flag
  }
}

void onConnectedController(ControllerPtr ctl) {
  for (int i = 0; i < BP32_MAX_GAMEPADS; i++) {
    if (myControllers[i] == nullptr) {
      myControllers[i] = ctl;
      Serial.printf("Gamepad connected on index=%d\n", i);
      controllerConnectedTime = millis(); // Set the connection time
      controllerJustConnected = true; // Set the flag
      break;
    }
  }
}

void onDisconnectedController(ControllerPtr ctl) {
  for (int i = 0; i < BP32_MAX_GAMEPADS; i++) {
    if (myControllers[i] == ctl) {
      myControllers[i] = nullptr;
      Serial.printf("Gamepad disconnected from index=%d\n", i);
      if (!isAnyControllerConnected()) {
        digitalWrite(MOSFET_PIN, LOW);  // Turn off the MOSFET if no controllers are connected
      }
      break;
    }
  }
}

bool isAnyControllerConnected() {
  for (auto &ctl : myControllers) {
    if (ctl != nullptr) {
      return true;
    }
  }
  return false;
}

void processGamepad(ControllerPtr ctl) {
  int throttleValue = ctl->throttle();
  int brakeValue = ctl->brake();
  int joystickValue = ctl->axisX();
  int forwardSpeed = 0, reverseSpeed = 0;
  int servoPosition = map(joystickValue, -511, 512, 50, 131);
if (ctl->a())
{
   forwardSpeed = map(throttleValue, 0, 1023, 90, 70);
}
else
{
  forwardSpeed = map(throttleValue, 0, 1023, 90, 77);
}
  reverseSpeed = map(brakeValue, 0, 1023, 90, 103);
  if (ctl->axisX() > -1 && ctl->axisX() < 58) {
    myServo.write(90);
  } else {
    myServo.write(servoPosition);
  }

  if (ctl->brake() > 100) {
    myMotor.write(reverseSpeed);}
  else if (ctl->throttle() > 100) {
    myMotor.write(forwardSpeed);
  }

  if (ctl->throttle() < 100 && ctl->brake() < 100) {
    myMotor.write(90);
  }

  Serial.printf("joystick %d\n", ctl->axisX());
}
