/*
 * Teste de leitura do sensor de temperatura NTC
 * 
 * REQUISITOS: Biblioteca Thermistor -> http://storage.ning.com/topology/rest/1.0/file/get/1798908730?profile=original
 * Passos: Sketch -> Incluir Biblioteca -> Adicionar biblioteca .ZIP
 */

#include <Thermistor.h> // inclusão da biblioteca Thermistor.h

Thermistor temp(A1);  // criação de variável do tipo Thermistor
                      // inicia ela no pino analógico A0

void setup() {
  Serial.begin(9600); // inicializando a porta serial
}

void loop() {
  int temperature = temp.getTemp(); // leitura do valor de temperatura com
                                    // função da biblioteca Thermistor
                                    // valores padrão para NTC 10kohm
  
  Serial.print("Temperatura: ");  // imprime um texto no monitor serial
  Serial.print(temperature);      // imprime o valor da temperatura lido
  Serial.println("*C");
  delay(1000);                    //Intervalo de medição
}
