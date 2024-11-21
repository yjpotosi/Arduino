// ESP32 Touch Test
// Just test touch pin - Touch0 is T0 which is on GPIO 4.
const int PINLED = 2;
int sensor;
int ledEncendido; // 1 Encendido 0 Apagado 
void setup() {
  Serial.begin(115200);  //baudio
  delay(1000); // give me time to bring up serial monitor
  Serial.println("ESP32 Touch Test");
  pinMode(PINLED, OUTPUT);
}

void loop() {
  sensor = touchRead(T0);

  if (sensor < 30 ){
    //Encender led 
    if(ledEncendido == 1){
      // Encendido, hay que apagarlo 
      digitalWrite(PINLED, LOW);
      ledEncendido = 0;
    }
    else{
      //Apagado, hay que encenderlo 
      digitalWrite(PINLED, HIGH);
      ledEncendido = 1;   
    }
    delay(200);

  }
  Serial.println(); // get value using T0
  delay(200);

}
