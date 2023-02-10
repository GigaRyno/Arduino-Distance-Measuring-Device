#include <LiquidCrystal.h>

//LEDs
#define GREEN_LED 2
#define RED_LED 3

//LCD
#define BACKLIGHT 13
#define CONTRAST 12

//Buzzer
#define BUZZER_PIN  8

//UltraSonic Sensor
#define TRIGGER_PIN  9
#define ECHO_PIN     10

long duration; // Duration used to calculate distance
int distanceCm; // Distance measured
int distanceIn; // Distance measured

LiquidCrystal lcd(13, 12, 4, 5, 6, 7); // LCD Shield

void setup() {
  lcd.begin(16, 2); // Initialize the LCD
  lcd.clear(); // Clear the LCD

  pinMode(BACKLIGHT, OUTPUT);
  analogWrite(BACKLIGHT, 210);
  pinMode(CONTRAST, OUTPUT);
  analogWrite(CONTRAST, 40);

  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  Serial.begin(9600);
}

void setlights(int redLightState, int greenLightState) {
  //Sets the Red and Green lights to the correct state
  digitalWrite(RED_LED, redLightState);
  digitalWrite(GREEN_LED, greenLightState);
}

void loop() {
  lcd.clear();

  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);
  distanceCm = duration * 0.034 / 2;
  distanceIn = duration * 0.0133 / 2;

  // Prints distances on LCD Screen
  lcd.setCursor(0, 0);
  lcd.print("Distance: " + String(distanceCm) + "Cm");
  lcd.setCursor(0, 1);
  lcd.print("Distance: " + String(distanceIn) + "In");

  if(distanceCm < 15 || distanceCm > 150) { // Too close or Too far
    tone(BUZZER_PIN, 440);
    setlights(HIGH, LOW);
  } else if(distanceCm < 1000 || distanceCm > 1200){ // UltraSonic Sensor gets junk data sometimes
    noTone(BUZZER_PIN);
    setlights(LOW, HIGH);
  } else { // Safe distance
    noTone(BUZZER_PIN);
    setlights(LOW, HIGH);
  }
  Serial.print("Distance: ");
  Serial.println(distanceCm);
}
