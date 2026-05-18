// Automata ontozorendszer Tinkercad-ben

int moisture = 0;

const int moisturePin = A0;

const int blueLed = 8;     
const int greenLed = 9;    
const int yellowLed = 10;  
const int orangeLed = 11;  
const int redLed = 12;     

const int pumpPin = 7;

void setup() {
  Serial.begin(9600);

  pinMode(blueLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(orangeLed, OUTPUT);
  pinMode(redLed, OUTPUT);

  pinMode(pumpPin, OUTPUT);
}

void loop() {
  moisture = analogRead(moisturePin);

  Serial.print("Talajnedvesseg: ");
  Serial.println(moisture);

  digitalWrite(blueLed, LOW);
  digitalWrite(greenLed, LOW);
  digitalWrite(yellowLed, LOW);
  digitalWrite(orangeLed, LOW);
  digitalWrite(redLed, LOW);

  digitalWrite(pumpPin, LOW);

  if (moisture < 200) {
    digitalWrite(redLed, HIGH);
    digitalWrite(pumpPin, HIGH);
    Serial.println("Nagyon szaraz - locsolo BE");
  }
  else if (moisture < 400) {
    digitalWrite(orangeLed, HIGH);
    digitalWrite(pumpPin, HIGH);
    Serial.println("Szaraz - locsolo BE");
  }
  else if (moisture < 600) {
    digitalWrite(yellowLed, HIGH);
    digitalWrite(pumpPin, LOW);
    Serial.println("Kozepes nedvesseg - locsolo KI");
  }
  else if (moisture < 800) {
    digitalWrite(greenLed, HIGH);
    digitalWrite(pumpPin, LOW);
    Serial.println("Nedves - locsolo KI");
  }
  else {
    digitalWrite(blueLed, HIGH);
    digitalWrite(pumpPin, LOW);
    Serial.println("Nagyon nedves - locsolo KI");
  }

  delay(500);
}