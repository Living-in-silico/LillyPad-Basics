const int sensorPin = A1; 
int sensorValue = 0;
int TU = 60;
int TD = 57;

void setup() {
  Serial.begin(9600);
  pinMode(sensorPin, INPUT); 
}

void loop() {
  sensorValue = analogRead(sensorPin);
//  Serial.println(sensorValue);
  if (sensorValue > TU || sensorValue < TD){
  Serial.println(sensorValue-59);
  }
  else{
    Serial.println(0);
  }
  delay(2);
}
