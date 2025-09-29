#include "pitches.h"

// Pin assignments
static constexpr int BUZZER_PIN = 8;

// Notes in the melody (C5 → C6 scale)
static constexpr int MELODY[] = {
    NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5,
    NOTE_G5, NOTE_A5, NOTE_B5, NOTE_C6
};

// Number of notes in the melody (calculated automatically)
static constexpr size_t MELODY_LENGTH = sizeof(MELODY) / sizeof(MELODY[0]);

// Durations
static constexpr int NOTE_DURATION   = 500;  // ms, each note plays for 0.5s
static constexpr int GAP_BETWEEN     = 1000; // ms, delay between notes
static constexpr int MELODY_RESTART  = 2000; // ms, delay before repeating melody

void setup() {
    pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
    for (size_t i = 0; i < MELODY_LENGTH; ++i) {
        // Play note on buzzer
        tone(BUZZER_PIN, MELODY[i], NOTE_DURATION);

        // Wait before playing the next note
        delay(GAP_BETWEEN);
    }

    // Pause before repeating melody
    delay(MELODY_RESTART);
}
