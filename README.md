# CAN Bus Library 
[![GitHub](https://img.shields.io/github/license/Longan-Labs/Arduino_CAN_BUS_MCP2515)](https://github.com/Longan-Labs/Arduino_CAN_BUS_MCP2515/blob/master/LICENSE)
[![Installation instructions](https://www.ardu-badge.com/badge/mcp_canbus.svg?)](https://www.ardu-badge.com/mcp_canbus)
[![GitHub version](https://img.shields.io/github/release/Longan-Labs/Arduino_CAN_BUS_MCP2515.svg?logo=github&logoColor=ffffff)](https://github.com/Longan-Labs/Arduino_CAN_BUS_MCP2515/releases/latest)
[![GitHub Release Date](https://img.shields.io/github/release-date/Longan-Labs/Arduino_CAN_BUS_MCP2515.svg?logo=github&logoColor=ffffff)](https://github.com/Longan-Labs/Arduino_CAN_BUS_MCP2515/releases/latest)
[![GitHub Repo stars](https://img.shields.io/github/stars/Longan-Labs/Arduino_CAN_BUS_MCP2515?logo=github&logoColor=ffffff)](https://github.com/Longan-Labs/Arduino_CAN_BUS_MCP2515/stargazers)
[![GitHub issues](https://img.shields.io/github/issues/Longan-Labs/Arduino_CAN_BUS_MCP2515.svg?logo=github&logoColor=ffffff)](https://github.com/Longan-Labs/Arduino_CAN_BUS_MCP2515/issues)

Arduino library for MCP2515, it's available for most of theArduino boards, we test it with Arduino UNO, Leonardo, Mega as well as Zero.

With this library, you can,

1. Send a CAN2.0 frame
2. Receive a CAN2.0 frame
3. Get data from OBD-II
4. Set the masks and filters, there're 32 masks and filters. 

## Installation

You can install it similiar to any other Arduino libraries, using the Library Manager or from a Zip file in the Arduino IDE.

- Install using the Library Manager
1. In the Arduino IDE, navigate to Sketch > Include Library > Manage Libraries...
2. Search for "mcp_canbus" to find this library
3. Click "INSTALL"

- Install from a Zip file
1. [Download this library](https://github.com/Longan-Labs/Aruino_CAN_BUS_MCP2515/archive/refs/heads/master.zip)
2. Extract the zip file
3. In the Arduino IDE, navigate to Sketch > Include Library > Add .ZIP Library

You can also read [how to install mcp_canbus library](https://www.ardu-badge.com/mcp_canbus) for a reference.

## Respository Contents

* [**/examples**](./examples) - Example sketches for the library (.ino). Run these from the Arduino IDE.
* [**/src**](./src) - Source files for the library (.cpp, .h).
* [**keywords.txt**](./keywords.txt) - Keywords from this library that will be highlighted in the Arduino IDE.
* [**library.properties**](./library.properties) - General library properties for the Arduino package manager.

## How to use
### Header
```
#include <mcp_canbus.h>
```

### Functions

- begin()
- init_Mask()
- init_filt()
- checkReceive()
- readMsgBufID()
- readMsgBuf()
- getCanId()
- sendMsgBuf()
- isRemoteRequest()
- isExtendedFrame()

### Examples

here are many examples implemented in this library. One of the examples is below. You can find other examples [here](./examples)

```Cpp
/*  send a frame from can bus
    support@longan-labs.cc
    
    CAN Baudrate,
    
    #define CAN_5KBPS           1
    #define CAN_10KBPS          2
    #define CAN_20KBPS          3
    #define CAN_25KBPS          4 
    #define CAN_31K25BPS        5
    #define CAN_33KBPS          6
    #define CAN_40KBPS          7
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
   
#include <mcp_canbus.h>
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
    CAN.sendMsgBuf(0x00, 0, 8, stmp);
    delay(100);                       // send data per 100ms
}

// END FILE
```

## Get a Dev Board

If you need a Dev board, plese try,

- [CAN Bus Shield for Arduino](https://www.longan-labs.cc/1030016.html)
- [CANBed V1](https://www.longan-labs.cc/1030008.html)
- [CANBed M0](https://www.longan-labs.cc/1030014.html)
- [OBD-II CAN Bus GPS Dev Kit](https://www.longan-labs.cc/1030003.html)

## Contact us

If you have any question, please feel free to contact [support@longan-labs.cc](support@longan-labs.cc)

