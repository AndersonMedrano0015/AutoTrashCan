const int motorPin = 6;
const int trigPin = 9;
const int echoPin = 10;

long duration;
int distance;

void setup() {
  pinMode(motorPin, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  digitalWrite(motorPin, HIGH); // ← Cambia a HIGH
  Serial.begin(9600);
}

void loop() {
  // Limpiar trigger
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  
  // Pulso de 10us
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Leer echo
  duration = pulseIn(echoPin, HIGH, 30000);
  distance = duration * 0.034 / 2;

  // Mostrar datos
  Serial.print("Distancia: ");
  Serial.print(distance);
  Serial.print(" cm | Motor: ");

  // Control del motor
  if (distance > 0 && distance < 10) {
    digitalWrite(motorPin, HIGH);
    Serial.println("ON");
  } else {
    digitalWrite(motorPin, LOW);
    Serial.println("OFF");
  }

  delay(200);
}