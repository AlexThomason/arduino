// Use constexpr for compile-time constants
static constexpr int BUZZER_PIN = 12;   // Pin connected to the active buzzer

// Define durations in milliseconds
static constexpr int LONG_DURATION  = 500;
static constexpr int MED_DURATION   = 300;
static constexpr int SHORT_DURATION = 100;
static constexpr int FINAL_DURATION = 5000;

void setup() {
    pinMode(BUZZER_PIN, OUTPUT);  // Initialize buzzer pin as output
}

void loop() {
    // Loop 20 times, changing sound duration depending on i
    for (int i = 0; i < 20; ++i) {
        int soundDuration = 0;

        if (i < 5) {
            soundDuration = LONG_DURATION;
        } else if (i < 10) {
            soundDuration = MED_DURATION;
        } else {
            soundDuration = SHORT_DURATION;
        }

        // Turn buzzer ON
        digitalWrite(BUZZER_PIN, HIGH);
        delay(soundDuration);

        // Turn buzzer OFF
        digitalWrite(BUZZER_PIN, LOW);
        delay(soundDuration);
    }

    // Final long buzzer sound (5 seconds)
    digitalWrite(BUZZER_PIN, HIGH);
    delay(FINAL_DURATION);
    digitalWrite(BUZZER_PIN, LOW);
}
