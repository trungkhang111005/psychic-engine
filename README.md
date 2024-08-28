# Psychic-Engine: 3D-Printed RC Car Project

## Introduction
This project involves the design, 3D printing, and assembly of a fully functional RC car, controlled by an ESP32 microcontroller. The car features a custom-designed rear differential and a rack-and-pinion steering system based on the Ackerman principle to avoid skidding. All parts are custom-designed, with the exception of a few metal machined parts where higher durability and precision were required.

## Features
- **Custom 3D-Printed Parts**: Major components are designed in SolidWorks, 3D-printed using PLA and PETG materials.
- **ESP32 Control**: The car is controlled using an ESP32 microcontroller, providing efficient wireless communication and processing power.
- **Ackerman Steering System**: The rack-and-pinion steering follows the Ackerman principle to reduce tire wear and improve cornering performance.
- **Rear Differential**: A custom-designed rear differential ensures smooth power distribution to the wheels, enhancing the car's handling.

## Technologies Used
- **CAD Software**: SolidWorks
- **3D Printer**: Sovol SV06
- **Materials**: PLA for structural components, PETG for functional parts
- **Microcontroller**: ESP32
- **Programming Language**: C++ (for Arduino/ESP32 script)

## Project Structure
- **/Structure/**
  - Contains the `SolidWorks` folder with all CAD files.
  - Assembly instructions for the physical components.
- **/Electronics/**
  - Contains the `Arduino` folder with ESP32 scripts.
  - Setup instructions for the electronic components.
- **/Images/**: Contains images and renderings of the 3D models and the assembled RC car.

## Getting Started
### Prerequisites
- SolidWorks installed for viewing and modifying CAD files.
- Arduino IDE configured to work with ESP32 for uploading the script.
- A Sovol SV06 3D printer (or similar) with a print plate size of at least 235x235 mm.

### Demo
[Watch the RC car in action](https://www.youtube.com/watch?v=example)

## Challenges and Solutions
- **Steering System**: Ensuring the steering followed the Ackerman principle was challenging. This was resolved by carefully calculating the steering angles and adjusting the rack-and-pinion design.
- **Material Selection**: Choosing the right material for each part was crucial. PLA was used for structural parts, while PETG was selected for functional components that require more durability.

## Future Improvements
- Integrating Bluetooth control via a mobile app.
- Enhancing the suspension system for better performance on rough terrain.
- Adding autonomous driving capabilities using sensors.

## License
- The ESP32 script is licensed under the MIT License.
- The SolidWorks design files are licensed under the Creative Commons Attribution 4.0 International License.

## Acknowledgments
- Thanks to [Open Source Resources] for the initial ESP32 code framework.
- Special thanks to [Your Instructor] for guidance on the project.

## Contact
If you have any questions or want to collaborate, feel free to reach out to me at [your.email@example.com].

## Project Website
Visit the [Project Website](https://your-username.github.io/3D-Printed-RC-Car) for more details.
