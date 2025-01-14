// Pin assignments
const int buttonPin = 2;
const int ledPin = 10;

// Variables
bool ledState = false; // To track the LED state
bool lastButtonState = LOW; // To store the previous button state
bool buttonPressed = false; // To debounce the button
unsigned long lastDebounceTime = 0; // Timing variable
const unsigned long debounceDelay = 1; // 5 ms debounce delay

void setup() {
  pinMode(buttonPin, INPUT_PULLUP); // Use the internal pull-up resistor
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW); // Initialize the LED as off
}

void loop() {
  // Get the current time
  unsigned long currentTime = millis();

  // Check if it's time to read the button
  if (currentTime - lastDebounceTime >= debounceDelay) {
    // Read the button state
    bool currentButtonState = digitalRead(buttonPin);

    // Check if the button state has changed
    if (currentButtonState == LOW && lastButtonState == HIGH && !buttonPressed) {
      ledState = !ledState; // Toggle the LED state
      digitalWrite(ledPin, ledState ? HIGH : LOW);
      buttonPressed = true; // Register the press
    }

    // Reset the buttonPressed flag when the button is released
    if (currentButtonState == HIGH) {
      buttonPressed = false;
    }

    lastButtonState = currentButtonState; // Update the last button state
    lastDebounceTime = currentTime; // Update the debounce timer
  }
}
