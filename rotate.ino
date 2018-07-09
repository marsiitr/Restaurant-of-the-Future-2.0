void rotate()
{
  digitalWrite(Rmotorpin, HIGH);
  analogWrite(Rmotorpwm, 180 );
  digitalWrite(Lmotorpin, LOW);
  analogWrite(Lmotorpwm, 180);
}
void stall()
{
  digitalWrite(Rmotorpin, HIGH);
  analogWrite(Rmotorpwm, 0);
  digitalWrite(Lmotorpin, LOW);
  analogWrite(Lmotorpwm, 0);
}
void rotate_opp()
{
  digitalWrite(Rmotorpin, LOW);
  analogWrite(Rmotorpwm, pwm);
  digitalWrite(Lmotorpin, HIGH);
  analogWrite(Lmotorpwm, pwm);
}
void str()
{
  //  Serial.print("Rspeed   ");
  //  Serial.print(Rspeed);
  //  Serial.print("\t");
  //  Serial.print("Lspeed    ");
  //  Serial.print(Lspeed);
  //  Serial.print("\t");
  digitalWrite(Rmotorpin, LOW);
  analogWrite(Rmotorpwm, Rspeed);
  digitalWrite(Lmotorpin, LOW);
  analogWrite(Lmotorpwm, Lspeed );

}
void pwmrotate(int theta)
{
  if (angle_deg <= 10 && angle_deg >= 0)
    pwm = 170 + 5 * angle_deg;

  if (angle_deg >= (theta - 10))
    pwm = 220 - 5 * (theta - angle_deg);
}



