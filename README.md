# Gorra_con_sensores_final
CONROL DE TRES SENSORES ULTRASONICOS CONB UN ARDUINO CON FUNSIONES TRIG Y ECO Y UNA FUNSIONB PARA CONTROLAR LA DISTANCIA
Sistema de Alerta de Proximidad Triple con Arduino
Este proyecto implementa un sistema de detección de objetos utilizando tres sensores ultrasónicos. El sistema emite diferentes tonos de alerta a través de un buzzer dependiendo de qué sensor detecte un obstáculo. Además, incluye un potenciómetro para ajustar dinámicamente la distancia de umbral (sensibilidad).
-Características
Detección Triple: Monitoreo simultáneo de tres áreas distintas.

Alertas Auditivas Diferenciadas: Cada sensor dispara un tono de frecuencia único.

Umbral Ajustable: La distancia de detección se calibra mediante hardware (potenciómetro) sin necesidad de reprogramar.

Monitoreo Serial: Visualización en tiempo real de distancias y valores de control en el computador.

-Componentes Necesarios

Arduino Nano(1)-Microcontrolador principal.
HC-SR04(3)-Sensores de distancia ultrasónicos.
Buzzer Pasivo(1)-Generador de tonos de alerta.
Potenciómetro(1)-Resistencia variable de 10k ohmios.
Protoboard y Cables-Para realizar las conexiones.
Se icluye un Diagrama de Conexiones 

Sensores Ultrasónicos (3)
Sensor	Pin Trig (Emisor)	Pin Echo (Receptor)
Sensor 1	2	3
Sensor 2	4	5
Sensor 3	7	6
-Otros Periféricos
Buzzer: Pin Digital 8.

Potenciómetro: Pin Analógico A0.

Funcionamiento del Código
Cálculo de Distancia: Se utiliza la fórmula estándar distancia= 58/tiempo
?
  para convertir el tiempo de retorno del pulso ultrasónico a centímetros.

Ajuste de Sensibilidad: * POT: Lee el valor de A0 y lo mapea de 0 a 250 (usado para el Sensor 3).

POT2: Mapea el valor de A0 de 0 a 125 (usado para Sensores 1 y 2).

Lógica de Alerta:

Si un objeto entra en el rango definido por el potenciómetro, el buzzer suena y el Monitor Serial indica qué sensor se activó.

Se utiliza una estructura if-else if para priorizar las alertas (Sensor 1 > Sensor 2 > Sensor 3).

 Instrucciones de Uso
Conecta los componentes siguiendo la tabla de pines.

Carga el código a tu placa Arduino mediante el IDE oficial.

Abre el Monitor Serial (9600 baudios) para ver las lecturas.

Gira el potenciómetro para aumentar o disminuir la distancia a la que quieres que el sistema empiece a pitar.
