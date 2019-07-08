# hackershed
Sample code for Hacker Shed focusing on hardware hacking for macOS admins

### Included Projects

* **flashled**: Simple project to show how to flash the LED
* **keyboardmouse**: control the Mac keyboard / mouse
* **cli**: implement a command line interface over serial for the Arudino
* **readbutton**: read the state of an external button between GPIO 4 and ground and print state
* **launchdaemon**: macOS LaunchDaemon to monitor the mac serial port and speak when a physical button is pressed
 
### Setup
Start by downloading this repository using the `Clone or download` button above.  

Next install the Arduino IDE app for your platform from the [Arduino software page](https://www.arduino.cc/en/Main/Software). 

Launch the Arduino app and open Preferences from the menu. Find the box near the bottom for “Additional Boards Manager URLs” and enter this text:

    https://adafruit.github.io/arduino-board-index/package_adafruit_index.json

Close Preferences, then go to the Tools menu and find `Board > Boards Manager…`. From the `Type` list, select `Contributed`. Look in the list for `Adafruit AVR Boards` and click the Install button.

Next quit and relaunch Arduino IDE to confirm new boards are installed. Once relaunched, go back to the Tools menu and under `Board` find the Adafruit boards shown near the bottom and select `Adafruit ItsyBitsy 32u4 5V 16MHz`.

Next go to the Sketch menu and under `Include Library` open `Manage Libraries…`. Search for `HID-Project`, then find the entry shown for `HID-Project by NicoHood` and click Install. Then search for `ArduinoJSON`. Change the version selection for this library to version `5.13.5` and click Install.

Next from the hackershed repository find the file  called `flashled.ino` in the `flashled` folder and open this in the Arduino app. Click the `Verify` button near the top left corner of the Arduino app to confirm all configuration is complete. If any warnings or errors are shown, review the section above to confirm that the correct versions of required libraries were installed correctly.

Next plug in the ItsyBitsy and go to the Tools menu.  Hover over `Port`. Select the new entry shown there for the ItsyBitsy (should have `/dev/cu.usbmodem` in port name shown).  If this is not shown at first, close the Tools menu and wait a moment, then reopen it and move the cursor back to the Port section.  

Once all this is configured, upload the code to the ItsyBitsy by clicking the Upload button (near the Verify button). A message will be shown in the lower left corner of the Arduino app saying `Compiling sketch…`, then `Uploading…`, then `Done uploading`. 

### Hardware
Adafruit ItsyBitsy 5v


### Dependencies
Recommend installing [Serial.app](https://www.decisivetactics.com/products/serial/) for easy connecting to command line interface of Arduino.  After installing and launching Serial, plug in the ItsyBitsy and select it from the `Open Port` dialog box.  Then from the Terminal menu, select `Settings`.  Then in the `Terminal Settings` section, change the choice for `Return Key` to `CR+LF`.  Then lower down in this section, click the checkbox for `Echo Typed Characters`.  Click OK to close this dialog box.  Make sure to close Serial whenever uploading new code from the Arduino IDE to the ItsyBitsy.  

### Projects

#### Flash LED
Simple project to just flash the LED. Kind of the "hello world" of hardware hacking.

Upload the `flashled.ino` file to the Arduino.  Try changing the values for the `delay()` command to alter how fast the LED flashes.  Next try duplicating some of the lines to make a more complex flashing pattern, such as SOS (three short flashes, then three longer flashes, then three short flashes).  

#### keyboardmouse
Project to show control of the keyboard or mouse. 

1. `mouse_jump()`: Move the mouse a random amount every second. Annoying.
1. `type_password()`: Type a hardcoded password 
1. `show_about_menu()`: Use keyboard navigation to go to the Apple menu and show the About menu.

Upload the `keyboardmouse.ino` file to the Arduino and look at the code.  Scroll to the bottom and comment/uncomment the function calls in loop() to change which function is run.

When trying the `mouse_jump` function, try making a change to the `Mouse.move` command and seeing how it changes how it makes the mouse move.  

When done trying the `mouse_jump` function it may be best to unplug the Arduino to prevent it moving the mouse when no longer desired.  

When trying the `type_password` function, immediately after uploading the code to the Arduino, make sure to open TextEdit so the password can be written somewhere.  If the password gets accidentally written to the code in Arduino IDE, go to the Edit menu and click Undo.  

To change the value for `password` scroll to the top of the script and find the line where this is defined.

#### CLI
The CLI project is a template for a command line interface over serial.  Supports the following commands:

1. `help`: shows usage
1. `set_option` `on|off`: turns an option on or off
1. `flash`: start flashing the LED

Upload the `cli.ino` file to the Arduino.  Then open the Serial app (confirm that Serial configuration shown above is complete).  Try typing one of the commands into the Serial window and see how the Arduino responds.  Note that if a command is misspelled into Serial it cannot be corrected with the Delete key.  Instead just type Enter, ignore the response, and then try again.  

Try changing the code for the `help` command to change the message that the Arduino responds with when `help` is entered in Serial.  

#### readbutton
Project to monitor pin 4. Prints "up" when pin is free or "down" when connected to ground. To setup:

1. Upload readbutton.ino to Arduino.
1. Open Serial.
1. Connect button or short pins 4 and GND.

Note: Pins 4 and GND are on the side of the ItsyBitsy opposite the usb connector and are marked as `4` and `G` respectively.

![Itsybitsy](http://tc-downloads.s3.amazonaws.com/itsybitsy.jpg)

Every second the Serial window should type out the current state of the button as "up" or "down".  

#### launchdaemon
Sample project to show how to use a launchdaemon to monitor the state of an external button. The launchdaemon starts up a ruby script (`/usr/local/bin/serial_monitor.rb`) that speaks when the button is pressed. The button should be attached between ground and GPIO 4. Requires the readbutton firmware. To install:

1. Upload readbutton firmware to Arduino. 
1. Copy serial_monitor.rb to `/usr/local/bin`
1. Copy serial_monitor.plist to `/Library/LaunchDaemons`
1. Close the Serial app if it is currently running.

Note: To navigate to hidden folders in Finder, type `command-shift-g` and then enter the desired folder path.  

If you cannot find `/usr/local/bin`, go to `/usr/local` and create a folder called `bin`, then copy `serial_monitor.rb` to this new `bin` folder.

Install Xcode command line tools (if not currently installed) by opening Terminal and running this command:

    sudo xcode-select --install

Then run these commands in Terminal as well: 

    chmod 755 /usr/local/bin/serial_monitor.rb
    sudo gem install rubyserial
    cd /Library/LaunchDaemons/
    sudo chown root serial_monitor.plist
    sudo launchctl load serial_monitor.plist 
    sudo launchctl start serial_monitor

Press button or short pins 4 and GND. Mac should speak "down".

If desired, try changing the code in serial_monitor.rb.  Try changing the argument for the `system()` function.  This can take any shell script such as 

    system ("echo `Date` > ~/Downloads/date.txt")

This line will write the current date and time to a text file called `date.txt` in the Downloads folder.  Make sure to save this in `/usr/local/bin/serial_monitor.rb`

When done, you can remove the launchdaemon by running these commands in Terminal: 

    cd /Library/LaunchDaemons/
    sudo launchctl stop serial_monitor
    sudo launchctl unload serial_monitor.plist 
    sudo rm serial_monitor.plist
    rm /usr/local/bin/serial_monitor.rb

