#include <DHT.h>

// Configurações do Sensor de Umidade
#define DHTPIN 4
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

// Definição dos Pinos
const int pinLDR = 34; // Leitura analógica do "pH"
const int btnN = 12;   // Nitrogênio
const int btnP = 14;   // Fósforo
const int btnK = 27;   // Potássio
const int releBomba = 26; // Bomba de irrigação

void setup() {
  Serial.begin(115200);
  dht.begin();

  // INPUT_PULLUP inverte a lógica: botão não apertado lê HIGH, apertado lê LOW.
  pinMode(btnN, INPUT_PULLUP);
  pinMode(btnP, INPUT_PULLUP);
  pinMode(btnK, INPUT_PULLUP);

  pinMode(releBomba, OUTPUT);
  digitalWrite(releBomba, LOW); // Garante que a bomba inicie desligada
}

void loop() {
  // 1. Leitura da Umidade (DHT22)
  float umidade = dht.readHumidity();

  // 2. Leitura dos Nutrientes NPK
  // Como usamos PULLUP, verificamos se o sinal é LOW (pressionado)
  bool nivelN = (digitalRead(btnN) == LOW);
  bool nivelP = (digitalRead(btnP) == LOW);
  bool nivelK = (digitalRead(btnK) == LOW);

  // 3. Leitura e Tratamento do pH (LDR)
  int leituraLDR = analogRead(pinLDR);
  
  // O ESP32 lê portas analógicas de 0 a 4095. 
  // Vamos mapear isso para uma escala de pH de 0.0 a 14.0.
  float phBase = map(leituraLDR, 0, 4095, 0, 140) / 10.0;
  float phFinal = phBase;

  // Aplicação da regra do enunciado: Os botões afetam o pH.
  if (nivelN) phFinal -= 1.0; // Adição de Nitrogênio acidifica o solo
  if (nivelK) phFinal += 1.0; // Adição de Potássio alcaliniza o solo
  
  // Travas de segurança para manter o pH entre 0 e 14
  if (phFinal < 0) phFinal = 0;
  if (phFinal > 14) phFinal = 14;

  // 4. Lógica de Irrigação (Cultura: Cana-de-açúcar)
  bool precisaIrrigar = false;

  // Condição: Umidade abaixo de 50% E pH dentro da tolerância da cana (5.0 a 8.0)
  if (umidade < 50.0 && phFinal >= 5.0 && phFinal <= 8.0) {
    precisaIrrigar = true;
  }

  // 5. Execução
  if (precisaIrrigar) {
    digitalWrite(releBomba, HIGH);
    Serial.println("STATUS: Bomba LIGADA. Irrigando...");
  } else {
    digitalWrite(releBomba, LOW);
    Serial.println("STATUS: Bomba DESLIGADA.");
  }

  // Monitoramento no Console
  Serial.print("Umidade: "); Serial.print(umidade); Serial.print("% | ");
  Serial.print("pH Final: "); Serial.print(phFinal);
  Serial.print(" | N:"); Serial.print(nivelN);
  Serial.print(" P:"); Serial.print(nivelP);
  Serial.print(" K:"); Serial.println(nivelK);
  Serial.println("---------------------------------------------------");

  delay(2000); // Aguarda 2 segundos antes da próxima leitura
}
