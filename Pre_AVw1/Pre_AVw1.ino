#define LOW_SPEED 125
#define MAX_SPEED 255

long MeasureDistance = 0;

/*-----------------------------------------------*/
void setup() {

  Serial.begin(9600);
  SensorSetup();
  MotorDriveSetup();
  delay(1000);


   Forward(200);
   delay(900);
   RotateLeft(200);
   delay(450);








   Stop();

}
/*-----------------------------------------------*/
void loop() {
   

}

