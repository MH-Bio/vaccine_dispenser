int Relay = 4;    

void setup() {
  Serial.begin(57600);   
  pinMode(6, INPUT_PULLUP);         //Set Pin6 as output    
  pinMode(Relay, OUTPUT);     
} 
void loop() {
  int singal=digitalRead(6);
  Serial.println(singal);           
  digitalWrite(Relay, HIGH);           
  delay(2000);
  digitalWrite(Relay, LOW);             
  delay(2000);

} 
