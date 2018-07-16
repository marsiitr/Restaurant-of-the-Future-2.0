
void updateLencoder() {

  //For left encoder
  int LMSB = digitalRead(LencoderPin1); //MSB = most significant bit
  int LLSB = digitalRead(LencoderPin2); //LSB = least significant bit

  int Lencoded = (LMSB << 1) | LLSB; //converting the 2 pin value to single number
  int Lsum  = (LlastEncoded << 2) | Lencoded; //adding it to the previous encoded value

  if (Lsum == 13 || Lsum == 4 || Lsum == 2 || Lsum == 11) LencoderValue ++;
  if (Lsum == 14 || Lsum == 7 || Lsum == 1 || Lsum == 8) LencoderValue --;

  LlastEncoded = Lencoded; //store this value for next time
}

void updateRencoder() {
  //For right encoder
  int RMSB = digitalRead(RencoderPin1); //MSB = most significant bit
  int RLSB = digitalRead(RencoderPin2); //LSB = least significant bit

  int Rencoded = (RMSB << 1) | RLSB; //converting the 2 pin value to single number
  int Rsum  = (RlastEncoded << 2) | Rencoded; //adding it to the previous encoded value

  if (Rsum == 13 || Rsum == 4 || Rsum == 2 || Rsum == 11) RencoderValue ++;
  if (Rsum == 14 || Rsum == 7 || Rsum == 1 || Rsum == 8) RencoderValue --;
  RlastEncoded = Rencoded; //store this value for next time
}
