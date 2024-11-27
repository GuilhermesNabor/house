#include <Servo.h>
#include <DHT.h>

// Definindo os pinos para controle
#define PIN_LIGHT 2       
#define PIN_DOOR 3       
#define PIN_DEVICE 4     
#define PIR_SENSOR_PIN 5   
#define DHT_PIN 6      
#define BUTTON_PIN 7     


#define DHTTYPE DHT11
DHT dht(DHT_PIN, DHTTYPE);


Servo portaServo;

// Função para acender e apagar a luz
void controlLight(bool state) {
  if (state) {
    digitalWrite(PIN_LIGHT, HIGH);  
  } else {
    digitalWrite(PIN_LIGHT, LOW); 
  }
}

// Função para abrir ou fechar a porta
void controlDoor(bool open) {
  if (open) {
    portaServo.write(90);  
  } else {
    portaServo.write(0);  
  }
}

// Função para controlar um dispositivo eletrônico
void controlDevice(bool state) {
  if (state) {
    digitalWrite(PIN_DEVICE, HIGH); 
  } else {
    digitalWrite(PIN_DEVICE, LOW);   
  }
}

// Função para ler a temperatura e a umidade
void readTemperature() {
  float h = dht.readHumidity();
  float t = dht.readTemperature(); 

  if (isnan(t) || isnan(h)) {
    Serial.println("Erro ao ler o sensor DHT!");
    return;
  }


  Serial.print("Temperatura: ");
  Serial.print(t);
  Serial.print(" °C | Umidade: ");
  Serial.print(h);
  Serial.println(" %");

  // Controle baseado na temperatura (exemplo de uso de dispositivos)
  if (t > 25) {  // Se a temperatura for maior que 25°C, ligar o ventilador
    controlDevice(true);
  } else {
    controlDevice(false);
  }
}

void setup() {
  pinMode(PIN_LIGHT, OUTPUT);
  pinMode(PIN_DOOR, OUTPUT);
  pinMode(PIN_DEVICE, OUTPUT);
  pinMode(PIR_SENSOR_PIN, INPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);


  portaServo.attach(PIN_DOOR);
  
  dht.begin();


  Serial.begin(9600);
  Serial.println("Sistema de Automação Residencial Iniciado!");
  
  controlLight(false);
  controlDoor(false);
  controlDevice(false);
}

void loop() {
  if (digitalRead(PIR_SENSOR_PIN) == HIGH) { 
    Serial.println("Movimento detectado! Acionando luz...");
    controlLight(true);
  } else {  
    controlLight(false);
  }

  readTemperature();
  
  // Controle manual da porta (Botão de controle)
  if (digitalRead(BUTTON_PIN) == LOW) { 
    Serial.println("Botão pressionado! Abrindo porta...");
    controlDoor(true);
    delay(2000); 
    controlDoor(false);
  }

  delay(2000); 
}