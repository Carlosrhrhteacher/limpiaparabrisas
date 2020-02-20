 #define PIN_ANALOG_RAIN_SENSOR A0  // Entrada analógica para la señal del sensor lluvia
#include <Servo.h>

Servo servo;
Servo servo2; // Crea un objeto servo para controlar el servomotor
const int potpin = A0; // Pin analógico usado para conectar el potenciómetro
char val; //variable donde se almacena el caracter introducido por pantalla a través del monitor serial
int valorLectura = 0;  // variable para almacenar el valor leido desde el potenciometro


void setup() {
  
  Serial.begin(9600);        // abrimos el puerto serial para leer los datos del sensor de lluvia
  servo.attach(9);           // declaramos los servomotores
  servo2.attach(8); 


  
}
void loop() {
  // leemos el valor del potenciometro
//  valorLectura = analogRead(PIN_ANALOG_RAIN_SENSOR);  
  
   Serial.print("Analog value: "); 
   Serial.println( valorLectura); // Salida de valor analógico al monitor serial

 while ((valorLectura=analogRead(PIN_ANALOG_RAIN_SENSOR)) >= 100)
 {
 servo2.write(40);
 servo.write(40);
 delay(350);
 servo.write(130);
 servo2.write(130);
 delay(350);
 
 }
 
   
 
  delay(500);                  
} 
