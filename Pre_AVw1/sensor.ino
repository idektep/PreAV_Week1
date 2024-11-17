#include <NewPing.h>

#define ULTRASONIC_ECHO_PIN 35
#define ULTRASONIC_TRIG_PIN 5
#define MAX_DISTANCE 50

NewPing sonar(ULTRASONIC_TRIG_PIN, ULTRASONIC_ECHO_PIN, MAX_DISTANCE);
/*-----------------------------------------------*/

void SensorSetup() {
  pinMode(ULTRASONIC_ECHO_PIN, INPUT);
  pinMode(ULTRASONIC_TRIG_PIN, OUTPUT);
}
/*-----------------------------------------------*/
void Ultrasonic() {
  MeasureDistance = sonar.ping_cm();
  String DistanceText = String(MeasureDistance) + " Cm";
  // DisplayLcd(5, "Distance", 5, DistanceText); // Display
  Serial.println(DistanceText);
}
/*------------------------------------------*/
void ForwardToWall(uint32_t Speed, uint32_t Distance) {
  Ultrasonic();
  if (MeasureDistance < Distance) {
    Stop();
  } 
  else
    Forward(200);
    delay(100);
}