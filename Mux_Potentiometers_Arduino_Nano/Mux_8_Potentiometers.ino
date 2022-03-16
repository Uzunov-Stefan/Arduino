int pinOutS0 = 8;
int pinOutS1 = 9;
int pinOutS2 = 10;
int pinInMux = A0;
int MuxState[8] = {0};

void setup() {
    pinMode(pinOutS0, OUTPUT);
    pinMode(pinOutS1, OUTPUT);
    pinMode(pinOutS2, OUTPUT);

    Serial.begin(9600);
}

void loop() {
  updateMux1();
  for(int i=0;i<8;i++){
    if(i==7){
      Serial.println(MuxState[i]);
    }
    else{
      Serial.print(MuxState[i]);
      Serial.print(", ");
    }
  }
}

void updateMux1(){
  for(int i=0; i<8; i++){
    digitalWrite(pinOutS0, HIGH && (i & B00000001));
    digitalWrite(pinOutS1, HIGH && (i & B00000010));
    digitalWrite(pinOutS2, HIGH && (i & B00000100));
    MuxState[i] = analogRead(pinInMux);
  }
}
