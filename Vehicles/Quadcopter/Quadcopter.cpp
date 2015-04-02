#include "Quadcopter.h"
#include "TempMAVSender.h"

<<<<<<< HEAD
Quadcopter::Quadcopter(TempMAVSender& tempMAVSender) :
tempMAVSender{ tempMAVSender }
=======
//TODO: Move, remove, whatever
void Quadcopter::sendMessage(mavlink_message_t & msg){
	unsigned char* buffer =
					new unsigned char[MAVLINK_NUM_NON_PAYLOAD_BYTES
							+ (uint16_t) msg.len];
							
	int length = mavlink_msg_to_send_buffer(buffer, &msg);
	
	char* charPBuffer = reinterpret_cast<char*>(buffer);
	serialPort->writeData(charPBuffer,length);
	
	delete [] buffer;
}

Quadcopter::Quadcopter(SerialPort& serialPort): 
serialPort{ serialPort }
>>>>>>> LeftRight-Translation
{
}

Quadcopter::~Quadcopter()
{

}

void Quadcopter::liftOff()
{

}

void Quadcopter::arm()
{
	mavlink_message_t msg = mavlink_message_t();
	mavlink_msg_command_long_pack(255,0,&msg,1,250,400,0,1,0,0,0,0,0,0);
	sendMessage(msg);
}

void Quadcopter::moveLeft(signed int value)
{
	moveRight(-value);
}

void Quadcopter::moveRight(signed int value)
{
	mavlink_message_t msg = mavlink_message_t();
	mavlink_msg_rc_channels_override_pack(255,200,& msg,1,250,1487+value,UINT16_MAX, UINT16_MAX, UINT16_MAX,UINT16_MAX, UINT16_MAX, UINT16_MAX, UINT16_MAX);
	sendMessage(msg);
}

void Quadcopter::moveForward()
{

}

void Quadcopter::moveBackward()
{

}

void Quadcopter::stop()
{

}

void Quadcopter::land()
{

}

void Quadcopter::changeFlightSpeed(int)
{

}

void Quadcopter::changeHeading(int)
{

}