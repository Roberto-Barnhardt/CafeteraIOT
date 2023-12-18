volatile int pos = 0;
const int rightPin = 16;
const int leftPin = 4;
bool turnedRight = false;
bool turnedLeft = false;
bool lock = false;


void setup() {
  pinMode(rightPin, INPUT_PULLUP);
  pinMode(leftPin, INPUT_PULLUP);
  Serial.begin(115200);
  attachInterrupt(digitalPinToInterrupt(rightPin), doEncoder, RISING);
}

void doEncoder(){
  lock = true;
  if (digitalRead(leftPin)){
    turnedRight=true;
  } else {
    turnedLeft=true;
  }
}

void loop() {
  static volatile int currentPos = 0;
  if (lock == true){    
    if (turnedRight){
      turnedRight = false;
      pos++;
      Serial.println(pos);
      lock = false;
    } else if (turnedLeft){
      turnedLeft = false;
      pos--;
      Serial.println(pos);
      lock = false;
  }
  }
  //delay(20);
}