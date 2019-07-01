
#define PASSWORD "3DCE27D7-2544-4206-8CE0-5E6D1B5787B8"
#include <HID-Project.h>
#include <HID-Settings.h>


void setup(){


}
void presskey(KeyboardKeycode key, int times, int delayms) {

  for (int i = 0; i < times; i++) {
    BootKeyboard.press(key);
    delay(delayms);
    BootKeyboard.releaseAll();
    delay(100);

  }
}


void type_password() {
  delay(1500);
  Keyboard.begin();
  Keyboard.print(PASSWORD); 
  Keyboard.end();
  while(1);
}


void show_about_menu() {
  delay(1500);
   BootKeyboard.begin();
  BootKeyboard.press(KEY_LEFT_CTRL);
  BootKeyboard.press(KEY_F2);
  BootKeyboard.releaseAll();
  presskey(KEY_DOWN_ARROW,2 , 50);
  BootKeyboard.println();
  BootKeyboard.end();
  while(1);
}

void mouse_jump(){

  Mouse.begin();
  Mouse.move(50-random(0,1000),50-random(0,1000));
  Mouse.end();

  delay(1000);


}
void loop() {

//type_password();
//show_about_menu();
mouse_jump();


}
