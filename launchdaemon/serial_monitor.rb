#!/usr/bin/env ruby
require "rubyserial"

port_str = Dir["/dev/cu.usbmodem*"].first
raise StandardError, 'Device not connected' if port_str.nil?

sp = Serial.new port_str, 9600

loop do
  sleep(0.25);
  a = sp.read(255)
  system("say down") if (a.chomp == "down")
end
