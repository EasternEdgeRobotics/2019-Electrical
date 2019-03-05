/*************************************/
/*-----------------------------------*/
/********Tooling Embedded Code********/
/*****Eastern Edge Robotics 2019******/
/*-----------------------------------*/
/*************************************/

//Contributers: David Drover

#include <Adafruit_Sensor.h> //imu
#include <Adafruit_BNO055.h> //imu
#include <utility/imumaths.h> //pressure
#include "MS5837.h" //pressure
#include <OneWire.h> //Temperature
#include <DallasTemperature.h>//Temperature
#include <Wire.h> //i2c
#include "wiring_private.h" //i2c

//Pin Definitions
#define VMetal 4
#define VPH 5
#define TempData 10
#define EnableA1 9
#define DirA1 14
#define EnableA2 15
#define DirA2 17
#define EnableB1 8
#define DirB1 16
#define EnableB2 19
#define DirB2 28
#define LED 18
#define LED_IN 11
#define SCL_Pin 23
#define SDA_Pin 22


int motors[4] = {EnableA1, EnableA2, EnableB1, EnableB2};
int dirControl[4] = {DirA1, DirA2, DirB1, DirB2};
int id;
int dir, dir1, dir2, dir3, dir4; 
int duty, duty1, duty2, duty3, duty4;
int LedDuty;
int sensors = 0;
imu::Vector<3> euler;
imu::Vector<3> accel;
float Temp;
char buf[90];
char hold;
int x;

//Define one wire comunication
OneWire oneWire(TempData);

//Define temperature sensor
DallasTemperature temp(&oneWire);

//Define I2C Wire
TwoWire myWire(&sercom3, SDA_Pin, SCL_Pin);

//Define pressure sensor
MS5837 sensor;

//Define Gyro sensor
Adafruit_BNO055 bno = Adafruit_BNO055();

void returnImuPressureData(int mode = 1);
void changeMotor(int motorNum, int dir, int duty);
void Led(int duty);
void returnSensorData(void);
float calculateTemp(void);
int metal(void);
float ph(void);


void setup(void) 
{

  analogReadResolution(12); // sets the ADC to 12 bit mode
  
  Serial.begin(115200);

  myWire.begin();

  pinPeripheral(SDA_Pin, PIO_SERCOM);
  pinPeripheral(SCL_Pin, PIO_SERCOM);  

  sensor.init();
  sensor.setModel(MS5837::MS5837_02BA);
  sensor.setFluidDensity(997);
  
  bno.begin();

  temp.begin();

  //Setup pins
  pinMode(VMetal, INPUT); 
  pinMode(VPH, INPUT); 
  pinMode(TempData, INPUT); 
  pinMode(EnableA1, OUTPUT);
  pinMode(DirA1, OUTPUT);
  pinMode(EnableA2, OUTPUT);
  pinMode(DirA2, OUTPUT);
  pinMode(EnableB1, OUTPUT);
  pinMode(DirB1, OUTPUT);
  pinMode(EnableB2, OUTPUT);
  pinMode(DirB2, OUTPUT);
  pinMode(LED, OUTPUT);
  pinMode(LED_IN, OUTPUT);
  
  //ensure nothing run from not being set
  for(int i = 1; i<=4; i++)
  {
    changeMotor(i, 1, 0);
  }
  Led(0);
  for(int i = 0; i < 90; i++)
  {
    buf[i]= ',';
  }
}

