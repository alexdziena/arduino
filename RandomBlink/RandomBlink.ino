const int LED = 13;
const int MIN_DELAY = 100;
const int MAX_DELAY = 2000;
const int ON_FOR = 50;

void setup()
{
  Serial.begin(9600);
  //Serial.println("Setting Up");
  pinMode(LED,OUTPUT);
  randomSeed(analogRead(0));
  //Serial.println("Setup complete");
}

void loop() {
  int myDelay = getDelay();
  flip(ON_FOR,true);
  flip(myDelay,false);
}

void flip(int myDelay,boolean level) {
  //Serial.println(myDelay);
  if (level) {
    digitalWrite(LED, HIGH);   // turn the LED on (HIGH is the voltage level)
  } else {
    digitalWrite(LED, LOW);
  }
  delay(myDelay);              // wait for a second
}

int getDelay() {
  return random(MIN_DELAY,MAX_DELAY);
}
