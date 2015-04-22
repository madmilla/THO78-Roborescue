Arming and disarming test
=========================
Test program for testing if the quadcopter arms and disarms.
Is also a test for the isArmed command.

Usage
-----
Common usage is arming, then issueing the isArmed() command .
If it returns 1, the quad is armed, if it returns 0, the quad is disarmed.
When finishing test the disarm function and test isArmed() again.

Commands are sent by typing a character, then pressing enter.

Commands
--------
* a: Arm the quadcopter
* d: Disarm the quadcopter
* s: Shutdown the quadcopter
* g: Get armed status of the quadcopter
* p: Print received messages

Link to test report:
----------------------
http://roborescue.nl/wiki/index.php/Quadcopter_autonomous_flight_tests#Arming_and_disarming