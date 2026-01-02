const int motorPin = 6;       // Pin que controla el motor
const int trigPin = 9;
const int echoPin = 10;

long duration;
int distance;

void setup() {
  pinMode(motorPin, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  digitalWrite(motorPin, LOW); // Motor apagado al inicio
  Serial.begin(9600);
}

void loop() {
  // Medir distancia con sensor ultrasónico
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("Distancia: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Si detecta objeto a menos de 10 cm
  if (distance > 0 && distance < 10) {
    digitalWrite(motorPin, HIGH);  // Motor encendido
    Serial.println("Mano cerca - Motor girando");
  } else {
    digitalWrite(motorPin, LOW);   // Motor apagado
    Serial.println("Sin detección - Motor apagado");
  }

  delay(1000);  // Pequeña pausa entre lecturas
}
//Primera versión de código ;9
