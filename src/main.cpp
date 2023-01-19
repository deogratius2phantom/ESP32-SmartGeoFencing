// file IMUClassify.ino
#include <Arduino.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <ArduinoJson.h>
#include <Wire.h>
#include <SPI.h>
#include <LoRa.h>
#include <TinyGPS++.h>
#include "Pipeline.h"
#include "Classifier.h"
#define SCK 5
#define MISO 19
#define MOSI 27
#define SS 18
#define RST 14
#define DIO0 26
#define BAND 866E6
#define RXD2 16
#define TXD2 17
Adafruit_MPU6050 mpu;
TinyGPSPlus gps;
uint8_t GPS_SWITCH =4;
uint8_t counter=0,idleTimeCount=0;
uint32_t stepCount=0,latency=0;
TaskHandle_t Task1;
TaskHandle_t Task2;
void Task2code( void * pvParameters );
void Task1code( void * pvParameters );
SemaphoreHandle_t SerialMutex;
sensors_event_t acc,gyro,temp;
String predictedGuesture=" ";
void setup() {
  //Serial.begin(115200);
  StaticJsonDocument<200> doc;
  Serial.begin(1500000);
  SerialMutex=xSemaphoreCreateMutex();
  if(SerialMutex==NULL)
  {
    Serial.println(F("Mutex creation failed"));
  }
  if(mpu.begin())
  {
   // Serial.println(F("IMU initialized on i2c interface"));
    xSemaphoreTake(SerialMutex,portMAX_DELAY);
    Serial.println("initialized IMU successfuly");
    xSemaphoreGive(SerialMutex);
    mpu.setAccelerometerRange(MPU6050_RANGE_16_G);
    mpu.setGyroRange(MPU6050_RANGE_2000_DEG);
    mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);

    mpu.setHighPassFilter(MPU6050_HIGHPASS_0_63_HZ);
    mpu.setMotionDetectionThreshold(10);
    mpu.setMotionDetectionDuration(20);
    mpu.setInterruptPinLatch(true);	// Keep it latched.  Will turn off when reinitialized.
    mpu.setInterruptPinPolarity(true);
    mpu.setMotionInterrupt(true);
    
  }
  else{
    //Serial.println(F("Fialed to detect IMU, proceeding to scan i2c bus "));
  }
  xTaskCreatePinnedToCore(Task1code,"Task 1",1000,NULL,1,NULL,0);
  xTaskCreatePinnedToCore(Task2code,"Task 2",1000,NULL,1,NULL,0);
}

void loop() {
  /*
  default task that runns on core 0, sampling the MPU6050 IMU for readings
  a)acceleration in x,y,z
  b)angular acceleration in rads x,y,z (gyroscope readings)
  c)pitch and roll.
  */
  mpu.getEvent(&acc,&gyro,&temp);
  if(mpu.getMotionInterruptStatus())
  {
    mpu.getEvent(&acc,&gyro,&temp);
    xSemaphoreTake(SerialMutex,portMAX_DELAY);
    //Serial.println(F("motion detected"));
    //Serial.println(mpu.getMotionInterruptStatus());
    xSemaphoreGive(SerialMutex);
  }
  /*run the model on the just read parameters to predict the guesture ffrom training*/
  float features[]={acc.acceleration.x,acc.acceleration.y,acc.acceleration.z,gyro.gyro.x,gyro.gyro.y,gyro.gyro.z,acc.acceleration.pitch,acc.acceleration.roll};
  if (!pipeline.transform(features))
    return;  
  predictedGuesture= forest.predictLabel(pipeline.X);
  latency=pipeline.latencyInMicros();
  if(idleTimeCount==10)
      {
        xSemaphoreTake(SerialMutex,portMAX_DELAY);
        Serial.println(F("idling detected, turning gps off, or reducing gps sampling frequency"));
        Serial.println(mpu.getMotionInterruptStatus());
        xSemaphoreGive(SerialMutex);
        //digitalWrite(GPS_SWITCH,LOW);
        idleTimeCount=0;
      }
  // xSemaphoreTake(SerialMutex,portMAX_DELAY);
  // xSemaphoreGive(SerialMutex);

  vTaskDelay(pdMS_TO_TICKS(1000));
}
void Task1code( void * pvParameters ){
  while(1)
  {
    if(predictedGuesture.startsWith("walk")&&latency<1600)
    {
      xSemaphoreTake(SerialMutex,portMAX_DELAY);
      Serial.print(predictedGuesture+" score:");
      Serial.print(map(latency,1160,1800,100,0));
      Serial.println(String("%"));
      xSemaphoreGive(SerialMutex);
    }
    else if(predictedGuesture.equals("idle"))
    {
      idleTimeCount++;
      xSemaphoreTake(SerialMutex,portMAX_DELAY);
      Serial.print(predictedGuesture+" score:");
      Serial.print(map(latency,1160,1800,100,0));
      Serial.println(String("%"));
      xSemaphoreGive(SerialMutex);
    }
    else{
        xSemaphoreTake(SerialMutex,portMAX_DELAY);
        Serial.println(F("unknown motion detected "));
        Serial.print("\t"+predictedGuesture+" score:");
        Serial.print(map(latency,1160,1800,100,0));
        Serial.println(String("%"));
        xSemaphoreGive(SerialMutex);
    }
    vTaskDelay(pdMS_TO_TICKS(1000));
  }
  
}
void Task2code( void * pvParameters ){
  Serial2.begin(9600,SERIAL_8N1,RXD2,TXD2);
  pinMode(GPS_SWITCH,OUTPUT);
  digitalWrite(GPS_SWITCH,0);
  while(1)
  {
    if(Serial2.available()>0)
    {
      //gps.encode(Serial2.read());
      xSemaphoreTake(SerialMutex,portMAX_DELAY);
      Serial.print(Serial2.readStringUntil('\r'));
      Serial.print(F(","));
      Serial.println(gps.location.lng(), 6);
      xSemaphoreGive(SerialMutex);
    }
    vTaskDelay(pdMS_TO_TICKS(1000));
  }
}
