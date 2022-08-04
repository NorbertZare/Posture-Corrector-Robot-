# Posture-Corrector-Robot-
Posture Corrector Robot 
Most of the posture corrector devices aren't fun
so I built a posture corrector robot ;)

in this project I used an Arduino Uno , mpu6050 and 2 servo Motors.
mpu6050 sensor attaches to a person and when he/she hunch The robot arm corrects the person's posture.

MPU-6050 is a low-cost, highly accurate inertial measurement unit (IMU) with six degrees of freedom (DOF). IMUs can measure acceleration, inertia and a number of other parameters to allow you to determine their spatial position and velocity.
MPU-6050 is capable to send data in i2c protocol. (SCL & SDA pins)

SG90 is a 180° rotation servo. Servo motors works on PWM (Pulse Width Modulation) signal.

mpu6050 sensor attaches to person shoulder and when he/she hunch , roll variable gets more than than 55 degree so Arduino sends signal to the servos to raises the robot arm and corrects the person posture. And after 1 second goes back to first position.

YouTube Video:
https://youtu.be/K1aP64ZNP6A
