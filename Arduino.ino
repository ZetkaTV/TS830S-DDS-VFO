#include <AD9833.h>
#include <Encoder.h>

#define FNC_PIN 10
AD9833 gen(FNC_PIN);

// Encoder pins
#define encoderPinA 3
#define encoderPinB 2
#define encoderSwitchPin 4 

Encoder myEnc(encoderPinA, encoderPinB);

unsigned long frequency = 5700000;  // Initial frequency
unsigned long step = 100;           // Initial step size


bool lastSwitchState = HIGH;   
bool switchPressed = false;    

// Step sizes to cycle through
unsigned long steps[] = {1000, 100, 10};  
int currentStepIndex = 1;  // Start with 100Hz step size


long lastPosition = 0;

// Debouncing variables
unsigned long lastDebounceTime = 0;  
const unsigned long debounceDelay = 200; 

void setup() {
  Serial.begin(9600);
  gen.Begin();
  gen.EnableOutput(true);

  pinMode(encoderSwitchPin, INPUT_PULLUP);
}

void loop() {

  long newPosition = myEnc.read() / 4;  // Reduce sensitivity if needed

  // Adjust the frequency only if the encoder position has changed
  if (newPosition != lastPosition) {
    lastPosition = newPosition;

    frequency = 5700000 + (newPosition * step); 

    gen.ApplySignal(TRIANGLE_WAVE, REG0, frequency);
  }

  int switchState = digitalRead(encoderSwitchPin);
  unsigned long currentTime = millis();

  if (switchState == LOW && lastSwitchState == HIGH && (currentTime - lastDebounceTime) > debounceDelay) {
    lastDebounceTime = currentTime;  
    switchPressed = true;
  }


  if (switchPressed) {
    switchPressed = false;

    // Cycle through step sizes: 1000Hz > 100Hz > 10Hz > 1000Hz (loop)
    currentStepIndex = (currentStepIndex + 1) % 3;


    long frequencyOffset = frequency - 5700000;  
    step = steps[currentStepIndex];              
    lastPosition = frequencyOffset / step;       

    // Ensure the frequency aligns exactly to the step size
    frequency = 5700000 + (lastPosition * step);  


    myEnc.write(lastPosition * 4); 
  }

  // Update last switch state
  lastSwitchState = switchState;
}
