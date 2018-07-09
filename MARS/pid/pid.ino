void pid()
{
  cal_dis();
  error = LencoderValue - RencoderValue - offset;
//  Serial.print("\t");
//  Serial.print("error    ");
//  Serial.print(error);
//  Serial.print("\t");
  error = error / 5;

  diff_error = error - prev_error;
  correction = kp * error + kd * diff_error + ki * sum_error;

  if (correction > 50)
    correction = 50;
  if (correction < -50)
    correction = -50;
  Lspeed = pwm - correction;
  Rspeed = pwm + correction;
  //  Serial.print("correction    ");
  //  Serial.print(correction);
  //  Serial.print("\t");
  //str();
  prev_error = error;

}
void cal_dis()
{

  lenc_reading = (LencoderValue) * (wheel_dia * PI) / 2400;                                      //lenc_reading in mm
  renc_reading = (RencoderValue) * (wheel_dia * PI) / 2400;                                              //renc_reading in mm
  diff_lenc = lenc_reading - prev_lenc_reading;
  diff_renc = renc_reading - prev_renc_reading;
  theta = atan2((diff_lenc - diff_renc), wheel_dis);
  angle += theta;
  dx = (diff_lenc + diff_renc) * sin(angle) * 0.5;
  x += dx;
  dy = (diff_lenc + diff_renc) * cos(angle) * 0.5;
  y += dy;
  prev_lenc_reading = lenc_reading;
  prev_renc_reading = renc_reading;
  angle_deg = angle * 57.3;
}


void pid2()
{
  cal_dis();
  error_dis = x;
  error_or = angle_deg;
  error_dis_or = kdis * error_dis + kor * error_or;


  diff_error_dis_or = error_dis_or - prev_error_dis_or;
  correction_dis_or = kp_dis_or * error_dis_or + kd_dis_or * diff_error_dis_or + ki_dis_or * sum_error_dis_or;


  if (correction_dis_or > 30)
    correction_dis_or = 30;
  if (correction_dis_or < -30)
    correction = -30;
  Lspeed = Lspeed - correction_dis_or;
  Rspeed = Rspeed + correction_dis_or;
  Serial.print("\t");
  Serial.print(correction_dis_or);
  Serial.print("\t");
  prev_error_dis_or = error_dis_or;
}
