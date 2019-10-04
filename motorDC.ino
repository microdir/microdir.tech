void setup() {
  pinMode(8, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(7, INPUT_PULLUP);
  pinMode(A0, INPUT);
  Serial.begin(9600);
}

int apertado;
int estado = 0;
int botao;
int poten;
void loop() {
  botao = digitalRead(7);
  poten = map(analogRead(A0), 0, 1023, 0, 255);
  analogWrite(11,poten);
  if(botao==0){
    digitalWrite(8, LOW);
    delay(1000);
    digitalWrite(10, HIGH);    
  } else if(botao==1){
    digitalWrite(10, LOW);
    delay(1000);
    digitalWrite(8, HIGH);    
  }
  
}
