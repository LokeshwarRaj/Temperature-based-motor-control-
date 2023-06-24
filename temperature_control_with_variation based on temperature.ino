#define temperatureSensor A0
#define DC_Motor 9
int minTemp = -41;
int maxTemp = 125;
int minSpeed= 100;
int maxSpeed= 3000;
float duty;

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
  duty = map(temp, minTemp, maxTemp, minSpeed, maxSpeed);
  if(temp>=25){
  	
   analogWrite(DC_Motor , duty);
    
  }
  else {
  
  	analogWrite(DC_Motor , duty);
  }
}
