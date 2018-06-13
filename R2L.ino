int delaylegnth = 10;
const int buttonPin = 6;
int buttonState = 0;
int armState = 0;


void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT_PULLUP);
  
  //establish motor direction toggle pins
  pinMode(12, OUTPUT); //CH A -- HIGH = forwards and LOW = backwards???
  pinMode(13, OUTPUT); //CH B -- HIGH = forwards and LOW = backwards???
  
  //establish motor brake pins
  pinMode(9, OUTPUT); //brake (disable) CH A
  pinMode(8, OUTPUT); //brake (disable) CH B
  
}

void clockwise(int times) {
  int count = 0;
  while(count < times) {
    digitalWrite(9, LOW);  //ENABLE CH A
    digitalWrite(8, HIGH); //DISABLE CH B
  
    digitalWrite(12, HIGH);   //Sets direction of CH A
    analogWrite(3, 255);   //Moves CH A
    
    delay(delaylegnth);
    
    digitalWrite(9, HIGH);  //DISABLE CH A
    digitalWrite(8, LOW); //ENABLE CH B
  
    digitalWrite(13, LOW);   //Sets direction of CH B
    analogWrite(11, 255);   //Moves CH B
    
    delay(delaylegnth);
    
    digitalWrite(9, LOW);  //ENABLE CH A
    digitalWrite(8, HIGH); //DISABLE CH B
  
    digitalWrite(12, LOW);   //Sets direction of CH A
    analogWrite(3, 255);   //Moves CH A
    
    delay(delaylegnth);
      
    digitalWrite(9, HIGH);  //DISABLE CH A
    digitalWrite(8, LOW); //ENABLE CH B
  
    digitalWrite(13, HIGH);   //Sets direction of CH B
    analogWrite(11, 255);   //Moves CH B
    
    delay(delaylegnth);
    count++;
  }
}

void counterClockwise(int times) {
  int count = 0;
  while(count < times) {
    digitalWrite(9, LOW);  //ENABLE CH A
    digitalWrite(8, HIGH); //DISABLE CH B
  
    digitalWrite(12, HIGH);   //Sets direction of CH A
    analogWrite(3, 255);   //Moves CH A
    
    delay(delaylegnth);
    
    digitalWrite(9, HIGH);  //DISABLE CH A
    digitalWrite(8, LOW); //ENABLE CH B
  
    digitalWrite(13, HIGH);   //Sets direction of CH B
    analogWrite(11, 255);   //Moves CH B
    
    delay(delaylegnth);
    
    digitalWrite(9, LOW);  //ENABLE CH A
    digitalWrite(8, HIGH); //DISABLE CH B
  
    digitalWrite(12, LOW);   //Sets direction of CH A
    analogWrite(3, 255);   //Moves CH A
    
    delay(delaylegnth);
      
    digitalWrite(9, HIGH);  //DISABLE CH A
    digitalWrite(8, LOW); //ENABLE CH B
  
    digitalWrite(13, LOW);   //Sets direction of CH B
    analogWrite(11, 255);   //Moves CH B
    
    delay(delaylegnth);
    count++;
  }
}

void loop(){
  buttonState = digitalRead(buttonPin);
  Serial.println(buttonState);

  if (buttonState == 0) {
    if (armState == 0) {

    } else {
      counterClockwise(19);
      armState = 0;
    }

    //counterClockwise(19);
    delay(100);

  } else {
    if (armState == 0) {
      clockwise(19);
      armState = 1;
    } else {

    }
    delay(100);
  }
  delay(100);
}
