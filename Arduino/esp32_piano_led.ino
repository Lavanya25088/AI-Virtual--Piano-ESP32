
#define BUZZER_PIN 5      // Buzzer output pin (PWM capable)
#define LED_PIN_1  12      // LED 1 (C + D)
#define LED_PIN_2  13      // LED 2 (E + F)
#define LED_PIN_3  14      // LED 3 (G + A)
#define LED_PIN_4  15     // LED 4 (B + C2)


const int FREQUENCIES[8] = {
    262,  // C  (261.63)
    294,  // D  (293.66)
    330,  // E  (329.63)
    349,  // F  (349.23)
    392,  // G  (392.00)
    440,  // A  (440.00)
    494,  // B  (493.88)
    523   // C2 (523.25)
};

int ledPins[4] = {LED_PIN_1, LED_PIN_2, LED_PIN_3, LED_PIN_4};


void setup() {
    Serial.begin(9600);
    
    // Buzzer pin setup
    pinMode(BUZZER_PIN, OUTPUT);
    digitalWrite(BUZZER_PIN, LOW);
    
    // LED pins setup
    for (int i = 0; i < 4; i++) {
        pinMode(ledPins[i], OUTPUT);
        digitalWrite(ledPins[i], LOW);
    }
    
    delay(1000);
    Serial.println("ESP32 Piano Ready!");
}

// ─────────────────────────────────────────────
// MAIN LOOP
// ─────────────────────────────────────────────
void loop() {
    if (Serial.available()) {
        String input = Serial.readStringUntil('\n');
        input.trim();
        
        // Parse format: "NOTE:X,LED:Y"
        int noteNum = -1;
        int ledNum = -1;
        
        // Extract NOTE number
        int noteIdx = input.indexOf("NOTE:");
        if (noteIdx != -1) {
            int commaIdx = input.indexOf(",");
            if (commaIdx != -1) {
                noteNum = input.substring(noteIdx + 5, commaIdx).toInt();
            } else {
                noteNum = input.substring(noteIdx + 5).toInt();
            }
        }
        
        // Extract LED number
        int ledIdx = input.indexOf("LED:");
        if (ledIdx != -1) {
            ledNum = input.substring(ledIdx + 4).toInt();
        }
        
        // Validate inputs
        if (noteNum >= 0 && noteNum < 8 && ledNum >= 0 && ledNum < 4) {
            // Turn OFF all LEDs
            for (int i = 0; i < 4; i++) {
                digitalWrite(ledPins[i], LOW);
            }
            
            // Turn ON the corresponding LED
            digitalWrite(ledPins[ledNum], HIGH);
            
            // Play the note
            playNote(noteNum);
            
            // Debug output
            Serial.print("Note: ");
            Serial.print(noteNum);
            Serial.print(" | LED: ");
            Serial.print(ledNum);
            Serial.print(" | Freq: ");
            Serial.println(FREQUENCIES[noteNum]);
        }
    }
}

// ─────────────────────────────────────────────
// PLAY NOTE FUNCTION
// ─────────────────────────────────────────────
void playNote(int noteIndex) {
    if (noteIndex < 0 || noteIndex >= 8) return;
    
    int frequency = FREQUENCIES[noteIndex];
    int duration = 200;  // milliseconds
    
    tone(BUZZER_PIN, frequency, duration);
}
