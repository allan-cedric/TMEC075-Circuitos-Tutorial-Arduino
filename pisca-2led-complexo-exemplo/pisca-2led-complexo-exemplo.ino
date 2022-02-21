/*
 * Pisca-pisca(Blink) com 2 LEDs de forma alternada.
 * A cada iteração, o LED verde pisca uma vez e o 
 * LED vermelho vai piscar uma vez a mais que da vez anterior
 */

const uint8_t pinoLEDvd = 12; //pino de saída digital que o led verde está conectado
const uint8_t pinoLEDvm = 13; //pino de saída digital que o led vermelho está conectado

unsigned int maxVm = 1;

void setup() {
  pinMode(pinoLEDvm, OUTPUT); // declare o led como o output
  pinMode(pinoLEDvd, OUTPUT); // declare o led como o output
}

void loop() {
  digitalWrite(pinoLEDvd, HIGH);  // liga o led verde
  delay(1000);                    // espera 1000 milisegundos
  digitalWrite(pinoLEDvd, LOW);   // desliga o led verde
  delay(1000);                    // espera 1000 milisegundos
  
  for (int i = 0; i < maxVm; i++){ // executa um for maxVm vezes,
    //inicialmente esse valor é 1,
    //mas ele é incrementado em +1
    //após a execução do for
    
    digitalWrite(pinoLEDvm, HIGH);  // liga o led vermelho
    delay(100);                     // espera 100 milisegundos
    digitalWrite(pinoLEDvm, LOW);   // desliga o led vermelho
    delay(100);                     // espera 100 milisegundos
  }
  maxVm++;  // aumenta o maxVm em 1 para que na próxima vez o led vermelho
            // pisque uma vez a mais do que a última
}
