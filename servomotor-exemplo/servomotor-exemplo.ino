/*
 * Teste de um servomotor
 */

#include <Servo.h> // inclusão da biblioteca Servo.h

const uint8_t pinoServo = 6;  // inicialização do pino digital do servo
Servo s;                      // inicialização do objeto "s" do tipo Servo
int pos;                      // variável posição do servo

void setup (){
  s.attach(pinoServo);  // utilização da função s.attach da biblioteca
                        // para definir pino digital 6 ao objeto "s"
  s.write(0);           // inicia o motor na posição 0◦
}

//void loop(){
//}

void loop(){
  // loop for: com posição de 0 (inicia sempre em 0!) até 180◦,
  // indo de grau em grau (pos++)
  for(pos = 0; pos < 180; pos++){
    s.write(pos); // usa função da biblioteca Servo.h para
                  // escrever a posição no servo
    delay(30);    // intervalo de 30ms entre cada mudança de posição
  }
  
  delay(3000); // espera 3 segundos quando chega na posição de 180◦
  
  // loop for: fazemos agora a volta do servo
  for(pos = 180; pos >= 0; pos--){
    s.write(pos);
    //delay(30);  // delay comentado -> Aqui o servo vai voltar
                  // na sua velocidade máxima,
                  // sem delay entre as mudanças de posição
  }
  
  delay(2000);  // espera 2 segundos quando chega na posição de 0◦
}
