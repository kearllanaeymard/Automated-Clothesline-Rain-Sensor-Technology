// DC MOTOR
//IN3 DIGITALPIN 10
//IN4 DIGITALPIN 9
//ENB DIGITAL PIN 11

// FAN
//IN1 DIGITAL 5
//IN2 DIGITAL 6

// RAIN SENSOR ANALOG 0
// UV LIGHT DIGITAL 3

int in1 = 5;
int in2 = 6;
int in3 = 10;
int in4 = 9;
int enb = 11;

int uv_light = 3;

int rain_sensor = analogRead(A0);

void clockwise(char a)
{
 analogWrite(enb, a);
 digitalWrite(in3, HIGH);
 digitalWrite(in4, LOW); 
}

void counter_clockwise(char a)
{
 analogWrite(enb, a);
 digitalWrite(in3, LOW);
 digitalWrite(in4, HIGH); 
}

void fan_on()
{
 digitalWrite(in1, HIGH);
 digitalWrite(in2, LOW); 
}

void fan_off()
{
 digitalWrite(in1, LOW);
 digitalWrite(in2, LOW); 
}

 
void setup() {
  // put your setup code here, to run once:
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enb, OUTPUT);
  pinMode(rain_sensor, INPUT);
  pinMode(uv_light, OUTPUT);
  Serial.begin(9600);

  fan_off();
  digitalWrite(uv_light, LOW);

}

void loop() {
  // put your main code here, to run repeatedly:
//
//  int rain_sensor = analogRead(A0);
//
//  if(rain_sensor > 600) //Dry
//  {
//    Serial.println(rain_sensor);
//    clockwise(255);
//  }
//  if(rain_sensor < 300) //Wet
//  {
//    Serial.println(rain_sensor);
//    counter_clockwise(255);
//  }

//digitalWrite(uv_light, HIGH);
//delay(3000);
//digitalWrite(uv_light, LOW);
//delay(3000);



fan_on();
//digitalWrite(uv_light, HIGH);
delay(5000);

fan_off();
//digitalWrite(uv_light, LOW);
delay(3000);


}
