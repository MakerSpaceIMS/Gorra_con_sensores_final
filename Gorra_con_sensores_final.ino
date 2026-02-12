// --- Pines para los sensores ultrasónicos ---
// Sensor 1
const int emisorTrig1 = 2;
const int receptorEcho1 = 3;
// Sensor 2
const int emisorTrig2 = 4;
const int receptorEcho2 = 5;
// Sensor 3
const int emisorTrig3 = 7;
const int receptorEcho3 = 6;
// --- Pin para buzzer ---
const int pinBuzzer = 8;
// --- Potenciómetro ---
int POT;
int POT2;
const int potPin = A0;
void setup() {
// Iniciar comunicación serial
Serial.begin(9600);
// Configurar pines del Sensor 1
pinMode(emisorTrig1, OUTPUT);
pinMode(receptorEcho1, INPUT);
digitalWrite(emisorTrig1, LOW);
// Configurar pines del Sensor 2
pinMode(emisorTrig2, OUTPUT);
pinMode(receptorEcho2, INPUT);
digitalWrite(emisorTrig2, LOW);
// Configurar pines del Sensor 3
pinMode(emisorTrig3, OUTPUT);
pinMode(receptorEcho3, INPUT);
digitalWrite(emisorTrig3, LOW);
// Configurar pin del zumbador
pinMode(pinBuzzer, OUTPUT);
}
// --- Función para medir la distancia con cualquier sensor ---
long medirDistancia(int trigPin, int echoPin) 
{
// Asegurarse de que el Trig está apagado al inicio
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Enviar el pulso ultrasónico de 10 microsegundos
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Medir el tiempo que tarda en regresar el eco
long duracion = pulseIn(echoPin, HIGH);
// Calcular la distancia en centímetros (duracion / 58)
long distancia = duracion / 58;
return distancia;
}
void loop() {
// Leer el valor del potenciómetro (ajustado a rango 0-250)
POT = analogRead(potPin) / 4;
POT2 = analogRead(potPin) / 8;
// 1. Medir la distancia de cada sensor usando la función
long distancia1 = medirDistancia(emisorTrig1, receptorEcho1);
long distancia2 = medirDistancia(emisorTrig2, receptorEcho2);
long distancia3 = medirDistancia(emisorTrig3, receptorEcho3);
// 2. Imprimir las distancias y valor del potenciómetro en el monitor serial
Serial.print("Sensor 1: ");
Serial.print(distancia1);
Serial.print("cm | Sensor 2: ");
Serial.print(distancia2);
Serial.print("cm | Sensor 3: ");
Serial.print(distancia3);
Serial.print("cm | POT: ");
Serial.println(POT);
Serial.println(POT2);
// 3. Lógica de los tonos con umbral controlado por potenciómetro
if (distancia1 < POT2) {
Serial.println("¡Objeto cerca en Sensor 1!");
tone(pinBuzzer, 800, 50); // Tono de 800 Hz
delay(100);
}
else if (distancia2 < POT2) {
Serial.println("¡Objeto cerca en Sensor 2!");
tone(pinBuzzer, 600, 50); // Tono de 600 Hz
delay(50);
}
else if (distancia3 < POT) {
Serial.println("¡Objeto cerca en Sensor 3!");
tone(pinBuzzer, 1200, 50); // Tono de 1200 Hz
delay(50);
}
else {
Serial.println("Nada cerca");
}
// Pequeña pausa antes de la siguiente ronda de mediciones
delay(50);
}
