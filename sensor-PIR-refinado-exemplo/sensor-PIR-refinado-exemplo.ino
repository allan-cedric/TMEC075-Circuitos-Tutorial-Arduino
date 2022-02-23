/*
 * Leitura refinada do sensor de movimento PIR
 * 
 * Fonte: https://create.arduino.cc/projecthub/Arnov_Sharma_makes/pir-motion-activated-led-284eda
 */

int calibrationTime = 30; // tempo de calibração do sistema

long unsigned int lowIn;

// quantidade de tempo que o sensor deve estar em LOW
// para que se assuma que o movimento parou
long unsigned int pause = 5000; // 5 segundos

boolean lockLow = true;
boolean takeLowTime;
int pirPin = 2; // pino do PIR
int RELAY = 11; // pino do LED

/////////////////////////////
//SETUP
void setup(){
  Serial.begin(9600);
  pinMode(pirPin, INPUT);
  pinMode(RELAY, OUTPUT);
  digitalWrite(pirPin, LOW);
  
  // calibração do sensor ao ambiente - sugerida no datasheet!
  Serial.print("calibrating sensor ");
  for(int i = 0; i < calibrationTime; i++){
    Serial.print(".");
    delay(1000);
  }
  Serial.println(" done");
  Serial.println("SENSOR ACTIVE");
  delay(50);
}

////////////////////////////
//LOOP
void loop(){
  if(digitalRead(pirPin) == HIGH){ // se o pino pir estiver HIGH,
    // tem movimento
    digitalWrite(RELAY, HIGH); // então o LED deve ser ligado
    
    if(lockLow){
      // espera uma transição para LOW até que seja feita a próxima mudança
      lockLow = false;
      Serial.println("---");
      Serial.print("motion detected at ");
      Serial.print(millis()/1000);
      Serial.println(" sec");
      delay(50);
    }
    takeLowTime = true;
  }

  if(digitalRead(pirPin) == LOW){ // se o pino pir estiver LOW,
    // não tem movimento
    digitalWrite(RELAY, LOW); // então o LED deve estar desligado
    
    if(takeLowTime){
      lowIn = millis();     // salvamos o tempo em que o sensor está em LOW
      takeLowTime = false;  // pegado no começo da fase do LOW
    }
    
    // se o sensor está em LOW por um tempo maior
    // que a pausa determinada o led desliga
    if(!lockLow && millis() - lowIn > pause){
      lockLow = true;
      Serial.print("motion ended at "); // output
      Serial.print((millis() - pause)/1000);
      Serial.println(" sec");
      delay(50);
    }
  }
}
