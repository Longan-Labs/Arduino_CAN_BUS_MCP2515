/*
  CAN-BUS Shield Bridge Demo
  Requires two CAN Bus Shields
  First shield should be left default = CS is on D9 and INT is on D2
  Second shield needs modified so CS is on D10 and INT is on D3
  
  Written by Cory J. Fowler
  December 09, 2015
*/

#include <mcp_can.h>
#include <SPI.h>

long unsigned int rxId;
unsigned char len = 0;
unsigned char rxBuf[8];

MCP_CAN CAN0(9);                                // Set first CAN interface CS to pin 9
MCP_CAN CAN1(10);                               // Set second CAN interface CS to pin 10

void setup()
{
  Serial.begin(115200);
  
  pinMode(2, INPUT);                            // Setting pin 2 for first CAN bus /INT input
  pinMode(3, INPUT);                            // Setting pin 3 for second CAN bus /INT input
  
  CAN0.begin(CAN_500KBPS);                      // init first CAN bus  : baudrate = 500k 
  CAN1.begin(CAN_250KBPS);                      // init second CAN bus : baudrate = 250k 
  
  Serial.println("CAN Bridge Example.");
}

void loop()
{
    if(!digitalRead(2))                         // If pin 2 is low, read receive buffer of first CAN interface
    {
      CAN0.readMsgBuf(&len, rxBuf);             // Read data: len = data length, buf = data byte(s)
      rxId = CAN0.getCanId();                   // Get message ID
      CAN1.sendMsgBuf(rxId, 1, len, rxBuf);     // Unfortunately this library does not return if the received
                                                //   message was standard or extended. So sending as extended.
      Serial.println("Received on CAN0");
    }
    
    if(!digitalRead(3))                         // If pin 3 is low, read receive buffer of second CAN interface
    {
      CAN1.readMsgBuf(&len, rxBuf);             // Read data: len = data length, buf = data byte(s)
      rxId = CAN1.getCanId();                   // Get message ID
      CAN0.sendMsgBuf(rxId, 1, len, rxBuf);     // Unfortunately this library does not return if the received
                                                //   message was standard or extended. So sending as extended.
      Serial.println("Received on CAN1");
    }
}

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
