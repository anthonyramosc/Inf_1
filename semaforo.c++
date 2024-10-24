const int LED_VERDE = 15;
const int LED_AMARILLO = 18;
const int LED_ROJO = 19;
const int BOTON = 14;

int Estate_Semaforo = 0; 
bool button_Press = false;
unsigned long timeCh = 0;
unsigned long retraso = 5000; 

void setup() {
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_AMARILLO, OUTPUT);
  pinMode(LED_ROJO, OUTPUT);
  pinMode(BOTON, INPUT_PULLUP);

  Serial.begin(115200);
  
  digitalWrite(LED_VERDE, HIGH);
  Estate_Semaforo = 0;
  timeCh = millis(); 
}

void loop() {
  if (digitalRead(BOTON) == LOW && !button_Press) {
    button_Press = true;
  }

  unsigned long timeA = millis();

  switch (Estate_Semaforo) {
    case 0:
      if (button_Press) {
        cambiarAmarillo(); 
      } else if (timeA - timeCh >= retraso) {
        cambiarAmarillo();
      }
      break;

    case 1: 
      if (timeA - timeCh >= 2000) { 
        cambiarRojo();
      }
      break;

    case 2: 
      if (timeA - timeCh >= retraso) {
        if (button_Press) {
          button_Press = false;
          retraso = 3000;
        } else {
          retraso = 5000;
        }
        cambiarVerde();
      }
      break;

    
  }
}

void cambiarVerde() {
  digitalWrite(LED_ROJO, LOW);
  digitalWrite(LED_VERDE, HIGH);
  Estate_Semaforo = 0;
  timeCh = millis();
}

void cambiarAmarillo() {
  digitalWrite(LED_VERDE, LOW);
  digitalWrite(LED_AMARILLO, HIGH);
  Estate_Semaforo = 1;
  timeCh = millis();
}

void cambiarRojo() {
  digitalWrite(LED_AMARILLO, LOW);
  digitalWrite(LED_ROJO, HIGH);
  Estate_Semaforo = 2;
  timeCh = millis();
}