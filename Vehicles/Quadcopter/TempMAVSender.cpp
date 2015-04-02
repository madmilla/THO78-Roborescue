#include "TempMAVSender.h"
#include "SerialPort.h"

TempMAVSender::TempMAVSender(SerialPort& serialPort):
serialPort( serialPort )
{
}

void TempMAVSender::sendMessage(mavlink_message_t& message)
{
	auto buffer = new unsigned char[MAVLINK_NUM_NON_PAYLOAD_BYTES + message.len];
	int len = mavlink_msg_to_send_buffer(buffer, &message);
	serialPort.writeData(buffer, len);
}

bool TempMAVSender::receiveMessage(mavlink_message_t& message)
{
	mavlink_status_t status;
	char c;
	serialPort.readData(&c, 1);
	if(mavlink_parse_char(MAVLINK_COMM_0, c, &message, &status))
	{
		return true;
	}
	return false;
}