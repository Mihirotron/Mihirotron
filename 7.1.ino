 

int enA = 9;            // Speed control pin for Motor A

/* 
   control pins for Motor A
*/
int in1 = 8;           
int in2 = 7;
int enB = 3;           // Speed control pin for Motor B
/*
 *   control pins for Motor B
 */
int in3 = 5;           
int in4 = 4;

// input from bluetooth in user_choice variable 
char user_choice;

void setup() {
  // themotor control pins are set as output
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
 
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

  Serial.begin(9600);
}

void loop() 
{
    if(Serial.available() > 0)
    {
      user_choice = Serial.read();
      switch(user_choice)
      {
        /* When keys are pressed in the Bluetooth control app the letters are actual data are stored in user_choice variable using Serial.read() function,
         *  These letters are used as for rover movement
         */

        // Letter 'F' is for forward movement 
        case 'F':
          analogWrite(enA, 255);
          analogWrite(enB, 255);
          digitalWrite(in1, HIGH);
          digitalWrite(in2, LOW);
          digitalWrite(in3, HIGH);
          digitalWrite(in4, LOW);
   
          break;

          //Letter 'B' is for backward movement
        case 'B':
            analogWrite(enA, 255);
            analogWrite(enB, 255);
            digitalWrite(in1, LOW);
            digitalWrite(in2, HIGH);
            digitalWrite(in3, LOW);
            digitalWrite(in4,HIGH);
          
            break;

         // Letter 'L' is for left movement
        case 'L':
          analogWrite(enA, 255);
          analogWrite(enB, 255);
          digitalWrite(in1, HIGH);
          digitalWrite(in2, LOW);
          digitalWrite(in3, LOW);
          digitalWrite(in4, LOW);
  
          break;

          //Letter 'R' is for right movement
        case 'R':
          analogWrite(enA, 255);
          analogWrite(enB, 255);
          digitalWrite(in1, LOW);
          digitalWrite(in2, LOW);
          digitalWrite(in3, HIGH);
          digitalWrite(in4, LOW);
 
          break;

          //For all other inputs, stop the rover
        default:
          digitalWrite(in1, LOW);
          digitalWrite(in2, LOW);
          digitalWrite(in3, LOW);
          digitalWrite(in4, LOW);

          break;
      }
    }
}
