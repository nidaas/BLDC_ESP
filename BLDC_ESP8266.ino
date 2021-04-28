/* Sweep
  by BARRAGAN <http://barraganstudio.com>
  This example code is in the public domain.

  modified 28 May 2015
  by Michael C. Miller
  modified 8 Nov 2013
  by Scott Fitzgerald

  http://arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards


void setup() {
  Serial.begin(115200);
  myservo.attach(2);  // attaches the servo on GIO2 to the servo object
  myservo.write(0);

}

void loop() {
  if(Serial.available()){
    String st="";
    while(Serial.available()){
      while(Serial.available())
        st+=(char)Serial.read();
      delay(10);
    }
    uint8_t stVal=st.toInt();
    Serial.println("Servo val:"+String(stVal));
    myservo.write(stVal);
  }
}
