# Magic Button

ESP8266 Twilio Voice Caller
Welcome to the ESP8266 Twilio Voice Caller project! This repository contains all the necessary code and documentation to create a system that uses the ESP8266 to make voice calls via Twilio's API. This project was inspired by the need to assist an elderly relative who frequently misplaces their phone. With just a simple press of a button, their phone will ring, making it easy to locate. This solution can also be adapted for various other applications like emergency alerts or smart home integrations.

Features
Simple Button Trigger: Make calls by pressing a physical button connected to the ESP8266.
Status Indicator: An LED lights up during the call process to indicate that the call is being made.
Twilio API Integration: Uses Twilio's robust API for reliable communication.
WiFi Connectivity: Connects to the internet via WiFi to send call requests.
Prerequisites
To get started with this project, you will need:

An ESP8266 module.
A breadboard and jumper wires.
A button and LED for input and feedback.
Basic electronic components like resistors for the button and LED.
A Twilio account with a registered phone number.
Arduino IDE for programming the ESP8266.
Hardware Setup
Button: Connect one side to GPIO D1 and the other side to ground through a pull-down resistor.
LED: Connect the anode (longer leg) to GPIO D4 and the cathode (shorter leg) to ground through a resistor.
Software Setup
Install Libraries: Install the WiFiClientSecure and base64 libraries via the Arduino Library Manager.
Arduino Configuration: Load the provided Arduino sketch into the IDE. Replace the placeholders in the code with your WiFi credentials and Twilio API details.
Upload the Sketch: Connect your ESP8266 via USB, select the appropriate board and port in the Arduino IDE, and upload the sketch.
Usage
Once everything is set up:

Power the ESP8266 module.
Press the button to initiate a voice call through Twilio.
Observe the LED for call status.
Customization
You can customize the project by:

Changing the phone numbers in the sketch to match your Twilio account details and the desired recipient.
Modifying the call message or integrating with other systems like a home automation platform.
Contributing
Contributions are what make the open-source community such an amazing place to learn, inspire, and create. Any contributions you make are greatly appreciated.

Fork the Project
Create your Feature Branch (git checkout -b feature/AmazingFeature)
Commit your Changes (git commit -m 'Add some AmazingFeature')
Push to the Branch (git push origin feature/AmazingFeature)
Open a Pull Request
License
Distributed under the MIT License. See LICENSE for more information.

Acknowledgements
Twilio API: For providing the communication infrastructure.
Arduino Community: For continuously supporting and providing valuable resources.
 
