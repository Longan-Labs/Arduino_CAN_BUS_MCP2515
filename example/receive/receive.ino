// demo: CAN-BUS Shield, receive data
#include <mcp_can.h>
#include <SPI.h>

unsigned char Flag_Recv = 0;
unsigned char len = 0;
unsigned char buf[8];
char str[20];

void setup()
{
  CAN.begin(CAN_500KBPS);                       // init can bus : baudrate = 500k 
  pinMode(2, INPUT);                            // Setting pin 2 for /INT input
  Serial.begin(115200);
}

void loop()
{
    if(!digitalRead(2))                         // check if get data
    {
      CAN.readMsgBuf(&len, buf);                // read data,  len: data length, buf: data buf
      Serial.println("CAN_BUS GET DATA!");
      Serial.print("data len = ");
      Serial.println(len);
      
      for(int i = 0; i<len; i++)                // print the data
      {
        Serial.print(buf[i]);Serial.print("\t");
      }
      Serial.println();
    }
}

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