void loop(void) 
{
  //waiting for a serial write
  hold = Serial.read();
  while(hold == -1)
  {
    if(sensors == 1)
    {
      returnImuPressureData(2);
    }else{
      returnImuPressureData();
    }
    hold = Serial.read();
  }
  
  
  //serial reading code
  buf[0] = hold;
  x = 1;
  while(x <= 30 and hold != -1)
  {
    delay(4);
    hold = Serial.read();
    while( x == 0 and hold == -1)
    {
      hold = Serial.read();
    }
    buf[x] = hold;
    x++;
  }

  //decides how to read the input and does the action
  if(buf[2] == 'm' and buf[7] == '1')
  {
    sscanf(buf, "{ motor1:%d, %d, motor2:%d, %d, motor3:%d, %d, motor4:%d, %d, LED:%d, sensorsreading:%d }", &dir1, &duty1, &dir2, &duty2, &dir3, &duty3, &dir4, &duty4, &LedDuty, &sensors);
    changeMotor(1, dir1, duty1);
    changeMotor(2, dir2, duty2);
    changeMotor(3, dir3, duty3);
    changeMotor(4, dir4, duty4);
    Led(LedDuty);
  }else if(buf[2] == 'm'){
    sscanf(buf, "{ motor:%d, %d, %d }", &id, &dir, &duty);
    changeMotor(id, dir, duty);
  }else if(buf[2] == 'L'){
    sscanf(buf, "{ LED:%d }", &LedDuty);
    Led(LedDuty);
  }else if(buf[2] == 's'){
    sscanf(buf, "{ sensorsreading:%d }", &sensors);
  }else{
    sscanf(buf, "%d,%d,%d,%d,%d,%d,%d,%d,%d,%d", &dir1, &duty1, &dir2, &duty2, &dir3, &duty3, &dir4, &duty4, &LedDuty, &sensors);
    changeMotor(1, dir1, duty1);
    changeMotor(2, dir2, duty2);
    changeMotor(3, dir3, duty3);
    changeMotor(4, dir4, duty4);
    Led(LedDuty);
  }
}

//prints out imu and pressure sensors data
void returnImuPressureData(int mode)
{
  sensor.read();
  euler = bno.getVector(Adafruit_BNO055::VECTOR_EULER);
  accel = bno.getVector(Adafruit_BNO055::VECTOR_ACCELEROMETER);
  Temp = bno.getTemp();

  //Serial.print("Pressure:"); 
  Serial.print(sensor.pressure()); 
  
  //Serial.print(", TemperaturePS:"); 
  Serial.print(",");
  Serial.print(sensor.temperature()); 
 
  //Serial.print(", GyroX:");
  Serial.print(",");
  Serial.print(euler.x());
  
  //Serial.print(", GyroY:");
  Serial.print(",");
  Serial.print(euler.y());
  
  //Serial.print(", GyroZ:");
  Serial.print(",");
  Serial.print(euler.z());

  //Serial.print(", Accelx:");
  Serial.print(",");
  Serial.print(accel.x()); 

  //Serial.print(", Accely:");
  Serial.print(",");
  Serial.print(accel.y()); 

  //Serial.print(", Accelz:");
  Serial.print(",");
  Serial.print(accel.z()); 

  if(mode == 2)
  {
    //Serial.print(", TemperatureIMU:");
    Serial.print(",");
    Serial.print(Temp);
    returnSensorData();
  }else{
    //Serial.print(", TemperatureIMU:");
    Serial.print(",");
    Serial.println(Temp);
  }
}

//changes motor turn speed
void changeMotor(int motorNum, int dir, int duty)
{
  digitalWrite(dirControl[(motorNum - 1)], dir);
  analogWrite(motors[(motorNum - 1)], (255.0*(duty/100.0)));
}

//changes the brightness of the leds
void Led(int duty)
{
  analogWrite(LED, (255.0*(duty/100.0)));
}

//prints out ph, metal and tamperature sensor values
void returnSensorData(void)
{
  //Serial.print("temperature:");
  Serial.print(",");
  Serial.print(calculateTemp());

  //Serial.print(", Metal:");
  Serial.print(",");
  Serial.print(metal());

  //Serial.print(", PH:");
  Serial.print(",");
  Serial.println(ph());

}

//calculates temperature
float calculateTemp(void)
{
  temp.requestTemperatures();
  float temperature = temp.getTempCByIndex(0);
  return temperature;
}

//says if it is metal or not
int metal(void)
{
  if(analogRead(VMetal) > 2054)
  {
    return 1;
  }else{
    return 2;    
  }
}

//calculates ph level
float ph(void)
{
  int raw = analogRead(VPH);
  float ph = 3.5 * (raw * (3.3 / 4096.0)) ;
  return ph;
}
