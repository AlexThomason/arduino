// Group all RGB pin definitions in one place
struct RGBPins {
  static constexpr int RED   = 6;
  static constexpr int GREEN = 5;
  static constexpr int BLUE  = 3;
};

// Define fading delay time
constexpr int delayTime = 10; // ms

// Color values
int redValue;
int greenValue;
int blueValue;

void setup() {
  pinMode(RGBPins::RED, OUTPUT);
  pinMode(RGBPins::GREEN, OUTPUT);
  pinMode(RGBPins::BLUE, OUTPUT);

  digitalWrite(RGBPins::RED, HIGH);
  digitalWrite(RGBPins::GREEN, LOW);
  digitalWrite(RGBPins::BLUE, LOW);
}

void loop() {
  // --- Red → Green fade ---
  redValue = 255;
  greenValue = 0;
  blueValue = 0;

  for (int i = 0; i < 255; i++) {
    redValue -= 1;
    greenValue += 1;
    analogWrite(RGBPins::RED, redValue);
    analogWrite(RGBPins::GREEN, greenValue);
    delay(delayTime);
  }

  // --- Green → Blue fade ---
  redValue = 0;
  greenValue = 255;
  blueValue = 0;

  for (int i = 0; i < 255; i++) {
    greenValue -= 1;
    blueValue += 1;
    analogWrite(RGBPins::GREEN, greenValue);
    analogWrite(RGBPins::BLUE, blueValue);
    delay(delayTime);
  }

  // --- Blue → Red fade ---
  redValue = 0;
  greenValue = 0;
  blueValue = 255;

  for (int i = 0; i < 255; i++) {
    blueValue -= 1;
    redValue += 1;
    analogWrite(RGBPins::BLUE, blueValue);
    analogWrite(RGBPins::RED, redValue);
    delay(delayTime);
  }
}
