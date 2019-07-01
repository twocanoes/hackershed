# hackershed
Sample Code for Hacker Shed focusing on Hardware Hacking for macOS Admins

Sample Projects:

* cli: implement a command line interface over serial for the Arudino
* flashled: Simple project to show how to flash the LED
* keyboardmouse: control the Mac keyboard / mouse
* launchdaemon: macOS LaunchDaemon to monitor the mac serial port and speak when a physical button is pressed.
* readbutton: read the state of an external button between GPIO 4 and ground and print state.

 
### Setup
*instructions for setting up IDE and installing needed library on macOS*

### Hardware
Adafruit ItsyBitsy 5v

### Dependencies###
Recommend installing Serial.app for easy connecting to command line interface of Arduino

### Running Projects###

###### CLI
The CLI project is a template for a command line interface over serial.  Supports the following commands:

1. help: shows usage
1. set_option <on|off>: turns an option on or off
1. flash: start flashing the LED


###### Flash LED
Simple project to just flash the LED. Kind of the "hello world" of hardware hacking.

###### keyboardmouse
Project to show control the keyboard or mouse. Comment / Uncomment the function calls in loop() to do the follow functions:

1. type_password(): type a hardcoded password 
1. show_about_menu(): Use keyboard navigation to go to the apple menu and show the about menu.
1. mouse_jump(): mouse the mouse a random amount every second. Annoying.

###### launchdaemon
Sample project to show how to use a launchdaemon to monitor the state of an external button. The launchdaemon starts up a ruby script (/usr/local/binserial_monitor.rb) that speaks the button state if it pressed. The button should be attached between ground and GPIO 4. Requires the readbutton firmware. To install:

1. Copy serial_monitor.rb to /usr/local/bin and makes sure it is executable (chmod 755 /usr/local/bin/serial_monitor.rb).
1. Copy serial_monitor.plist to /Library/LaunchDaemons
1. Flash readbutton firmware. 
1. Connect button / short pins 4 and GND. Mac should speak "down".

###### readbutton
Project to monitor pin 4. Outputs "down" when connected to ground. To setup:
1. Monitor serial port
1. Connect button / short pins 4 and GND.



