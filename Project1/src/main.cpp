#include <Arduino.h>
#include <NewPing.h>

#define GREEN_LED 2
#define RED_LED 3
#define BUZZER_PIN  8
#define TRIGGER_PIN  9
#define ECHO_PIN     10
#define MAX_DISTANCE 400 // Maximum distance we want to measure (in centimeters).

long duration;
// int distanceCm, distanceInch;

// NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

// void setup() {
//   pinMode(BUZZER_PIN, OUTPUT);
//   pinMode(GREEN_LED, OUTPUT);
//   pinMode(RED_LED, OUTPUT);
//   Serial.begin(9600);
// }

// void loop() {
//   // delay(50);
//   // digitalWrite(TRIGGER_PIN, LOW);
//   // delayMicroseconds(2);
//   // digitalWrite(TRIGGER_PIN, HIGH);
//   // delayMicroseconds(10);
//   // digitalWrite(TRIGGER_PIN, LOW);
//   // duration = pulseIn(ECHO_PIN, HIGH);
//   // distanceCm = duration * 0.034 / 2;
//   // distanceInch = duration * 0.0133 / 2;
//   // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.

//   distanceCm = sonar.ping_cm(); // Send ping, get distance in cm and print result (0 = outside set distance range)
//   distanceInch = sonar.ping_in(); // Send ping, get distance in cm and print result (0 = outside set distance range)

//   Serial.print("Distance: ");
//   Serial.print(distanceCm);
//   Serial.println("Cm");

//   if(distanceCm < 15 && distanceCm > 300) {
//     tone(BUZZER_PIN, 440);
//     digitalWrite(RED_LED, HIGH);
//     digitalWrite(GREEN_LED, LOW);
//   } 
//     noTone(BUZZER_PIN);
//     digitalWrite(RED_LED, LOW);
//     digitalWrite(GREEN_LED, HIGH);
  
//   // digitalWrite(RED_LED, LOW);
//   // digitalWrite(GREEN_LED, HIGH);
//   // noTone(BUZZER_PIN);
// }

void setup() {
  pinMode(TRIGGER_PIN, OUTPUT); // Sets the trigPin as an Output
  pinMode(ECHO_PIN, INPUT); // Sets the echoPin as an Input
  pinMode(BUZZER_PIN, OUTPUT); // Sets the buzzerPin as an Output
  pinMode(GREEN_LED, OUTPUT); // Sets the greenLedPin as an Output
  pinMode(RED_LED, OUTPUT); // Sets the redLedPin as an Output
  Serial.begin(9600); // Starts the serial communication
}

void loop() {
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);
  int distance = duration * 0.034 / 2;

  if(distance < 15 || distance > 150) {
    tone(BUZZER_PIN, 440);
    digitalWrite(RED_LED, HIGH);
    digitalWrite(GREEN_LED, LOW);
  } else {
    noTone(BUZZER_PIN);
    digitalWrite(RED_LED, LOW);
    digitalWrite(GREEN_LED, HIGH);
  }

  Serial.print("Distance: ");
  Serial.println(distance);
  
}