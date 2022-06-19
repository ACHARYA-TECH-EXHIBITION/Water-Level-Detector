int analogInPin = A5;
int buzzer = 6; //BUZZER
int relay = 10;
int stopLed = 11;
bool isActive = false;

int resval = 0;

void setup() {
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
  pinMode(relay, OUTPUT);
  pinMode(2, INPUT);
  pinMode(11, OUTPUT);

}

void work() {
  resval = analogRead(analogInPin);

  if (resval <= 100) {
    Serial.println("Empty ");
    digitalWrite(buzzer, LOW);
    digitalWrite(relay, LOW);

  } else if (resval > 100 && resval <= 300) {
    Serial.println("Low ");
    digitalWrite(buzzer, LOW);
    digitalWrite(relay, LOW);

  } else if (resval > 300 && resval <= 330) {
    Serial.println("Medium ");
  } else if (resval > 330) {
    Serial.println("High");

    digitalWrite(buzzer, HIGH);
    digitalWrite(relay, HIGH);

  }
}

void loop() {

  if (digitalRead(2) == HIGH) {
    Serial.print("Touched");
    if (isActive) {
      //START ALL FUNCTIONS
      isActive = false;
    } else {
      //CLOSE WORKING
      isActive = true;
    }
  }

  if (!isActive) {
    digitalWrite(stopLed,LOW);
    work();
  }else{
     digitalWrite(buzzer, LOW);
    digitalWrite(relay, HIGH);
    digitalWrite(11,HIGH);
  }

  delay(1000);
}
