void setup() {
  pinMode(4, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  // read the state of the pushbutton value:
  int buttonState = digitalRead(4);
  if (buttonState==1) {
    Serial.println("up");
  }
  else Serial.println("down");
  delay(1000);

}
