#!/usr/bin/env ruby
require "rubyserial"


port_str = "/dev/cu.usbmodem144101"

sp=Serial.new port_str,9600

while (1) do
    sleep(0.25);
 a=sp.read(255)
 system("say down") if (a.chomp=="down")
end
