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
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  Serial.begin(9600);
}

void setlights(int redlight, int greenlight) {
  digitalWrite(RED_LED, redlight);
  digitalWrite(GREEN_LED, greenlight);
}


int readdata() {
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);
  int distance = duration * 0.034 / 2;

  return distance;
}

// int findaverage(int distance) {
//   int average = 0;
//   int sum = 0;
//   int readings[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};


//   return average;
// }

// int findaverage(int distance) {
//   //find the avergae of the last 10 readings
//   // and if one is more than 150% different from the average ignore it
//   // and find the average of the remaining 9

//   int average = 0;
//   int sum = 0;
//   int readings[10];
//   for (int i = 0; i < 10; i++) {
//     readings[i] = 0;
//   }
//   int current = 0;
//   int count = 0;

//   while (count < 10) {
//     if (distance < MAX_DISTANCE) {
//       readings[current] = distance;
//       current = (current + 1) % 150;
//       count++;
//     }
//   }

//   for (int i = 0; i < 10; i++) {
//     sum += readings[i];
//   }
//   average = sum / 10;

//   //check if any of the readings are more than 10% different from average
//   for (int i = 0; i < 10; i++) {
//     if (readings[i] > (average * 1.5) || readings[i] < (average * 0)) {
//       readings[i] = 0;
//     }
//   }

//   //find the average of the remaining readings
//   sum = 0;
//   count = 0;
//   for (int i = 0; i < 10; i++) {
//     if (readings[i] != 0) {
//       sum += readings[i];
//       count++;
//     }
//   }
//   average = sum / count;

//   Serial.print("Average: ");
//   Serial.println(average);

//   return average;
// }

void loop() {
  // digitalWrite(TRIGGER_PIN, LOW);
  // delayMicroseconds(2);
  // digitalWrite(TRIGGER_PIN, HIGH);
  // delayMicroseconds(10);
  // digitalWrite(TRIGGER_PIN, LOW);

  // duration = pulseIn(ECHO_PIN, HIGH);
  // int distance = duration * 0.034 / 2;

  // readdata();

  // delay(50);

  // findaverage();

  long distance = readdata();

  // findaverage(distance);

  if(distance < 15 || distance > 150) {
    tone(BUZZER_PIN, 440);
    setlights(HIGH, LOW);
  } else if(distance < MAX_DISTANCE){
    noTone(BUZZER_PIN);
    setlights(LOW, HIGH);
  } else if (distance > MAX_DISTANCE) {
    noTone(BUZZER_PIN);
    setlights(LOW, HIGH);
  }
  Serial.print("Distance: ");
  Serial.println(distance);

  // delay(50);
}