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

void Ultrasonic(uint32_t Distance) {
  MeasureDistance = sonar.ping_cm();
  String DistanceText = String(MeasureDistance) + " Cm";
 
  Serial.println(DistanceText);

  if (MeasureDistance < Distance && MeasureDistance > 0) {
    Stop();
    delay(500);
  } 
  else
    Forward(200);
    delay(100);
}
