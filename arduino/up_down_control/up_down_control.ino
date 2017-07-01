uint8_t buf[8] = { 
  0 };   /* Keyboard report buffer */

#define BUT1_PIN 2 //sobe
#define BUT2_PIN 3 //desce

void setup() 
{
  Serial.begin(9600);
  pinMode(BUT1_PIN, INPUT);
  pinMode(BUT2_PIN, INPUT);
  
  digitalWrite(BUT1_PIN, 1);
  digitalWrite(BUT2_PIN, 1);

  delay(200);
}

void loop() 
{
  int state1 = digitalRead(BUT1_PIN);
  if (state1 != 1) {
    buf[2] = 81;   // up key
    Serial.write(buf, 8); // Send keypress
  } 

  int state2 = digitalRead(BUT2_PIN);
  if (state2 != 1) {
    buf[2] = 82;   // down key
    Serial.write(buf, 8); // Send keypress
  } 

  if (state1 == 1 && state2 == 1)
  {
    releaseKey();
  }
  
}

void releaseKey() 
{
  buf[0] = 0;
  buf[2] = 0;
  Serial.write(buf, 8); // Release key  
}
