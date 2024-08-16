// Pin Definitions
const int ledPin = LED_BUILTIN;  // Built-in LED (Pin 13 on most boards)
const int buttonPin = 2;         // Push button connected to pin 2

// Timing constants (in milliseconds)
const int dotDuration = 1000;    // Duration of a dot
const int dashDuration = 3 * dotDuration;  // Duration of a dash
const int letterSpace = 3 * dotDuration;   // Space between letters
const int wordSpace = 7 * dotDuration;     // Space between words

bool buttonState = LOW;         // Current state of the button
bool lastButtonState = LOW;     // Previous state of the button

void setup() {
  pinMode(ledPin, OUTPUT);      // Set the LED pin as output
  pinMode(buttonPin, INPUT_PULLUP); 
}

void loop() {
  buttonState = digitalRead(buttonPin);  

  if (buttonState == LOW && lastButtonState == HIGH) {
    blinkMorseCode();  
  }

  lastButtonState = buttonState; 
}

void blinkMorseCode() {
  // P: .--.
  blinkDot();
  blinkDash();
  blinkDash();
  blinkDot();
  delay(letterSpace);

  // R: .-.
  blinkDot();
  blinkDash();
  blinkDot();
  delay(letterSpace);

  // I: ..
  blinkDot();
  blinkDot();
  delay(letterSpace);

  // Y: -.--
  blinkDash();
  blinkDot();
  blinkDash();
  blinkDash();
  delay(letterSpace);

  // A: .-
  blinkDot();
  blinkDash();
  delay(letterSpace);

  // N: -. 
  blinkDash();
  blinkDot();
  delay(letterSpace);

  // K: -.-
  blinkDash();
  blinkDot();
  blinkDash();
  delay(letterSpace);

  // C: -.-.
  blinkDash();
  blinkDot();
  blinkDash();
  blinkDot();
  delay(letterSpace);

  // A: .-
  blinkDot();
  blinkDash();
  delay(letterSpace);

  // Space between letters or words (optional, adjust as needed)
  delay(wordSpace);
}

// Function to blink a dot
void blinkDot() {
  digitalWrite(ledPin, HIGH);  // Turn the LED on
  delay(dotDuration);
  digitalWrite(ledPin, LOW);   // Turn the LED off
  delay(dotDuration);          // Space between dots/dashes
}

// Function to blink a dash
void blinkDash() {
  digitalWrite(ledPin, HIGH);  // Turn the LED on
  delay(dashDuration);
  digitalWrite(ledPin, LOW);   // Turn the LED off
  delay(dotDuration);          // Space between dots/dashes
}
