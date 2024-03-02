const int entranceSensorPin = 2;  
const int exitSensorPin = 3;      
const int relayPin = 4;           

int peopleCount = 0;

void setup() {
  pinMode(entranceSensorPin, INPUT);
  pinMode(exitSensorPin, INPUT);
  pinMode(relayPin, OUTPUT);

  digitalWrite(relayPin, LOW);

  Serial.begin(9600);
}

void loop() {
  int entranceSensorStatus = digitalRead(entranceSensorPin);
  int exitSensorStatus = digitalRead(exitSensorPin);


  if (entranceSensorStatus == LOW) {
    peopleCount++;
  }

  if (exitSensorStatus == LOW) {
    peopleCount--;
  }

  peopleCount = max(0, peopleCount);

  controlLights();

  Serial.print("People Count: ");
  Serial.println(peopleCount);

  delay(500);  
}

void controlLights() {
  if (peopleCount > 0) {
    digitalWrite(relayPin, HIGH);
  } else {
    digitalWrite(relayPin, LOW);
  }
}
