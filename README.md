# Sistema de Automação Residencial Inteligente com Arduino
Implementa uma automação simples, onde as luzes acendem automaticamente ao detectar movimento, a temperatura do ambiente é monitorada para controlar um ventilador, e a porta pode ser aberta ou fechada manualmente com um botão.
<br><br>
- Função controlLight(bool state): Acende ou apaga a luz dependendo do estado (HIGH ou LOW).
- Função controlDoor(bool open): Abre (com 90 graus) ou fecha (com 0 graus) a porta usando o servo motor.
- Função controlDevice(bool state): Liga ou desliga um dispositivo eletrônico (como ventilador) com base no estado fornecido.
- Função readTemperature(): Lê a temperatura e umidade do ambiente usando o sensor DHT11 e aciona o ventilador se a temperatura for superior a 25°C.
- Função setup(): Inicializa os pinos, configura o sensor DHT11 e o servo motor, e imprime uma mensagem inicial no monitor serial.
- Função loop(): Monitora continuamente os sensores:
- 1. Detecta movimento para acionar a luz.
- 2. Lê a temperatura e controla o ventilador conforme a necessidade.
- 3.Verifica o botão para abrir ou fechar a porta manualmente.
  
## Pré-Requisitos de Hardware
Placa Arduino:
A placa Arduino é a base do sistema e será responsável por controlar todos os sensores e atuadores. O código foi desenvolvido para a Arduino Uno, mas pode ser adaptado para outras placas da linha Arduino.
<br><br>
Sensor de Movimento PIR (Passive Infrared Sensor):
Este sensor detecta movimento no ambiente e é usado para acionar as luzes automaticamente quando uma pessoa é detectada. O pino de saída do sensor PIR deve ser conectado a um pino digital do Arduino.
<br><br>
Sensor de Temperatura e Umidade DHT11 (ou DHT22):
O sensor DHT11 é utilizado para medir a temperatura e a umidade do ambiente. Ele será usado para ligar ou desligar dispositivos como ventiladores ou aquecedores, dependendo da temperatura. O pino de dados do sensor deve ser conectado a um pino digital.
<br><br>
Servo Motor:
O servo motor será usado para abrir e fechar uma porta, ajustando sua posição de acordo com o comando enviado pelo Arduino. O pino de controle do servo deve ser conectado a um pino PWM do Arduino.
<br><br>
Botão de Controle (Push Button):
Um botão será utilizado para permitir o controle manual da porta. Quando pressionado, o Arduino abrirá ou fechará a porta. O botão deve ser conectado a um pino digital, e é recomendado utilizar um resistor de pull-up ou pull-down.
<br><br>
Relés ou Dispositivos Eletrônicos:
Dependendo do que você deseja automatizar, como lâmpadas ou ventiladores, você pode precisar de um módulo relé para controlar dispositivos de maior potência. O pino de controle do relé deve ser conectado ao Arduino.
<br><br>
Fios de Conexão:
Fios jumper para conectar todos os componentes à placa Arduino. Certifique-se de ter fios suficientes para conectar os sensores, o servo motor e outros dispositivos.

## Pré-Requisitos de Software:
Bibliotecas do Arduino:
- Servo: A biblioteca Servo.h é usada para controlar o servo motor.
- DHT: A biblioteca DHT.h é necessária para ler dados dos sensores DHT11 ou DHT22. 
