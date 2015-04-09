// MESSAGE sendInterrupt PACKING

#define MAVLINK_MSG_ID_sendInterrupt 11

typedef struct __mavlink_sendinterrupt_t
{
 uint8_t Destination; ///< Device ID
 uint8_t Function; ///< Name of the function
 uint8_t Payload; ///< Payload
} mavlink_sendinterrupt_t;

#define MAVLINK_MSG_ID_sendInterrupt_LEN 3
#define MAVLINK_MSG_ID_11_LEN 3

#define MAVLINK_MSG_ID_sendInterrupt_CRC 247
#define MAVLINK_MSG_ID_11_CRC 247



#define MAVLINK_MESSAGE_INFO_sendInterrupt { \
	"sendInterrupt", \
	3, \
	{  { "Destination", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_sendinterrupt_t, Destination) }, \
         { "Function", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_sendinterrupt_t, Function) }, \
         { "Payload", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_sendinterrupt_t, Payload) }, \
         } \
}


/**
 * @brief Pack a sendinterrupt message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param Destination Device ID
 * @param Function Name of the function
 * @param Payload Payload
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_sendinterrupt_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint8_t Destination, uint8_t Function, uint8_t Payload)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_sendInterrupt_LEN];
	_mav_put_uint8_t(buf, 0, Destination);
	_mav_put_uint8_t(buf, 1, Function);
	_mav_put_uint8_t(buf, 2, Payload);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_sendInterrupt_LEN);
#else
	mavlink_sendinterrupt_t packet;
	packet.Destination = Destination;
	packet.Function = Function;
	packet.Payload = Payload;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_sendInterrupt_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_sendInterrupt;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_sendInterrupt_LEN, MAVLINK_MSG_ID_sendInterrupt_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_sendInterrupt_LEN);
#endif
}

/**
 * @brief Pack a sendinterrupt message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param Destination Device ID
 * @param Function Name of the function
 * @param Payload Payload
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_sendinterrupt_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint8_t Destination,uint8_t Function,uint8_t Payload)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_sendInterrupt_LEN];
	_mav_put_uint8_t(buf, 0, Destination);
	_mav_put_uint8_t(buf, 1, Function);
	_mav_put_uint8_t(buf, 2, Payload);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_sendInterrupt_LEN);
#else
	mavlink_sendinterrupt_t packet;
	packet.Destination = Destination;
	packet.Function = Function;
	packet.Payload = Payload;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_sendInterrupt_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_sendInterrupt;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_sendInterrupt_LEN, MAVLINK_MSG_ID_sendInterrupt_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_sendInterrupt_LEN);
#endif
}

/**
 * @brief Encode a sendinterrupt struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param sendinterrupt C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_sendinterrupt_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_sendinterrupt_t* sendinterrupt)
{
	return mavlink_msg_sendinterrupt_pack(system_id, component_id, msg, sendinterrupt->Destination, sendinterrupt->Function, sendinterrupt->Payload);
}

/**
 * @brief Encode a sendinterrupt struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param sendinterrupt C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_sendinterrupt_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_sendinterrupt_t* sendinterrupt)
{
	return mavlink_msg_sendinterrupt_pack_chan(system_id, component_id, chan, msg, sendinterrupt->Destination, sendinterrupt->Function, sendinterrupt->Payload);
}

/**
 * @brief Send a sendinterrupt message
 * @param chan MAVLink channel to send the message
 *
 * @param Destination Device ID
 * @param Function Name of the function
 * @param Payload Payload
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_sendinterrupt_send(mavlink_channel_t chan, uint8_t Destination, uint8_t Function, uint8_t Payload)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_sendInterrupt_LEN];
	_mav_put_uint8_t(buf, 0, Destination);
	_mav_put_uint8_t(buf, 1, Function);
	_mav_put_uint8_t(buf, 2, Payload);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_sendInterrupt, buf, MAVLINK_MSG_ID_sendInterrupt_LEN, MAVLINK_MSG_ID_sendInterrupt_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_sendInterrupt, buf, MAVLINK_MSG_ID_sendInterrupt_LEN);
#endif
#else
	mavlink_sendinterrupt_t packet;
	packet.Destination = Destination;
	packet.Function = Function;
	packet.Payload = Payload;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_sendInterrupt, (const char *)&packet, MAVLINK_MSG_ID_sendInterrupt_LEN, MAVLINK_MSG_ID_sendInterrupt_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_sendInterrupt, (const char *)&packet, MAVLINK_MSG_ID_sendInterrupt_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_sendInterrupt_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_sendinterrupt_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t Destination, uint8_t Function, uint8_t Payload)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint8_t(buf, 0, Destination);
	_mav_put_uint8_t(buf, 1, Function);
	_mav_put_uint8_t(buf, 2, Payload);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_sendInterrupt, buf, MAVLINK_MSG_ID_sendInterrupt_LEN, MAVLINK_MSG_ID_sendInterrupt_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_sendInterrupt, buf, MAVLINK_MSG_ID_sendInterrupt_LEN);
#endif
#else
	mavlink_sendinterrupt_t *packet = (mavlink_sendinterrupt_t *)msgbuf;
	packet->Destination = Destination;
	packet->Function = Function;
	packet->Payload = Payload;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_sendInterrupt, (const char *)packet, MAVLINK_MSG_ID_sendInterrupt_LEN, MAVLINK_MSG_ID_sendInterrupt_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_sendInterrupt, (const char *)packet, MAVLINK_MSG_ID_sendInterrupt_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE sendInterrupt UNPACKING


/**
 * @brief Get field Destination from sendinterrupt message
 *
 * @return Device ID
 */
static inline uint8_t mavlink_msg_sendinterrupt_get_Destination(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field Function from sendinterrupt message
 *
 * @return Name of the function
 */
static inline uint8_t mavlink_msg_sendinterrupt_get_Function(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Get field Payload from sendinterrupt message
 *
 * @return Payload
 */
static inline uint8_t mavlink_msg_sendinterrupt_get_Payload(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Decode a sendinterrupt message into a struct
 *
 * @param msg The message to decode
 * @param sendinterrupt C-struct to decode the message contents into
 */
static inline void mavlink_msg_sendinterrupt_decode(const mavlink_message_t* msg, mavlink_sendinterrupt_t* sendinterrupt)
{
#if MAVLINK_NEED_BYTE_SWAP
	sendinterrupt->Destination = mavlink_msg_sendinterrupt_get_Destination(msg);
	sendinterrupt->Function = mavlink_msg_sendinterrupt_get_Function(msg);
	sendinterrupt->Payload = mavlink_msg_sendinterrupt_get_Payload(msg);
#else
	memcpy(sendinterrupt, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_sendInterrupt_LEN);
#endif
}
