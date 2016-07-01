Work In Progress - Library Seems to Work...
==============

MCP_CAN Library for Arduino
==============
MCP_CAN library v1.5
This library is compatible with any shield or board that uses the MCP2515 or MCP25625 CAN protocol controller.

This version supports setting the ID filter mode of the protocol controller, the BAUD rate with clock speed with the begin() function.  Baudrates 5k, 10k, 20k, 50k, 100k, 125k, 250k, 500k, & 1000k using 16MHz clock on the MCP2515 are confirmed to work using a Peak-System PCAN-USB dongle as a reference.  Baudrates for 8MHz and 20MHz crystals are yet to be confirmed but were calculated appropiately.

The readMsgBuf() function brings in the message ID. The getCanId() function is depreciated.

Using the setMode() function the sketch can now put the protocol controller into sleep, loop-back, or listen-only modes as well as normal operation.  Right now the code defaults to loop-back mode after the begin() function runs.  I have found this to increase the stability of filtering when the controller is initialized while connected to an active bus.


Installation
==============
Copy this into the "[...]/MySketches/libraries/" folder and restart the Arduino editor.

NOTE: If an older version of the library exists (e.g. CAN_BUS_Shield) be sure to remove it from the libraries folder or replace the files with those in this library to avoid conflicts.


*Happy Coding!*
