// demo: CAN-BUS Shield, send data
#include <mcp_can.h>
#include <SPI.h>

MCP_CAN CAN0(10);                                      // Set CS to pin 10

void setup()
{
  Serial.begin(115200);
  // Init CAN bus with 500kb/s baudrate at 16MHz with Mask and Filters disabled.
  if(CAN0.begin(MCP_ANY, CAN_500KBPS, MCP_16MHZ) == CAN_OK) Serial.print("MCP2515 init ok!!\r\n");
  else Serial.print("Can init fail!!\r\n");
  CAN0.setMode(MCP_NORMAL);   // Change to normal mode to allow messages to be transmitted
}

unsigned char stmp[8] = {0, 1, 2, 3, 4, 5, 6, 7};
void loop()
{
  // send data:  id = 0x00, standrad flame, data len = 8, stmp: data buf
  CAN0.sendMsgBuf(0x00, 0, 8, stmp);  
  delay(100);                       // send data per 100ms
}

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
