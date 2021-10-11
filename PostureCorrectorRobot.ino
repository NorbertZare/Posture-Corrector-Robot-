#include <SPI.h>
#include <Wire.h>
#include <Servo.h>
#define MPU 0x68  // I2C address of the MPU-6050

Servo ServoA, ServoB;
double AcX, AcY, AcZ;
int Pitch, Roll;
int a=0;
int i;
int ll;
void setup() {
  Serial.begin(9600);
  ServoA.attach(8);
  ServoB.attach(9);
  init_MPU(); // Inizializzazione MPU6050
}

void loop()
{

if (a==0)
{
  a=1;

ServoA.write(100);
delay(2000);
ServoB.write(175); 
delay(2000); 

}
  
  FunctionsMPU(); // Acquisisco assi AcX, AcY, AcZ.

  Roll = FunctionsPitchRoll(AcX, AcY, AcZ);   //Calcolo angolo Roll
  Pitch = FunctionsPitchRoll(AcY, AcX, AcZ);  //Calcolo angolo Pitch


 int ServoRoll;
 int ServoPitch;


  Serial.print("Roll: "); Serial.print(Roll);
  Serial.print("\n");


if (Roll>55)
{

for (i=175;i>=70;i--)
{
ServoB.write(i);
ll = map(i, 175, 70, 100, 50);
ServoA.write(ll);
delay(5);
}




delay(1000);


for (i=70;i<=175;i++)
{
ServoB.write(i);
ll = map(i, 70, 175, 50, 100);
ServoA.write(ll);
delay(5);
}


}




}

void init_MPU() {
  Wire.begin();
  Wire.beginTransmission(MPU);
  Wire.write(0x6B);  // PWR_MGMT_1 register
  Wire.write(0);     // set to zero (wakes up the MPU-6050)
  Wire.endTransmission(true);
  delay(1000);
}

//Funzione per il calcolo degli angoli Pitch e Roll
double FunctionsPitchRoll(double A, double B, double C) {
  double DatoA, DatoB, Value;
  DatoA = A;
  DatoB = (B * B) + (C * C);
  DatoB = sqrt(DatoB);

  Value = atan2(DatoA, DatoB);
  Value = Value * 180 / 3.14;

  return (int)Value;
}

//Funzione per l'acquisizione degli assi X,Y,Z del MPU6050
void FunctionsMPU() {
  Wire.beginTransmission(MPU);
  Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
  Wire.endTransmission(false);
  Wire.requestFrom(MPU, 6, true); // request a total of 14 registers
  AcX = Wire.read() << 8 | Wire.read(); // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)
  AcY = Wire.read() << 8 | Wire.read(); // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
  AcZ = Wire.read() << 8 | Wire.read(); // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
}
