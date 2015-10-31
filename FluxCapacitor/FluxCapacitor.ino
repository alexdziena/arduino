const int OUTER_SET = 2;
const int MIDDLE_SET = 3;
const int INNER_SET = 4;
const int MIN_DELAY = 10;
const float MAX_DELAY = 500.0;
const int MAX_ITERS = 200;
const float DELAY_DISCOUNT_FACTOR = 1.1;


float mDelay = MAX_DELAY;
int iters = 0;
int leds[] = {OUTER_SET,MIDDLE_SET,INNER_SET};
int ledsLength = 3;

void setup()
{
//  Serial.begin(9600);
  for (int i = 0; i < 3; i++) {
    pinMode(leds[i],OUTPUT);
  }
}

void loop() {
  if (mDelay < MIN_DELAY) {
    iters += 1;
  }
  if (iters > MAX_ITERS) {
    iters = 0;
    mDelay = MAX_DELAY;
  }
  for (int i = 0; i < ledsLength; i++) {
    int led_off = i-1;
    if (i == 0) {
      led_off = ledsLength -1;
    }
    digitalWrite(leds[led_off], LOW);
    digitalWrite(leds[i], HIGH);
    delay(mDelay);
  }
  Serial.print(mDelay);
  if (mDelay >= MIN_DELAY && iters == 0) {
    mDelay = mDelay / DELAY_DISCOUNT_FACTOR;
  }
}
