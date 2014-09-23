Work In Progress - Library Seems to Work...
==============

MCP2515 Library for Arduino
==============
MCP2515 library v1.5
This library is compatible with any shield or CAN interface that uses the MCP2515 CAN protocol controller.

This version supports setting the ID mode of the MCP2515, the BAUD rate with clock speed with the begin() function.
Baudrates 5k, 10k, 20k, 50k, 100k, 125k, 250k, 500k, & 1000k using 16MHz clock on the MCP2515 are confirmed to work using a Peak-System PCAN-USB dongle as a reference.
Baudrates for a 20MHz crystal are yet to be confirmed but were calculated appropiately.
Baudrates for a 8MHz crystal are yet to be confirmed but were calculated appropiately.

The readMsgBuf() function brings in the message ID. The getCanId() function is depreciated.

Using the setMode() function you can now put the MCP2515 into sleep, loop-back, or listen-only modes as well as normal operation from your sketch.  Right now the code defaults to loop-back mode after the begin() function runs.  I have found this to increase the stability of filtering when the controller is initialized while connected to an active bus.


Installation
==============
Copy this into your "[...]/MySketches/libraries/" folder and restart the Arduino editor.

NOTE: If you have an older version of the library (CAN_BUS_Shield) be sure to remove
 it from the libraries folder or replace the files with those in this library to avoid conflicts.


*Happy Coding!*
