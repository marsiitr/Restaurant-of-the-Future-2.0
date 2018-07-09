//these pins can not be changed 2/3 are special pins
int temp = 0; int flag1 = 1, flagr = 0, flag2 = 0;
long offset=0;
//For left encoder
int LencoderPin1 = 3;
int LencoderPin2 = 2;

volatile int LlastEncoded = 0;
volatile long LencoderValue = 0;
volatile long lLencoderValue = 0;

long LlastencoderValue = 0;
float cal_Lspeed = 0; //rpm speed

int LMSB = 0;
int LLSB = 0;

//For right encoder
int RencoderPin1 = 18;
int RencoderPin2 = 19;

volatile int RlastEncoded = 0;
volatile long RencoderValue = 0;

long RlastencoderValue = 0;
float cal_Rspeed = 0;

int RMSB = 0;
int RLSB = 0;
//bot Para
double wheel_dia = 9.5;
double wheel_dis = 57.0;

//normal decl
double lenc_reading = 0.0, renc_reading = 0.0, diff_lenc = 0.0, diff_renc = 0.0, prev_lenc_reading = 0.0, prev_renc_reading = 0.0, theta = 0.0, angle = 0.0, dx = 0.0, dy = 0.0, x = 0.0, y = 0.0, angle_deg = 0.0;
//new dec
double kp = 0.5, kd = 0.3, ki = 0.0;
double kp_dis_or  = 3, kd_dis_or  = 0.5, ki_dis_or  = 0.0;
double kdis = 0.6, kor = 0.4;
double error = 0.0, diff_error = 0.0, sum_error = 0.0, prev_error = 0.0;
double error_dis_or = 0.0, error_or = 0.0, error_dis = 0.0, diff_error_dis_or = 0.0, sum_error_dis_or = 0.0, prev_error_dis_or = 0.0;
double correction = 0.0;
double correction_dis_or = 0.0;
int pwm = 170;
int Lspeed = 0, Rspeed = 0;


//For left motor
int Lmotorpwm = 8;
int Lmotorpin = 30;

//For right motor
int Rmotorpwm = 9;
int Rmotorpin = 34;

unsigned long inptime = 0;
unsigned long outtime = 0;
int prev_LencoderValue = 0;

long preValue_L = 0;
long nextValue_L = 0;
long preValue_R = 0;
long nextValue_R = 0;

//void updateEncoder();

void setup() {
  Serial.begin (9600);

  //For left encoder
  pinMode(LencoderPin1, INPUT);
  pinMode(LencoderPin2, INPUT);

  digitalWrite(LencoderPin1, HIGH); //turn pullup resistor on
  digitalWrite(LencoderPin2, HIGH); //turn pullup resistor on

  //call updateEncoder() when any high/low changed seen
  //on interrupt 0 (pin 2), or interrupt 1 (pin 3)
  attachInterrupt(0, updateLencoder, CHANGE);
  attachInterrupt(1, updateLencoder, CHANGE);


  // For right encoder
  pinMode(RencoderPin1, INPUT);
  pinMode(RencoderPin2, INPUT);

  digitalWrite(RencoderPin1, HIGH); //turn pullup resistor on
  digitalWrite(RencoderPin2, HIGH); //turn pullup resistor on

  //call updateEncoder() when any high/low changed seen
  //on interrupt 5 (pin 18), or interrupt 4 (pin 19)
  attachInterrupt(4, updateRencoder, CHANGE);
  attachInterrupt(5, updateRencoder, CHANGE);

  // set all the motor control pins to outputs
  pinMode(Lmotorpwm, OUTPUT);
  pinMode(Rmotorpwm, OUTPUT);
  pinMode(Lmotorpin, OUTPUT);
  pinMode(Rmotorpin, OUTPUT);


}

void loop()
{

  //  Serial.print(LMSB);
  //  Serial.print("\t");
  //  Serial.print(LLSB);
  //  Serial.print("\t");
  Serial.print(LencoderValue);

  //  Serial.print("\t");
  //  Serial.print(RMSB);
  //  Serial.print("\t");
  //  Serial.print(RLSB);
  Serial.print("\t");
  Serial.print(RencoderValue);
  Serial.print("\t");
  pid();
 // pid2();

  printval();
  // str();

  if (flag1 )
  {
    if (y < 200)
    {
      if (y <= 10 && y >= 0)
      {
        pwm = 170 + 5 * y;
      }

      if (y >= 190)
      {
        pwm = 220 - 5 * (y - 190);

      }
      str();
      //Serial.println("str");
    }

    if (y >= 200)
    {
      flagr = 1;
      flag1 = 0;
       Serial.println("Rotating");
    }
  }
  if (flagr)
  {
    if (angle_deg <= 95 && angle_deg >= -95)
    {
      //pwm = 170;
      pwmrotate(95);
      rotate();
      //Serial.println(pwm);
    }
    if ((angle_deg >= 95 && angle_deg >= -95))
    {
      flagr = 0;
      flag2 = 1;
      offset=LencoderValue-RencoderValue;
       Serial.println("Straight");

    }
  }
  if (flag2)
  {
    if (x < 200)
    {
      if (x <= 10)
        pwm = 170 + 5 * x;


      if (x >= 190)
      {
        pwm = 220 - 5 * (x - 90);

      }
      str();
    }

    if (x >= 200 )
    {
      flag2 = 0;
      stall();
    }
  }

}
