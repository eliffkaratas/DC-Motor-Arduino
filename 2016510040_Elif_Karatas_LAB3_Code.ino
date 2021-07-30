#define in2 10
#define in1 8
#define sp 9
#define pot A0
#define button 2

int direction = 0; // for rotate state
int count1 = 0, count2 = 0; // for delays and loops
int pressed = false; // for button controls

void setup()
{ 
  pinMode(sp, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(button, INPUT);
  Serial.begin(9600);
}

void loop()
{
  int potValue = analogRead(A0); // read potentiometer value
  int pwmOutput = map(potValue, 0, 1023, 0 , 255); // potentiometer value from 0 to 255
  analogWrite(sp, pwmOutput); // send signal to pin

  // if button is pressed
  if (digitalRead(button) == true) {
        pressed = !pressed;
  }
  
  // if button is pressed - change rotation direction
  if (pressed == true) {
    // if direction rotate is 0
    if(direction == 0){
      // rotate to 1
      direction = 1;
      Serial.println("a");
      // call d0 void for rotating
      d0();
    }
    // if direction rotate is 1
    else{
      direction = 0;
      // rotate to 0
      Serial.println("b");
      // call d1 void for rotating
      d1();
    } 
  }
  // reset counters for 3seconds delay and loop
  count1 = 0;
  count2 = 0;

  // if button is pressed - change rotation direction
  if (pressed == false) {
    // if direction rotate is 0
    if(direction == 0){
      // rotate to 1
      direction = 1;
      Serial.println("c");
      // call d0 void for rotating
      d0();
    }
    // if direction rotate is 1
    else{
      direction = 0;
      // rotate to 0
      Serial.println("d");
      // call d1 void for rotating
      d1();
    }
  }
  // reset counters for 3seconds delay and loop
  count1 = 0;
  count2 = 0;
  
}

// rotate clockwise
void d0(){
  while(count2<=300){
            digitalWrite(in1, HIGH);
            digitalWrite(in2, LOW);
            count2++;
    		delay(10);
  }
}

// rotate reverse-clockwise
void d1(){
  while(count1<=300){
            digitalWrite(in1, LOW);
            digitalWrite(in2, HIGH);
            count1++;
    		delay(10);
  }
}
