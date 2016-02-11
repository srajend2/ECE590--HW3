#define DXL_BUS_SERIAL1 1  //Dynamixel on Serial1(USART1)  <-OpenCM9.04
#define DXL_BUS_SERIAL2 2  //Dynamixel on Serial2(USART2)  <-LN101,BT210
#define DXL_BUS_SERIAL3 3  //Dynamixel on Serial3(USART3)  <-OpenCM 485EXP

#define J_ID 1
#define J_ID2 2
 
Dynamixel Dxl(DXL_BUS_SERIAL1); 
 
void setup() {
  Dxl.begin(3);  
  Dxl.jointMode(J_ID); //jointMode() is to use position mode  
  Dxl.jointMode(J_ID2);
}
 
void loop() {
  /*Turn first motor to position 45*/
  Dxl.goalPosition(J_ID, 125); 
  delay(2000);              
  /*Turn first motor to position 90*/
  Dxl.goalPosition(J_ID, 250);
  delay(2000); 
  /*Turn first motor to position 0*/
  Dxl.goalPosition(J_ID2, 0); 
  delay(1000);              
  /*Turn second motor to position 180*/
  Dxl.goalPosition(J_ID2, 500);
  delay(1000);              
}
