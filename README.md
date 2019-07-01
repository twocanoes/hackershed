# hackershed
Sample code for Hacker Shed focusing on hardware hacking for macOS admins

### Included Projects

* **cli**: implement a command line interface over serial for the Arudino
* **flashled**: Simple project to show how to flash the LED
* **keyboardmouse**: control the Mac keyboard / mouse
* **launchdaemon**: macOS LaunchDaemon to monitor the mac serial port and speak when a physical button is pressed.
* **readbutton**: read the state of an external button between GPIO 4 and ground and print state.

 
### Setup
Start by downloading and installing the Arduino IDE app for your platform from the [Arduino software page](https://www.arduino.cc/en/Main/Software). Launch the Arduino app and open Preferences from the menu. Find the box near the bottom for “Additional Boards Manager URLs” and enter this text:

    https://adafruit.github.io/arduino-board-index/package_adafruit_index.json

Close Preferences, then go to the Tools menu and find `Board > Boards Manager…`. From the `Type` list, select `Contributed`. Look in the list for `Adafruit AVR Boards` and click the Install button.

Next quit and relaunch Arduino IDE to confirm new boards are installed. Once relaunched, go back to the Tools menu and under `Board` find the Adafruit boards shown near the bottom and select `Adafruit ItsyBitsy 32u4 5V 16MHz`.

Next go to the Sketch menu and under `Include Library` open `Manage Libraries…`. Search for `HID-Project`, then find the entry shown for `HID-Project by NicoHood` and click Install. Then search for `ArduinoJSON`. Change the version selection for this library to version `5.13.5` and click Install.

Next from the hackershed repository find the file  called `cli.ino` in the `cli` folder and open this in the Arduino app. Click the `Verify` button near the top left corner of the Arduino app to confirm all configuration is complete. If any warnings or errors are shown, review the section above to confirm that the correct versions of required libraries were installed correctly.

Next plug in the ItsyBitsy and quickly double-tap the programming button, then go to the Tools menu and hover over `Port`. Select the new entry shown there for the ItsyBitsy (should have “ItsyBitsy” in port name shown).  If this is not shown, disconnect and reconnect the ItsyBitsy and try this again.  This may take several tries to complete.  

Once all this is configured, upload the code to the ItsyBitsy by plugging it in again, then clicking the Upload button (near the Verify button). A message will be shown in the lower left corner of the Arduino app saying `Compiling sketch…`, then `Uploading…`, then `Done uploading`. 

### Hardware
Adafruit ItsyBitsy 5v

### Dependencies
Recommend installing [Serial.app](https://www.decisivetactics.com/products/serial/) for easy connecting to command line interface of Arduino.  After installing and launching Serial, plug in the ItsyBitsy and select it from the `Open Port` dialog box.  Then from the Terminal menu, select `Settings`.  Then in the `Terminal Settings` section, change the choice for `Return Key` to `CR+LF`.  Then lower down in this section, click the checkbox for `Echo Typed Characters`.  Click OK to close this dialog box.  Make sure to close Serial whenever uploading new code from the Arduino IDE to the ItsyBitsy.  

### Projects

#### CLI
The CLI project is a template for a command line interface over serial.  Supports the following commands:

1. help: shows usage
1. set_option `on|off`: turns an option on or off
1. flash: start flashing the LED


#### Flash LED
Simple project to just flash the LED. Kind of the "hello world" of hardware hacking.

#### keyboardmouse
Project to show control of the keyboard or mouse. Comment / Uncomment the function calls in loop() to do the follow functions:

1. `type_password()`: Type a hardcoded password 
1. `show_about_menu()`: Use keyboard navigation to go to the Apple menu and show the About menu.
1. `mouse_jump()`: Move the mouse a random amount every second. Annoying.

#### launchdaemon
Sample project to show how to use a launchdaemon to monitor the state of an external button. The launchdaemon starts up a ruby script (`/usr/local/bin/serial_monitor.rb`) that speaks the button state if it is pressed. The button should be attached between ground and GPIO 4. Requires the readbutton firmware. To install:

1. Copy serial_monitor.rb to /usr/local/bin and makes sure it is executable (`chmod 755 /usr/local/bin/serial_monitor.rb`).
1. Open Terminal and run this command: `sudo gem install rubyserial`.
1. Copy serial_monitor.plist to `/Library/LaunchDaemons`
1. Flash readbutton firmware. 
1. Connect button / short pins 4 and GND. Mac should speak "down".

#### readbutton
Project to monitor pin 4. Outputs "down" when connected to ground. To setup:
1. Monitor serial port
1. Connect button / short pins 4 and GND.
