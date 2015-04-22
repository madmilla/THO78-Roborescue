LiftOff, changeAltitude and land test
=====================================
Test program for testing if the quadcopter correctly takes off, changes altitude and lands.
Is also a test for the changeMode and saveQuadcopter commands.

Usage
-----
Common usage is arming the quadcopter, lifting off, changing altitude to 5 and 1 meters and landing again.
SaveQuadcopter is used to give all control back to the radio control operator.
changeMode(with parameter althold) is used to put the quad in althold .

Commands are sent by typing a character, then pressing enter.

Commands
--------
* u : changeAltitude to 5 meters
* d : changeAltitude to 1 meter
* o : liftOff to 10 meters
* l : land the quadcopter
* h : change the flightMode to AltHold
* s : 'save' the quadcopter - returns control to the radio control operator
* r : restart the quadcopter
* a : arm the quadcopter
* q : disarm the quadcopter