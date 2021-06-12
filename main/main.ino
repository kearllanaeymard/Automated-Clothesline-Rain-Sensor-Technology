// DC MOTOR
//IN3 DIGITALPIN 10
//IN4 DIGITALPIN 9
//ENB DIGITAL PIN 11

// FAN
//IN1 DIGITAL 5
//IN2 DIGITAL 6

// RAIN SENSOR DIGITAL 4
// UV LIGHT DIGITAL 3

int in1 = 5;
int in2 = 6;
int in3 = 10;
int in4 = 9;
int enb = 11;

int uv_light = 3;

int rain_sensor = analogRead(A0);

void labas()
{
 analogWrite(enb, 255);
 digitalWrite(in3, HIGH);
 digitalWrite(in4, LOW);

 delay(4100);

 digitalWrite(in3, LOW);
 digitalWrite(in4, LOW);
}

void pasok()
{
 analogWrite(enb, 255);
 digitalWrite(in3, LOW);
 digitalWrite(in4, HIGH);

 delay(4100);

 digitalWrite(in3, LOW);
 digitalWrite(in4, LOW);
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
  Serial.println("READY");

  fan_off();
  digitalWrite(uv_light, LOW);

delay(1000);

}

void loop() {

  rain_sensor = analogRead(A0);

  if(rain_sensor > 600) //Dry
  {
    Serial.println("DRY");
    fan_off();
    digitalWrite(uv_light, LOW);
  }
  
  else if(rain_sensor < 310) //Wet
  {
    Serial.println("WET (LABAS)");
    pasok();
    fan_on();
    digitalWrite(uv_light, HIGH);

    while(rain_sensor < 310)
    {
      rain_sensor = analogRead(A0);
      Serial.println("WET(LOOB)");
      fan_on();
      digitalWrite(uv_light, HIGH);
    
      if(rain_sensor > 600) //Dry
      {
        Serial.println("DRY(PALABAS)");
        fan_off();
        digitalWrite(uv_light, LOW);
        labas();
        break;
      }
    }  
  }
}
