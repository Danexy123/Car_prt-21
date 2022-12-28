#include<PS2X_lib.h>; 
PS2X ps2x; 
void setup() { 
  ps2x.config_gamepad(17, 15, 16, 14, false, false);            // Инициируем работу геймпада, проверяя указанные выводы для подключения (clock, command, attention, data, Pressures, Rumble) 
  pinMode(2, OUTPUT);  
  pinMode(3, OUTPUT);  
  pinMode(4, OUTPUT);  
  pinMode(5, OUTPUT); 
  pinMode(6, OUTPUT); 
  pinMode(7, OUTPUT); 
  pinMode(8, OUTPUT); 
  pinMode(9, OUTPUT); 
Serial.begin(9600); 
 
 
} 
struct stick 
{ 
  int x; 
  int y;
}

void getSpeedOfWheels(stick leftStick, stick rightStick) 
{ 
    int leftWheelUp = leftStick.y - leftStick.x + rightStick.x + rightStick.y; 
    int leftWheelDown = leftStick.y + leftStick.x + rightStick.y + rightStick.x; 
    int rightWheelUp = leftStick.x + leftStick.y + (rightStick.y - rightStick.x); 
    int rightWheelDown = leftStick.y - leftStick.x + (rightStick.y - rightStick.x); 
    map(leftWheelUp,0,1024,-255,255); 
    map(leftWheelDown,0,1024,-255,255); 
    map(rightWheelUp,0,1024,-255,255); 
    map(rightWheelDown,0,1024,-255,255); 
     
    if (leftWheelUp >= 0) 
    { 
      analogWrite(3,leftWheelUp); 
    } 
 
        if (leftWheelDown >= 0) 
    { 
      analogWrite(9,leftWheelDown); 
    } 
 
        if (rightWheelUp >= 0) 
    { 
      analogWrite(5,leftWheelDown); 
    } 
 
        if (rightWheelDown >= 0) 
    { 
      analogWrite(7,rightWheelDown); 
    } 
 
     if (leftWheelUp <= 0) 
    { 
      leftWheelUp = -leftWheelUp; 
      analogWrite(2,leftWheelUp); 
    } 
 
        if (leftWheelDown <= 0) 
    { 
      leftWheelDown= -leftWheelDown; 
      analogWrite(8,leftWheelDown); 
    } 
 
        if (rightWheelUp <= 0) 
    { 
      rightWheelUp = -rightWheelUp; 
      analogWrite(4,leftWheelDown); 
    } 
 
        if (rightWheelDown <= 0) 
    { 
      rightWheelDown = -rightWheelDown; 
      analogWrite(6,rightWheelDown); 
    } 
     Serial.print("LU"); 
    Serial.println(leftWheelUp); 
         Serial.print("LD"); 
 
    Serial.println(leftWheelDown); 
                 Serial.print("RU"); 
 
    Serial.println(rightWheelUp); 
             
     Serial.print("RD"); 
 
    Serial.println(rightWheelDown); 
 
} 
 }; 
 
void loop() { 
    ps2x.read_gamepad(); 
    stick leftStick, rightStick; 
    leftStick.x = ps2x.Analog(PSS_LX); 
    leftStick.y = ps2x.Analog(PSS_LY); 
    rightStick.x = ps2x.Analog(PSS_RX); 
    rightStick.y = ps2x.Analog(PSS_RY); 
   leftStick.getSpeedOfWheels(leftStick, rightStick); 
delay (50); 
}
