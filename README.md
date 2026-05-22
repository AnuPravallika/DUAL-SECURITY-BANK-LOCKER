# DUAL SECURITY BANK LOCKER

-------------------------------------
# Project Overview

The Dual Bank Locking System is an embedded systems security project designed to provide secure access to a bank locker using fingerprint authentication and password verification. The system enhances locker security by allowing access only to authorized users.

This project is developed using Embedded C and implemented on a microcontroller platform with peripherals such as LCD, keypad, UART communication, EEPROM, and fingerprint sensor.

-------------------------------------

# Features

* Fingerprint-based authentication
* Password protection using keypad
* LCD display for user interaction
* EEPROM data storage support
* UART communication support
* Secure locker access mechanism
* Embedded C based implementation
* Modular driver-based programming structure

-------------------------------------

# Technologies Used

* Embedded C
* Keil uVision IDE
* ARM/LPC Microcontroller
* UART Communication
* SPI Communication
* EEPROM Interface
* Fingerprint Sensor (R305)
* LCD Display
* Keypad Module

-------------------------------------

# Project Structure

BANK LOCKER SECURITY SYSTEM USING FINGERPRINT SENSOR/

 projectmain.c          # Main application logic
 R305.c / R305.h        # Fingerprint sensor driver
 lcd.c / lcd.h          # LCD driver files
 uart0.c / uart0.h      # UART communication
 spi_eeprom.c           # EEPROM interface
 kpm2.c                 # Keypad handling
 ext_int.c              # External interrupt handling
 timer.c                # Timer functions
 func.c                 # Utility functions
 Startup.s              # Startup assembly file
 banklocker_security.uvproj

-------------------------------------

# Hardware Requirements

* LPC2148 / ARM7 Microcontroller
* R305 Fingerprint Sensor
* LCD Display (16x2)
* Matrix Keypad
* EEPROM Module
* Power Supply
* Connecting Wires
* Embedded Development Board

-------------------------------------

# Software Requirements

* Keil uVision IDE
* Flash Magic (for programming)
* Embedded C Compiler

-------------------------------------

# Working Principle

1. The system initializes all peripherals.
2. User places a finger on the fingerprint sensor.
3. The fingerprint is verified with stored templates.
4. If fingerprint authentication is successful, the user enters the password using the keypad.
5. Upon successful verification, the locker unlocking mechanism is activated.
6. LCD displays the authentication and access status.

-------------------------------------

# How to Run the Project

1. Open the project in Keil uVision.
2. Build the project.
3. Connect the microcontroller development board.
4. Flash the generated HEX file into the controller.
5. Connect all peripherals properly.
6. Power ON the system.
7. Test fingerprint and password authentication.

-------------------------------------

# Applications

* Bank Locker Security Systems
* Home Security Systems
* Office Access Control
* Smart Authentication Systems

-------------------------------------

# Future Enhancements

* GSM alert integration
* IoT-based remote monitoring
* Mobile application control
* Face recognition integration
* Cloud database support

-------------------------------------

# Author

Developed as an Embedded Systems Security Project using Embedded C and ARM Microcontroller.

-------------------------------------

# License

This project is intended for educational and learning purposes.


