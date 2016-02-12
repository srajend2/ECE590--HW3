#define DXL_BUS_SERIAL1 1  //Dynamixel on Serial1(USART1)  <-OpenCM9.04
#define DXL_BUS_SERIAL2 2  //Dynamixel on Serial2(USART2)  <-LN101,BT210
#define DXL_BUS_SERIAL3 3  //Dynamixel on Serial3(USART3)  <-OpenCM 485EXP
#define STEP_DEGREE 0.29296875
#define J_ID  1
#define J_ID2 2
 
Dynamixel Dxl(DXL_BUS_SERIAL1); 
 
void setup() {
  Dxl.begin(3);  
  //Speed has been calculated based on the required RPM.
  //For 3.75RPM which is moving from 45degrees to 90degrees in 2 seconds
  //the speed control setting should be 34 (3.75/0.111328125)
  //For 30RPM which is moving from 0 degree to 180 degrees in 1 second
  //the speed control setting should be 270 (30/0.111328125)
  Dxl.goalSpeed(J_ID, 34);  //Dynamixel ID 1 Speed Control 34 setting
  Dxl.jointMode(J_ID); //jointMode() is to use position mode  
  Dxl.goalSpeed(J_ID2, 270);  //Dynamixel ID 2 Speed Control 270 setting
  Dxl.jointMode(J_ID2);
}
 
void loop() {
  /*Turn first motor to position 45*/
  Dxl.goalPosition(J_ID, (45/STEP_DEGREE)); 
  delay(3500);              
  /*Turn first motor to position 90*/
  Dxl.goalPosition(J_ID, (90/STEP_DEGREE));
  delay(3500); 
  /*Turn first motor to position 45*/
  Dxl.goalPosition(J_ID, (45/STEP_DEGREE)); 

  /*Turn first motor to position 0*/
  Dxl.goalPosition(J_ID2, 0); 
  delay(3000);              
  /*Turn second motor to position 180*/
  Dxl.goalPosition(J_ID2, (180/STEP_DEGREE));
  delay(3000);              
  /*Turn first motor to position 0*/
  Dxl.goalPosition(J_ID2, 0); 
}
