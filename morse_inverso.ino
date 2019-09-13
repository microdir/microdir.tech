void setup() {
  pinMode(10, INPUT_PULLUP);
  Serial.begin(9600);
}
unsigned long tempo=0, tempo_inicial = 0, temp;
int estado = 0;
void loop() {
  tempo = millis();
  if(digitalRead(10) == 0 && estado == 0){
     estado = 1;
     tempo_inicial = tempo;
  }

  if(digitalRead(10) == 0 && estado == 1){
    temp = (tempo - tempo_inicial);
    Serial.println(temp);
    if(temp <= 150){
      Serial.print("curto");
      estado = 2;
      tempo_inicial = tempo;
    } else {
      Serial.print("longo");
      estado = 3;
      tempo_inicial = tempo;
    }
  }

  if(estado == 2){
    if(digitalRead(10) == 0){
      estado = 4;
      tempo_inicial = tempo;
    }
  }

  if(estado == 3){
    if(digitalRead(10) == 0){
      estado = 5;
      tempo_inicial = tempo;
    }
  }

  if(digitalRead(10) == 0 && estado == 4){ //curto antes
    temp = (tempo - tempo_inicial);
    Serial.println(temp);
    if(temp <= 150){
      Serial.print("curto");
      estado = 2;
      tempo_inicial = tempo;
    } else {
      Serial.print("longo");
      estado = 3;
      tempo_inicial = tempo;
    }
  }

  if(digitalRead(10) == 0 && estado == 4){ //longo antes
    temp = (tempo - tempo_inicial);
    Serial.println(temp);
    if(temp <= 150){
      Serial.print("curto");
      estado = 2;
      tempo_inicial = tempo;
    } else {
      Serial.print("longo");
      estado = 3;
      tempo_inicial = tempo;
    }
  }
  
}
