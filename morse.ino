void setup() {
  pinMode(8, OUTPUT);
  Serial.begin(9600);
}
unsigned long tempo_inicial = 0;
unsigned long tempo = 0;
String estado = " ";
int index = 0;
int tamanhoEntrada = 0;
unsigned long temp;
void loop() {
  if(Serial.available() > 0){
    estado = Serial.readString();
    tamanhoEntrada = estado.length();  
  }
  Serial.println(estado);
  tempo = millis();
  if(estado.charAt(index) == 'a'){
     temp = (tempo - tempo_inicial);
     if(temp < 100){
        digitalWrite(8, HIGH); 
     } else if(temp >= 100 && temp < 200){
        digitalWrite(8, LOW); 
     } else if(temp >= 200 && temp < 500){
        digitalWrite(8, HIGH);
     } else if(temp >= 500 && temp < 1000){
        digitalWrite(8, LOW);
     } else {
        tempo_inicial = tempo;
        index += 1;
        if(index == (tamanhoEntrada-1)){
          index = 0;
        }
     }
  } else if(estado.charAt(index) == 'e'){
     temp = (tempo - tempo_inicial);
     if(temp < 100){
        digitalWrite(8, HIGH); 
     } else if(temp >= 100 && temp < 600){
        digitalWrite(8, LOW); 
     } else {
        tempo_inicial = tempo;
        index += 1;
        if(index == (tamanhoEntrada-1)){
          index = 0;
        }
     }
  } else if(estado.charAt(index) == 'i'){
     temp = (tempo - tempo_inicial);
     if(temp < 100){
        digitalWrite(8, HIGH); 
     } else if(temp >= 100 && temp < 200){
        digitalWrite(8, LOW); 
     } else if(temp >= 200 && temp < 300){
        digitalWrite(8, HIGH); 
     } else if(temp >= 300 && temp < 800){
        digitalWrite(8, LOW); 
     } else {
        tempo_inicial = tempo;
        index += 1;
        if(index == (tamanhoEntrada-1)){
          index = 0;
        }
     }
  } else if(estado.charAt(index) == 'o'){
     temp = (tempo - tempo_inicial);
     if(temp < 300){
        digitalWrite(8, HIGH); 
     } else if(temp >= 300 && temp < 400){
        digitalWrite(8, LOW); 
     } else if(temp >= 400 && temp < 700){
        digitalWrite(8, HIGH); 
     } else if(temp >= 700 && temp < 800){
        digitalWrite(8, LOW); 
     } else if(temp >= 800 && temp < 1100){
        digitalWrite(8, HIGH); 
     } else if(temp >= 1100 && temp < 1600){
        digitalWrite(8, LOW); 
     } else {
        tempo_inicial = tempo;
        index += 1;
        if(index == (tamanhoEntrada-1)){
          index = 0;
        }
     }
  } else if(estado.charAt(index) == 'u'){
     temp = (tempo - tempo_inicial);
     if(temp < 100){
        digitalWrite(8, HIGH); 
     } else if(temp >= 100 && temp < 200){
        digitalWrite(8, LOW); 
     } else if(temp >= 200 && temp < 300){
        digitalWrite(8, HIGH); 
     } else if(temp >= 300 && temp < 400){
        digitalWrite(8, LOW); 
     } else if(temp >= 400 && temp < 700){
        digitalWrite(8, HIGH); 
     } else if(temp >= 700 && temp < 1200){
        digitalWrite(8, LOW); 
     } else {
        tempo_inicial = tempo;
        index += 1;
        if(index == (tamanhoEntrada-1)){
          index = 0;
        }
     }
  } else {
    tempo_inicial = tempo;
    digitalWrite(8, LOW);
  }
}
