void cal_Speed()
{



if(millis()-inptime>=1)
{
  nextValue=LencoderValue;
cal_Lspeed=(nextValue-preValue)/4;
  preValue=nextValue;
 
inptime=millis();
}
 Serial.print("\t");
 Serial.print(cal_Lspeed);

}

