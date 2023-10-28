int IN1 = 2; // Motor Direito - Direção (HIGH ou LOW)   - Pino 2
int IN2 = 3; // Motor Direito - Velocidade (0 a 255)    - Pino 3  (~PWD)
int IN3 = 4; // Motor Esquerdo - Direção (HIGH ou LOW)  - Pino 4
int IN4 = 5; // Motor Esquerdo - Velocidade (0 a 255)   - Pino 5 (~PWD)


#define pin_S1 8 // Sensor Esquerdo - Pino 8
#define pin_S2 9 // Sensor Direito  - Pino 9
bool Sensor1 = 0;
bool Sensor2 = 0;

int velocidade = 50; // Velocidade pré-definida para 50

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

// Faz o robô andar pra frente (Liga os dois motores em HIGH)
void andar_pra_frente(int velocidade) {
  digitalWrite(IN1, HIGH); 		// Motor Direito
  digitalWrite(IN3, HIGH); 		// Motor Esquerdo
  analogWrite(IN2, velocidade);	// Motor Direito
  analogWrite(IN4, velocidade);	// Motor Esquerdo
}

// Faz o robô virar para a esquerda (Liga o motor da direita em HIGH)
void virar_esquerda(int velocidade) {
  digitalWrite(IN1, HIGH);		// Motor Direito
  digitalWrite(IN3, LOW);		// Motor Esquerdo
  analogWrite(IN2, velocidade);	// Motor Direito
  analogWrite(IN4, 0);			// Motor Esquerdo
}

// Faz o robô virar para a direita  (Liga o motor da esquerda em HIGH)
void virar_direita(int velocidade) {
  digitalWrite(IN1, LOW);		// Motor Direito
  digitalWrite(IN3, HIGH);		// Motor Esquerdo
  analogWrite(IN2, 0);			// Motor Direito
  analogWrite(IN4, velocidade);	// Motor Esquerdo
}

void loop() {

  // Faz o robô ir para a frente
  if (Sensor1 == 0 && Sensor2 == 0)
    andar_pra_frente(velocidade);

  // Vira a direção do robô para a Esquerda
  if (Sensor1 == 1 && Sensor2 == 0)
    virar_direita(velocidade);

  // Vira a direção do robô para a Direita
  if (Sensor1 == 0 && Sensor2 == 1)
    virar_esquerda(velocidade);
}

