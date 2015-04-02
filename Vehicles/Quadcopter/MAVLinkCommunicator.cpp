#include "MAVLinkCommunicator.h"
#include "SerialPort.h"

MAVLinkCommunicator::MAVLinkCommunicator(SerialPort& serialPort) :
serialPort{ serialPort }
{
}

void MAVLinkCommunicator::sendMessage(mavlink_message_t& message, char priority)
{
	priority_mavlink_message_t prio_message = priority_mavlink_message_t(message, priority);
	pQueue.push(prio_message);
	/*

	auto buffer = new unsigned char[MAVLINK_NUM_NON_PAYLOAD_BYTES + message.len];
	int len = mavlink_msg_to_send_buffer(buffer, &message);
	serialPort.writeData(buffer, len);

	*/
}

mavlink_message_t MAVLinkCommunicator::getMessage(mavlink_message_t& message, char priority)
{
	priority_mavlink_message_t prio_message = priority_mavlink_message_t(message, priority);
	prio_message.setHandled(false);
	pQueue.push(prio_message);

	while (!prio_message.getHandled())
	{
		// wait for the message to be handled
	}

	return prio_message.getMessage();
}

bool MAVLinkCommunicator::receiveMessage(mavlink_message_t& message)
{
	mavlink_status_t status;
	char c;
	serialPort.readData(&c, 1);
	if (mavlink_parse_char(MAVLINK_COMM_0, c, &message, &status))
	{
		return true;
	}
	return false;
}