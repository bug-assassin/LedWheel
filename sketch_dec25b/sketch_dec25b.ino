struct Coordonates
{
  float x;
  float y;
};

Coordinate coordinate;

Coordinate origin = new Coordinate(38, 38);

float currentAngle = 0;

unsigned long startTimeOfRotation = 0;

#define RPS = 3;
#define TIMEONEROTATION = 1000 / RPS;


void setup() {
startTimeOfRotation = millis();
}

void loop() {
  // put your main code here, to run repeatedly:

}

float updateCurrentAngle() {
  long timeElapsed = millis() - startTimeOfRotation;
  if(timeElapsed >= TIMEONEROTATION)
  {
    timeElapsed = 0;
    startTimeOfRotation = millis();
  }
  
  return 2 * PI * (timeElapsed / TIMEONEROTATION);
}

Coordinate getXY(Coordinate origin, float radius, float angle) {
  Coordinate xy;
  
    xy.x = origin.x + r * cos(angle)
    xy.y = origin.y + r * sin(angle)
  return xy;
}
