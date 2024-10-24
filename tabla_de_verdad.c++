const int pulsante1 = 13;
const int pulsante2 = 12; 
const int pulsante3 = 14;
const int ledPin = 15;

bool estadoPulsante1 = false;
bool estadoPulsante2 = false;
bool estadoPulsante3 = false;
bool ultimoEstadoPulsante1 = false;
bool ultimoEstadoPulsante2 = false;
bool ultimoEstadoPulsante3 = false;

void setup() {
  Serial.begin(115200);
  pinMode(pulsante1, INPUT);
  pinMode(pulsante2, INPUT);
  pinMode(pulsante3, INPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
}

void loop() {
  bool lecturaPulsante1 = digitalRead(pulsante1);
  bool lecturaPulsante2 = digitalRead(pulsante2);
  bool lecturaPulsante3 = digitalRead(pulsante3);

  if (lecturaPulsante1 && !ultimoEstadoPulsante1) {
    estadoPulsante1 = !estadoPulsante1;
  }
  if (lecturaPulsante2 && !ultimoEstadoPulsante2) {
    estadoPulsante2 = !estadoPulsante2;
  }
  if (lecturaPulsante3 && !ultimoEstadoPulsante3) {
    estadoPulsante3 = !estadoPulsante3;
  }

  ultimoEstadoPulsante1 = lecturaPulsante1;
  ultimoEstadoPulsante2 = lecturaPulsante2;
  ultimoEstadoPulsante3 = lecturaPulsante3;

  bool F = (estadoPulsante1 && estadoPulsante2 && estadoPulsante3) ||
          (!estadoPulsante1 && estadoPulsante2) ||
          (!estadoPulsante2 && estadoPulsante3);

  digitalWrite(ledPin, F);

  Serial.print("Pulsante1: ");
  Serial.print(estadoPulsante1);
  Serial.print(" Pulsante2: ");
  Serial.print(estadoPulsante2);
  Serial.print(" Pulsante3: ");
  Serial.print(estadoPulsante3);
  Serial.print(" F: ");
  Serial.println(F);

  delay(50);
}