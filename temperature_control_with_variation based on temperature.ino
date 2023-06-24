#define temperatureSensor A0
#define DC_Motor 9
int minTemp = -41;
int maxTemp = 125;
int minSpeed= 0;
int maxSpeed= 5500;
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
  delay(2000);
  duty = map(temp, minTemp, maxTemp, minSpeed, maxSpeed);
  duty = map ( temp,-40,125,255 ,0);
  
  // this set of code is for when u want the motor to inc speed 
  // if the temp remains constant 
 /* int temp_old =0;
  int temp_n = temp;
  duty = duty+2*(temp_n-temp_old);
  temp_old= temp;*/
  Serial.println(duty); 	
  analogWrite(DC_Motor , duty);

}
