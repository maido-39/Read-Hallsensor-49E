void setup() {
  Serial.begin(115200);
}
int average = 0;
int sensorValue = 0;
int bias = 519; // initial value for making 0 base

float alpha = 0.2; // Low pass filter's alpha 
void loop() {
  unsigned long startTime = millis();
  unsigned long currentTime = millis();
  while(currentTime - startTime < 2) {
    // read the sensor value
    sensorValue = analogRead(A0) - bias ;

    average = alpha * average + (1 - alpha) * sensorValue; 
    
    // send the sensor value to Serial Plotter
    Serial.println(String(sensorValue)+" "+String(average)+" 0");

    // update current time
    currentTime = millis();
  }
  
}
