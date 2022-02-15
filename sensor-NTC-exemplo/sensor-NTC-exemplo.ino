// NTC_Thermistor by Yurii Salimov (Version 2.0.3)

#include <Thermistor.h>
#include <NTC_Thermistor.h>

const uint8_t pinoTermistor = A1; // Pino analógico A0
const int resExterna = 10000;     // Resistor externo
const int resNominal = 10000;     // Resistência nominal do termistor
const int tempNominal = 25;       // Temperatura nominal do termistor
const int valorBeta = 4100;       // Valor beta do termistor (Relação entre resistência e temperatura)

// Instância de um termistor
NTC_Thermistor termistor(pinoTermistor, resExterna, resNominal, tempNominal, valorBeta); 

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  double temperaturaCelsius = termistor.readCelsius(); // Leitura do termistor

  Serial.print("Temperatura: ");
  Serial.print(temperaturaCelsius);
  Serial.println("°C");
  delay(100);
}
