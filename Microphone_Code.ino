const int sensorPin = A0; 
const int buttonPin = 7;
int buttonState = 0;
int sensorValue = 0;
int TU = 63;
int TD = 57;
bool state=true;
#include <SD.h>
#include <SPI.h>

int CS_PIN = 4;

File file;

void setup() {
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
  initializeSD();
  createFile("Values2.csv");
  pinMode(buttonPin, INPUT);
}

void loop() {
  sensorValue = analogRead(sensorPin);
//  Serial.println(sensorValue);
  if (sensorValue > TU || sensorValue < TD){
    if(sensorValue-60!=0){
    Serial.println(sensorValue-60);
    String value = String(sensorValue-60);
    char copy[50];
    value.toCharArray(copy,50);
    writeToFile(copy);
    }
  }
  else{
    Serial.println(0);
  }

 buttonState = digitalRead(buttonPin);
 if (buttonState == HIGH) {
  closeFile();
  Serial.write("Finished Storing Data");
  exit(0);
 }
}

void initializeSD()
{
  Serial.println("Initializing SD card...");
  pinMode(CS_PIN, OUTPUT);

  if (SD.begin())
  {
    Serial.println("SD card is ready to use.");
  } else
  {
    Serial.println("SD card initialization failed");
    return;
  }
}
int createFile(char filename[])
{
  file = SD.open(filename, FILE_WRITE);

  if (file)
  {
    Serial.println("File created successfully.");
    return 1;
  } else
  {
    Serial.println("Error while creating file.");
    return 0;
  }
}

int writeToFile(char text[])
{
  if (file)
  {
    file.println(text);
    Serial.println("Writing to file: ");
    Serial.println(text);
    return 1;
  } else
  {
    Serial.println("Couldn't write to file");
    return 0;
  }
}

void closeFile()
{
  if (file)
  {
    file.close();
    Serial.println("File closed");
  }
}
