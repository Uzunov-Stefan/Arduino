
#define ArrayElementCount(x) (sizeof(x) / sizeof(x[0]))

const int TRIG_PIN   = 6; 
const int ECHO_PIN   = 7;
const int BUZZER_PIN = 3;
const int DISTANCE_THRESHOLD = 55;

float duration_us, distance_cm;

double notes[34] = { 
  220.00,246.94,261.63,293.66,329.63,349.23,392.00,440.00,493.88,523.25,587.33,659.25,698.46,783.99,880.00,987.77,1046.50, 1174.66, 1318.51,1396.91,1567.98,1760.00,1975.53,2093.00,2349.32,2637.02,2793.83,3135.96,3520.00,3951.07,4186.01,4698.63,5274.04,5587.65 };

void setup() {
  Serial.begin (9600);         
  pinMode(TRIG_PIN, OUTPUT);   
  pinMode(ECHO_PIN, INPUT);    
  pinMode(BUZZER_PIN, OUTPUT); 
}

void loop() {
  
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration_us = pulseIn(ECHO_PIN, HIGH);
  distance_cm = 0.017 * duration_us;
  int idx = nearest(distance_cm*100, notes, ArrayElementCount(notes));

//  Serial.print("distance*100: ");
//  Serial.print(distance_cm*100);
  
  if(distance_cm < DISTANCE_THRESHOLD){
    //digitalWrite(BUZZER_PIN, HIGH);
    //int sound = notes[idx];
      tone(BUZZER_PIN, notes[idx], 500);
    }
  if(distance_cm >= DISTANCE_THRESHOLD){
    digitalWrite(BUZZER_PIN, LOW);  
  }
  Serial.print("distance: ");
  Serial.print(distance_cm);
  Serial.println(" cm");

  delay(500);
}

int nearest(int x, double myArray[], int elements)
{
  int idx = 0;

  int distance = abs(myArray[idx] - x);
  for (int i = 1; i < elements; i++)
  {
    int d = abs(myArray[i] - x);
    if (d < distance)
    {
      idx = i;
      distance = d;
    }
  }
  return idx;
}
