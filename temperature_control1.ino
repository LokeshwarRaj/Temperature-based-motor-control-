#define temperatureSensor A0
#define DC_Motor 2

void setup() {
  
  pinMode(DC_Motor, OUTPUT);
  Serial.begin(9600);
}

void loop() 
{
  
  int value = analogRead(temperatureSensor);
  float volt = value * (5.0/ 1024.0);
  float temp = (volt - 0.5) * 100;
  Serial.print("Temperature = ");
  Serial.println(temp);
  delay(1000);
  if(temp>=25){
  	
    digitalWrite(DC_Motor , LOW);
    
  }
  else {
  
  	digitalWrite(DC_Motor , HIGH);
  }
  
}
