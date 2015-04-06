#include "MAVLinkCommunicator.h"
#include "SerialPort.h"

MAVLinkCommunicator::MAVLinkCommunicator(SerialPort& serialPort) :
serialPort{ serialPort }
{
	thread = new std::thread(&MAVLinkCommunicator::Loop, this);
}

void MAVLinkCommunicator::Loop()
{
	// If you want the loop to STOP, it will continue untill the queue is empty.
	// If you want the loop to ABORT, it will stop immediatly
	while ((!stop || SendingQueue.size() > 0) && !abort)
	{
		if (SendingQueue.size() > 0)
		{
			priority_mavlink_message_t msg = SendingQueue.top();
			mavlink_message_t* message = msg.getMessage();
			auto buffer = new unsigned char[MAVLINK_NUM_NON_PAYLOAD_BYTES + message->len];
			int len = mavlink_msg_to_send_buffer(buffer, message);
			serialPort.writeData(buffer, len);
			if (!msg.getHandled()){
				int n = 0;
				message = &mavlink_message_t(); // Empty the message
				while (!receiveMessage(*message) && n < 5){ // Attempt to receive a message 5 times
					n++;
				}
				msg.setHandled(true); // The message has been handled. If nothing was received after 5 atempts, the message will still be empty.
			}
			SendingQueue.pop();
		}
		else {
			mavlink_message_t msg;
			if (receiveMessage(msg))
			{
				ReceiveQueue.push_back(msg);
			}
		}
	}
}

void MAVLinkCommunicator::sendMessage(mavlink_message_t& message, char priority)
{
	priority_mavlink_message_t prio_message = priority_mavlink_message_t(message, priority);
	SendingQueue.push(prio_message);
}

mavlink_message_t MAVLinkCommunicator::getMessage(mavlink_message_t& message, char priority)
{
	priority_mavlink_message_t prio_message = priority_mavlink_message_t(message, priority);
	prio_message.setHandled(false);
	SendingQueue.push(prio_message);

	while (!prio_message.getHandled())
	{
		// wait for the message to be handled
	}

	return *prio_message.getMessage();
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

void MAVLinkCommunicator::StopLoop()
{
	stop = true;
}

void MAVLinkCommunicator::AbortLoop()
{
	abort = true;
}

void MAVLinkCommunicator::Join()
{
	thread->join();
}