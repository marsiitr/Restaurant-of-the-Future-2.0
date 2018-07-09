//void driveStraightDistance(int distance, int Rspeed , int cal_Lspeed , int cal_Rspeed)
//{
//  //This will count up the total encoder ticks despite the fact that the encoders are constantly reset.
//  int netdistance = 0;
//  int netspeed = 0;
//  unsigned long inptime;
//  unsigned long outtime;
//  //Initialise slavePower as masterPower - 5 so we don't get huge error for the first few iterations. The
//  //-5 value is based off a rough guess of how much the motors are different, which prevents the robot from
//  //veering off course at the start of the function.
//  int Lspeed = Rspeed - 5;
//
//  int error = 0;
//
//  int kp = 5;
//
//  //Monitor 'totalTicks', instead of the values of the encoders which are constantly reset.
//  while ( netdistance < distance)
//  {
//    inptime = millis();
//    //Proportional algorithm to keep the robot going straight.
//    digitalWrite(Rin1, HIGH);
//    digitalWrite(Rin2, LOW);
//    analogWrite(Rmotorpwm, Rspeed);
//
//    digitalWrite(Lin1, HIGH);
//    digitalWrite(Lin2, LOW);
//    analogWrite(Lmotorpwm, Lspeed);
//
//    
//    if(cal_Lspeed>cal_Rspeed)
//    {
//      error = cal_Lspeed - cal_Rspeed;
//      Rspeed = Rspeed + (error / kp);
//    }
//
//     
//    if(cal_Rspeed>cal_Lspeed)
//    {
//      error = cal_Rspeed - cal_Lspeed;
//      Lspeed = Lspeed + (error / kp);
//    }
//
//    
//
//    delay(100);
//
//    //Add this iteration's encoder values to totalTicks.
//
//    netspeed = (cal_Rspeed + cal_Lspeed) / 2;
//
//    outtime = millis();
//    netdistance = netdistance + netspeed * (outtime - inptime);
//  }
//  analogWrite(Rmotorpwm, 0);
//  analogWrite(Lmotorpwm, 0);
//}
