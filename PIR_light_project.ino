int in1 = 9;
int sensor = 2;
int led = 13;
unsigned long t=0;

void setup() 
{
  Serial.begin(9600);
  pinMode(in1, OUTPUT);
  pinMode(sensor, INPUT);
  pinMode(led, OUTPUT);
  
  digitalWrite(in1,HIGH);
  digitalWrite(led,LOW);

  while(millis()<13000)
  {
    digitalWrite(led,HIGH);
    delay(50);
    digitalWrite(led,LOW);
    delay(50);
  }
  digitalWrite(led,LOW);
 Serial.println("LABEL, Date, Time, Motion State");
}


void loop() 
{
  Serial.print("DATA, DATE, TIME,");
  digitalWrite(in1,LOW);
  digitalWrite(led,HIGH);
  if(digitalRead(sensor)==HIGH)  
  {
   t=millis();
   Serial.print("Motion detected");

   while(millis()<(t+5000))
   {
   digitalWrite(in1,HIGH);
   digitalWrite(led,LOW);
     if((millis()>(t+2300))&&(digitalRead(sensor)==HIGH))
      {
       t=millis();
      }
      
   }
  }
  else
  {
    Serial.print("Motion ended");
  }
}
