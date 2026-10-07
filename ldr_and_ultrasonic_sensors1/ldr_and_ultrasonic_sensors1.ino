
 // Pin identity
const int trigPin = 12;        // TRIG PIN OUTPUT
const int echoPin = 10;        // ECHO PIN INPUT
const int resistancePin = A1;  // LDR INPUT
const int ledPin = 3;          // LED OUTPUT

// Variables
long duration;
int distance;
const int darkThreshold = 400;
const int distanceThreshold = 20;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(resistancePin, INPUT);
  pinMode(ledPin, OUTPUT); 
  Serial.begin(9600);
}

int calcDist() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = 0.034 * duration / 2;
  return distance;
}

void loop() {
  int ldrValue = analogRead(resistancePin);  //  Missing semicolon fixed
  distance = calcDist();                     // Ensure distance is updated

  Serial.print("Light level: ");
  Serial.println(ldrValue);

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // ✅ Corrected if-statement (removed stray semicolon)
  if (ldrValue < darkThreshold && distance <= distanceThreshold && distance > 0) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

  delay(1000);
}
 
    
    
  
    
  
    
    
    
    
    



  
