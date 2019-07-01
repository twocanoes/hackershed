void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
}

void showusage() {
  
  Serial.println(F("help: this message"));


}
void flash_led(){
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);              // wait for a second
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);              // wait for a second
}
void enter_cli() {
  
  Serial.begin(9600);
  Serial.println(F("Command Line Mode. Enter help for assistance."));
 
    Serial.setTimeout(1000000);
    Serial.print(">");
    String s = Serial.readStringUntil('\n');
    s.trim();
    Serial.println(s);

    if (s.startsWith("flash") == true) {
      flash_led();
    }
    else if (s.startsWith(F("help")) == true) {
      showusage();
    }

    else if (s.startsWith(F("set_option")) == true) {
        char *line = (char *)s.c_str();
        char *ptr = NULL;
        byte index = 0;
        char *tokens[2];
        ptr = strtok(line, " ");  // takes a list of delimiters
        while (ptr != NULL && index < 2) {
          tokens[index] = ptr;
          index++;
          ptr = strtok(NULL, " ");  // takes a list of delimiters
        }
        if (index != 2) {
        
          Serial.println(F("Invalid commmand. Please provide on or off for the set_autorun command"));
        }
        else {
          if (strncmp(tokens[1], "on", 3) == 0) {
    

            Serial.println(F("turned on"));
            
          }
          else if (strncmp(tokens[1], "off", 3) == 0) {
            Serial.println(F("turned off"));
          }
          else {
            Serial.println(F("Invalid value. Please specify on or off"));
          }
        }
    }
    else {
      Serial.println(F("Invalid command. Enter help for usage."));
      Serial.println(s);

    }
  }


void loop() {

  enter_cli();

}
