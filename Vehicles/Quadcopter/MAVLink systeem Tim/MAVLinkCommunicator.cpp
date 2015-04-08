#include "MAVLinkCommunicator.h"
#include "../Dependencies/Serial/SerialPort.h"

MAVLinkCommunicator::MAVLinkCommunicator(SerialPort &serialPort) :
serialPort{ serialPort }
{
}

MAVLinkCommunicator::~MAVLinkCommunicator()
{
}

void MAVLinkCommunicator::Loop()
{
	while ((!stop || sendQueue.size()) && !abort)
	{
		if (sendQueue.size())
		{
			PriorityMessage message = Peek();
			Send(mavlink_message_t(message));
			sendQueue.pop();
			if (!message.getHandled())
			{
				mavlink_message_t msg{};
				int n_trys = 0;
				while (!Receive(msg) && n_trys < 4)
				{
					n_trys++;
				}
				message.setHandled(true);
			}
		}
		else {
			mavlink_message_t message{};
			if (Receive(message))
			{
				receiveQueue.push_back(message);
			}
		}
	}
}

void MAVLinkCommunicator::SendMessage(mavlink_message_t msg, char priority)
{
	sendQueue.push(PriorityMessage{ msg, priority });
}

mavlink_message_t MAVLinkCommunicator::GetResponse(mavlink_message_t msg, char priority)
{
	PriorityMessage *message = new PriorityMessage{ msg, priority };
	message->setHandled(false);
	sendQueue.push(*message);
	while (!message->getHandled())
	{
		//wait untill the message is handled
	}
	return *message;
}

mavlink_message_t MAVLinkCommunicator::ReceiveMessage()
{
	if (receiveQueue.size())
	{
		return receiveQueue.front();
	}
	return mavlink_message_t{};
}

int MAVLinkCommunicator::sendQueueSize()
{
	return sendQueue.size();
}

int MAVLinkCommunicator::receiveQueueSize()
{
	return receiveQueue.size();
}

PriorityMessage MAVLinkCommunicator::Peek()
{
	if (sendQueue.size())
	{
		return sendQueue.top();
	}
	else return PriorityMessage{};
}

void MAVLinkCommunicator::Send(mavlink_message_t msg)
{
	auto buffer = new unsigned char[MAVLINK_NUM_NON_PAYLOAD_BYTES + msg.len];
	int len = mavlink_msg_to_send_buffer(buffer, &msg);
	serialPort.writeData(buffer, len);
}

bool MAVLinkCommunicator::Receive(mavlink_message_t & msg)
{
	mavlink_status_t status;
	unsigned char c;
	serialPort.readData(&c, 1);
	if (mavlink_parse_char(MAVLINK_COMM_0, c, &msg, &status))
	{
		return true;
	}
	return false;
}

void MAVLinkCommunicator::stopThread()
{
	stop = true;
}

void MAVLinkCommunicator::abortThread()
{
	abort = true;
}