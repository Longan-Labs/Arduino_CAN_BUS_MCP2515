/*  demo: set_mask_filter_send
    this demo will show you how to use mask and filter
    support@longan-labs.cc

    CAN Baudrate,
    
    #define CAN_5KBPS           1
    #define CAN_10KBPS          2
    #define CAN_20KBPS          3
    #define CAN_25KBPS          4 
    #define CAN_31K25BPS        5
    #define CAN_33KBPS          6
    #define CAN_40KBPS          7
    #define CAN_47KBPS          19
    #define CAN_50KBPS          8
    #define CAN_80KBPS          9
    #define CAN_83K3BPS         10
    #define CAN_95KBPS          11
    #define CAN_100KBPS         12
    #define CAN_125KBPS         13
    #define CAN_200KBPS         14
    #define CAN_250KBPS         15
    #define CAN_500KBPS         16
    #define CAN_666KBPS         17
    #define CAN_1000KBPS        18
   
    CANBed V1: https://www.longan-labs.cc/1030008.html
    CANBed M0: https://www.longan-labs.cc/1030014.html
    CAN Bus Shield: https://www.longan-labs.cc/1030016.html
    OBD-II CAN Bus GPS Dev Kit: https://www.longan-labs.cc/1030003.html
   
*/

#include <mcp_can.h>
#include <SPI.h>

const int SPI_CS_PIN = 17;              // CANBed V1
// const int SPI_CS_PIN = 3;            // CANBed M0
// const int SPI_CS_PIN = 9;            // CAN Bus Shield

MCP_CAN CAN(SPI_CS_PIN);                                    // Set CS pin

void setup()
{
    Serial.begin(115200);
    while(!Serial);
    
    // below code need for OBD-II GPS Dev Kit
    // pinMode(A3, OUTPUT);
    // digitalWrite(A3, HIGH);
    
    while (CAN_OK != CAN.begin(CAN_500KBPS))    // init can bus : baudrate = 500k
    {
        Serial.println("CAN BUS FAIL!");
        delay(100);
    }
    Serial.println("CAN BUS OK!");
}

unsigned char stmp[8] = {0, 1, 2, 3, 4, 5, 6, 7};

void loop()
{
    for(int id=0; id<10; id++)
    {
        memset(stmp, id, sizeof(stmp));                 // set id to send data buff
        CAN.sendMsgBuf(id, 0, sizeof(stmp), stmp);
        delay(100);
    }
}

// END FILE
