//these pins can not be changed 2/3 are special pins


//For right motor
int Rmotorpwm = 7;
int Rin1 = 30;
int Rin2 = 32;

void setup() {
  Serial.begin (9600);

 



  // set all the motor control pins to outputs
 
  pinMode(Rmotorpwm, OUTPUT);
 
  pinMode(Rin1, OUTPUT);
  pinMode(Rin2, OUTPUT);

}

void loop() {
     digitalWrite(Rin1, HIGH);
    digitalWrite(Rin2, LOW);
    analogWrite(Rmotorpwm,100);
  delay(1000); //just here to slow down the output, and show it will work  even during a delay
}



